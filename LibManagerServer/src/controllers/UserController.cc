#include "UserController.h"
#include "drogon/orm/Mapper.h"
#include "../models/Users.h"
#include "../services/UserTokenStorage.h"

using namespace LibManager;

// Add definition of your processing function here
void User::registerUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) const {
    std::string name;
    std::string password;
    Permission permission = Permission::NO_PERMISSION;

    if (CT_APPLICATION_JSON != req->contentType()) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
        callback(resp);
        return;
    }

    Json::Value json;
    std::istringstream(req->body().data()) >> json;

    std::string token = req->headers().find("token")->second;

    if (json["username"] == Json::nullValue) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
        resp->setBody("Name is required");
        callback(resp);
        return;
    }

    if (json["password"] == Json::nullValue) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
        resp->setBody("Password is required");
        callback(resp);
        return;
    }

    name = json["username"].asString();
    password = json["password"].asString();

    if (name.empty() || password.empty()) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
        resp->setBody("Name and password are required");
        callback(resp);
        return;
    }

    drogon::orm::Mapper<drogon_model::libmanager::Users> mapper(drogon::app().getFastDbClient());

    auto user = drogon_model::libmanager::Users();
    user.setUsername(name);
    user.setPassword(password);
    user.setPermissions(static_cast<uint8_t>(permission));

    mapper.insert(user, [callback](const drogon_model::libmanager::Users &user) {
        auto resp = HttpResponse::newHttpResponse();

        resp->setStatusCode(HttpStatusCode::k200OK);

        callback(resp);
    }, [callback](const drogon::orm::DrogonDbException &e) {
        auto resp = HttpResponse::newHttpResponse();

        resp->setStatusCode(HttpStatusCode::k500InternalServerError);
        resp->setBody(e.base().what());

        callback(resp);
    });

    auto resp = HttpResponse::newHttpResponse();

    resp->setStatusCode(HttpStatusCode::k200OK);
    resp->setBody("User registered");

    callback(resp);
}

void
User::getUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) const {
    auto token = req->headers().find("token");

    if (token != req->headers().end() && !token->second.empty()) {
        auto resp = HttpResponse::newHttpResponse();
        Json::Value json;
        json["username"] = UserTokenStorage::getInstance().getUsernameByToken(token->second);
        json["token"] = token->second;
        json["permissions"] = static_cast<uint8_t>(UserTokenStorage::getInstance().getPermissionByToken(token->second));

        resp->setStatusCode(HttpStatusCode::k200OK);
        resp->setBody(json.toStyledString());
        callback(resp);
        return;
    }

    if (CT_APPLICATION_JSON != req->contentType()) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
        callback(resp);
        return;
    }

    Json::Value json;

    std::istringstream(req->body().data()) >> json;

    std::string name = json["username"].asString();
    std::string password = json["password"].asString();

    if (name.empty() || password.empty()) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
        resp->setBody("Name and password are required");
        /*auto &origin = req->getHeader("Origin");
        resp->addHeader("Access-Control-Allow-Origin", origin);
        resp->addHeader("Access-Control-Allow-Methods", "GET,PUT,POST,DELETE,PATCH,OPTIONS");
        resp->addHeader("Access-Control-Allow-Headers",
                        "Origin, X-Requested-With, Content-Type, Accept, Authorization, Token");
        resp->addHeader("Access-Control-Allow-Credentials", "true");*/
        callback(resp);
        return;
    }

    drogon::app().getFastDbClient()->execSqlAsync(
            "SELECT * FROM users WHERE username = $1 AND password = sha256($2::bytea)::text;",
            [callback](const drogon::orm::Result &r) {
                auto resp = HttpResponse::newHttpResponse();
                if (r.empty()) {
                    resp->setStatusCode(HttpStatusCode::k404NotFound);
                    resp->setBody("User not found");
                } else {
                    resp->setStatusCode(HttpStatusCode::k200OK);
                    std::string token;
                    if (UserTokenStorage::getInstance().findTokenByUsername(
                            r[0]["username"].as<std::string>()).empty()) {
                        token = drogon::utils::getUuid();
                        UserTokenStorage::getInstance().addUserToken(token, r[0]["username"].as<std::string>(),
                                                                     static_cast<Permission>(r[0]["permissions"].as<uint8_t>()));
                    } else {
                        token = UserTokenStorage::getInstance().findTokenByUsername(r[0]["username"].as<std::string>());
                        UserTokenStorage::getInstance().updateTokenExpirationTime(token);
                    }

                    Json::Value json;

                    json["username"] = r[0]["username"].as<std::string>();
                    json["token"] = token;
                    json["permissions"] = r[0]["permissions"].as<uint8_t>();

                    resp->setBody(json.toStyledString());
                }
                callback(resp);
            },
            [callback](const drogon::orm::DrogonDbException &e) {
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(HttpStatusCode::k500InternalServerError);
                resp->setBody(e.base().what());
                callback(resp);
            },
            name, password);
}

void User::deleteUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                      std::string &&name) const {
    if (name.empty()) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
        callback(resp);
        return;
    }

    drogon::app().getFastDbClient()->execSqlAsync(
            "DELETE FROM users WHERE username = $1;",
            [callback](const drogon::orm::Result &r) {
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(HttpStatusCode::k200OK);
                callback(resp);

            },
            [callback](const drogon::orm::DrogonDbException &e) {
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(HttpStatusCode::k500InternalServerError);
                resp->setBody(e.base().what());
                callback(resp);
            },
            name);
}

void
User::updateUserPermission(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) const {
    std::cout << "updateUserPermission" << std::endl;
    if (CT_APPLICATION_JSON != req->contentType()) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
        callback(resp);
        return;
    }

    Json::Value json;

    std::istringstream(req->body().data()) >> json;

    std::string token = req->headers().find("token")->second;

    if (token.empty() || !UserTokenStorage::getInstance().hasPermission(token, Permission::CREATE_USER)) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(HttpStatusCode::k401Unauthorized);
        callback(resp);
        return;
    }

    if (json["username"] == Json::nullValue || json["permission"] == Json::nullValue) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
        resp->setBody("Name is required");
        callback(resp);
        return;
    }

    std::string name = json["username"].asString();
    auto permission = json["permission"].asUInt();

    if (permission > 31) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
        resp->setBody("Invalid permission");
        callback(resp);
        return;
    }

    drogon::app().getFastDbClient()->execSqlAsync(
            "UPDATE users SET permissions = $1 WHERE username = $2;",
            [callback, name](const drogon::orm::Result &r) {
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(HttpStatusCode::k200OK);
                UserTokenStorage::getInstance().removeUserToken(
                        UserTokenStorage::getInstance().findTokenByUsername(name));
                callback(resp);
            },
            [callback](const drogon::orm::DrogonDbException &e) {
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(HttpStatusCode::k500InternalServerError);
                resp->setBody(e.base().what());
                callback(resp);
            },
            permission, name);
}

void
User::updateUserInformation(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) const {
    if (CT_APPLICATION_JSON != req->contentType()) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
        callback(resp);
        return;
    }

    Json::Value json;
    std::istringstream(req->body().data()) >> json;
    std::string token = req->headers().find("token")->second;

    auto oldUserName = UserTokenStorage::getInstance().getUsernameByToken(token);

    std::string newUserName = json["username"].asString();
    std::string newPassword = json["password"].asString();

    if (oldUserName.empty() || newUserName.empty() || newPassword.empty()) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
        callback(resp);
        return;
    }

    drogon::app().getFastDbClient()->execSqlAsync(
            "UPDATE users SET username = $1, password = $2 WHERE username = $3;",
            [callback, oldUserName](const drogon::orm::Result &r) {
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(HttpStatusCode::k200OK);
                UserTokenStorage::getInstance().removeUserToken(
                        UserTokenStorage::getInstance().findTokenByUsername(oldUserName));
                callback(resp);
            },
            [callback](const drogon::orm::DrogonDbException &e) {
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(HttpStatusCode::k500InternalServerError);
                resp->setBody(e.base().what());
                callback(resp);
            },
            newUserName, newPassword, oldUserName);
}

void User::getUserPermission(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                             std::string &&name) const {
    if (name.empty()) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
        callback(resp);
        return;
    }

    drogon::app().getFastDbClient()->execSqlAsync(
            "SELECT permissions FROM users WHERE username = $1;",
            [callback](const drogon::orm::Result &r) {
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(HttpStatusCode::k200OK);
                Json::Value response;
                response["permissions"] = r[0]["permissions"].as<uint8_t>();
                resp->setBody(response.toStyledString());
                callback(resp);
            },
            [callback](const drogon::orm::DrogonDbException &e) {
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(HttpStatusCode::k500InternalServerError);
                resp->setBody(e.base().what());
                callback(resp);
            },
            name);
}

void User::getUsers(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) const {
    drogon::app().getFastDbClient()->execSqlAsync(
            "SELECT username FROM users;",
            [callback](const drogon::orm::Result &r) {
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(HttpStatusCode::k200OK);
                Json::Value users;
                users["username"] = Json::arrayValue;
                for (const auto &row: r) {
                    users["username"].append(row["username"].as<std::string>());
                }
                resp->setBody(users.toStyledString());
                callback(resp);
            },
            [callback](const drogon::orm::DrogonDbException &e) {
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(HttpStatusCode::k500InternalServerError);
                resp->setBody(e.base().what());
                callback(resp);
            });
}
