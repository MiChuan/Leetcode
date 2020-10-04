## [LCOF58 - I 翻转单词顺序](https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/)

### 题目

输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

### 解析

从后向前统计单词

### 代码

```C++
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
```

