class Solution {
public:
    int exchangeBits(int num) {
        int even = (num & 0xaaaaaaaa) >> 1;
        int odd = (num & 0x55555555) << 1;
        return even | odd;
    }
};