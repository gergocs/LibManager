//
// Created by csger on 2024. 03. 26..
//

#ifndef LIBMANAGERSERVER_LANGUAGECODE_H
#define LIBMANAGERSERVER_LANGUAGECODE_H


#include "../Directory.h"
#include "../../helpers.h"

namespace LibManager::MARC {

    class LanguageCode : public Directory {
    public:
        explicit LanguageCode(uint16_t id) = delete;

        LanguageCode(uint16_t id, uint16_t length) = delete;

        LanguageCode() : Directory(35, 3) {}

        explicit LanguageCode(const std::string &indicator, const std::string &data) : Directory(41, 0) {
            this->processData(indicator, data);
        }

        Json::Value toJson() override {
            Json::Value value;

            for (auto &languageCode: languageCodes) {
                Json::Value array;
                for (auto &item: languageCode.second) {
                    array.append(item);
                }
                value[std::to_string(static_cast<uint8_t>(languageCode.first))] = array;
            }

            value["indicator1"] = this->indicator1;
            value["indicator2"] = this->indicator2;
            value["material"] = this->material;

            return value;
        }

        enum class fields : uint8_t {
            a = 'a',
            b = 'b',
            d = 'd',
            e = 'e',
            f = 'f',
            g = 'g',
            h = 'h',
            i = 'i',
            j = 'j',
            k = 'k',
            m = 'm',
            n = 'n',
            p = 'p',
            q = 'q',
            r = 'r',
            t = 't',
        };

    private:
        std::map<fields, std::vector<std::string>> languageCodes{};
        uint8_t indicator1 = '#';
        uint8_t indicator2 = '#';
        std::string material;

        void processData(const std::string &indicator, const std::string &data) {
            if (indicator.length() != 2) {
                throw std::invalid_argument("Invalid indicator");
            }

            if (indicator[0] == '#' || indicator[0] == '0' || indicator[0] == '1') {
                this->indicator1 = indicator[0];
            } else {
                throw std::invalid_argument("Invalid indicator");
            }

            if (indicator[1] == '#' || indicator[1] == '7') {
                this->indicator2 = indicator[0];
                if (indicator[1] == '7') {
                    //TODO: implement language codes
                    throw std::invalid_argument("Not implemented");
                }
            } else {
                throw std::invalid_argument("Invalid indicator");
            }

            auto fields = Helpers::split(data, "$");

            for (auto field: fields) {
                auto type = field[1];

                switch (type) {
                    case 'a':
                        languageCodes[fields::a].push_back(field.substr(2));
                        break;
                    case 'b':
                        languageCodes[fields::b].push_back(field.substr(2));
                        break;
                    case 'd':
                        languageCodes[fields::d].push_back(field.substr(2));
                        break;
                    case 'e':
                        languageCodes[fields::e].push_back(field.substr(2));
                        break;
                    case 'f':
                        languageCodes[fields::f].push_back(field.substr(2));
                        break;
                    case 'g':
                        languageCodes[fields::g].push_back(field.substr(2));
                        break;
                    case 'h':
                        languageCodes[fields::h].push_back(field.substr(2));
                        break;
                    case 'i':
                        languageCodes[fields::i].push_back(field.substr(2));
                        break;
                    case 'j':
                        languageCodes[fields::j].push_back(field.substr(2));
                        break;
                    case 'k':
                        languageCodes[fields::k].push_back(field.substr(2));
                        break;
                    case 'm':
                        languageCodes[fields::m].push_back(field.substr(2));
                        break;
                    case 'n':
                        languageCodes[fields::n].push_back(field.substr(2));
                        break;
                    case 'p':
                        languageCodes[fields::p].push_back(field.substr(2));
                        break;
                    case 'q':
                        languageCodes[fields::q].push_back(field.substr(2));
                        break;
                    case 'r':
                        languageCodes[fields::r].push_back(field.substr(2));
                        break;
                    case 't':
                        languageCodes[fields::t].push_back(field.substr(2));
                        break;
                    case '2':
                    case '7':
                        throw std::invalid_argument("Not implemented");
                        break;
                    case '3':
                        this->material = field.substr(2);
                        break;
                    default:
                        throw std::invalid_argument("Invalid tag");
                }
            }
        }
    };

} // MARC
// LibManager

#endif //LIBMANAGERSERVER_LANGUAGECODE_H
