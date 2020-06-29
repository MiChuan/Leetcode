class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size()<=1) return numbers[0];
        int min=numbers[0];
        for(int i=0; i<numbers.size(); ++i) if(min>=numbers[i]) min=numbers[i];
        return min;
    }
};