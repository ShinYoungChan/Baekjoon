import sys
input = sys.stdin.readline

n = int(input())
lst = []; dp = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    lst.append(list(map(int, input().split())))
dp[0][0] = 1
for i in range(n):
    for j in range(n):
        if dp[i][j] == 0: continue
        if i == n - 1 and j == n - 1: break
        if i + lst[i][j] < n:
            dp[i + lst[i][j]][j] += dp[i][j]
        if j + lst[i][j] < n:
            dp[i][j + lst[i][j]] += dp[i][j]

print(dp[n-1][n-1])