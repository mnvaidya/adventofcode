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



int main()
{

    txtio;


    ifstream file;
    file.open("input.txt");
    if(!file.is_open()){
        cout<<"error in opening file"<<endl;
        return 0;
    }

    ll X=1, cycle=1, sprp=0;
    char ar[6][40]={'/'};

    string s;
    while(getline(cin, s)){
        stringstream ss(s);
        string word;
        ss>>word;

        if(word=="addx"){
            string word2;
            ss>>word2;

            
            if(((cycle-1)%40)>=sprp and ((cycle-1)%40)<(sprp+3)){
                ar[(cycle-1)/40][(cycle-1)%40]='#';
            }
            else ar[(cycle-1)/40][(cycle-1)%40]='.';
            mp[cycle++]=X;
            if(((cycle-1)%40)>=sprp and ((cycle-1)%40)<(sprp+3)){
                ar[(cycle-1)/40][(cycle-1)%40]='#';
            }
            else ar[(cycle-1)/40][(cycle-1)%40]='.';
            mp[cycle++]=X;

            X=X+stoi(word2);
            sprp=X-1;

        }
        else{
            // noop
            if(((cycle-1)%40)>=sprp and ((cycle-1)%40)<(sprp+3)){
                ar[(cycle-1)/40][(cycle-1)%40]='#';
            }
            else ar[(cycle-1)/40][(cycle-1)%40]='.';
            mp[cycle++]=X;
        }
    }

    // ------------------------- 

    for(int i=0; i<6; i++){
        for(int j=0; j<40; j++) cout<<ar[i][j];
        cout<<endl;
    }
   
    

    

    return 0;
}