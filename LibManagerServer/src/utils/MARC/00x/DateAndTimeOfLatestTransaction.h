//
// Created by csger on 2024. 03. 16..
//

#ifndef LIBMANAGERSERVER_DATEANDTIMEOFLATESTTRANSACTION_H
#define LIBMANAGERSERVER_DATEANDTIMEOFLATESTTRANSACTION_H

#include <string>
#include <chrono>
#include <ctime>
#include "../Directory.h"

namespace LibManager::MARC {

    class DateAndTimeOfLatestTransaction : public Directory {
    public:
        explicit DateAndTimeOfLatestTransaction(uint16_t id) = delete;

        DateAndTimeOfLatestTransaction(uint16_t id, uint16_t length) = delete;

        DateAndTimeOfLatestTransaction() : Directory(5, 0) {
            this->dateAndTimeOfLatestTransaction = std::chrono::seconds(std::time(nullptr)).count();
        }

        explicit DateAndTimeOfLatestTransaction(uint64_t dateAndTimeOfLatestTransaction) : Directory(5, std::to_string(
                dateAndTimeOfLatestTransaction).length()),
                                                                                           dateAndTimeOfLatestTransaction(
                                                                                                   dateAndTimeOfLatestTransaction) {}

        [[nodiscard]] uint64_t getDateAndTimeOfLatestTransaction() const {
            return dateAndTimeOfLatestTransaction;
        }

        Json::Value toJson() override {
            Json::Value value;
            value["id"] = getId();
            value["length"] = getLength();
            value["dateAndTimeOfLatestTransaction"] = getDateAndTimeOfLatestTransaction();
            return value;
        }

    private:
        uint64_t dateAndTimeOfLatestTransaction;
    };

} // MARC
// LibManager

#endif //LIBMANAGERSERVER_DATEANDTIMEOFLATESTTRANSACTION_H
