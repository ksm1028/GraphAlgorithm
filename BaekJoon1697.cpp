#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100000;

bool visited[MAX + 1] = {false, };
int n, k;

int bfs(int start, int end)
{
    queue<int> q;
    int seconds = 0;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int qSize = q.size();

        for (int i = 0; i < qSize; ++i)
        {
            int curPos = q.front();
            q.pop();

            if (curPos == end) return seconds;

            if (curPos - 1 >= 0 && !visited[curPos - 1])
            {
                q.push(curPos - 1);
                visited[curPos - 1] = true;
            }
            if (curPos + 1 <= MAX && !visited[curPos + 1])
            {
                q.push(curPos + 1);
                visited[curPos + 1] = true;
            }
            if (curPos * 2 <= MAX && !visited[curPos * 2])
            {
                q.push(curPos * 2);
                visited[curPos * 2] = true;
            }
        }

        seconds++;
    }

    return seconds;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(visited, false, sizeof(visited));

    cin >> n >> k;

    cout << bfs(n, k) << "\n";

    return 0;
}
