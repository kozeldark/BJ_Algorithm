word = input()
pw = input()

cnt = -1
ascii_values = []
list = []
for character in word:
    ascii_values.append(ord(character))
    list.append(ord(character))
    list.append(cnt)
    cnt = cnt - 1

cnt = cnt + 1


g = 1
ans = 0
for i in reversed(range(len(pw))):
    ans = (ans + g * abs(list[(list.index(ord(pw[i])) + 1)])) % 900528
    g = g * abs(cnt) % 900528

print(ans)