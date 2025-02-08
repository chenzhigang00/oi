t = int(input())
for _ in range(t):
    mystr = input()
    ans = 0
    for i in range(len(mystr)):
        if mystr[i] == '1':
            ans += 1
    print(ans) 