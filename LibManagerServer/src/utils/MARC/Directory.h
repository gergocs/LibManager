//
// Created by csger on 2024. 03. 16..
//

#ifndef LIBMANAGERSERVER_DIRECTORY_H
#define LIBMANAGERSERVER_DIRECTORY_H

#include <cstdint>
#include <json/value.h>

namespace LibManager {
    namespace MARC {

        class Directory {
        public:
            Directory() {
                id = 0;
                length = 0;
            }

            Directory(uint16_t id, uint16_t length) {
                this->id = id;
                this->length = length;
            }

            explicit Directory(uint16_t id) : id(id) {
                length = 0;
            }

            [[nodiscard]] uint16_t getId() const {
                return id;
            }

            [[nodiscard]] uint16_t getLength() const {
                return length;
            }

            void setLength(uint16_t length) {
                Directory::length = length;
            }

            void setId(uint16_t id) {
                Directory::id = id;
            }

            virtual Json::Value toJson() = 0;

            virtual ~Directory() = default;

        private:
            uint16_t id;
            uint16_t length;
        };

    } // MARC
} // LibManager

#endif //LIBMANAGERSERVER_DIRECTORY_H
