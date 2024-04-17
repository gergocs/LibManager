/**
 *
 *  LibManager_CorsFilter.h
 *
 */

#pragma once

#include <drogon/HttpFilter.h>
using namespace drogon;
namespace LibManager
{

class CorsFilter : public HttpFilter<CorsFilter>
{
  public:
    CorsFilter() {}
    void doFilter(const HttpRequestPtr &req,
                  FilterCallback &&fcb,
                  FilterChainCallback &&fccb) override;
};

}
