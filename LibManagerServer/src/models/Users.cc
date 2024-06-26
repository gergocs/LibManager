/**
 *
 *  Users.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Users.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::libmanager;

const std::string Users::Cols::_id = "id";
const std::string Users::Cols::_username = "username";
const std::string Users::Cols::_password = "password";
const std::string Users::Cols::_permissions = "permissions";
const std::string Users::primaryKeyName = "id";
const bool Users::hasPrimaryKey = true;
const std::string Users::tableName = "users";

const std::vector<typename Users::MetaData> Users::metaData_={
{"id","int32_t","integer",4,1,1,1},
{"username","std::string","text",0,0,0,1},
{"password","std::string","text",0,0,0,1},
{"permissions","int32_t","integer",4,0,0,1}
};
const std::string &Users::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Users::Users(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["username"].isNull())
        {
            username_=std::make_shared<std::string>(r["username"].as<std::string>());
        }
        if(!r["password"].isNull())
        {
            password_=std::make_shared<std::string>(r["password"].as<std::string>());
        }
        if(!r["permissions"].isNull())
        {
            permissions_=std::make_shared<int32_t>(r["permissions"].as<int32_t>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 4 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            username_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            password_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            permissions_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
    }

}

Users::Users(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            username_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            password_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            permissions_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[3]].asInt64());
        }
    }
}

Users::Users(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("username"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["username"].isNull())
        {
            username_=std::make_shared<std::string>(pJson["username"].asString());
        }
    }
    if(pJson.isMember("password"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["password"].isNull())
        {
            password_=std::make_shared<std::string>(pJson["password"].asString());
        }
    }
    if(pJson.isMember("permissions"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["permissions"].isNull())
        {
            permissions_=std::make_shared<int32_t>((int32_t)pJson["permissions"].asInt64());
        }
    }
}

void Users::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            username_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            password_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            permissions_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[3]].asInt64());
        }
    }
}

void Users::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("username"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["username"].isNull())
        {
            username_=std::make_shared<std::string>(pJson["username"].asString());
        }
    }
    if(pJson.isMember("password"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["password"].isNull())
        {
            password_=std::make_shared<std::string>(pJson["password"].asString());
        }
    }
    if(pJson.isMember("permissions"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["permissions"].isNull())
        {
            permissions_=std::make_shared<int32_t>((int32_t)pJson["permissions"].asInt64());
        }
    }
}

const int32_t &Users::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Users::getId() const noexcept
{
    return id_;
}
void Users::setId(const int32_t &pId) noexcept
{
    id_ = std::make_shared<int32_t>(pId);
    dirtyFlag_[0] = true;
}
const typename Users::PrimaryKeyType & Users::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &Users::getValueOfUsername() const noexcept
{
    const static std::string defaultValue = std::string();
    if(username_)
        return *username_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Users::getUsername() const noexcept
{
    return username_;
}
void Users::setUsername(const std::string &pUsername) noexcept
{
    username_ = std::make_shared<std::string>(pUsername);
    dirtyFlag_[1] = true;
}
void Users::setUsername(std::string &&pUsername) noexcept
{
    username_ = std::make_shared<std::string>(std::move(pUsername));
    dirtyFlag_[1] = true;
}

const std::string &Users::getValueOfPassword() const noexcept
{
    const static std::string defaultValue = std::string();
    if(password_)
        return *password_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Users::getPassword() const noexcept
{
    return password_;
}
void Users::setPassword(const std::string &pPassword) noexcept
{
    password_ = std::make_shared<std::string>(pPassword);
    dirtyFlag_[2] = true;
}
void Users::setPassword(std::string &&pPassword) noexcept
{
    password_ = std::make_shared<std::string>(std::move(pPassword));
    dirtyFlag_[2] = true;
}

const int32_t &Users::getValueOfPermissions() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(permissions_)
        return *permissions_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Users::getPermissions() const noexcept
{
    return permissions_;
}
void Users::setPermissions(const int32_t &pPermissions) noexcept
{
    permissions_ = std::make_shared<int32_t>(pPermissions);
    dirtyFlag_[3] = true;
}

void Users::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Users::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "username",
        "password",
        "permissions"
    };
    return inCols;
}

void Users::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getUsername())
        {
            binder << getValueOfUsername();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getPassword())
        {
            binder << getValueOfPassword();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getPermissions())
        {
            binder << getValueOfPermissions();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Users::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if(dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    if(dirtyFlag_[3])
    {
        ret.push_back(getColumnName(3));
    }
    return ret;
}

void Users::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getUsername())
        {
            binder << getValueOfUsername();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getPassword())
        {
            binder << getValueOfPassword();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getPermissions())
        {
            binder << getValueOfPermissions();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Users::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getUsername())
    {
        ret["username"]=getValueOfUsername();
    }
    else
    {
        ret["username"]=Json::Value();
    }
    if(getPassword())
    {
        ret["password"]=getValueOfPassword();
    }
    else
    {
        ret["password"]=Json::Value();
    }
    if(getPermissions())
    {
        ret["permissions"]=getValueOfPermissions();
    }
    else
    {
        ret["permissions"]=Json::Value();
    }
    return ret;
}

Json::Value Users::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 4)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getUsername())
            {
                ret[pMasqueradingVector[1]]=getValueOfUsername();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getPassword())
            {
                ret[pMasqueradingVector[2]]=getValueOfPassword();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getPermissions())
            {
                ret[pMasqueradingVector[3]]=getValueOfPermissions();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getUsername())
    {
        ret["username"]=getValueOfUsername();
    }
    else
    {
        ret["username"]=Json::Value();
    }
    if(getPassword())
    {
        ret["password"]=getValueOfPassword();
    }
    else
    {
        ret["password"]=Json::Value();
    }
    if(getPermissions())
    {
        ret["permissions"]=getValueOfPermissions();
    }
    else
    {
        ret["permissions"]=Json::Value();
    }
    return ret;
}

bool Users::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("username"))
    {
        if(!validJsonOfField(1, "username", pJson["username"], err, true))
            return false;
    }
    else
    {
        err="The username column cannot be null";
        return false;
    }
    if(pJson.isMember("password"))
    {
        if(!validJsonOfField(2, "password", pJson["password"], err, true))
            return false;
    }
    else
    {
        err="The password column cannot be null";
        return false;
    }
    if(pJson.isMember("permissions"))
    {
        if(!validJsonOfField(3, "permissions", pJson["permissions"], err, true))
            return false;
    }
    return true;
}
bool Users::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                               const std::vector<std::string> &pMasqueradingVector,
                                               std::string &err)
{
    if(pMasqueradingVector.size() != 4)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[1] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[2].empty())
      {
          if(pJson.isMember(pMasqueradingVector[2]))
          {
              if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[2] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[3].empty())
      {
          if(pJson.isMember(pMasqueradingVector[3]))
          {
              if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                  return false;
          }
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Users::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("username"))
    {
        if(!validJsonOfField(1, "username", pJson["username"], err, false))
            return false;
    }
    if(pJson.isMember("password"))
    {
        if(!validJsonOfField(2, "password", pJson["password"], err, false))
            return false;
    }
    if(pJson.isMember("permissions"))
    {
        if(!validJsonOfField(3, "permissions", pJson["permissions"], err, false))
            return false;
    }
    return true;
}
bool Users::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                             const std::vector<std::string> &pMasqueradingVector,
                                             std::string &err)
{
    if(pMasqueradingVector.size() != 4)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
      if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
      {
          if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
              return false;
      }
      if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
      {
          if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
              return false;
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Users::validJsonOfField(size_t index,
                             const std::string &fieldName,
                             const Json::Value &pJson,
                             std::string &err,
                             bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(isForCreation)
            {
                err="The automatic primary key cannot be set";
                return false;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 2:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 3:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        default:
            err="Internal error in the server";
            return false;
            break;
    }
    return true;
}
