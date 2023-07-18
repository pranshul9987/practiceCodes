/* Segment tree implementation --- Given an array, you have to tackle 2 types of queries: (i) i x v: update the element at index x to value v; (ii) 2 l r: return the sum of elements from index l to r, both inclusive.
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100100];

int t[400400]; // We need it's size to be 4 times that of the given array.

void update(int index, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        t[index] = val;
        arr[l] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(index * 2, l, mid, pos, val);
    update(index * 2 + 1, mid + 1, r, pos, val);
    t[index] = t[2 * index] + t[2 * index + 1];
}

int query(int index, int l, int r, int lq, int rq)
{
    if (lq > rq || lq > r || rq<l)
    {
        return 0;
    }
    if (lq <= l && r <= rq)
    {
        return t[index];
    }
    int mid = (l + r) / 2;
    return query(index * 2, l, mid, lq, rq) + query(index * 2 + 1, mid + 1, r, lq, rq);
}
void build(int index, int l, int r)
{
    if (l == r)
    {
        t[index] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
    t[index] = t[2 * index] + t[2 * index + 1];
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    for(int i=1; i<=15; i++){
        cout<<t[i]<<'\t';
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int x, v;
            cin >> x >> v;
            update(1, 0, n - 1, x, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, r) << '\n';
        }
    }
}

int main()
{
    solve();
    return 0;
}*/

/* Given an array, you have to tackle 2 types of queries: (i) 1 x v: update the element at index x to a value v; (ii) 2 l r: return the minimum element from the range l to r along with the number of times the minimum element occurs.
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100100];

struct node
{
    int mini;
    int cnt;
    node(int m = 1e9, int c = 0)
    {
        mini = m;
        cnt = c;
    }
};

node t[400400];

node merge(node a, node b)
{
    if (a.mini == b.mini)
    {
        return node(a.mini, a.cnt + b.cnt);
    }
    else if (a.mini < b.mini)
    {
        return a;
    }
    return b;
}

void build(int index, int l, int r)
{
    if (l == r)
    {
        t[index] = node(arr[l], 1);
        return;
    }

    int mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

void update(int index, int l, int r, int pos, int val)
{
    if (l == r)
    {
        t[index] = node(val, 1);
        arr[l] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * index, l, mid, pos, val);
    update(2 * index + 1, mid + 1, r, pos, val);
}

node query(int index, int l, int r, int lq, int rq)
{
    if (l > rq || lq > r)
    {
        return 0;
    }
    if (lq <= l && rq >= r)
    {
        return t[index];
    }
    int mid = (l + r) / 2;
    return merge(query(index * 2, l, mid, lq, rq), query(index * 2 + 1, mid + 1, r, lq, rq));
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int x, v;
            cin >> x >> v;
            update(1, 0, n - 1, x, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            node ans = query(1, 0, n - 1, l, r);
            cout<<ans.mini<<'\t'<<ans.cnt<<'\n';
        }
    }
}

int main()
{
    solve();
    return 0;
}*/

/* Given an array, you have to tackle 2 types of queries: (i) 1 l r v: add v to all the elements in the range l to r; (ii) 1 x: return the xth element of the array.
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100100];

int t[400400];

void build(int index, int l, int r)
{
    if (l == r)
    {
        t[index] = arr[l];
        return;
    }
    else
    {
        t[index] = 0;
    }

    int mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
}

void update(int index, int l, int r, int lq, int rq, int val)
{
    if (lq <= l && rq >= r)
    {
        t[index] += val;
    }
    else if (lq > r || rq < l)
    {
        return;
    }
    else
    {
        int mid = (l + r) / 2;
        update(index * 2, l, mid, lq, rq, val);
        update(index * 2 + 1, mid + 1, r, lq, rq, val);
    }
}

int query(int index, int l, int r, int x)
{
    if (l == r)
    {
        if (x == l)
        {
            return t[index];
        }
        else{
            return 0;
        }
    }
    int mid = (l + r) / 2;
    return t[index] + query(2 * index, l, mid, x) + query(2 * index + 1, mid + 1, r, x);
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << '\t';
    }
    cout << '\n';
    for (int i = 1; i <= 9; i++)
    {
        cout << t[i] << '\t';
    }
    cout << '\n';
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            update(1, 0, n - 1, l, r, v);
        }
        else
        {
            int x;
            cin >> x;
            cout << query(1, 0, n - 1, x) << '\n';
        }
    }
}

int main()
{
    solve();
    return 0;
}*/

/* Given an array, you have to tackle 2 types of queries: (i) 1 x v: update the xth index with value v; (ii) 1 l r: return the sum of elements of the max sum subarray in range l to r.
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100100];

struct node
{
    int lSum;
    int rSum;
    int mSum;
    int totSum;
    node(int a = 0, int b = 0, int c = 0, int d = 0)
    {
        lSum = a;
        rSum = b;
        mSum = c;
        totSum = d;
    }
};

node t[400400];

node merge(node a, node b)
{
    node returnNode;
    returnNode.lSum = max(a.lSum, a.totSum + b.lSum);
    returnNode.rSum = max(b.rSum, b.totSum + a.rSum);
    returnNode.totSum = a.totSum + b.totSum;
    returnNode.mSum = max({a.mSum, b.mSum, a.rSum + b.lSum});
    return returnNode;
}

void build(int index, int l, int r)
{
    if (l == r)
    {
        t[index] = node(arr[l], arr[l], arr[l], arr[l]);
        return;
    }

    int mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

void update(int index, int l, int r, int pos, int val)
{
    if (l == r)
    {
        if (l == pos)
        {
            t[index] = node(val, val, val, val);
            arr[l] = val;
            while(index!=1){
                if(index%2==0){
                    t[index/2]=merge(t[index], t[index+1]);
                    index/=2;
                }else{
                    t[index/2]=merge(t[index], t[index-1]);
                    index/=2;
                }
            }
        }
        return;
    }
    int mid = (l + r) / 2;
    update(2 * index, l, mid, pos, val);
    update(2 * index + 1, mid + 1, r, pos, val);
}

node query(int index, int l, int r, int lq, int rq)
{
    if (l > rq || lq > r)
    {
        return node(0,0,0,0);
    }
    if (lq <= l && rq >= r)
    {
        return t[index];
    }
    int mid = (l + r) / 2;
    return merge(query(index * 2, l, mid, lq, rq), query(index * 2 + 1, mid + 1, r, lq, rq));
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int x, v;
            cin >> x >> v;
            update(1, 0, n - 1, x, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            node ans = query(1, 0, n - 1, l, r);
            cout << ans.mSum << '\n';
        }
    }
}

int main()
{
    solve();
    return 0;
}*/

/* We need to create a data structure that can tackle the following operations: (i) + x: Insert an element, x; (ii) - x: Remove an element x if it exists; (iii) ? k: Find the Kth element in the data structure.
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100100];

int t[400400]; // We need it's size to be 4 times that of the given array.

int merge(int a, int b)
{
    return a + b;
}

void addElement(int index, int l, int r, int x)
{
    if (l == r)
    {
        if (l == x)
        {
            t[index] = 1;
        }
        return;
    }
    int mid = (l + r) / 2;
    addElement(2 * index, l, mid, x);
    addElement(2 * index + 1, mid + 1, r, x);
    t[index] = merge(t[index * 2], t[index * 2 + 1]);
}

void deleteElement(int index, int l, int r, int x)
{
    if (l == r)
    {
        if (l == x)
        {
            t[index] = 0;
        }
        return;
    }
    int mid = (l + r) / 2;
    deleteElement(2 * index, l, mid, x);
    deleteElement(2 * index + 1, mid + 1, r, x);
    t[index] = merge(t[index * 2], t[index * 2 + 1]);
}

int findElement(int index, int l, int r, int x)
{
    if (l == r)
    {
        if (x == 1)
        {
            return l;
        };
        return -1;
    }

    int mid = (l + r) / 2;
    if (x <= t[2 * index])
    {
        return findElement(2 * index, l, mid, x);
    }
    else
    {
        return findElement(2 * index + 1, mid + 1, r, x - t[2 * index]);
    }
}

void build(int index, int l, int r)
{
    if (l == r)
    {
        t[index] = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
    t[index] = t[2 * index] + t[2 * index + 1];
}

void solve()
{
    cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    build(1, 0, n - 1);
    for (int i = 1; i <= 7; i++)
    {
        cout << t[i] << '\t';
    }
    cout << '\n';
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        char ch;
        cin >> ch;
        if (ch == '+')
        {
            int x;
            cin >> x;
            addElement(1, 0, n - 1, x);
            for (int i = 1; i <= 7; i++)
            {
                cout << t[i] << '\t';
            }
            cout << '\n';
        }
        else if (ch == '-')
        {
            int x;
            cin >> x;
            deleteElement(1, 0, n - 1, x);
            for (int i = 1; i <= 7; i++)
            {
                cout << t[i] << '\t';
            }
            cout << '\n';
        }
        else if (ch == '?')
        {
            int x;
            cin >> x;
            cout << findElement(1, 0, n - 1, x) << '\n';
        }
    }
}

int main()
{
    solve();
    return 0;
}*/

// ****************IMPORTANT**************
/*There are N people standing in a line, each with a different height, in a random order. For each person, the number of people in front of him who are taller than him is given. We also have the heights for N people, but do not know which is whose height. Find the height of each person.
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100100]; // Stores the number of people standing in front of the ith person.
int heights[100100]; // Stores the values of possible heights.
int t[400400]; // This is the segment tree, it will store the heights of the people.
int ans[100100];

int merge(int a, int b){

}

void build(int index, int l, int r){
    if(l==r){
        t[index]=heights[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*index, l, mid);
    build(2*index+1, mid+1, r);
    t[index]=merge(t[index*2], t[index*2+1]);
}

void solve()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        cin>>heights[i];
    }
    sort(arr, arr+n);
    build(1, 0, 2*n);
}

int main()
{
    solve();
    return 0;
}*/

/* Koi to problem thhi, yaad nhi kaunsi :)
#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define all(o) (o).begin(), (o).end()
#define F first
#define S second

using ii = pair<int, int>;
using vii = vector<ii>;

int n, q;
int arr[100100];
int t[400400];

void build(int index, int l, int r)
{
    if (l == r)
    {
        t[index] = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
    t[index] = t[2 * index] + t[2 * index + 1];
}

void update(int index, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        t[index] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * index, l, mid, pos, val);
    update(2 * index + 1, mid + 1, r, pos, val);
    t[index] = t[2 * index] + t[2 * index + 1];
}

int query(int index, int l, int r, int lq, int rq)
{
    if (lq > rq || lq > r || rq < l)
    {
        return 0;
    }
    if (lq <= l && rq >= r)
    {
        return t[index];
    }
    int mid = (l + r) / 2;
    return query(2 * index, l, mid, lq, rq) + query(2 * index + 1, mid + 1, r, lq, rq);
}

void solve()
{
    cin >> n >> q;
    vii vals;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        vals.PB({arr[i], i});
    }
    sort(all(vals));
    vector<pair<ii, ii>> queries;
    for (int i = 0; i < q; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        queries.PB({{k, i}, {l, r}});
    }
    sort(all(queries));
    int ans[q];
    build(1, 0, n - 1);
    int pos = 0;
    for (auto v : queries)
    {
        while (pos < vals.size() && vals[pos].F <= v.F.F)
        {
            update(1, 0, n - 1, vals[pos].S, 1);
            pos++;
        }
        ans[v.F.S] = query(1, 0, n - 1, v.S.F, v.S.S);
    }
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << '\n';
    }
}

int main()
{
    solve();
    return 0;
}*/

/* Coordinate compression ---> When the number of elements is much smaller than the range of possible values of the numbers. For example, we have 5 numbers: 2, 5, 6, 9, 1e5. For this creating a tree for 100000 leaves is overkill. We use coordinate compression in this case. Hence we replace all the values by some other value, say their index in the original array. Hence we will have values 1,2,3,4,5 that are to be pushed in the segment tree.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

struct coordinateCompress
{
    map<ll, ll> compVal;
    vi rev;

    int cnt;
    void add(ll x)
    {
        compVal[x]; // creates a new mapping from x -> 0 in the map compVal
    }
    void build()
    {
        cnt = 0;
        for (auto &v : compVal)
        {
            rev.emplace_back(v.first);
            v.second = cnt++;
        }
    }
    inline ll getCompVal(ll x)
    {
        return compVal[x];
    }

    inline ll getOriginal(ll x)
    {
        return rev[x];
    }

    ll getPrev(ll x)
    {
        auto it = compVal.upper_bound(x);
        it--;
        return it->second;
    }
    ll getNext(ll x)
    {
        auto it = compVal.lower_bound(x);
        return it->second;
    }
} CMP;

void solve()
{
    vi arr = {1, 3, 5, 3, 5, 2, 3, 1, 1000000};
    for (auto v : arr)
    {
        CMP.add(v);
    }
    for (auto v : CMP.compVal)
    {
        cout << v.first << ":" << v.second << '\t';
    }
    cout << '\n';
    for (int i = 0; i < CMP.rev.size(); i++)
    {
        cout << i << ":" << CMP.rev[i] << '\t';
    }
    cout << '\n';

    CMP.build();

    for (auto v : CMP.compVal)
    {
        cout << v.first << ":" << v.second << '\t';
    }
    cout << '\n';
    for (int i = 0; i < CMP.rev.size(); i++)
    {
        cout << i << ":" << CMP.rev[i] << '\t';
    }
    cout << '\n';

    cout << CMP.getNext(5) << '\n';
    cout << CMP.getNext(6) << '\n';
}
int main()
{
    solve();
    return 0;
}
*/

/* You are given an N sized array, A, and a number D. Your task is to find the longest subsequence A1, A2, A3...Ak such that abs(Ai-A(i+1))<=D. N<=1e5, A[i]<=1e9, D<=1e9. :)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, D, arr[100100];
map<ll, ll> compVal;

int t[400400]; // Globally initialised, hence all values are zero.

void update(int index, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
    {
        // cout << "check1\n";
        return;
    }
    if (l == r)
    {
        // cout << "check2\n";
        t[index] = max(t[index], val);
        return;
    }
    // cout<<"check3\n";
    int mid = (l + r) >> 2;
    // cout<<"check4\n";
    update(index << 1, l, mid, pos, val);
    // cout<<"check5\n";
    update((index << 1) | 1, mid + 1, r, pos, val);
    // cout<<"check6\n";
    t[index] = max(t[index * 2], t[index * 2 + 1]);
    // cout<<"check7\n";
}

int query(int index, int l, int r, int lq, int rq)
{
    if (lq > r || rq < l)
        return 0;
    if (lq <= l && r <= rq)
    {
        return t[index];
    }
    int mid = (l + r) / 2;
    return max(query(index * 2, l, mid, lq, rq), query(index * 2 + 1, mid + 1, r, lq, rq));
}

void solve()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        compVal[arr[i]];
    }

    cin >> D;

    int cnt = 0;
    for (auto &v : compVal)
    {
        v.second = cnt++;
    }
    // for(auto v:compVal) cout<<v.first<<": "<<v.second<<'\n';

    int ans = 0;
    int dp[n];

    for (int i = 0; i < n; i++)
    {
        cout << "i = " << i << '\n';

        int lo = arr[i] - D;
        int hi = arr[i] + D;
        cout<<"lo: "<<lo<<'\t'<<"hi: "<<hi<<'\n';

        auto it = compVal.upper_bound(hi);
        it--;
        hi = it->second;

        it = compVal.lower_bound(lo);
        lo = it->second;

        cout<<"lo: "<<lo<<'\t'<<"hi: "<<hi<<'\n';

        dp[i] = query(1, 0, cnt - 1, lo, hi) + 1;
        ans = max(ans, dp[i]);

        update(1, 0, cnt - 1, compVal[arr[i]], dp[i]);
    }

    cout << ans << '\n';
}

int main()
{
    solve();
    return 0;
}*/

/* Lazy propagation implementation:
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int sum, maxr, lazy;
    node()
    {
        sum = 0;
        maxr = 0;
        lazy = 0;
    }
};

node merge(node a, node b)
{
    node temp;
    temp.sum = a.sum + b.sum;
    temp.maxr = max(a.maxr, b.maxr);
    return temp;
}

#define MAXN 100100
node t[4 * MAXN];

void push(int id, int l, int r)
{
    if(t[id].lazy){
        t[id].sum=t[id].lazy*(r-l+1);
        t[id].maxr=t[id].lazy;
        if(l!=r){
            t[id*2].lazy=t[id].lazy;
            t[id*2+1].lazy=t[id].lazy;
        }
        t[id].lazy=0;
    }
}

void update(int id, int l, int r, int lq, int rq, int v)
{
    push(id, l, r);
    if (lq > r || l > rq)
    {
        return;
    }
    if (lq <= l && r <= rq)
    {
        t[id].lazy = v;
        push(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, lq, rq, v);
    update(id * 2 + 1, mid + 1, r, lq, rq, v);
    t[id] = merge(t[id * 2], t[id * 2 + 1]);
}

node query(int id, int l, int r, int lq, int rq)
{
    push(id, l, r);
    if (lq > r || rq < l)
        return node();
    if (lq <= l && rq >= r)
    {
        return t[id];
    }

    int mid = (l + r) / 2;
    return merge(query(id * 2, l, mid, lq, rq), query(id * 2 + 1, mid + 1, r, lq, rq));
}

void solve()
{
    update(1, 0, 9, 0, 5, 3);
    update(1, 0, 9, 6, 9, 4);
    node x = query(1, 0, 9, 3, 6);
    cout << x.sum << " " << x.maxr << '\n';
}

int main()
{
    solve();
    return 0;
}*/

