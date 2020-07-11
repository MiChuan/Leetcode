1.每次取最后两位数,rem = num % 100
2.若rem > 25,则无法表示,即rem的个位和十位无法合一起，则用translateNum(num/10),表示前进一位
3.若在00 <= rem <= 09,则无法表示，即rem的个位和十位无法合一起，所以用translateNum(num/10)
如num = 506,其只有一种表示为fag,不可表示为fg，所以0是无法和6组合一起成为06
4.若在10 <= rem <= 25,则可以分出两种表示方法,所以用translateNum(num/10) + translateNum(num/100)递归来计算数量
5.所以总结以上就是：
if (num < 10),则加1
if (num%100 < 10 || num%100 > 25) translateNum(num/10);
if (10 <= num % 100 <= 25) translateNum(num/10) + translateNum(num/100);
链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/solution/cjian-ji-dai-ma-shuang-bai-by-orangeman/
