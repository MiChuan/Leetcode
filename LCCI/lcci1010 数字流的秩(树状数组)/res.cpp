class StreamRank {
    int a[50010];
public:
    StreamRank() {
        for (int i=1;i<=50001;++i) a[i]=0;
    }
    
    void track(int x) {//i&-i保留最低位1
        ++x;
        for (int i=x;i<=50001;i+=i&(-i)) a[i]++;
    }
    
    int getRankOfNumber(int x) {
        ++x;
        int sum=0;
        for (int i=x;i;i-=i&(-i)) sum+=a[i];
        return sum;
    }
};