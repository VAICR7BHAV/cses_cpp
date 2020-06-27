n=int(input())
while(n>0):
    n-=1
    a,b,c=map(int,input().split())
    print(pow(a,pow(b,c),1000000007))