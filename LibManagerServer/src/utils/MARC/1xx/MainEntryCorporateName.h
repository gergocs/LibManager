//
// Created by csger on 2024. 03. 29..
//

#ifndef LIBMANAGERSERVER_MAINENTRYCORPORATENAME_H
#define LIBMANAGERSERVER_MAINENTRYCORPORATENAME_H


#include <cstdint>
#include "../Directory.h"
#include "../../helpers.h"

namespace LibManager::MARC {

    class MainEntryCorporateName : public Directory {
    public:
        explicit MainEntryCorporateName(const uint16_t &id) = delete;

        MainEntryCorporateName(const uint16_t &id, const uint16_t &length) = delete;

        MainEntryCorporateName() : Directory(110, 0) {}

        explicit MainEntryCorporateName(const std::string &indicator, const std::string &data) : Directory(110, 0) {
            this->processData(indicator, data);
        }

        Json::Value toJson() override {
            Json::Value value;

            value["name"] = this->name;
            value["subordinate"] = this->subordinate;
            value["location"] = this->location;
            value["dateOfMeeting"] = this->dateOfMeeting;
            value["relator"] = this->relator;
            value["dateOfWork"] = this->dateOfWork;
            value["misc"] = this->misc;
            value["formSubheading"] = this->formSubheading;
            value["language"] = this->language;
            value["number"] = this->number;
            value["nameOfPartSection"] = this->nameOfPartSection;
            value["titleOfWork"] = this->titleOfWork;
            value["affiliation"] = this->affiliation;
            value["authorityRecordControlNumber"] = this->authorityRecordControlNumber;
            value["indicator1"] = this->indicator1;

            return value;
        }

    private:
        std::string name;
        std::string subordinate;
        std::string location;
        std::string dateOfMeeting;
        std::string relator;
        std::string dateOfWork;
        std::string misc;
        std::string formSubheading;
        std::string language;
        std::string number;
        std::string nameOfPartSection;
        std::string titleOfWork;
        std::string affiliation;
        std::string authorityRecordControlNumber;
        uint8_t indicator1 = '#';

        void processData(const std::string &indicator, const std::string &data) {
            if (indicator.length() != 2 || indicator[1] != '#') {
                throw std::invalid_argument("Invalid indicator");
            }

            if (indicator[0] == '0' || indicator[0] == '1' || indicator[0] == '3') {
                this->indicator1 = indicator[0];
            } else {
                throw std::invalid_argument("Invalid indicator");
            }

            auto fields = Helpers::split(data, "$");

            for (auto field: fields) {
                uint8_t tag = field[1];
                std::string value = field.substr(2);

                switch (tag) {
                    case 'a':
                        this->name = value;
                        break;
                    case 'b':
                        this->subordinate = value;
                        break;
                    case 'c':
                        this->location = value;
                        break;
                    case 'd':
                        this->dateOfMeeting = value;
                        break;
                    case 'e':
                        this->relator = value;
                        break;
                    case 'f':
                        this->dateOfWork = value;
                        break;
                    case 'g':
                        this->misc = value;
                        break;
                    case 'k':
                        this->formSubheading = value;
                        break;
                    case 'l':
                        this->language = value;
                        break;
                    case 'n':
                        this->number = value;
                        break;
                    case 'p':
                        this->nameOfPartSection = value;
                        break;
                    case 't':
                        this->titleOfWork = value;
                        break;
                    case 'u':
                        this->affiliation = value;
                        break;
                    case '0':
                        this->authorityRecordControlNumber = value;
                        break;
                    default:
                        throw std::invalid_argument("Invalid tag");
                }
            }
        }
    };

} // MARC
// LibManager

#endif //LIBMANAGERSERVER_MAINENTRYCORPORATENAME_H
