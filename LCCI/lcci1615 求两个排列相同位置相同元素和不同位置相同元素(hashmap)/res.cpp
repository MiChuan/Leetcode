class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        unordered_map<char, int> chars;
        for(int i = 0; i < 4; ++i) ++chars[guess[i]];//记录solution
        vector<int> res{0,0};
        for(int i = 0; i < 4; ++i){
            if(solution[i] == guess[i]) ++res[0];
            if(chars[solution[i]]) {
                ++res[1];
                --chars[solution[i]];
            }
        }
        res[1] -= res[0];
        return res;
    }
};