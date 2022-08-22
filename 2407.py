import math

n, m = map(int, input().split())
ans = 1
"""
for i in range(n, n - m, -1):
    ans *= (i / (- n + m + i))
print(math.trunc(ans))
"""
print(math.factorial(n) // (math.factorial(m) * math.factorial(n - m)))