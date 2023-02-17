#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 10001;

vector<int> graph[MAX_N];
int cnt[MAX_N];
bool visited[MAX_N];

int dfs(int node) {
    visited[node] = true;
    int res = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        int nextNode = graph[node][i];
        if (!visited[nextNode]) {
            res += dfs(nextNode);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    int maxCnt = 0;
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        cnt[i] = dfs(i);
        maxCnt = max(maxCnt, cnt[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (cnt[i] == maxCnt) {
            cout << i << " ";
        }
    }
    cout << '\n';

    return 0;
}
