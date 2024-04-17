/**
 *
 *  LibManager_LoggedInFilter.h
 *
 */

#pragma once

#include <drogon/HttpFilter.h>
#include "../controllers/UserController.h"

using namespace drogon;
namespace LibManager
{

class LoggedInFilter : public HttpFilter<LoggedInFilter>
{
  public:
    LoggedInFilter() {}
    void doFilter(const HttpRequestPtr &req,
                  FilterCallback &&fcb,
                  FilterChainCallback &&fccb) override;
};

}
