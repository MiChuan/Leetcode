class Solution {
public:
    int waysToStep(int n) {
        if(n <= 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 4;

        long one = 1, two = 2, three = 4, i = 3;
        while(i < n)
        {
            int tmp = (one + two + three) % 1000000007;
            one = two;
            two = three;
            three = tmp;
            i++;
        }
        return three;
    }
};