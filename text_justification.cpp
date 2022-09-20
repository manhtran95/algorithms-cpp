#include <bits/stdc++.h>
using std::cout;
using std::vector;
using std::string;

string padRight(string s, int n){
    s += string(n, ' ');
    return s;
}

string justifyLine(vector<string>& words, int numSpace){
    string ans;
    int n = words.size();
    if (n == 1){
        return padRight(words[0], numSpace);
    }
    // total number of spaces
    int d = numSpace / (n-1), m = numSpace % (n-1);
    cout << "t: " << numSpace << ", d: " << d << ", m: " << m << "\n";
    for (int i=0; i<n-1; i++){
        int ns = i < m? d+1 : d;
        string s = padRight(words[i], ns);
        ans += s;
    }
    ans += words[n-1];
    return ans;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res, line;
    int n = words.size(), i = 0, lineWordsLen;
    while (i < n){
        line.clear(); lineWordsLen = 0;
        // string firstInLine = words[i++];
        // line.push_back(firstInLine); lineWordsLen += firstInLine.size();
        // int l = firstInLine.size();
        cout << "outside\n";
        cout << "i: " << i << "\n";
        int l = 0, k = 0;
        while (i < n && l + words[i].size()  <= maxWidth-k){
            cout << "inside\n";
            l += words[i].size();
            line.push_back(words[i]); lineWordsLen += words[i].size();
            i++; k++;
        }
        if (i < n){
            string lineJustified =  justifyLine(line, maxWidth-lineWordsLen);
            res.push_back(lineJustified);
        } else {
            string lineStr;
            for (int i=0; i<line.size()-1; i++){
                lineStr += line[i] + " "; lineWordsLen += 1;
            }
            lineStr += line[line.size()-1];
            lineStr = padRight(lineStr, maxWidth - lineWordsLen);
            res.push_back(lineStr);
        }
    }
    return res;
}

int main(){
    vector<string> input{"This", "is", "an", "example", "of", "text", "justification."};
    // vector<string> input{"What","must","be","acknowledgment","shall","be"};
    // vector<string> input{"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    int maxWidth = 16;
    vector<string> res = fullJustify(input, maxWidth);
    for (auto s : res){
        cout << s << "\n";
    }
}