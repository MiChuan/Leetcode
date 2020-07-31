- n = 1 时，直接把盘子从 A 移到 C
- n > 1 时
  - 先把上面 n - 1 个盘子从 A 移到 B（子问题，递归）
  - 再将最大的盘子从 A 移到 C
  - 再将 B 上 n - 1 个盘子从 B 移到 C（子问题，递归）

[链接](https://leetcode-cn.com/problems/hanota-lcci/solution/tu-jie-yi-nuo-ta-de-gu-shi-ju-shuo-dang-64ge-pan-z/)
