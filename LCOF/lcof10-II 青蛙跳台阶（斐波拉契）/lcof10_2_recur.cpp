class Solution {
public:
    int numWays(int n) {
        int mod = 1000000007;
        int out = fb(n);
        return out;
    }
    int fb(int n){
        if(n == 0 || n == 1) return 1;
        return (numWays(n-1)+numWays(n-2)) % mod;
    }
  };