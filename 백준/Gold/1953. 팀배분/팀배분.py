import sys

blue = []
white = []

def dfs(x):
    visited[x] = 1
    stack = [x]
    while stack:
        node = stack.pop()
        for nei in grid[node]:
            if not visited[nei]:
                visited[nei]=-visited[node]
                stack.append(nei)

n = int(sys.stdin.readline())

grid = [[] for _ in range(n+1)]
for i in range(n):
    info = list(map(int, sys.stdin.readline().split()))
    for j in range(info[0]):
        grid[i+1].append(info[j+1])
        grid[info[j+1]].append(i+1)
visited = [0 for _ in range(n+1)]
for i in range(1, n+1):
    if not visited[i]:
        dfs(i)
for i in range(1,n+1):
    if visited[i]==1:
        blue.append(i)
    else:
        white.append(i)
print(len(blue))
print(" ".join(map(str, blue)))
print(len(white))
print(" ".join(map(str, white)))