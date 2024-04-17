//
// Created by csger on 2024. 03. 17..
//

#ifndef LIBMANAGERSERVER_PHYSICALDESCRIPTIONFIXEDFIELDGENERALINFORMATION_H
#define LIBMANAGERSERVER_PHYSICALDESCRIPTIONFIXEDFIELDGENERALINFORMATION_H

#include <string>
#include <stdexcept>
#include <map>

#include "../Directory.h"
#include "../../helpers.h"
#include "../enumHelpers/PhysicalDescriptionEnumHelpers.h"

//TODO: replace magic numbers with constants

namespace LibManager::MARC {

    class PhysicalDescriptionFixedFieldGeneralInformation : public Directory {
    public:
        explicit PhysicalDescriptionFixedFieldGeneralInformation(uint16_t id) = delete;

        PhysicalDescriptionFixedFieldGeneralInformation(uint16_t id, uint16_t length) = delete;

        explicit PhysicalDescriptionFixedFieldGeneralInformation(const std::string &strData) : Directory(7, 0) {
            this->processStr(strData);
        }

        Json::Value toJson() override {
            Json::Value value;
            value["id"] = getId();
            value["length"] = getLength();
            value["categoryOfMaterial"] = static_cast<uint8_t>(this->categoryOfMaterial);
            value["specificMaterialDesignation"] = static_cast<uint8_t>(this->specificMaterialDesignation);

            for (const auto &item: this->otherPhysicalDetails) {
                value["otherPhysicalDetails"][item.first] = item.second;
            }

            return value;
        }

    private:
        PhysicalDescriptionEnumHelpers::Material categoryOfMaterial = PhysicalDescriptionEnumHelpers::Material::Unspecified;
        uint8_t specificMaterialDesignation{};
        std::map<uint8_t, uint8_t> otherPhysicalDetails;

        void processMap(const std::string &strData) {
            if (strData.length() != 8) {
                throw std::invalid_argument(std::to_string(strData.length()));
            }

            if (!PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationMapEnumChecker::is_value(strData[1])) {
                throw std::invalid_argument("1");
            } else {
                this->specificMaterialDesignation = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationMap>(strData[1]));
            }

            if (strData[2] != '#') {
                throw std::invalid_argument("2");
            }

            if (!PhysicalDescriptionEnumHelpers::ColorMapGlobeEnumChecker::is_value(strData[3])) {
                throw std::invalid_argument("3");
            } else {
                this->otherPhysicalDetails[3] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::ColorMapGlobe>(strData[3]));
            }

            if (!PhysicalDescriptionEnumHelpers::PhysicalMediumMapEnumChecker::is_value(strData[4])) {
                throw std::invalid_argument("4");
            } else {
                this->otherPhysicalDetails[4] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::PhysicalMediumMap>(strData[4]));
            }

            if (!PhysicalDescriptionEnumHelpers::TypeOfReproductionEnumChecker::is_value(strData[5])) {
                throw std::invalid_argument("5");
            } else {
                this->otherPhysicalDetails[5] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::TypeOfReproduction>(strData[5]));
            }

            if (!PhysicalDescriptionEnumHelpers::ProductionDetailsEnumChecker::is_value(strData[6])) {
                throw std::invalid_argument("6");
            } else {
                this->otherPhysicalDetails[6] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::ProductionDetails>(strData[6]));
            }

            if (!PhysicalDescriptionEnumHelpers::PositiveNegativeAspectEnumChecker::is_value(strData[7])) {
                throw std::invalid_argument("7");
            } else {
                this->otherPhysicalDetails[7] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::PositiveNegativeAspect>(strData[7]));
            }
        }

        void processElectronic(const std::string &strData) {
            if (strData.length() != 14) {
                throw std::invalid_argument(std::to_string(strData.length()));
            }

            if (!PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationElectronicResourceEnumChecker::is_value(strData[1])) {
                throw std::invalid_argument("1");
            } else {
                this->specificMaterialDesignation = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationElectronicResource>(strData[1]));
            }

            if (strData[2] != '#') {
                throw std::invalid_argument("2");
            }

            if (!PhysicalDescriptionEnumHelpers::ColorElectricEnumChecker::is_value(strData[3])) {
                throw std::invalid_argument("3");
            } else {
                this->otherPhysicalDetails[3] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::ColorMapGlobe>(strData[3]));
            }

            if (!PhysicalDescriptionEnumHelpers::DimensionElectricEnumChecker::is_value(strData[4])) {
                throw std::invalid_argument("4");
            } else {
                this->otherPhysicalDetails[4] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::DimensionElectric>(strData[4]));
            }

            if (!PhysicalDescriptionEnumHelpers::SoundElectricEnumChecker::is_value(strData[5])) {
                throw std::invalid_argument("5");
            } else {
                this->otherPhysicalDetails[5] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SoundElectric>(strData[5]));
            }

            std::string bitDepth = strData.substr(6, 3);

            if (!Helpers::is_number(bitDepth)) {
                if (bitDepth != "mmm" && bitDepth != "nnn" && bitDepth != "---" && bitDepth != "|||") {
                    throw std::invalid_argument("6");
                } else {
                    this->otherPhysicalDetails[6] = 0;
                    this->otherPhysicalDetails[7] = bitDepth[0];
                }
            } else {
                this->otherPhysicalDetails[6] = static_cast<uint8_t>(std::stoi(bitDepth));
            }

            if (!PhysicalDescriptionEnumHelpers::FileFormatElectricEnumChecker::is_value(strData[9])) {
                throw std::invalid_argument("9");
            } else {
                this->otherPhysicalDetails[9] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::FileFormatElectric>(strData[9]));
            }

            if (!PhysicalDescriptionEnumHelpers::QualityAssuranceTargetElectricEnumChecker::is_value(strData[10])) {
                throw std::invalid_argument("10");
            } else {
                this->otherPhysicalDetails[10] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::QualityAssuranceTargetElectric>(strData[10]));
            }

            if (!PhysicalDescriptionEnumHelpers::AntecedentSourceElectricEnumChecker::is_value(strData[11])) {
                throw std::invalid_argument("11");
            } else {
                this->otherPhysicalDetails[11] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::AntecedentSourceElectric>(strData[11]));
            }

            if (!PhysicalDescriptionEnumHelpers::LevelOfCompressionElectricEnumChecker::is_value(strData[12])) {
                throw std::invalid_argument("12");
            } else {
                this->otherPhysicalDetails[12] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::LevelOfCompressionElectric>(strData[12]));
            }

            if (!PhysicalDescriptionEnumHelpers::ReformattingQualityElectricEnumChecker::is_value(strData[13])) {
                throw std::invalid_argument("13");
            } else {
                this->otherPhysicalDetails[13] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::ReformattingQualityElectric>(strData[13]));
            }
        }

        void processGlobe(const std::string &strData) {
            if (strData.length() != 6) {
                throw std::invalid_argument(std::to_string(strData.length()));
            }

            if (!PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationGlobeEnumChecker::is_value(strData[1])) {
                throw std::invalid_argument("1");
            } else {
                this->specificMaterialDesignation = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationGlobe>(strData[1]));
            }

            if (strData[2] != '#') {
                throw std::invalid_argument("2");
            }

            if (!PhysicalDescriptionEnumHelpers::ColorMapGlobeEnumChecker::is_value(strData[3])) {
                throw std::invalid_argument("3");
            } else {
                this->otherPhysicalDetails[3] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::ColorMapGlobe>(strData[3]));
            }

            if (!PhysicalDescriptionEnumHelpers::PhysicalMediumGlobeEnumChecker::is_value(strData[4])) {
                throw std::invalid_argument("4");
            } else {
                this->otherPhysicalDetails[4] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::PhysicalMediumGlobe>(strData[4]));
            }

            if (!PhysicalDescriptionEnumHelpers::TypeOfReproductionEnumChecker::is_value(strData[5])) {
                throw std::invalid_argument("5");
            } else {
                this->otherPhysicalDetails[5] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::TypeOfReproduction>(strData[5]));
            }
        }

        void processTactileMaterial(const std::string &strData) {
            if (strData.length() != 10) {
                throw std::invalid_argument(std::to_string(strData.length()));
            }

            if (!PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationTactileMaterialEnumChecker::is_value(strData[1])) {
                throw std::invalid_argument("1");
            } else {
                this->specificMaterialDesignation = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationTactileMaterial>(strData[1]));
            }

            if (strData[2] != '#') {
                throw std::invalid_argument("2");
            }

            if (!PhysicalDescriptionEnumHelpers::ClassOfBrailleWritingEnumChecker::is_value(strData[3])) {
                throw std::invalid_argument("3");
            } else {
                this->otherPhysicalDetails[3] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::ClassOfBrailleWriting>(strData[3]));
            }

            if (!PhysicalDescriptionEnumHelpers::ClassOfBrailleWritingEnumChecker::is_value(strData[4])) {
                throw std::invalid_argument("4");
            } else {
                this->otherPhysicalDetails[4] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::ClassOfBrailleWriting>(strData[4]));
            }

            if (!PhysicalDescriptionEnumHelpers::LevelOfContractionEnumChecker::is_value(strData[5])) {
                throw std::invalid_argument("5");
            } else {
                this->otherPhysicalDetails[5] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::LevelOfContraction>(strData[5]));
            }

            if (!PhysicalDescriptionEnumHelpers::BrailleMusicFormatEnumChecker::is_value(strData[6])) {
                throw std::invalid_argument("6");
            } else {
                this->otherPhysicalDetails[6] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::BrailleMusicFormat>(strData[6]));
            }

            if (!PhysicalDescriptionEnumHelpers::BrailleMusicFormatEnumChecker::is_value(strData[7])) {
                throw std::invalid_argument("7");
            } else {
                this->otherPhysicalDetails[7] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::BrailleMusicFormat>(strData[7]));
            }

            if (!PhysicalDescriptionEnumHelpers::BrailleMusicFormatEnumChecker::is_value(strData[8])) {
                throw std::invalid_argument("8");
            } else {
                this->otherPhysicalDetails[8] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::BrailleMusicFormat>(strData[8]));
            }

            if (!PhysicalDescriptionEnumHelpers::SpecialPhysicalCharacteristicsTactileEnumChecker::is_value(strData[9])) {
                throw std::invalid_argument("9");
            } else {
                this->otherPhysicalDetails[9] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SpecialPhysicalCharacteristicsTactile>(strData[9]));
            }
        }

        void processProjectedGraphic(const std::string &strData) {
            if (strData.length() != 9) {
                throw std::invalid_argument(std::to_string(strData.length()));
            }

            if (!PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationProjectedEnumChecker::is_value(strData[1])) {
                throw std::invalid_argument("1");
            } else {
                this->specificMaterialDesignation = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationProjected>(strData[1]));
            }

            if (strData[2] != '#') {
                throw std::invalid_argument("2");
            }

            if (!PhysicalDescriptionEnumHelpers::ColorProjectedEnumChecker::is_value(strData[3])) {
                throw std::invalid_argument("3");
            } else {
                this->otherPhysicalDetails[3] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::ColorProjected>(strData[3]));
            }

            if (!PhysicalDescriptionEnumHelpers::BaseOfEmulsionProjectedEnumChecker::is_value(strData[4])) {
                throw std::invalid_argument("4");
            } else {
                this->otherPhysicalDetails[4] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::BaseOfEmulsionProjected>(strData[4]));
            }

            if (!PhysicalDescriptionEnumHelpers::SoundOnMediumProjectedMotionPictureEnumChecker::is_value(strData[5])) {
                throw std::invalid_argument("5");
            } else {
                this->otherPhysicalDetails[5] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SoundOnMediumProjectedMotionPicture>(strData[5]));
            }

            if (!PhysicalDescriptionEnumHelpers::MediumForSoundEnumChecker::is_value(strData[6])) {
                throw std::invalid_argument("6");
            } else {
                this->otherPhysicalDetails[6] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::MediumForSoundProjected>(strData[6]));
            }

            if (!PhysicalDescriptionEnumHelpers::DimensionProjectedEnumChecker::is_value(strData[7])) {
                throw std::invalid_argument("7");
            } else {
                this->otherPhysicalDetails[7] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::DimensionProjected>(strData[7]));
            }

            if (!PhysicalDescriptionEnumHelpers::SecondarySupportMaterialProjectedEnumChecker::is_value(strData[8])) {
                throw std::invalid_argument("8");
            } else {
                this->otherPhysicalDetails[8] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SecondarySupportMaterialProjected>(strData[8]));
            }
        }

        void processMicroform(const std::string &strData) {
            if (strData.length() != 13) {
                throw std::invalid_argument(std::to_string(strData.length()));
            }

            if (!PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationMicroformEnumChecker::is_value(strData[1])) {
                throw std::invalid_argument("1");
            } else {
                this->specificMaterialDesignation = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationMicroform>(strData[1]));
            }

            if (strData[2] != '#') {
                throw std::invalid_argument("2");
            }

            if (!PhysicalDescriptionEnumHelpers::PositiveNegativeAspectEnumChecker::is_value(strData[3])) {
                throw std::invalid_argument("3");
            } else {
                this->otherPhysicalDetails[3] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::PositiveNegativeAspect>(strData[3]));
            }

            if (!PhysicalDescriptionEnumHelpers::DimensionMicroformEnumChecker::is_value(strData[4])) {
                throw std::invalid_argument("4");
            } else {
                this->otherPhysicalDetails[4] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::DimensionMicroform>(strData[4]));
            }

            if (!PhysicalDescriptionEnumHelpers::ReductionRatioRangeEnumChecker::is_value(strData[5])) {
                throw std::invalid_argument("5");
            } else {
                this->otherPhysicalDetails[5] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::ReductionRatioRange>(strData[5]));
            }

            std::string ratio = strData.substr(6, 3);

            for (size_t i = 0; i < ratio.length(); i++) {
                if (std::isdigit(ratio[i])) {
                    this->otherPhysicalDetails[6 + i] = static_cast<uint8_t>(std::stoi(ratio));
                } else if (ratio[i] == '-') {
                    this->otherPhysicalDetails[6 + i] = static_cast<uint8_t>(0);
                } else {
                    throw std::invalid_argument("6");

                }
            }

            if (!PhysicalDescriptionEnumHelpers::ColorMicroformEnumChecker::is_value(strData[9])) {
                throw std::invalid_argument("9");
            } else {
                this->otherPhysicalDetails[9] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::ColorMicroform>(strData[9]));
            }

            if (!PhysicalDescriptionEnumHelpers::EmulsionOnFilmEnumChecker::is_value(strData[10])) {
                throw std::invalid_argument("10");
            } else {
                this->otherPhysicalDetails[10] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::EmulsionOnFilm>(strData[10]));
            }

            if (!PhysicalDescriptionEnumHelpers::GenerationEnumChecker::is_value(strData[11])) {
                throw std::invalid_argument("11");
            } else {
                this->otherPhysicalDetails[11] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::GenerationMicroform>(strData[11]));
            }

            if (!PhysicalDescriptionEnumHelpers::BaseOfFilmEnumChecker::is_value(strData[12])) {
                throw std::invalid_argument("12");
            } else {
                this->otherPhysicalDetails[12] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::BaseOfFilm>(strData[12]));
            }
        }

        void processNonProjectedGraphic(const std::string &strData) {
            if (strData.length() != 6) {
                throw std::invalid_argument(std::to_string(strData.length()));
            }

            if (!PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationNonProjectedEnumChecker::is_value(strData[1])) {
                throw std::invalid_argument("1");
            } else {
                this->specificMaterialDesignation = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationNonProjected>(strData[1]));
            }

            if (strData[2] != '#') {
                throw std::invalid_argument("2");
            }

            if (!PhysicalDescriptionEnumHelpers::ColorNonProjectedEnumChecker::is_value(strData[3])) {
                throw std::invalid_argument("3");
            } else {
                this->otherPhysicalDetails[3] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::ColorNonProjected>(strData[3]));
            }

            if (!PhysicalDescriptionEnumHelpers::PrimarySupportMaterialEnumChecker::is_value(strData[4])) {
                throw std::invalid_argument("4");
            } else {
                this->otherPhysicalDetails[4] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::PrimarySupportMaterial>(strData[4]));
            }

            if (!PhysicalDescriptionEnumHelpers::SecondarySupportMaterialNonProjectedEnumChecker::is_value(strData[5])) {
                throw std::invalid_argument("5");
            } else {
                this->otherPhysicalDetails[5] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SecondarySupportMaterialNonProjected>(strData[5]));
            }
        }

        void processMotionPicture(const std::string &strData) {
            if (strData.length() != 23) {
                throw std::invalid_argument(std::to_string(strData.length()));
            }

            if (!PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationMotionPictureEnumChecker::is_value(strData[1])) {
                throw std::invalid_argument("1");
            } else {
                this->specificMaterialDesignation = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationMotionPicture>(strData[1]));
            }

            if (strData[2] != '#') {
                throw std::invalid_argument("2");
            }

            if (!PhysicalDescriptionEnumHelpers::ColorMotionPictureEnumChecker::is_value(strData[3])) {
                throw std::invalid_argument("3");
            } else {
                this->otherPhysicalDetails[3] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::ColorMotionPicture>(strData[3]));
            }

            if (!PhysicalDescriptionEnumHelpers::MotionPicturePresentationFormatEnumChecker::is_value(strData[4])) {
                throw std::invalid_argument("4");
            } else {
                this->otherPhysicalDetails[4] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::MotionPicturePresentationFormat>(strData[4]));
            }

            if (!PhysicalDescriptionEnumHelpers::SoundOnMediumProjectedMotionPictureEnumChecker::is_value(strData[5])) {
                throw std::invalid_argument("5");
            } else {
                this->otherPhysicalDetails[5] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SoundOnMediumProjectedMotionPicture>(strData[5]));
            }

            if (!PhysicalDescriptionEnumHelpers::MediumForSoundMotionPictureEnumChecker::is_value(strData[6])) {
                throw std::invalid_argument("6");
            } else {
                this->otherPhysicalDetails[6] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::MediumForSoundMotionPicture>(strData[6]));
            }

            if (!PhysicalDescriptionEnumHelpers::DimensionMotionPictureEnumChecker::is_value(strData[7])) {
                throw std::invalid_argument("7");
            } else {
                this->otherPhysicalDetails[7] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::DimensionMotionPicture>(strData[7]));
            }

            if (!PhysicalDescriptionEnumHelpers::ConfigurationOfPlaybackChannelsEnumChecker::is_value(strData[8])) {
                throw std::invalid_argument("8");
            } else {
                this->otherPhysicalDetails[8] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::ConfigurationOfPlaybackChannelsMotionPicture>(strData[8]));
            }

            if (!PhysicalDescriptionEnumHelpers::ProductionElementsEnumChecker::is_value(strData[9])) {
                throw std::invalid_argument("9");
            } else {
                this->otherPhysicalDetails[9] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::ProductionElements>(strData[9]));
            }

            if (!PhysicalDescriptionEnumHelpers::PositiveNegativeAspectEnumChecker::is_value(strData[10])) {
                throw std::invalid_argument("10");
            } else {
                this->otherPhysicalDetails[10] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::PositiveNegativeAspect>(strData[10]));
            }

            if (!PhysicalDescriptionEnumHelpers::GenerationMotionPictureEnumChecker::is_value(strData[11])) {
                throw std::invalid_argument("11");
            } else {
                this->otherPhysicalDetails[11] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::GenerationMotionPicture>(strData[11]));
            }

            if (!PhysicalDescriptionEnumHelpers::BaseOfFilmEnumChecker::is_value(strData[12])) {
                throw std::invalid_argument("12");
            } else {
                this->otherPhysicalDetails[12] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::BaseOfFilm>(strData[12]));
            }

            if (!PhysicalDescriptionEnumHelpers::RefinedCategoriesOfColorEnumChecker::is_value(strData[13])) {
                throw std::invalid_argument("13");
            } else {
                this->otherPhysicalDetails[13] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::RefinedCategoriesOfColor>(strData[13]));
            }

            if (!PhysicalDescriptionEnumHelpers::KindOfColorStockEnumChecker::is_value(strData[14])) {
                throw std::invalid_argument("14");
            } else {
                this->otherPhysicalDetails[14] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::KindOfColorStock>(strData[14]));
            }

            if (!PhysicalDescriptionEnumHelpers::DeteriorationStageEnumChecker::is_value(strData[15])) {
                throw std::invalid_argument("15");
            } else {
                this->otherPhysicalDetails[15] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::DeteriorationStage>(strData[15]));
            }

            if (!PhysicalDescriptionEnumHelpers::CompletnessEnumChecker::is_value(strData[16])) {
                throw std::invalid_argument("16");
            } else {
                this->otherPhysicalDetails[16] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::Completness>(strData[16]));
            }

            this->otherPhysicalDetails[17] = static_cast<uint8_t>(std::stoi(strData.substr(17)));
        }

        void processKitAndNotedMusic(const std::string &strData) {
            if (strData.length() != 2) {
                throw std::invalid_argument(std::to_string(strData.length()));
            }

            if (!PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationKitNotedMusicRemoteSensingImageEnumChecker::is_value(
                    strData[1])) {
                throw std::invalid_argument("1");
            } else {
                this->specificMaterialDesignation = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationKitNotedMusicRemoteSensingImage>(strData[1]));
            }
        }

        void processRemoteSensingImage(const std::string &strData) {
            if (strData.length() != 11) {
                throw std::invalid_argument(std::to_string(strData.length()));
            }

            if (!PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationKitNotedMusicRemoteSensingImageEnumChecker::is_value(
                    strData[1])) {
                throw std::invalid_argument("1");
            } else {
                this->specificMaterialDesignation = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationKitNotedMusicRemoteSensingImage>(strData[1]));
            }

            if (strData[2] != '#') {
                throw std::invalid_argument("2");
            }

            if (!PhysicalDescriptionEnumHelpers::AltitudeOfSensorEnumChecker::is_value(strData[3])) {
                throw std::invalid_argument("3");
            } else {
                this->otherPhysicalDetails[3] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::AltitudeOfSensor>(strData[3]));
            }

            if (!PhysicalDescriptionEnumHelpers::AttitudeOfSensorEnumChecker::is_value(strData[4])) {
                throw std::invalid_argument("4");
            } else {
                this->otherPhysicalDetails[4] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::AttitudeOfSensor>(strData[4]));
            }

            if (!PhysicalDescriptionEnumHelpers::CloudCoverEnumChecker::is_value(strData[5])) {
                throw std::invalid_argument("5");
            } else {
                this->otherPhysicalDetails[5] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::CloudCover>(strData[5]));
            }

            if (!PhysicalDescriptionEnumHelpers::PlatformConstructionTypeEnumChecker::is_value(strData[6])) {
                throw std::invalid_argument("6");
            } else {
                this->otherPhysicalDetails[6] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::PlatformConstructionType>(strData[6]));
            }

            if (!PhysicalDescriptionEnumHelpers::PlatformCategoryEnumChecker::is_value(strData[7])) {
                throw std::invalid_argument("7");
            } else {
                this->otherPhysicalDetails[7] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::PlatformCategory>(strData[7]));
            }

            if (!PhysicalDescriptionEnumHelpers::SensorTypeEnumChecker::is_value(strData[8])) {
                throw std::invalid_argument("8");
            } else {
                this->otherPhysicalDetails[8] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SensorType>(strData[8]));
            }

            auto dataType = frozen::string(strData.substr(9, 2));

            if (std::find(PhysicalDescriptionEnumHelpers::dataType.begin(), PhysicalDescriptionEnumHelpers::dataType.end(), dataType) ==
                PhysicalDescriptionEnumHelpers::dataType.end()) {
                throw std::invalid_argument("9");
            } else {
                this->otherPhysicalDetails[9] = strData[9];
                this->otherPhysicalDetails[10] = strData[10];
            }
        }

        void processSoundRecording(const std::string &strData) {
            if (strData.length() != 14) {
                throw std::invalid_argument(std::to_string(strData.length()));
            }

            if (!PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationSoundRecordingEnumChecker::is_value(strData[1])) {
                throw std::invalid_argument("1");
            } else {
                this->specificMaterialDesignation = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationSoundRecording>(strData[1]));
            }

            if (strData[2] != '#') {
                throw std::invalid_argument("2");
            }

            if (!PhysicalDescriptionEnumHelpers::SpeedEnumChecker::is_value(strData[3])) {
                throw std::invalid_argument("3");
            } else {
                this->otherPhysicalDetails[3] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::Speed>(strData[3]));
            }

            if (!PhysicalDescriptionEnumHelpers::ConfigurationOfPlaybackChannelsSoundRecordingEnumChecker::is_value(strData[4])) {
                throw std::invalid_argument("4");
            } else {
                this->otherPhysicalDetails[4] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::ConfigurationOfPlaybackChannelsSoundRecording>(strData[4]));
            }

            if (!PhysicalDescriptionEnumHelpers::GrooveWidthEnumChecker::is_value(strData[5])) {
                throw std::invalid_argument("5");
            } else {
                this->otherPhysicalDetails[5] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::GrooveWidth>(strData[5]));
            }

            if (!PhysicalDescriptionEnumHelpers::DimensionSoundRecordingEnumChecker::is_value(strData[6])) {
                throw std::invalid_argument("6");
            } else {
                this->otherPhysicalDetails[6] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::DimensionSoundRecording>(strData[6]));
            }

            if (!PhysicalDescriptionEnumHelpers::TapeWidthEnumChecker::is_value(strData[7])) {
                throw std::invalid_argument("7");
            } else {
                this->otherPhysicalDetails[7] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::TapeWidth>(strData[7]));
            }

            if (!PhysicalDescriptionEnumHelpers::TapeConfigurationEnumChecker::is_value(strData[8])) {
                throw std::invalid_argument("8");
            } else {
                this->otherPhysicalDetails[8] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::TapeConfiguration>(strData[8]));
            }

            if (!PhysicalDescriptionEnumHelpers::KindOfDiscEnumChecker::is_value(strData[9])) {
                throw std::invalid_argument("9");
            } else {
                this->otherPhysicalDetails[9] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::KindOfDisc>(strData[9]));
            }

            if (!PhysicalDescriptionEnumHelpers::KindOfMaterialEnumChecker::is_value(strData[10])) {
                throw std::invalid_argument("10");
            } else {
                this->otherPhysicalDetails[10] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::KindOfMaterial>(strData[10]));
            }

            if (!PhysicalDescriptionEnumHelpers::KindOfCuttingEnumChecker::is_value(strData[11])) {
                throw std::invalid_argument("11");
            } else {
                this->otherPhysicalDetails[11] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::KindOfCutting>(strData[11]));
            }

            if (!PhysicalDescriptionEnumHelpers::SpecialPlaybackCharacteristicsEnumChecker::is_value(strData[12])) {
                throw std::invalid_argument("12");
            } else {
                this->otherPhysicalDetails[12] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SpecialPlaybackCharacteristics>(strData[12]));
            }

            if (!PhysicalDescriptionEnumHelpers::OriginalCaptureEnumChecker::is_value(strData[13])) {
                throw std::invalid_argument("13");
            } else {
                this->otherPhysicalDetails[13] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::OriginalCapture>(strData[13]));
            }
        }

        void processText(const std::string &strData) {
            if (strData.length() != 2) {
                throw std::invalid_argument(std::to_string(strData.length()));
            }

            if (!PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationTextEnumChecker::is_value(strData[1])) {
                throw std::invalid_argument("1");
            } else {
                this->specificMaterialDesignation = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationText>(strData[1]));
            }
        }

        void processVideoRecording(const std::string &strData) {
            if (strData.length() != 9) {
                throw std::invalid_argument(std::to_string(strData.length()));
            }

            if (!PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationVideoRecordingEnumChecker::is_value(strData[1])) {
                throw std::invalid_argument("1");
            } else {
                this->specificMaterialDesignation = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationVideoRecording>(strData[1]));
            }

            if (strData[2] != '#') {
                throw std::invalid_argument("2");
            }

            if (!PhysicalDescriptionEnumHelpers::ColorVideoRecordingEnumChecker::is_value(strData[3])) {
                throw std::invalid_argument("3");
            } else {
                this->otherPhysicalDetails[3] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::ColorVideoRecording>(strData[3]));
            }

            if (!PhysicalDescriptionEnumHelpers::VideoRecordingFormatEnumChecker::is_value(strData[4])) {
                throw std::invalid_argument("4");
            } else {
                this->otherPhysicalDetails[4] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::VideoRecordingFormat>(strData[4]));
            }

            if (!PhysicalDescriptionEnumHelpers::SoundOnMediumVideoRecordingEnumChecker::is_value(strData[5])) {
                throw std::invalid_argument("5");
            } else {
                this->otherPhysicalDetails[5] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SoundOnMediumVideoRecording>(strData[5]));
            }

            if (!PhysicalDescriptionEnumHelpers::MediumForSoundVideoRecordingEnumChecker::is_value(strData[6])) {
                throw std::invalid_argument("6");
            } else {
                this->otherPhysicalDetails[6] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::MediumForSoundVideoRecording>(strData[6]));
            }

            if (!PhysicalDescriptionEnumHelpers::DimensionVideoRecordingEnumChecker::is_value(strData[7])) {
                throw std::invalid_argument("7");
            } else {
                this->otherPhysicalDetails[7] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::DimensionVideoRecording>(strData[7]));
            }

            if (!PhysicalDescriptionEnumHelpers::ConfigurationOfPlaybackChannelsVideoRecordingEnumChecker::is_value(strData[8])) {
                throw std::invalid_argument("8");
            } else {
                this->otherPhysicalDetails[8] = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::ConfigurationOfPlaybackChannelsVideoRecording>(strData[8]));
            }
        }

        void processUnspecified(const std::string &strData) {
            if (strData.length() != 2) {
                throw std::invalid_argument(std::to_string(strData.length()));
            }

            if (!PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationUnspecifiedEnumChecker::is_value(strData[1])) {
                throw std::invalid_argument("1");
            } else {
                this->specificMaterialDesignation = static_cast<uint8_t>(static_cast<PhysicalDescriptionEnumHelpers::SpecificMaterialDesignationUnspecified>(strData[1]));
            }
        }

        void processStr(const std::string &strData) {
            if (strData.empty()) {
                throw std::invalid_argument("0");
            }

            if (!PhysicalDescriptionEnumHelpers::MaterialEnumChecker::is_value(strData[0])) {
                throw std::invalid_argument("0");
            } else {
                this->categoryOfMaterial = static_cast<PhysicalDescriptionEnumHelpers::Material>(strData[0]);
            }

            switch (this->categoryOfMaterial) {
                case PhysicalDescriptionEnumHelpers::Material::Map:
                    processMap(strData);
                    break;
                case PhysicalDescriptionEnumHelpers::Material::Electronic:
                    processElectronic(strData);
                    break;
                case PhysicalDescriptionEnumHelpers::Material::Globe:
                    processGlobe(strData);
                    break;
                case PhysicalDescriptionEnumHelpers::Material::TactileMaterial:
                    processTactileMaterial(strData);
                    break;
                case PhysicalDescriptionEnumHelpers::Material::ProjectedGraphic:
                    processProjectedGraphic(strData);
                    break;
                case PhysicalDescriptionEnumHelpers::Material::Microform:
                    processMicroform(strData);
                    break;
                case PhysicalDescriptionEnumHelpers::Material::NonProjectedGraphic:
                    processNonProjectedGraphic(strData);
                    break;
                case PhysicalDescriptionEnumHelpers::Material::MotionPicture:
                    processMotionPicture(strData);
                    break;
                case PhysicalDescriptionEnumHelpers::Material::Kit:
                case PhysicalDescriptionEnumHelpers::Material::NotatedMusic:
                    processKitAndNotedMusic(strData);
                    break;
                case PhysicalDescriptionEnumHelpers::Material::RemoteSensingImage:
                    processRemoteSensingImage(strData);
                    break;
                case PhysicalDescriptionEnumHelpers::Material::SoundRecording:
                    processSoundRecording(strData);
                    break;
                case PhysicalDescriptionEnumHelpers::Material::Text:
                    processText(strData);
                    break;
                case PhysicalDescriptionEnumHelpers::Material::VideoRecording:
                    processVideoRecording(strData);
                    break;
                case PhysicalDescriptionEnumHelpers::Material::Unspecified:
                    processUnspecified(strData);
                    break;
            }
        }
    };

} // MARC
// LibManager

#endif //LIBMANAGERSERVER_PHYSICALDESCRIPTIONFIXEDFIELDGENERALINFORMATION_H
