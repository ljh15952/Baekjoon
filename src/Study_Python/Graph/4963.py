# w, h = map(int, input().split()) # 지도의 너비, 높이

# if w == 0 and h == 0:
#     exit()

w = 2
h = 2

grid = []
visited = []

for _ in range(h):
    grid.append(list(map(int, input().split())))

for i in range(h):
    visited.append([])
    for _ in range(w):
        visited[i].append(False)
   



def dfs(y, x) :
    print(y,x)
    visited[y][x] = True

    if x+1 < w:
        if grid[y][x+1] == 1:
            dfs(y,x+1)
    elif x-1 >= 0:
        if grid[y][x-1] == 1:
            dfs(y,x-1)
    elif y+1 < h:
        if grid[y+1][x] == 1:
            dfs(y+1,x)
    elif y-1 >= 0:
        if grid[y-1][x] == 1:
            dfs(y-1,x)


dfs(0,0) # h, w

print(visited)




