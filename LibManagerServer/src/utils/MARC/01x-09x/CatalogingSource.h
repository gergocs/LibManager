//
// Created by csger on 2024. 03. 25..
//

#ifndef LIBMANAGERSERVER_CATALOGINGSOURCE_H
#define LIBMANAGERSERVER_CATALOGINGSOURCE_H


#include "../Directory.h"
#include "../helpers/Constants.h"
#include "../../helpers.h"

namespace LibManager::MARC {

    class CatalogingSource : public Directory {
    public:
        explicit CatalogingSource(uint16_t id) = delete;

        CatalogingSource(uint16_t id, uint16_t length) = delete;

        CatalogingSource() : Directory(20, 0) {}

        explicit CatalogingSource(const std::string &indicator, const std::string &data) : Directory(40, 0) {
            processData(indicator, data);
        }

        Json::Value toJson() override {
            Json::Value value;
            value["catalogingAgency"] = this->catalogingAgency;
            value["languageOfCataloging"] = this->languageOfCataloging;
            value["transcribingAgency"] = this->transcribingAgency;
            value["modifyingAgency"] = this->modifyingAgency;
            value["descriptionConventions"] = this->descriptionConventions;

            return value;
        }

    private:
        std::string catalogingAgency;
        std::string languageOfCataloging;
        std::string transcribingAgency;
        std::string modifyingAgency;
        std::string descriptionConventions;

        void processData(const std::string &indicator, const std::string &data) {
            if (indicator.length() != 2 || indicator[0] != '#' || indicator[1] != '#') {
                throw std::invalid_argument("Invalid indicator");
            }

            auto fields = Helpers::split(data, "$");

            for (auto &field: fields) {
                auto tag = field.substr(0, 2);
                auto value = field.substr(2);

                if (tag[1] == 'a') {
                    this->catalogingAgency = data;
                } else if (tag[1] == 'b') {
                    if (std::find(Constants::validLanguages.begin(), Constants::validLanguages.end(),
                                  frozen::string(data)) ==
                        Constants::validLanguages.end()) {
                        throw std::invalid_argument("Invalid language");
                    }
                    this->languageOfCataloging = data;
                } else if (tag[1] == 'c') {
                    this->transcribingAgency = data;
                } else if (tag[1] == 'd') {
                    this->modifyingAgency = data;
                } else if (tag[1] == 'e') {
                    this->descriptionConventions = data;
                }
            }
        }
    };

} // MARC
// LibManager

#endif //LIBMANAGERSERVER_CATALOGINGSOURCE_H
