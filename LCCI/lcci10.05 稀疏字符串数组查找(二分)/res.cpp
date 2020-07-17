class Solution {
public:
    int finds(vector<string>& words, string& s,int left,int right){
        int mid = (left+right)/2;
        if(left > right) return 0;
        if(words[mid] == s) return mid;
        if(words[mid] == "") return finds(words,s,left,mid-1)|finds(words,s,mid+1,right);
        else if(words[mid] > s) return finds(words,s,left,mid-1);
        return finds(words,s,mid+1,right);
    }
    int findString(vector<string>& words, string s) {
        int res = finds(words,s,0,words.size()-1);
        return res? res:(words[0] == s? 0:-1);
    }
};