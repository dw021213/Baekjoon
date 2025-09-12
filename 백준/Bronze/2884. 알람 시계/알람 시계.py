def solve(h, m):
    if m>=45:
        m=m-45
    else:
        m=(m-45)%60
        h=(h-1)%24
    return h, m

H, M = map(int, input().split())
h, m = solve(H,M)
print(h, m)