n, k = map(int, input().split())

arr = []
ans = []
for _ in range(100000):
    ans.append(0)
    arr.append(0)

n1, n2 = 0,0
for _ in range(n):
    n1, n2 = map(int, input().split())
    arr[n1] = n2



for i in range(2,10):
    if i + i - 1 > k:
       # print(i)
        ans[i] = ans[i - 1] + arr[k - i]
        
    else:
        #print(i)
        ans[i] = ans[i-1] + arr[i-2]
        #print(arr[i-2])
#print(ans[2])
for i in range(0,20):
    print(arr[i])
#print(max(ans))