//
// Created by csger on 2024. 03. 25..
//

#ifndef LIBMANAGERSERVER_ISSN_H
#define LIBMANAGERSERVER_ISSN_H


#include "../Directory.h"
#include "../../helpers.h"

namespace LibManager::MARC {

    class ISSN : public Directory {
    public:
        explicit ISSN(uint16_t id) = delete;

        ISSN(uint16_t id, uint16_t length) = delete;

        ISSN() : Directory(20, 0) {}

        explicit ISSN(const std::string &indicator, const std::string &data) : Directory(20, 0) {
            if (!isValidISSN(data)) {
                throw std::invalid_argument("Invalid ISSN");
            }

            this->issn = data;
        }

        Json::Value toJson() override {
            Json::Value value;
            value["issn"] = this->issn;
            value["invalidISSN"] = this->invalidISSN;
            value["canceledISSN"] = this->canceledISSN;
            value["indicator1"] = this->indicator1;

            return value;
        }

    private:
        std::string issn;
        std::string invalidISSN;
        std::string canceledISSN;
        uint8_t indicator1 = '#';

        static bool isValidISSN(const std::string &issn) {
            if (issn.length() != 8) {
                return false;
            }

            char lastChar = issn[7];

            uint16_t sum = 0;

            for (uint8_t i = 0; i < 7; i++) {
                sum += (issn[i] - '0') * (8 - i);
            }

            sum %= 11;

            if (sum == 0) {
                return lastChar == '0';
            } else if (sum == 1) {
                return lastChar == 'X';
            } else {
                return lastChar == (11 - sum) + '0';
            }
        }

        void processData(const std::string &indicator, const std::string &data) {
            if (indicator.length() != 2 || indicator[1] != '#') {
                throw std::invalid_argument("Invalid indicator");
            }

            switch (indicator[0]) {
                case '#':
                case '0':
                case '1':
                    this->indicator1 = indicator[0];
                    break;
                default:
                    throw std::invalid_argument("Invalid indicator");
            }

            auto fields = Helpers::split(data, "$");

            for (auto &field: fields) {
                auto tag = field.substr(0, 2);
                auto value = field.substr(2);

                switch (tag[1]) {
                    case 'a': {
                        if (!isValidISSN(value)) {
                            throw std::invalid_argument("Invalid ISSN");
                        }

                        this->issn = value;
                        break;
                    }
                    case 'y': {
                        this->invalidISSN = value;
                    }
                    case 'z': {
                        this->canceledISSN = value;
                    }
                    default:
                        throw std::invalid_argument("Invalid tag");
                }
            }
        }
    };

} // MARC
// LibManager

#endif //LIBMANAGERSERVER_ISSN_H
