class Solution {
private:
    int abs(int a){
        return a > 0?a:(0 - a);
    }
    int min(int a, int b){
        return a > b?b:a;
    }
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        // 双指针用2倍数组长度，这样遍历时第一次更新指针的位置无论是在哪儿，都能保证abs(w1_ptr - w2_ptr)大于数组长度。
        int w1_ptr = 2 * words.size(), w2_ptr = 2 * words.size();
        int distance = words.size();
        for(int i = 0; i < words.size(); i++){
            if(words[i] == word1){
                w1_ptr = i;
                distance = min(distance, abs(w1_ptr - w2_ptr));
            }
            else if(words[i] == word2){
                w2_ptr = i;
                distance = min(distance, abs(w2_ptr - w1_ptr));
            }
        }
        return distance;
    }
};