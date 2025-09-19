N = int(input())
s=[]
for i in range (N):
    s.append(int(input()))
s.sort()
for i in range(N):
    print(s[i])