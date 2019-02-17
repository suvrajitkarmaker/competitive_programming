cat = [0]*1002
cat[0]=1

for n in range(1, 1002,1):
    for i in range(0,n,1):
        cat[n] += (cat[i]*cat[n-1-i])
while True:
    try:
        s=int(input())
        print(int(cat[s]))
    except:
        break
