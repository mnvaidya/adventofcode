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


void seqq(int size, ...)
{
    va_list args;
    va_start(args, size);
    for (int i = 0; i < size; i++)
        cout << va_arg(args, int) << " ";
    va_end(args);
    cout << endl;
}


////////////////////////////////


int ans;

bool complete_overlap(int first, int second, int third, int fourth){
    if(first>=third and second<=fourth) return true;
    else if(third>=first and fourth<=second) return true;
    return false;
}

void process(){
    string s;
    while(getline(cin, s)){
        int first=0, second=0, third=0, fourth=0;
        bool f_dash=false, s_dash=false, comma=false;

        for(char ch: s){
            if(ch=='-'){
                if(!f_dash) f_dash=true;
                else s_dash=true;
            }
            else if(ch==',') comma=true;
            else{
                // digit
                if(!f_dash) first=first*10+(ch-'0');
                else if(f_dash and !comma) second=second*10+(ch-'0');
                else if(comma and !s_dash) third=third*10+(ch-'0');
                else fourth=fourth*10+(ch-'0');
            }
        }

        // seqq(4, first, second, third, fourth);
        if(complete_overlap(first, second, third, fourth)) ans++;
    }
}


int main(){
    
    txtio;

    ans=0;

    process();
    print(ans);


    return 0;   
}