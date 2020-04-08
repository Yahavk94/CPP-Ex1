#include <string>
#include "PhoneticFinder.hpp"
#include "doctest.h"
using namespace phonetic;

/**
 * The following tests are used to check whether find method works properly, given
 * any text and any word.
 * @authors Yahav Karpel, Shoval Benayon and Daniel Korotine.
 */

TEST_CASE("Test replacement of v and w") {
    string text = "the words vowel and brainwave";
    CHECK(find(text, "vowel") == string("vowel"));
    CHECK(find(text, "wovel") == string("vowel"));
    CHECK(find(text, "vovel") == string("vowel"));
    CHECK(find(text, "wowel") == string("vowel"));
    CHECK(find(text, "brainwave") == string("brainwave"));
    CHECK(find(text, "brainwawe") == string("brainwave"));
    CHECK(find(text, "brainvave") == string("brainwave"));
    CHECK(find(text, "brainvawe") == string("brainwave"));
}

TEST_CASE("Test replacement of b, f and p") {
    string text = "happy birthday";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    CHECK(find(text, "haffy") == string("happy"));
    CHECK(find(text, "hapfy") == string("happy"));
    CHECK(find(text, "hafpy") == string("happy"));
    CHECK(find(text, "birthday") == string("birthday"));
    CHECK(find(text, "pirthday") == string("birthday"));
    CHECK(find(text, "firthday") == string("birthday"));
}

TEST_CASE("Test replacement of g and j") {
    string text = "joggers and joggle";
    CHECK(find(text, "joggers") == string("joggers"));
    CHECK(find(text, "gojgers") == string("joggers"));
    CHECK(find(text, "gogjers") == string("joggers"));
    CHECK(find(text, "goggers") == string("joggers"));
    CHECK(find(text, "gojjers") == string("joggers"));
    CHECK(find(text, "jogjers") == string("joggers"));
    CHECK(find(text, "jojgers") == string("joggers"));
    CHECK(find(text, "jojjers") == string("joggers"));
    CHECK(find(text, "joggle") == string("joggle"));
    CHECK(find(text, "gojgle") == string("joggle"));
    CHECK(find(text, "gogjle") == string("joggle"));
    CHECK(find(text, "goggle") == string("joggle"));
    CHECK(find(text, "jojgle") == string("joggle"));
    CHECK(find(text, "jogjle") == string("joggle"));
    CHECK(find(text, "jojjle") == string("joggle"));
}

TEST_CASE("Test replacement of c, k and q") {
    string text = "xxx cooking a cake yyy";
    CHECK(find(text, "cooking") == string("cooking"));
    CHECK(find(text, "koocing") == string("cooking"));
    CHECK(find(text, "coocing") == string("cooking"));
    CHECK(find(text, "kooking") == string("cooking"));
    CHECK(find(text, "cooqing") == string("cooking"));
    CHECK(find(text, "qoocing") == string("cooking"));
    CHECK(find(text, "qooqing") == string("cooking"));
    CHECK(find(text, "kooqing") == string("cooking"));
    CHECK(find(text, "qooking") == string("cooking"));
    CHECK(find(text, "kooking") == string("cooking"));
}

TEST_CASE("Test replacement of s and z") {
    string text = "scissors are super sharp";
    CHECK(find(text, "scissors") == string("scissors"));
    CHECK(find(text, "zcizzorz") == string("scissors"));
    CHECK(find(text, "sciszorz") == string("scissors"));
    CHECK(find(text, "scizsorz") == string("scissors"));
    CHECK(find(text, "scizzors") == string("scissors"));
    CHECK(find(text, "scizzorz") == string("scissors"));
    CHECK(find(text, "zcizsorz") == string("scissors"));
    CHECK(find(text, "zcizzors") == string("scissors"));
    CHECK(find(text, "super") == string("super"));
    CHECK(find(text, "zuper") == string("super"));
    CHECK(find(text, "sharp") == string("sharp"));
    CHECK(find(text, "zharp") == string("sharp"));
}

TEST_CASE("Test replacement of d and t") {
    string text = "xxx a thunderbolt strikes the ground yyy";
    CHECK(find(text, "thunderbolt") == string("thunderbolt"));
    CHECK(find(text, "thunterbolt") == string("thunderbolt"));
    CHECK(find(text, "thunterbold") == string("thunderbolt"));
    CHECK(find(text, "thunderbold") == string("thunderbolt"));
    CHECK(find(text, "dhunderbolt") == string("thunderbolt"));
    CHECK(find(text, "dhunterbolt") == string("thunderbolt"));
    CHECK(find(text, "dhunterbold") == string("thunderbolt"));
    CHECK(find(text, "dhunderbold") == string("thunderbolt"));
    CHECK(find(text, "strikes") == string("strikes"));
    CHECK(find(text, "sdrikes") == string("strikes"));
    CHECK(find(text, "the") == string("the"));
    CHECK(find(text, "dhe") == string("the"));
    CHECK(find(text, "ground") == string("ground"));
    CHECK(find(text, "grount") == string("ground"));
}

TEST_CASE("Test replacement of o and u") {
    string text = "xxx honolulu is capital of hawaii yyy";
    CHECK(find(text, "honululu") == string("honolulu"));
    CHECK(find(text, "hunolulu") == string("honolulu"));
    CHECK(find(text, "hunulolu") == string("honolulu"));
    CHECK(find(text, "hunululo") == string("honolulu"));
    CHECK(find(text, "honulolu") == string("honolulu"));
    CHECK(find(text, "honululo") == string("honolulu"));
    CHECK(find(text, "honololu") == string("honolulu"));
    CHECK(find(text, "honolulo") == string("honolulu"));
    CHECK(find(text, "honulolo") == string("honolulu"));
    CHECK(find(text, "hunololo") == string("honolulu"));
    CHECK(find(text, "hunululu") == string("honolulu"));
    CHECK(find(text, "honololo") == string("honolulu"));
    CHECK(find(text, "of") == string("of"));
    CHECK(find(text, "uf") == string("of"));
}

TEST_CASE("Test replacement of i and y") {
    string text = "the baby is crying today yyy";
    CHECK(find(text, "baby") == string("baby"));
    CHECK(find(text, "babi") == string("baby"));
    CHECK(find(text, "is") == string("is"));
    CHECK(find(text, "ys") == string("is"));
    CHECK(find(text, "crying") == string("crying"));
    CHECK(find(text, "criyng") == string("crying"));
    CHECK(find(text, "cryyng") == string("crying"));
    CHECK(find(text, "criing") == string("crying"));
    CHECK(find(text, "today") == string("today"));
    CHECK(find(text, "todai") == string("today"));
    CHECK(find(text, "yyy") == string("yyy"));
    CHECK(find(text, "iyy") == string("yyy"));
    CHECK(find(text, "yiy") == string("yyy"));
    CHECK(find(text, "yyi") == string("yyy"));
    CHECK(find(text, "iiy") == string("yyy"));
    CHECK(find(text, "iyi") == string("yyy"));
    CHECK(find(text, "yii") == string("yyy"));
    CHECK(find(text, "iii") == string("yyy"));
}

TEST_CASE("Test replacement of lower case and upper case") {
    string text = "Happier PEOPLE are ThE RicHER OneS";
    CHECK(find(text, "Happier") == string("Happier"));
    CHECK(find(text, "happier") == string("Happier"));
    CHECK(find(text, "HAPPIER") == string("Happier"));
    CHECK(find(text, "HapPIeR") == string("Happier"));
    CHECK(find(text, "HAPpiEr") == string("Happier"));
    CHECK(find(text, "hApPIeR") == string("Happier"));
    CHECK(find(text, "PEOPLE") == string("PEOPLE"));
    CHECK(find(text, "People") == string("PEOPLE"));
    CHECK(find(text, "PeoPLE") == string("PEOPLE"));
    CHECK(find(text, "PEopLe") == string("PEOPLE"));
    CHECK(find(text, "peOPlE") == string("PEOPLE"));
    CHECK(find(text, "are") == string("are"));
    CHECK(find(text, "Are") == string("are"));
    CHECK(find(text, "aRe") == string("are"));
    CHECK(find(text, "arE") == string("are"));
    CHECK(find(text, "ARE") == string("are"));
    CHECK(find(text, "the") == string("ThE"));
    CHECK(find(text, "THE") == string("ThE"));
    CHECK(find(text, "The") == string("ThE"));
    CHECK(find(text, "ThE") == string("ThE"));
    CHECK(find(text, "RicHER") == string("RicHER"));
    CHECK(find(text, "richer") == string("RicHER"));
    CHECK(find(text, "RICHER") == string("RicHER"));
    CHECK(find(text, "RiCheR") == string("RicHER"));
    CHECK(find(text, "ricHER") == string("RicHER"));
    CHECK(find(text, "OneS") == string("OneS"));
    CHECK(find(text, "ones") == string("OneS"));
    CHECK(find(text, "ONES") == string("OneS"));
    CHECK(find(text, "oNeS") == string("OneS"));
}

TEST_CASE("Test replacement of upper cases and spelling mistakes") {
    string text = "Dont mess with the Zohan";
    CHECK(find(text, "tunD") == string("Dont"));
    CHECK(find(text, "dunt") == string("Dont"));
    CHECK(find(text, "TOND") == string("Dont"));
    CHECK(find(text, "dOnD") == string("Dont"));
    CHECK(find(text, "mESz") == string("mess"));
    CHECK(find(text, "MeSS") == string("mess"));
    CHECK(find(text, "mEZZ") == string("mess"));
    CHECK(find(text, "MEZs") == string("mess"));
    CHECK(find(text, "viDh") == string("with"));
    CHECK(find(text, "VITH") == string("with"));
    CHECK(find(text, "wiDh") == string("with"));
    CHECK(find(text, "DhE") == string("the"));
    CHECK(find(text, "DHE") == string("the"));
    CHECK(find(text, "SoHaN") == string("Zohan"));
    CHECK(find(text, "sOHaN") == string("Zohan"));
    CHECK(find(text, "zOhan") == string("Zohan"));
}