/**
 *
 *  LibManager_CorsFilter.cc
 *
 */

#include "CorsFilter.h"

using namespace drogon;
using namespace LibManager;

void CorsFilter::doFilter(const HttpRequestPtr &req,
                          FilterCallback &&fcb,
                          FilterChainCallback &&fccb) {
    if (req->method() == Options) {
        auto &origin = req->getHeader("Origin");
        auto resp = HttpResponse::newHttpResponse();
        resp->addHeader("Access-Control-Allow-Origin", origin);
        resp->addHeader("Access-Control-Allow-Methods", "GET,PUT,POST,DELETE,PATCH,OPTIONS");
        resp->addHeader("Access-Control-Allow-Headers",
                        "Origin, X-Requested-With, Content-Type, Accept, Authorization, Token");
        resp->addHeader("Access-Control-Allow-Credentials", "true");
        fcb(resp);
        return;
    }
    fccb();
}
