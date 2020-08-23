class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        set<int>s;
        int sum1=0,sum2=0;
        for(int i=0;i<array1.size();i++)
            sum1+=array1[i];
        for(int i=0;i<array2.size();i++){
            sum2+=array2[i];
            s.insert(array2[i]);     
        }
        if(abs(sum2-sum1)%2==1)     //abs取绝对值
           return {};                      //奇数直接返回空数组
        int n=(sum2-sum1)/2;                //体会一下这里n如果是负数会怎样
        for(int i=0;i<array1.size();i++){
            if(s.find(array1[i]+n)!=s.end())      //找到了就返回这俩数就行了
                return {array1[i],array1[i]+n}; //这里用array[i]+n代替array2里需要交换的数，秒！
        }
        return {};      //没找到返回空数组
    }  
};