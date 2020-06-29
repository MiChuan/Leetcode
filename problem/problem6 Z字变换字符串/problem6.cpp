class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<2) return s;
        int charGap = numRows*2 - 2;
        int Gap1 = charGap;
        int Gap2 = 0;
        string zString = "";
        int flag = 1;
        for(int level=0; level<numRows; level++){
            if(level==0 || level==numRows-1){
                for(int zNum=level; zNum<s.size(); zNum+=charGap){
                    zString += s[zNum];
                }
                Gap1 -= 2;
                Gap2 = charGap - Gap1;
            }else{
                int zNum = level;
                flag = 1;
                while(zNum<s.size()){
                    zString += s[zNum];
                    if(flag==1){
                        zNum+=Gap1;
                        flag = 2;
                    }
                    else{
                        zNum+=Gap2;
                        flag = 1;
                    }
                }
                Gap1 -= 2;
                Gap2 = charGap - Gap1;
            }
        }
        return zString;
    }
};