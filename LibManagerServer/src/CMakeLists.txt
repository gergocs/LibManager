cmake_minimum_required(VERSION 3.22)
project(LibManagerServer)

set(CMAKE_CXX_STANDARD 20)

include(../cmake/get_cpm.cmake)

CPMAddPackage(
        NAME drogon
        GITHUB_REPOSITORY drogonframework/drogon
        GIT_TAG v1.9.3
)

CPMAddPackage(
        NAME frozen
        GITHUB_REPOSITORY serge-sans-paille/frozen
        GIT_TAG 3d33fb47eb38b783e709b3ac41f28a8403a15f7a
)

add_executable(LibManagerServer main.cpp
        controllers/RecordController.cc
        controllers/RecordController.h
        controllers/UserController.cc
        controllers/UserController.h
        filters/CorsFilter.cc
        filters/CorsFilter.h
        filters/LoggedInFilter.cc
        filters/LoggedInFilter.h
        models/Record.cc
        models/Record.h
        models/Users.cc
        models/Users.h
        utils/MARC/MARCProcessor.cpp
        utils/MARC/MARCProcessor.h
        utils/helpers.h
        utils/MARC/00x/ControlNumber.h
        utils/MARC/Directory.h
        utils/MARC/00x/ControlNumberIdentifier.h
        utils/MARC/00x/DateAndTimeOfLatestTransaction.h
        utils/MARC/leader/Leader.h
        utils/MARC/00x/PhysicalDescriptionFixedFieldGeneralInformation.h
        utils/MARC/enumHelpers/PhysicalDescriptionEnumHelpers.h
        utils/MARC/00x/FixedLengthDataElementsGeneralInformation.h
        utils/MARC/expections/Exception.h
        services/UserTokenStorage.h
        utils/MARC/enumHelpers/FixedLengthDataElementsEnumHelper.h
        utils/MARC/01x-09x/ISBN.h
        utils/MARC/01x-09x/ISSN.h
        utils/MARC/01x-09x/CatalogingSource.h
        utils/MARC/helpers/Constants.h
        utils/MARC/01x-09x/LanguageCode.h
        utils/MARC/01x-09x/UniversalDecimalClassificationNumber.h
        utils/MARC/1xx/MainEntryPersonalName.h
        utils/MARC/1xx/MainEntryCorporateName.h)

target_link_libraries(LibManagerServer PRIVATE drogon frozen)
