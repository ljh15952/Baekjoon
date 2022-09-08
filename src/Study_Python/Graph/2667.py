from collections import deque

n = int(input()) # 지도의 크기

grid = []
for _ in range(n):
    grid.append(list(map(int,input())))

dx = [-1,1,0,0]
dy = [0,0,-1,1]



def bfs(y, x):
    grid[y][x] = 0 # 들렸다는 체크
    _deque = deque()
    _deque.append((y,x))

    cnt = 1

    while _deque:
        y,x = _deque.popleft()
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if grid[ny][nx] == 1:
                grid[ny][nx] = 2
                _deque.append((ny,nx))
                cnt += 1
    return cnt


house = []

for i in range(n):
    for j in range(n):
        if grid[i][j] == 1:
            house.append(bfs(i, j))

print(len(house))
house.sort()
for i in range(len(house)):
    print(house[i])


