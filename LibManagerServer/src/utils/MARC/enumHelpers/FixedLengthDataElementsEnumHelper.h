//
// Created by csger on 2024. 03. 24..
//

#ifndef LIBMANAGERSERVER_FIXEDLENGTHDATAELEMENTSENUMHELPER_H
#define LIBMANAGERSERVER_FIXEDLENGTHDATAELEMENTSENUMHELPER_H

#include <cstdint>
#include <array>

#include "../../helpers.h"
#include "frozen/string.h"

namespace LibManager::MARC {

    class FixedLengthDataElementsEnumHelper {
    public:
        enum class TypeOfDate : uint8_t {
            NoDatesGivenBcInvolved = 'b',
            ContinuingResourceCurrentlyPublished = 'c',
            ContinuingResourceCeasedPublication = 'd',
            DetailedDate = 'e',
            InclusiveDatesOfCollection = 'i',
            RangeOfYearsOfBulkOfCollection = 'k',
            MultipleDates = 'm',
            DatesUnknown = 'n',
            DateOfDistributionReleaseIssueAndProductionRecordingSessionWhenDifferent = 'p',
            QuestionableDate = 'q',
            ReprintReissueDateAndOriginalDate = 'r',
            SingleKnownDate = 's',
            PublicationDateAndCopyrightDate = 't',
            ContinuingResourceStatusUnknown = 'u',
            NoAttemptToCode = '|'
        };

        enum class ModifiedRecord : uint8_t {
            NotModified = '#',
            DashedOnInformationOmitted = 'd',
            CompletelyRomanizedPrintedCardRomanized = 'o',
            CompletelyRomanizedPrintedCardInScript = 'r',
            Shortened = 's',
            MissingCharacters = 'x',
            NoAttemptToCode = '|'
        };

        enum class CatalogingSource : uint8_t {
            NationalBibliographicAgency = 'a',
            CooperativeCatalogingProgram = 'c',
            Other = 'd',
            Unknown = 'u',
            NoAttemptToCode = '|'
        };

        enum class Illustrations : uint8_t {
            NoIllustrations = '#',
            Illustrations = 'a',
            Maps = 'b',
            Portraits = 'c',
            Charts = 'd',
            Plans = 'e',
            Plates = 'f',
            Music = 'g',
            Facsimiles = 'h',
            CoatsOfArms = 'i',
            GenealogicalTables = 'j',
            Forms = 'k',
            Samples = 'l',
            PhonodiscPhonowireEtc = 'm',
            Photographs = 'o',
            Illuminations = 'p',
            NoAttemptToCode = '|'
        };

        enum class TargetAudience : uint8_t {
            UnknownOrNotSpecified = 'a',
            Preschool = 'b',
            Primary = 'c',
            PreAdolescent = 'd',
            Adolescent = 'e',
            Adult = 'f',
            Specialized = 'g',
            General = 'j',
            Juvenile = 'j',
            NoAttemptToCode = '|'
        };

        enum class FormOfItemBook : uint8_t {
            NoSpecifiedForm = '#',
            Microfilm = 'b',
            Microfiche = 'c',
            Microopaque = 'd',
            LargePrint = 'f',
            Braille = 'o',
            Online = 'q',
            DirectElectronic = 'r',
            RegularPrint = 't',
            NoAttemptToCode = '|'
        };

        enum class NatureOfContents : uint8_t {
            NoSpecifiedNatureOfContents = '#',
            AbstractsSummaries = 'a',
            Bibliographies = 'b',
            Catalogs = 'c',
            Dictionaries = 'd',
            Encyclopedias = 'e',
            Handbooks = 'f',
            LegalArticles = 'g',
            Indexes = 'i',
            PatentDocument = 'j',
            Discographies = 'k',
            Legislation = 'l',
            Theses = 'm',
            SurveysOfLiteratureInASubjectArea = 'n',
            Reviews = 'o',
            ProgrammedTexts = 'p',
            Filmographies = 'q',
            Directories = 'r',
            Statistics = 's',
            TechnicalReports = 't',
            StandardsSpecifications = 'u',
            LegalCasesAndCaseNotes = 'v',
            LawReportsAndDigests = 'w',
            Yearbooks = 'y',
            Treaties = 'z',
            Offprints = '2',
            Calendars = '5',
            ComicsGraphicNovels = '6',
            NoAttemptToCode = '|'
        };

        enum class GovernmentPublication : uint8_t {
            NotAGovernmentPublication = '#',
            AutonomousOrSemiAutonomousComponent = 'a',
            Multilocal = 'c',
            FederalNational = 'f',
            InternationalIntergovernmental = 'i',
            Local = 'l',
            Multistate = 'm',
            GovernmentPublicationLevelUndetermined = 'o',
            StateProvincialTerritorialDependentEtc = 's',
            UnknownIfItemIsGovernmentPublication = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class ConferencePublication : uint8_t {
            NotConferencePublication = '0',
            ConferencePublication = '1',
            NoAttemptToCode = '|'
        };

        enum class Festschrift : uint8_t {
            NotAFestschrift = '0',
            Festschrift = '1',
            NoAttemptToCode = '|'
        };

        enum class Index : uint8_t {
            NoIndex = '0',
            Index = '1',
            NoAttemptToCode = '|'
        };

        enum class LiteraryForm : uint8_t {
            NotFictionNotFurtherSpecified = '0',
            FictionNotFurtherSpecified = '1',
            Dramas = 'd',
            Essays = 'e',
            Novels = 'f',
            HumorSatiresEtc = 'h',
            Letters = 'i',
            ShortStories = 'j',
            MixedForms = 'm',
            Poetry = 'p',
            Speeches = 's',
            Unknown = 'u',
            NoAttemptToCode = '|'
        };

        enum class Biography : uint8_t {
            NoBiographicalMaterial = 'x',
            Autobiography = 'a',
            IndividualBiography = 'b',
            CollectiveBiography = 'c',
            ContainsBiographicalInformation = 'd',
            NoAttemptToCode = '|'
        };

        enum class FormOfItemComputerFile : uint8_t {
            NoSpecifiedForm = '#',
            Online = 'o',
            DirectElectronic = 'q',
            NoAttemptToCode = '|'
        };

        enum class TypeOfComputerFile : uint8_t {
            NumericData = 'a',
            ComputerProgram = 'b',
            Representational = 'c',
            Document = 'd',
            BibliographicData = 'e',
            Font = 'f',
            Game = 'g',
            Sound = 'h',
            InteractiveMultimedia = 'i',
            OnlineSystemOrService = 'j',
            Combination = 'm',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class CartographicRelief : uint8_t {
            NoReliefShown = '#',
            Contours = 'a',
            Shading = 'b',
            GradientAndBathymetricTints = 'c',
            Hachures = 'd',
            BathymetrySoundings = 'e',
            FormLines = 'f',
            SpotHeights = 'g',
            Pictorially = 'i',
            LandForms = 'j',
            BathymetryIsolines = 'k',
            RockDrawings = 'm',
            Other = 'z'
        };

        static constexpr std::array<frozen::string, 48> Projection{
                "##", "aa", "ab", "ac", "ad", "ae", "af", "ag", "am", "an", "ap", "au", "az", "ba", "bb", "bc", "bd",
                "be",
                "bf", "bg", "bh", "bi", "bj", "bk", "bl", "bo", "br", "bs", "bu", "bz", "ca", "cb", "cc", "ce", "cp",
                "cu", "cz", "da", "db", "dc", "dd", "de", "df", "dg", "dh", "dl", "zz", "||"
        };

        enum class TypeOfCartographicMaterial : uint8_t {
            SingleMap = 'a',
            MapSeries = 'b',
            MapSerial = 'c',
            Globe = 'd',
            Atlas = 'e',
            SeparateSupplementToAnotherWork = 'f',
            BoundAsPartOfAnotherWork = 'g',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class FormOfItemMap : uint8_t {
            NoSpecifiedForm = '#',
            Microfilm = 'a',
            Microfiche = 'b',
            Microopaque = 'c',
            LargePrint = 'd',
            Braille = 'f',
            Online = 'o',
            DirectElectronic = 'q',
            RegularPrintReproduction = 'r',
            Electronic = 's',
            NoAttemptToCode = '|'
        };

        enum class SpecialFormatCharacteristics : uint8_t {
            NoSpecifiedSpecialFormatCharacteristics = '#',
            Manuscript = 'e',
            PictureCardPostCard = 'j',
            Calendar = 'k',
            Puzzle = 'l',
            Game = 'n',
            WallMap = 'o',
            PlayingCards = 'p',
            LooseLeaf = 'r',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        static constexpr std::array<frozen::string, 47> FormOfComposition = {
                "aa", "ab", "ac", "ad", "ae", "af", "ag", "am", "an", "ap", "au", "az", "ba", "bb", "bc", "bd", "be",
                "bf", "bg", "bh", "bi", "bj", "bk", "bl", "bo", "br", "bs", "bu", "bz", "ca", "cb", "cc", "ce", "cp",
                "cu", "cz", "da", "db", "dc", "dd", "de", "df", "dg", "dh", "dl", "zz", "||"
        };

        enum class FormatOfMusic : uint8_t {
            FullScore = 'a',
            MiniatureOrStudyScore = 'b',
            AccompanimentReducedForKeyboard = 'c',
            VoiceScoreWithAccompanimentOmitted = 'd',
            CondensedScoreOrPianoConductorScore = 'e',
            CloseScore = 'g',
            ChorusScore = 'h',
            CondensedScore = 'i',
            PerformerConductorPart = 'j',
            VocalScore = 'k',
            Score = 'l',
            MultipleScoreFormats = 'm',
            NotApplicable = 'n',
            PianoScore = 'p',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class MusicParts : uint8_t {
            NoPartsInHandOrNotSpecified = 'a',
            InstrumentalAndVocalParts = 'd',
            InstrumentalParts = 'e',
            VocalParts = 'f',
            NotApplicable = 'n',
            Unknown = 'u',
            NoAttemptToCode = '|'
        };

        enum class FormOfItemMusic : uint8_t {
            NoSpecifiedForm = '#',
            Microfilm = 'a',
            Microfiche = 'b',
            Microopaque = 'c',
            LargePrint = 'd',
            Braille = 'f',
            Online = 'o',
            DirectElectronic = 'q',
            RegularPrintReproduction = 'r',
            Electronic = 's',
            NoAttemptToCode = '|'
        };

        enum class AccompanyingMatter : uint8_t {
            NoAccompanyingMatter = '#',
            Discography = 'a',
            Bibliography = 'b',
            ThematicIndex = 'c',
            LibrettoOrText = 'd',
            BiographyOfComposerOrAuthor = 'e',
            BiographyOfPerformerOrHistoryOfEnsemble = 'f',
            TechnicalAndOrHistoricalInformationOnInstruments = 'g',
            TechnicalInformationOnMusic = 'h',
            HistoricalInformation = 'i',
            EthnologicalInformation = 'k',
            InstructionalMaterials = 'r',
            Music = 's',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class LiteraryTestForSoundRecordings : uint8_t {
            Autobiography = 'a',
            Biography = 'b',
            ConferenceProceedings = 'c',
            Drama = 'd',
            Essays = 'e',
            Fiction = 'f',
            Reporting = 'g',
            History = 'h',
            Instruction = 'i',
            LanguageInstruction = 'j',
            Comedy = 'k',
            LecturesSpeeches = 'l',
            Memoirs = 'm',
            NotApplicable = 'n',
            Folktales = 'o',
            Poetry = 'p',
            Rehearsals = 'r',
            Sounds = 's',
            Interviews = 't',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class TranspositionAndArrangement : uint8_t {
            NotArrangementOrTranspositionOrNotSpecified = 'a',
            Transposition = 'b',
            Arrangement = 'c',
            BothTransposedAndArranged = 'd',
            NotApplicable = 'n',
            Unknown = 'u',
            NoAttemptToCode = '|'
        };

        enum class Frequency : uint8_t {
            NoDeterminableFrequency = '#',
            Annual = 'a',
            Bimonthly = 'b',
            Semiweekly = 'c',
            Daily = 'd',
            Biweekly = 'e',
            Semiannual = 'f',
            Biennial = 'g',
            Triennial = 'h',
            ThreeTimesAWeek = 'i',
            ThreeTimesAMonth = 'j',
            ContinuouslyUpdated = 'k',
            Monthly = 'm',
            Quarterly = 'q',
            Semimonthly = 's',
            ThreeTimesAYear = 't',
            Unknown = 'u',
            Weekly = 'w',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class Regularity : uint8_t {
            NormalizedIrregular = 'n',
            Regular = 'r',
            Unknown = 'u',
            CompletelyIrregular = 'x',
            NoAttemptToCode = '|'
        };

        enum class TypeOfContinuingResource : uint8_t {
            UpdatingDatabase = 'd',
            Magazine = 'g',
            Blog = 'h',
            Journal = 'j',
            UpdatingLooseLeaf = 'l',
            MonographicSeries = 'm',
            Newspaper = 'n',
            Periodical = 'p',
            Repository = 'r',
            Newsletter = 's',
            Directory = 't',
            UpdatingWebSite = 'w',
            NoAttemptToCode = '|'
        };

        enum class FormOfOriginalItemContinuingResources : uint8_t {
            NoSpecifiedForm = '#',
            Microfilm = 'a',
            Microfiche = 'b',
            Microopaque = 'c',
            LargePrint = 'd',
            NewspaperFormat = 'e',
            Braille = 'f',
            Online = 'o',
            DirectElectronic = 'q',
            Electronic = 's',
            NoAttemptToCode = '|'
        };

        enum class FormOfItemConitnuingResources : uint8_t {
            NoSpecifiedForm = '#',
            Microfilm = 'a',
            Microfiche = 'b',
            Microopaque = 'c',
            LargePrint = 'd',
            Braille = 'f',
            Online = 'o',
            DirectElectronic = 'q',
            RegularPrintReproduction = 'r',
            Electronic = 's',
            NoAttemptToCode = '|'
        };

        enum class NatureOfEntireWork : uint8_t {
            NotSpecified = '#',
            AbstractsSummaries = 'a',
            Bibliographies = 'b',
            Catalogs = 'c',
            Dictionaries = 'd',
            Encyclopedias = 'e',
            Handbooks = 'f',
            LegalArticles = 'g',
            Biography = 'h',
            Indexes = 'i',
            Discographies = 'k',
            Legislation = 'l',
            Theses = 'm',
            SurveysOfLiteratureInASubjectArea = 'n',
            Reviews = 'o',
            ProgrammedTexts = 'p',
            Filmographies = 'q',
            Directories = 'r',
            Statistics = 's',
            TechnicalReports = 't',
            StandardsSpecifications = 'u',
            LegalCasesAndCaseNotes = 'v',
            LawReportsAndDigests = 'w',
            Yearbooks = 'y',
            Treaties = 'z',
            Calendars = '5',
            ComicsGraphicNovels = '6',
            NoAttemptToCode = '|'
        };

        enum class NatureOfContentsContinuingResources : uint8_t {
            NotSpecified = '#',
            AbstractsSummaries = 'a',
            Bibliographies = 'b',
            Catalogs = 'c',
            Dictionaries = 'd',
            Encyclopedias = 'e',
            Handbooks = 'f',
            LegalArticles = 'g',
            Biography = 'h',
            Indexes = 'i',
            Discographies = 'k',
            Legislation = 'l',
            Theses = 'm',
            SurveysOfLiteratureInASubjectArea = 'n',
            Reviews = 'o',
            ProgrammedTexts = 'p',
            Filmographies = 'q',
            Directories = 'r',
            Statistics = 's',
            TechnicalReports = 't',
            StandardsSpecifications = 'u',
            LegalCasesAndCaseNotes = 'v',
            LawReportsAndDigests = 'w',
            Yearbooks = 'y',
            Treaties = 'z',
            Calendars = '5',
            ComicsGraphicNovels = '6',
            NoAttemptToCode = '|'
        };

        enum class OriginalAlphabetOrScriptOfTitle : uint8_t {
            NoAlphabetOrScriptGivenNoKeyTitle = '#',
            BasicRoman = 'a',
            ExtendedRoman = 'b',
            Cyrillic = 'c',
            Japanese = 'd',
            Chinese = 'e',
            Arabic = 'f',
            Greek = 'g',
            Hebrew = 'h',
            Thai = 'i',
            Devanagari = 'j',
            Korean = 'k',
            Tamil = 'l',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class EntryConvention : uint8_t {
            SuccessiveEntry = '0',
            LatestEntry = '1',
            IntegratedEntry = '2',
            NoAttemptToCode = '|'
        };

        enum class FormOfItemVisualMaterials : uint8_t {
            NoSpecifiedForm = '#',
            Microfilm = 'a',
            Microfiche = 'b',
            Microopaque = 'c',
            LargePrint = 'd',
            Braille = 'f',
            Online = 'o',
            DirectElectronic = 'q',
            RegularPrintReproduction = 'r',
            Electronic = 's',
            NoAttemptToCode = '|'
        };

        enum class TypeOfVisualMaterial : uint8_t {
            ArtOriginal = 'a',
            Kit = 'b',
            ArtReproduction = 'c',
            Diorama = 'd',
            Filmstrip = 'f',
            Game = 'g',
            Picture = 'i',
            Graphic = 'k',
            TechnicalDrawing = 'l',
            MotionPicture = 'm',
            Chart = 'n',
            FlashCard = 'o',
            MicroscopeSlide = 'p',
            Model = 'q',
            Realia = 'r',
            Slide = 's',
            Transparency = 't',
            Videorecording = 'v',
            Toy = 'w',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class Technique : uint8_t {
            Animation = 'a',
            AnimationAndLiveAction = 'c',
            LiveAction = 'l',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class FormOfItemUnspecified : uint8_t {
            NoSpecifiedForm = '#',
            Microfilm = 'a',
            Microfiche = 'b',
            Microopaque = 'c',
            LargePrint = 'd',
            Braille = 'f',
            Online = 'o',
            DirectElectronic = 'q',
            RegularPrintReproduction = 'r',
            Electronic = 's',
            NoAttemptToCode = '|'
        };

        using TypeOfDateEnumChecker = Helpers::EnumCheck<TypeOfDate, TypeOfDate::NoDatesGivenBcInvolved, TypeOfDate::ContinuingResourceCurrentlyPublished, TypeOfDate::ContinuingResourceCeasedPublication, TypeOfDate::DetailedDate, TypeOfDate::InclusiveDatesOfCollection, TypeOfDate::RangeOfYearsOfBulkOfCollection, TypeOfDate::MultipleDates, TypeOfDate::DatesUnknown, TypeOfDate::DateOfDistributionReleaseIssueAndProductionRecordingSessionWhenDifferent, TypeOfDate::QuestionableDate, TypeOfDate::ReprintReissueDateAndOriginalDate, TypeOfDate::SingleKnownDate, TypeOfDate::PublicationDateAndCopyrightDate, TypeOfDate::ContinuingResourceStatusUnknown, TypeOfDate::NoAttemptToCode>;
        using ModifiedRecordEnumChecker = Helpers::EnumCheck<ModifiedRecord, ModifiedRecord::NotModified, ModifiedRecord::DashedOnInformationOmitted, ModifiedRecord::CompletelyRomanizedPrintedCardRomanized, ModifiedRecord::CompletelyRomanizedPrintedCardInScript, ModifiedRecord::Shortened, ModifiedRecord::MissingCharacters, ModifiedRecord::NoAttemptToCode>;
        using CatalogingSourceEnumChecker = Helpers::EnumCheck<CatalogingSource, CatalogingSource::NationalBibliographicAgency, CatalogingSource::CooperativeCatalogingProgram, CatalogingSource::Other, CatalogingSource::Unknown, CatalogingSource::NoAttemptToCode>;

        using IllustrationsEnumChecker = Helpers::EnumCheck<Illustrations, Illustrations::NoIllustrations, Illustrations::Illustrations, Illustrations::Maps, Illustrations::Portraits, Illustrations::Charts, Illustrations::Plans, Illustrations::Plates, Illustrations::Music, Illustrations::Facsimiles, Illustrations::CoatsOfArms, Illustrations::GenealogicalTables, Illustrations::Forms, Illustrations::Samples, Illustrations::PhonodiscPhonowireEtc, Illustrations::Photographs, Illustrations::Illuminations, Illustrations::NoAttemptToCode>;
        using TargetAudienceEnumChecker = Helpers::EnumCheck<TargetAudience, TargetAudience::UnknownOrNotSpecified, TargetAudience::Preschool, TargetAudience::Primary, TargetAudience::PreAdolescent, TargetAudience::Adolescent, TargetAudience::Adult, TargetAudience::Specialized, TargetAudience::General, TargetAudience::Juvenile, TargetAudience::NoAttemptToCode>;
        using FormOfItemBookEnumChecker = Helpers::EnumCheck<FormOfItemBook, FormOfItemBook::NoSpecifiedForm, FormOfItemBook::Microfilm, FormOfItemBook::Microfiche, FormOfItemBook::Microopaque, FormOfItemBook::LargePrint, FormOfItemBook::Braille, FormOfItemBook::Online, FormOfItemBook::DirectElectronic, FormOfItemBook::RegularPrint, FormOfItemBook::NoAttemptToCode>;
        using NatureOfContentsEnumChecker = Helpers::EnumCheck<NatureOfContents, NatureOfContents::NoSpecifiedNatureOfContents, NatureOfContents::AbstractsSummaries, NatureOfContents::Bibliographies, NatureOfContents::Catalogs, NatureOfContents::Dictionaries, NatureOfContents::Encyclopedias, NatureOfContents::Handbooks, NatureOfContents::LegalArticles, NatureOfContents::Indexes, NatureOfContents::PatentDocument, NatureOfContents::Discographies, NatureOfContents::Legislation, NatureOfContents::Theses, NatureOfContents::SurveysOfLiteratureInASubjectArea, NatureOfContents::Reviews, NatureOfContents::ProgrammedTexts, NatureOfContents::Filmographies, NatureOfContents::Directories, NatureOfContents::Statistics, NatureOfContents::TechnicalReports, NatureOfContents::StandardsSpecifications, NatureOfContents::LegalCasesAndCaseNotes, NatureOfContents::LawReportsAndDigests, NatureOfContents::Yearbooks, NatureOfContents::Treaties, NatureOfContents::Offprints, NatureOfContents::Calendars, NatureOfContents::ComicsGraphicNovels, NatureOfContents::NoAttemptToCode>;
        using GovernmentPublicationEnumChecker = Helpers::EnumCheck<GovernmentPublication, GovernmentPublication::NotAGovernmentPublication, GovernmentPublication::AutonomousOrSemiAutonomousComponent, GovernmentPublication::Multilocal, GovernmentPublication::FederalNational, GovernmentPublication::InternationalIntergovernmental, GovernmentPublication::Local, GovernmentPublication::Multistate, GovernmentPublication::GovernmentPublicationLevelUndetermined, GovernmentPublication::StateProvincialTerritorialDependentEtc, GovernmentPublication::UnknownIfItemIsGovernmentPublication, GovernmentPublication::Other, GovernmentPublication::NoAttemptToCode>;
        using ConferencePublicationEnumChecker = Helpers::EnumCheck<ConferencePublication, ConferencePublication::NotConferencePublication, ConferencePublication::ConferencePublication, ConferencePublication::NoAttemptToCode>;
        using FestschriftEnumChecker = Helpers::EnumCheck<Festschrift, Festschrift::NotAFestschrift, Festschrift::Festschrift, Festschrift::NoAttemptToCode>;
        using IndexEnumChecker = Helpers::EnumCheck<Index, Index::NoIndex, Index::Index, Index::NoAttemptToCode>;
        using LiteraryFormEnumChecker = Helpers::EnumCheck<LiteraryForm, LiteraryForm::NotFictionNotFurtherSpecified, LiteraryForm::FictionNotFurtherSpecified, LiteraryForm::Dramas, LiteraryForm::Essays, LiteraryForm::Novels, LiteraryForm::HumorSatiresEtc, LiteraryForm::Letters, LiteraryForm::ShortStories, LiteraryForm::MixedForms, LiteraryForm::Poetry, LiteraryForm::Speeches, LiteraryForm::Unknown, LiteraryForm::NoAttemptToCode>;
        using BiographyEnumCheker = Helpers::EnumCheck<Biography, Biography::NoBiographicalMaterial, Biography::Autobiography, Biography::IndividualBiography, Biography::CollectiveBiography, Biography::ContainsBiographicalInformation, Biography::NoAttemptToCode>;

        using FormOfItemComputerFileEnumChecker = Helpers::EnumCheck<FormOfItemComputerFile, FormOfItemComputerFile::NoSpecifiedForm, FormOfItemComputerFile::Online, FormOfItemComputerFile::DirectElectronic, FormOfItemComputerFile::NoAttemptToCode>;
        using TypeOfComputerFileEnumChecker = Helpers::EnumCheck<TypeOfComputerFile, TypeOfComputerFile::NumericData, TypeOfComputerFile::ComputerProgram, TypeOfComputerFile::Representational, TypeOfComputerFile::Document, TypeOfComputerFile::BibliographicData, TypeOfComputerFile::Font, TypeOfComputerFile::Game, TypeOfComputerFile::Sound, TypeOfComputerFile::InteractiveMultimedia, TypeOfComputerFile::OnlineSystemOrService, TypeOfComputerFile::Combination, TypeOfComputerFile::Unknown, TypeOfComputerFile::Other, TypeOfComputerFile::NoAttemptToCode>;

        using CartographicReliefEnumChecker = Helpers::EnumCheck<CartographicRelief, CartographicRelief::NoReliefShown, CartographicRelief::Contours, CartographicRelief::Shading, CartographicRelief::GradientAndBathymetricTints, CartographicRelief::Hachures, CartographicRelief::BathymetrySoundings, CartographicRelief::FormLines, CartographicRelief::SpotHeights, CartographicRelief::Pictorially, CartographicRelief::LandForms, CartographicRelief::BathymetryIsolines, CartographicRelief::RockDrawings, CartographicRelief::Other>;
        using TypeOfCartographicMaterialEnumChecker = Helpers::EnumCheck<TypeOfCartographicMaterial, TypeOfCartographicMaterial::SingleMap, TypeOfCartographicMaterial::MapSeries, TypeOfCartographicMaterial::MapSerial, TypeOfCartographicMaterial::Globe, TypeOfCartographicMaterial::Atlas, TypeOfCartographicMaterial::SeparateSupplementToAnotherWork, TypeOfCartographicMaterial::BoundAsPartOfAnotherWork, TypeOfCartographicMaterial::Unknown, TypeOfCartographicMaterial::Other, TypeOfCartographicMaterial::NoAttemptToCode>;
        using FormOfItemMapEnumChecker = Helpers::EnumCheck<FormOfItemMap, FormOfItemMap::NoSpecifiedForm, FormOfItemMap::Microfilm, FormOfItemMap::Microfiche, FormOfItemMap::Microopaque, FormOfItemMap::LargePrint, FormOfItemMap::Braille, FormOfItemMap::Online, FormOfItemMap::DirectElectronic, FormOfItemMap::RegularPrintReproduction, FormOfItemMap::Electronic, FormOfItemMap::NoAttemptToCode>;
        using SpecialFormatCharacteristicsEnumChecker = Helpers::EnumCheck<SpecialFormatCharacteristics, SpecialFormatCharacteristics::NoSpecifiedSpecialFormatCharacteristics, SpecialFormatCharacteristics::Manuscript, SpecialFormatCharacteristics::PictureCardPostCard, SpecialFormatCharacteristics::Calendar, SpecialFormatCharacteristics::Puzzle, SpecialFormatCharacteristics::Game, SpecialFormatCharacteristics::WallMap, SpecialFormatCharacteristics::PlayingCards, SpecialFormatCharacteristics::LooseLeaf, SpecialFormatCharacteristics::Other, SpecialFormatCharacteristics::NoAttemptToCode>;

        using FormatOfMusicEnumChecker = Helpers::EnumCheck<FormatOfMusic, FormatOfMusic::FullScore, FormatOfMusic::MiniatureOrStudyScore, FormatOfMusic::AccompanimentReducedForKeyboard, FormatOfMusic::VoiceScoreWithAccompanimentOmitted, FormatOfMusic::CondensedScoreOrPianoConductorScore, FormatOfMusic::CloseScore, FormatOfMusic::ChorusScore, FormatOfMusic::CondensedScore, FormatOfMusic::PerformerConductorPart, FormatOfMusic::VocalScore, FormatOfMusic::Score, FormatOfMusic::MultipleScoreFormats, FormatOfMusic::NotApplicable, FormatOfMusic::PianoScore, FormatOfMusic::Unknown, FormatOfMusic::Other, FormatOfMusic::NoAttemptToCode>;
        using MusicPartsEnumChecker = Helpers::EnumCheck<MusicParts, MusicParts::NoPartsInHandOrNotSpecified, MusicParts::InstrumentalAndVocalParts, MusicParts::InstrumentalParts, MusicParts::VocalParts, MusicParts::NotApplicable, MusicParts::Unknown, MusicParts::NoAttemptToCode>;
        using FormOfItemMusicEnumChecker = Helpers::EnumCheck<FormOfItemMusic, FormOfItemMusic::NoSpecifiedForm, FormOfItemMusic::Microfilm, FormOfItemMusic::Microfiche, FormOfItemMusic::Microopaque, FormOfItemMusic::LargePrint, FormOfItemMusic::Braille, FormOfItemMusic::Online, FormOfItemMusic::DirectElectronic, FormOfItemMusic::RegularPrintReproduction, FormOfItemMusic::Electronic, FormOfItemMusic::NoAttemptToCode>;
        using AccompanyingMatterEnumChecker = Helpers::EnumCheck<AccompanyingMatter, AccompanyingMatter::NoAccompanyingMatter, AccompanyingMatter::Discography, AccompanyingMatter::Bibliography, AccompanyingMatter::ThematicIndex, AccompanyingMatter::LibrettoOrText, AccompanyingMatter::BiographyOfComposerOrAuthor, AccompanyingMatter::BiographyOfPerformerOrHistoryOfEnsemble, AccompanyingMatter::TechnicalAndOrHistoricalInformationOnInstruments, AccompanyingMatter::TechnicalInformationOnMusic, AccompanyingMatter::HistoricalInformation, AccompanyingMatter::EthnologicalInformation, AccompanyingMatter::InstructionalMaterials, AccompanyingMatter::Music, AccompanyingMatter::Other, AccompanyingMatter::NoAttemptToCode>;
        using LiteraryTestForSoundRecordingsEnumChecker = Helpers::EnumCheck<LiteraryTestForSoundRecordings, LiteraryTestForSoundRecordings::Autobiography, LiteraryTestForSoundRecordings::Biography, LiteraryTestForSoundRecordings::ConferenceProceedings, LiteraryTestForSoundRecordings::Drama, LiteraryTestForSoundRecordings::Essays, LiteraryTestForSoundRecordings::Fiction, LiteraryTestForSoundRecordings::Reporting, LiteraryTestForSoundRecordings::History, LiteraryTestForSoundRecordings::Instruction, LiteraryTestForSoundRecordings::LanguageInstruction, LiteraryTestForSoundRecordings::Comedy, LiteraryTestForSoundRecordings::LecturesSpeeches, LiteraryTestForSoundRecordings::Memoirs, LiteraryTestForSoundRecordings::NotApplicable, LiteraryTestForSoundRecordings::Folktales, LiteraryTestForSoundRecordings::Poetry, LiteraryTestForSoundRecordings::Rehearsals, LiteraryTestForSoundRecordings::Sounds, LiteraryTestForSoundRecordings::Interviews, LiteraryTestForSoundRecordings::Other, LiteraryTestForSoundRecordings::NoAttemptToCode>;
        using TranspositionAndArrangementEnumChecker = Helpers::EnumCheck<TranspositionAndArrangement, TranspositionAndArrangement::NotArrangementOrTranspositionOrNotSpecified, TranspositionAndArrangement::Transposition, TranspositionAndArrangement::Arrangement, TranspositionAndArrangement::BothTransposedAndArranged, TranspositionAndArrangement::NotApplicable, TranspositionAndArrangement::Unknown, TranspositionAndArrangement::NoAttemptToCode>;

        using FrequencyEnumChecker = Helpers::EnumCheck<Frequency, Frequency::NoDeterminableFrequency, Frequency::Annual, Frequency::Bimonthly, Frequency::Semiweekly, Frequency::Daily, Frequency::Biweekly, Frequency::Semiannual, Frequency::Biennial, Frequency::Triennial, Frequency::ThreeTimesAWeek, Frequency::ThreeTimesAMonth, Frequency::ContinuouslyUpdated, Frequency::Monthly, Frequency::Quarterly, Frequency::Semimonthly, Frequency::ThreeTimesAYear, Frequency::Unknown, Frequency::Weekly, Frequency::Other, Frequency::NoAttemptToCode>;
        using RegularityEnumChecker = Helpers::EnumCheck<Regularity, Regularity::NormalizedIrregular, Regularity::Regular, Regularity::Unknown, Regularity::CompletelyIrregular, Regularity::NoAttemptToCode>;
        using TypeOfContinuingResourceEnumChecker = Helpers::EnumCheck<TypeOfContinuingResource, TypeOfContinuingResource::UpdatingDatabase, TypeOfContinuingResource::Magazine, TypeOfContinuingResource::Blog, TypeOfContinuingResource::Journal, TypeOfContinuingResource::UpdatingLooseLeaf, TypeOfContinuingResource::MonographicSeries, TypeOfContinuingResource::Newspaper, TypeOfContinuingResource::Periodical, TypeOfContinuingResource::Repository, TypeOfContinuingResource::Newsletter, TypeOfContinuingResource::Directory, TypeOfContinuingResource::UpdatingWebSite, TypeOfContinuingResource::NoAttemptToCode>;
        using FormOfOriginalItemContinuingResourcesEnumChecker = Helpers::EnumCheck<FormOfOriginalItemContinuingResources, FormOfOriginalItemContinuingResources::NoSpecifiedForm, FormOfOriginalItemContinuingResources::Microfilm, FormOfOriginalItemContinuingResources::Microfiche, FormOfOriginalItemContinuingResources::Microopaque, FormOfOriginalItemContinuingResources::LargePrint, FormOfOriginalItemContinuingResources::NewspaperFormat, FormOfOriginalItemContinuingResources::Braille, FormOfOriginalItemContinuingResources::Online, FormOfOriginalItemContinuingResources::DirectElectronic, FormOfOriginalItemContinuingResources::Electronic, FormOfOriginalItemContinuingResources::NoAttemptToCode>;
        using FormOfItemConitnuingResourcesEnumChecker = Helpers::EnumCheck<FormOfItemConitnuingResources, FormOfItemConitnuingResources::NoSpecifiedForm, FormOfItemConitnuingResources::Microfilm, FormOfItemConitnuingResources::Microfiche, FormOfItemConitnuingResources::Microopaque, FormOfItemConitnuingResources::LargePrint, FormOfItemConitnuingResources::Braille, FormOfItemConitnuingResources::Online, FormOfItemConitnuingResources::DirectElectronic, FormOfItemConitnuingResources::RegularPrintReproduction, FormOfItemConitnuingResources::Electronic, FormOfItemConitnuingResources::NoAttemptToCode>;
        using NatureOfEntireWorkEnumChecker = Helpers::EnumCheck<NatureOfEntireWork, NatureOfEntireWork::NotSpecified, NatureOfEntireWork::AbstractsSummaries, NatureOfEntireWork::Bibliographies, NatureOfEntireWork::Catalogs, NatureOfEntireWork::Dictionaries, NatureOfEntireWork::Encyclopedias, NatureOfEntireWork::Handbooks, NatureOfEntireWork::LegalArticles, NatureOfEntireWork::Biography, NatureOfEntireWork::Indexes, NatureOfEntireWork::Discographies, NatureOfEntireWork::Legislation, NatureOfEntireWork::Theses, NatureOfEntireWork::SurveysOfLiteratureInASubjectArea, NatureOfEntireWork::Reviews, NatureOfEntireWork::ProgrammedTexts, NatureOfEntireWork::Filmographies, NatureOfEntireWork::Directories, NatureOfEntireWork::Statistics, NatureOfEntireWork::TechnicalReports, NatureOfEntireWork::StandardsSpecifications, NatureOfEntireWork::LegalCasesAndCaseNotes, NatureOfEntireWork::LawReportsAndDigests, NatureOfEntireWork::Yearbooks, NatureOfEntireWork::Treaties, NatureOfEntireWork::Calendars, NatureOfEntireWork::ComicsGraphicNovels, NatureOfEntireWork::NoAttemptToCode>;
        using NatureOfContentsContinuingResourcesEnumChecker = Helpers::EnumCheck<NatureOfContentsContinuingResources, NatureOfContentsContinuingResources::NotSpecified, NatureOfContentsContinuingResources::AbstractsSummaries, NatureOfContentsContinuingResources::Bibliographies, NatureOfContentsContinuingResources::Catalogs, NatureOfContentsContinuingResources::Dictionaries, NatureOfContentsContinuingResources::Encyclopedias, NatureOfContentsContinuingResources::Handbooks, NatureOfContentsContinuingResources::LegalArticles, NatureOfContentsContinuingResources::Biography, NatureOfContentsContinuingResources::Indexes, NatureOfContentsContinuingResources::Discographies, NatureOfContentsContinuingResources::Legislation, NatureOfContentsContinuingResources::Theses, NatureOfContentsContinuingResources::SurveysOfLiteratureInASubjectArea, NatureOfContentsContinuingResources::Reviews, NatureOfContentsContinuingResources::ProgrammedTexts, NatureOfContentsContinuingResources::Filmographies, NatureOfContentsContinuingResources::Directories, NatureOfContentsContinuingResources::Statistics, NatureOfContentsContinuingResources::TechnicalReports, NatureOfContentsContinuingResources::StandardsSpecifications, NatureOfContentsContinuingResources::LegalCasesAndCaseNotes, NatureOfContentsContinuingResources::LawReportsAndDigests, NatureOfContentsContinuingResources::Yearbooks, NatureOfContentsContinuingResources::Treaties, NatureOfContentsContinuingResources::Calendars, NatureOfContentsContinuingResources::ComicsGraphicNovels, NatureOfContentsContinuingResources::NoAttemptToCode>;
        using OriginalAlphabetOrScriptOfTitleEnumChecker = Helpers::EnumCheck<OriginalAlphabetOrScriptOfTitle, OriginalAlphabetOrScriptOfTitle::NoAlphabetOrScriptGivenNoKeyTitle, OriginalAlphabetOrScriptOfTitle::BasicRoman, OriginalAlphabetOrScriptOfTitle::ExtendedRoman, OriginalAlphabetOrScriptOfTitle::Cyrillic, OriginalAlphabetOrScriptOfTitle::Japanese, OriginalAlphabetOrScriptOfTitle::Chinese, OriginalAlphabetOrScriptOfTitle::Arabic, OriginalAlphabetOrScriptOfTitle::Greek, OriginalAlphabetOrScriptOfTitle::Hebrew, OriginalAlphabetOrScriptOfTitle::Thai, OriginalAlphabetOrScriptOfTitle::Devanagari, OriginalAlphabetOrScriptOfTitle::Korean, OriginalAlphabetOrScriptOfTitle::Tamil, OriginalAlphabetOrScriptOfTitle::Unknown, OriginalAlphabetOrScriptOfTitle::Other, OriginalAlphabetOrScriptOfTitle::NoAttemptToCode>;
        using EntryConventionEnumChecker = Helpers::EnumCheck<EntryConvention, EntryConvention::SuccessiveEntry, EntryConvention::LatestEntry, EntryConvention::IntegratedEntry, EntryConvention::NoAttemptToCode>;

        using FormOfItemVisualMaterialsEnumChecker = Helpers::EnumCheck<FormOfItemVisualMaterials, FormOfItemVisualMaterials::NoSpecifiedForm, FormOfItemVisualMaterials::Microfilm, FormOfItemVisualMaterials::Microfiche, FormOfItemVisualMaterials::Microopaque, FormOfItemVisualMaterials::LargePrint, FormOfItemVisualMaterials::Braille, FormOfItemVisualMaterials::Online, FormOfItemVisualMaterials::DirectElectronic, FormOfItemVisualMaterials::RegularPrintReproduction, FormOfItemVisualMaterials::Electronic, FormOfItemVisualMaterials::NoAttemptToCode>;
        using TypeOfVisualMaterialEnumChecker = Helpers::EnumCheck<TypeOfVisualMaterial, TypeOfVisualMaterial::ArtOriginal, TypeOfVisualMaterial::Kit, TypeOfVisualMaterial::ArtReproduction, TypeOfVisualMaterial::Diorama, TypeOfVisualMaterial::Filmstrip, TypeOfVisualMaterial::Game, TypeOfVisualMaterial::Picture, TypeOfVisualMaterial::Graphic, TypeOfVisualMaterial::TechnicalDrawing, TypeOfVisualMaterial::MotionPicture, TypeOfVisualMaterial::Chart, TypeOfVisualMaterial::FlashCard, TypeOfVisualMaterial::MicroscopeSlide, TypeOfVisualMaterial::Model, TypeOfVisualMaterial::Realia, TypeOfVisualMaterial::Slide, TypeOfVisualMaterial::Transparency, TypeOfVisualMaterial::Videorecording, TypeOfVisualMaterial::Toy, TypeOfVisualMaterial::Other, TypeOfVisualMaterial::NoAttemptToCode>;
        using TechniqueEnumChecker = Helpers::EnumCheck<Technique, Technique::Animation, Technique::AnimationAndLiveAction, Technique::LiveAction, Technique::NotApplicable, Technique::Unknown, Technique::Other, Technique::NoAttemptToCode>;

        using FormOfItemUnspecifiedEnumChecker = Helpers::EnumCheck<FormOfItemUnspecified, FormOfItemUnspecified::NoSpecifiedForm, FormOfItemUnspecified::Microfilm, FormOfItemUnspecified::Microfiche, FormOfItemUnspecified::Microopaque, FormOfItemUnspecified::LargePrint, FormOfItemUnspecified::Braille, FormOfItemUnspecified::Online, FormOfItemUnspecified::DirectElectronic, FormOfItemUnspecified::RegularPrintReproduction, FormOfItemUnspecified::Electronic, FormOfItemUnspecified::NoAttemptToCode>;
    };

} // MARC
// LibManager

#endif //LIBMANAGERSERVER_FIXEDLENGTHDATAELEMENTSENUMHELPER_H
