#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> is_prime(10001000);

/*Sieve of Eratosthenes
void sieveOfEratosthenes(){
    for(ll i=1; i<=1e7; i++){
        is_prime[i]=i;
   }

    for(ll i=2; i*i<=10000000; i++){
        if(is_prime[i]==i){
            for(ll j=i*i; j<=10000000; j+=i){
                is_prime[j]=0;
            }
        }
    }

    for(ll i=0; i<=10000000; i++){
        if(is_prime[i]) cout<<is_prime[i]<<'\t';
    }
}
*/

void segmentedSieve(){
    ll a, b;
    cin>>a>>b;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // sieveOfEratosthenes();

    //segmentedSieve

    return 0;
}



