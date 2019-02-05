a=[]
a.append(0)
a.append(0)
sum=0
ls=0
for i in range(2,1011,1):
    sum+=ls
    ls=sum
    if i%2==0:
        sum+=1
    a.append(sum)

while True:
    try:
        s=int(input())
        print(a[s])
    except:
        break
