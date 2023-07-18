#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*Find the longest subarray with number of zeroes <= k
void subArrZero(){
    int n, k;
    cin>>n>>k;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int head=-1, tail=0, count=0, maxLength=0;
    while(tail<n){
        while(((count<=k && v[head+1]==1) || (count<k && v[head+1]==0)) && head<n-1){
            head+=1;
            if(v[head]==0) count+=1;
        }
        maxLength=max(maxLength, head-tail+1);
        if(head>=tail){
            if(v[tail]==0) count-=1;
            tail++;
        }else{
            tail+=1;
            head=tail-1;
        }
    }
    cout<<maxLength<<'\n';
}
*/

/*Find the number of subarrays with k distinct elements.
void distinctElementSubArr(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    map<int, int> mp;
    //Here we used count to keep track of distinct elements in the subarray.
    //Could have used map to check that but would have been troublesome.

    int head=-1, tail=0, count=0, ans=0;
    while(tail<n){
        while(head<n-1 && ((mp[v[head+1]]>0 && count<=k) || (mp[v[head+1]]==0 && count<k))){
            head+=1;
            if(mp[v[head]]==0) count+=1;
            mp[v[head]]+=1;
        }
            ans+=head-tail+1;
        if(head>=tail){
            mp[v[tail]]--;
            if(mp[v[tail]]==0) count-=1;
            tail++;
        }else{
            tail+=1;
            head=tail-1;
        }
    }
    cout<<ans<<'\n';
}
*/

void kOddNumber(){
    int n, k, d;
    cin>>n>>k>>d;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<int> ps(n+1);
    for(int i=1; i<=n; i++){
        ps[i]=ps[i-1]+v[i-1];
    }

    int head=-1, tail=0, oddCount=0, subarrCount=0;
    while(tail<n){
        while(head<n-1 && ((v[head]%2==0 && oddCount<=k) || (v[head]%2!=0 && oddCount<k))){
            head+=1;
            if(v[head]%2!=0) oddCount+=1;
        
            if(oddCount<=k){
                int sum=ps[head+1]-ps[tail];
                if(sum<=d) subarrCount+=1;
            }
        }
        
        if(head>=tail){
            if(v[tail]%2!=0) oddCount-=1;
            tail+=1;
        }else{
            tail+=1;
            head=tail-1;
        }
    }
    
    if(subarrCount) cout<<subarrCount<<'\n';
    else cout<<"IMPOSSIBLE\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // subArrZero();

    // distinctElementSubArr();

    kOddNumber();

    return 0;
}