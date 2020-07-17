class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0]; //only one element
        return findMaxSubArray(nums,0,nums.size()-1);
    }
    int findMaxSubArray(vector<int>& sub,int low,int high){
        if (low == high) {
            return sub[low];
        }
        int mid = (low+high)/2;
        int leftsum = findMaxSubArray(sub,low,mid);
        int rightsum = findMaxSubArray(sub,mid+1,high);
        int crosssuum = findCrossMax(sub,low,mid,high);
        if(leftsum>=rightsum && leftsum>=crosssuum) return leftsum;
        else if(rightsum>=leftsum && rightsum>=crosssuum) return rightsum;
        else return crosssuum;
    }
    int findCrossMax(vector<int>& cross,int low,int mid,int high){
        if(low == high) return cross[low];
        int leftsum = INT_MIN;
        int rightsum = INT_MIN;
        int sum = 0;
        for(int i = mid;low<=i;i--){//find left half max
            sum = sum + cross[i];
            if(sum>leftsum){
                leftsum = sum;
            }
        }
        sum = 0;
        for(int j = mid+1;j<=high;j++){
            sum = sum + cross[j];
            if(sum>rightsum){
                rightsum = sum;
            }
        } 
        return leftsum+rightsum;
    }
};