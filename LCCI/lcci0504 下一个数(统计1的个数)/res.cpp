class Solution {
public:
    int countOne(int num){
        int carry=1;
        int countOne=0;
        for(int i=0;i<31;++i){
            if(num&carry) countOne++;
            carry<<=1;
        }
        return countOne;
    }
    vector<int> findClosedNumbers(int num) {
        int numOne=countOne(num);
        int bigger=-1,smaller=-1;
        for(int i=num+1;i<=2147483647;++i){
            if(countOne(i)==numOne){
                bigger=i;
                break;
            }
        }
        for(int i=num-1;i>=1;--i){
            if(countOne(i)==numOne){
                smaller=i;
                break;
            }
        }
        return {bigger,smaller};
    }
};