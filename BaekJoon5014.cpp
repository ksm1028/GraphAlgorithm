#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1000000;
int f, s, g, u, d;
int dist[MAX + 1];

void bfs(int start) 
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) 
    {
        int cur = q.front();
        q.pop();

        if (cur == g) return;

        if (cur + u <= f && dist[cur + u] == -1) 
        {
            dist[cur + u] = dist[cur] + 1;
            q.push(cur + u);
        }

        if (cur - d >= 1 && dist[cur - d] == -1) 
        {
            dist[cur - d] = dist[cur] + 1;
            q.push(cur - d);
        }
    }
}

int main() 
{
    cin >> f >> s >> g >> u >> d;

    memset(dist, -1, sizeof(dist));

    bfs(s);

    if (dist[g] == -1) cout << "use the stairs\n";
    else cout << dist[g] << '\n';

    return 0;
}
