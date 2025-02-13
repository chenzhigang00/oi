def fun4():
    x1,x2,x3=a+b,c+d,e+f
    for i in [a,b]:
        for j in [c,d]:
            for k in [e,f]:
                if i == j == k:   # 三个矩阵有相同的边
                    return True
                if i == j and x1+x2-i-j == k:
                    return True
                if i == k and x1+x3-i-k == j:
                    return True
                if j == k and x2+x3-j-k == i:
                    return True
    return False

def fun6():
    for i in [a,b]:
        for j in [c,d]:
            for k in [e,f]:
                if i ==j or i == k or j == k:
                    return True
                if i + j == k or i + k == j or j + k == i:
                    return True
    return False

def solve():
    if fun4():
        print(4)
        return
    if fun6():
        print(6)
        return
    print(8)
    return

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        a,b,c,d,e,f=map(int,input().split())
        solve()

        