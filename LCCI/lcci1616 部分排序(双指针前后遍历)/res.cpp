class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        int n = array.size();
        int maxx = INT_MIN, minn = INT_MAX;
        int l = -1, r = -1;
        for (int i = 0; i < n; ++i) {
            if (array[i] < maxx) r = i;
            else maxx = array[i];
        }
        for (int i = n-1; i >= 0; --i) {
            if (array[i] > minn) l = i;
            else minn = array[i];
        }
        return {l, r};
    }
};