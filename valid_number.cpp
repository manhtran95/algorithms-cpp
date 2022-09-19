#include <bits/stdc++.h>

using std::string;
using std::vector;
using std::cout;
using std::stringstream;
using std::getline;
using std::regex;
using std::count_if;

string toLowercase(string s){
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
        return std::tolower(c);
    });
    return s;
}

bool isInteger(string s){
    if (s[0] == '+' || s[0] == '-'){
        s.erase(s.begin(), s.begin()+1);
    }
    string rstr(R"(^[0-9]+$)");
    regex r(rstr);
    return regex_match(s, r);
}

bool isDecimal(string s){
    if (s[0] == '+' || s[0] == '-'){
        s.erase(s.begin(), s.begin()+1);
    }
    int numDot = count_if(s.begin(), s.end(), [](char c){
        return c == '.';
    });
    stringstream ss(s);
    string segment;
    vector<string> segments;
    while (getline(ss, segment, '.')){
        if (segment != ""){
            segments.push_back(segment);
        }
    }
    if (numDot != 1){
        return false;
    }
    int count = 0;
    for (auto segment:segments){
        // cout << segment << " from " << s << "\n";
        regex r("^[0-9]+$");
        if (!regex_match(segment, r)){
            return false;
        }
        count++;
    }
    if (count == 0){
        return false;
    }
    return true;
}

bool isDecimalOrInteger(string s){
    return isDecimal(s) || isInteger(s);
}


bool isNumber(string s) {
    // convert s to lowercase
    s = toLowercase(s);
    // split by 'e'
    stringstream ss(s);
    string segment;
    vector<string> segments;
    int numE = count_if(s.begin(), s.end(), [](char c){
        return c == 'e';
    });
    while (getline(ss, segment, 'e')){
        segments.push_back(segment);
    }
    if (numE >= 2 || numE == 1 && segments.size()==1){
        return false;
    }
    if (numE == 0){
        // cout << "simple: " << s << "\n";
        return isDecimalOrInteger(s);
    } else {
        // cout << "not simple: " << s << "\n";
        return isDecimalOrInteger(segments[0]) && isInteger(segments[1]);
    }
}

int main(){
    vector<string>tests{"34e5", "-.9", "0089", "-0.1", "3e+7", "+3.14", "53.5e93", "abc", "1a", "99e2.5", "--6", ".", "00565"};
    for (auto t:tests){
        if (isNumber(t)){
            cout << "match!\n";
        } else {
            cout << "unmatched!\n";
        }
    }
}