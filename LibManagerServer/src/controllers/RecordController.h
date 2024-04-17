#pragma once

#include <drogon/HttpController.h>

namespace LibManager {
    class RecordController : public drogon::HttpController<RecordController> {
    public:
        METHOD_LIST_BEGIN
            ADD_METHOD_TO(RecordController::addRecord, "/addRecord", drogon::Post);
        METHOD_LIST_END

        static void
        addRecord(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback);
    };
}
