n, k = map(int, input().split())

arr = []

for _ in range(100000):
    arr.append(0)

n1, n2 = 0,0
for _ in range(n):
    n1, n2 = map(int, input().split())
    arr[n1] = n2
  
print(n1)