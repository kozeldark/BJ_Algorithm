N = int(input())
div = 0

if N % 2 == 0 or N % 5 == 0:
    print(-1)
else:
    for i in range(1, N+1):
        div = (10*div + 1) % N
        if div == 0:
            print(i)
            break
