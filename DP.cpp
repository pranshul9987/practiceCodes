/* #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int n;
// int p[100100], h[100100];
// int b, k;
// vector<pair<int, int>> cur;
// int ans = 0;

// void rec(int level)
// {
//     if (level == n)
//     {
//         int totcost = 0;
//         int tothap = 0;
//         for (auto v : cur)
//         {
//             totcost += v.first;
//             tothap += v.second;
//         }
//         if (totcost <= b && cur.size() <= k)
//         {
//             ans = max(ans, tothap);
//         }
//         return;
//     }

//     rec(level + 1);

//     cur.push_back({p[level], h[level]});
//     rec(level + 1);
//     cur.pop_back();
// }

// void solve()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> p[i] >> h[i];
//     }
//     cin >> b >> k;
//     rec(0);
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     solve();

//     return 0;
// }*/

/*#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n;
int p[100100], h[100100];
int b, k;
vector<pair<int, int>> cur;
int ans = 0;

void rec(int level, int totcost, int tothap, int cursize)
{
    if (level == n)
    {

        if (totcost <= b && cursize <= k)
        {
            ans = max(ans, tothap);
        }
        return;
    }

    rec(level + 1, totcost, tothap, cursize);

    rec(level + 1, totcost + p[level], tothap + h[level], cursize + 1);
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> h[i];
    }
    cin >> b >> k;
    rec(0, 0, 0, 0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}*/

/*#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int p[100100], h[100100];
int b, k;
int ans = 0;

int rec(int level, int totcost, int cursize)
{
    if (level == n)
    {
        return 0;
    }

    ans = rec(level + 1, totcost, cursize);
    if(cursize<k){
        ans=max(rec(level + 1, totcost + p[level], cursize + 1)+h[level], ans);
    }

}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> h[i];
    }
    cin >> b >> k;
    cout<<rec(0, 0, 0)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
*/

/*#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int p[100100], h[100100];
int b, k;
int ans;

int dp[101][1001][101];

int rec(int level, int spent, int taken){
    if(level==n){
        return 0;
    }
    if(dp[level][spent][taken]!=-1){
        return dp[level][spent][taken];
    }
    ans=rec(level+1, spent, taken);

    if(spent+p[level]<=b && taken+1<=k){
        ans=max(ans, rec(level+1, spent+p[level], taken+1)+h[level]);
    }

    dp[level][spent][taken]=ans;
    return ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> h[i];
    }
    memset(dp, -1, sizeof(dp));
    cin >> b >> k;
    cout<<rec(0,0,0)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}*/

/*#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int p[100100], h[100100];
int b, k;

int dp[101][1001][101];

int rec(int level, int spent, int taken){
    //Pruning

    //Base case code
    if(level==n){
        return 0;
    }

    //Cache check
    if(dp[level][spent][taken]!=-1){
        return dp[level][spent][taken];
    }
    //Compute with transition
    int ans=rec(level+1, spent, taken);

    if(spent+p[level]<=b && taken+1<=k){
        ans=max(ans, rec(level+1, spent+p[level], taken+1)+h[level]);
    }

    //Save and return
    return dp[level][spent][taken] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> h[i];
    }
    memset(dp, -1, sizeof(dp));
    cin >> b >> k;
    cout<<rec(0,0,0)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}*/

/*#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, q;
int numbers[100100];

int saved[101][100100];
int dp[101][100100];

bool rec(int level, int sumNeeded){
    //Pruning

    //Base check code
    if(level==n){
        if(sumNeeded==0) return true;
        return false;
    }
    //Computation with transition
    if(saved[level][sumNeeded]!=0){
        return dp[level][sumNeeded];
    }

    dp[level][sumNeeded] = rec(level+1, sumNeeded) || rec(level+1, sumNeeded-numbers[level]);

    // Save and return
    saved[level][sumNeeded]=1;
    return dp[level][sumNeeded];

}

void solve(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>numbers[i];
    }
    memset(dp, -1, sizeof(dp));
    memset(saved, 0, sizeof(saved));
    cin>>q;
    while(q--){
        int sumReqd;
        cin>>sumReqd;
        if(rec(0, sumReqd)) cout<<"YES\n";
        else cout<<"NO\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
*/

/*Recursive code:
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MP make_pair

int n, k;
string str;
int arr[100100];
map<char, int> mp;
map<int, char> rmp;

int dp[100100][3][101];
int back[100100][3][101];

int result(int move, int compare){
    return compare==(move+1)%3;

}
int rec(int level, int last, int ch_left){
    if(ch_left<0) return -1e9;
    if(level==n){
        return 0;
    }
    if(dp[level][last][ch_left]!=-1) return dp[level][last][ch_left];

    int ans=0;
    back[level][last][ch_left]=-1;
    for(int x=0; x<3; x++){
        ans=max(ans, result(x, arr[level])+rec(level+1, x, ch_left-((x==last)?0:1)));
        if(ans==result(x, arr[level])+rec(level+1, x, ch_left-((x==last)?0:1))){
            back[level][last][ch_left]=x;
        }
    }
    return dp[level][last][ch_left]=ans;
}

string final_ans;
void generate(int level, int last, int ch_left){
    if(level==n) return;
    int x=back[level][last][ch_left];
    final_ans+=rmp[x];
    generate(level+1, x, ch_left-((x==last)?0:1));
}

void solve(){
    cin>>n>>k;
    string str;
    for(int i=0; i<n; i++){
        arr[i]=mp[str[i]];
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<3; j++){
            for(int x=0; x<=k; x++){
                dp[i][j][x] = -1;
            }
        }
    }
    pair<int, int> ans=max(MP(rec(0,0,k), 0), MP(rec(0,1,k), 1), MP(rec(0,2,k), 2));
    cout<<ans.first<<'\n';
    generate(0, ans.second, k);
    cout<<final_ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    mp['P'] = 0;
    mp['H'] = 1;
    mp['S'] = 2;
    rmp[0] = 'P';
    rmp[1] = 'H';
    rmp[2] = 'S';

    solve();

    return 0;
} */

/*Iterative code:
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MP make_pair

int n, k;
string str;
int arr[100100];
map<char, int> mp;
map<int, char> rmp;

int dp[100100][3][101];
int back[100100][3][101];

int result(int move, int compare){
    return compare==(move+1)%3;
}

void solve(){
    cin>>n>>k;
    string str;
    for(int i=0; i<n; i++){
        arr[i]=mp[str[i]];
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<3; j++){
            for(int x=0; x<=k; x++){
                dp[i][j][x] = -1;
            }
        }
    }

    for(int level=n; level>=0; level--){
        for(int last=0; last<3; last++){
            for(int ch_left=0; ch_left<=k; ch_left++){
                if(level==n){
                    dp[level][last][ch_left] = 0;
                }
                int ans=0;
                for(int x=0; x<3; x++){
                    if(ch_left-((x==last)?0:1)>=0){
                        ans=max(ans, result(x, arr[level])+dp[level][last][ch_left-((x==last)?0:1)]);
                    }
                }
                dp[level][last][ch_left] = ans;
            }
        }
    }

    int ans=max({dp[0][0][k], dp[0][1][k], dp[0][2][k]});
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    mp['P'] = 0;
    mp['H'] = 1;
    mp['S'] = 2;
    rmp[0] = 'P';
    rmp[1] = 'H';
    rmp[2] = 'S';

    solve();

    return 0;
}
*/

/*#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int x[101], y[101];

int dp[101][101];

int sq(int a)
{
    return a * a;
}

int dist(int i, int j)
{
    return sq(x[i] - x[j]) + sq(y[i] - y[j]);
}

int rec(int l, int r)
{
    if (r - l < 3)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    int ans = 1e9;
    ans = min(ans, rec(l + 1, r) + dist(r,l+1));
    ans = min(ans, rec(l, r - 1) + dist(r - 1,l));
    for (int x = l + 2; x < r-1; x++)
    {
        ans = min(ans, dist(l, x) + dist(x, r) + rec(l, x) + rec(x, r));
    }

    return dp[l][r] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, n - 1) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();

    return 0;
}*/

/* FORM-2 ----> Find the maximum sum subarray in a given array.
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int arr[100100];

int dp[100100];
bool saved[100100];
int rec(int level)
{
    if (level < 0)
    {
        return INT_MIN;
    }

    if (level == 0)
        return arr[0];

    if (saved[level] != 0)
    {
        return dp[level];
    }

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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}*/

/* Kadane's algorithm - O(n) solution for the maximum sum subarray
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans=INT_MIN, sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        ans=max(ans, sum);
        if(sum<0) sum=0;
    }
    cout<<ans<<'\n';
}*/

/* FORM-3 ----> Find the longest common subsequence in two given strings
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n1, n2;
string s1, s2;

int dp[101][101];
string soln;

int rec(int l1, int l2)
{
    if (l1 == n1 || l2 == n2)
    {
        return 0;
    }

    if (dp[l1][l2] != -1)
    {
        return dp[l1][l2];
    }

    int ans = 0;
    if (s1[l1] == s2[l2])
    {
        ans = rec(l1 + 1, l2 + 1) + 1;
    }
    else
    {
        ans = max(rec(l1 + 1, l2), rec(l1, l2 + 1));
    }
    return dp[l1][l2] = ans;
}

void solve()
{
    cin >> s1 >> s2;
    n1 = s1.length();
    n2 = s2.length();
    memset(dp, -1, sizeof(dp));
    int ans = rec(0, 0);
    cout << ans << '\t' << soln << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}*/

/* FORM-4 ----> Find the max possible score of player 1 in the game
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int arr[100100];

int dp[2001][2001];
int saved[2001][2001];

int rec(int l, int r){
    if(l>r){
        return 0;
    }

    if(saved[l][r]!=0) return dp[l][r];

    int ans=max(arr[l]-rec(l+1, r), arr[r]-rec(l,r-1));

    saved[l][r]=1;
    return dp[l][r] = ans;
}

void solve(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    memset(dp, -1, sizeof(dp));
    memset(saved, 0, sizeof(saved));
    int ans=0;
    ans=rec(0,n-1);
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}*/

/* FORM-5 ----> Find the winner in the game for 2 players. Given a number X, and a set of numbers which you can subtract from X in your move. The player who can not make a move will lose. Player can't make a move if after making the move the value of X becomes negative.
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int x, n;
vector<int> arr={1,3,4};

int dp[100100];

int rec(int level){
    if(level==0) return 0;

    if(dp[level]!=-1) return dp[level];

    dp[level]=0;
    bool flag=false;
    for(auto i:arr){
        if(i<=level && rec(level-i)==0){
            flag=true;
            break;
        }
    }
    if(flag) dp[level]=1;

    return dp[level];
}

void solve(){
    // cin>>x>>n;
    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }

    memset(dp, -1, sizeof(dp));
    int ans=rec(x);
    for(int i=0; i<20; i++){
        cout<<"For X = "<<i<<" ---> ";
        if(rec(i)) cout<<"Player 1 wins\n";
        else cout<<"Player 2 wins\n";
    }
    // if(ans) cout<<"Player 1 wins\n";
    // else cout<<"Player 2 wins\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}*/

/* https://atcoder.jp/contests/dp/tasks/dp_a
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
vector<ll> arr(100100);

ll dp[100100];

int rec(ll level)
{
    if (level == n)
        return 0;

    if (dp[level] != -1)
        return dp[level];

    int ans = 0;
    if (level == n - 2)
    {
        ans = abs(arr[level] - arr[level + 1]);
    }
    else if (level == n - 1)
    {
        ans = 0;
    }
    else
    {
        ans = min(rec(level + 1) + abs(arr[level] - arr[level + 1]), (rec(level + 2) + abs(arr[level] - arr[level + 2])));
    }

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
    ll ans = rec(0);
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

/* https://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k;
vector<ll> arr(100100);

ll dp[100100];

int rec(ll level)
{
    if (level >= n - 1)
        return 0;

    if (dp[level] != -1)
        return dp[level];

    ll ans = abs(arr[level] - arr[level + 1]) + rec(level + 1);
    for (int i = 2; i <= k; i++)
    {
        if (level + i <= n - 1)
        {
            ans = min(ans, abs(arr[level] - arr[level + i]) + rec(level + i));
        }
    }

    return dp[level] = ans;
}

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    ll ans = rec(0);
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

/* https://atcoder.jp/contests/dp/tasks/dp_c
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int a[100100], b[100100], c[100100];

ll dp[100100][3];

int rec(int level, int last){
    if(level==n) return 0;

    if(dp[level][last]!=-1) return dp[level][last];
    int ans=0;
    if(last==0){
        ans = max(a[level]+rec(level+1, 1), a[level]+rec(level+1, 2));
    }else if(last==1){
        ans = max(b[level]+rec(level+1, 0), b[level]+rec(level+1, 2));
    }else if(last==2){
        ans = max(c[level]+rec(level+1, 0), c[level]+rec(level+1, 1));
    }

    return dp[level][last] = ans;
}

void solve(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    memset(dp, -1, sizeof(dp));

    int ans=0;
    ans = max({rec(0, 0), rec(0, 1), rec(0, 2)});
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}*/

/* https://atcoder.jp/contests/dp/tasks/dp_d
#include<bits/stdc++.h>
using namespace std;
#define ll long long


int n, w;
ll weight[100100], value[100100];

ll dp[101][100100];

ll rec(int level, int weightPossible){
    if(level==n){
        return 0;
    }

    if(dp[level][weightPossible]!=-1) return dp[level][weightPossible];

    ll ans=0;
    ans = rec(level+1, weightPossible);
    if(weightPossible-weight[level]>=0){
        ans = max(ans, rec(level+1, weightPossible-weight[level])+value[level]);
    }

    return dp[level][weightPossible] = ans;
}

void solve(){
    cin>>n>>w;
    for(int i=0; i<n; i++){
        cin>>weight[i]>>value[i];
    }
    memset(dp, -1, sizeof(dp));
    ll ans=rec(0, w);
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}*/

/* https://atcoder.jp/contests/dp/tasks/dp_e
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll w;
vector<ll> weights(110), values(110);

ll dp[101][100100];

ll rec(int level, int val)
{
    if (val == 0)
        return 0;
    if (level == n)
        return 1e10;

    if (dp[level][val] != -1)
        return dp[level][val];

    ll ans = rec(level + 1, val);
    if (val - values[level] >= 0)
    {
        ans = min(ans, rec(level + 1, val - values[level]) + weights[level]);
    }

    return dp[level][val] = ans;
}

void solve()
{
    cin >> n >> w;
    ll valSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i] >> values[i];
        valSum += values[i];
    }

    memset(dp, -1, sizeof(dp));

    ll ans;
    for (ll val = valSum; val >= 0; val--)
    {
        if (rec(0, val) <= w)
        {
            ans = val;
            break;
        }
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
}
*/

/* https://atcoder.jp/contests/dp/tasks/dp_i
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int n;
ld probs[3001];

double dp[3001][3001];

ld rec(int level, int headNeeded)
{
    if (level == n)
    {
        if (headNeeded == 0)
            return 1;
        return 0;
    }
    if (headNeeded == 0)
        return rec(level + 1, headNeeded) * (1 - probs[level]);
    if (dp[level][headNeeded] != -1.0)
        return dp[level][headNeeded];

    ld ans = rec(level + 1, headNeeded) * (1 - probs[level]);

    if (headNeeded >= 1)
    {
        ans += rec(level + 1, headNeeded - 1) * (probs[level]);
    }

    return dp[level][headNeeded] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> probs[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1.0;
        }
    }

    ld ans = 0;
    for (int i = n / 2 + 1; i <= n; i++)
    {
        ans += rec(0, i);
    }

    cout <<setprecision(10)<< ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}*/

/* Find the number of N length binary strings with no "0100" substring present
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;

int dp[10010][4];

int rec(int level, int state){
    if(level==n){
        return 1;
    }

    if(dp[level][state]!=-1) return dp[level][state];

    int ans=0;

    if(state==0){
        ans+=rec(level+1, 0);
        ans+=rec(level+1, 1);
    }else if(state==1){
        ans+=rec(level+1, 2);
        ans+=rec(level+1, 1);
    }else if(state==2){
        ans+=rec(level+1, 0);
        ans+=rec(level+1, 3);
    }else if(state==3){
        ans+=rec(level+1, 2);
    }

    return dp[level][state] = ans;
}

void solve(){
    cin>>n;
    memset(dp, -1, sizeof(dp));
    int ans=0;
    ans=rec(0, 0);
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}*/

/* 2 players play a game, 2 piles of stones are given. In a move, a player can remove any number of stones from either of the piles, or remove equal number of stones from both the piles. The player loses who can not make a move. Initially the piles have x and y number of stones, and player 1 makes the first move.
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int X, Y;

int dp[1001][1001];

int rec(int x, int y)
{
    if (x == 0 && y == 0)
    {
        return 0;
    }

    if (dp[x][y] != -1)
        return dp[x][y];

    int ans = 0;

    for (int i = 1; i <= y; i++)
    {
        if (rec(x, y - i) == 0)
        {
            ans = 1;
            return dp[x][y] = ans;
        }
    }
    for (int i = 1; i <= x; i++)
    {
        if (rec(x - i, y) == 0)
        {
            ans = 1;
            return dp[x][y] = ans;
        }
    }
    for (int i = 1; i <= min(x, y); i++)
    {
        if (rec(x - i, y - i) == 0)
        {
            ans = 1;
            return dp[x][y] = ans;
        }
    }

    return dp[x][y] = ans;
}

void solve()
{
    cin >> X >> Y;
    memset(dp, -1, sizeof(dp));
    int ans = rec(X, Y);
    if (ans)
        cout << "Player-1 wins\n";
    else
        cout << "Player-2 wins\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}*/

/* Given a number N, in how many ways can it be broken down into sum of positive numbers in range 1-N, numbers can be repeated any number of times
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int arr[1001];

int dp[1001][1001];
vector<int> soln;

int rec(int level, int sumRemaining){
    if(sumRemaining==0){
        // cout<<"level = "<<level<<" sumRemaining = "<<sumRemaining<<'\n';
        for(auto val:soln){
            cout<<val<<'\t';
        }
        cout<<'\n';
        return 1;
    }
    if(level==n){
        return 0;
    }

    if(dp[level][sumRemaining]!=-1) return dp[level][sumRemaining];

    int ans=0;
    for(int i=level; i<n; i++){
        if(sumRemaining-arr[i]>=0){
            // cout<<"level = "<<level<<" i = "<<i<<" sumRemaining = "<<sumRemaining<<'\n';
            soln.push_back(arr[i]);
            ans+=rec(i, sumRemaining-arr[i]);
            soln.pop_back();
        }else{
            break;
        }
    }

    return dp[level][sumRemaining]=ans;
}

void solve(){
    cin>>n;
    for(int i=0; i<n; i++){
        arr[i]=i+1;
    }
    memset(dp, -1, sizeof(dp));
    int ans=0;
    for(int i=0; i<n; i++){
        soln.push_back(arr[i]);
        ans+=(rec(i, n-arr[i]));
        soln.pop_back();
    }
    cout<<"\nTotal number of solutions: "<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}*/

/* In a stone-paper-hand game, you are given the sequence of N move that are made by the computer. You have to maximise your overall score, the constraint being that you can only change your object K number of times.
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
string arr;
map<int, char> mp;
map<char, int> rmp;
int dp[100100][3][101];

int result(int a, int b){
    if((a==1 && b==3) || (a==2 && b==1) || (a==3 && b==2)) return 1;
    return 0;
}

int rec(int level, int last, int ch_left)
{

    if (level == n)
    {
        return 0;
    }

    if (dp[level][last][ch_left] != -1){
        return dp[level][last][ch_left];
    }

    int ans=0;
    for(int i=1; i<=3; i++){
        ans=max(ans, result(rmp[arr[level]], i)+rec(level+1, i, ch_left-((i==last)?0:1)));
    }
    return dp[level][last][ch_left] = ans;
}

void solve()
{
    cin >> n >> k;
    cin >> arr;

    for(int i=0; i<=n; i++){
        for(int j=0; j<3; j++){
            for(int x=0; x<=k; x++){
                dp[i][j][x]=-1;
            }
        }
    }
    mp[1] = 'S'; // Scissor
    mp[2] = 'P'; // Paper
    mp[3] = 'H'; // Hand
    rmp['S'] = 1;
    rmp['P'] = 2;
    rmp['H'] = 3;

    int ans = max({rec(0, 1, k), rec(0, 2, k), rec(0, 3, k)});

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

/* FORM-4 type problem ---> Given a N sided polygon, we have to calculate the minimum cost of triangulation of the polygon, if the cost of creating any diagonal is equal to the square of the length of that diagonal
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int x[101], y[101];

int dp[101][101];

int sq(int x)
{
    return x * x;
}

int dist(int i, int j)
{
    return sq(x[i] - x[j]) + sq(y[i] - y[j]);
}

int rec(int l, int r)
{
    if (r - l < 3)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    int ans = 1e9;

    ans = min(ans, rec(l + 1, r) + dist(l + 1, r));
    ans = min(ans, rec(l, r - 1) + dist(l, r - 1));

    for (int x = l + 2; x <= r - 2; x++)
    {
        ans = min(ans, rec(l, x) + rec(x, r) + dist(l, x) + dist(x, r));
    }

    return dp[l][r] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    memset(dp, -1, sizeof(dp));
    int ans = rec(0, n - 1);
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

/* FORM-4 type problem ---> Given N bags, with a value alloted to each of them. In a move, we can replace 2 adjacent bags, of values X and Y, with a single bag, whose value is (X+Y)%100, and gain a benefit of X*Y. Find the max possible benefit if all N bags are reduced to a single bag after N-1 steps.
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int values[510], pSum[510];

int dp[510][510];

int rec(int l, int r)
{
    if (l >= r){
        return 0;
    }

    if (dp[l][r] != -1){
        return dp[l][r];
    }

    int ans = 0;

    for (int mid = l; mid < r; mid++)
    {
        ans = max(ans, rec(l, mid) + rec(mid + 1, r) + ((pSum[mid] - pSum[l - 1] + 100) % 100) * ((pSum[r] - pSum[mid] + 100) % 100));
    }
    return dp[l][r] = ans;
}

void solve(){
    cin>>n;
    values[0]=0;
    pSum[0]=0;
    for(int i=1; i<=n; i++){
        cin>>values[i];
        pSum[i]=pSum[i-1]+values[i];
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            dp[i][j]=-1;
        }
    }
    int ans=rec(1, n);
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}*/

/* FORM-2 type problem ---> Given a NxM grid, with some cells blocked. We have to find the total number of ways to reach the last cell, beginning from first cell.
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int arr[1010][1010];

int dp[1010][1010];

int rec(int x, int y)
{
    if (x == n - 1 && y == m - 1)
    {
        if(arr[x][y]==0) return 0;
        return 1;
    }

    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }

    int ans = 0;
    if (arr[x][y] == 0)
    {
        return dp[x][y] = ans;
    }
    if (x < n - 1)
    {
        if (arr[x + 1][y] != 0)
        {
            ans += rec(x + 1, y);
        }
    }
    if (y < m - 1)
    {
        if (arr[x][y + 1] != 0)
        {
            ans += rec(x, y + 1);
        }
    }

    return dp[x][y] = ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = rec(0, 0);
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

/* Same problem as previous, but with no cells blocked, and each cell has been alloted some weight. We have to maximize the sum to reach the last cell. Only moves allowed are right and down.
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int arr[1010][1010];

int dp[1010][1010];

int rec(int x, int y)
{
    if (x == n - 1 && y == m - 1)
    {
        return 0;
    }

    if (dp[x][y] != -1e9)
    {
        return dp[x][y];
    }

    int ans = 0;
    int temp = 0;
    if (x < n - 1)
    {
        temp = max(temp, rec(x + 1, y)+arr[x+1][y]);
    }
    if (y < m - 1)
    {
        temp = max(temp, rec(x, y + 1)+arr[x][y+1]);
    }
    ans = temp;
    return dp[x][y] = ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = -1e9;
        }
    }
    int ans = arr[0][0] + rec(0, 0);
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

/* Given a N*M grid of 0s and 1s. Find the area of the largest square containing only 1s.
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int arr[1010][1010];

int dp[1010][1010];

int rec(int i, int j)
{
    if(i<0 || j<0){
        return 0;
    }

    if (arr[i][j] == 0)
        return dp[i][j] = 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 1+min({rec(i-1, j), rec(i, j-1), rec(i-1, j-1)});
    return dp[i][j] = ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, rec(i, j));
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}*/

/* CHERRY-PICKUP PROBLEM ---> Given a N*M grid with each cell having some value. You have to go to the last cell of the grid, beginning from the first, and return back to the first cell. Goal is to maximize the sum of the values of the cells visited. CONDITION --> Even if a cell is visited twice, it's value will be considered once only.

    METHOD-1 ---> Consider 2 men starting from the first cell, moving towards the last cell. We add the values of all the cells they visit in the answer, but in case they both visit the same cell (ans this always happens at the same time, THINK), then we'll add the cell value only once and not twice.

    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long

    int n, m;
    int arr[1010][1010];

    int dp[101][101][101][101];

    int rec(int l1, int r1, int l2, int r2)
    {
        if (l1 > n - 1 || r1 > m - 1 || l2 > n - 1 || r2 > m - 1)
        {
            return -1e9;
        }

        if (l1 == n - 1 && r1 == m - 1 && l2 == n - 1 && r2 == m - 1)
        {
            return arr[l1][r1];
        }

        if (dp[l1][r1][l2][r2] != -1) // Considering all the values of the grid are positive, if not, it'll be -1e18 or similar instead of -1.
            return dp[l1][r1][l2][r2];

        int ans = (l1 == l2 && r1 == r2) ? arr[l1][r2] : arr[l1][r1] + arr[l2][r2];

        ans = ans + max({rec(l1 + 1, r1, l2 + 1, r2), rec(l1, r1 + 1, l2 + 1, r2), rec(l1 + 1, r1, l2, r2 + 1), rec(l1, r1 + 1, l2, r2 + 1)});

        return dp[l1][r1][l2][r2] = ans;
    }

    void solve()
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    for (int l = 0; l <= m; l++)
                    {
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }

        int ans = rec(0, 0, 0, 0);
        cout << ans << '\n';
    }

    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        solve();

        return 0;
    }


    METHOD-2 ---> The same approach, but instead of having 4 states in the DP, take only 3, say l1, r1, l2. And since l1+r1=l2+r2, for each state we have r2=l1+r1-l2, and hence we don't need the fourth state.
    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long

    int n, m;
    int arr[1010][1010];

    int dp[101][101][101];

    int rec(int l1, int r1, int l2)
    {
        int r2 = l1 + r1 - l2;
        if (l1 > n - 1 || r1 > m - 1 || l2 > n - 1 || r2 > m - 1)
        {
            return -1e9;
        }

        if (l1 == n - 1 && r1 == m - 1 && l2 == n - 1 && r2 == m - 1)
        {
            return arr[l1][r1];
        }

        if (dp[l1][r1][l2] != -1) // Considering all the values of the grid are positive, if not, it'll be -1e18 or similar instead of -1.
            return dp[l1][r1][l2];

        int ans = (l1 == l2 && r1 == r2) ? arr[l1][r2] : arr[l1][r1] + arr[l2][r2];

        ans = ans + max({rec(l1 + 1, r1, l2 + 1), rec(l1, r1 + 1, l2 + 1), rec(l1 + 1, r1, l2), rec(l1, r1 + 1, l2)});

        return dp[l1][r1][l2] = ans;
    }

    void solve()
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }

        int ans = rec(0, 0, 0);
        cout << ans << '\n';
    }

    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        solve();

        return 0;
    }

*/

/* Given a N size array, find exactly K disjoint subarrays such that the sum of elements of the K subarrays is maximum.
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
int arr[1010];
int pSum[1010];
int dp[1010][1010];
bool saved[1010][1010];

int rec(int level, int k)
{
    if (level < 0)
    {
        if (k == 0)
        {
            return 0;
        }
        return -1e9;
    }



    if (saved[level][k])
    {
        return dp[level][k];
    }

    int ans=rec(level-1, k);
    for(int j=0; j<=level+1; j++){
        ans=max(ans, rec(level-j,k-1)+pSum[level+1]-pSum[level-j+1]);
    }
    saved[level][k]=1;
    return dp[level][k]=ans;
}

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pSum[0]=0;
    for(int i=1; i<=n; i++){
        pSum[i]=pSum[i-1]+arr[i-1];
    }
    memset(saved, 0, sizeof(saved));
    int ans = rec(n - 1, k);
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

/* Given a N*M grid, find the max possible sum of elements of any subgrid.
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10010][10010];

int getMaxSum(vector<int> &rowSum) // Using Kadane's Algorithm
{
    int ans = INT_MIN, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += rowSum[i];
        ans = max(sum, ans);
        if (sum < 0)
            sum = 0;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    if (m <= n)
    {
        for (int c1 = 0; c1 < m; c1++)
        {
            vector<int> rowSum(n, 0);
            for (int c2 = c1; c2 < m; c2++)
            {
                for (int i = 0; i < n; i++)
                {
                    rowSum[i] += arr[i][c2];
                }
                ans = max(ans, getMaxSum(rowSum));
            }
        }
    }
    else
    {
        for (int r1 = 0; r1 < n; r1++)
        {
            vector<int> colSum(n, 0);
            for (int r2 = r1; r2 < n; r2++)
            {
                for (int i = 0; i < m; i++)
                {
                    colSum[i] += arr[r2][i];
                }
                ans = max(ans, getMaxSum(colSum));
            }
        }
    }

    cout << ans << '\n';

    return 0;
}*/

/* Given a N*M grid with 1s and 0s, find the largest subgrid containing 1s only. Solution approach: Consider the problem like finding the largest area rectangle in a histogram, traverse through the grid along the columns, with current column as the base for histogram, find the largest possible area of a 1s rectangle. This solution approach in O(N*M). Written for m<=n, similar portion has to be added for case with n<m.
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int arr[1010][1010];
vector<int> oneCount(1010, 0);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    if (m <= n)
    {
        for (int col = 0; col < m; col++)
        {
            cout << "Column: " << col << '\n';
            for (int row = 0; row < n; row++)
            {
                if (arr[row][col] == 0)
                    oneCount[row] = 0;
                else
                    oneCount[row] += 1;
            }

            // cout << "oneCount vector:\t";
            // for (int i = 0; i < n; i++)
            //     cout << oneCount[i] << '\t';
            // cout << '\n';

            // prevSmallerIdx will store the index of the previous smaller element (nextSmallerIdx stores the index of the next smaller element) than the current element
            vector<int> prevSmallerIdx, nextSmallerIdx(n);
            stack<pair<int, int>> prevStack;
            stack<pair<int, int>> nextStack;

            // Filling up prevSmallerIdx vector
            for (int row = 0; row < n; row++)
            {
                while (!prevStack.empty())
                {
                    if (prevStack.top().first < oneCount[row])
                    {
                        prevSmallerIdx.push_back(prevStack.top().second);
                        break;
                    }
                    else
                    {
                        prevStack.pop();
                    }
                }
                if (prevStack.empty())
                {
                    prevSmallerIdx.push_back(-1);
                }
                prevStack.push({oneCount[row], row});
            }

            // cout << "prevSmallerIdx vector:\t";
            // for (int i = 0; i < n; i++)
            //     cout << prevSmallerIdx[i] << '\t';
            // cout << '\n';

            // Filling up nextSmallerIdx vector
            for (int row = 0; row < n; row++)
            {
                while (!nextStack.empty() && nextStack.top().first > oneCount[row])
                {
                    nextSmallerIdx[nextStack.top().second] = row;
                    nextStack.pop();
                }
                nextStack.push({oneCount[row], row});
            }
            while (!nextStack.empty())
            {
                nextSmallerIdx[nextStack.top().second] = n;
                nextStack.pop();
            }

            // cout << "nextSmallerIdx vector:\t";
            // for (int i=0; i<n; i++)
            //     cout << nextSmallerIdx[i] << '\t';
            // cout << '\n';

            for (int row = 0; row < n; row++)
            {
                ans = max(ans, (oneCount[row] * (nextSmallerIdx[row] - prevSmallerIdx[row] - 1)));
            }
        }
        cout << ans << '\n';
    }

    return 0;
}*/

/* Given a string S of length N. Each character is assigned a cost of removing it. Find the minimum cost for removing the characters such that it does not contain any subsequence "hard".
#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;
string t;
int n, m;
int arr[10010];
int dp[10010][1010];

int rec(int idx1, int idx2)
{
    cout<<"idx1 = "<<idx1<<" idx2 = "<<idx2<<'\n';
    if (idx1 == n && idx2!=m)
    {
        return 0;
    }
    if (idx2 == m)
    {
        return 1e9;
    }

    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    int ans = 1e9;
    if (s[idx1] == t[idx2])
    {
        ans = min({ans, rec(idx1 + 1, idx2) + arr[idx1], rec(idx1 + 1, idx2 + 1)});
    }
    else
    {
        ans = rec(idx1 + 1, idx2);
    }
    return dp[idx1][idx2] = ans;
}

void solve()
{
    cin >> s >> t;
    n = s.size();
    m = t.size();

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = -1;
        }
    }

    int ans = rec(0, 0);
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

/* You are given a string S consisting of and ')' characters. You have to find the longest substring that is a regular bracket sequence. You also have to find  he number of such substrings. A bracket sequence is called regular if by inserting '+' and '1' into it we can get a correct mathematical expression. Youu have to print the length of longet such substring and the number of longest substrings present.
#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;
int n;
int dp[100100];
int countNum = 0, maxLen = 0;

int rec(int level)
{
    if (level < 0){
        return 0;
    }

    if (level == n){
        return 0;
    }

    if (s[level] == '(')
    {
        return dp[level] = 0;
    }

    if (dp[level] != -1)
    {
        return dp[level];
    }

    int ans = 0;

    if (level > 0)
    {
        if (s[level - 1] == '(')
        {
            ans += 2;
            ans += rec(level - 2);
        }
        else
        {
            int temp = rec(level - 1);
            if ((level - temp - 1 >= 0) && s[level - temp - 1] == '(')
            {
                ans += 2 + rec(level - 1);
                ans += rec(level - temp - 2);
            }
        }
    }
    int temp=maxLen;
    maxLen = max(maxLen, ans);
    if(temp==maxLen && ans==maxLen){
        countNum+=1;
    }else{
        countNum=1;
    }
    return dp[level] = ans;
}

void solve()
{
    cin >> s;
    n = s.size();
    for(int i=0; i<=n; i++){
        dp[i]=-1;
    }

    int ans=0;
    for(int i=0; i<n; i++){
        ans=max(ans, rec(i));
    }
    if(maxLen!=0){
        cout<<maxLen<<"\t"<<countNum<<'\n';
    }else{
        cout<<"0\t1\n";
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

/* Given N1 green and N2 red marbles. FInd the number of arrangements for them in a line so that no K1 green and no K2 red marbles are placed consecutively.
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, n1, n2, k1, k2;

int dp[101][101][20][20];

int rec(int level1, int level2, int newk1, int newk2)
{
    if (level1 + level2 == 0)
    {
        return 1;
    }

    if (dp[level1][level2][newk1][newk2] != -1)
        return dp[level1][level2][newk1][newk2];

    int ans = 0;
    if (newk1 > 0)
    {
        if(level1!=0)
            ans += rec(level1-1, level2, newk1 - 1, k2);
    }
    if (newk2 > 0)
    {
        if(level2!=0)
            ans += rec(level1, level2-1, k1, newk2 - 1);
    }

    return dp[level1][level2][newk1][newk2] = ans;
}

void solve()
{
    cin >> n1 >> n2 >> k1 >> k2;
    n = n1 + n2;
    memset(dp, -1, sizeof(dp));

    cout << rec(n1, n2, k1, k2) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}*/

/* You are given an array of colored gemstones. In one second, you can remove exactly one continuous substring of colored gemstones that is a palindrome. You have to find the minimum number of seconds needed to destroy all the gemstones.
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1010];

int dp[1010][1010];

int rec(int start, int last)
{
    if(last>=n){
        return 1e9;
    }
    if(start>last){
        return dp[start][last]=1e9;
    }
    if(start==last){
        return dp[start][last]=1;
    }
    if (last == 0)
    {
        return dp[start][last] = 1;
    }
    if (dp[start][last] != -1)
    {
        return dp[start][last];
    }

    int ans=1+rec(start+1, last);

    if(arr[start]==arr[start+1]){
        ans=min(ans, 1+rec(start+2, last));
    }
    for(int k=start+2; k<=last; k++){
        if(arr[start]==arr[k]){
            ans=min(ans, rec(start+1, k-1)+rec(k+1, last));
        }
    }

    return dp[start][last]=ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            dp[i][j]=-1;
        }
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, rec(0, i));
    }

    cout << dp[0][n-1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}*/

/* LIS - Find and print the longest increasing subsequence of a given array of integers.
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100100];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> positions(n);
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        if (temp.empty() || arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            positions[i] = temp.size() - 1;
        }
        else
        {
            auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
            *it = arr[i];
            positions[i] = it - temp.begin();
        }
    }

    vector<int> ans;
    int check = temp.size() - 1;
    for (int i = positions.size() - 1; i >= 0; i--)
    {
        if (positions[i] == check)
        {
            ans.push_back(arr[i]);
            check--;
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto soln : ans)
        cout << soln << '\t';
    cout << '\n';
}

int main()
{
    solve();

    return 0;
}*/

// LDS - Longest Decreasing Subsequence of a given array of integers is the reverse of the LIS of the reverse of the array, that is, rev(LIS(rev(arr))).

/* LNDS - Find and print the longest non-decreasing subsequence of a given array of integers.
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100100];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> positions(n);
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        if (temp.empty() || arr[i] >= temp.back())
        {
            temp.push_back(arr[i]);
            positions[i] = temp.size() - 1;
        }
        else
        {
            auto it = upper_bound(temp.begin(), temp.end(), arr[i]);
            *it = arr[i];
            positions[i] = it - temp.begin();
        }
    }

    vector<int> ans;
    int check = temp.size() - 1;
    for (int i = positions.size() - 1; i >= 0; i--)
    {
        if (positions[i] == check)
        {
            ans.push_back(arr[i]);
            check--;
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto soln : ans)
        cout << soln << '\t';
    cout << '\n';
}

int main()
{
    solve();

    return 0;
}*/

/* LBS - Find the LENGTH of the Longest Bitonic Subsequence of a given array of integers. This works in O(N^2), since here we are able to print the LBS also. There exists a solution in O(NlogN), but we can only find the length of the LBS, and not the LBS itself. To find the length of the LBS, for each index from 0 to N-1, find the length of LIS of the array and the LNDS of the reverse of the array. The answer will be the maximum of (LIS+LDS-1) across all the i's.
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1001];

int dp[1001][2];
pair<int, int> back[1001][2];

int rec(int i, int dec)
{
    if (dp[i][dec] != -1)
        return dp[i][dec];

    int ans = 1;
    back[i][dec] = make_pair(-1, -1);

    if (dec == 0)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                if (ans < (rec(j, 0) + 1))
                {
                    ans = rec(j, 0) + 1;
                    back[i][dec] = make_pair(j, 0);
                }
            }
        }
    }
    else
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
            {
                if (ans < (rec(j, 0) + 1))
                {
                    ans = rec(j, 0) + 1;
                    back[i][dec] = make_pair(j, 0);
                }
                if (ans < (rec(j, 1) + 1))
                {
                    ans = rec(j, 1) + 1;
                    back[i][dec] = make_pair(j, 1);
                }
            }
        }
    }

    return dp[i][dec] = ans;
}

vector<int> soln;
void generate(int i, int dec)
{
    if (i < 0)
    {
        return;
    }
    generate(back[i][dec].first, back[i][dec].second);
    soln.push_back(arr[i]);
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max({ans, rec(i, 0), rec(i, 1)});
    }
    cout << ans << '\n';

    // Generating the solutions
    for (int i = 0; i < n; i++)
    {
        if (rec(i, 0) == ans)
        {
            soln.clear();
            generate(i, 0);
            for (auto x : soln)
            {
                cout << x << '\t';
            }
            cout << '\n';
        }
        if (rec(i, 1) == ans)
        {
            soln.clear();
            generate(i, 1);
            for (auto x : soln)
            {
                cout << x << '\t';
            }
            cout << '\n';
        }
    }
}

int main()
{
    solve();
    return 0;
}*/

/* Find the length of the LBS of a given array of integers. This solution works in O(NlogN). Here we are using the LIS and LDS to find the length of the LBS.
#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> lis(vector<int> &arr)
{
    vector<int> temp;
    vector<int> ans;
    for (auto v : arr)
    {
        if (temp.empty() || v > temp.back())
        {
            temp.push_back(v);
        }
        else
        {
            auto it = lower_bound(temp.begin(), temp.end(), v);
            *it = v;
        }
        ans.push_back(temp.size());
    }

    return ans;
}

void solve()
{
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    auto LIS = lis(arr);
    reverse(arr.begin(), arr.end());
    auto LDS = lis(arr);
    reverse(LDS.begin(), LDS.end());

    int soln = 0;
    for (int i = 0; i < LIS.size(); i++)
    {
        soln = max(soln, LIS[i] + LDS[i] - 1);
    }
    cout << soln << '\n';
}

int main()
{
    solve();

    return 0;
}*/

/* Find the number of LIS of an array of integers.
// O(N^3) Solution --- >
#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1001][1001];

int main()
{
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int longest = 0;
    for (int i = 0; i < n; i++)
    {
        for (int sz = 1; sz < n; sz++)
        {
            if (sz == 1)
            {
                dp[i][sz] = 1;
            }
            else
            {
                for (int j = 0; j < i; j++)
                {
                    dp[i][sz] += dp[j][sz - 1];
                }
            }
            if (dp[i][sz])
            {
                longest = max(longest, dp[i][sz]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += dp[i][longest];
    }
    cout << ans << '\n';

    return 0;
}

// O(N^2) Solution --->
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

using ii = pair<int, int>;

int n;
int arr[2020];

ii merge(ii cur, ii val) // To find the length and count of LIS
{
    if (val.F > cur.F)
    {
        return val;
    }
    else if (val.F == cur.F)
    {
        cur.S += val.S;
        return cur;
    }
    else
    {
        return cur;
    }
}

ii dp[2022];

ii rec(int i)
{
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ii ans = {-1, 0};

    for (int i = 0; i < n; i++)
    {
        dp[i] = {1, 1};
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = merge(dp[i], {dp[j].F + 1, dp[j].S});
            }
        }
        ans = merge(ans, dp[i]);
    }

    cout << ans.F << " " << ans.S << '\n';

    return 0;
}*/

/* Consider N shops, that sell groceries everyday. On ith day, the jth shop sells the groceries at a price A[i][j]. If you buy from the same shop for 2 consecutive days, you get a discount of amount D. If you have to make a purchase each day, for M days, find the minimum amount paid by you over the M days period.
#include <bits/stdc++.h>
using namespace std;

int n, m, d;
int cost[2020][2020];

int calc(int level);

int rec(int level, int last){
    if(level==n) return 0;

    int ans=min(calc(level+1), rec(level+1,last)+cost[level][last]-d);

    return ans;
}

int calc(int level){
    int ans=1e9;
    for(int i=0; i<m; i++){
        ans=min(ans, rec(level,i)+cost[level-1][i]);
    }
}

void solve()
{
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> cost[i][j];
        }
    }
}

int main()
{
    solve();
    return 0;
}*/

/* Given n cities, you cn travel from city i to i+1 via bus, cost being B[i], or travel from ith city to (i+j)th city via plane, the cost of travel being P[i]+P[i+j]. Find the minimum cost to reach the last city. You can travel at most to the (i+k)th city from the ith city through the plane.
#include <bits/stdc++.h>
using namespace std;

deque<int> dq;
void insert(int x)
{
    while (!dq.empty() && dq.back() > x)
    {
        dq.pop_back();
    }
    dq.push_back(x);
}
void remove(int y)
{
    if (dq.front() == y)
    {
        dq.pop_front();
    }
}
int getMin()
{
    return dq.front();
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n - 1];
    int brr[n];
    int dp[n];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> brr[i];
    }
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        insert(dp[i - 1] + arr[i - 1]);
        if (i - k >= 0)
            remove(dp[i - k] + brr[i - k]);

        dp[i] = getMin() + brr[i];
        dp[i] = min(dp[i], dp[i - 1] + arr[i - 1]);
    }
    cout << dp[n - 1] << '\n';
}

int main()
{
    solve();
    return 0;
}*/

/* Same problem as before, but the maximum number of flights that can be taken is M.
#include <bits/stdc++.h>
using namespace std;

deque<int> dq;
void insert(int x)
{
    while (!dq.empty() && dq.back() > x)
    {
        dq.pop_back();
    }
    dq.push_back(x);
}
void remove(int y)
{
    if (dq.front() == y)
    {
        dq.pop_front();
    }
}
int getMin()
{
    return dq.front();
}
void clearVal()
{
    while (!dq.empty())
        dq.pop_back();
}
void solve()
{
    int n, k, m;
    cin >> n >> m >> k;
    int arr[n - 1];
    int brr[n];
    int dp[m + 1][n];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> brr[i];
    }

    // dp[i][j] ---> Min cost of reaching city j, using less than or equal to i number of flights.

    for (int i = 0; i <= m; i++)
    { // i is the number of flights
        dp[i][0] = 0;
        clearVal();
        for (int j = 0; j < n; j++)
        { // City number
            if (i == 0)
            {
                dp[i][0] = dp[i][j - 1] + arr[j - 1];
            }
            else
            {
                dp[i][0] = dp[i][j - 1] + arr[j - 1];
                insert(dp[i - 1][j - 1]);
                if (j - k >= 0)
                    remove(dp[i - 1][j - k] + brr[j - k]);
                dp[i][j] = min(dp[i][j], getMin() + brr[j]);
            }
        }
    }
    cout << dp[m][n - 1] << '\n';
}

int main()
{
    solve();
    return 0;
}*/

/*#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[720][720];

int rec(int l1, int l2, string &a, string &b)
{
    if (l2 == m)
    {
        return 1;
    }
    if (l1 == n)
    {
        return 0;
    }

    if (dp[l1][l2] != -1)
        return dp[l1][l2];

    int ans = 0;

    if (a[l1] == b[l2])
    {
        ans += rec(l1 + 1, l2 + 1, a, b);
        ans += rec(l1 + 1, l2, a, b);
    }
    else
    {
        ans += rec(l1 + 1, l2, a, b);
    }

    return dp[l1][l2]=ans;
}

void numDistinct(string a, string b)
{
    n = a.size();
    m = b.size();
    memset(dp, -1, sizeof(dp));
    int ans = rec(0, 0, a, b);
    cout << ans << '\n';
}

int main()
{
    string a, b;
    cin >> a >> b;
    numDistinct(a, b);
}*/

// **********************ADVANCED DP*************************

// ************************TREE DP***************************

/* Find the sum of the distances of a given node to all the other nodes in a given tree.
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[100100];

int sz[100100];
int indp[100100];
int outdp[100100];

void indfs(int node, int par)
{
    indp[node] = 0;
    sz[node] = 1;
    for (auto v : g[node])
    {
        if (v != par)
        {
            indfs(v, node);
            sz[node] += sz[v];
            indp[node] += indp[v] + sz[v];
        }
    }
}

void outdfs(int node, int par)
{
    if (node == 1)
    {
        outdp[node] = 0;
    }
    else
    {
        outdp[node] = outdp[par] + indp[par] - (indp[node] + sz[node]) + n - sz[node];
    }
    for (auto v : g[node])
    {
        if (v != par)
        {
            outdfs(v, node);
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    indfs(1, 0);
    outdfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << sz[i] << '\t' << indp[i] << '\t' << outdp[i] << '\n';
    }
}

int main()
{
    solve();
    return 0;
}*/

/* Given a tree with nodes assigned different values. You have to take some nodes in order to mazimise the sum of values of the nodes with the restriction that no two adjacent nodes can be selected.
#include <bits/stdc++.h>
using namespace std;

vector<int> g[100100];
int dp[100100][2];
int n;
int arr[100100];

void indfs(int node, int par)
{
    dp[node][0] = arr[node];
    dp[node][1] = 0;
    int temp = 0;
    for (auto v : g[node])
    {
        if (v != par)
        {
            indfs(v, node);
            dp[node][1] += dp[v][0];
            dp[node][0] += dp[v][1];
        }
    }
    dp[node][0] = max(dp[node][0], dp[node][1]);
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    indfs(1, 0);

    cout << dp[1][0] << '\n';
}*/

/* Given a tree with no specified root, find the node which when taken as the root will make the height of the tree max.
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[100100];
int indp[100100];
int outdp[100100];

int ans[100100];

void dfsin(int node, int par)
{
    // Consider each node as leaf initially.
    indp[node] = 1;

    // For all childs of the node, calculate their indp and use it to find the indp of the node.
    for (auto ch : g[node])
    {
        if (ch != par)
        {
            dfsin(ch, node);
            indp[node] = max(indp[node], indp[ch] + 1);
        }
    }
}

void dfsout(int node, int par, int outVal)
{
    outdp[node] = outVal;

    int max1 = -1, max2 = -1;
    for (auto ch : g[node])
    {
        if (ch != par)
        {
            if (indp[ch] > max1)
            {
                max2 = max1;
                max1 = indp[ch];
            }
            else if (indp[ch] > max2)
            {
                max2 = indp[ch];
            }
        }
    }

    for (auto ch : g[node])
    {
        if (ch != par)
        {
            if (indp[ch] == max1)
            {
                dfsout(ch, node, max(outdp[node] + 1, max2 + 2));
            }
            else
            {
                dfsout(ch, node, max(outdp[node] + 1, max1 + 2));
            }
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfsin(1, 0);
    dfsout(1, 0, 0);
}

int main()
{
    solve();
    return 0;
}*/

/* Given a tree, with each node given some value, you have to select k number of nodes such that no 2 of them are neighbours and the sum of their values is maximised.
#include <bits/stdc++.h>
using namespace std;
int n;
int k;
int arr[101];
int sz[101];
int dp[101][2][101];
vector<vector<int>> g;
void dfs(int node, int par)
{
    for (int i = 0; i <= k; i++)
    {
        dp[node][1][i] = (i == 1 ? arr[node] : -1e9);
        dp[node][0][i] = (i == 0 ? 0 : -1e9);
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
    cin >> n >> k;
    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    cout << max(dp[1][0][k], dp[1][1][k]);
}

int main()
{
    solve();
    return 0;
}*/

/* Find the number of integers between L and R such that the sum of digits in base 10 is a multiple of D.
#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int len;
string L, R;
int D;

int dp[10010][2][2][100];
int rec(int level, int tlo, int thi, int sumD)
{
    if (level == len)
    {
        if (sumD == 0)
            return 1;
        return 0;
    }

    if (dp[level][tlo][thi][sumD] != -1)
    {
        return dp[level][tlo][thi][sumD];
    }

    int ans = 0;
    int lo = 0;
    if (tlo == 1)
    {
        lo = L[level] - '0';
    }

    int hi = 9;
    if (thi == 1)
    {
        hi = R[level] - '0';
    }
    for (int i = lo; i <= hi; i++)
    {
        int ntlo = tlo;
        if (i != L[level] - '0')
            ntlo = 0;
        int nthi = thi;
        if (i != R[level] - '0')
            nthi = 0;

        ans += rec(level + 1, ntlo, nthi, (sumD + i) % D);
        ans %= mod;
    }

    return dp[level][tlo][thi][sumD] = ans;
}

void solve()
{
    cin >> L >> R;
    cin >> D;
    int cnt = R.length() - L.length();
    string temp = "";

    while (cnt--)
    {
        temp += "0";
    }

    L = temp + L;
    len = R.length();
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, 1, 0) << '\n';
}

int main()
{
    solve();
    return 0;
}*/

