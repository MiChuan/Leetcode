class Solution {
public:
    vector<int> tmp;
    int merge(vector<int>& nums,int l,int r){
        if(l>=r) return 0;
        int mid = (l+r)>>1;
        int res = merge(nums,l,mid)+merge(nums,mid+1,r);
        for(int i = l;i<=r;i++) tmp[i]=nums[i];
        for(int k = l,i =l,j=mid+1;k<=r;k++)
            if( i > mid) nums[k]=tmp[j++];
            else if( j > r) nums[k]=tmp[i++];
            else if(tmp[i]>tmp[j]) {
                //nums[i]>nums[j]时，res+=mid-i+1;
                //其余与归并排序一样
                nums[k]=tmp[j++];
                res += mid-i+1;
            }
            else nums[k]=tmp[i++];
        return res;
    }
    int reversePairs(vector<int>& nums) {
        tmp = vector<int> (nums.begin(),nums.end());
        return merge(nums,0,nums.size()-1);
    }
};