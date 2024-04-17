//
// Created by csger on 2024. 03. 16..
//

#ifndef LIBMANAGERSERVER_MARCPROCESSOR_H
#define LIBMANAGERSERVER_MARCPROCESSOR_H

#include <string>
#include <map>
#include <vector>
#include <set>
#include "frozen/string.h"
#include "frozen/map.h"
#include "frozen/unordered_map.h"
#include "Directory.h"
#include "../helpers.h"


/*
 * 111
 * 130
 * 240
 * 245
 * 246
 * 250
 * 260
 * 300
 * 490
 * 500
 * 504
 * 505
 * 583
 * 600
 * 650
 * 651
 * 700
 * 710
 * 711
 * 730
 * 740
 * 830
 */

namespace LibManager::MARC {
    class MARCProcessor {
    public:
        explicit MARCProcessor(std::string strData);

        explicit MARCProcessor(const Json::Value &json);

        void processData();

        std::vector<std::shared_ptr<Directory>> getFields();

        std::shared_ptr<Directory> getField(uint16_t field);

        bool isFieldExist(uint16_t field);

        [[nodiscard]] std::string getStrData() const;

        Json::Value toJson();

        enum class MARCNum : uint16_t {
            Leader = 0,
            ControlNumber = 1,
            ControlNumberIdentifier = 3,
            DateAndTimeOfLatestTransaction = 5,
            FixedLengthDataElementsAdditionalMaterialCharacteristics = 6,
            PhysicalDescriptionFixedField = 7,
            FixedLengthDataElements = 8,
            ISBN = 20,
            ISSN = 22,
            CatalogingSource = 40,
            LanguageCode = 41,
            UniversalDecimalClassificationNumber = 80,
            MainEntryPersonalName = 100,
            MainEntryCorporateName = 110,
            MARCNumCount = 13 // Count of MARCNum UPDATE ALWAYS
        };

        using MARCNumEnumChecker = Helpers::EnumCheck<MARCNum, MARCNum::Leader, MARCNum::ControlNumber, MARCNum::ControlNumberIdentifier, MARCNum::DateAndTimeOfLatestTransaction, MARCNum::FixedLengthDataElementsAdditionalMaterialCharacteristics, MARCNum::PhysicalDescriptionFixedField, MARCNum::FixedLengthDataElements>;
    private:
        std::string strData;
        std::vector<std::shared_ptr<Directory>> dataFieldsArray;
        std::set<MARCNum> seenFields{};

        [[maybe_unused]] static constexpr frozen::unordered_map<MARCNum, frozen::string, static_cast<uint16_t>(MARCNum::MARCNumCount)> MarcNumStr = {
                {MARCNum::ControlNumber,                                            "Control Number"},
                {MARCNum::ControlNumberIdentifier,                                  "Control Number Identifier"},
                {MARCNum::DateAndTimeOfLatestTransaction,                           "Date and Time of Latest Transaction"},
                {MARCNum::FixedLengthDataElementsAdditionalMaterialCharacteristics, "Fixed-Length Data Elements - Additional Material Characteristics"},
                {MARCNum::PhysicalDescriptionFixedField,                            "Physical Description Fixed Field"},
                {MARCNum::FixedLengthDataElements,                                  "Fixed-Length Data Elements"},
                {MARCNum::ISBN,                                                     "ISBN"},
                {MARCNum::ISSN,                                                     "ISSN"},
                {MARCNum::CatalogingSource,                                         "Cataloging Source"},
                {MARCNum::LanguageCode,                                             "Language Code"},
                {MARCNum::UniversalDecimalClassificationNumber,                     "Universal Decimal Classification Number"},
                {MARCNum::MainEntryPersonalName,                                    "Main Entry - Personal Name"},
                {MARCNum::MainEntryCorporateName,                                   "Main Entry - Corporate Name"},
        };

        static std::string resolveNum(MARCNum num);

        static std::array<std::string, 2> readControlNumber();

        void processMap();

        void processStr();
    };

} // MARC
// LibManager

#endif //LIBMANAGERSERVER_MARCPROCESSOR_H
