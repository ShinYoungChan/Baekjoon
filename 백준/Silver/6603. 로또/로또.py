import itertools
while True:
    
    arr=map(int,input().split())
    arr=list(arr)
    n=arr[0]
    if n == 0:
        break
    arr.pop(0)
    nCr=itertools.combinations(arr,6)
    for i in nCr:
        for j in range(len(i)):
            print(i[j],end=" ")
        print()
    print()