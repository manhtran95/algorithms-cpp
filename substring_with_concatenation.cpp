#include <bits/stdc++.h>
using std::cout;
using std::vector;
using std::string;
using std::unordered_map;

unordered_map<string, int> wordsMap;
int n, numWords, wordLen;

bool compare(unordered_map<string, int>& u1, unordered_map<string, int>& u2){
    for (auto it = u1.begin(); it != u1.end(); it++){
        string k = it->first;
        // cout << "u1-k: " << k << "\n";
        if (u2.find(k) == u2.end() || u2.find(k) != u2.end() && u2[k] != u1[k]){
            return false;
        }
    }
    return true;
}

void slidingWindow(string s, vector<string>& words, vector<int>& res, int left){
    unordered_map<string, int> wordsFound;
    int right = left + wordLen;
    while (right <= n) {
        while (right <= n && (right - left)/wordLen <= numWords){
            // cout << "left " << left << ", right " << right << "\n";
            string lastWord = s.substr(right-wordLen, wordLen);
            if (wordsMap.find(lastWord) == wordsMap.end()){
                left = right; right = left + wordLen;
                wordsFound.clear();
                continue;
            }
            wordsFound[lastWord] = wordsFound.find(lastWord) != wordsFound.end()? wordsFound[lastWord]+1 : 1;
            if ((right - left)/wordLen == numWords && compare(wordsFound, wordsMap)){
                res.push_back(left);
            }
            right += wordLen;
        }
        string leftSubstr = s.substr(left, wordLen);
        wordsFound[leftSubstr] -= 1;
        if (wordsFound[leftSubstr] == 0){
            wordsFound.erase(leftSubstr);
        }
        left += wordLen;
    }
}

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    n = s.size();
    numWords = words.size();
    wordLen = words[0].size();
    int left = 0;
    for (auto w:words){
        wordsMap[w] = wordsMap.find(w) != wordsMap.end()? wordsMap[w]+1 : 1;
    }
    for (left = 0; left < words[0].size(); left++){
        slidingWindow(s, words, res, left);
    }

    return res;
}

int main(){
    string s = "nananfoobarthebarfooman";
    vector<string> words{"nan"};
    vector<int> ans = findSubstring(s, words);
    for (auto i:ans){
        cout << i << ", ";
    }
    cout << "\n";
}