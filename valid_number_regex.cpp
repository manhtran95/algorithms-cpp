#include <bits/stdc++.h>
#include <regex>
#include <string>
using std::cout;
using std::string;
using std::regex;

bool isNumber(string s) {
    regex r("^((\\+|\\-)?((\\d+\\.|\\d+\\.\\d+|\\.\\d+)|\\d+)((e|E)(\\+|\\-)?\\d+)?)$");
    if (std::regex_match(s, r)) 
        cout << "matched\n";
    else 
        cout << "unmatched\n";
    return true;
    return std::regex_match(s, r);
}

int main(){
    isNumber("34e5");
    isNumber("-.9");
    isNumber("0089");
    isNumber("-0.1");
    isNumber("3e+7");
    isNumber("+3.14");
    isNumber("53.5e93");
    isNumber("abc");
    isNumber("1a");
    isNumber("99e2.5");
    isNumber("--6");
    isNumber(".");
    isNumber("00565");
}