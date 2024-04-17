//
// Created by csger on 2024. 03. 16..
//

#include "MARCProcessor.h"

#include <utility>
#include <fstream>
#include <json/value.h>
#include <json/reader.h>

#include "00x/ControlNumber.h"
#include "00x/ControlNumberIdentifier.h"
#include "00x/DateAndTimeOfLatestTransaction.h"
#include "00x/PhysicalDescriptionFixedFieldGeneralInformation.h"
#include "00x/FixedLengthDataElementsGeneralInformation.h"
#include "leader/Leader.h"
#include "expections/Exception.h"
#include "01x-09x/ISBN.h"
#include "01x-09x/ISSN.h"
#include "01x-09x/CatalogingSource.h"
#include "01x-09x/LanguageCode.h"
#include "01x-09x/UniversalDecimalClassificationNumber.h"
#include "1xx/MainEntryPersonalName.h"
#include "1xx/MainEntryCorporateName.h"

namespace LibManager::MARC {
    MARCProcessor::MARCProcessor(std::string strData) : strData(std::move(strData)), dataFieldsArray({}) {}

    MARCProcessor::MARCProcessor(const Json::Value &json) {
        //TODO: process json
    }

    void MARCProcessor::processData() {
        processStr();
        if (strData.empty() && !dataFieldsArray.empty()) {
            processMap();
        } else if (!strData.empty() && dataFieldsArray.empty()) {
            processStr();
        } else {
            throw std::invalid_argument("Invalid data");
        }
    }

    std::vector<std::shared_ptr<Directory>> MARCProcessor::getFields() {
        return dataFieldsArray;
    }

    std::shared_ptr<Directory> MARCProcessor::getField(uint16_t field) {
        if (!this->isFieldExist(field)) {
            throw std::invalid_argument("Field does not exist");
        }

        return dataFieldsArray[field];
    }

    bool MARCProcessor::isFieldExist(uint16_t field) {
        return field < dataFieldsArray.size();
        //TODO: better check
    }

    std::string MARCProcessor::getStrData() const {
        return strData;
    }

    std::string MARCProcessor::resolveNum(MARCNum num) {
        return MarcNumStr.at(num).data();
    }

    void MARCProcessor::processMap() {

    }

    void MARCProcessor::processStr() {
        auto lines = Helpers::split(strData, "\n");

        for (auto i = 0; i < lines.size(); i++) {
            auto fields = Helpers::split(lines[i], "\t");

            if (!Helpers::is_number(fields[0])) {
                throw std::invalid_argument("Invalid field number");
            }

            uint16_t fieldId = std::stoi(fields[0]);

            if (fieldId == 0) {
                if (seenFields.find(MARCNum::Leader) != seenFields.end()) {
                    throw std::invalid_argument("Leader field is already defined");
                }
                dataFieldsArray.push_back(std::make_shared<Leader>(fields[1]));
                seenFields.insert(MARCNum::Leader);
                continue;
            }

            MARCNum field;

            if (!MARCNumEnumChecker::is_value(fieldId)) {
                throw std::invalid_argument("Invalid field number");
            } else {
                field = static_cast<MARCNum>(fieldId);
            }

            if (dataFieldsArray.empty() || static_cast<MARCNum>(dataFieldsArray[0]->getId()) != MARCNum::Leader) {
                throw std::invalid_argument("Leader field is missing");
            }

            try {
                switch (field) {
                    case MARCNum::PhysicalDescriptionFixedField: {
                        if (seenFields.find(MARCNum::PhysicalDescriptionFixedField) != seenFields.end()) {
                            throw std::invalid_argument("Physical Description Fixed Field is already defined");
                        }
                        dataFieldsArray.push_back(
                                std::make_shared<PhysicalDescriptionFixedFieldGeneralInformation>(fields[1]));
                        seenFields.insert(MARCNum::PhysicalDescriptionFixedField);
                        break;
                    }
                    case MARCNum::FixedLengthDataElementsAdditionalMaterialCharacteristics:
                        break;
                    case MARCNum::FixedLengthDataElements: {
                        if (seenFields.find(MARCNum::FixedLengthDataElements) != seenFields.end()) {
                            throw std::invalid_argument("Fixed-Length Data Elements is already defined");
                        }
                        dataFieldsArray.push_back(
                                std::make_shared<FixedLengthDataElementsGeneralInformation>(fields[1],
                                                                                            static_cast<Leader::TypeOfRecord>(reinterpret_cast<Leader *>(dataFieldsArray[0].get())->getTypeOfRecord()),
                                                                                            static_cast<Leader::BibliographicLevel>(reinterpret_cast<Leader *>(dataFieldsArray[0].get())->getBibliographicLevel())));
                        seenFields.insert(MARCNum::FixedLengthDataElements);
                        break;
                    }
                    case MARCNum::ISBN: {
                        if (fields.size() != 3) {
                            throw std::invalid_argument("Invalid field length");
                        }

                        dataFieldsArray.push_back(std::make_shared<ISBN>(fields[1], fields[2]));
                        seenFields.insert(MARCNum::ISBN);
                        break;
                    }
                    case MARCNum::ISSN: {
                        if (fields.size() != 3) {
                            throw std::invalid_argument("Invalid field length");
                        }

                        dataFieldsArray.push_back(std::make_shared<ISSN>(fields[1], fields[2]));
                        seenFields.insert(MARCNum::ISSN);
                        break;
                    }
                    case MARCNum::CatalogingSource: {
                        if (fields.size() != 3) {
                            throw std::invalid_argument("Invalid field length");
                        }

                        dataFieldsArray.push_back(std::make_shared<CatalogingSource>(fields[1], fields[2]));
                        seenFields.insert(MARCNum::CatalogingSource);
                        break;
                    }
                    case MARCNum::LanguageCode: {
                        if (fields.size() != 3) {
                            throw std::invalid_argument("Invalid field length");
                        }

                        dataFieldsArray.push_back(std::make_shared<LanguageCode>(fields[1], fields[2]));
                        seenFields.insert(MARCNum::LanguageCode);
                        break;
                    }
                    case MARCNum::UniversalDecimalClassificationNumber: {
                        if (fields.size() != 3) {
                            throw std::invalid_argument("Invalid field length");
                        }

                        dataFieldsArray.push_back(
                                std::make_shared<UniversalDecimalClassificationNumber>(fields[1], fields[2]));
                        seenFields.insert(MARCNum::UniversalDecimalClassificationNumber);
                        break;
                    }
                    case MARCNum::MainEntryPersonalName:
                        if (fields.size() != 3) {
                            throw std::invalid_argument("Invalid field length");
                        }

                        dataFieldsArray.push_back(std::make_shared<MainEntryPersonalName>(fields[1], fields[2]));
                        seenFields.insert(MARCNum::MainEntryPersonalName);
                        break;
                    case MARCNum::MainEntryCorporateName:
                        if (fields.size() != 3) {
                            throw std::invalid_argument("Invalid field length");
                        }

                        dataFieldsArray.push_back(std::make_shared<MainEntryCorporateName>(fields[1], fields[2]));
                        seenFields.insert(MARCNum::MainEntryCorporateName);
                        break;
                    default:
                        throw std::invalid_argument("Invalid field number");
                }
            } catch (std::exception &e) {
                dataFieldsArray.clear();
                throw MarcException(lines[i], i, std::stoi(e.what()));
            }
        }

        auto controlNumbers = readControlNumber();

        dataFieldsArray.push_back(std::make_shared<ControlNumber>(static_cast<uint32_t>(std::stoi(controlNumbers[0]))));
        dataFieldsArray.push_back(std::make_shared<ControlNumberIdentifier>(controlNumbers[1]));
        dataFieldsArray.push_back(std::make_shared<DateAndTimeOfLatestTransaction>());
    }

    std::array<std::string, 2> MARCProcessor::readControlNumber() {
        std::ifstream file("../config/libManagerConfig.json");
        Json::Value config;
        Json::Reader reader;
        reader.parse(file, config);

        return {config["ControlNumber"].asString(), config["ControlNumberIdentifier"].asString()};
    }

    Json::Value MARCProcessor::toJson() {
        Json::Value retVal;

        for (const auto &field: dataFieldsArray) {
            retVal[resolveNum(static_cast<MARCNum>(field->getId()))] = field->toJson();
        }

        return retVal;
    }
} // MARC
// LibManager