#include<bits/stdc++.h>
using namespace std;

#define ll long long

/*Find the index of the first 1 in an array of form [00.....00111...111]
void binaryArray(){
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int lo=0, hi=n-1, ans=-1;
    int mid=(lo+hi)/2;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(v[mid]==1){
            hi=mid-1;
            ans=mid;
        }else if(v[mid]==0){
            lo=mid+1;
        }
    }

    cout<<ans<<'\n';
}
*/

/*Find the index of the first element >= given x
void lowerBound(){
    int n;
    cin>>n;
    vector<int> v(n);

    int x;
    cin>>x;

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int lo=0, hi=n-1, ans=-1;
    while(lo<=hi){
        int mid=(lo+hi/2);
        if(v[mid]>=x){ //it will be v[mid]>x if we want upperBound
            hi=mid-1;
            ans=mid;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans<<'\t'<<v[ans]<<'\n';
}
*/

/*Find the minimum time required to paint the wall divided into n partitions, given k painters
bool check(int mid, int k, vector<int> v, int n){
    int sum=0, count=0;
    for(int i=0; i<n; i){
        while((sum+v[i])<=mid && i<n){
            sum+=v[i];
            i++;
        }
        count+=1;
        sum=0;
    }
    
    if(count<=k) return 1;
    return 0;
}
void painterPartition(){
    int n, k;
    cin>>n>>k;

    int ans=-1, lo=0, hi=0;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        lo=max(lo, v[i]);
        hi+=v[i];
    }

    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(check(mid, k, v, n)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }

    cout<<ans<<'\n';


}
*/

/*Minimise maximum neighbour dsitance between given n points using k more points
bool check(int mid, int k, int n, vector<int> v){
    int count=0;
    for(int i=1; i<n; i++){
        int temp=(v[i]-v[i-1]+mid-1)/mid - 1;
        count+=temp;
    }

    return (count<=k);
}
void minimizeMaxDistance(){
    int n, k;
    cin>>n>>k;
    
    int ans=-1, lo=0, hi=0;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(i>0) hi=max(hi, v[i]-v[i-1]);
    }

    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(check(mid, k, n, v)){
            hi=mid-1;
            ans=mid;
        }else{
            lo=mid+1;
        }
    }

    cout<<ans<<'\n';

}
*/

/* Find the number of subarrays of a binary N sized array that you can make all one's with <=k flips
bool check(int mid, int n, int k, int i, vector<int> ps){
    if(((mid-i+1)-(ps[mid]-(i>0?ps[i]:0)))<=k) return true;
    return false;
}
void cntSubarrays(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n), ps(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(i) ps[i]=ps[i-1]+v[i-1];
    }

    int ans=0;

    for(int i=0; i<n; i++){
        int temp=i-1;
        int lo=i, hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(check(mid, n, k, i, ps)){
                lo=mid+1;
                temp=mid;
            }else{
                hi=mid-1;
            }
        }

        ans+=(temp-i+1);
    }

    cout<<ans<<'\n';

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // binaryArray();

    // lowerBound();

    // painterPartition();

    // minimizeMaxDistance();

    cntSubarrays();

    return 0;
}*/

