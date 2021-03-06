## [LCOF60 n个骰子的点数](https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/)

### 题目

把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

示例 2:

```markdown
输入: 2
输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
```

### 解析

把n个骰子的点数分解为n-1个骰子的点数加上一个骰子的点数。
根据1个骰子的点数概率数组求出2的点数概率数组，根据2的点数概率数组求出3的点数概率数组....直到求出n的点数。
那么我们要怎么根据n-1个骰子的点数概率数组求出n个骰子的点数概率数组呢？
我们假设n=2。
则我们已知1的点数概率数组为{1/6d,1/6d,1/6d,1/6d,1/6d,1/6d}
我们要求的2个骰子，可以分解为n-1个骰子和1个骰子
同时易知2个骰子的点数概率数组长度为2*5+1。

使得n-1点数概率数组和1点数概率数组元素两两相乘，并将乘积结果**加到**n点数概率数组上。
运算完成后就得到了最终的n点数概率数组。

根据动态规划的套路：
1.构造dp数组：tmp[]为n个骰子的点数概率数组，pre[]为n-1个骰子的点数概率数组，一个骰子的点数概率数组显然是6个六分之一,不需要另设数组。
2.初始化dp数组：pre[]={1/6d,1/6d,1/6d,1/6d,1/6d,1/6d}
3.构造状态转移方程:tmp[x+y]+=pre[x]*num[y];

来源：
[动态规划](https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/solution/java-dong-tai-gui-hua-by-zhi-xiong/)

### 代码

```C++
class Solution {
public:
    vector<double> twoSum(int n) {
        vector<double> pre = {1.0/6, 1.0/6, 1.0/6, 1.0/6, 1.0/6, 1.0/6};
        for(int i=2; i<=n; ++i){
            vector<double> tmp(5*i+1, 0);
            for(int j=0; j<pre.size(); ++j)
                for(int x=0; x<6; ++x) //n-1，下一个骰子有6个点，每个概率1/6
                    tmp[j+x] += pre[j]/6; //二项式定理
            pre = tmp;
        }
        return pre;
    }
};
```

