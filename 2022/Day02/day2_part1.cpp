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



int rock, paper, sci;
int lost, won, tiee;
int ans;

int win(string first, string second){             // -1, 0, 1
    int toret;
    if(first=="A"){
        if(second=="X") toret=0;
        else if(second=="Y") toret=1;
        else toret =-1;
    }
    else if(first=="B"){
        if(second=="X") toret=-1;
        else if(second=="Y") toret=0;
        else toret=1;
    }
    else{
        if(second=="X") toret=1;
        else if(second=="Y") toret=-1;
        else toret=0;
    }

    if(toret==1) return won;
    else if(toret==0) return tiee;
    else return lost;
}


void process(){
    string s;
    while(getline(cin, s)){
        stringstream ss(s);
        string first, second;
        ss>>first, ss>>second;

        int temp = 0;
        if(second=="X") temp=rock;
        else if(second=="Y") temp=paper;
        else temp=sci;

        ans+=win(first, second)+temp;
    }
    return;
}


int main(){
    
    txtio;

    rock=1, paper=2, sci=3;
    lost=0, won=6, tiee=3;
    ans=0;

    process();
    print(ans);

    

    return 0;   
}