#include "pch.h"
#include "../Translit/Translit.cpp"

using namespace std;

TEST(getTranslittedText, noChangesExpected) {
    string text = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890 .!??*%;№@^:()-+=";
    char* expected = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890 .!??*%;№@^:()-+=";
    string result = getTranslittedText(text);
    char* res=  new char[result.length() + 1];
    strcpy(res, result.c_str());
    ASSERT_STREQ(expected, res);
    delete[] res;
}


TEST(getTranslittedText, lowerLettersTransliterationExpected) {
    string text= "а б в г д е ё ж з и й к л м н о п р с т у ф х ц ч ш щ ы э ю я";
    char* expected = "a b v g d e yo zh z i j k l m n o p r s t u f h ts ch sh sc i e yu ya";
    string result = getTranslittedText(text);
    char* res = new char[result.length() + 1];
    strcpy(res, result.c_str());
    ASSERT_STREQ(expected, res);
    delete[] res;
}


TEST(getTranslittedText, higherLettersTransliterationExpected) {
    string text = "А Б В Г Д Е Ё Ж З И Й К Л М Н О П Р С Т У Ф Х Ц Ч Ш Щ Ы Э Ю Я";
    char* expected = "A B V G D E Yo Zh Z I J K L M N O P R S T U F H Ts Ch Sh Sc I E Yu Ya";
    string result = getTranslittedText(text);
    char* res = new char[result.length() + 1];
    strcpy(res, result.c_str());
    ASSERT_STREQ(expected, res);
    delete[] res;
}

TEST(getTranslittedText, correctTransliterationExpected) {
    string text = "Съешь ещё этих мягких французских булок да выпей чаю!";
    char* expected = "Sesh eschyo etih myagkih frantsuzskih bulok da vipej chayu!";
    string result = getTranslittedText(text);
    char* res = new char[result.length() + 1];
    strcpy(res, result.c_str());
    ASSERT_STREQ(expected, res);
    delete[] res;
}