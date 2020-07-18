class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<128> bits;
        for (char c : s) {
            bits.flip(c);
        }
        return bits.none() || bits.count() == 1;
    }
};