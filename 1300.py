N = int(input())
K = int(input())

'''
list = []

for i in range(1, N + 1):
    line = []
    for j in range(1, N + 1):
        line.append(i*j)
    list.append(line)

ans = sum(list, [])
ans.sort()

print(ans[K])
'''

start = 1
end = K

while start <= end:
    mid = (start+end) // 2
    cnt = 0
    for i in range(1, N+1):
        cnt += min(mid//i, N)
    if cnt >= K:
        ans = mid
        end = mid - 1
    else:
        start = mid + 1
print(ans)