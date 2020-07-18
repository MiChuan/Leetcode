class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        int n = 0;
        if(s1.size() == s2.size()){
            for(int i = 0; i < s1.size(); ++i){
                n = n + s1[i] - s2[i];
            }
            if(n == 0) return true;
        }
        return false;
    }
};