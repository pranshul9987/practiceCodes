#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll MOD=1e9+7;

/*
void LR_Sum_Query(){
    int n, q;
    cin>>n>>q;

    vector<ll> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    // for(int i=0; i<n; i++){
    //     cout<<v[i]<<'\t';
    // }
    // cout<<'\n';

    vector<ll> prefixSum(n+1);

    for(int i=1; i<=n; i++){
        prefixSum[i]=prefixSum[i-1]+v[i-1];
        if(prefixSum[i]<0){
            prefixSum[i]+=MOD;
        }
        if(prefixSum[i]>=MOD){
            prefixSum[i]-=MOD;
        }
    }

    
    // for(int i=0; i<=n; i++){
    //     cout<<prefixSum[i]<<'\t';
    // }
    // cout<<'\n';

    int l, r;
    while(q--){
        cin>>l>>r;
        ll ans=(prefixSum[r]-prefixSum[l-1]);
        if(ans<0){
            ans+=MOD;
        }
        if(ans>=MOD){
            ans-=MOD;
        }
        cout<<ans<<'\n';
    }
}
*/
/*
void Multiply_Sum_Query(){
    int n, q;
    cin>>n>>q;

    vector<ll> v(n+1);
    for(int i=1; i<=n; i++){
        cin>>v[i];
    }

    vector<ll> ps1(n+1), ps2(n+1);

    for(int i=1; i<=n; i++){
        ps1[i]=ps1[i-1]+v[i];
        if(ps1[i]<0){
            ps1[i]+=MOD;
        }
        if(ps1[i]>=MOD){
            ps1[i]-=MOD;
        }

        ps2[i]=ps2[i-1]+v[i]*i;
        if(ps2[i]<0){
            ps2[i]+=MOD;
        }
        if(ps2[i]>=MOD){
            ps2[i]-=MOD;
        }
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        ll ans=(ps1[r]-ps1[l-1])*(1-l)+(ps2[r]-ps2[l-1]);
        while(ans<0){
            ans+=MOD;
        }
        while(ans>=MOD){
            ans-=MOD;
        }

        cout<<ans<<'\n';
    }

}
*/
/*
void goodNumbers(){
    int n, k, q;
    cin>>n>>k>>q;

    vector<ll> v(n+1);

    for(int i=1; i<=n; i++){
        int l, r;
        cin>>l>>r;
        v[l]+=1;
        if(r!=n) v[r+1]-=1;
    }

    for(int i=1; i<=n; i++){
        v[i]+=v[i-1];
    }
    for(int i=1; i<=n; i++){
        v[i]=(v[i]>=k);
    }
    for(int i=1; i<=n; i++){
        v[i]+=v[i-1];
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        int count=v[r]-v[l-1];
        cout<<count<<'\n';
    }

}
*/
/*
void rectangleSumQuery(){
    int n, m, q;
    cin>>n>>m>>q;
    vector<vector<ll>> v(n+1);
    v[0]=vector<ll>(m+1);
    for(int i=1; i<=n; i++){
        v[i]=vector<ll>(m+1);
        for(int j=1; j<=m; j++){
            ll x;
            cin>>x;
            while(x<0){
                x+=MOD;
            }
            while(x>=MOD){
                x-=MOD;
            }
            v[i][j]=x;
        }
    }
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++){
    //         cout<<v[i][j]<<'\t';
    //     }
    //     cout<<'\n';
    // }

    // cout<<'\n'<<'\n';

    vector<vector<ll>> ps(n+1);
    
    ps[0]=vector<ll>(m+1);
    
    for(int i=1; i<=n; i++){
        ps[i]=vector<ll>(m+1);
        for(int j=1; j<=m; j++){
            ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+v[i][j];
        }
    }

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         cout<<ps[i][j]<<'\t';
    //     }
    //     cout<<'\n';
    // }

    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        ll ans=ps[c][d]-ps[c][b-1]-ps[a-1][d]+ps[a-1][b-1];
        while(ans<0){
            ans+=MOD;
        }
        while(ans>=MOD){
            ans-=MOD;
        }
        cout<<ans<<'\n';
    }
}
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // LR_Sum_Query();

    // Multiply_Sum_Query();

    // goodNumbers();

    // rectangleSumQuery();

    int a=7;
    cout<<__builtin_popcountll(a)<<'\n';
    cout<<__builtin_clzll(a)<<'\n';

    auto num=0b111;
    cout<<num<<'\n';

    return 0;
}