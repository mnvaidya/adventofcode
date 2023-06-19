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
    freopen("output2.txt", "w", stdout);

const int mod = 1e9 + 7;
const int MOD = 5; // mod_division
const int modd = 998244353;
const int inf = INT_MAX;
const int neg_inf = INT_MIN;
const ll INF = 1e18;
using namespace std;

////////////////////////////////

void seqq(int size, ...)
{
    va_list args;
    va_start(args, size);
    for (int i = 0; i < size; i++)
        cout << va_arg(args, int) << " ";
    va_end(args);
    cout << endl;
}
pair<int, int> evod(int s, int ee)
{
    int e = (ee - s + 2 - (s % 2)) / 2;
    int o = (ee - s + 1) - e;
    pair<int, int> p = {e, o};
    return p;
}

ll bin_exp(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = ((res % MOD) * (a % MOD)) % MOD;
        }
        a = ((a % MOD) * (a % MOD)) % MOD;
        b >>= 1LL;
    }
    return res;
} // used for mod_inverse
ll mod_inverse(ll a)
{
    ll mmi;
    mmi = (bin_exp(a, MOD - 2) + MOD) % MOD;
    return mmi;
} // used for modulo division
ll mod_divide(ll a, ll b) { return (a * mod_inverse(b)) % MOD; } // if returned 0, no mod_division possible

//------------------------------------------




int main()
{

    txtio;

    string s; cin>>s;
    for(int i=0; i<s.length()-14; i++){
        set<char> st;
        for(int j=i; j<min((i+14), (int)s.length()); j++){
            st.insert(s[j]);
        }
        if(st.size()==14){
            print(i);
            return 0;
        }
    }
    
    

    

    return 0;
}