class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> m;//map值为结果二维数组行索引
        vector<vector<string>> ans;
        for ( int i = 0; i < strs.size(); i++ ){
            string ordered_str = strs[i];
            sort( ordered_str.begin(), ordered_str.end() );
            if ( m.count(ordered_str) ){
                ans[m[ordered_str]].push_back( strs[i] );
            } else {//当前词组不在map
                vector<string> v = { strs[i] };
                ans.push_back( v );
                m[ordered_str] = ans.size()-1;
            }
        }
        return ans;
    }
};