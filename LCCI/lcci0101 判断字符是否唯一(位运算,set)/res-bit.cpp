class Solution {
public:
    bool isUnique(string astr) {
        int x = 0;
        for(char ch : astr){
            if(x & (1 << (ch - 'a'))) return false;
            else x |= (1 << (ch - 'a'));
        }
        return true;
    }
};