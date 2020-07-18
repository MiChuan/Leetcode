class Solution {
public:
    int reverseBits(int num){
        int ans = 0;
        int cnt = 0, pre = 0;
        while(num){
            if(num & 1){
                cnt ++;//统计0右边的1
            }
            else{
                ans = max(ans, cnt + pre + 1);//0左右的1
                pre = cnt;
                cnt = 0;
            }
            num >>= 1;
        }
        ans = max(ans, cnt + pre + 1);
        return ans;
    }
};