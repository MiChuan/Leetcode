class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> allWords(words.begin(), words.end());
        string ans;
        for(auto word:words){
            auto tmpCollects = allWords;
            tmpCollects.erase(word);
            if(isCombinated(word,tmpCollects)){
                if (word.size() > ans.size())ans = word;
                if (word.size() == ans.size())ans = min(ans, word);
            }
        }
        return ans;
    }
private:
    bool isCombinated(string s,unordered_set<string>& words){
        if (s.size() == 0)return true;
        for(int i=1;i<=s.size();i++){
            if (words.count(s.substr(0, i)) && isCombinated(s.substr(i), words))return true;
        }
        return false;
    }
};