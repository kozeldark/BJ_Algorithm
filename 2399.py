N = int(input())
arr = list(map(int, input().split()))
cnt = 0
for i in range(N):
    for j in range(N):
        cnt += abs(arr[i]-arr[j])
print(cnt)