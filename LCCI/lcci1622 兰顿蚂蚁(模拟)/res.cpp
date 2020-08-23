class Solution {
public:
    vector<string> printKMoves(int K) {
        int a = 0, b = 0, c = 0, d = 0;
        unordered_map<int,unordered_set<int>> m;
        unordered_map<char,pair<int,int>> n1;
        n1['L'] = {-1,0};
        n1['R'] = {1,0};
        n1['U'] = {0,1};
        n1['D'] = {0,-1};
        string k = "LURD";
        int x = 0, y = 0,temp = 2;
        while(K-- > 0){
            if(m.find(x) != m.end() && m[x].find(y) != m[x].end()){
                m[x].erase(y);
                x -= n1[k[temp]].first;
                y -= n1[k[temp]].second;
                temp = (temp+3)%4;
            }
            else{
                m[x].insert(y);
                x += n1[k[temp]].first;
                y += n1[k[temp]].second;
                temp = (temp+1)%4;
            }
            a = min(a,y),b = max(b,y);
            c = min(c,x),d = max(d,x);
        }
        int l = b-a+1,h = d-c+1;
        vector<string> res(h,string(l,'_'));
        for(auto& p:m){
            for(auto& t:p.second){
                res[p.first-c][t-a] = 'X';
            }
        }
        res[x-c][y-a] = k[temp];
        return res;
    }
};