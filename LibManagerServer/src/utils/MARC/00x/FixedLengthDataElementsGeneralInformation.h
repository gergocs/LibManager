//
// Created by csger on 2024. 03. 19..
//

#ifndef LIBMANAGERSERVER_FIXEDLENGTHDATAELEMENTSGENERALINFORMATION_H
#define LIBMANAGERSERVER_FIXEDLENGTHDATAELEMENTSGENERALINFORMATION_H

#include <numeric>

#include "../Directory.h"
#include "../leader/Leader.h"
#include "../enumHelpers/FixedLengthDataElementsEnumHelper.h"

namespace LibManager::MARC {

    class FixedLengthDataElementsGeneralInformation : public Directory {
    public:
        explicit FixedLengthDataElementsGeneralInformation(uint16_t id) = delete;

        FixedLengthDataElementsGeneralInformation(uint16_t id, uint16_t length) = delete;

        FixedLengthDataElementsGeneralInformation() : Directory(8, 0) {}

        explicit FixedLengthDataElementsGeneralInformation(const std::string &strData,
                                                           const Leader::TypeOfRecord typeOfRecord,
                                                           const Leader::BibliographicLevel bibliographicLevel)
                : Directory(8,
                            0) {
            this->parseData(strData, typeOfRecord, bibliographicLevel);
        };

        Json::Value toJson() override {
            Json::Value json;
            json["dateEnteredOnFile"] = this->dateEnteredOnFile;
            json["typeOfDate"] = this->typeOfDate;
            json["date"] = this->date;
            json["placeOfPublication"] = this->placeOfPublication;

            for (const auto &item: this->materialSpecificDetails) {
                json["materialSpecificDetails"][item.first] = item.second;
            }
            
            json["language"] = this->language;
            json["modifiedRecord"] = this->modifiedRecord;
            json["catalogingSource"] = this->catalogingSource;

            return json;
        }

    private:
        uint64_t dateEnteredOnFile{};
        uint8_t typeOfDate{};
        std::string date{};
        std::string placeOfPublication;
        std::map<uint8_t, uint8_t> materialSpecificDetails;
        std::string language;
        uint8_t modifiedRecord{};
        uint8_t catalogingSource{};

        static bool isBook(Leader::TypeOfRecord typeOfRecord, Leader::BibliographicLevel bibliographicLevel) {
            return (typeOfRecord == Leader::TypeOfRecord::LanguageMaterial ||
                    typeOfRecord == Leader::TypeOfRecord::ManuscriptLanguageMaterial) &&
                   (bibliographicLevel == Leader::BibliographicLevel::MonographicComponentPart ||
                    bibliographicLevel == Leader::BibliographicLevel::Subunit ||
                    bibliographicLevel == Leader::BibliographicLevel::MonographItem);
        }

        static bool isComputerFile(Leader::TypeOfRecord typeOfRecord) {
            return typeOfRecord == Leader::TypeOfRecord::ComputerFile;
        }

        static bool isMap(Leader::TypeOfRecord typeOfRecord) {
            return typeOfRecord == Leader::TypeOfRecord::CartographicMaterial ||
                   typeOfRecord == Leader::TypeOfRecord::ManuscriptCartographicMaterial;
        }

        static bool isMusic(Leader::TypeOfRecord typeOfRecord) {
            return typeOfRecord == Leader::TypeOfRecord::NotatedMusic ||
                   typeOfRecord == Leader::TypeOfRecord::ManuscriptNotatedMusic ||
                   typeOfRecord == Leader::TypeOfRecord::NonmusicalSoundRecording ||
                   typeOfRecord == Leader::TypeOfRecord::MusicalSoundRecording;
        }

        static bool
        isContinuingResource(Leader::TypeOfRecord typeOfRecord, Leader::BibliographicLevel bibliographicLevel) {
            return typeOfRecord == Leader::TypeOfRecord::LanguageMaterial &&
                   (bibliographicLevel == Leader::BibliographicLevel::Serial ||
                    bibliographicLevel == Leader::BibliographicLevel::IntegratingResource ||
                    bibliographicLevel == Leader::BibliographicLevel::SerialComponentPart);
        }

        static bool isVisualMaterial(Leader::TypeOfRecord typeOfRecord) {
            return typeOfRecord == Leader::TypeOfRecord::ProjectedMedium ||
                   typeOfRecord == Leader::TypeOfRecord::TwoDimensionalNonprojectableGraphic ||
                   typeOfRecord == Leader::TypeOfRecord::Kit ||
                   typeOfRecord == Leader::TypeOfRecord::ThreeDimensionalArtifactOrNaturallyOccurringObject;
        }

        static bool isUnspecified(Leader::TypeOfRecord typeOfRecord) {
            return typeOfRecord == Leader::TypeOfRecord::MixedMaterials;
        }

        void processBook(const std::string &strData) {
            if (strData.length() != 16) {
                throw std::invalid_argument("18");
            }

            if (!FixedLengthDataElementsEnumHelper::IllustrationsEnumChecker::is_value(strData[0])) {
                throw std::invalid_argument("18");
            } else {
                this->materialSpecificDetails[0] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::Illustrations>(strData[0]));
            }

            if (!FixedLengthDataElementsEnumHelper::IllustrationsEnumChecker::is_value(strData[1])) {
                throw std::invalid_argument("19");
            } else {
                this->materialSpecificDetails[1] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::Illustrations>(strData[1]));
            }

            if (!FixedLengthDataElementsEnumHelper::IllustrationsEnumChecker::is_value(strData[2])) {
                throw std::invalid_argument("20");
            } else {
                this->materialSpecificDetails[2] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::Illustrations>(strData[2]));
            }

            if (!FixedLengthDataElementsEnumHelper::IllustrationsEnumChecker::is_value(strData[3])) {
                throw std::invalid_argument("21");
            } else {
                this->materialSpecificDetails[3] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::Illustrations>(strData[3]));
            }

            if (!FixedLengthDataElementsEnumHelper::TargetAudienceEnumChecker::is_value(strData[4])) {
                throw std::invalid_argument("22");
            } else {
                this->materialSpecificDetails[4] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::TargetAudience>(strData[4]));
            }

            if (!FixedLengthDataElementsEnumHelper::FormOfItemBookEnumChecker::is_value(strData[5])) {
                throw std::invalid_argument("23");
            } else {
                this->materialSpecificDetails[5] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::FormOfItemBook>(strData[5]));
            }

            if (!FixedLengthDataElementsEnumHelper::NatureOfContentsEnumChecker::is_value(strData[6])) {
                throw std::invalid_argument("24");
            } else {
                this->materialSpecificDetails[6] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::NatureOfContents>(strData[6]));
            }

            if (!FixedLengthDataElementsEnumHelper::NatureOfContentsEnumChecker::is_value(strData[7])) {
                throw std::invalid_argument("25");
            } else {
                this->materialSpecificDetails[7] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::NatureOfContents>(strData[7]));
            }

            if (!FixedLengthDataElementsEnumHelper::NatureOfContentsEnumChecker::is_value(strData[8])) {
                throw std::invalid_argument("26");
            } else {
                this->materialSpecificDetails[8] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::NatureOfContents>(strData[8]));
            }

            if (!FixedLengthDataElementsEnumHelper::NatureOfContentsEnumChecker::is_value(strData[9])) {
                throw std::invalid_argument("27");
            } else {
                this->materialSpecificDetails[9] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::NatureOfContents>(strData[9]));
            }

            if (!FixedLengthDataElementsEnumHelper::GovernmentPublicationEnumChecker::is_value(strData[10])) {
                throw std::invalid_argument("28");
            } else {
                this->materialSpecificDetails[10] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::GovernmentPublication>(strData[10]));
            }

            if (!FixedLengthDataElementsEnumHelper::ConferencePublicationEnumChecker::is_value(strData[11])) {
                throw std::invalid_argument("29");
            } else {
                this->materialSpecificDetails[11] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::ConferencePublication>(strData[11]));
            }

            if (!FixedLengthDataElementsEnumHelper::FestschriftEnumChecker::is_value(strData[12])) {
                throw std::invalid_argument("30");
            } else {
                this->materialSpecificDetails[12] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::Festschrift>(strData[12]));
            }

            if (!FixedLengthDataElementsEnumHelper::IndexEnumChecker::is_value(strData[13])) {
                throw std::invalid_argument("31");
            } else {
                this->materialSpecificDetails[13] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::Index>(strData[13]));
            }

            if (strData[14] != '#') {
                throw std::invalid_argument("32");
            }

            if (!FixedLengthDataElementsEnumHelper::LiteraryFormEnumChecker::is_value(strData[15])) {
                throw std::invalid_argument("33");
            } else {
                this->materialSpecificDetails[15] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::LiteraryForm>(strData[15]));
            }

            if (!FixedLengthDataElementsEnumHelper::BiographyEnumCheker::is_value(strData[16])) {
                throw std::invalid_argument("34");
            } else {
                this->materialSpecificDetails[16] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::Biography>(strData[16]));
            }
        }

        void processComputerFile(const std::string &strData) {
            if (strData.length() != 16) {
                throw std::invalid_argument("18");
            }

            for (uint8_t i = 0; i < 4; i++) {
                if (strData[i + 6] != '#' && strData[i + 6] != '|') {
                    throw std::invalid_argument(std::to_string(i + 18));
                }
            }

            if (!FixedLengthDataElementsEnumHelper::TargetAudienceEnumChecker::is_value(strData[4])) {
                throw std::invalid_argument("22");
            } else {
                this->materialSpecificDetails[4] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::TargetAudience>(strData[4]));
            }

            if (!FixedLengthDataElementsEnumHelper::FormOfItemComputerFileEnumChecker::is_value(strData[5])) {
                throw std::invalid_argument("23");
            } else {
                this->materialSpecificDetails[5] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::FormOfItemComputerFile>(strData[5]));
            }

            for (uint8_t i = 0; i < 2; i++) {
                if (strData[i + 6] != '#' && strData[i + 6] != '|') {
                    throw std::invalid_argument(std::to_string(i + 18 + 6));
                }
            }

            if (!FixedLengthDataElementsEnumHelper::TypeOfComputerFileEnumChecker::is_value(strData[8])) {
                throw std::invalid_argument("26");
            } else {
                this->materialSpecificDetails[8] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::TypeOfComputerFile>(strData[8]));
            }

            if (strData[9] != '#' && strData[9] != '|') {
                throw std::invalid_argument("27");
            }

            if (!FixedLengthDataElementsEnumHelper::GovernmentPublicationEnumChecker::is_value(strData[10])) {
                throw std::invalid_argument("28");
            } else {
                this->materialSpecificDetails[10] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::GovernmentPublication>(strData[10]));
            }

            for (uint8_t i = 0; i < 6; i++) {
                if (strData[i + 11] != '#' && strData[i + 11] != '|') {
                    throw std::invalid_argument(std::to_string(i + 18 + 11));
                }
            }
        }

        void processMap(const std::string &strData) {
            if (strData.length() != 16) {
                throw std::invalid_argument("18");
            }

            for (uint8_t i = 0; i < 4; i++) {
                if (FixedLengthDataElementsEnumHelper::CartographicReliefEnumChecker::is_value(strData[i])) {
                    this->materialSpecificDetails[i] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::CartographicRelief>(strData[i]));
                } else {
                    throw std::invalid_argument(std::to_string(i + 18));
                }
            }

            auto projection = frozen::string(strData.substr(4, 2));

            if (std::find_if(FixedLengthDataElementsEnumHelper::Projection.begin(),
                             FixedLengthDataElementsEnumHelper::Projection.end(),
                             [&projection](const frozen::string &s) { return s == projection; }) ==
                FixedLengthDataElementsEnumHelper::Projection.end()) {
                throw std::invalid_argument("22");
            }

            if (strData[6] != '#' && strData[6] != '|') {
                throw std::invalid_argument("24");
            }

            if (!FixedLengthDataElementsEnumHelper::TypeOfCartographicMaterialEnumChecker::is_value(strData[7])) {
                throw std::invalid_argument("25");
            } else {
                this->materialSpecificDetails[7] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::TypeOfCartographicMaterial>(strData[7]));
            }

            for (uint8_t i = 0; i < 2; i++) {
                if (strData[i + 8] != '#' && strData[i + 8] != '|') {
                    throw std::invalid_argument("26");
                }
            }

            if (!FixedLengthDataElementsEnumHelper::GovernmentPublicationEnumChecker::is_value(strData[10])) {
                throw std::invalid_argument("28");
            } else {
                this->materialSpecificDetails[10] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::GovernmentPublication>(strData[10]));
            }

            if (!FixedLengthDataElementsEnumHelper::FormOfItemMapEnumChecker::is_value(strData[11])) {
                throw std::invalid_argument("29");
            } else {
                this->materialSpecificDetails[11] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::FormOfItemMap>(strData[11]));
            }

            if (strData[12] != '#' && strData[12] != '|') {
                throw std::invalid_argument("30");
            }

            if (!FixedLengthDataElementsEnumHelper::IndexEnumChecker::is_value(strData[13])) {
                throw std::invalid_argument("31");
            } else {
                this->materialSpecificDetails[13] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::Index>(strData[13]));
            }

            if (strData[14] != '#' && strData[14] != '|') {
                throw std::invalid_argument("32");
            }

            if (!FixedLengthDataElementsEnumHelper::SpecialFormatCharacteristicsEnumChecker::is_value(strData[15])) {
                throw std::invalid_argument("33");
            } else {
                this->materialSpecificDetails[15] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::SpecialFormatCharacteristics>(strData[15]));
            }

            if (!FixedLengthDataElementsEnumHelper::SpecialFormatCharacteristicsEnumChecker::is_value(strData[16])) {
                throw std::invalid_argument("34");
            } else {
                this->materialSpecificDetails[16] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::SpecialFormatCharacteristics>(strData[16]));
            }
        }

        void processMusic(const std::string &strData) {
            if (strData.length() != 16) {
                throw std::invalid_argument("18");
            }

            auto formOfMusic = frozen::string(strData.substr(0, 2));

            if (std::find_if(FixedLengthDataElementsEnumHelper::FormOfComposition.begin(),
                             FixedLengthDataElementsEnumHelper::FormOfComposition.end(),
                             [&formOfMusic](const frozen::string &s) { return s == formOfMusic; }) ==
                FixedLengthDataElementsEnumHelper::FormOfComposition.end()) {
                throw std::invalid_argument("18");
            }

            if (!FixedLengthDataElementsEnumHelper::FormatOfMusicEnumChecker::is_value(strData[2])) {
                throw std::invalid_argument("2");
            } else {
                this->materialSpecificDetails[2] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::FormatOfMusic>(strData[2]));
            }

            if (!FixedLengthDataElementsEnumHelper::MusicPartsEnumChecker::is_value(strData[3])) {
                throw std::invalid_argument("3");
            } else {
                this->materialSpecificDetails[3] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::MusicParts>(strData[3]));
            }

            if (!FixedLengthDataElementsEnumHelper::TargetAudienceEnumChecker::is_value(strData[4])) {
                throw std::invalid_argument("4");
            } else {
                this->materialSpecificDetails[4] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::TargetAudience>(strData[4]));
            }

            if (!FixedLengthDataElementsEnumHelper::FormOfItemMusicEnumChecker::is_value(strData[5])) {
                throw std::invalid_argument("5");
            } else {
                this->materialSpecificDetails[5] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::FormOfItemMusic>(strData[5]));
            }

            for (uint8_t i = 0; i < 6; i++) {
                if (!FixedLengthDataElementsEnumHelper::AccompanyingMatterEnumChecker::is_value(strData[i + 6])) {
                    throw std::invalid_argument(std::to_string(i + 6 + 18));
                } else {
                    this->materialSpecificDetails[i +
                                                  6] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::AccompanyingMatter>(strData[
                            i + 6]));
                }
            }

            if (!FixedLengthDataElementsEnumHelper::LiteraryTestForSoundRecordingsEnumChecker::is_value(strData[12])) {
                throw std::invalid_argument("30");
            } else {
                this->materialSpecificDetails[12] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::LiteraryTestForSoundRecordings>(strData[12]));
            }

            if (!FixedLengthDataElementsEnumHelper::LiteraryTestForSoundRecordingsEnumChecker::is_value(strData[13])) {
                throw std::invalid_argument("31");
            } else {
                this->materialSpecificDetails[13] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::LiteraryTestForSoundRecordings>(strData[13]));
            }

            if (strData[14] != '#' && strData[14] != '|') {
                throw std::invalid_argument("32");
            }

            if (!FixedLengthDataElementsEnumHelper::TranspositionAndArrangementEnumChecker::is_value(strData[15])) {
                throw std::invalid_argument("33");
            } else {
                this->materialSpecificDetails[15] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::TranspositionAndArrangement>(strData[15]));
            }

            if (strData[16] != '#' && strData[16] != '|') {
                throw std::invalid_argument("34");
            }
        }

        void processContinouingResource(const std::string &strData) {
            if (strData.length() != 16) {
                throw std::invalid_argument("18");
            }

            if (!FixedLengthDataElementsEnumHelper::FrequencyEnumChecker::is_value(strData[0])) {
                throw std::invalid_argument("18");
            } else {
                this->materialSpecificDetails[0] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::Frequency>(strData[0]));
            }

            if (!FixedLengthDataElementsEnumHelper::RegularityEnumChecker::is_value(strData[1])) {
                throw std::invalid_argument("19");
            } else {
                this->materialSpecificDetails[1] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::Regularity>(strData[1]));
            }

            if (strData[2] != '#' && strData[2] != '|') {
                throw std::invalid_argument("20");
            }

            if (!FixedLengthDataElementsEnumHelper::TypeOfContinuingResourceEnumChecker::is_value(strData[3])) {
                throw std::invalid_argument("21");
            } else {
                this->materialSpecificDetails[3] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::TypeOfContinuingResource>(strData[3]));
            }

            if (!FixedLengthDataElementsEnumHelper::FormOfOriginalItemContinuingResourcesEnumChecker::is_value(
                    strData[4])) {
                throw std::invalid_argument("22");
            } else {
                this->materialSpecificDetails[4] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::FormOfOriginalItemContinuingResources>(strData[4]));
            }

            if (!FixedLengthDataElementsEnumHelper::FormOfItemConitnuingResourcesEnumChecker::is_value(strData[5])) {
                throw std::invalid_argument("23");
            } else {
                this->materialSpecificDetails[5] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::FormOfItemConitnuingResources>(strData[5]));
            }

            if (!FixedLengthDataElementsEnumHelper::NatureOfEntireWorkEnumChecker::is_value(strData[6])) {
                throw std::invalid_argument("24");
            } else {
                this->materialSpecificDetails[6] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::NatureOfEntireWork>(strData[6]));
            }

            for (uint8_t i = 0; i < 3; i++) {
                if (!FixedLengthDataElementsEnumHelper::NatureOfContentsContinuingResourcesEnumChecker::is_value(
                        strData[i + 7])) {
                    throw std::invalid_argument(std::to_string(i + 7 + 18));
                } else {
                    this->materialSpecificDetails[i +
                                                  7] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::NatureOfContentsContinuingResources>(strData[
                            i + 7]));
                }
            }

            if (!FixedLengthDataElementsEnumHelper::GovernmentPublicationEnumChecker::is_value(strData[10])) {
                throw std::invalid_argument("28");
            } else {
                this->materialSpecificDetails[10] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::GovernmentPublication>(strData[10]));
            }

            if (!FixedLengthDataElementsEnumHelper::ConferencePublicationEnumChecker::is_value(strData[11])) {
                throw std::invalid_argument("29");
            } else {
                this->materialSpecificDetails[11] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::ConferencePublication>(strData[11]));
            }

            for (uint8_t i = 0; i < 3; i++) {
                if (strData[i + 12] != '#' && strData[i + 12] != '|') {
                    throw std::invalid_argument(std::to_string(i + 12 + 18));
                }
            }

            if (!FixedLengthDataElementsEnumHelper::OriginalAlphabetOrScriptOfTitleEnumChecker::is_value(strData[15])) {
                throw std::invalid_argument("33");
            } else {
                this->materialSpecificDetails[15] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::OriginalAlphabetOrScriptOfTitle>(strData[15]));
            }

            if (!FixedLengthDataElementsEnumHelper::EntryConventionEnumChecker::is_value(strData[16])) {
                throw std::invalid_argument("34");
            } else {
                this->materialSpecificDetails[16] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::EntryConvention>(strData[16]));
            }
        }

        void processVisualMaterial(const std::string &strData) {
            if (strData.length() != 16) {
                throw std::invalid_argument("18");
            }

            auto runningTime = strData.substr(0, 3);

            if (runningTime == "000" || runningTime == "nnn" || runningTime == "---" || runningTime == "|||") {
                this->materialSpecificDetails[0] = runningTime[0];
                this->materialSpecificDetails[1] = runningTime[1];
                this->materialSpecificDetails[2] = runningTime[2];
            } else {
                for (size_t i = 0; i < runningTime.length(); i++) {
                    if (!std::isdigit(runningTime[i])) {
                        throw std::invalid_argument(std::to_string(i + 18));
                    }

                    this->materialSpecificDetails[i] = runningTime[i];
                }
            }

            if (strData[3] != '#' && strData[3] != '|') {
                throw std::invalid_argument("21");
            }

            if (!FixedLengthDataElementsEnumHelper::TargetAudienceEnumChecker::is_value(strData[4])) {
                throw std::invalid_argument("22");
            } else {
                this->materialSpecificDetails[4] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::TargetAudience>(strData[4]));
            }

            for (uint8_t i = 0; i < 5; i++) {
                if (strData[i + 5] != '#' && strData[i + 5] != '|') {
                    throw std::invalid_argument(std::to_string(i + 23));
                }
            }

            if (!FixedLengthDataElementsEnumHelper::GovernmentPublicationEnumChecker::is_value(strData[10])) {
                throw std::invalid_argument("28");
            } else {
                this->materialSpecificDetails[10] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::GovernmentPublication>(strData[10]));
            }

            if (!FixedLengthDataElementsEnumHelper::FormOfItemVisualMaterialsEnumChecker::is_value(strData[11])) {
                throw std::invalid_argument("29");
            } else {
                this->materialSpecificDetails[11] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::FormOfItemVisualMaterials>(strData[11]));
            }

            for (uint8_t i = 0; i < 3; i++) {
                if (strData[i + 12] != '#' && strData[i + 12] != '|') {
                    throw std::invalid_argument(std::to_string(i + 30));
                }
            }

            if (!FixedLengthDataElementsEnumHelper::TypeOfVisualMaterialEnumChecker::is_value(strData[15])) {
                throw std::invalid_argument("33");
            } else {
                this->materialSpecificDetails[15] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::TypeOfVisualMaterial>(strData[15]));
            }

            if (!FixedLengthDataElementsEnumHelper::TechniqueEnumChecker::is_value(strData[16])) {
                throw std::invalid_argument("34");
            } else {
                this->materialSpecificDetails[16] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::Technique>(strData[16]));
            }
        }

        void processUnspecified(const std::string &strData) {
            if (strData.length() != 16) {
                throw std::invalid_argument("18");
            }

            for (uint8_t i = 0; i < 5; i++) {
                if (strData[i] != '#' && strData[i] != '|') {
                    throw std::invalid_argument(std::to_string(i + 18));
                }
            }

            if (!FixedLengthDataElementsEnumHelper::FormOfItemUnspecifiedEnumChecker::is_value(strData[5])) {
                throw std::invalid_argument("23");
            } else {
                this->materialSpecificDetails[5] = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::FormOfItemUnspecified>(strData[5]));
            }

            for (uint8_t i = 0; i < 10; i++) {
                if (strData[i + 6] != '#' && strData[i + 6] != '|') {
                    throw std::invalid_argument(std::to_string(i + 24));
                }
            }
        }

        void parseData(const std::string &strData, Leader::TypeOfRecord typeOfRecord,
                       Leader::BibliographicLevel bibliographicLevel) {
            if (strData.length() != 40) {
                throw std::invalid_argument("0");
            }

            if (!FixedLengthDataElementsEnumHelper::TypeOfDateEnumChecker::is_value(strData[7])) {
                throw std::invalid_argument("7");
            } else {
                this->typeOfDate = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::TypeOfDate>(strData[7]));
            }

            this->date = strData.substr(7, 8);

            for (size_t i = 0; i < this->date.length(); i++) {
                if (!std::isdigit(this->date[i]) && this->date[i] != '#' && this->date[i] != 'u' &&
                    this->date[i] != '|') {
                    throw std::invalid_argument("0");
                }

                if (this->date[i] == '|') {
                    if ((i != 0 && i != 3)) {
                        throw std::invalid_argument(std::to_string(i + 7));
                    } else {
                        i += 3;
                    }
                }
            }

            this->placeOfPublication = strData.substr(15, 3);

            bool isGood = true;

            if (this->placeOfPublication == "xx#" || this->placeOfPublication == "vp#") {
                isGood = true;
            } else {
                for (size_t i = 0; i < this->placeOfPublication.length(); i++) {
                    if ((!std::isalpha(this->placeOfPublication[i]) && this->placeOfPublication[i] != '#') ||
                        this->placeOfPublication[i] == '#' && i != 2) {
                        isGood = false;
                        break;
                    }
                }
            }

            if (!isGood) {
                throw std::invalid_argument("15");
            }

            std::string strMaterialSpecificDetails = strData.substr(18, 16);

            if (isBook(typeOfRecord, bibliographicLevel)) {
                this->processBook(strMaterialSpecificDetails);
            } else if (isComputerFile(typeOfRecord)) {
                this->processComputerFile(strMaterialSpecificDetails);
            } else if (isMap(typeOfRecord)) {
                this->processMap(strMaterialSpecificDetails);
            } else if (isMusic(typeOfRecord)) {
                this->processMusic(strMaterialSpecificDetails);
            } else if (isContinuingResource(typeOfRecord, bibliographicLevel)) {
                this->processContinouingResource(strMaterialSpecificDetails);
            } else if (isVisualMaterial(typeOfRecord)) {
                this->processVisualMaterial(strMaterialSpecificDetails);
            } else if (isUnspecified(typeOfRecord)) {
                this->processUnspecified(strMaterialSpecificDetails);
            } else {
                throw std::invalid_argument("8");
            }

            this->language = strData.substr(35, 3);

            isGood = true;

            if (this->language == "|||" || this->language == "###" || this->language == "zxx" ||
                this->language == "mul" || this->language == "sgn" || this->language == "und") {
                isGood = true;
            } else {
                for (size_t i = 0; i < this->language.length(); i++) {
                    if (!std::isalpha(this->language[i])) {
                        isGood = false;
                        break;
                    }
                }
            }

            if (!isGood) {
                throw std::invalid_argument("35");
            }

            if (!FixedLengthDataElementsEnumHelper::ModifiedRecordEnumChecker::is_value(strData[38])) {
                throw std::invalid_argument("38");
            } else {
                this->modifiedRecord = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::ModifiedRecord>(strData[38]));
            }

            if (!FixedLengthDataElementsEnumHelper::CatalogingSourceEnumChecker::is_value(strData[39])) {
                throw std::invalid_argument("39");
            } else {
                this->catalogingSource = static_cast<uint8_t>(static_cast<FixedLengthDataElementsEnumHelper::CatalogingSource>(strData[39]));
            }
        };
    };

} // MARC
// LibManager

#endif //LIBMANAGERSERVER_FIXEDLENGTHDATAELEMENTSGENERALINFORMATION_H
