a=[]
a.append(0)
a.append(0)
a.append(0)
a.append(4)
a.append(7)

for i in range(5,10011,1):
    dd=a[i-1]+a[i-2]
    a.append(dd)

while True:
    try:
        s=int(input())
        print(a[s])
    except:
        break
