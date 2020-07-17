class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int n[128] = {0};
        if(s1.empty() && s2.empty()) return true;
        if(s1.size() == s2.size()){
            for(int i = 0; i < s1.size(); ++i){
                ++n[s1[i]];
                --n[s2[i]];
            }
            for(int i = 0; i < 128; ++i){
                if(n[i] != 0) return false;
            }
            return true;
        }
        return false;
    }
};