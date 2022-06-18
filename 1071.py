N = int(input())
arr = list(map(int, input().split()))

arr.sort(reverse=True)
tmp = arr
ans = [min(arr)]
del arr[arr.index(min(arr))]

while sum(arr) > 0:
    i = -1
    if ans[-1] + 1 == arr[-1]:
        if arr[-1] == max(arr):
            idx = len(ans) - 1
            while idx >= 0 and ans[idx] == ans[-1]:
                idx -= 1

            ans = ans[:idx + 1] + arr + ans[idx + 1:]
            break

        else:
            while ans[-1] + 1 == arr[i]:
                i -= 1

    ans.append(arr[i])
    del arr[i]

print(*ans)
