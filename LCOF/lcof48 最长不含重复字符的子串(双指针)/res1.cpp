class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        if(s.size() == 0) return 0;
        unordered_set<char> chars;
        int right = 0;
        for(int left = 0; left < s.size(); left ++){
            while(right < s.size() && !chars.count(s[right])){//当前子串增长
                chars.insert(s[right]);
                right ++;
            }
            maxLen = maxLen > right - left ? maxLen : right - left;//比较当前子串与当前最长子串大小
            if(right == s.size()) break;//右指针遍历到串尾
            chars.erase(s[left]);//下一个字符开头的子串
        }
        return maxLen;
    }
};