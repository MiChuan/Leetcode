class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        size_t len = array.size();
        vector<int> memo((len << 1) + 1, -2);
        memo[len] = -1;
        size_t begin = 0, end = 0;
        int res = 0, count = 0;
        for (size_t i = 0; i < len; ++i) {
            count += (array[i][0] - 'A' < 0) ? -1 : 1;
            if (memo[count + len] <= -2) memo[count + len] = i;
            else if (i - memo[count + len] > res) {
                begin = memo[count + len] + 1;
                end = i + 1;
                res = i - memo[count + len];
            }
        }
        return vector<string>(array.begin() + begin, array.begin() + end);
    }
};