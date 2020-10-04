class Solution {
public:
    vector<double> twoSum(int n) {
        vector<double> pre = {1.0/6, 1.0/6, 1.0/6, 1.0/6, 1.0/6, 1.0/6};
        for(int i=2; i<=n; ++i){
            vector<double> tmp(5*i+1, 0);
            for(int j=0; j<pre.size(); ++j)
                for(int x=0; x<6; ++x)
                    tmp[j+x] += pre[j]/6; //二项式定理
            pre = tmp;
        }
        return pre;
    }
};