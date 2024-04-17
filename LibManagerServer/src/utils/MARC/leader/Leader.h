//
// Created by csger on 2024. 03. 17..
//

#ifndef LIBMANAGERSERVER_LEADER_H
#define LIBMANAGERSERVER_LEADER_H

#include <cstdint>
#include <string>
#include <stdexcept>
#include <iostream>

#include "../Directory.h"

namespace LibManager::MARC {

    class Leader : public Directory {
    public:
        explicit Leader(uint16_t id) = delete;

        Leader(uint16_t id, uint16_t length) = delete;

        explicit Leader(const std::string &leader) : Directory(0, 0) {
            this->processLeader(leader);
        }

        [[nodiscard]] uint8_t getRecordStatus() const {
            return recordStatus;
        }

        [[nodiscard]] uint8_t getTypeOfRecord() const {
            return typeOfRecord;
        }

        [[nodiscard]] uint8_t getBibliographicLevel() const {
            return bibliographicLevel;
        }

        [[nodiscard]] bool isTypeOfControl() const {
            return typeOfControl;
        }

        [[nodiscard]] bool isCharacterCodingScheme() const {
            return characterCodingScheme;
        }

        [[nodiscard]] uint8_t getIndicatorCount() const {
            return indicatorCount;
        }

        [[nodiscard]] uint8_t getSubfieldCodeCount() const {
            return subfieldCodeCount;
        }

        [[nodiscard]] uint32_t getBaseAddressOfData() const {
            return baseAddressOfData;
        }

        [[nodiscard]] uint8_t getEncodingLevel() const {
            return encodingLevel;
        }

        [[nodiscard]] uint8_t getDescriptiveCatalogingForm() const {
            return descriptiveCatalogingForm;
        }

        [[nodiscard]] uint8_t getMultipartResourceRecordLevel() const {
            return multipartResourceRecordLevel;
        }

        [[nodiscard]] uint8_t getLengthOfLengthOfFieldPortion() const {
            return lengthOfLengthOfFieldPortion;
        }

        [[nodiscard]] uint8_t getLengthOfStringCharacterPositionPortion() const {
            return lengthOfStringCharacterPositionPortion;
        }

        [[nodiscard]] uint8_t getLengthOfImplementationDefinedPortion() const {
            return lengthOfImplementationDefinedPortion;
        }

        [[nodiscard]] uint8_t getUndefined() const {
            return undefined;
        }

        Json::Value toJson() override {
            Json::Value value;
            value["id"] = getId();
            value["length"] = getLength();
            value["recordStatus"] = getRecordStatus();
            value["typeOfRecord"] = getTypeOfRecord();
            value["bibliographicLevel"] = getBibliographicLevel();
            value["typeOfControl"] = isTypeOfControl();
            value["characterCodingScheme"] = isCharacterCodingScheme();
            value["indicatorCount"] = getIndicatorCount();
            value["subfieldCodeCount"] = getSubfieldCodeCount();
            value["baseAddressOfData"] = getBaseAddressOfData();
            value["encodingLevel"] = getEncodingLevel();
            value["descriptiveCatalogingForm"] = getDescriptiveCatalogingForm();
            value["multipartResourceRecordLevel"] = getMultipartResourceRecordLevel();
            value["lengthOfLengthOfFieldPortion"] = getLengthOfLengthOfFieldPortion();
            value["lengthOfStringCharacterPositionPortion"] = getLengthOfStringCharacterPositionPortion();
            value["lengthOfImplementationDefinedPortion"] = getLengthOfImplementationDefinedPortion();
            value["undefined"] = getUndefined();
            return value;
        }

        enum class TypeOfRecord : uint8_t {
            LanguageMaterial = 'a',
            NotatedMusic = 'c',
            ManuscriptNotatedMusic = 'd',
            CartographicMaterial = 'e',
            ManuscriptCartographicMaterial = 'f',
            ProjectedMedium = 'g',
            NonmusicalSoundRecording = 'i',
            MusicalSoundRecording = 'j',
            TwoDimensionalNonprojectableGraphic = 'k',
            ComputerFile = 'm',
            Kit = 'o',
            MixedMaterials = 'p',
            ThreeDimensionalArtifactOrNaturallyOccurringObject = 'r',
            ManuscriptLanguageMaterial = 't'
        };

        enum class BibliographicLevel : uint8_t {
            MonographicComponentPart = 'a',
            SerialComponentPart = 'b',
            Collection = 'c',
            Subunit = 'd',
            IntegratingResource = 'i',
            MonographItem = 'm',
            Serial = 's'
        };

        enum class EncodingLevel : uint8_t {
            FullLevelMaterialNotExamined = '1',
            LessThanFullLevelMaterialNotExamined = '2',
            AbbreviatedLevel = '3',
            CoreLevel = '4',
            PartialPreliminaryLevel = '5',
            MinimalLevel = '7',
            PrepublicationLevel = '8',
            Unknown = 'u',
            NotApplicable = 'z'
        };

        enum class DescriptiveCatalogingForm : uint8_t {
            AACR2 = 'a',
            ISBDPunctuationOmitted = 'c',
            ISBDPunctuationIncluded = 'i',
            NonISBDPunctuationOmitted = 'n',
            Unknown = 'u'
        };

        enum class MultiPartResourceRecordLevel : uint8_t {
            NotSpecifiedOrNotApplicable = '#',
            Set = 'a',
            PartWithIndependentTitle = 'b',
            PartWithDependentTitle = 'c'
        };

        using TypeOfRecordEnumChecker = Helpers::EnumCheck<TypeOfRecord, TypeOfRecord::LanguageMaterial, TypeOfRecord::NotatedMusic, TypeOfRecord::ManuscriptNotatedMusic, TypeOfRecord::CartographicMaterial, TypeOfRecord::ManuscriptCartographicMaterial, TypeOfRecord::ProjectedMedium, TypeOfRecord::NonmusicalSoundRecording, TypeOfRecord::MusicalSoundRecording, TypeOfRecord::TwoDimensionalNonprojectableGraphic, TypeOfRecord::ComputerFile, TypeOfRecord::Kit, TypeOfRecord::MixedMaterials, TypeOfRecord::ThreeDimensionalArtifactOrNaturallyOccurringObject, TypeOfRecord::ManuscriptLanguageMaterial>;
        using BibliographicLevelEnumChecker = Helpers::EnumCheck<BibliographicLevel, BibliographicLevel::MonographicComponentPart, BibliographicLevel::SerialComponentPart, BibliographicLevel::Collection, BibliographicLevel::Subunit, BibliographicLevel::IntegratingResource, BibliographicLevel::MonographItem, BibliographicLevel::Serial>;
        using EncodingLevelEnumChecker = Helpers::EnumCheck<EncodingLevel, EncodingLevel::FullLevelMaterialNotExamined, EncodingLevel::LessThanFullLevelMaterialNotExamined, EncodingLevel::AbbreviatedLevel, EncodingLevel::CoreLevel, EncodingLevel::PartialPreliminaryLevel, EncodingLevel::MinimalLevel, EncodingLevel::PrepublicationLevel, EncodingLevel::Unknown, EncodingLevel::NotApplicable>;
        using DescriptiveCatalogingFormEnumChecker = Helpers::EnumCheck<DescriptiveCatalogingForm, DescriptiveCatalogingForm::AACR2, DescriptiveCatalogingForm::ISBDPunctuationOmitted, DescriptiveCatalogingForm::ISBDPunctuationIncluded, DescriptiveCatalogingForm::NonISBDPunctuationOmitted, DescriptiveCatalogingForm::Unknown>;
        using MultiPartResourceRecordLevelEnumChecker = Helpers::EnumCheck<MultiPartResourceRecordLevel, MultiPartResourceRecordLevel::NotSpecifiedOrNotApplicable, MultiPartResourceRecordLevel::Set, MultiPartResourceRecordLevel::PartWithIndependentTitle, MultiPartResourceRecordLevel::PartWithDependentTitle>;

    private:
        uint8_t recordStatus{};
        uint8_t typeOfRecord{};
        uint8_t bibliographicLevel{};
        bool typeOfControl{};
        bool characterCodingScheme{};
        uint8_t indicatorCount = 2;
        uint8_t subfieldCodeCount = 2;
        uint32_t baseAddressOfData{};
        uint8_t encodingLevel{};
        uint8_t descriptiveCatalogingForm{};
        uint8_t multipartResourceRecordLevel{};
        uint8_t lengthOfLengthOfFieldPortion = 4;
        uint8_t lengthOfStringCharacterPositionPortion = 5;
        uint8_t lengthOfImplementationDefinedPortion = 0;
        uint8_t undefined = 0;

        void processLeader(const std::string &data) {
            this->setLength(static_cast<uint32_t>(0));
            this->recordStatus = static_cast<uint8_t>('n');

            if (!TypeOfRecordEnumChecker::is_value(data[0])) {
                throw std::invalid_argument("0");
            } else {
                this->typeOfRecord = static_cast<uint8_t>(data[0]);
            }

            if (!BibliographicLevelEnumChecker::is_value(data[1])) {
                throw std::invalid_argument("1");
            } else {
                this->bibliographicLevel = static_cast<uint8_t>(data[1]);
            }

            if (data[2] == '#' || data[2] == 'a') {
                this->typeOfControl = data[2] == 'a';
            } else {
                throw std::invalid_argument("2");
            }

            this->characterCodingScheme = true; // Character coding scheme UTF8
            this->baseAddressOfData = 0; // Base address of data

            if (!EncodingLevelEnumChecker::is_value(data[17])) {
                throw std::invalid_argument("17");
            } else {
                this->encodingLevel = static_cast<uint8_t>(data[17]);
            }

            if (!DescriptiveCatalogingFormEnumChecker::is_value(data[18])) {
                throw std::invalid_argument("18");
            } else {
                this->descriptiveCatalogingForm = static_cast<uint8_t>(data[18]);
            }

            if (!MultiPartResourceRecordLevelEnumChecker::is_value(data[19])) {
                throw std::invalid_argument("19");
            } else {
                this->multipartResourceRecordLevel = static_cast<uint8_t>(data[19]);
            }
        }
    };

} // MARC
// LibManager

#endif //LIBMANAGERSERVER_LEADER_H
