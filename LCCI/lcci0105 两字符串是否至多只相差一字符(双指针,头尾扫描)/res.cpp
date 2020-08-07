class Solution {
public:
    bool oneEditAway(string first, string second) {
        if(first==second) return true;
        int len = first.size() - second.size();
        if(len > 1 || len < -1) return false;
        int i,j,k;
        for(i = 0; i<first.size() && i<second.size() && first[i]==second[i]; ++i); // i从左至右扫描
        for(j=first.size()-1,k=second.size()-1; j>=0 && k>=0 && first[j]==second[k]; --j, --k);// j、k从右至左扫描
        return j-i<1 && k-i<1;
    }
};