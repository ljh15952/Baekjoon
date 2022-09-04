def dfs(y, x) :
    if visited[y][x] == True:
        return
    visited[y][x] = True
    # 배열을 벗어나지 않고 땅이라면 이동!
    # -1 0 1
    for i in range(-1, 2):
        for j in range(-1, 2):
            if y+i < h and x+j < w and y+i >= 0 and x+j >= 0:
                if grid[y+i][x+j] == 1 and visited[y+i][x+j] == False:
                    dfs(y+i,x+j)

while True:
    w, h = map(int, input().split()) # 지도의 너비, 높이

    if w == 0 and h == 0:
        exit()

    grid = []
    visited = []

    for _ in range(h):
        grid.append(list(map(int, input().split())))

    for i in range(h):
        visited.append([])
        for _ in range(w):
            visited[i].append(False)

    ans = 0

    for i in range(h):
        for j in range(w):
            if grid[i][j] == 1 and visited[i][j] == False:
                dfs(i,j) # h, w
                ans += 1

    print(ans)




