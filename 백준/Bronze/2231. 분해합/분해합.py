def solve(N):
    for i in range(1,1000001):
        t=i
        sum=t
        while t>0:
            sum=sum+t%10
            t=t//10
        if sum==N:
            return i
    return 0
            
N=int(input())
M=solve(N)
print(M)