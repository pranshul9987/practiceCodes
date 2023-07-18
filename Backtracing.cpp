#include<bits/stdc++.h>
using namespace std;
#define ll long long

// N queens on a N*N board
int n;
vector<int> queens;

int ans;

bool check(int row, int col){
    //Loop on all the previous rows to see if the current queen is in path of attack of any of the previous queens.
    for(int prow=0; prow<row; prow++){
        //pcol is the column number of the queen in "prow" row.
        int pcol=queens[prow];
        //If the columns of queens are same, or the change in x==change in y, then they are in line of attack of each other.
        //Hence return false.
        if(pcol==col || abs(row-prow)==abs(pcol-col)) return false;
    }
    return true;
}

void rec(int level){
    if(level==n){ //We reached here -> means that all the previous positions have been filled up rightly -> so increase the answer by 1
        ans+=1;
        return;
    }

    //We check for all possible positions of the queen in the row LEVEL, hence we iterate for col from 0 to n
    for(int col=0; col<n; col++){
        //If placing the queen at [row,col] is possible, we place the queen there, and move to the next level. Else we move on.
        if(check(level, col)){
            //Here we placed the queen at [row, col] by pushing back col.
            queens.push_back(col);
            // Here we now move to the next row with given configuration.
            rec(level+1);
            //After checking for all possibilities with the given setting, we remove the queen from [row,col],
            //and move on to check for the next possible position of the queen in the same row.
            queens.pop_back();
        }
    }
}

void solve(){
    ans=0;
    cin>>n;
    rec(0);
    cout<<ans<<'\n';
}


/*K knights on a N*N board
int n, k;
int board[14][14];
int ans;

int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};

bool check(int i, int j){
    if(board[i][j]==1) return 0;
    for(int pos=0; pos<8; pos++){
        int nx=i+dx[i];
        int ny=j+dy[i];

        if(nx<n&&nx>=0 && ny<n&&ny>=0 && board[nx][ny]==1) return 0;
    }
    return 1;
}

void rec(int level){
    if(level==k){
        ans+=1;
        return;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check(i,j)){
                board[i][j]=1;
                rec(level+1);
                board[i][j]=0;
            }
        }
    }
}

void solve(){
    cin>>n>>k;
    ans=0;
    rec(0);
    for(int i=2; i<=k; i++){
        ans/=i;
    }
    cout<<ans<<'\n';
}
*/

/*Given n number, print all the permutations of the numbers without using the next_permutation function.
int n, ans;
map<int, int> mp;
vector<vector<int>> allSoln;
vector<int> currPerm;

void rec(int level){
    if(level==n){
        allSoln.push_back(currPerm);
        ans+=1;
        return;
    }
    for(auto next:mp){
        if(next.second!=0){
            mp[next.first]--;
            currPerm.push_back(next.first);
            rec(level+1);
            currPerm.pop_back();
            mp[next.first]++;
        }
    }
}

void solve(){
    cin>>n;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        mp[num]+=1;
    }

    ans=0;
    rec(0);
    cout<<ans<<'\n';
    for(int i=0; i<ans; i++){
        for(int j=0; j<n; j++){
            cout<<allSoln[i][j]<<'\t';
        }
        cout<<'\n';
    }
}
*/

/*Given n numbers from 1 to n, of all the possible permutations, print the kth of them when arranged lexicographically.
int n, k, order, flag=1;
vector<int> currPerm;
map<int, int> mp;

void rec(int level, int flag){
    if(level==n){
        order+=1;
        if(order==k){
            flag=0;
            for(int i=0; i<n; i++){
                cout<<currPerm[i]<<'\t';
            }
            cout<<'\n';
        }
    }
    for(auto next:mp){
        if(next.second!=0){
            currPerm.push_back(next.first);
            mp[next.first]--;
            rec(level+1, flag);
            currPerm.pop_back();
            mp[next.first]++;
        }
    }
}

void solve(){
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        mp[i]++;
    }
    order=0;
    rec(0, flag);
}
*/

/*Meet in the Middle --> Find the number of subarrays of an array of size N with sum of elements <= some given X.
N<=40
int n, x;
vector<ll> arr;

vector<ll> generate(vector<ll> newArr){
    vector<ll> sum;

    for(int i=0; i<(1<<(newArr.size())); i++){
        ll tempSum=0;
        for(int j=0; j<n; j++){
            if((i>>j)&1) tempSum+=newArr[j];
        }
        sum.push_back(tempSum);
    }

    return sum;
}

void solve(){
    cin>>n>>x;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }

    vector<ll> newArr[2];

    for(int i=0; i<n; i++){
        newArr[i&1].push_back(arr[i]);
    }

    vector<ll> sub0, sub1;
    sub0=generate(newArr[0]);
    sub1=generate(newArr[1]);
    
    ll count=0;

    for(auto v:sub0){
        count+=upper_bound(sub1.begin(), sub1.end(), x-v)-sub1.begin();
    }

    cout<<count<<'\n';
}
*/

/*Meet in the Middle --> Classical 4Sum problem --> With 0<=a<b<c<d<=N-1
int n, x;
vector<int> arr;
map<int, int> pos;

void solve(){
    
    cin>>n>>x;
    
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    
    for(int b=n-2; b>=1; b--){
        for(int a=b-1; a>=0; a--){
            if(pos[x-arr[a]-arr[b]]){
                cout<<"YES\n";
                return;
            }
        }
        int c=b;
        for(int d=c+1; d<n; d++){
            pos[arr[c]+arr[d]]=1;
        }
    }
    
    cout<<"NO\n";

    return;
}*/

int main(){
    ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);

    solve();

    return 0;
}