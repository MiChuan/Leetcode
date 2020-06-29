[题解](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/solution/mian-shi-ti-13-ji-qi-ren-de-yun-dong-fan-wei-dfs-b/)

- 机器人运动一次一步，检查当前位置后向下、向右检查
- 下标越界、下标数字和大于k、已访问位置，返回0
- 向下、向右访问下标出现十进制进位时，下标数字和减小，19、20,即（x+1）% 10=0, S_(x+1) = S_x - 8