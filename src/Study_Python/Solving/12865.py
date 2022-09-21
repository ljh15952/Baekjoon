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

ans[1] = arr[1]

for i in range(2,10):
    ans[i] = arr[i]
    print(ans[i])
