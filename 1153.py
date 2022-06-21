N = int(input())

'''
def prime(num):
    list = []
    for i in range(N):
        result = True
        if(i < 2):
            result = False
        for j in range(2,i):
            if (i%j == 0):
                result = False
        if result:
            list.append(i)
    return list
'''
def prime(num):
    list = [False,False] + [True]*(N-1)

    for i in range(2, N+1):
        if list[i]:
            for j in range(2*i, N+1, i):
                list[j] = False
    return list

prime_list = prime(N)

odd = True

if N < 8:
    print(-1)
    exit()
if N % 2 == 0:
    N -= 4
else:
    N -= 5
    odd = False

for i in range(2, N):
    if prime_list[i] and prime_list[N - i] and odd == True:
        print('2 2', i, N - i)
        exit()
    if prime_list[i] and prime_list[N - i]  and odd == False:
        print('2 3', i, N - i)
        exit()

print(-1)
