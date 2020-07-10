class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> sub;
        int i = 1;//gap
        while(i*(i+1)/2 < target){//正数
            if(((target - i*(i+1)/2) % (i+1)) == 0){//整数
                int x = (target - i*(i+1)/2) / (i+1);//下界
                int y = x + i;//上界
                for(; x <= y ; ++x) sub.push_back(x);//上下界闭区间连续正整数
                res.push_back(sub);
                sub.clear();
            }
            i += 1;
        }
        std::reverse(res.begin(),res.end());//调整不同列从小到大
        return res;
    }
};