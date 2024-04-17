//
// Created by csger on 2024. 03. 20..
//

#ifndef LIBMANAGERSERVER_USERTOKENSTORAGE_H
#define LIBMANAGERSERVER_USERTOKENSTORAGE_H

#include <string>
#include <map>
#include <utility>
#include "../controllers/UserController.h"

namespace LibManager {

    class UserTokenStorage {
    public:
        static UserTokenStorage &getInstance() {
            static UserTokenStorage instance;
            return instance;
        }

        void addUserToken(const std::string &token, const std::string &username, User::Permission permission) {
            userTokens[token] = UserToken(username, permission);
        }

        void removeUserToken(const std::string &token) {
            userTokens.erase(token);
        }

        bool isUserTokenExist(const std::string &token) {
            if (userTokens.find(token) != userTokens.end()) {
                auto userToken = userTokens[token];

                if (userToken.getExpirationTime() > std::chrono::system_clock::now()) {
                    return true;
                } else {
                    userTokens.erase(token);
                }
            }

            return false;
        }

        bool hasPermission(const std::string &token, User::Permission permission) {
            if (isUserTokenExist(token)) {
                return static_cast<bool>(userTokens[token].getPermissions() & permission);
            }

            return false;
        }

        void updateTokenExpirationTime(const std::string &token) {
            if (isUserTokenExist(token)) {
                userTokens[token] = UserToken(userTokens[token].getUsername(), userTokens[token].getPermissions());
            }
        }

        std::string findTokenByUsername(const std::string &username) {
            for (const auto &userToken: userTokens) {
                if (userToken.second.getUsername() == username) {
                    return userToken.first;
                }
            }

            return "";
        }

        std::string getUsernameByToken(const std::string &token) {
            if (isUserTokenExist(token)) {
                return userTokens[token].getUsername();
            }

            return "";
        }

        User::Permission getPermissionByToken(const std::string &token) {
            if (isUserTokenExist(token)) {
                return userTokens[token].getPermissions();
            }

            return User::Permission::NO_PERMISSION;
        }

    private:

        UserTokenStorage() = default;

        class UserToken {
        public:
            UserToken() = default;

            UserToken(std::string username, LibManager::User::Permission permissions) : username(std::move(username)),
                                                                                        permissions(permissions),
                                                                                        expirationTime(
                                                                                                std::chrono::system_clock::now() +
                                                                                                std::chrono::hours(
                                                                                                        1)) {}

            [[nodiscard]] const std::string &getUsername() const {
                return username;
            }

            [[nodiscard]] User::Permission getPermissions() const {
                return permissions;
            }

            [[nodiscard]] const std::chrono::time_point<std::chrono::system_clock> &getExpirationTime() const {
                return expirationTime;
            }

        private:
            std::string username;
            LibManager::User::Permission permissions = LibManager::User::Permission::NO_PERMISSION;
            std::chrono::time_point<std::chrono::system_clock> expirationTime;
        };

        std::map<std::string, UserToken> userTokens{};
    };

} // LibManager

#endif //LIBMANAGERSERVER_USERTOKENSTORAGE_H
