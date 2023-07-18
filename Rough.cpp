/*#include <bits/stdc++.h>
using namespace std;

int dp[1010][1010];

int rec(int x, int y, vector<vector<int>> &A, int n, int m)
{
    // cout << "check2\n";
    if ((x == n - 1) && (y == m - 1))
    {
        return A[x][y];
    }
    if (x > n - 1 || y > m - 1)
    {
        return INT_MAX;
    }

    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    // cout << "check6\n";
    int ans = A[x][y] + min({(rec(x + 1, y, A, n, m)), (rec(x, y + 1, A, n, m))});
    return dp[x][y] = ans;
}

void minPathSum(vector<vector<int>> &A)
{
    int n, m;
    n = A.size();
    m = A[0].size();
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = -1;
        }
    }
    int ans = rec(0, 0, A, n, m);
    cout << ans << '\n';
}

int main()
{

    vector<vector<int>> A = {{20, 29, 84, 4, 32, 60, 86, 8, 7, 37},
                             {77, 69, 85, 83, 81, 78, 22, 45, 43, 63},
                             {60, 21, 0, 94, 59, 88, 9, 54, 30, 80},
                             {40, 78, 52, 58, 26, 84, 47, 0, 24, 60},
                             {40, 17, 69, 5, 38, 5, 75, 59, 35, 26},
                             {64, 41, 85, 22, 44, 25, 3, 63, 33, 13},
                             {2, 21, 39, 51, 75, 70, 76, 57, 56, 22},
                             {31, 45, 47, 100, 65, 10, 94, 96, 81, 14}};
    // vector<vector<int>> A = {{1, 2}, {3, 4}};
    minPathSum(A);

    return 0;
}*/

/* Minumum element in k-window using deque.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    deque<int> dq;

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {

        while(!dq.empty() && dq.back()>v[i]){
                dq.pop_back();
            }
        dq.push_back(v[i]);

        if (i >= k - 1)
        {
            ans.push_back(dq.front());
            if (dq.front() == v[i - k + 1])
            {
                dq.pop_front();
            }
        }
    }

    for (auto num : ans)
        cout << num << '\t';
    cout << '\n';
}*/

/*#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[101];
int sz[101];
int dp[101][2][101];
vector<int> g[101];

void dfs(int node, int par)
{
    for (int i = 0; i <= k; i++)
    {
        dp[node][0][i] = (i == 1 ? arr[node] : -1e9);
        dp[node][1][i] = (i == 0 ? 0 : -1e9);
    }

    for (auto v : g[node])
    {
        dfs(v, node);
        sz[node] += sz[v];

        for (int a = k; a >= 0; a--)
        {
            for (int b = k; b >= 0; b--)
            {
                dp[node][0][a + b] = max(dp[node][0][a + b], dp[node][0][a] + max(dp[v][0][b], dp[v][1][b]));
                dp[node][1][a + b] = max(dp[node][1][a + b], dp[node][1][a] + dp[v][0][b]);
            }
        }
    }
}

void solve()
{
}

int main()
{
    solve();
    return 0;
}*/

/*#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
int arr[100100];
int dp[100100][2];

void dfs(int node, int par)
{
    dp[node][0] = arr[node];
    dp[node][1] = 0;

    for (auto v : g[node])
    {
        if (v != par)
        {
            dfs(v, node);
            dp[node][0] += dp[v][1];
            dp[node][1] += dp[v][0];
        }
    }

    dp[node][0] = max(dp[node][0], dp[node][1]);
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    g.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            dp[i][j] = -1;
        }
    }

    dfs(1, 0);

    cout << dp[1][0] << '\n';
}

int main()
{
    solve();
    return 0;
}*/

/*#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;

int indp[100100];
int outdp[100100];

void indfs(int node, int par)
{
    indp[node] = 1;

    for (auto v : g[node])
    {
        if (v != par)
        {
            indfs(v, node);
            indp[node] = max(indp[v] + 1, indp[node]);
        }
    }
}

void outdfs(int node, int par, int outVal)
{
    outdp[node] = outVal;

    int max1 = -1, max2 = -1;

    for (auto v : g[node])
    {
        if (v != par)
        {
            if (indp[v] > max1)
            {
                max2 = max1;
                max1 = indp[v];
            }
            else if (indp[v] > max2)
            {
                max2 = indp[v];
            }
        }
    }

    for (auto v : g[node])
    {
        if (v != par)
        {
            if (indp[v] == max1)
            {
                outdfs(v, node, max(outdp[node] + 1, max2 + 2));
            }
            else
            {
                outdfs(v, node, max(outdp[node] + 1, max1 + 2));
            }
        }
    }
}

void solve()
{
    cin >> n;
    g.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    indfs(1, 0);
    outdfs(1, 0, 0);
}

int main()
{
    solve();
    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100100];
int dp[100100];
bool saved[100100];

int rec(int level)
{
    if (level < 0)
        return INT_MIN;
    if (level == 0)
        return arr[0];
    if (saved[level] != 0)
        return dp[level];
    int ans = max(arr[level], rec(level - 1) + arr[level]);
    saved[level] = 1;
    return dp[level] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));
    memset(saved, 0, sizeof(saved));

    int ans = rec(0);
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, rec(i));
    }

    cout << ans << '\n';
}