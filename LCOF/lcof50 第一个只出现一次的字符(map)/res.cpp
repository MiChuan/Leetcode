class Solution {
public:
    char firstUniqChar(string s) {
        if(s == "") return ' ';
        map<char,int> charMap;
        for(int i = 0; i < s.size(); ++i){
            char c = s[i];
            if(charMap.count(c) > 0){
                ++charMap[c];
            }
            else{
                charMap[c] = 1;
            }
        }
        for(int i = 0; i < s.size(); ++i){
            char c = s[i];
            if(charMap[c] == 1) return c;
        }
        return ' ';
    }
};