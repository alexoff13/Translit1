#include "pch.h"
#include "../Translit/Translit.cpp"

using namespace std;

TEST(getTranslittedText, noChangesExpected) {
    string text = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890 .!??*%;�@^:()-+=";
    char* expected = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890 .!??*%;�@^:()-+=";
    string result = getTranslittedText(text);
    char* res=  new char[result.length() + 1];
    strcpy(res, result.c_str());
    ASSERT_STREQ(expected, res);
    delete[] res;
}


TEST(getTranslittedText, lowerLettersTransliterationExpected) {
    string text= "� � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �";
    char* expected = "a b v g d e yo zh z i j k l m n o p r s t u f h ts ch sh sc i e yu ya";
    string result = getTranslittedText(text);
    char* res = new char[result.length() + 1];
    strcpy(res, result.c_str());
    ASSERT_STREQ(expected, res);
    delete[] res;
}


TEST(getTranslittedText, higherLettersTransliterationExpected) {
    string text = "� � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �";
    char* expected = "A B V G D E Yo Zh Z I J K L M N O P R S T U F H Ts Ch Sh Sc I E Yu Ya";
    string result = getTranslittedText(text);
    char* res = new char[result.length() + 1];
    strcpy(res, result.c_str());
    ASSERT_STREQ(expected, res);
    delete[] res;
}

TEST(getTranslittedText, correctTransliterationExpected) {
    string text = "����� ��� ���� ������ ����������� ����� �� ����� ���!";
    char* expected = "Sesh eschyo etih myagkih frantsuzskih bulok da vipej chayu!";
    string result = getTranslittedText(text);
    char* res = new char[result.length() + 1];
    strcpy(res, result.c_str());
    ASSERT_STREQ(expected, res);
    delete[] res;
}