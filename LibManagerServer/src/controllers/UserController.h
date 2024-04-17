#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace LibManager {
    class User : public drogon::HttpController<User> {
    public:
        METHOD_LIST_BEGIN
            ADD_METHOD_TO(User::registerUser, "/registerUser", Post, Options,
                          "LibManager::CorsFilter", "LibManager::LoggedInFilter");
            ADD_METHOD_TO(User::getUser, "/getUser", Post, Options, "LibManager::CorsFilter");
            ADD_METHOD_TO(User::deleteUser, "/deleteUser/{1}", Delete, Options,
                          "LibManager::CorsFilter", "LibManager::LoggedInFilter");
            ADD_METHOD_TO(User::updateUserPermission, "/updateUserPermission", Post, Options,
                          "LibManager::CorsFilter", "LibManager::LoggedInFilter");
            ADD_METHOD_TO(User::updateUserInformation, "/updateUserInformation", Post, Options,
                          "LibManager::CorsFilter", "LibManager::LoggedInFilter");
            ADD_METHOD_TO(User::getUserPermission, "/getUserPermission/{1}", Get, Options, "LibManager::CorsFilter",
                          "LibManager::LoggedInFilter");
            ADD_METHOD_TO(User::getUsers, "/getUsers", Get, Options, "LibManager::CorsFilter",
                          "LibManager::LoggedInFilter");
        METHOD_LIST_END

        void registerUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) const;

        void getUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) const;

        void deleteUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                        std::string &&name) const;

        void
        updateUserPermission(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) const;

        void
        updateUserInformation(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) const;

        void getUserPermission(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                               std::string &&name) const;

        void getUsers(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) const;

        enum class Permission : uint8_t {
            NO_PERMISSION = 0,
            READ = 1 << 0,
            WRITE = 1 << 1,
            DELETE = 1 << 2,
            CREATE_USER = 1 << 3,
            DELETE_USER = 1 << 4,
        };
    };

    inline User::Permission operator|(const User::Permission &a, const User::Permission &b) {
        return static_cast<User::Permission>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
    }

    inline User::Permission operator&(const User::Permission &a, const User::Permission &b) {
        return static_cast<User::Permission>(static_cast<uint8_t>(a) & static_cast<uint8_t>(b));
    }

    inline User::Permission operator~(const User::Permission &a) {
        return static_cast<User::Permission>(~static_cast<uint8_t>(a));
    }

    inline User::Permission &operator|=(User::Permission &a, const User::Permission &b) {
        a = a | b;
        return a;
    }

    inline User::Permission &operator&=(User::Permission &a, const User::Permission &b) {
        a = a & b;
        return a;
    }

    inline bool operator!(const User::Permission &a) {
        return !static_cast<uint8_t>(a);
    }

    inline bool operator==(const User::Permission &a, const User::Permission &b) {
        return static_cast<uint8_t>(a) == static_cast<uint8_t>(b);
    }

    inline bool operator!=(const User::Permission &a, const User::Permission &b) {
        return static_cast<uint8_t>(a) != static_cast<uint8_t>(b);
    }


}
