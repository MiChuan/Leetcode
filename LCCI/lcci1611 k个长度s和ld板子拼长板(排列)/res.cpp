class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;
        if(k != 0){
            if(shorter == longer) return vector <int> (1, shorter * k);
            for(int i = 0; i <= k; ++i){
                res.push_back(i * longer + (k-i) * shorter);
            }
        }
        return res;
    }
};