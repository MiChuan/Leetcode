class Solution {
public:
    bool isUnique(string astr) {
        set<char> res;
        for(char ch : astr){
            if(res.count(ch) > 0) return false;
            else res.insert(ch);
        }
        return true;
    }
};