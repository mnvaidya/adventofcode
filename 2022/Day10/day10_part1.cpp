#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstdarg>
#include <tuple>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define coutarr(ar, n)          \
    for (int i = 0; i < n; i++) \
        cout << ar[i] << " ";   \
    cout << endl;
#define test(t) \
    int t;      \
    cin >> t;   \
    while (t--)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define print(z) cout << z << endl
#define seq(n, val)
#define ll long long
#define lli long long
#define pb push_back
#define null NULL
#define pi pair<int, int>;
#define no "NO"
#define yes "YES"
#define print1narr(ar, n)        \
    for (int i = 1; i <= n; i++) \
        cout << ar[i] << " ";    \
    cout << endl;
#define print0n1arr(ar, n)      \
    for (int i = 0; i < n; i++) \
        cout << ar[i] << " ";   \
    cout << endl;
#define in(ar, n)               \
    for (int i = 0; i < n; i++) \
        cin >> ar[i];
#define inn(ar, n)               \
    for (int i = 1; i <= n; i++) \
        cin >> ar[i];
#define txtio                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

const int mod = 1e9 + 7;
const int MOD = 5; // mod_division
const int modd = 998244353;
const int inf = INT_MAX;
const int neg_inf = INT_MIN;
const ll INF = 1e18;
using namespace std;

////////////////////////////////



map<ll, ll> mp;


ll process(){
    ll ans=0;
    for(ll i=20; i<=220; i+=40){
        ans+=(i*mp[i]);
    }

    return ans;
}

int main()
{

    txtio;


    ifstream file;
    file.open("input.txt");
    if(!file.is_open()){
        cout<<"error in opening file"<<endl;
        return 0;
    }

    ll X=1, cycle=1;

    string s;
    while(getline(cin, s)){
        stringstream ss(s);
        string word;
        ss>>word;

        if(word=="addx"){
            string word2;
            ss>>word2;

            mp[cycle++]=X;
            mp[cycle++]=X;

            X=X+stoi(word2);
        }
        else{
            // noop
            mp[cycle++]=X;
        }
    }
    

    ll ans= process();
    print(ans);
    

    

    return 0;
}