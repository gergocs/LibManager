//
// Created by csger on 2024. 03. 24..
//

#ifndef LIBMANAGERSERVER_ISBN_H
#define LIBMANAGERSERVER_ISBN_H

#include "../Directory.h"
#include "../../helpers.h"

namespace LibManager::MARC {

    class ISBN : public Directory {
    public:
        explicit ISBN(uint16_t id) = delete;

        ISBN(uint16_t id, uint16_t length) = delete;

        ISBN() : Directory(20, 0) {}

        explicit ISBN(const std::string &indicator, const std::string &data) : Directory(20, 0) {
            this->processData(indicator, data);
        }

        std::string getISBN() {
            return this->isbn;
        }

        Json::Value toJson() override {
            Json::Value value;
            value["isbn"] = this->isbn;
            value["termsOfAvailability"] = this->termsOfAvailability;
            value["qualifyingInformation"] = this->qualifyingInformation;
            value["canceledISBN"] = this->canceledISBN;
            value["linkage"] = this->linkage;
            value["fieldLinkAndSequenceNumber"] = this->fieldLinkAndSequenceNumber;

            return value;
        }

    private:
        std::string isbn;
        std::string termsOfAvailability;
        std::string qualifyingInformation;
        std::string canceledISBN;
        std::string linkage;
        std::string fieldLinkAndSequenceNumber;

        static bool isValidISBN10(const std::vector<uint8_t> &digits) {
            uint16_t sum = 0;
            uint16_t t = 0;

            for (auto digit: digits) {
                t += digit;
                sum += t;
            }
            return sum % 11 == 0;
        }

        static bool isValidISBN13(const std::vector<uint8_t> &digits) {
            bool isOdd = true;

            uint16_t sum = 0;
            for (size_t i = 0; i < digits.size() - 1; i++) {
                if (isOdd) {
                    sum += digits[i];
                } else {
                    sum += digits[i] * 3;
                }
                isOdd = !isOdd;
            }

            return 10 - (sum % 10) == digits[digits.size() - 1];
        }

        static bool isValidISBN(std::string isbnData) {
            isbnData.erase(std::remove(isbnData.begin(), isbnData.end(), '-'), isbnData.end());

            if (isbnData.length() != 10 && isbnData.length() != 13) {
                return false;
            }

            std::vector<uint8_t> digits;

            for (auto it: isbnData) {
                if (!std::isdigit(it)) {
                    return false;
                }

                digits.push_back(it - '0');
            }

            if (isbnData.length() == 10) {
                return isValidISBN10(digits);
            } else {
                return isValidISBN13(digits);
            }
        }

        void processData(const std::string &indicator, const std::string &data) {
            if (indicator.length() != 2 || indicator[0] != '#' || indicator[1] != '#') {
                throw std::invalid_argument("Invalid indicator");
            }

            auto fields = Helpers::split(data, "$");

            for (auto &field: fields) {
                auto tag = field.substr(0, 2);
                auto value = field.substr(2);

                switch (tag[0]) {
                    case 'a':
                        this->isbn = isValidISBN(value) ? value : throw std::invalid_argument("Invalid ISBN");
                        break;
                    case 'c':
                        this->termsOfAvailability = value;
                        break;
                    case 'q':
                        this->qualifyingInformation = value;
                        break;
                    case 'z':
                        this->canceledISBN = value;
                        break;
                    case '6':
                        this->linkage = value;
                        break;
                    case '8':
                        this->fieldLinkAndSequenceNumber = value;
                        break;
                    default:
                        throw std::invalid_argument("Invalid tag");
                }
            }
        }
    };

} // MARC
// LibManager

#endif //LIBMANAGERSERVER_ISBN_H
