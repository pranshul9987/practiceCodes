/* DFS code ---> Basic structure
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
vector<vector<int>> g;

vector<int> vis;

int nodeVisited = 0;

void dfs(int node)
{
    vis[node] = 1;
    nodeVisited += 1;
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.clear();
    g.resize(n + 1);
    vis.assign(n + 1, 0);

    // We have n nodes, and m edges between them. g[a] stores all the neighbours of the node a. Hence when we input the edge a b, we push b in g[a], and a in g[b].
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    nodeVisited = 0;
    vector<int> compsz;

    for (int node = 1; node <= n; node++)
    {
        if (!vis[node])
        {
            nodeVisited = 0;
            dfs(node);
            compsz.push_back(nodeVisited);
        }
    }

    ll ans = 0, preSum = 0;
    for (auto v : compsz)
    {
        ans += preSum * v;
        preSum += v;
    }
    cout << ans << '\n';
}

int main()
{
    solve();
    return 0;
}*/

/* DFS - Cycle finding
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> g;
vector<int> col;
vector<int> parent;

bool is_cycle = 0;
vector<int> any_cycle;

void dfs(int node, int par)
{
    parent[node]=par;
    col[node] = 2;
    for (auto v : g[node])
    {
        if (col[v] == 1)
        {
            // Node <----------> v is a forward edge.
            dfs(v, node);
        }
        else if (col[node] == 2)
        {
            // Node <----------> v is a backward edge.
            // Cycle found.
            if(is_cycle==0){
                int temp=node;
                while(temp!=v){
                    any_cycle.push_back(temp);
                    temp=parent[temp];
                }
                any_cycle.push_back(temp);
                reverse(any_cycle.begin(), any_cycle.end());
            }
            is_cycle = 1;
        }
        else if (col[node] == 3)
        {
            // Node <----------> v is a cross edge.
            // Not important, here.
        }
    }
    col[node] = 3;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    col.assign(n + 1, 1);
    parent.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
    {
        if (col[i] == 1)
        {
            dfs(i, 0);
        }
    }

    for(auto v:any_cycle){
        cout<<v<<'\t';
    }
    cout<<'\n';
}

int main()
{
    solve();

    return 0;
}*/

/* DFS - Counting the total number of cycles present in the graph
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> g;
vector<int> col;
vector<int> parent;

bool is_cycle = 0;
vector<int> any_cycle;

vector<int> cntcycle;
vector<int> prefixOrder;

void dfs(int node, int par)
{
    parent[node]=par;
    col[node] = 2;
    for (auto v : g[node])
    {
        if(v==parent[node]){ // For undirected graph, since for x ----> y, we will also have y ----> x. And we need to avoid these being counted as cycles.
            continue;
        }
        if (col[v] == 1)
        {
            // Node <----------> v is a forward edge.
            dfs(v, node);
        }
        else if (col[node] == 2)
        {
            // Node <----------> v is a backward edge.
            // Cycle found.
            if(is_cycle==0){
                int temp=node;
                while(temp!=v){
                    any_cycle.push_back(temp);
                    temp=parent[temp];
                }
                any_cycle.push_back(temp);
                reverse(any_cycle.begin(), any_cycle.end());
            }
            cntcycle[node]++;
            cntcycle[parent[v]]--;
            is_cycle = 1;
        }
        else if (col[node] == 3)
        {
            // Node <----------> v is a cross edge.
            // Not important, here.
        }
    }
    col[node] = 3;
    prefixOrder.push_back(node);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    col.assign(n + 1, 1);
    parent.assign(n + 1, 0);
    cntcycle.assign(n+1, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (col[i] == 1)
        {
            dfs(i, 0);
        }
    }

    for(auto v:any_cycle){
        cout<<v<<'\t';
    }
    cout<<'\n';


    for(auto v:prefixOrder){
        cntcycle[parent[v]]+=cntcycle[v];
    }
    int cntnodes=0;
    for(int i=1; i<=n; i++){
        if(cntcycle[i]>0) cntnodes++;
    }
    cout<<cntnodes<<'\n';
}

int main()
{
    solve();

    return 0;
}*/

/* BFS - Find the shortest path to reach a cell in given grid with some obstacles.
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ii = pair<int, int>;

int n, m;
vector<string> arr;
int dist[1010][1010];
ii par[1010][1010];

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

bool inside(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == '#')
        return 0;
    return 1;
}

void bfs(ii st)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = 1e9;
        }
    }
    dist[st.F][st.S] = 0;
    queue<ii> q;
    q.push(st);
    while (!q.empty())
    {
        ii cur = q.front();
        q.pop();
        int curd = dist[cur.F][cur.S];
        for (int k = 0; k < 4; k++)
        {
            if (!inside(cur.F + dx[k], cur.S + dy[k]))
                continue;
            ii neigh = {cur.F + dx[k], cur.S + dy[k]};
            if (dist[neigh.F][neigh.S] > curd + 1) // Relaxing
            {
                dist[neigh.F][neigh.S] = curd + 1;
                par[neigh.F][neigh.S]=cur;
                q.push(neigh);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    arr.resize(n);
    ii st, en;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 'S')
            {
                st = {i, j};
            }
            else if (arr[i][j] == 'E')
            {
                en = {i, j};
            }
        }
    }
    bfs(st);
    // cout << dist[en.F][en.S] << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << '\t';
        }
        cout << '\n';
    }

    ii temp=en;
    vector<ii> path;
    while(temp!=st){
        path.push_back(temp);
        temp=par[temp.F][temp.S];
    }
    path.push_back(st);
    reverse(path.begin(), path.end());
    for(auto v:path){
        cout<<v.F<<'\t'<<v.S<<'\n';
    }
}*/

/* You and some monsters are in a matrix. When taking a step to some direction in the matrix, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster. Your task is to find out if your goal is possible, and if it is, print the shortest length of the path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool grid[N][N];
int distA[N][N];
int distMon[N][N];

queue<pair<int, int>> monsterOcc, AOcc;
pair<int, int> par[N][N];

void solve()
{
    int n, m;
    cin >> n >> m;

    memset(grid, false, sizeof(grid));
    memset(distMon, -1, sizeof(distMon));
    memset(distA, -1, sizeof(distA));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            grid[i][j] = true;
            if (s[j] == '#')
            {
                grid[i][j] = false;
            }
            else if (s[j] == 'M')
            {
                distMon[i][j] = 0;
                monsterOcc.push({i, j});
            }
            else if (s[j] == 'A')
            {
                distA[i][j] = 0;
                AOcc.push({i, j});
                par[i][j] = {-1, -1};
            }
        }
    }

    while (!monsterOcc.empty())
    {
        auto it = monsterOcc.front();
        int x = it.first, y = it.second;
        for (int k = 0; k < 4; k++)
        {
            int xx = x + dx[k], yy = y + dy[k];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m)
            {
                continue;
            }
            if (grid[xx][yy] && distMon[xx][yy] == -1)
            {
                distMon[xx][yy] = distMon[x][y] + 1;
                monsterOcc.push({xx, yy});
            }
        }
    }

    while (!AOcc.empty())
    {
        auto it = AOcc.front();
        int x = it.first, y = it.second;
        for (int k = 0; k < 4; k++)
        {
            int xx = x + dx[k], yy = y + dy[k];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m)
            {
                continue;
            }
            if (grid[xx][yy] && distA[xx][yy] == -1)
            {
                distMon[xx][yy] = distA[x][y] + 1;
                AOcc.push({xx, yy});
            }
        }
    }

    int finx = -1, finy = -1, findist = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] && distA[i][0] >= 0 && (distA[i][0] < distMon[i][0] || distMon[i][0] == -1))
        {
            finx = i;
            finy = 0;
            findist = min(findist, distA[i][0]);
        }

        if (grid[i][m - 1] && distA[i][m - 1] >= 0 && (distA[i][m - 1] < distMon[i][m - 1] || distMon[i][m - 1] == -1))
        {
            finx = i;
            finy = m - 1;
            findist = min(findist, distA[i][m - 1]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] && distA[0][i] >= 0 && (distA[0][i] < distMon[0][i] || distMon[0][i] == -1))
        {
            finx = 0;
            finy = i;
            findist = min(findist, distA[0][i]);
        }

        if (grid[m - 1][i] && distA[m - 1][i] >= 0 && (distA[m - 1][i] < distMon[m - 1][i] || distMon[m - 1][i] == -1))
        {
            finx = m - 1;
            finy = i;
            findist = min(findist, distA[m - 1][i]);
        }
    }

    if (finx == -1)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        cout << findist << '\n';
    }
}

int main()
{
    solve();
    return 0;
}*/

/* Topological ordering of a DAG using DFS
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

vector<int> vis;

vector<int> topo;

void dfs(int node){
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
    topo.push_back(node);
}

void solve(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    vis.assign(n+1,0);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    reverse(topo.begin(), topo.end());
    for(auto v:topo){
        cout<<v<<'\t';
    }
}

int main(){
    solve();
    return 0;
}*/

/* Find the longest length path in a given DAG --- Using DP
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int dp[100100];

int rec(int level)
{
    if (dp[level] != -1)
    {
        return dp[level];
    }

    int ans = 0;
    for (auto v : g[level])
    {
        ans = max(ans, 1 + rec(v));
    }

    return dp[level] = ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, rec(i));
    }
    cout << ans << '\n';
}

int main()
{
    solve();
    return 0;
}*/

/* Find the longest length path in a given DAG --- Using Topological ordering
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;
vector<int> topo;

int dp[100100];

void dfs(int node){
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
    topo.push_back(node);
}

void solve(){
    int n, m;
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    vis.assign(n+1,0);

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    int final=0;
    for(auto node:topo){
        int ans=0;
        for(auto v:g[node]){
            ans=max(ans, 1+dp[v]);
        }
        dp[node]=ans;
        final=max(final, dp[node]);
    }

    cout<<final<<'\n';

}

int main(){
    solve();
    return 0;
}*/

/* Kahn's Algo --- Topological ordering of a DAG using BFS
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> indeg;

vector<int> topo;

void kahn(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        topo.push_back(cur);
        for(auto v:g[cur]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(v);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    indeg.assign(n+1,0);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]+=1;
    }
    kahn();
    for(auto v:topo){
        cout<<v<<'\t';
    }
    cout<<'\n';

}

int main(){
    solve();
    return 0;
}*/

/* Find the lexicographically smallest topological order using BFS.
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> indeg;

vector<int> topo;

void kahn(){
    priority_queue<int> q;
    for(int i=1; i<=n; i++){
        if(indeg[i]==0){
            q.push(-i);
        }
    }
    while(!q.empty()){
        int cur=-q.top();
        q.pop();
        topo.push_back(cur);
        for(auto v:g[cur]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(-v);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    indeg.assign(n+1,0);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]+=1;
    }
    kahn();
    for(auto v:topo){
        cout<<v<<'\t';
    }
    cout<<'\n';

}

int main(){
    solve();
    return 0;
}*/

/*  Shortest distance from the starting point --- Using BFS
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
int n, m, x, y, a, b;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

bool check(int i, int j)
{
    if (i >= 1 && i <= n && j >= 1 && j <= m)
    {
        return true;
    }
    return false;
}

int dist[1010][1010];
void bfs(int stx, int sty)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dist[i][j] = 1e9;
        }
    }

    queue<ii> q;
    q.push({stx, sty});
    dist[stx][sty] = 0;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int xx = it.first + dx[i], yy = it.second + dy[i];
            if (check(xx, yy) && dist[xx][yy] > dist[it.first][it.second])
            {
                dist[xx][yy] = dist[it.first][it.second] + 1;
                q.push({xx, yy});
            }
        }
    }
}

int main()
{
    cin >> n >> m>>x>>y>>a>>b;
    bfs(1,1);
    for(int i=1; i<=n; i++){
        for(int j=1;j<=m;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}

*/

/* Find the shortest distance of nodes from the starting node --- 0-1 BFS
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
using ii = pair<int, int>;

int n, m;
vector<vector<ii>> g;
vector<int> dis;
deque<int> dq;

void zobfs(int st){
    while(!dq.empty()){
        int curr=dq.front();
        dq.pop_front();
        for(auto next:g[curr]){
            int node=next.F;
            int change=next.S;
            if(dis[node]>dis[curr]+change){
                dis[node]=dis[curr]+change;
                if(change==0){
                    dq.push_front(node);
                }else{
                    dq.push_back(node);
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    dis.assign(n+1, 1e9);
    dis[1]=0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
    }
    dq.push_back(1);
    zobfs(1);

    for(int i=1; i<=n; i++){
        cout<<i<<'\t'<<dis[i]<<'\n';
    }
}

int main()
{
    solve();
    return 0;
}*/

/* Given a N*M grid, with each cell marked with one of the four arrows - Right, Left, Up, Down. You begin from first cell and have to reach the last cell of the grid in minimum cost. If you are on a cell with arrow pointing in direction D, then you can move in that direction free of cost, but moving in other 3 directions costs 1. --- Using 0-1 BFS
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
#define F first
#define S second

int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<vector<pair<pair<int, int>, int>>>> g;
vector<vector<int>> dis;
vector<vector<int>> grid;
deque<ii> dq;

void bfs(int x, int y)
{
    while (!dq.empty())
    {
        auto curr = dq.front();
        dq.pop_front();
        for (auto next : g[curr.F][curr.S])
        {
            int xx = next.F.F, yy = next.F.S, change = next.S;
            int curDis = dis[xx][yy];
            if (curDis > dis[curr.F][curr.S] + change)
            {
                dis[xx][yy] = dis[curr.F][curr.S] + change;
                if (change == 0)
                {
                    dq.push_front({xx, yy});
                }
                else
                {
                    dq.push_back({xx, yy});
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n);
    dis.resize(n);
    for (int i = 0; i < n; i++)
    {
        g[i].resize(m);
        dis[i].assign(m, 1e9);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int dir;
            cin >> dir;
            if (j + 1 < m)
            {
                if (dir == 1)
                {
                    g[i][j].push_back({{i, j + 1}, 0});
                }
                else
                {
                    g[i][j].push_back({{i, j + 1}, 1});
                }
            }
            if (j - 1 > 0)
            {
                if (dir == -1)
                {
                    g[i][j].push_back({{i, j - 1}, 0});
                }
                else
                {
                    g[i][j].push_back({{i, j - 1}, 1});
                }
            }
            if (i - 1 > 0)
            {
                if (dir == -2)
                {
                    g[i][j].push_back({{i - 1, j}, 0});
                }
                else
                {
                    g[i][j].push_back({{i - 1, j}, 1});
                }
            }
            if (i + 1 < n)
            {
                if (dir == 2)
                {
                    g[i][j].push_back({{i + 1, j}, 0});
                }
                else
                {
                    g[i][j].push_back({{i + 1, j}, 1});
                }
            }
        }
    }
    dis[0][0] = 0;
    dq.push_back({0, 0});
    bfs(0, 0);
    for (auto row : dis)
    {
        for (auto col : row)
        {
            cout << col << '\t';
        }
        cout << '\n';
    }
}

int main()
{
    solve();
    return 0;
}*/

/* Givena  2D grid, with some points marked with Red/Blue/Yellow colours. We have to draw lines joining the points such that each line passes through at least one point of each colour. Task is to minimize the sum of lengths of these lines.
#include <bits/stdc++.h>
using namespace std;
using state = pair<int, int>;
#define F first
#define S second
int n;

struct point
{
    int x, y, c;
};

int dist(point p1, point p2)
{
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

vector<point> arr;
int vis[1010][(1 << 4)];
int dis[1010][(1 << 4)];
void dijkstra()
{
    priority_queue<pair<int, state>> pq;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (1 << 4); j++)
        {
            dis[i][j] = 1e9;
            vis[i][j] = 0;
        }
        dis[i][(1 << arr[i].c)] = 0;
        pq.push({0, {i, (1 << arr[i].c)}});
    }

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int disp = -cur.F;
        int curp = cur.S.F;
        int taken = cur.S.S;

        if (vis[curp][taken])
            continue;
        vis[curp][taken] = 1;

        for (int i = 0; i < n; i++)
        {
            if (dis[i][taken | (1 << arr[i].c)] > disp + dist(arr[curp], arr[i]))
            {
                dis[i][taken | (1 << arr[i].c)] = disp + dist(arr[curp], arr[i]);
                pq.push({-dis[i][taken | (1 << arr[i].c)], {i, taken | (1 << arr[i].c)}});
            }
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        arr.push_back({x, y, c});
    }
    dijkstra();
    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, dis[i][(1 << 4) - 1]);
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}*/

/* Given a sequence a0, a1, a2, a3....a(n-1). We are given the following informations and questions: (i) relate(x,y,z): ay is greater than ax by z; (ii) diff(x,y): report the difference between ax and ay, i.e., ay-ax.
#include <bits/stdc++.h>
using namespace std;

int par[100100];
int diff[100100];

void init()
{
    for (int i = 0; i < 100100; i++)
    {
        par[i] = i;
        diff[i] = 0;
    }
}

pair<int, int> find(int x)
{
    if (par[x] == x)
    {
        return {x, 0};
    }
    pair<int, int> temp = find(par[x]);
    diff[x] += temp.second;
    par[x] = temp.first;
    return {par[x], diff[x]};
}

void relate(int x, int y, int z)
{
    pair<int, int> temp1 = find(x);
    pair<int, int> temp2 = find(y);
    if (temp1.first == temp2.first)
        return;
    diff[temp2.first] = temp1.second + z - temp2.second;
    par[temp2.first] = temp1.first;
}

void diffQ(int x, int y)
{
    pair<int, int> temp1 = find(x);
    pair<int, int> temp2 = find(y);
    if (temp1.first != temp2.first)
    {
        cout << "?\n"; // Since they are unrelated, we can not find the difference in this case, hence we output "?".
    }
    else
    {
        cout << temp2.second - temp1.second << '\n';
    }
}

void solve()
{
    int n, m;
    cin>>n>>m;
    init();
    for(int i=0; i<m; i++){
        int ch, x, y, z;
        cin>>ch;
        if(ch==0){
            cin>>x>>y>>z;
            relate(x, y, z);
        }else{
            cin>>x>>y;
            diffQ(x, y);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}*/

/* Articulation point and bridges --- DFS
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100
vector<int> g[MAXN];
int inTime[MAXN], loTime[MAXN];
int timer = 0;
vector<int> numSplits(MAXN);

void dfs(int node, int par)
{
    timer += 1;
    inTime[node] = loTime[node] = timer;
    bool isArti = false;
    int child = 0;
    numSplits[node] = 1;

    for (auto x : g[node])
    {
        if (x == par)
            continue;
        if (!inTime[x])
        { // node<--->x is a fowrard edge
            child += 1;
            dfs(x, node);
            loTime[node] = min(loTime[node], loTime[x]);
            if (loTime[x] >= inTime[node])
            {
                isArti = true; // x will be a new component.
                numSplits[node] += 1;
            }
            if (loTime[x] > loTime[node])
            {
                // node<--->x is a bridge
                cout << "Articulation bridge:\t" << node << " ----- " << x << '\n';
            }
        }
        else
        { // node to x is a backedge
            loTime[node] = min(loTime[node], loTime[x]);
        }
    }

    if (par == 0)
        numSplits[node] = child;

    if ((par == 0 && child >= 2) || (par != 0 && isArti))
    {
        // This node is an articulation point.
        cout << "Articulation point:\t" << node << '\n';
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int comp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!inTime[i])
        {
            comp += 1;
            dfs(i, 0);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() == 0)
        {
            cout << comp - 1 << '\n';
        }
        else
        {
            cout << comp - 1 + numSplits[i] << '\n';
        }
    }
}

int main()
{
    solve();
    return 0;
}*/

/* DFS --- Euler tour on tree --- Rooted tree given, answer Q queries u v --- whether u is an ancestor of v or not?
#include <bits/stdc++.h>
using namespace std;

vector<int> g[100100];
vector<int> inTime(100100);
vector<int> outTime(100100);
int timer = 0;

void dfs(int node, int par)
{
    timer++;
    inTime[node] = timer;
    for (auto v : g[node])
    {
        if (!inTime[v])
        {
            dfs(v, node);
        }
    }

    timer++;
    outTime[node] = timer;
}

bool isUAncestorOfV(int u, int v){
    if(inTime[u]<inTime[v] && outTime[u]>outTime[v]){
        return true;
    }
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << "Node: " << i << "\tInTime: " << inTime[i] << "\tOutTime: " << outTime[i] << '\n';
    }
}

int main()
{
    solve();
    return 0;
}*/

/* Self Practice --- Topological order using DFS
#include <bits/stdc++.h>
using namespace std;

vector<int> isVis;
vector<vector<int>> g;

vector<int> topo;
void dfs(int node)
{
    isVis[node] = 1;

    for (auto v : g[node])
    {
        if (!isVis[v])
        {
            dfs(v);
        }
    }
    topo.push_back(node);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    isVis.resize(n + 1, 0);
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!isVis[i])
        {
            dfs(i);
        }
    }

    reverse(topo.begin(), topo.end());

    for (auto v : topo)
        cout << v << '\t';
    cout << '\n';
}

int main()
{
    solve();
    return 0;
}*/

/* Cycle detection in undirected graph using BFS
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> isVisited;
queue<pair<int, int>> q;
bool hasCycle = false;

void bfs()
{
    while (!q.empty())
    {
        int node = q.front().first, par = q.front().second;
        q.pop();
        isVisited[node] = 1;
        for (auto v : g[node])
        {
            if (v != par)
            {

                if (isVisited[v])
                {
                    hasCycle = true;
                }
                else
                {
                    q.push({v, node});
                }
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    isVisited.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(!isVisited[i]){
            q.push({i,0});
            bfs();
        }
    }
    if (hasCycle)
        cout << "Cycle found\n";
    else
        cout << "No Cycle\n";
}

int main()
{
    solve();
    return 0;
}*/

/* Cycle detection in undirected graph using DFS
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> isVisited;

bool hasCycle = false;

void dfs(int node, int par)
{
    isVisited[node] = 1;
    for (auto v : g[node])
    {
        if (!hasCycle)
        {
            if (!isVisited[v])
            {
                dfs(v, node);
            }
            else if (isVisited[v] && v == par)
            {
                hasCycle = true;
            }
        }
        else
        {
            return;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    isVisited.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!hasCycle && !isVisited[i])
        {
            dfs(i, 0);
        }
    }

    if (hasCycle)
        cout << "Cycle found\n";
    else
        cout << "No Cycle\n";
}

int main()
{
    solve();
    return 0;
}*/

/* Binary Tree Traversals ***DFS*** ---> Pre-order traversal --- Root Left Right --- In-order Traversal --- Left root right --- Post-order Traversal --- Left Right Root
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void preorderdfs(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << '\n';
    preorderdfs(root->left);
    preorderdfs(root->right);
}

void inOrderDFS(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderDFS(root->left);
    cout << root->data << '\n';
    inOrderDFS(root->right);
}

void postOrderDFS(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderDFS(root->left);
    postOrderDFS(root->right);
    cout << root->data << '\n';
}

void solve()
{
}

int main()
{
    solve();
    return 0;
}*/

/* Binary Tree Traversal ***BFS*** ---> Level Order Traversal
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}

void solve();

int main()
{
    solve();
    return 0;
}*/

/* Binary Tree Traversal --- Iterative Ways
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> preOrder;
    if (root == NULL)
    {
        return preOrder;
    }
    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();
        preOrder.push_back(root->val);
        if (root->right != NULL)
            st.push(root->right);
        if (root->left != NULL)
            st.push(root->left);
    }
    return preOrder;
}

vector<int> inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    TreeNode *node = root;
    vector<int> inOrder;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            node = st.top();
            st.pop();
            inOrder.push_back(node->val);
            node = node->right;
        }
    }
    return inOrder;
}

// Using 2 stacks
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> postOrder;
    if (root == NULL)
    {
        return postOrder;
    }
    stack<TreeNode *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if (root->left != NULL)
        {
            st1.push(root->left);
        }
        if (root->right != NULL)
        {
            st1.push(root->right);
        }
    }
    while (!st2.empty())
    {
        postOrder.push_back(st2.top()->val);
        st2.pop();
    }
    return postOrder;
}

// Using 1 stack
vector<int> postorderTraversal2(TreeNode *root)
{
    vector<int> postOrder;
    TreeNode *curr = root;
    stack<TreeNode *> st;

    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->val);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->val);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return postOrder;
}

void solve()
{
}

int main()
{
    solve();
    return 0;
}*/

/* Max Depth in Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive
int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh, rh);
}

// Level Order search
int maxHeight = 1;
int levelOrderSearch(TreeNode *root)
{
    queue<TreeNode *> q;
    if (root == NULL)
        return 0;
    int height = 0;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->left != NULL)
            {

                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        height+=1;
    }
    return height;
}

void solve()
{
}

int main()
{
    solve();
    return 0;
}*/

/* Check if a tree is balanced or not
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = dfs(root->left);
    if (lh == -1)
        return -1;
    int rh = dfs(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;
    return max(lh, rh) + 1;
}

bool isBalanced(TreeNode *root)
{
    return dfs(root) != -1;
}

void solve()
{
}

int main()
{
    solve();
    return 0;
}*/

/* Diameter of a binary tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int diameter(TreeNode *root)
{
    int maxDia = 0;
    height(root, maxDia);
    return maxDia;
}

int height(TreeNode *root, int &maxDia)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left, maxDia);
    int rh = height(root->right, maxDia);
    maxDia = max(maxDia, lh + rh);

    return 1 + max(lh, rh);
}*/

/* Maximum path sum in Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int func(TreeNode *node, int &maxSum)
{
    if (node == NULL)
        return 0;
    int lSum = max(0, func(node->left, maxSum));
    int rSum = max(0, func(node->right, maxSum));
    maxSum = max(lSum + rSum + node->val, maxSum);
    return node->val + max(lSum, rSum);
}

int maxPathSum(TreeNode *root)
{
    int maxSum = 0;
    func(root, maxSum);
    return maxSum;
}

void solve()
{
}

int main()
{
    solve();
    return 0;
}*/

/* Check if two trees are identical
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool areSame(TreeNode *p, TreeNode *q)
{
    if (p == NULL || q == NULL)
    {
        return p == q;
    }
    return (p->val == q->val && areSame(p->left, q->left) && areSame(p->right, q->right));
}*/

/* Spiral Traversal or Zig-Zag Traversal in Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagTraversal(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == NULL)
        return result;

    queue<TreeNode *> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty())
    {
        int siz = q.size();
        vector<int> row(siz);
        for (int i = 0; i < siz; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            int index = leftToRight ? i : (siz - i - 1);
            row[index] = node->val;

            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}*/

/* Boundary Traversal
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isLeaf(TreeNode *node)
{
    return (node->left == NULL && node->right == NULL);
}

void leftBoundary(TreeNode *node, vector<int> &result)
{
    TreeNode *cur = node->left;
    while (cur)
    {
        if (!isLeaf(cur))
            result.push_back(cur->val);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void rightBoundary(TreeNode *node, vector<int> &result)
{
    TreeNode *cur = node->right;
    vector<int> temp;
    while (cur)
    {
        if (!isLeaf(cur))
            temp.push_back(cur->val);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        result.push_back(temp[i]);
    }
}

void leaves(TreeNode *node, vector<int> &result)
{
    if (isLeaf(node))
    {
        result.push_back(node->val);
        return;
    }
    if (node->left)
        leaves(node->left, result);
    if (node->right)
        leaves(node->right, result);
}

vector<int> boundaryOfTree(TreeNode *root)
{
    vector<int> result;
    if (!root)
        return result;
    if (!isLeaf(root))
        result.push_back(root->val);
    leftBoundary(root, result);
    leaves(root, result);
    rightBoundary(root, result);

    return result;
}*/

/* Vertical Traversal
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> verrticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode *cur = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(cur->val);
        if (cur->left)
            q.push({cur->left, {x - 1, y + 1}});
        if (cur->right)
            q.push({cur->right, {x + 1, y + 1}});
    }

    vector<vector<int>> res;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        res.push_back(col);
    }

    return res;
}*/

/* Top view of a Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> topView(TreeNode *root)
{
    vector<int> res;
    if(root==NULL){
        return res;
    }
    queue<pair<TreeNode *, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode *cur = p.first;
        int line = p.second;
        if (mp.find(line) == mp.end())
        {
            mp[line] = cur->val;
        }
        if (cur->left != NULL)
            q.push({cur->left, line - 1});
        if (cur->right != NULL)
            q.push({cur->right, line + 1});
    }

    for (auto it : mp)
    {
        res.push_back(it.second);
    }

    return res;
}*/

/* Bottom view of Tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> topView(TreeNode *root)
{
    vector<int> res;
    if (root == NULL)
    {
        return res;
    }
    queue<pair<TreeNode *, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode *cur = p.first;
        int line = p.second;
        mp[line] = cur->val;
        if (cur->left != NULL)
            q.push({cur->left, line - 1});
        if (cur->right != NULL)
            q.push({cur->right, line + 1});
    }
    for (auto it : mp)
    {
        res.push_back(it.second);
    }
    return res;
}*/

/* Right view of Tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void func(TreeNode *root, int level, vector<int> &res)
{
    if (root == NULL)
        return;
    if (res.size() == level)
        res.push_back(root->val);
    if (root->right != NULL)
        func(root->right, level + 1, res);
    if (root->left != NULL)
        func(root->left, level + 1, res);
}

vector<int> rightView(TreeNode *root)
{
    vector<int> res;
    func(root, 0, res);
    return res;
}*/

/* Check for Symmetrical Tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool func(TreeNode *left, TreeNode *right)
{
    if (left == NULL || right == NULL)
        return left == right;

    return (left->val == right->val && func(left->left, right->right) && func(left->right, right->left));
}

bool isSymmetric(TreeNode *root)
{
    return root == NULL || func(root->left, root->right);
}*/

/* Root to node path in a binary tree; Node is given
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool getPath(TreeNode *root, vector<int> &res, int x)
{
    if (!root)
        return false;

    res.push_back(root->val);

    if (root->val == x)
        return true;
    if (getPath(root->left, res, x) || getPath(root->right, res, x))
        return true;

    res.pop_back();
    return false;
}

vector<int> solve(TreeNode *root, int x)
{
    vector<int> res;
    if (root == NULL)
        return res;
    getPath(root, res, x);
    return res;
}*/

/* Find LCA of two given nodes in a Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        root;
}*/

/* Width of a Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getWidth(TreeNode *root)
{
    if (!root)
        return 0;
    int ans = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        int minPossible = q.front().second;
        int first, last;
        for (int i = 0; i < size; i++)
        {
            int curIdx = q.front().second - minPossible;
            TreeNode *node = q.front().first;
            q.pop();
            if (i == 0)
                first = curIdx;
            if (i == size - 1)
                last = curIdx;
            if (node->left)
                q.push({node->left, curIdx * 2 + 1});
            if (node->right)
                q.push({node->right, curIdx * 2 + 2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}*/



/* Disjoint union
#include <bits/stdc++.h>
using namespace std;

class disjointSet
{
    vector<int> rank, parent;

public:
    disjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
        {
            return;
        }
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u] += 1;
        }
    }
};

void solve()
{
    disjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if(ds.findUPar(3)==ds.findUPar(7)){
        cout<<"same\n";
    }else{
        cout<<"not same\n";
    }
    ds.unionBySize(3,7);
    if(ds.findUPar(3)==ds.findUPar(7)){
        cout<<"same\n";
    }else{
        cout<<"not same\n";
    }
}

int main()
{
    solve();
    return 0;
}*/

/* Topological Ordering --- DFS
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int vis[], stack<int> &st, vector<int> g[])
{
    vis[node] = 1;
    for (auto next : g[node])
    {
        if (!vis[next])
        {
            dfs(next, vis, st, g);
        }
    }
    st.push(node);
}

vector<int> topoSort(int v, vector<int> g[])
{
    int vis[v] = {0};
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, g);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}*/

/* Topological Ordering --- BFS --- Kahn's Algorithm
#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indeg(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indeg[it] += 1;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indeg[it]--;
            if (indeg[it] == 0)
            {
                q.push(it);
            }
        }
    }

    return topo;
}*/

/* Cycle Detection --- BFS --- Kahn's Algo Application
#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int n, vector<int> adj[])
{
    vector<int> inDeg(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            inDeg[it] += 1;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (inDeg[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            inDeg[it]-=1;
            if(inDeg[it]==0){
                q.push(it);
            }
        }
    }

    return !(topo.size()==n);
}*/

/* Dijkstra Algo --- Using Sets
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<int>> adj[], int s)
{
    set<pair<int, int>> st;
    vector<int> dist(n, 1e9);
    st.insert({0, s});
    dist[s] = 0;

    while (!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for (auto it : adj[node])
        {
            int neigh = it[0];
            int weight = it[1];

            if (dis + weight < dist[neigh])
            {
                if (dist[neigh] != 1e9)
                    st.erase({dist[neigh], neigh});
                dist[neigh] = dis + weight;
                st.insert({dist[neigh], neigh});
            }
        }
    }

    return dist;
}*/

/* Prim's Algo --- Minimum Spanning Tree (MST)
#include <bits/stdc++.h>
using namespace std;

int spanningTree(int n, vector<vector<int>> g[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(n + 1, 0);
    pq.push({0, 0}); //{weight, node}
    int sum = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int weight = it.first;
        if (visited[node] == 1)
            continue;

        visited[node] = 1;
        sum += weight;

        for (auto next : g[node])
        {
            int neigh = next[0];
            int neighWeight = next[1];

            if (!visited[neigh])
            {
                pq.push({neighWeight, neigh});
            }
        }
    }
    return sum;
}*/

/* Kruskal's Algo --- MST

int findPar(int u, vector<int> &par)
{
    if (u == par[u])
    {
        return u;
    }

    return par[u] = findPar(par[u], par);
}

void unionFind(int u, int v, vector<int> &par, vector<int> &siz)
{
    int pu = findPar(u, par);
    int pv = findPar(v, par);

    if (pu != pv)
    {
        if (siz[pu] > siz[pv])
        {
            par[pv] = pu;
            siz[pu] += siz[pv];
        }
        else
        {
            par[pu] = pv;
            siz[pv] += siz[pu];
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

int spanningTree(int n, vector<vector<int>> g[])
{
    vector<int> par(n + 1), siz(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < n; i++)
    {
        for (auto it : g[i])
        {
            int node = it[0];
            int weight = it[1];
            int neigh = i;

            edges.push_back({weight, {node, neigh}});
        }
    }

    sort(edges.begin(), edges.end());
    int mstWeight = 0;

    for (auto it : edges)
    {
        int weight = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (findPar(u, par) != findPar(v, par))
        {
            mstWeight += weight;
            unionFind(u, v, par, siz);
        }
    }

    return mstWeight;
}*/

/* Strongly connected components --- SCC --- Kosaraju's Algo --- ONLY FOR DIRECTED GRAPHS
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &visited, stack<int> &st)
{
    visited[node] = 1;

    for (auto next : adj[node])
    {
        if (!visited[next])
        {
            dfs(next, adj, visited, st);
        }
    }

    st.push(node);
}

int kosaraju(int n, vector<int> adj[])
{
    vector<int> visited(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, st);
        }
    }

    vector<int> newAdj[n];
    for (int i = 0; i < n; i++)
    {
        for (auto j : adj[i])
        {
            newAdj[j].push_back(i);
        }
    }
    visited.assign(n, 0);

    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!visited[node])
        {
            scc += 1;
            dfs(node, newAdj, visited, st);
        }
    }

    return scc;
}*/

/* Tarjan's Algo --- Bridges in a graph
#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int> &visited, vector<vector<int>> &g, vector<int> &inTime, vector<int> &lowTime, vector<vector<int>> &ans)
{
    visited[node] = 1;
    inTime[node] = lowTime[node] = timer;
    timer += 1;

    for (auto next : g[node])
    {
        if(next==parent) continue;
        if (!visited[next])
        {
            dfs(next, node, visited, g, inTime, lowTime, ans);
            lowTime[node] = min(lowTime[node], lowTime[next]);
            if (lowTime[next] > inTime[node])
            {
                ans.push_back({next, node});
            }
        }
        else
        {
            lowTime[node] = min(lowTime[node], lowTime[next]);
        }
    }
}

vector<vector<int>> bridges(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> g(n);
    for (auto u : connections)
    {
        g[u[0]].push_back(u[1]);
        g[u[1]].push_back(u[0]);
    }
    vector<int> visited(n, 0);
    vector<int> inTime(n);
    vector<int> lowTime(n);

    vector<vector<int>> ans;
    dfs(0, -1, visited, g, inTime, lowTime, ans);

    return ans;
}*/

/* Articulation Point in a graph
#include <bits/stdc++.h>
using namespace std;

int timer = 0;

void dfs(int node, int parent, vector<int> adj[], vector<int> &visited, vector<int> &inTime, vector<int> &loTime, vector<int> &mark)
{
    visited[node] = 1;
    inTime[node] = loTime[node] = timer;
    timer += 1;
    int child = 0;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!visited[it])
        {
            dfs(it, node, adj, visited, inTime, loTime, mark);
            loTime[node] = min(loTime[node], loTime[it]);
            if (loTime[it] >= inTime[node] && parent != -1)
            {
                mark[node] = 1;
            }
            child += 1;
        }
        else
        {
            loTime[node] = min(loTime[node], inTime[it]);
        }
    }
    if (child > 1 && parent == -1)
    {
        mark[node] = 1;
    }
}

vector<int>
articulationPoint(int n, vector<int> adj[])
{
    vector<int> visited(n, 0);
    vector<int> inTime(n);
    vector<int> loTime(n);
    vector<int> mark(n, 0); // marks articulation points
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1, adj, visited, inTime, loTime, mark);
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (mark[i])
        {
            ans.push_back(i);
        }
    }
    if (ans.size() == 0)
        return {-1};
    return ans;
}*/
