/* KMP Algo
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int kmp[n+1];
    kmp[0] = -1;
    int i = 0, j = -1;
    while (i < n)
    {
        while (j != -1 && s[i] != s[j]){
            j=kmp[j];
        }
        j++;
        i++;
        kmp[i] = j;
    }

    for (int i = 0; i <= n; i++)
    {
        cout << kmp[i] << " ";
    }
}

int main()
{
    solve();
    return 0;
}*/

/* Z-Algo implementation
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<int> z(n, 0);
    z[0] = -1;
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        // Reuse information from the starting block.
        if (i <= r)
        {
            z[i] = min(r - i + 1, z[i - l]); // z[i']
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i] += 1; // Naive algo; Both the if statements are the optimizing elements in this algo.

        // If zbox crossed, make a new box from l=i to r=i+(z[i]-1).
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << z[i] << '\t';
    }
}

int main()
{
    solve();
    return 0;
}*/

/* Rolling Hash
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll quickHash(string s, ll p, ll mod) // This is O(n)
{
    ll ans = s[0] - 'a' + 1;
    for (int i = 1; i < s.length(); i++)
    {
        ans = (ans * p + (s[i] - 'a' + 1)) % mod;
    }
    return ans;
}

struct hasher
{
    int sz;
    ll mod;
    ll p;
    vector<ll> fHash, pk;
    void init(string s, ll _p, ll _mod)
    {
        mod = _mod;
        p = _p;
        sz = s.length();
        fHash.resize(sz);
        pk.resize(sz);
        fHash[0] = (s[0] - 'a' + 1);
        pk[0] = 1;
        for (int i = 1; i < sz; i++)
        {
            fHash[i] = (fHash[i - 1] * p + (s[i] - 'a' + 1)) % mod;
            pk[i] = (pk[i - 1] * p) % mod;
        }
    }
    ll getfHash(int l, int r)
    {
        if (l == 0)
        {
            return fHash[r];
        }
        return ((fHash[r] - fHash[l - 1] * (pk[r - l + 1])) % mod + mod) % mod;
    }
};

    /* *************BASIC IMPLEMENTATION*************
void solve()
{
    string s;
    // cin >> s;
    for (int i = 0; i < 500; i++)
    {
        s += ('a' + (rand() % 26));
    }
    hasher sHash;
    sHash.init(s, 31, 1e9 + 7);

    map<int, set<string>> mp;

    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // cout<<sHash.getfHash(i,j)<<'\n';
            mp[sHash.getfHash(i, j)].insert(s.substr(i, j - i + 1));
        }
    }

    for (auto v : mp)
    {
        if (v.second.size() > 1)
        {
            cout << v.first << "\n";
            for (auto temp : v.second)
            {
                cout << temp << "*******************************************";
            }
            cout << '\n';
        }
    }*/

/* *************Sample problem: find the number of times a given pattern P appears in a given text T. length(P)=M, length(T)=N*************
void solve()
{
string text, pattern;
cin>>text>>pattern;
int p=pattern.length();
hasher texth;
texth.init(text, 31, 999999929);
int h=quickHash(pattern, 31, 999999929);
for(int i=0; i+p-1<text.length(); i++){
    if(h==texth.getfHash(i, i+p-1)){
        cout<<"match at "<<i<<'\n';
    }
}*/

/* Given a string, from all the cycle shift forms of the string, find the lexicographically smallest form. Also, arrange them in the ascending lexicographic order.

int n;
string s;
hasher sHash;

bool cmp(int i, int j){ // O(logN)
    int lo=1;
    int hi=n;
    int ans=0;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(sHash.getfHash(i, i+mid-1)==sHash.getfHash(j, j+mid-1)){
            ans=mid;
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    if(ans==n){
        return 0;
    }else{
        return s[i+ans]<s[j+ans];
    }
}

void solve(){
    cin>>s;
    n=s.length();
    s=s+s;
    sHash.init(s, 37, 999999937);
    vector<int> final;
    for(int i=0; i<n; i++){
        final.push_back(i);
    }
    sort(final.begin(), final.end(), cmp); //O(NlogN*logN)
    for(int i=0; i<n; i++){
        cout<<final[i]<<'\t';
    }
}

int main()
{
    solve();
    return 0;
}

*/

/* TRIE Data Structure
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        // Base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Considering all letters smallcase
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        removeUtil(child, word.substr(1));
    }

    void removeWord(string word)
    {
        removeUtil(root, word);
    }
};

void solve()
{
    Trie *t = new Trie();
    t->insertWord("abcd");
    cout << "Present or not " << t->searchWord("abcd") << '\n';
    t->removeWord("abcd");
    cout << "Present or not " << t->searchWord("abcd") << '\n';
}

int main()
{
    solve();
    return 0;
}*/

/* Longest common prefix using TRIE
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode *root, string word)
    {
        // Base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Considering all letters smallcase
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (root->childCount == 1)
            {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }else{
                break;
            }

            if(root->isTerminal){
                break;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    Trie *t = new Trie('\0');
    string first;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        t->insertWord(s);
        if (i == 0)
        {
            first = s;
        }


    }
        string ans = "";
        t->lcp(first, ans);
        cout << ans << '\n';

    return 0;
}*/

/*#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int long long

ll quickHash(string s, ll p, ll m)
{
    ll ans = (s[0] - 'a' + 1);
    for (int i = 1; i < s.length(); i++)
    {
        ans = (ans * p + (s[i] - 'a' + 1)) % m;
    }
    return ans;
}

struct hasher
{
    int sz;
    ll mod, p;
    vector<ll> fHash;
    vector<ll> pk;
    void init(string s, ll _p, ll _mod)
    {
        mod = _mod;
        p = _p;
        sz = s.size();
        fHash.resize(sz);
        pk.resize(sz);
        fHash[0] = (s[0] - 'a' + 1);
        pk[0] = 1;
        for (int i = 1; i < sz; i++)
        {
            fHash[i] = (fHash[i - 1] * p + (s[i] - 'a' + 1)) % mod;
            pk[i] = (p * pk[i - 1]) % mod;
        }
    }

    ll getHash(int l, int r)
    {
        if (l == 0)
            return fHash[r];

        return ((fHash[r] - fHash[l - 1] * pk[r - l + 1]) % mod + mod) % mod;
    }
};

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    string temp = s + s;
    cout << "s --->" << s << '\n';
    cout << "temp --->" << temp << '\n';
    hasher tempHash;
    tempHash.init(temp, 31, 999999929);
    ll mini = tempHash.getHash(0, n - 1);
    ll minIdx = 0;
    cout << temp.substr(0, n) << '\t' << mini << '\t' << minIdx << '\n';
    for (int i = 1; i < n; i++)
    {
        cout << temp.substr(i, n) << '\t' << tempHash.getHash(i, i + n - 1) << '\t' << i << '\n';
        if (tempHash.getHash(i, i + n - 1) < mini)
        {
            mini = tempHash.getHash(i, i + n - 1);
            minIdx = i;
        }
    }

    cout << "Lexicographically smallest rotation is --->\t" << temp.substr(minIdx, n) << '\n';
}

signed main()
{
    solve();
    return 0;
}*/

/* Manacher's algo
#include <bits/stdc++.h>
using namespace std;

struct manacher
{
    vector<int> p;

    void run_manacher(string s)
    {
        cout << s << '\n';
        int n = s.length();
        p.assign(n, 1);
        int l = 1, r = 1;
        for (int i = 1; i < n; i++)
        {
            p[i] = max(0, min(r - i, p[l + r - i]));
            while (i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]])
            {
                p[i] += 1;
            }
            if (i + p[i] > r)
            {
                l = i - p[i];
                r = i + p[i];
            }
        }

        for (auto v : p)
        {
            cout << v << " ";
        }
        cout << '\n';
    }

    void build(string s)
    {
        string t;
        for (auto v : s)
        {
            t += string("#") + v;
        }
        run_manacher(t + "#");
    }

    int getLongest(int cen, bool odd)
    {
        int pos = 2 * cen + 1 + (!odd);
        return p[pos] - 1;
    }

    bool checkPalin(int l, int r)
    {
        if ((r - l + 1) <= getLongest((l + r) / 2, l % 2 == r % 2)) // l%2==r%2 to check odd position or even. For example when we have l=2 and r=4, odd should be 1, and this expression give us 1. If l=2 and r=5, then the expression gives us 0.
        {
            return 1;
        }
        return 0;
    }
} m;

void solve()
{
    string s = "babbabbabc";
    m.build(s);
}

int main()
{
    solve();
    return 0;
}*/

