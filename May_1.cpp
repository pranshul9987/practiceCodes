#include <bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<char, int> symbols = {{'(', -1},{')', 1},{'{', -2},{'}', 2},{'[', -3},{']', 3},};

int MOD=1e9+7;

int binExponentiation(int a, int b){
    int ans=1;
    while(b){
        if(b%2!=0){
            ans = (1LL*ans*a) %MOD;
        }
        a = (1LL*a*a) %MOD;
        b=b/2;
    }

    return ans;
}

string isBalanced(string s){
    stack<char> st;
    for(char bracket:s){
        if(symbols[bracket]<0){
            st.push(bracket);
        }else{
            if(st.empty()) return "NO";
            char top=st.top();
            st.pop();
            if(symbols[top]+symbols[bracket]!=0){
                return "NO";
            }
        }
    }
    if(st.empty()) return "YES";
    return "NO";
}

void print(multiset<string> &s){
    for(auto it:s){
        cout<<(it);
        cout<<'\n';
    }

    for(auto it1=s.begin(); it1!=s.end(); it1++){
        cout<<*it1<<'\n';
    }
}

vector<int> NGE(vector<int> v){
    vector<int> nge(v.size());
    stack<int> st;
    for(int i=0; i<v.size(); i++){
        while(!st.empty() && v[st.top()]<v[i]){
            nge[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        nge[st.top()]=-1;
        st.pop();
    }
    return nge;
}

bool cmp (int a, int b){
    return a>b;
}

int main(){

    // int a[10]={1,3,5,5,5,7,9,11,11,13};
    // int x=upper_bound(a, a+10, 5)-a;
    // cout<<x;

    // string s="abcdef";
    // reverse(s.begin(), s.end());
    // cout<<s;
    // sort(s.begin(), s.begin()+4);
    // cout<<s;

    // pair<int, string> p;
    // // p=make_pair(2, "abc");
    // p={2,"deg"};
    // cout<<p.first<<'\t'<<p.second<<'\n';
    // pair<int, string> p1=p;
    // p1.first=3234;
    // cout<<p.first<<'\t'<<p.second<<'\n';
    // cout<<p1.first<<'\t'<<p1.second<<'\n';

    // int a[]={1,2,3}, b[]={2,3,4};
    // pair<int, int> p_array[3];
    // p_array[0]={1,2};
    // p_array[1]={2,3};
    // p_array[2]={3,4};

    // for(int i=0; i<3; i++){
    //     cout<<p_array[i].first<<'\t'<<p_array[i].second<<'\n';
    // }
    // swap(p_array[0], p_array[2]);
    
    // for(int i=0; i<3; i++){
    //     cout<<p_array[i].first<<'\t'<<p_array[i].second<<'\n';
    // }

    // vector<int> v;
    // int n;
    // cin>>n;
    // for(int i=0; i<n; i++){
    //     int x;
    //     cin>>x;
    //     v.push_back(x);
    //     printVec(v);
    //     v.pop_back();
    // }

    // vector<pair<int, int>> v1(2, {1,2});
    // for(int i=0; i<2; i++){
    //     cout<<v1[i].first<<'\t'<<v1[i].second<<'\n';
    // }

    // vector<pair<int, int>> v={{1,2},{2,3},{4,6}};
    // printVec(v);
    // printVec(v);

    // vector<int> v[5];

    // for(int i=0; i<5; i++){
    //     int n; cin>>n;
    //     for(int j=0; j<n; j++){
    //         int x;
    //         cin>>x;
    //         v[i].push_back(x);
    //     }
    // }

    // for(int i=0; i<5; i++){
    //     printVec(v[i]);
    // }

    // vector<vector<int>> v;
    // int n;
    // cin>>n;
    // for(int i=0; i<n; i++){
    //     int m;
    //     cin>>m;
    //     vector<int> temp;
    //     for(int j=0; j<m; j++){
    //         int x;
    //         cin>>x;
    //         temp.push_back(x);
    //     }
    //     v.push_back(temp);
    // }

    // for(int i=0; i<v.size(); i++){
    //     printVec(v[i]);
    // }

    // cout<<'\n'<<v[0][4];

    // vector<int> v={1,2,3,4,5,6,7,8};
    // vector<int> :: iterator it=v.begin();
    // for(it=v.begin(); it!=v.end(); it++){
    //     cout<<*it<<'\t';
    // }

    // vector<pair<int, int>> v1={{1,2},{2,3},{4,3}};
    // vector<pair<int, int>>::iterator it1=v1.begin();
    // for(it1; it1!=v1.end(); it1++){
    //     cout<<(*it1).first<<'\t'<<(*it1).second<<'\n';
    // }

    // for(it1=v1.begin(); it1!=v1.end(); it1++){
    //     cout<<it1->first<<'\t'<<it1->second<<'\n';
    // }

    // vector<int> v={1,2,3,4,5,6,7,8};
    // for(int value:v){
    //     cout<<value<<'\t';
    // }

    // vector<pair<int, int>> v={{1,2},{2,3},{4,3}};
    // for(pair<int, int> &value:v){
    //     cout<<value.first++<<'\t'<<value.second++<<'\n';
    // }

    // for(pair<int, int> value:v){
    //     cout<<value.first<<'\t'<<value.second<<'\n';
    // }
    
    // map<int, string> m;
    // m[1]="abc";
    // m[5]="cdc";
    // m[3]="acd";
    // m.insert({4, "afg"});
    // map<int, string>::iterator it;
    // for(it=m.begin(); it!=m.end(); it++){
    //     cout<<(*it).first<<" "<<it->second<<'\n';
    // }
    
    // for(auto &pr:m){
    //     cout<<pr.first<<" "<<pr.second<<'\n';
    // }

    // // auto itr = m.find(75);
    // m.erase(7);
    // for(it=m.begin(); it!=m.end(); it++){
    //     cout<<(*it).first<<" "<<it->second<<'\n';
    // }

    // map<string, int> m;
    // int n;
    // cin>>n;
    // for(int i=0; i<n; i++){
    //     string str;
    //     cin>>str;
    //     m[str]+=1;
    // }

    // for(auto it:m){
    //     cout<<it.first<<'\t'<<it.second<<'\n';
    // }

    // unordered_map<int, string> m;
    // m[1]="abc";
    // m[5]="cdc";
    // m[3]="acd";
    // m.insert({4, "afg"}); 
    
    // print(m);

    // int n;
    // cin>>n;
    // multiset<string> s;

    // s.insert("abd");
    // s.insert("dcuc");
    // s.insert("jrmf");
    // // auto it=s.find("abd");
    // // cout<<*it<<'\n';
    
    // for(int i=0; i<n; i++){
    //     string temp;
    //     cin>>temp;
    //     s.insert(temp);
    // }
    
    // print(s);

    // int t;
    // cin>>t;

    // while(t--){
    //     int n, k;
    //     cin>>n>>k;
    //     multiset<ll> s;
    //     for(int i=0; i<n; i++){
    //         int num;
    //         cin>>num;
    //         s.insert(num);
    //     }
    //     ll sum=0;
    //     for(int i=0; i<k; i++){
    //         auto it=s.end();
    //         it--;
    //         sum+=*it;
    //         s.insert((*it)/2);
    //         s.erase(it);
    //     }
    //     cout<<sum<<'\n';
    // }

    // map<pair<string, string>, vector<int>> m;
    // int n;
    // cin>>n;

    // for(int i=0; i<n; i++){
    //     string firstName, lastName;
    //     cin>>firstName>>lastName;
    //     int subjectCount;
    //     cin>>subjectCount;
    //     int marks;
    //     for(int j=0; j<subjectCount; j++){
    //         cin>>marks;
    //         m[{firstName, lastName}].push_back(marks);
    //     }
    // }

    // for(auto &pr:m){
    //     auto &fullName=pr.first;
    //     auto &list=pr.second;
    //     cout<<fullName.first<<" "<<fullName.second<<'\n';
    //     cout<<list.size()<<'\n';
    //     for(auto &element:list){
    //         cout<<element<<" ";
    //     }
    //     cout<<'\n';
    // }

    // map<int, multiset<string>> m;
    // int studentCount;
    // cin>>studentCount;

    // for(int i=0; i<studentCount; i++){
    //     int marks;
    //     string name;
    //     cin>>name>>marks;
    //     m[marks].insert(name);
    // }
    // auto &it=--m.end();
    // while(true){
    //     auto &students=it->second;
    //     int sMarks=it->first;
    //     for(auto &student:students){
    //         cout<<student<<" "<<sMarks<<'\n';
    //     }
    //     if(it==m.begin()) break;
    //     it--;
    // }

    // stack<int> s;

    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // while(!s.empty()){
    //     cout<<s.top()<<'\n';
    //     s.pop();
    // }

    // int t;
    // cin>>t;
    // while(t--){
    //     string s;
    //     cin>>s;
    //     cout<<isBalanced(s)<<'\n';
    // }

    // int n;
    // cin>>n;
    // vector<int> v(n);
    // for(int i=0; i<n; i++){
    //     cin>>v[i];
    // }

    // vector<int> nge=NGE(v);

    // for(int i=0; i<n; i++){
    //     cout<<v[i]<<"\t"<<(nge[i] == -1?-1:v[nge[i]])<<'\n';
    // }

    // vector<int> v;
    // int n;
    // cin>>n;
    // for(int i=0; i<n; i++){
    //     int num;
    //     cin>>num;
    //     v.push_back(num);
    // }

    // sort(v.begin(), v.end(), cmp);

    // for(int i=0; i<n; i++){
    //     cout<<v[i]<<'\t';
    // }
    // cout<<'\n';

    cout<<binExponentiation(2,100);
    
    return 0;
}