//
// Created by csger on 2024. 03. 16..
//

#ifndef LIBMANAGERSERVER_CONTROLNUMBER_H
#define LIBMANAGERSERVER_CONTROLNUMBER_H

#include <string>
#include "../Directory.h"


namespace LibManager::MARC {

    class ControlNumber : public Directory {
    public:
        explicit ControlNumber(uint16_t id) = delete;

        ControlNumber(uint16_t id, uint16_t length) = delete;

        ControlNumber() : Directory(3, 0), controlNumber(0) {}

        explicit ControlNumber(uint32_t controlNumber) : Directory(3, std::to_string(controlNumber).length()),
                                                         controlNumber(controlNumber) {}

        [[nodiscard]] uint32_t getControlNumber() const {
            return controlNumber;
        }

        Json::Value toJson() override {
            Json::Value value;
            value["id"] = getId();
            value["length"] = getLength();
            value["controlNumber"] = getControlNumber();
            return value;
        }

    private:
        uint32_t controlNumber;
    };

} // MARC
// LibManager

#endif //LIBMANAGERSERVER_CONTROLNUMBER_H
