import collections as col
from collections import deque
import sys

sys.setrecursionlimit(10**6)


n, m, v = map(int, input().split())


graph = [[] for _ in range(n + 1)]

for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(n + 1):
    graph[i].sort()

    visited = [False for i in range(n + 1)]

def DFS(num):
    for i in graph[num]:
        if(not visited[i]):
            visited[i] = True
            print(i, end=" ")
            DFS(i)

visited[v] = True
print(v, end= " ")
DFS(v)
print()

visited = [False for i in range(n + 1)]

q = deque()
def BFS(num):
    visited[num] = True
    for i in graph[num]:
        if(not visited[i]):
            if(not i in q):
                q.append(i)
    print(num, end= " ")
    if(len(q) > 0):
        BFS(q.popleft())
        

q.append(v)
BFS(q.popleft())
