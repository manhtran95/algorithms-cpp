#include <bits/stdc++.h>
using std::string;
using std::cout;
using std::vector;

const int N = 50;
const char STAR = '*';
const char DOT = '.';
enum PatternType {PTStar, PTChar};
class Token {
    PatternType ptype;
    char c;

    public:
        Token(){};
        Token(PatternType ptype1, char c1) {
            ptype = ptype1;
            c = c1;
        };
        PatternType getPatternType(){
            return ptype;
        }
        char getChar(){
            return c;
        }
        string getStr(){
            string typeStr = (ptype == PTStar) ? "Star" : "Char"; 
            return string(1,c) + " - " + typeStr;
        };
};

class Solution {
public:    
    vector<Token> makePatternList(string s) {
        int L = s.size();
        vector<Token> tokens;
        for (int i=0; i<L; i++){
            if (i<L-1 && s[i+1] == STAR) {
                Token token{PTStar, s[i]};
                tokens.push_back(token);
                i++;
            } else {
                Token token{PTChar, s[i]};
                tokens.push_back(token);
            }
        }
        return tokens;
    };

    bool compare(char c1, char c2){
        if (c1 == DOT) {
            return true;
        } else {
            return c1 == c2;
        }
    }
    
    bool isMatch(string s, string p) {
        int SL = s.size();
        vector<Token> pList = makePatternList(p);
        int PL = pList.size();
        int arr[PL+1][SL+1] = {};
        for (int i=0; i<PL+1; i++){
            for (int j=0; j<SL+1; j++) {
                arr[i][j] = 0;
            }
        }        
        arr[0][0] = 1;
        int k = 1;
        while (k < PL+1 && pList[k-1].getPatternType() == PTStar) {
            arr[k][0] = 1;
            k++;
        }
        for (int i=1; i<PL+1; i++){
            for (int j=1; j<SL+1; j++) {
                char pChar = pList[i-1].getChar();
                char sChar = s[j-1];
                switch (pList[i-1].getPatternType()){
                    case PTStar:
                        if (compare(pChar, sChar)){
                            arr[i][j] = arr[i][j-1]  || arr[i-1][j-1] || arr[i-1][j];
                        } else {
                            arr[i][j] = arr[i-1][j];
                        }
                        break;
                    case PTChar:
                        if (compare(pChar, sChar) && arr[i-1][j-1] == 1){
                            arr[i][j] = 1;
                        }
                        break;
                }
            }
        }

        for (int i=0; i<PL+1; i++){
            for (int j=0; j<SL+1; j++) {        
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        return arr[PL][SL];
    }
};

int main(){
    Solution sol;
    bool res = sol.isMatch("aasdfasdfasdfasdfas", "aasdf.*asdf.*asdf.*asdf.*s");
    
    if (res) {
        cout << "Matched!!\n";
    } else {
        cout << "NOT matched!\n";
    }

    // vector<Token> v = sol.makePatternList("ab*c*d.*");
    // for (auto t : v){
    //     cout << t.getStr() << "\n";
    // }
}

