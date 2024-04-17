#include "drogon/HttpAppFramework.h"
#include "controllers/RecordController.h"

int main() {
    drogon::app().loadConfigFile("../config/config.json");
    drogon::app().registerPostHandlingAdvice([](const drogon::HttpRequestPtr &req,
                                                const drogon::HttpResponsePtr &resp) {
        auto &origin = req->getHeader("Origin");
        resp->addHeader("Access-Control-Allow-Origin", origin);
        resp->addHeader("Access-Control-Allow-Methods", "GET,PUT,POST,DELETE,PATCH,OPTIONS");
        resp->addHeader("Access-Control-Allow-Headers",
                        "Origin, X-Requested-With, Content-Type, Accept, Authorization, Token");
        resp->addHeader("Access-Control-Allow-Credentials", "true");
    });
    drogon::app().registerPreSendingAdvice([](const drogon::HttpRequestPtr &req,
                                              const drogon::HttpResponsePtr &resp) {
        auto &origin = req->getHeader("Origin");
        resp->addHeader("Access-Control-Allow-Origin", origin);
        resp->addHeader("Access-Control-Allow-Methods", "GET,PUT,POST,DELETE,PATCH,OPTIONS");
        resp->addHeader("Access-Control-Allow-Headers",
                        "Origin, X-Requested-With, Content-Type, Accept, Authorization, Token");
        resp->addHeader("Access-Control-Allow-Credentials", "true");
    });
    drogon::app().run();
    return 0;
}
