//
// Created by csger on 2024. 03. 26..
//

#ifndef LIBMANAGERSERVER_UNIVERSALDECIMALCLASSIFICATIONNUMBER_H
#define LIBMANAGERSERVER_UNIVERSALDECIMALCLASSIFICATIONNUMBER_H


#include "../Directory.h"
#include "../../helpers.h"

namespace LibManager::MARC {

    class UniversalDecimalClassificationNumber : public Directory {
    public:
        explicit UniversalDecimalClassificationNumber(uint16_t id) = delete;

        UniversalDecimalClassificationNumber(uint16_t id, uint16_t length) = delete;

        UniversalDecimalClassificationNumber() : Directory(60, 0) {}

        explicit UniversalDecimalClassificationNumber(const std::string &indicator, const std::string &data)
                : Directory(80, 0) {
            this->processData(indicator, data);
        }

        Json::Value toJson() override {
            Json::Value value;

            value["UDCN"] = this->UDCN;
            value["itemNumber"] = this->itemNumber;
            value["commonAuxiliarySubdivision"] = this->commonAuxiliarySubdivision;
            value["editionIdentifier"] = this->editionIdentifier;
            value["indicator1"] = this->indicator1;

            return value;
        }

    private:
        std::string UDCN;
        std::string itemNumber;
        std::string commonAuxiliarySubdivision;
        uint16_t editionIdentifier = 0;
        uint8_t indicator1 = '#';

        void processData(const std::string &indicator, const std::string &data) {
            if (indicator.length() != 2 || indicator[1] != '#') {
                throw std::invalid_argument("Invalid indicator");
            }

            if (indicator[0] == '#' || indicator[0] == '0' || indicator[0] == '1') {
                indicator1 = indicator[0];
            } else {
                throw std::invalid_argument("Invalid indicator");
            }

            auto fields = Helpers::split(data, "$");

            for (auto field: fields) {
                if (field[1] == 'a') {
                    UDCN = field.substr(1);
                } else if (field[1] == 'b') {
                    itemNumber = field.substr(1);
                } else if (field[1] == 'x') {
                    commonAuxiliarySubdivision = field.substr(1);
                } else if (field[1] == '0' || field[1] == '1') {
                    //TODO: implement
                    throw std::invalid_argument("Not implemented");
                } else if (field[1] == '2') {
                    editionIdentifier = std::stoi(field.substr(1));
                } else {
                    throw std::invalid_argument("Invalid field");
                }
            }
        }

    };

} // MARC
// LibManager

#endif //LIBMANAGERSERVER_UNIVERSALDECIMALCLASSIFICATIONNUMBER_H
