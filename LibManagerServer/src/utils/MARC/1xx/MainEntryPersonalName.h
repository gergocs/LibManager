//
// Created by csger on 2024. 03. 26..
//

#ifndef LIBMANAGERSERVER_MAINENTRYPERSONALNAME_H
#define LIBMANAGERSERVER_MAINENTRYPERSONALNAME_H


#include "../Directory.h"
#include "../../helpers.h"

namespace LibManager::MARC {

    class MainEntryPersonalName : public Directory {
    public:
        explicit MainEntryPersonalName(uint16_t id) = delete;

        MainEntryPersonalName(uint16_t id, uint16_t length) = delete;

        MainEntryPersonalName() : Directory(100, 0) {}

        explicit MainEntryPersonalName(const std::string &indicator, const std::string &data) : Directory(100, 0) {
            this->processData(indicator, data);
        }

        Json::Value toJson() override {
            Json::Value value;

            value["name"] = this->name;
            value["numeration"] = this->numeration;
            value["title"] = this->title;
            value["dates"] = this->dates;
            value["relator"] = this->relator;
            value["attribution"] = this->attribution;
            value["fullerForm"] = this->fullerForm;
            value["affiliation"] = this->affiliation;
            value["relationship"] = this->relationship;
            value["dateOfWork"] = this->dateOfWork;
            value["formSubHeading"] = this->formSubHeading;
            value["language"] = this->language;
            value["numberOfPartOfWork"] = this->numberOfPartOfWork;
            value["nameOfPartSectionOfWork"] = this->nameOfPartSectionOfWork;
            value["titleOfWork"] = this->titleOfWork;
            value["otherInformation"] = this->otherInformation;
            value["recordControlNumber"] = this->recordControlNumber;
            value["indicator1"] = this->indicator1;

            return value;
        }

    private:
        std::string name;
        std::string numeration;
        std::string title;
        std::string dates;
        std::string relator;
        std::string attribution;
        std::string fullerForm;
        std::string affiliation;
        std::string relationship;
        std::string dateOfWork;
        std::string formSubHeading;
        std::string language;
        std::string numberOfPartOfWork;
        std::string nameOfPartSectionOfWork;
        std::string titleOfWork;
        std::string otherInformation;
        std::string recordControlNumber;
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
                    case 'a': {
                        this->name = value;
                        break;
                    }
                    case 'b': {
                        this->numeration = value;
                        break;
                    }
                    case 'c': {
                        this->title = value;
                        break;
                    }
                    case 'd': {
                        this->dates = value;
                        break;
                    }
                    case 'e': {
                        this->relator = value;
                        break;
                    }
                    case 'j': {
                        this->attribution = value;
                        break;
                    }
                    case 'q': {
                        this->fullerForm = value;
                        break;
                    }
                    case 'u': {
                        this->affiliation = value;
                        break;
                    }
                    case '4': {
                        this->relationship = value;
                        break;
                    }
                    case 'f': {
                        this->dateOfWork = value;
                        break;
                    }
                    case 'k': {
                        this->formSubHeading = value;
                        break;
                    }
                    case 'l': {
                        this->language = value;
                        break;
                    }
                    case 'n': {
                        this->numberOfPartOfWork = value;
                        break;
                    }
                    case 'p': {
                        this->nameOfPartSectionOfWork = value;
                        break;
                    }
                    case 't': {
                        this->titleOfWork = value;
                        break;
                    }
                    case 'g': {
                        this->otherInformation = value;
                        break;
                    }
                    case '0': {
                        this->recordControlNumber = value;
                        break;
                    }
                    default:
                        throw std::invalid_argument("Invalid tag");
                }
            }
        }
    };

} // MARC
// LibManager

#endif //LIBMANAGERSERVER_MAINENTRYPERSONALNAME_H
