class Solution {
public:
    int cuttingRope(int n) {
        //余数(剩余长)、除数(等段长)、商(等段数)、积(长度积)
        int rem = 0,div = 0,con = 0,max = 0;
        for(div = 1; div < 4 && div < n; ++div){
            rem = n % div;
            con = n / div;
            if(rem != 0 && div != 1){
                int tmp;
                if(con == rem || rem == 2) tmp = pow(div,con)*rem;//余数与段数相等，余数为2
                else tmp = pow(div,con-rem)*pow(div+1,rem);
                if(max < tmp) max = tmp;
            }
            else if(div == 1){//段长为1
                if(max < 1) max = 1;
            }
            else{//余数为0
                int tmp = pow(div,con);
                if(max < tmp) max = tmp;
            }
        }
        return max;
    }
};