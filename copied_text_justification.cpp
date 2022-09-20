#include <bits/stdc++.h>
using std::cout;
using std::vector;
using std::string;

vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> res;
    for(int i = 0, k, l; i < words.size(); i += k) {
        for(k = l = 0; i + k < words.size() and l + words[i+k].size() <= L - k; k++) {
            l += words[i+k].size();
        }
        string tmp = words[i];
        for(int j = 0; j < k - 1; j++) {
            if(i + k >= words.size()) tmp += " ";
            else tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
            tmp += words[i+j+1];
        }
        tmp += string(L - tmp.size(), ' ');
        res.push_back(tmp);
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