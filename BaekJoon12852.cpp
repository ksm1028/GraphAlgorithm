#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <ctime>
#include <time.h>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;

int d[1000001];
int v[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    queue<int> q;
    q.push(n);
    v[n] = 1;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        if(x == 1)
            break;

        if(x % 3 == 0)
        {
            if(v[x / 3] == 0)
            {
                q.push(x / 3);
                v[x / 3] = v[x] + 1;
                d[x / 3] = x;
            }
        }
        if(x % 2 == 0)
        {
            if(v[x / 2] == 0)
            {
                q.push(x / 2);
                v[x / 2] = v[x] + 1;
                d[x / 2] = x;
            }
        }
        if(v[x - 1] == 0)
        {
            q.push(x - 1);
            v[x - 1] = v[x] + 1;
            d[x - 1] = x;
        }
    }

    cout << v[1] - 1 << '\n';

    int x = 1;
    vector<int> ans;
    ans.push_back(1);

    while(x != n)
    {
        ans.push_back(d[x]);
        x = d[x];
    }

    reverse(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";

    return 0;
}
