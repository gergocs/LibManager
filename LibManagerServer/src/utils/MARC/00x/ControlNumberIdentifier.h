//
// Created by csger on 2024. 03. 16..
//

#ifndef LIBMANAGERSERVER_CONTROLNUMBERIDENTIFIER_H
#define LIBMANAGERSERVER_CONTROLNUMBERIDENTIFIER_H

#include <string>
#include "../Directory.h"


namespace LibManager::MARC {

    class ControlNumberIdentifier : public Directory {
    public:
        explicit ControlNumberIdentifier(uint16_t id) = delete;

        ControlNumberIdentifier(uint16_t id, uint16_t length) = delete;

        ControlNumberIdentifier() : Directory(1, 0) {}

        explicit ControlNumberIdentifier(const std::string &controlNumberId) : Directory(1,
                                                                                         controlNumberId.length()),
                                                                               controlNumberIdentifier(
                                                                                       controlNumberId) {}

        [[nodiscard]] std::string getControlNumberIdentifier() const {
            return controlNumberIdentifier;
        }

        Json::Value toJson() override {
            Json::Value value;
            value["id"] = getId();
            value["length"] = getLength();
            value["controlNumberIdentifier"] = getControlNumberIdentifier();
            return value;
        }

    private:
        std::string controlNumberIdentifier;
    };

} // MARC
// LibManager

#endif //LIBMANAGERSERVER_CONTROLNUMBERIDENTIFIER_H
