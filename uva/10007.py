cat = [0]*302
cat[0]=1

for n in range(1, 302,1):
    for i in range(0,n,1):
        cat[n] += (cat[i]*cat[n-1-i])
while True:
    
        s=int(input())
        if s==0:
            break
        x=cat[s]
        for i in range(1,s+1,1):
            x*=i
        print(x)
