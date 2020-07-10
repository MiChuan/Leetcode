class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return s;
        int wordLength = 0;
        string reverseStr = "";
        for(int pos = s.size()-1; pos>=0; pos--){
            //从后向前统计单词字符，将由空格分隔的单词转移到字符串前面
            if(s[pos]==' ' && wordLength!=0){
                reverseStr += s.substr(pos+1,wordLength) + " ";
                wordLength = 0;
                continue;
            }
            if(s[pos]!=' ') wordLength++;
        }
        if(wordLength!=0) reverseStr += s.substr(0,wordLength);//最后一个单词为原字符串第一个单词
        if(reverseStr.size()>0 && reverseStr[reverseStr.size()-1] == ' ') 
            reverseStr.erase(reverseStr.size()-1,1); //除去最后一个单词后的空格
        return reverseStr;
    }
};