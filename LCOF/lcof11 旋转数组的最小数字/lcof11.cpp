class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size()<=1) return numbers[0];
        int index1=0,index2=numbers.size()-1;
        int indexM=0;
        while(numbers[index1]>=numbers[index2]){
            if(index2-index1==1){
                indexM=index2;
                break;
            }
            indexM=(index1+index2)/2;
            if(numbers[index1]==numbers[index2] && numbers[indexM]==numbers[index1]){
                int min = numbers[index1];
                for(int i=index1+1; i<index2;++i){
                    if(min>numbers[i]) min = numbers[i];
                }
                return min;
            }
            if(numbers[indexM]>=numbers[index1]) index1=indexM;
            if(numbers[indexM]<=numbers[index2]) index2=indexM;
        }
        return numbers[indexM];
    }
};