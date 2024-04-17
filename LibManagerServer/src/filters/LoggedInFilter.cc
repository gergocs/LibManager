/**
 *
 *  LibManager_LoggedInFilter.cc
 *
 */

#include "LoggedInFilter.h"
#include "../services/UserTokenStorage.h"

using namespace drogon;
using namespace LibManager;

void LoggedInFilter::doFilter(const HttpRequestPtr &req,
                              FilterCallback &&fcb,
                              FilterChainCallback &&fccb) {
    auto token = req->headers().find("token");
    if (token == req->headers().end() || !UserTokenStorage::getInstance().isUserTokenExist(token->second) ||
        (req->path().find("registerUser") != std::string::npos &&
         !UserTokenStorage::getInstance().hasPermission(token->second, User::Permission::CREATE_USER))
        || (req->path().find("deleteUser") != std::string::npos &&
            !UserTokenStorage::getInstance().hasPermission(token->second, User::Permission::DELETE_USER))
        || (req->path().find("updateUserPermission") != std::string::npos &&
            !UserTokenStorage::getInstance().hasPermission(token->second, User::Permission::CREATE_USER))
        || (req->path().find("getUserPermission") != std::string::npos &&
            !UserTokenStorage::getInstance().hasPermission(token->second, User::Permission::CREATE_USER))
        || (req->path().find("getUsers") != std::string::npos &&
            !UserTokenStorage::getInstance().hasPermission(token->second, User::Permission::CREATE_USER | User::Permission::DELETE_USER))) {
        auto res = drogon::HttpResponse::newHttpResponse();
        res->setStatusCode(k401Unauthorized);
        fcb(res);
        return;
    }

    UserTokenStorage::getInstance().updateTokenExpirationTime(token->second);

    fccb();
}
