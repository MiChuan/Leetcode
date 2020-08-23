class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        vector<int> year(101,0);
        int i,j,k;
        for(i = 0, j = 0; i < birth.size(); ++i, ++j){
            for(k = birth[i]-1900; k <= death[j]-1900; ++k){
                ++year[k];
            }
        }
        for(i = 0, j = year[0], k = 0; i < year.size(); ++i){
            if(year[i] > j){
                j = year[i];
                k = i;
            }
        }
        return k+1900;
    }
};