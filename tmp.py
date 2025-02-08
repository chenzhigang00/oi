# 质因数分解：给定一个正整数 n，求 n 的质因数个数 https://www.acwing.com/problem/content/description/4661/
# 思路：算术基本定理，任何一个大于 1 的自然数 n，如果 n 不是质数，那么 n 可以唯一分解成有限个质数的乘积

n, i, ans = int(input()), 2, 0 # n 枚举的质数 答案
while i ** 2 <= n: # 约数一定 <= √n
    if n % i == 0: # 发现一个约数
        ans += 1 # 更新答案
        while n % i == 0: # 把该质因数分解出来
            n //= i
    i += 1
print(ans if n == 1 else ans + 1) # 循环结束后的值不为 1 的话，说明这个值也是 n 的质因数