#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*Pigeon hole principle: find the number of subarrays with sum divisible by the n, the size of the array
void solve(){
    int n;
    cin>>n;

    vector<ll> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    vector<ll> pre(n+1);
    ll sum=0;
    
    pre[0]=1;
    for(int i=0; i<n; i++){
        sum+=v[i];
        sum=((sum%n)+n)%n;
        pre[sum]++;
    }

    ll soln=0;
    for(int i=0; i<n; i++){
        ll x=pre[i];
        soln += x*(x-1)/2;
    }

    cout<<soln<<'\n';
}
*/

/*SWEEPLINE TECHNIQUE: Find the length of the union of given n intervals
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> events;
    for(int i=0; i<n; i++){
        int l, r;
        cin>>l>>r;
        events.push_back({l,1});
        events.push_back({r,-1});
    }
    sort(events.begin(), events.end());
    
    int count=0, unionLength=0;
    for(int i=0; i<events.size()-1; i++){
        count+=events[i].second;
        if(count>0){
            unionLength+=events[i+1].first-events[i].first;
        }
    }
    cout<<unionLength<<'\n';

}
*/

/*
void solve(){
    int n;
    cin>>n;
    vector<pair<int, pair<int, int>>> events;
    for(int i=0; i<n; i++){
        int l, r, x;
        cin>>l>>r>>x;
        events.push_back({l,{0,x}});
        events.push_back({r,{2,x}});
    }
    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        int y;
        cin>>y;
        events.push_back({y,{1,i}});
    }
    sort(events.begin(), events.end());
    vector<int> ans(q);
    multiset<int> mt;
    for(int i=0; i<events.size()-1; i++){
        if(events[i].second.first==0){
            mt.insert(events[i].second.second);
        }else if(events[i].second.first==2){
            mt.erase(mt.find(events[i].second.second));
        }else{
            if(mt.empty()){
                ans[events[i].second.second]=-1;
            }else{
                ans[events[i].second.second]=*mt.rbegin();
            }
        }
    }

    for(int i=0; i<q; i++){
        cout<<ans[i]<<'\t';
    }
    cout<<'\n';
}
*/


/*Given n job activities with their start time and finish time. Find the maximum number of activities that canbe performed without performing two activities at the same time
bool comp(pair<int, int> &a, pair<int, int> &b){
    return a.second<b.second;
}

int maxJobs(vector<pair<int, int>> &v){
    int count=0, prevEnd=INT_MIN;
    for(int i=0; i<v.size(); i++){
        if(v[i].first>=prevEnd){
            count+=1;
            prevEnd=v[i].second;
        }
    }
    return count;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int, int>> v(n);
    for(int i=0; i<n; i++){
        int start, end;
        cin>>start>>end;
        v[i]={start, end};
    }
    sort(v.begin(), v.end(), comp);
    int ans=maxJobs(v);
    cout<<ans<<'\n';
}*/

/* Given lengths of n ropes, we need to join them and make a single rope. Joining two ropes will make a singlerope of length equal to the sum of both the ropes and also the cost of joining is also equal to the sum ofropes that are joined.
int findSum(priority_queue<int> &pq){
    int sum=0;
    while(pq.size()>=2){
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        sum+=(x+y);
        pq.push(x+y);
    }

    return -1*sum;
}

void solve(){
    int n;
    cin>>n;
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        pq.push(-1*num);
    }
    int ans=findSum(pq);
    cout<<ans<<'\n';
}*/

/* Find the minimum number of operations that can be performed on elements of the array such that the gcd ofthe array becomes equal or multiple of k. In one operation you can pick any element and increment ordecrement its value by 1.
void solve(){
    int n, k;
    cin>>n>>k;
    int ans=0;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        int modVal=num%k;
        modVal=min(modVal, k-modVal);
        ans+=modVal;
    }
    cout<<ans<<'\n';
}*/

void solve(){
    string s, ans="";
    int k;
    cin>>s;
    cin>>k;

    int n=s.length();
    stack<char> res;
    int i;
    for(i=0; i<n; i++){
        while(!res.empty() && res.top()>s[i] && k>0){
            k--;
            res.pop();
        }
        res.push(s[i]);
    }
    while(!res.empty()){
        ans.push_back(res.top());
        res.pop();
    }
    reverse(ans.begin(), ans.end());
    while(k--){
        ans.pop_back();
    }
    i=0;
    while(i<n && ans[i]==0){
        i++;
    }
    ans=ans.substr(i);
    if(ans.empty()) cout<<0<<'\n';
    else cout<<ans<<'\n';

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}