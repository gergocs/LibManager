//
// Created by csger on 2024. 03. 25..
//

#ifndef LIBMANAGERSERVER_CONSTANTS_H
#define LIBMANAGERSERVER_CONSTANTS_H

#include "frozen/string.h"

namespace LibManager {
    namespace MARC {

        class Constants {
        public:
            static const constexpr std::array<frozen::string, 516> validLanguages{
                    "aar",
                    "abk",
                    "ace",
                    "ach",
                    "ada",
                    "ady",
                    "afa",
                    "afh",
                    "afr",
                    "ain",
                    "-ajm",
                    "aka",
                    "akk",
                    "alb",
                    "ale",
                    "alg",
                    "alt",
                    "amh",
                    "ang",
                    "anp",
                    "apa",
                    "ara",
                    "arc",
                    "arg",
                    "arm",
                    "arn",
                    "arp",
                    "art",
                    "arw",
                    "asm",
                    "ast",
                    "ath",
                    "aus",
                    "ava",
                    "ave",
                    "awa",
                    "aym",
                    "aze",
                    "bad",
                    "bai",
                    "bak",
                    "bal",
                    "bam",
                    "ban",
                    "baq",
                    "bas",
                    "bat",
                    "bej",
                    "bel",
                    "bem",
                    "ben",
                    "ber",
                    "bho",
                    "bih",
                    "bik",
                    "bin",
                    "bis",
                    "bla",
                    "bnt",
                    "bos",
                    "bra",
                    "bre",
                    "btk",
                    "bua",
                    "bug",
                    "bul",
                    "bur",
                    "byn",
                    "cad",
                    "cai",
                    "-cam",
                    "car",
                    "cat",
                    "cau",
                    "ceb",
                    "cel",
                    "cha",
                    "chb",
                    "che",
                    "chg",
                    "chi",
                    "chk",
                    "chm",
                    "chn",
                    "cho",
                    "chp",
                    "chr",
                    "chu",
                    "chv",
                    "chy",
                    "cmc",
                    "cnr",
                    "cop",
                    "cor",
                    "cos",
                    "cpe",
                    "cpf",
                    "cppr)",
                    "cre",
                    "crh",
                    "crp",
                    "csb",
                    "cus",
                    "cze",
                    "dak",
                    "dan",
                    "dar",
                    "day",
                    "del",
                    "den",
                    "dgr",
                    "din",
                    "div",
                    "doi",
                    "dra",
                    "dsb",
                    "dua",
                    "dum",
                    "dut",
                    "dyu",
                    "dzo",
                    "efi",
                    "egy",
                    "eka",
                    "elx",
                    "eng",
                    "enm",
                    "epo",
                    "-esk",
                    "-esp",
                    "est",
                    "-eth",
                    "ewe",
                    "ewo",
                    "fan",
                    "fao",
                    "-far",
                    "fat",
                    "fij",
                    "fil",
                    "fin",
                    "fiu",
                    "fon",
                    "fre",
                    "-fri",
                    "frm",
                    "fro",
                    "frr",
                    "frs",
                    "fry",
                    "ful",
                    "fur",
                    "gaa",
                    "-gae",
                    "-gag",
                    "-gal",
                    "gay",
                    "gba",
                    "gem",
                    "geo",
                    "ger",
                    "gez",
                    "gil",
                    "gla",
                    "gle",
                    "glg",
                    "glv",
                    "gmh",
                    "goh",
                    "gon",
                    "gor",
                    "got",
                    "grb",
                    "grc",
                    "gre",
                    "grn",
                    "gsw",
                    "-gua",
                    "guj",
                    "gwi",
                    "hai",
                    "hat",
                    "hau",
                    "haw",
                    "heb",
                    "her",
                    "hil",
                    "him",
                    "hin",
                    "hit",
                    "hmn",
                    "hmo",
                    "hrv",
                    "hsb",
                    "hun",
                    "hup",
                    "iba",
                    "ibo",
                    "ice",
                    "ido",
                    "iii",
                    "ijo",
                    "iku",
                    "ile",
                    "ilo",
                    "ina",
                    "inc",
                    "ind",
                    "ine",
                    "inh",
                    "-int",
                    "ipk",
                    "ira",
                    "-iri",
                    "iro",
                    "ita",
                    "jav",
                    "jbo",
                    "jpn",
                    "jpr",
                    "jrb",
                    "kaa",
                    "kab",
                    "kac",
                    "kal",
                    "kam",
                    "kan",
                    "kar",
                    "kas",
                    "kau",
                    "kaw",
                    "kaz",
                    "kbd",
                    "kha",
                    "khi",
                    "khm",
                    "kho",
                    "kik",
                    "kin",
                    "kir",
                    "kmb",
                    "kok",
                    "kom",
                    "kon",
                    "kor",
                    "kos",
                    "kpe",
                    "krc",
                    "krl",
                    "kro",
                    "kru",
                    "kua",
                    "kum",
                    "kur",
                    "-kus",
                    "kut",
                    "lad",
                    "lah",
                    "lam",
                    "-lan",
                    "lao",
                    "-lap",
                    "lat",
                    "lav",
                    "lez",
                    "lim",
                    "lin",
                    "lit",
                    "lol",
                    "loz",
                    "ltz",
                    "lua",
                    "lub",
                    "lug",
                    "lui",
                    "lun",
                    "luo",
                    "lus",
                    "mac",
                    "mad",
                    "mag",
                    "mah",
                    "mai",
                    "mak",
                    "mal",
                    "man",
                    "mao",
                    "map",
                    "mar",
                    "mas",
                    "-max",
                    "may",
                    "mdf",
                    "mdr",
                    "men",
                    "mga",
                    "mic",
                    "min",
                    "mis",
                    "mkh",
                    "-mla",
                    "mlg",
                    "mlt",
                    "mnc",
                    "mni",
                    "mno",
                    "moh",
                    "-mol",
                    "mon",
                    "mos",
                    "mul",
                    "mun",
                    "mus",
                    "mwl",
                    "mwr",
                    "myn",
                    "myv",
                    "nah",
                    "nai",
                    "nap",
                    "nau",
                    "nav",
                    "nbl",
                    "nde",
                    "ndo",
                    "nds",
                    "nep",
                    "new",
                    "nia",
                    "nic",
                    "niu",
                    "nno",
                    "nob",
                    "nog",
                    "non",
                    "nor",
                    "nqo",
                    "nso",
                    "nub",
                    "nwc",
                    "nya",
                    "nym",
                    "nyn",
                    "nyo",
                    "nzi",
                    "oci",
                    "oji",
                    "ori",
                    "orm",
                    "osa",
                    "oss",
                    "ota",
                    "oto",
                    "paa",
                    "pag",
                    "pal",
                    "pam",
                    "pan",
                    "pap",
                    "pau",
                    "peo",
                    "per",
                    "phi",
                    "phn",
                    "pli",
                    "pol",
                    "pon",
                    "por",
                    "pra",
                    "pro",
                    "pus",
                    "que",
                    "raj",
                    "rap",
                    "rar",
                    "roa",
                    "roh",
                    "rom",
                    "rum",
                    "run",
                    "rup",
                    "rus",
                    "sad",
                    "sag",
                    "sah",
                    "sai",
                    "sal",
                    "sam",
                    "san",
                    "-sao",
                    "sas",
                    "sat",
                    "-scc",
                    "scn",
                    "sco",
                    "-scr",
                    "sel",
                    "sem",
                    "sga",
                    "sgn",
                    "shn",
                    "-sho",
                    "sid",
                    "sin",
                    "sio",
                    "sit",
                    "sla",
                    "slo",
                    "slv",
                    "sma",
                    "sme",
                    "smi",
                    "smj",
                    "smn",
                    "smo",
                    "sms",
                    "sna",
                    "snd",
                    "-snh",
                    "snk",
                    "sog",
                    "som",
                    "son",
                    "sot",
                    "spa",
                    "srd",
                    "srn",
                    "srp",
                    "srr",
                    "ssa",
                    "-sso",
                    "ssw",
                    "suk",
                    "sun",
                    "sus",
                    "sux",
                    "swa",
                    "swe",
                    "-swz",
                    "syc",
                    "syr",
                    "-tag",
                    "tah",
                    "tai",
                    "-taj",
                    "tam",
                    "-tar",
                    "tat",
                    "tel",
                    "tem",
                    "ter",
                    "tet",
                    "tgk",
                    "tgl",
                    "tha",
                    "tib",
                    "tig",
                    "tir",
                    "tiv",
                    "tkl",
                    "tlh",
                    "tli",
                    "tmh",
                    "tog",
                    "ton",
                    "tpi",
                    "-tru",
                    "tsi",
                    "tsn",
                    "tso",
                    "-tsw",
                    "tuk",
                    "tum",
                    "tup",
                    "tur",
                    "tut",
                    "tvl",
                    "twi",
                    "tyv",
                    "udm",
                    "uga",
                    "uig",
                    "ukr",
                    "umb",
                    "und",
                    "urd",
                    "uzb",
                    "vai",
                    "ven",
                    "vie",
                    "vol",
                    "vot",
                    "wak",
                    "wal",
                    "war",
                    "was",
                    "wel",
                    "wen",
                    "wln",
                    "wol",
                    "xal",
                    "xho",
                    "yao",
                    "yap",
                    "yid",
                    "yor",
                    "ypk",
                    "zap",
                    "zbl",
                    "zen",
                    "zha",
                    "znd",
                    "zul",
                    "zun",
                    "zxx",
                    "zza",
            };
        };

    } // MARC
} // LibManager

#endif //LIBMANAGERSERVER_CONSTANTS_H
