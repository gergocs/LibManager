//
// Created by csger on 2024. 03. 19..
//

#ifndef LIBMANAGERSERVER_EXCEPTION_H
#define LIBMANAGERSERVER_EXCEPTION_H

#include <stdexcept>

namespace LibManager {
    namespace MARC {
        class MarcException : public std::runtime_error {
        public:
            explicit MarcException(const std::string &message, uint32_t line, uint8_t pos)
                    : runtime_error(
                    "Error in line " + std::to_string(line) + " at position " + std::to_string(pos) + ": " + message) {
            }
        };

    } // MARC
} // LibManager

#endif //LIBMANAGERSERVER_EXCEPTION_H
