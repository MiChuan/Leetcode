class Solution {
public:
    string replaceSpaces(string S, int length) {
        string str;
        for(auto ch : S){
            if(ch==' ') str+="%20";
            else str+=ch;
            if(--length == 0) break;
        }
        return str;
    }
};