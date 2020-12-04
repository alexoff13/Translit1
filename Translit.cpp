#include <iostream>
#include <string>
#include <map>
#include <Windows.h>
using namespace std;

std::string getTranslittedText(string text) {
    map <char, string> book = {
    {'а', "a"},
    {'б', "b"},
    {'в', "v"},
    {'г', "g"},
    {'д', "d"},
    {'е', "e"},
    {'ё', "yo"},
    {'ж', "zh"},
    {'з', "z"},
    {'и', "i"},
    {'й', "j"},
    {'к', "k"},
    {'л', "l"},
    {'м', "m"},
    {'н', "n"},
    {'о', "o"},
    {'п', "p"},
    {'р', "r"},
    {'с', "s"},
    {'т', "t"},
    {'у', "u"},
    {'ф', "f"},
    {'х', "h"},
    {'ц', "ts"},
    {'ч', "ch"},
    {'ш', "sh"},
    {'щ', "sc"},
    {'ъ', "'"},
    {'ы', "i"},
    {'ь', "'"},
    {'э', "e"},
    {'ю', "yu"},
    {'я', "ya"},
    {'А', "A"},
    {'Б', "B"},
    {'В', "V"},
    {'Г', "G"},
    {'Д', "D"},
    {'Е', "E"},
    {'Ё', "Yo"},
    {'Ж', "Zh"},
    {'З', "Z"},
    {'И', "I"},
    {'Й', "J"},
    {'К', "K"},
    {'Л', "L"},
    {'М', "M"},
    {'Н', "N"},
    {'О', "O"},
    {'П', "P"},
    {'Р', "R"},
    {'С', "S"},
    {'Т', "T"},
    {'У', "U"},
    {'Ф', "F"},
    {'Х', "H"},
    {'Ц', "Ts"},
    {'Ч', "Ch"},
    {'Ш', "Sh"},
    {'Щ', "Sc"},
    {'Ъ', "'"},
    {'Ы', "I"},
    {'Ь', "'"},
    {'Э', "E"},
    {'Ю', "Yu"},
    {'Я', "Ya"},
    {' ', " "},
    };
    map <char, string> ::iterator it;
    string res;
    for (char ch : text) {
        it = book.find(ch);
        if (it != book.end())
            res+= it->second;
        else res+=ch;
    }
    return res;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Enter text: ";
    string text;
    getline(cin,text);
    cout<<getTranslittedText(text);
}