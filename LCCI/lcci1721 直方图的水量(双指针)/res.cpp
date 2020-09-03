class Solution {
public:
    int trap(vector<int>& height){
        int left=0,right=height.size()-1;
        int leftmax=0,rightmax=0;
        int res=0;
        while(left<right){
            if(height[left]<height[right]){
                height[left]>leftmax ? leftmax=height[left] : res+=(leftmax-height[left]) ;
                left++;
            }
            else{
                height[right]>rightmax ? rightmax=height[right] : res+=(rightmax-height[right]) ;
                right--;
            }
        }
        return res;
    }
};