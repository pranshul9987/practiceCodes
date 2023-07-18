#include<bits/stdc++.h>
using namespace std;


int xorTillN(int n){
    // int n;
    // cin>>n;
    map<int, int> m;
    m[1]=1;
    m[2]=n+1;
    m[3]=0;
    m[4]=n;

    return m[(n-1)%4+1];
}

void oneMissingNumber(){
    int n;
    cin>>n;
    int num=0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        num^=x;
    }
    int num2=xorTillN(n+1);

    cout<<(num^num2)<<'\n';
}

void masking(int n){
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int sum=0;
    for(int mask=1; mask<(1<<n); mask++){
        for(int submask=mask; submask; submask=(submask-1)&mask){
            for(int pos=0; pos<n; pos++){
                if((submask>>pos)&1){
                    sum+=v[pos];
                }
            }
        }
    }
    cout<<sum;
}

#define ll long long

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // xorTillN();

    // oneMissingNumber();

    int n;
    cin>>n;
    masking(n);

    return 0;
}