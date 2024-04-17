//
// Created by csger on 2024. 03. 17..
//

//Please god forgive me for this code

#ifndef LIBMANAGERSERVER_PHYSICALDESCRIPTIONENUMHELPERS_H
#define LIBMANAGERSERVER_PHYSICALDESCRIPTIONENUMHELPERS_H

#include <cstdint>

#include "../../helpers.h"

namespace LibManager::MARC {

    class PhysicalDescriptionEnumHelpers {
    public:
        enum class Material : uint8_t {
            Map = 'a',
            Electronic = 'c',
            Globe = 'd',
            TactileMaterial = 'f',
            ProjectedGraphic = 'g',
            Microform = 'h',
            NonProjectedGraphic = 'k',
            MotionPicture = 'm',
            Kit = 'o',
            NotatedMusic = 'q',
            RemoteSensingImage = 'r',
            SoundRecording = 's',
            Text = 't',
            VideoRecording = 'v',
            Unspecified = 'z'
        };

        enum class SpecificMaterialDesignationMap : uint8_t {
            Atlas = 'd',
            Diagram = 'g',
            Map = 'j',
            Profile = 'k',
            Model = 'q',
            RemoteSensingImage = 'r',
            Section = 's',
            Unknown = 'u',
            View = 'v',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class ColorMapGlobe : uint8_t {
            oneColor = 'a',
            MultipleColors = 'c',
            NoAttemptToCode = '|'
        };

        enum class PhysicalMediumMap : uint8_t {
            Paper = 'a',
            Wood = 'b',
            Stone = 'c',
            Metal = 'd',
            Synthetic = 'e',
            Skin = 'f',
            Textile = 'g',
            Plastic = 'i',
            Glass = 'j',
            Vinyl = 'l',
            Vellum = 'n',
            Plaster = 'p',
            FlexibleBasePhotographicPos = 'q',
            FlexibleBasePhotographicNeg = 'r',
            NonFlexibleBasePhotographicPos = 's',
            NonFlexibleBasePhotographicNeg = 't',
            Unknown = 'u',
            Leather = 'v',
            Parchment = 'w',
            NotApplicable = 'x',
            OtherPhotographicMedium = 'y',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class TypeOfReproduction : uint8_t {
            Facsimile = 'f',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class ProductionDetails : uint8_t {
            PhotoCopyOrBlueLinePrint = 'a',
            PhotoCopy = 'b',
            PhotographicPreProduction = 'c',
            Film = 'd',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class PositiveNegativeAspect : uint8_t {
            Positive = 'a',
            Negative = 'b',
            MixedPolarity = 'm',
            NotApplicable = 'n',
            NoAttemptToCode = '|'
        };

        enum class SpecificMaterialDesignationElectronicResource : uint8_t {
            TapeCartridge = 'a',
            ChipCartridge = 'b',
            ComputerOpticalDiscCartridge = 'c',
            ComputerDisc = 'd',
            ComputerDiscCartridge = 'e',
            TapeCassette = 'f',
            TapeReel = 'h',
            MagneticDisk = 'j',
            ComputerCard = 'k',
            MagnetoOpticalDisc = 'm',
            OpticalDisc = 'o',
            Remote = 'r',
            StandAloneDevice = 's',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class ColorElectric : uint8_t {
            OneColor = 'a',
            BlackAndWhite = 'b',
            MultiColor = 'c',
            GrayScale = 'g',
            Mixed = 'm',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class DimensionElectric : uint8_t {
            ThreeAndHalfInch = 'a',
            TwelveInch = 'e',
            FourAndThreeQuarterInch = 'g',
            OneAndOneEighthInch = 'i',
            ThreeAndSevenEighthInch = 'j',
            NotApplicable = 'n',
            FiveAndOneQuarterInch = 'o',
            Unknown = 'u',
            EightInch = 'v',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class SoundElectric : uint8_t {
            Silent = '#',
            Sound = 'a',
            Unknown = 'u',
            NoAttemptToCode = '|'
        };

        enum class FileFormatElectric : uint8_t {
            OneFileFormat = 'a',
            MultipleFileFormat = 'm',
            Unknown = 'u',
            NoAttemptToCode = '|'
        };

        enum class QualityAssuranceTargetElectric : uint8_t {
            Absent = 'a',
            NotApplicable = 'n',
            Present = 'p',
            Unknown = 'u',
            NoAttemptToCode = '|'
        };

        enum class AntecedentSourceElectric : uint8_t {
            Original = 'a',
            Microform = 'b',
            ElectronicResource = 'c',
            Intermediate = 'd',
            Mixed = 'm',
            NotApplicable = 'n',
            Unknown = 'u',
            NoAttemptToCode = '|'
        };

        enum class LevelOfCompressionElectric : uint8_t {
            Uncompressed = 'a',
            Lossless = 'b',
            Lossy = 'd',
            Mixed = 'm',
            Unknown = 'u',
            NoAttemptToCode = '|'
        };

        enum class ReformattingQualityElectric : uint8_t {
            Access = 'a',
            NotApplicable = 'n',
            Preservation = 'p',
            replacement = 'r',
            Unknown = 'u',
            NoAttemptToCode = '|'
        };

        enum class SpecificMaterialDesignationGlobe : uint8_t {
            CelestialGlobe = 'a',
            PlanetaryOrLunarGlobe = 'b',
            TerrestrialGlobe = 'c',
            EarthMoonGlobe = 'e',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class PhysicalMediumGlobe : uint8_t {
            Paper = 'a',
            Wood = 'b',
            Stone = 'c',
            Metal = 'd',
            Synthetic = 'e',
            Skin = 'f',
            Textile = 'g',
            Plastic = 'i',
            Glass = 'j',
            Vinyl = 'l',
            Vellum = 'n',
            Plaster = 'p',
            Unknown = 'u',
            Leather = 'v',
            Parchment = 'w',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class SpecificMaterialDesignationTactileMaterial : uint8_t {
            Moon = 'a',
            Braille = 'b',
            Combination = 'c',
            Tactile = 'd',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class ClassOfBrailleWriting : uint8_t {
            NoSpecifiedClass = '#',
            Literary = 'a',
            FormatCode = 'b',
            Mathematics = 'c',
            Computer = 'd',
            Music = 'e',
            Multiple = 'm',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class LevelOfContraction : uint8_t {
            Uncontracted = 'a',
            Contracted = 'b',
            Combination = 'c',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class BrailleMusicFormat : uint8_t {
            NoSpecifiedFormat = '#',
            BarOverBar = 'a',
            BarByBar = 'b',
            LineOverLine = 'c',
            Paragraph = 'd',
            SingleLine = 'e',
            SectionBySection = 'f',
            LineByLine = 'g',
            OpenScore = 'h',
            SpannerShortForm = 'i',
            ShortForm = 'j',
            Outline = 'k',
            VerticalScore = 'l',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class SpecialPhysicalCharacteristicsTactile : uint8_t {
            Print = 'a',
            JumboOrEnLargedBraille = 'b',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class SpecificMaterialDesignationProjected : uint8_t {
            FilmstripCartridge = 'c',
            Filmslip = 'd',
            Filmstrip = 'f',
            FilmstripRoll = 'o',
            Slide = 's',
            Transparency = 't',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class ColorProjected : uint8_t {
            OneColor = 'a',
            BlackAndWhite = 'b',
            MultiColor = 'c',
            HandColored = 'h',
            Mixed = 'm',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class BaseOfEmulsionProjected : uint8_t {
            Glass = 'd',
            Synthetic = 'e',
            SafetyFilm = 'j',
            FilmBase = 'k',
            Mixed = 'm',
            Paper = 'o',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class SoundOnMediumProjectedMotionPicture : uint8_t {
            Silent = '#',
            Sound = 'a',
            SoundSeparateFromMedium = 'b',
            Unknown = 'u',
            NoAttemptToCode = '|'
        };

        enum class MediumForSoundProjected : uint8_t {
            NoSound = '#',
            OpticalSoundTrackOnMotionPictureFilm = 'a',
            MagneticSoundTrackOnMotionPictureFilm = 'b',
            MagneticAudioTapeCartidge = 'c',
            SoundDisc = 'd',
            MagneticAudioTapeReel = 'e',
            MagneticAudioTapeCassette = 'f',
            OpticalAndMagneticSoundTrackOnMotionPictureFilm = 'g',
            Videotape = 'v',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class DimensionProjected : uint8_t {
            Standard8mm = 'a',
            Super8mm = 'b',
            NineAndAHalfMm = 'c',
            SixteenMm = 'd',
            TwentyEightMm = 'e',
            ThirtyFiveMm = 'f',
            SeventyMm = 'g',
            TwoInch = 'j',
            TwoAndOneQuarterInch = 'k',
            FourInch = 's',
            FiveInch = 't',
            EightInch = 'v',
            NineInch = 'w',
            ThenInch = 'x',
            SevenInch = 'y',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class SecondarySupportMaterialProjected : uint8_t {
            NoSecondarySupport = '#',
            Cardboard = 'c',
            Glass = 'd',
            Synthetic = 'e',
            Metal = 'h',
            MetalAndGlass = 'j',
            SyntheticAndGlass = 'k',
            Mixed = 'm',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class SpecificMaterialDesignationMicroform : uint8_t {
            ApertureCard = 'a',
            MicrofilmCartridge = 'b',
            MicrofilmCassette = 'c',
            MicrofilmReel = 'd',
            Microfiche = 'e',
            MicroficheCassette = 'f',
            Microopaque = 'g',
            MicrofilmSlip = 'h',
            MicrofilmRoll = 'j',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class DimensionMicroform : uint8_t {
            //TODO: Special checks
            EightMillimeter = 'a',
            SixteenMillimeter = 'd',
            ThirtyFiveMillimeter = 'f',
            SeventyMillimeter = 'g',
            OneHundredAndFiveMillimeter = 'h',
            ThreeInch = 'l',
            FourInch = 'm',
            SixInch = 'o',
            ThreeAndOneFourthInch = 'p',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class ReductionRatioRange : uint8_t {
            LowReduction = 'a',
            NormalReduction = 'b',
            HighReduction = 'c',
            VeryHighReduction = 'd',
            UltraHighReduction = 'e',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class ColorMicroform : uint8_t {
            BlackAndWhite = 'b',
            Color = 'c',
            Mixed = 'm',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class EmulsionOnFilm : uint8_t {
            SilverHalide = 'a',
            Diazo = 'd',
            Vesicular = 'c',
            Mixed = 'm',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class GenerationMicroform : uint8_t {
            FirstGeneration = 'a',
            PrintingMaster = 'b',
            ServiceCopy = 'c',
            Mixed = 'm',
            Unknown = 'u',
            NoAttemptToCode = '|'
        };

        enum class BaseOfFilm : uint8_t {
            SafetyBaseUndetermined = 'a',
            SafetyBaseAcetate = 'c',
            SafetyBaseDiacetate = 'd',
            NitrateBase = 'i',
            Mixed = 'm',
            NotApplicable = 'n',
            SafetyBasePolyester = 'p',
            SafetyBaseMixed = 'r',
            SafetyBaseTriacetate = 't',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class SpecificMaterialDesignationNonProjected : uint8_t {
            ActivityCard = 'a',
            Collage = 'c',
            Drawing = 'd',
            Painting = 'e',
            PhotoMechanicalPrint = 'f',
            PhotoNegative = 'g',
            PhotoPrint = 'h',
            Picture = 'i',
            Print = 'j',
            Poster = 'k',
            TechnicalDrawing = 'l',
            Chart = 'n',
            FlashCard = 'o',
            Postcard = 'p',
            Icon = 'q',
            RadioGraph = 'r',
            StudyPrint = 's',
            Unspecified = 'u',
            Photograph = 'v',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class ColorNonProjected : uint8_t {
            OneColor = 'a',
            BlackAndWhite = 'b',
            MultiColor = 'c',
            HandColored = 'h',
            Mixed = 'm',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class PrimarySupportMaterial : uint8_t {
            Canvas = 'a',
            BristolBoard = 'b',
            CardboardIllustrationBoard = 'c',
            Glass = 'd',
            Synthetic = 'e',
            Skin = 'f',
            Textile = 'g',
            Metal = 'h',
            Plastic = 'i',
            Vinyl = 'l',
            MixedCollection = 'm',
            Vellum = 'n',
            Paper = 'o',
            Plaster = 'p',
            Hardboard = 'q',
            Porcelain = 'r',
            Stone = 's',
            Wood = 't',
            Unknown = 'u',
            Leather = 'v',
            Parchment = 'w',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class SecondarySupportMaterialNonProjected : uint8_t {
            NoSecondarySupport = '#',
            Canvas = 'a',
            BristolBoard = 'b',
            CardboardIllustrationBoard = 'c',
            Glass = 'd',
            Synthetic = 'e',
            Skin = 'f',
            Textile = 'g',
            Metal = 'h',
            Plastic = 'i',
            Vinyl = 'l',
            MixedCollection = 'm',
            Vellum = 'n',
            Paper = 'o',
            Plaster = 'p',
            Hardboard = 'q',
            Porcelain = 'r',
            Stone = 's',
            Wood = 't',
            Unknown = 'u',
            Leather = 'v',
            Parchment = 'w',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class SpecificMaterialDesignationMotionPicture : uint8_t {
            FilmCartridge = 'c',
            FilmCassette = 'f',
            FilmRoll = 'o',
            FilmReel = 'r',
            Unspecified = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class ColorMotionPicture : uint8_t {
            BlackAndWhite = 'b',
            MultiColor = 'c',
            HandColored = 'h',
            Mixed = 'm',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class MotionPicturePresentationFormat : uint8_t {
            StandardSoundAperture = 'a',
            Nonanamorphic = 'b',
            ThreeD = 'c',
            Anamorphic = 'd',
            OtherWideScreenFormat = 'e',
            StandardSilentAperture = 'f',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class MediumForSoundMotionPicture : uint8_t {
            NoSound = '#',
            OpticalSoundTrackOnMotionPictureFilm = 'a',
            MagneticSoundTrackOnMotionPictureFilm = 'b',
            MagneticAudioTapeCartidge = 'c',
            SoundDisc = 'd',
            MagneticAudioTapeReel = 'e',
            MagneticAudioTapeCassette = 'f',
            OpticalAndMagneticSoundTrackOnMotionPictureFilm = 'g',
            Videotape = 'h',
            Videodisc = 'i',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class DimensionMotionPicture : uint8_t {
            Standard8mm = 'a',
            Super8mm = 'b',
            NineAndAHalfMm = 'c',
            SixteenMm = 'd',
            TwentyEightMm = 'e',
            ThirtyFiveMm = 'f',
            SeventyMm = 'g',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class ConfigurationOfPlaybackChannelsMotionPicture : uint8_t {
            Mixed = 'k',
            Monaural = 'm',
            NotApplicable = 'n',
            Quadraphonic = 'q',
            Stereophonic = 's',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class ProductionElements : uint8_t {
            Workprint = 'a',
            Trims = 'b',
            Outtakes = 'c',
            Rushes = 'd',
            MixingTracks = 'e',
            TitleBandsInterTitleRolls = 'f',
            ProductionRolls = 'g',
            NotApplicable = 'n',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class GenerationMotionPicture : uint8_t {
            Duplicate = 'd',
            Master = 'e',
            Original = 'o',
            ReferencePrintViewingCopy = 'r',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class RefinedCategoriesOfColor : uint8_t {
            ThreeLayerColor = 'a',
            TwoColorSingleStrip = 'b',
            UndeterminedTwoColor = 'c',
            UndeterminedThreeColor = 'd',
            ThreeStripColor = 'e',
            TwoStripColor = 'f',
            RedStrip = 'g',
            BlueOrGreenStrip = 'h',
            CyanStrip = 'i',
            MagentaStrip = 'j',
            YellowStrip = 'k',
            S_E_N_2 = 'l',
            S_E_N_3 = 'm',
            NotApplicable = 'n',
            SepiaTone = 'p',
            OtherTone = 'q',
            Tint = 'r',
            TintedAndToned = 's',
            StencilColor = 't',
            Unknown = 'u',
            HandColored = 'v',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class KindOfColorStock : uint8_t {
            ImbibitionDyeTransferPrints = 'a',
            ThreeLayerStock = 'b',
            ThreeLayerStockLowFade = 'c',
            DuplitizedStock = 'd',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class DeteriorationStage : uint8_t {
            NoneApparent = 'a',
            NitrateSuspiciousOdor = 'b',
            NitratePungentOdor = 'c',
            NitrateBrownishDiscolorationFadingDusty = 'd',
            NitrateSticky = 'e',
            NitrateFrothyBubblesBlisters = 'f',
            NitrateCongealed = 'g',
            NitratePowder = 'h',
            NonNitrateDetectableDeterioration = 'k',
            NonNitrateAdvancedDeterioration = 'l',
            NonNitrateDisaster = 'm',
            NoAttemptToCode = '|'
        };

        enum class Completness : uint8_t {
            Complete = 'c',
            Incomplete = 'i',
            NoApplicable = 'n',
            Unknown = 'u',
            NoAttemptToCode = '|'
        };

        enum class SpecificMaterialDesignationKitNotedMusicRemoteSensingImage : uint8_t {
            Unspecified = 'u',
            NoAttemptToCode = '|'
        };

        enum class AltitudeOfSensor : uint8_t {
            Surface = 'a',
            Airborne = 'b',
            Spaceborne = 'c',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class AttitudeOfSensor : uint8_t {
            LowOblique = 'a',
            HighOblique = 'b',
            Vertical = 'c',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class CloudCover : uint8_t {
            Zero = '0',
            Ten = '1',
            Twenty = '2',
            Thirty = '3',
            Forty = '4',
            Fifty = '5',
            Sixty = '6',
            Seventy = '7',
            Eighty = '8',
            Ninety = '9',
            NotApplicable = 'n',
            Unknown = 'u',
            NoAttemptToCode = '|'
        };

        enum class PlatformConstructionType : uint8_t {
            Ballon = 'a',
            AircraftLowAltitude = 'b',
            AircraftMediumAltitude = 'c',
            AircraftHighAltitude = 'd',
            MannedSpacecraft = 'e',
            UnmannedSpacecraft = 'f',
            LandBasedRemoteSensingDevice = 'g',
            WaterSurfaceBasedRemoteSensingDevice = 'h',
            SubmersibleRemoteSensingDevice = 'i',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class PlatformCategory : uint8_t {
            Meteorological = 'a',
            SurfaceObserving = 'b',
            SpaceObserving = 'c',
            MixedUses = 'm',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class SensorType : uint8_t {
            Active = 'a',
            Passive = 'b',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        static constexpr std::array<frozen::string, 42> dataType = {
                "aa",
                "da",
                "db",
                "dc",
                "dd",
                "de",
                "df",
                "dv",
                "dz",
                "ga",
                "gb",
                "gc",
                "gd",
                "ge",
                "gf",
                "gg",
                "gu",
                "gz",
                "ja",
                "jb",
                "jc",
                "jv",
                "jz",
                "ma",
                "mb",
                "mm",
                "nn",
                "pa",
                "pb",
                "pc",
                "pd",
                "pe",
                "pz",
                "ra",
                "rb",
                "rc",
                "rd",
                "sa",
                "ta",
                "uu",
                "zz",
                "||"
        };

        enum class SpecificMaterialDesignationSoundRecording : uint8_t {
            Belt = 'b',
            SoundDisc = 'd',
            Cylinder = 'e',
            SoundCartridge = 'g',
            SoundTrackFilm = 'i',
            Roll = 'q',
            Remote = 'r',
            SoundCassette = 's',
            SoundTapeReel = 't',
            Unspecified = 'u',
            WireRecording = 'w',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class Speed : uint8_t {
            SixteenRPM = 'a',
            ThirtyThreeRPM = 'b',
            FortyFiveRPM = 'c',
            SeventyEightRPM = 'd',
            EightRPM = 'e',
            OnePointFourMPerSecond = 'f',
            OneHundredTwentyRPM = 'h',
            OneHundredSixtyRPM = 'i',
            FifteenSixteenthIPS = 'k',
            OneAndSevenSixteenthIPS = 'l',
            OneAndSevenEighthIPS = 'm',
            ThreeAndThreeFourthIPS = 'n',
            SevenAndOneHalfIPS = 'o',
            FifteenIPS = 'p',
            ThirtyIPS = 'r',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class ConfigurationOfPlaybackChannelsSoundRecording : uint8_t {
            Monaural = 'm',
            Quadraphonic = 'q',
            Stereophonic = 's',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };
        enum class GrooveWidth : uint8_t {
            Microgroove = 'm',
            NotApplicable = 'n',
            Standard = 's',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class DimensionSoundRecording : uint8_t {
            ThreeInch = 'a',
            FiveInch = 'b',
            SevenInch = 'c',
            TenInch = 'd',
            TwelveInch = 'e',
            SixteenInch = 'f',
            FourAndThreeQuarterInch = 'g',
            ThreeAndSevenEighthInch = 'h',
            NotApplicable = 'n',
            FiveAndOneQuarterInch = 'o',
            TwoAndThreeQuarterInch = 's',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class TapeWidth : uint8_t {
            OneEighthInch = 'l',
            OneQuarterInch = 'm',
            NotApplicable = 'n',
            OneHalfInch = 'o',
            OneInch = 'p',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class TapeConfiguration : uint8_t {
            FullTrack = 'a',
            HalfTrack = 'b',
            QuarterTrack = 'c',
            EightTrack = 'd',
            TwelveTrack = 'e',
            SixteenTrack = 'f',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class KindOfDisc : uint8_t {
            MasterTape = 'a',
            TapeDuplicationMaster = 'b',
            DiscMasterNegative = 'd',
            InstantaneousRecordedOnTheSpot = 'i',
            MassProduced = 'm',
            NotApplicable = 'n',
            MotherPositive = 'r',
            StamperNegative = 's',
            TestPressing = 't',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class KindOfMaterial : uint8_t {
            LacquerCoating = 'a',
            CelluloseNitrate = 'b',
            AcetateTapeWithFerrousOxide = 'c',
            GlassWithLacquer = 'g',
            AluminumWithLacquer = 'i',
            Metal = 'l',
            PlasticWithMetal = 'm',
            NotApplicable = 'n',
            PaperWithLacquerOrFerrousOxide = 'r',
            Shellac = 's',
            Wax = 'w',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class KindOfCutting : uint8_t {
            HillAndDale = 'h',
            LateralOrCombined = 'l',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class SpecialPlaybackCharacteristics : uint8_t {
            NABStandard = 'a',
            CCIRStandard = 'b',
            DolbyBEncoded = 'c',
            dbxEncoded = 'd',
            DigitalRecording = 'e',
            DolbyAEncoded = 'f',
            DolbyCEncoded = 'g',
            CXEncoded = 'h',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class OriginalCapture : uint8_t {
            AcousticalCaptureAnalogDirectStorage = 'a',
            ElectricalCaptureAnalogDirectStorage = 'b',
            ElectricalCaptureDigitalStorage = 'd',
            ElectricalCaptureAnalogElectricalStorage = 'e',
            UnknownCaptureAndStorage = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class SpecificMaterialDesignationText : uint8_t {
            RegularPrint = 'a',
            LargePrint = 'b',
            Braille = 'c',
            LooseLeaf = 'd',
            Unspecified = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class SpecificMaterialDesignationVideoRecording : uint8_t {
            Videocartridge = 'c',
            Videodisc = 'd',
            Videocassette = 'f',
            Videoreel = 'r',
            Unspecified = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class ColorVideoRecording : uint8_t {
            OneColor = 'a',
            BlackAndWhite = 'b',
            MultiColor = 'c',
            Mixed = 'm',
            NotApplicable = 'n',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class VideoRecordingFormat : uint8_t {
            Beta = 'a',
            VHS = 'b',
            U_matic = 'c',
            EIAJ = 'd',
            TypeC = 'e',
            Quadruplex = 'f',
            Laserdisc = 'g',
            CED = 'h',
            Betacam = 'i',
            BetacamSP = 'j',
            SuperVHS = 'k',
            M_II = 'm',
            D_2 = 'o',
            EightMM = 'p',
            Hi_8MM = 'q',
            Blu_rayDisc = 's',
            Unknown = 'u',
            DVD = 'v',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class SoundOnMediumVideoRecording : uint8_t {
            NoSound = 'a',
            Sound = 'b',
            SoundSeparateFromMedium = 'c',
            Unknown = 'u',
            NoAttemptToCode = '|'
        };

        enum class MediumForSoundVideoRecording : uint8_t {
            NoSound = 'a',
            OpticalSoundTrackOnMotionPictureFilm = 'b',
            MagneticSoundTrackOnMotionPictureFilm = 'c',
            MagneticAudioTapeCartidge = 'd',
            SoundDisc = 'e',
            MagneticAudioTapeReel = 'f',
            OpticalAndMagneticSoundTrackOnMotionPictureFilm = 'g',
            Videotape = 'h',
            Videodisc = 'i',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class DimensionVideoRecording : uint8_t {
            EightMM = 'a',
            OneQuarterInch = 'm',
            OneHalfInch = 'o',
            OneInch = 'p',
            TwoInch = 'q',
            ThreeQuarterInch = 'r',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class ConfigurationOfPlaybackChannelsVideoRecording : uint8_t {
            Mixed = 'k',
            Monaural = 'm',
            NotApplicable = 'n',
            Quadraphonic = 'q',
            Stereophonic = 's',
            Unknown = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        enum class SpecificMaterialDesignationUnspecified : uint8_t {
            MultiplePhysicalForms = 'm',
            Unspecified = 'u',
            Other = 'z',
            NoAttemptToCode = '|'
        };

        using MaterialEnumChecker = Helpers::EnumCheck<Material, Material::Map, Material::Electronic, Material::Globe, Material::TactileMaterial, Material::ProjectedGraphic, Material::Microform, Material::NonProjectedGraphic, Material::MotionPicture, Material::Kit, Material::NotatedMusic, Material::RemoteSensingImage, Material::SoundRecording, Material::Text, Material::VideoRecording, Material::Unspecified>;

        using SpecificMaterialDesignationMapEnumChecker = Helpers::EnumCheck<SpecificMaterialDesignationMap, SpecificMaterialDesignationMap::Atlas, SpecificMaterialDesignationMap::Diagram, SpecificMaterialDesignationMap::Map, SpecificMaterialDesignationMap::Profile, SpecificMaterialDesignationMap::Model, SpecificMaterialDesignationMap::RemoteSensingImage, SpecificMaterialDesignationMap::Section, SpecificMaterialDesignationMap::Unknown, SpecificMaterialDesignationMap::View, SpecificMaterialDesignationMap::Other, SpecificMaterialDesignationMap::NoAttemptToCode>;
        using ColorMapGlobeEnumChecker = Helpers::EnumCheck<ColorMapGlobe, ColorMapGlobe::oneColor, ColorMapGlobe::MultipleColors, ColorMapGlobe::NoAttemptToCode>;
        using PhysicalMediumMapEnumChecker = Helpers::EnumCheck<PhysicalMediumMap, PhysicalMediumMap::Paper, PhysicalMediumMap::Wood, PhysicalMediumMap::Stone, PhysicalMediumMap::Metal, PhysicalMediumMap::Synthetic, PhysicalMediumMap::Skin, PhysicalMediumMap::Textile, PhysicalMediumMap::Plastic, PhysicalMediumMap::Glass, PhysicalMediumMap::Vinyl, PhysicalMediumMap::Vellum, PhysicalMediumMap::Plaster, PhysicalMediumMap::FlexibleBasePhotographicPos, PhysicalMediumMap::FlexibleBasePhotographicNeg, PhysicalMediumMap::NonFlexibleBasePhotographicPos, PhysicalMediumMap::NonFlexibleBasePhotographicNeg, PhysicalMediumMap::Unknown, PhysicalMediumMap::Leather, PhysicalMediumMap::Parchment, PhysicalMediumMap::NotApplicable, PhysicalMediumMap::OtherPhotographicMedium, PhysicalMediumMap::Other, PhysicalMediumMap::NoAttemptToCode>;
        using TypeOfReproductionEnumChecker = Helpers::EnumCheck<TypeOfReproduction, TypeOfReproduction::Facsimile, TypeOfReproduction::NotApplicable, TypeOfReproduction::Unknown, TypeOfReproduction::Other, TypeOfReproduction::NoAttemptToCode>;
        using ProductionDetailsEnumChecker = Helpers::EnumCheck<ProductionDetails, ProductionDetails::PhotoCopyOrBlueLinePrint, ProductionDetails::PhotoCopy, ProductionDetails::PhotographicPreProduction, ProductionDetails::Film, ProductionDetails::Unknown, ProductionDetails::Other, ProductionDetails::NoAttemptToCode>;
        using PositiveNegativeAspectEnumChecker = Helpers::EnumCheck<PositiveNegativeAspect, PositiveNegativeAspect::Positive, PositiveNegativeAspect::Negative, PositiveNegativeAspect::MixedPolarity, PositiveNegativeAspect::NotApplicable, PositiveNegativeAspect::NoAttemptToCode>;

        using SpecificMaterialDesignationElectronicResourceEnumChecker = Helpers::EnumCheck<SpecificMaterialDesignationElectronicResource, SpecificMaterialDesignationElectronicResource::TapeCartridge, SpecificMaterialDesignationElectronicResource::ChipCartridge, SpecificMaterialDesignationElectronicResource::ComputerOpticalDiscCartridge, SpecificMaterialDesignationElectronicResource::ComputerDisc, SpecificMaterialDesignationElectronicResource::ComputerDiscCartridge, SpecificMaterialDesignationElectronicResource::TapeCassette, SpecificMaterialDesignationElectronicResource::TapeReel, SpecificMaterialDesignationElectronicResource::MagneticDisk, SpecificMaterialDesignationElectronicResource::ComputerCard, SpecificMaterialDesignationElectronicResource::MagnetoOpticalDisc, SpecificMaterialDesignationElectronicResource::OpticalDisc, SpecificMaterialDesignationElectronicResource::Remote, SpecificMaterialDesignationElectronicResource::StandAloneDevice, SpecificMaterialDesignationElectronicResource::Unknown, SpecificMaterialDesignationElectronicResource::Other, SpecificMaterialDesignationElectronicResource::NoAttemptToCode>;
        using ColorElectricEnumChecker = Helpers::EnumCheck<ColorElectric, ColorElectric::OneColor, ColorElectric::BlackAndWhite, ColorElectric::MultiColor, ColorElectric::GrayScale, ColorElectric::Mixed, ColorElectric::NotApplicable, ColorElectric::Unknown, ColorElectric::Other, ColorElectric::NoAttemptToCode>;
        using DimensionElectricEnumChecker = Helpers::EnumCheck<DimensionElectric, DimensionElectric::ThreeAndHalfInch, DimensionElectric::TwelveInch, DimensionElectric::FourAndThreeQuarterInch, DimensionElectric::OneAndOneEighthInch, DimensionElectric::ThreeAndSevenEighthInch, DimensionElectric::NotApplicable, DimensionElectric::FiveAndOneQuarterInch, DimensionElectric::Unknown, DimensionElectric::EightInch, DimensionElectric::Other, DimensionElectric::NoAttemptToCode>;
        using SoundElectricEnumChecker = Helpers::EnumCheck<SoundElectric, SoundElectric::Silent, SoundElectric::Sound, SoundElectric::Unknown, SoundElectric::NoAttemptToCode>;
        using FileFormatElectricEnumChecker = Helpers::EnumCheck<FileFormatElectric, FileFormatElectric::OneFileFormat, FileFormatElectric::MultipleFileFormat, FileFormatElectric::Unknown, FileFormatElectric::NoAttemptToCode>;
        using QualityAssuranceTargetElectricEnumChecker = Helpers::EnumCheck<QualityAssuranceTargetElectric, QualityAssuranceTargetElectric::Absent, QualityAssuranceTargetElectric::NotApplicable, QualityAssuranceTargetElectric::Present, QualityAssuranceTargetElectric::Unknown, QualityAssuranceTargetElectric::NoAttemptToCode>;
        using AntecedentSourceElectricEnumChecker = Helpers::EnumCheck<AntecedentSourceElectric, AntecedentSourceElectric::Original, AntecedentSourceElectric::Microform, AntecedentSourceElectric::ElectronicResource, AntecedentSourceElectric::Intermediate, AntecedentSourceElectric::Mixed, AntecedentSourceElectric::NotApplicable, AntecedentSourceElectric::Unknown, AntecedentSourceElectric::NoAttemptToCode>;
        using LevelOfCompressionElectricEnumChecker = Helpers::EnumCheck<LevelOfCompressionElectric, LevelOfCompressionElectric::Uncompressed, LevelOfCompressionElectric::Lossless, LevelOfCompressionElectric::Lossy, LevelOfCompressionElectric::Mixed, LevelOfCompressionElectric::Unknown, LevelOfCompressionElectric::NoAttemptToCode>;
        using ReformattingQualityElectricEnumChecker = Helpers::EnumCheck<ReformattingQualityElectric, ReformattingQualityElectric::Access, ReformattingQualityElectric::NotApplicable, ReformattingQualityElectric::Preservation, ReformattingQualityElectric::replacement, ReformattingQualityElectric::Unknown, ReformattingQualityElectric::NoAttemptToCode>;

        using SpecificMaterialDesignationGlobeEnumChecker = Helpers::EnumCheck<SpecificMaterialDesignationGlobe, SpecificMaterialDesignationGlobe::CelestialGlobe, SpecificMaterialDesignationGlobe::PlanetaryOrLunarGlobe, SpecificMaterialDesignationGlobe::TerrestrialGlobe, SpecificMaterialDesignationGlobe::EarthMoonGlobe, SpecificMaterialDesignationGlobe::Unknown, SpecificMaterialDesignationGlobe::Other, SpecificMaterialDesignationGlobe::NoAttemptToCode>;
        using PhysicalMediumGlobeEnumChecker = Helpers::EnumCheck<PhysicalMediumGlobe, PhysicalMediumGlobe::Paper, PhysicalMediumGlobe::Wood, PhysicalMediumGlobe::Stone, PhysicalMediumGlobe::Metal, PhysicalMediumGlobe::Synthetic, PhysicalMediumGlobe::Skin, PhysicalMediumGlobe::Textile, PhysicalMediumGlobe::Plastic, PhysicalMediumGlobe::Glass, PhysicalMediumGlobe::Vinyl, PhysicalMediumGlobe::Vellum, PhysicalMediumGlobe::Plaster, PhysicalMediumGlobe::Unknown, PhysicalMediumGlobe::Leather, PhysicalMediumGlobe::Parchment, PhysicalMediumGlobe::Other, PhysicalMediumGlobe::NoAttemptToCode>;

        using SpecificMaterialDesignationTactileMaterialEnumChecker = Helpers::EnumCheck<SpecificMaterialDesignationTactileMaterial, SpecificMaterialDesignationTactileMaterial::Moon, SpecificMaterialDesignationTactileMaterial::Braille, SpecificMaterialDesignationTactileMaterial::Combination, SpecificMaterialDesignationTactileMaterial::Tactile, SpecificMaterialDesignationTactileMaterial::Unknown, SpecificMaterialDesignationTactileMaterial::Other, SpecificMaterialDesignationTactileMaterial::NoAttemptToCode>;
        using ClassOfBrailleWritingEnumChecker = Helpers::EnumCheck<ClassOfBrailleWriting, ClassOfBrailleWriting::NoSpecifiedClass, ClassOfBrailleWriting::Literary, ClassOfBrailleWriting::FormatCode, ClassOfBrailleWriting::Mathematics, ClassOfBrailleWriting::Computer, ClassOfBrailleWriting::Music, ClassOfBrailleWriting::Multiple, ClassOfBrailleWriting::NotApplicable, ClassOfBrailleWriting::Unknown, ClassOfBrailleWriting::Other, ClassOfBrailleWriting::NoAttemptToCode>;
        using LevelOfContractionEnumChecker = Helpers::EnumCheck<LevelOfContraction, LevelOfContraction::Uncontracted, LevelOfContraction::Contracted, LevelOfContraction::Combination, LevelOfContraction::NotApplicable, LevelOfContraction::Unknown, LevelOfContraction::Other, LevelOfContraction::NoAttemptToCode>;
        using BrailleMusicFormatEnumChecker = Helpers::EnumCheck<BrailleMusicFormat, BrailleMusicFormat::NoSpecifiedFormat, BrailleMusicFormat::BarOverBar, BrailleMusicFormat::BarByBar, BrailleMusicFormat::LineOverLine, BrailleMusicFormat::Paragraph, BrailleMusicFormat::SingleLine, BrailleMusicFormat::SectionBySection, BrailleMusicFormat::LineByLine, BrailleMusicFormat::OpenScore, BrailleMusicFormat::SpannerShortForm, BrailleMusicFormat::ShortForm, BrailleMusicFormat::Outline, BrailleMusicFormat::VerticalScore, BrailleMusicFormat::NotApplicable, BrailleMusicFormat::Unknown, BrailleMusicFormat::Other, BrailleMusicFormat::NoAttemptToCode>;
        using SpecialPhysicalCharacteristicsTactileEnumChecker = Helpers::EnumCheck<SpecialPhysicalCharacteristicsTactile, SpecialPhysicalCharacteristicsTactile::Print, SpecialPhysicalCharacteristicsTactile::JumboOrEnLargedBraille, SpecialPhysicalCharacteristicsTactile::NotApplicable, SpecialPhysicalCharacteristicsTactile::Unknown, SpecialPhysicalCharacteristicsTactile::Other, SpecialPhysicalCharacteristicsTactile::NoAttemptToCode>;

        using SpecificMaterialDesignationProjectedEnumChecker = Helpers::EnumCheck<SpecificMaterialDesignationProjected, SpecificMaterialDesignationProjected::FilmstripCartridge, SpecificMaterialDesignationProjected::Filmslip, SpecificMaterialDesignationProjected::Filmstrip, SpecificMaterialDesignationProjected::FilmstripRoll, SpecificMaterialDesignationProjected::Slide, SpecificMaterialDesignationProjected::Transparency, SpecificMaterialDesignationProjected::Unknown, SpecificMaterialDesignationProjected::Other, SpecificMaterialDesignationProjected::NoAttemptToCode>;
        using ColorProjectedEnumChecker = Helpers::EnumCheck<ColorProjected, ColorProjected::OneColor, ColorProjected::BlackAndWhite, ColorProjected::MultiColor, ColorProjected::HandColored, ColorProjected::Mixed, ColorProjected::NotApplicable, ColorProjected::Unknown, ColorProjected::Other, ColorProjected::NoAttemptToCode>;
        using BaseOfEmulsionProjectedEnumChecker = Helpers::EnumCheck<BaseOfEmulsionProjected, BaseOfEmulsionProjected::Glass, BaseOfEmulsionProjected::Synthetic, BaseOfEmulsionProjected::SafetyFilm, BaseOfEmulsionProjected::FilmBase, BaseOfEmulsionProjected::Mixed, BaseOfEmulsionProjected::Paper, BaseOfEmulsionProjected::Unknown, BaseOfEmulsionProjected::Other, BaseOfEmulsionProjected::NoAttemptToCode>;
        using SoundOnMediumProjectedMotionPictureEnumChecker = Helpers::EnumCheck<SoundOnMediumProjectedMotionPicture, SoundOnMediumProjectedMotionPicture::Silent, SoundOnMediumProjectedMotionPicture::Sound, SoundOnMediumProjectedMotionPicture::SoundSeparateFromMedium, SoundOnMediumProjectedMotionPicture::Unknown, SoundOnMediumProjectedMotionPicture::NoAttemptToCode>;
        using MediumForSoundEnumChecker = Helpers::EnumCheck<MediumForSoundProjected, MediumForSoundProjected::NoSound, MediumForSoundProjected::OpticalSoundTrackOnMotionPictureFilm, MediumForSoundProjected::MagneticSoundTrackOnMotionPictureFilm, MediumForSoundProjected::MagneticAudioTapeCartidge, MediumForSoundProjected::SoundDisc, MediumForSoundProjected::MagneticAudioTapeReel, MediumForSoundProjected::MagneticAudioTapeCassette, MediumForSoundProjected::OpticalAndMagneticSoundTrackOnMotionPictureFilm, MediumForSoundProjected::Videotape, MediumForSoundProjected::Unknown, MediumForSoundProjected::Other, MediumForSoundProjected::NoAttemptToCode>;
        using DimensionProjectedEnumChecker = Helpers::EnumCheck<DimensionProjected, DimensionProjected::Standard8mm, DimensionProjected::Super8mm, DimensionProjected::NineAndAHalfMm, DimensionProjected::SixteenMm, DimensionProjected::TwentyEightMm, DimensionProjected::ThirtyFiveMm, DimensionProjected::SeventyMm, DimensionProjected::TwoInch, DimensionProjected::TwoAndOneQuarterInch, DimensionProjected::FourInch, DimensionProjected::FiveInch, DimensionProjected::EightInch, DimensionProjected::NineInch, DimensionProjected::ThenInch, DimensionProjected::SevenInch, DimensionProjected::Unknown, DimensionProjected::Other, DimensionProjected::NoAttemptToCode>;
        using SecondarySupportMaterialProjectedEnumChecker = Helpers::EnumCheck<SecondarySupportMaterialProjected, SecondarySupportMaterialProjected::NoSecondarySupport, SecondarySupportMaterialProjected::Cardboard, SecondarySupportMaterialProjected::Glass, SecondarySupportMaterialProjected::Synthetic, SecondarySupportMaterialProjected::Metal, SecondarySupportMaterialProjected::MetalAndGlass, SecondarySupportMaterialProjected::SyntheticAndGlass, SecondarySupportMaterialProjected::Mixed, SecondarySupportMaterialProjected::Unknown, SecondarySupportMaterialProjected::Other, SecondarySupportMaterialProjected::NoAttemptToCode>;

        using SpecificMaterialDesignationMicroformEnumChecker = Helpers::EnumCheck<SpecificMaterialDesignationMicroform, SpecificMaterialDesignationMicroform::ApertureCard, SpecificMaterialDesignationMicroform::MicrofilmCartridge, SpecificMaterialDesignationMicroform::MicrofilmCassette, SpecificMaterialDesignationMicroform::MicrofilmReel, SpecificMaterialDesignationMicroform::Microfiche, SpecificMaterialDesignationMicroform::MicroficheCassette, SpecificMaterialDesignationMicroform::Microopaque, SpecificMaterialDesignationMicroform::MicrofilmSlip, SpecificMaterialDesignationMicroform::MicrofilmRoll, SpecificMaterialDesignationMicroform::Unknown, SpecificMaterialDesignationMicroform::Other, SpecificMaterialDesignationMicroform::NoAttemptToCode>;
        using DimensionMicroformEnumChecker = Helpers::EnumCheck<DimensionMicroform, DimensionMicroform::EightMillimeter, DimensionMicroform::SixteenMillimeter, DimensionMicroform::ThirtyFiveMillimeter, DimensionMicroform::SeventyMillimeter, DimensionMicroform::OneHundredAndFiveMillimeter, DimensionMicroform::ThreeInch, DimensionMicroform::FourInch, DimensionMicroform::SixInch, DimensionMicroform::ThreeAndOneFourthInch, DimensionMicroform::Unknown, DimensionMicroform::Other, DimensionMicroform::NoAttemptToCode>;
        using ReductionRatioRangeEnumChecker = Helpers::EnumCheck<ReductionRatioRange, ReductionRatioRange::LowReduction, ReductionRatioRange::NormalReduction, ReductionRatioRange::HighReduction, ReductionRatioRange::VeryHighReduction, ReductionRatioRange::UltraHighReduction, ReductionRatioRange::Unknown, ReductionRatioRange::Other, ReductionRatioRange::NoAttemptToCode>;
        using ColorMicroformEnumChecker = Helpers::EnumCheck<ColorMicroform, ColorMicroform::BlackAndWhite, ColorMicroform::Color, ColorMicroform::Mixed, ColorMicroform::Unknown, ColorMicroform::Other, ColorMicroform::NoAttemptToCode>;
        using EmulsionOnFilmEnumChecker = Helpers::EnumCheck<EmulsionOnFilm, EmulsionOnFilm::SilverHalide, EmulsionOnFilm::Diazo, EmulsionOnFilm::Vesicular, EmulsionOnFilm::Mixed, EmulsionOnFilm::NotApplicable, EmulsionOnFilm::Unknown, EmulsionOnFilm::Other, EmulsionOnFilm::NoAttemptToCode>;
        using GenerationEnumChecker = Helpers::EnumCheck<GenerationMicroform, GenerationMicroform::FirstGeneration, GenerationMicroform::PrintingMaster, GenerationMicroform::ServiceCopy, GenerationMicroform::Mixed, GenerationMicroform::Unknown, GenerationMicroform::NoAttemptToCode>;
        using BaseOfFilmEnumChecker = Helpers::EnumCheck<BaseOfFilm, BaseOfFilm::SafetyBaseUndetermined, BaseOfFilm::SafetyBaseAcetate, BaseOfFilm::SafetyBaseDiacetate, BaseOfFilm::NitrateBase, BaseOfFilm::Mixed, BaseOfFilm::NotApplicable, BaseOfFilm::SafetyBasePolyester, BaseOfFilm::SafetyBaseMixed, BaseOfFilm::SafetyBaseTriacetate, BaseOfFilm::Unknown, BaseOfFilm::Other, BaseOfFilm::NoAttemptToCode>;

        using SpecificMaterialDesignationNonProjectedEnumChecker = Helpers::EnumCheck<SpecificMaterialDesignationNonProjected, SpecificMaterialDesignationNonProjected::ActivityCard, SpecificMaterialDesignationNonProjected::Collage, SpecificMaterialDesignationNonProjected::Drawing, SpecificMaterialDesignationNonProjected::Painting, SpecificMaterialDesignationNonProjected::PhotoMechanicalPrint, SpecificMaterialDesignationNonProjected::PhotoNegative, SpecificMaterialDesignationNonProjected::PhotoPrint, SpecificMaterialDesignationNonProjected::Picture, SpecificMaterialDesignationNonProjected::Print, SpecificMaterialDesignationNonProjected::Poster, SpecificMaterialDesignationNonProjected::TechnicalDrawing, SpecificMaterialDesignationNonProjected::Chart, SpecificMaterialDesignationNonProjected::FlashCard, SpecificMaterialDesignationNonProjected::Postcard, SpecificMaterialDesignationNonProjected::Icon, SpecificMaterialDesignationNonProjected::RadioGraph, SpecificMaterialDesignationNonProjected::StudyPrint, SpecificMaterialDesignationNonProjected::Unspecified, SpecificMaterialDesignationNonProjected::Photograph, SpecificMaterialDesignationNonProjected::Other, SpecificMaterialDesignationNonProjected::NoAttemptToCode>;
        using ColorNonProjectedEnumChecker = Helpers::EnumCheck<ColorNonProjected, ColorNonProjected::OneColor, ColorNonProjected::BlackAndWhite, ColorNonProjected::HandColored, ColorNonProjected::MultiColor, ColorNonProjected::Mixed, ColorNonProjected::Unknown, ColorNonProjected::Other, ColorNonProjected::NoAttemptToCode>;
        using PrimarySupportMaterialEnumChecker = Helpers::EnumCheck<PrimarySupportMaterial, PrimarySupportMaterial::Canvas, PrimarySupportMaterial::BristolBoard, PrimarySupportMaterial::CardboardIllustrationBoard, PrimarySupportMaterial::Glass, PrimarySupportMaterial::Synthetic, PrimarySupportMaterial::Skin, PrimarySupportMaterial::Textile, PrimarySupportMaterial::Metal, PrimarySupportMaterial::Plastic, PrimarySupportMaterial::Vinyl, PrimarySupportMaterial::MixedCollection, PrimarySupportMaterial::Vellum, PrimarySupportMaterial::Paper, PrimarySupportMaterial::Plaster, PrimarySupportMaterial::Hardboard, PrimarySupportMaterial::Porcelain, PrimarySupportMaterial::Stone, PrimarySupportMaterial::Wood, PrimarySupportMaterial::Unknown, PrimarySupportMaterial::Leather, PrimarySupportMaterial::Parchment, PrimarySupportMaterial::Other, PrimarySupportMaterial::NoAttemptToCode>;
        using SecondarySupportMaterialNonProjectedEnumChecker = Helpers::EnumCheck<SecondarySupportMaterialNonProjected, SecondarySupportMaterialNonProjected::NoSecondarySupport, SecondarySupportMaterialNonProjected::Canvas, SecondarySupportMaterialNonProjected::BristolBoard, SecondarySupportMaterialNonProjected::CardboardIllustrationBoard, SecondarySupportMaterialNonProjected::Glass, SecondarySupportMaterialNonProjected::Synthetic, SecondarySupportMaterialNonProjected::Skin, SecondarySupportMaterialNonProjected::Textile, SecondarySupportMaterialNonProjected::Metal, SecondarySupportMaterialNonProjected::Plastic, SecondarySupportMaterialNonProjected::Vinyl, SecondarySupportMaterialNonProjected::MixedCollection, SecondarySupportMaterialNonProjected::Vellum, SecondarySupportMaterialNonProjected::Paper, SecondarySupportMaterialNonProjected::Plaster, SecondarySupportMaterialNonProjected::Hardboard, SecondarySupportMaterialNonProjected::Porcelain, SecondarySupportMaterialNonProjected::Stone, SecondarySupportMaterialNonProjected::Wood, SecondarySupportMaterialNonProjected::Unknown, SecondarySupportMaterialNonProjected::Leather, SecondarySupportMaterialNonProjected::Parchment, SecondarySupportMaterialNonProjected::Other, SecondarySupportMaterialNonProjected::NoAttemptToCode>;

        using SpecificMaterialDesignationMotionPictureEnumChecker = Helpers::EnumCheck<SpecificMaterialDesignationMotionPicture, SpecificMaterialDesignationMotionPicture::FilmCartridge, SpecificMaterialDesignationMotionPicture::FilmCassette, SpecificMaterialDesignationMotionPicture::FilmRoll, SpecificMaterialDesignationMotionPicture::FilmReel, SpecificMaterialDesignationMotionPicture::Unspecified, SpecificMaterialDesignationMotionPicture::Other, SpecificMaterialDesignationMotionPicture::NoAttemptToCode>;
        using ColorMotionPictureEnumChecker = Helpers::EnumCheck<ColorMotionPicture, ColorMotionPicture::BlackAndWhite, ColorMotionPicture::MultiColor, ColorMotionPicture::HandColored, ColorMotionPicture::Mixed, ColorMotionPicture::NotApplicable, ColorMotionPicture::Unknown, ColorMotionPicture::Other, ColorMotionPicture::NoAttemptToCode>;
        using MotionPicturePresentationFormatEnumChecker = Helpers::EnumCheck<MotionPicturePresentationFormat, MotionPicturePresentationFormat::StandardSoundAperture, MotionPicturePresentationFormat::Nonanamorphic, MotionPicturePresentationFormat::ThreeD, MotionPicturePresentationFormat::Anamorphic, MotionPicturePresentationFormat::OtherWideScreenFormat, MotionPicturePresentationFormat::StandardSilentAperture, MotionPicturePresentationFormat::Unknown, MotionPicturePresentationFormat::Other, MotionPicturePresentationFormat::NoAttemptToCode>;
        using MediumForSoundMotionPictureEnumChecker = Helpers::EnumCheck<MediumForSoundMotionPicture, MediumForSoundMotionPicture::NoSound, MediumForSoundMotionPicture::OpticalSoundTrackOnMotionPictureFilm, MediumForSoundMotionPicture::MagneticSoundTrackOnMotionPictureFilm, MediumForSoundMotionPicture::MagneticAudioTapeCartidge, MediumForSoundMotionPicture::SoundDisc, MediumForSoundMotionPicture::MagneticAudioTapeReel, MediumForSoundMotionPicture::MagneticAudioTapeCassette, MediumForSoundMotionPicture::OpticalAndMagneticSoundTrackOnMotionPictureFilm, MediumForSoundMotionPicture::Videotape, MediumForSoundMotionPicture::Videodisc, MediumForSoundMotionPicture::Unknown, MediumForSoundMotionPicture::Other, MediumForSoundMotionPicture::NoAttemptToCode>;
        using DimensionMotionPictureEnumChecker = Helpers::EnumCheck<DimensionMotionPicture, DimensionMotionPicture::Standard8mm, DimensionMotionPicture::Super8mm, DimensionMotionPicture::NineAndAHalfMm, DimensionMotionPicture::SixteenMm, DimensionMotionPicture::TwentyEightMm, DimensionMotionPicture::ThirtyFiveMm, DimensionMotionPicture::SeventyMm, DimensionMotionPicture::Unknown, DimensionMotionPicture::Other, DimensionMotionPicture::NoAttemptToCode>;
        using ConfigurationOfPlaybackChannelsEnumChecker = Helpers::EnumCheck<ConfigurationOfPlaybackChannelsMotionPicture, ConfigurationOfPlaybackChannelsMotionPicture::Mixed, ConfigurationOfPlaybackChannelsMotionPicture::Monaural, ConfigurationOfPlaybackChannelsMotionPicture::NotApplicable, ConfigurationOfPlaybackChannelsMotionPicture::Quadraphonic, ConfigurationOfPlaybackChannelsMotionPicture::Stereophonic, ConfigurationOfPlaybackChannelsMotionPicture::Unknown, ConfigurationOfPlaybackChannelsMotionPicture::Other, ConfigurationOfPlaybackChannelsMotionPicture::NoAttemptToCode>;
        using ProductionElementsEnumChecker = Helpers::EnumCheck<ProductionElements, ProductionElements::Workprint, ProductionElements::Trims, ProductionElements::Outtakes, ProductionElements::Rushes, ProductionElements::MixingTracks, ProductionElements::TitleBandsInterTitleRolls, ProductionElements::ProductionRolls, ProductionElements::NotApplicable, ProductionElements::Other, ProductionElements::NoAttemptToCode>;
        using GenerationMotionPictureEnumChecker = Helpers::EnumCheck<GenerationMotionPicture, GenerationMotionPicture::Duplicate, GenerationMotionPicture::Master, GenerationMotionPicture::Original, GenerationMotionPicture::ReferencePrintViewingCopy, GenerationMotionPicture::Unknown, GenerationMotionPicture::Other, GenerationMotionPicture::NoAttemptToCode>;
        using RefinedCategoriesOfColorEnumChecker = Helpers::EnumCheck<RefinedCategoriesOfColor, RefinedCategoriesOfColor::ThreeLayerColor, RefinedCategoriesOfColor::TwoColorSingleStrip, RefinedCategoriesOfColor::UndeterminedTwoColor, RefinedCategoriesOfColor::UndeterminedThreeColor, RefinedCategoriesOfColor::ThreeStripColor, RefinedCategoriesOfColor::TwoStripColor, RefinedCategoriesOfColor::RedStrip, RefinedCategoriesOfColor::BlueOrGreenStrip, RefinedCategoriesOfColor::CyanStrip, RefinedCategoriesOfColor::MagentaStrip, RefinedCategoriesOfColor::YellowStrip, RefinedCategoriesOfColor::S_E_N_2, RefinedCategoriesOfColor::S_E_N_3, RefinedCategoriesOfColor::NotApplicable, RefinedCategoriesOfColor::SepiaTone, RefinedCategoriesOfColor::OtherTone, RefinedCategoriesOfColor::Tint, RefinedCategoriesOfColor::TintedAndToned, RefinedCategoriesOfColor::StencilColor, RefinedCategoriesOfColor::Unknown, RefinedCategoriesOfColor::HandColored, RefinedCategoriesOfColor::Other, RefinedCategoriesOfColor::NoAttemptToCode>;
        using KindOfColorStockEnumChecker = Helpers::EnumCheck<KindOfColorStock, KindOfColorStock::ImbibitionDyeTransferPrints, KindOfColorStock::ThreeLayerStock, KindOfColorStock::ThreeLayerStockLowFade, KindOfColorStock::DuplitizedStock, KindOfColorStock::NotApplicable, KindOfColorStock::Unknown, KindOfColorStock::Other, KindOfColorStock::NoAttemptToCode>;
        using DeteriorationStageEnumChecker = Helpers::EnumCheck<DeteriorationStage, DeteriorationStage::NoneApparent, DeteriorationStage::NitrateSuspiciousOdor, DeteriorationStage::NitratePungentOdor, DeteriorationStage::NitrateBrownishDiscolorationFadingDusty, DeteriorationStage::NitrateSticky, DeteriorationStage::NitrateFrothyBubblesBlisters, DeteriorationStage::NitrateCongealed, DeteriorationStage::NitratePowder, DeteriorationStage::NonNitrateDetectableDeterioration, DeteriorationStage::NonNitrateAdvancedDeterioration, DeteriorationStage::NonNitrateDisaster, DeteriorationStage::NoAttemptToCode>;
        using CompletnessEnumChecker = Helpers::EnumCheck<Completness, Completness::Complete, Completness::Incomplete, Completness::NoApplicable, Completness::Unknown, Completness::NoAttemptToCode>;

        using SpecificMaterialDesignationKitNotedMusicRemoteSensingImageEnumChecker = Helpers::EnumCheck<SpecificMaterialDesignationKitNotedMusicRemoteSensingImage, SpecificMaterialDesignationKitNotedMusicRemoteSensingImage::Unspecified, SpecificMaterialDesignationKitNotedMusicRemoteSensingImage::NoAttemptToCode>;

        using AltitudeOfSensorEnumChecker = Helpers::EnumCheck<AltitudeOfSensor, AltitudeOfSensor::Surface, AltitudeOfSensor::Airborne, AltitudeOfSensor::Spaceborne, AltitudeOfSensor::NotApplicable, AltitudeOfSensor::Unknown, AltitudeOfSensor::Other, AltitudeOfSensor::NoAttemptToCode>;
        using AttitudeOfSensorEnumChecker = Helpers::EnumCheck<AttitudeOfSensor, AttitudeOfSensor::LowOblique, AttitudeOfSensor::HighOblique, AttitudeOfSensor::Vertical, AttitudeOfSensor::NotApplicable, AttitudeOfSensor::Unknown, AttitudeOfSensor::Other, AttitudeOfSensor::NoAttemptToCode>;
        using CloudCoverEnumChecker = Helpers::EnumCheck<CloudCover, CloudCover::Zero, CloudCover::Ten, CloudCover::Twenty, CloudCover::Thirty, CloudCover::Forty, CloudCover::Fifty, CloudCover::Sixty, CloudCover::Seventy, CloudCover::Eighty, CloudCover::Ninety, CloudCover::NotApplicable, CloudCover::Unknown, CloudCover::NoAttemptToCode>;
        using PlatformConstructionTypeEnumChecker = Helpers::EnumCheck<PlatformConstructionType, PlatformConstructionType::Ballon, PlatformConstructionType::AircraftLowAltitude, PlatformConstructionType::AircraftMediumAltitude, PlatformConstructionType::AircraftHighAltitude, PlatformConstructionType::MannedSpacecraft, PlatformConstructionType::UnmannedSpacecraft, PlatformConstructionType::LandBasedRemoteSensingDevice, PlatformConstructionType::WaterSurfaceBasedRemoteSensingDevice, PlatformConstructionType::SubmersibleRemoteSensingDevice, PlatformConstructionType::NotApplicable, PlatformConstructionType::Unknown, PlatformConstructionType::Other, PlatformConstructionType::NoAttemptToCode>;
        using PlatformCategoryEnumChecker = Helpers::EnumCheck<PlatformCategory, PlatformCategory::Meteorological, PlatformCategory::SurfaceObserving, PlatformCategory::SpaceObserving, PlatformCategory::MixedUses, PlatformCategory::NotApplicable, PlatformCategory::Unknown, PlatformCategory::Other, PlatformCategory::NoAttemptToCode>;
        using SensorTypeEnumChecker = Helpers::EnumCheck<SensorType, SensorType::Active, SensorType::Passive, SensorType::Unknown, SensorType::Other, SensorType::NoAttemptToCode>;

        using SpecificMaterialDesignationSoundRecordingEnumChecker = Helpers::EnumCheck<SpecificMaterialDesignationSoundRecording, SpecificMaterialDesignationSoundRecording::Belt, SpecificMaterialDesignationSoundRecording::SoundDisc, SpecificMaterialDesignationSoundRecording::Cylinder, SpecificMaterialDesignationSoundRecording::SoundCartridge, SpecificMaterialDesignationSoundRecording::SoundTrackFilm, SpecificMaterialDesignationSoundRecording::Roll, SpecificMaterialDesignationSoundRecording::Remote, SpecificMaterialDesignationSoundRecording::SoundCassette, SpecificMaterialDesignationSoundRecording::SoundTapeReel, SpecificMaterialDesignationSoundRecording::Unspecified, SpecificMaterialDesignationSoundRecording::WireRecording, SpecificMaterialDesignationSoundRecording::Other, SpecificMaterialDesignationSoundRecording::NoAttemptToCode>;
        using SpeedEnumChecker = Helpers::EnumCheck<Speed, Speed::SixteenRPM, Speed::ThirtyThreeRPM, Speed::FortyFiveRPM, Speed::SeventyEightRPM, Speed::EightRPM, Speed::OnePointFourMPerSecond, Speed::OneHundredTwentyRPM, Speed::OneHundredSixtyRPM, Speed::FifteenSixteenthIPS, Speed::OneAndSevenSixteenthIPS, Speed::OneAndSevenEighthIPS, Speed::ThreeAndThreeFourthIPS, Speed::SevenAndOneHalfIPS, Speed::FifteenIPS, Speed::ThirtyIPS, Speed::Unknown, Speed::Other, Speed::NoAttemptToCode>;
        using ConfigurationOfPlaybackChannelsSoundRecordingEnumChecker = Helpers::EnumCheck<ConfigurationOfPlaybackChannelsSoundRecording, ConfigurationOfPlaybackChannelsSoundRecording::Monaural, ConfigurationOfPlaybackChannelsSoundRecording::Quadraphonic, ConfigurationOfPlaybackChannelsSoundRecording::Stereophonic, ConfigurationOfPlaybackChannelsSoundRecording::Unknown, ConfigurationOfPlaybackChannelsSoundRecording::Other, ConfigurationOfPlaybackChannelsSoundRecording::NoAttemptToCode>;
        using GrooveWidthEnumChecker = Helpers::EnumCheck<GrooveWidth, GrooveWidth::Microgroove, GrooveWidth::NotApplicable, GrooveWidth::Standard, GrooveWidth::Unknown, GrooveWidth::Other, GrooveWidth::NoAttemptToCode>;
        using DimensionSoundRecordingEnumChecker = Helpers::EnumCheck<DimensionSoundRecording, DimensionSoundRecording::ThreeInch, DimensionSoundRecording::FiveInch, DimensionSoundRecording::SevenInch, DimensionSoundRecording::TenInch, DimensionSoundRecording::TwelveInch, DimensionSoundRecording::SixteenInch, DimensionSoundRecording::FourAndThreeQuarterInch, DimensionSoundRecording::ThreeAndSevenEighthInch, DimensionSoundRecording::NotApplicable, DimensionSoundRecording::FiveAndOneQuarterInch, DimensionSoundRecording::TwoAndThreeQuarterInch, DimensionSoundRecording::Unknown, DimensionSoundRecording::Other, DimensionSoundRecording::NoAttemptToCode>;
        using TapeWidthEnumChecker = Helpers::EnumCheck<TapeWidth, TapeWidth::OneEighthInch, TapeWidth::OneQuarterInch, TapeWidth::NotApplicable, TapeWidth::OneHalfInch, TapeWidth::OneInch, TapeWidth::Unknown, TapeWidth::Other, TapeWidth::NoAttemptToCode>;
        using TapeConfigurationEnumChecker = Helpers::EnumCheck<TapeConfiguration, TapeConfiguration::FullTrack, TapeConfiguration::HalfTrack, TapeConfiguration::QuarterTrack, TapeConfiguration::EightTrack, TapeConfiguration::TwelveTrack, TapeConfiguration::SixteenTrack, TapeConfiguration::NotApplicable, TapeConfiguration::Unknown, TapeConfiguration::Other, TapeConfiguration::NoAttemptToCode>;
        using KindOfDiscEnumChecker = Helpers::EnumCheck<KindOfDisc, KindOfDisc::MasterTape, KindOfDisc::TapeDuplicationMaster, KindOfDisc::DiscMasterNegative, KindOfDisc::InstantaneousRecordedOnTheSpot, KindOfDisc::MassProduced, KindOfDisc::NotApplicable, KindOfDisc::MotherPositive, KindOfDisc::StamperNegative, KindOfDisc::TestPressing, KindOfDisc::Unknown, KindOfDisc::Other, KindOfDisc::NoAttemptToCode>;
        using KindOfMaterialEnumChecker = Helpers::EnumCheck<KindOfMaterial, KindOfMaterial::LacquerCoating, KindOfMaterial::CelluloseNitrate, KindOfMaterial::AcetateTapeWithFerrousOxide, KindOfMaterial::GlassWithLacquer, KindOfMaterial::AluminumWithLacquer, KindOfMaterial::Metal, KindOfMaterial::PlasticWithMetal, KindOfMaterial::NotApplicable, KindOfMaterial::PaperWithLacquerOrFerrousOxide, KindOfMaterial::Shellac, KindOfMaterial::Wax, KindOfMaterial::Unknown, KindOfMaterial::Other, KindOfMaterial::NoAttemptToCode>;
        using KindOfCuttingEnumChecker = Helpers::EnumCheck<KindOfCutting, KindOfCutting::HillAndDale, KindOfCutting::LateralOrCombined, KindOfCutting::NotApplicable, KindOfCutting::Unknown, KindOfCutting::Other, KindOfCutting::NoAttemptToCode>;
        using SpecialPlaybackCharacteristicsEnumChecker = Helpers::EnumCheck<SpecialPlaybackCharacteristics, SpecialPlaybackCharacteristics::NABStandard, SpecialPlaybackCharacteristics::CCIRStandard, SpecialPlaybackCharacteristics::DolbyBEncoded, SpecialPlaybackCharacteristics::dbxEncoded, SpecialPlaybackCharacteristics::DigitalRecording, SpecialPlaybackCharacteristics::DolbyAEncoded, SpecialPlaybackCharacteristics::DolbyCEncoded, SpecialPlaybackCharacteristics::CXEncoded, SpecialPlaybackCharacteristics::NotApplicable, SpecialPlaybackCharacteristics::Unknown, SpecialPlaybackCharacteristics::Other, SpecialPlaybackCharacteristics::NoAttemptToCode>;
        using OriginalCaptureEnumChecker = Helpers::EnumCheck<OriginalCapture, OriginalCapture::AcousticalCaptureAnalogDirectStorage, OriginalCapture::ElectricalCaptureAnalogDirectStorage, OriginalCapture::ElectricalCaptureDigitalStorage, OriginalCapture::ElectricalCaptureAnalogElectricalStorage, OriginalCapture::UnknownCaptureAndStorage, OriginalCapture::Other, OriginalCapture::NoAttemptToCode>;

        using SpecificMaterialDesignationTextEnumChecker = Helpers::EnumCheck<SpecificMaterialDesignationText, SpecificMaterialDesignationText::RegularPrint, SpecificMaterialDesignationText::LargePrint, SpecificMaterialDesignationText::Braille, SpecificMaterialDesignationText::LooseLeaf, SpecificMaterialDesignationText::Unspecified, SpecificMaterialDesignationText::Other, SpecificMaterialDesignationText::NoAttemptToCode>;

        using SpecificMaterialDesignationVideoRecordingEnumChecker = Helpers::EnumCheck<SpecificMaterialDesignationVideoRecording, SpecificMaterialDesignationVideoRecording::Videocartridge, SpecificMaterialDesignationVideoRecording::Videodisc, SpecificMaterialDesignationVideoRecording::Videocassette, SpecificMaterialDesignationVideoRecording::Videoreel, SpecificMaterialDesignationVideoRecording::Unspecified, SpecificMaterialDesignationVideoRecording::Other, SpecificMaterialDesignationVideoRecording::NoAttemptToCode>;
        using ColorVideoRecordingEnumChecker = Helpers::EnumCheck<ColorVideoRecording, ColorVideoRecording::OneColor, ColorVideoRecording::BlackAndWhite, ColorVideoRecording::MultiColor, ColorVideoRecording::Mixed, ColorVideoRecording::NotApplicable, ColorVideoRecording::Unknown, ColorVideoRecording::Other, ColorVideoRecording::NoAttemptToCode>;
        using VideoRecordingFormatEnumChecker = Helpers::EnumCheck<VideoRecordingFormat, VideoRecordingFormat::Beta, VideoRecordingFormat::VHS, VideoRecordingFormat::U_matic, VideoRecordingFormat::EIAJ, VideoRecordingFormat::TypeC, VideoRecordingFormat::Quadruplex, VideoRecordingFormat::Laserdisc, VideoRecordingFormat::CED, VideoRecordingFormat::Betacam, VideoRecordingFormat::BetacamSP, VideoRecordingFormat::SuperVHS, VideoRecordingFormat::M_II, VideoRecordingFormat::D_2, VideoRecordingFormat::EightMM, VideoRecordingFormat::Hi_8MM, VideoRecordingFormat::Blu_rayDisc, VideoRecordingFormat::Unknown, VideoRecordingFormat::DVD, VideoRecordingFormat::Other, VideoRecordingFormat::NoAttemptToCode>;
        using SoundOnMediumVideoRecordingEnumChecker = Helpers::EnumCheck<SoundOnMediumVideoRecording, SoundOnMediumVideoRecording::NoSound, SoundOnMediumVideoRecording::Sound, SoundOnMediumVideoRecording::SoundSeparateFromMedium, SoundOnMediumVideoRecording::Unknown, SoundOnMediumVideoRecording::NoAttemptToCode>;
        using MediumForSoundVideoRecordingEnumChecker = Helpers::EnumCheck<MediumForSoundVideoRecording, MediumForSoundVideoRecording::NoSound, MediumForSoundVideoRecording::OpticalSoundTrackOnMotionPictureFilm, MediumForSoundVideoRecording::MagneticSoundTrackOnMotionPictureFilm, MediumForSoundVideoRecording::MagneticAudioTapeCartidge, MediumForSoundVideoRecording::SoundDisc, MediumForSoundVideoRecording::MagneticAudioTapeReel, MediumForSoundVideoRecording::MagneticAudioTapeCartidge, MediumForSoundVideoRecording::OpticalAndMagneticSoundTrackOnMotionPictureFilm, MediumForSoundVideoRecording::Videotape, MediumForSoundVideoRecording::Videodisc, MediumForSoundVideoRecording::Unknown, MediumForSoundVideoRecording::Other, MediumForSoundVideoRecording::NoAttemptToCode>;
        using DimensionVideoRecordingEnumChecker = Helpers::EnumCheck<DimensionVideoRecording, DimensionVideoRecording::EightMM, DimensionVideoRecording::OneQuarterInch, DimensionVideoRecording::OneHalfInch, DimensionVideoRecording::OneInch, DimensionVideoRecording::TwoInch, DimensionVideoRecording::ThreeQuarterInch, DimensionVideoRecording::Unknown, DimensionVideoRecording::Other, DimensionVideoRecording::NoAttemptToCode>;
        using ConfigurationOfPlaybackChannelsVideoRecordingEnumChecker = Helpers::EnumCheck<ConfigurationOfPlaybackChannelsVideoRecording, ConfigurationOfPlaybackChannelsVideoRecording::Mixed, ConfigurationOfPlaybackChannelsVideoRecording::Monaural, ConfigurationOfPlaybackChannelsVideoRecording::NotApplicable, ConfigurationOfPlaybackChannelsVideoRecording::Quadraphonic, ConfigurationOfPlaybackChannelsVideoRecording::Stereophonic, ConfigurationOfPlaybackChannelsVideoRecording::Unknown, ConfigurationOfPlaybackChannelsVideoRecording::Other, ConfigurationOfPlaybackChannelsVideoRecording::NoAttemptToCode>;

        using SpecificMaterialDesignationUnspecifiedEnumChecker = Helpers::EnumCheck<SpecificMaterialDesignationUnspecified, SpecificMaterialDesignationUnspecified::MultiplePhysicalForms, SpecificMaterialDesignationUnspecified::Unspecified, SpecificMaterialDesignationUnspecified::Other, SpecificMaterialDesignationUnspecified::NoAttemptToCode>;
    };

} // MARC
// LibManager

#endif //LIBMANAGERSERVER_PHYSICALDESCRIPTIONENUMHELPERS_H
