class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, -1);//ANSCII码表大小
        int res = 0, left = -1;
        for(int i = 0; i < s.size(); ++i) {
            left = left > m[s[i]] ? left : m[s[i]];//出现重复字符，跳到该字符重新统计
            m[s[i]] = i;
            res = res > i - left ? res : i - left;
        }
        return res;
        
    }
};