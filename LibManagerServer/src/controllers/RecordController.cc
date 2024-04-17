#include "RecordController.h"

#include "../utils/MARC/MarcProcessor.h"
#include "../utils/MARC/expections/Exception.h"
#include "../models/Record.h"


void LibManager::RecordController::addRecord(const drogon::HttpRequestPtr &req,
                                             std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
    LibManager::MARC::MARCProcessor marcProcessor(std::string(req->getBody()));

    auto resp = drogon::HttpResponse::newHttpResponse();

    try {
        marcProcessor.processData();

        Json::Value json;
        json["id"] = drogon::utils::getUuid();
        json["data"] = marcProcessor.toJson().toStyledString();

        drogon::orm::Mapper<drogon_model::libmanager::Record> mapper(drogon::app().getFastDbClient());

        mapper.insert(drogon_model::libmanager::Record(json), [resp](const drogon_model::libmanager::Record &record) {
            resp->setStatusCode(drogon::HttpStatusCode::k200OK);
        }, [resp](const drogon::orm::DrogonDbException &e) {
            std::cerr << "error:" << e.base().what() << std::endl;
            resp->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
        });
    } catch (const LibManager::MARC::MarcException &e) {
        resp->setStatusCode(drogon::HttpStatusCode::k400BadRequest);
        resp->setBody(e.what());
    } catch (...) {
        resp->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
        resp->setBody("Internal server error");
    }

    callback(resp);
}

// Add definition of your processing function here
