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

//------------------------------------------


const int n=25;
int ar[n][n][n];
int ans, cnt;

int dx[]={1, -1, 0, 0, 0, 0}; 
int dy[]={0, 0, 1, -1, 0, 0};
int dz[]={0, 0, 0, 0, 1, -1};


void create_array(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                ar[i][j][k]=0;
            }
        }
    }
}


void take_input(){
    string s; 
    while(getline(cin, s)){
        bool fc=false, sc=false;
        int first=0, second=0, third=0;

        for(char ch:s){
            if(ch==','){
                if(!fc) fc=true;
                else sc=true;
            }
            else{
                if(!fc) first=first*10+(ch-'0');
                else if(!sc) second=second*10+(ch-'0');
                else third=third*10+(ch-'0');
            }
        }
        ar[first+1][second+1][third+1]=1;
    }
}


bool valid(int i, int j, int k){
    if(i<0 or j<0 or k<0) return false;
    else if(i>=n or j>=n or k>=n) return false;
    else if(ar[i][j][k]==1 or ar[i][j][k]==2) return false;
    return true;
}


void dfs(int i, int j, int k){
    if(!valid(i,j,k)){
        return;
    }

    ar[i][j][k]=2;
    for(int m=0; m<6; m++){
        dfs(i+dx[m], j+dy[m], k+dz[m]);
    }
    return;
}

void process(){

    dfs(0, 0, 0);

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            for(int k=1; k<n; k++){
                if(ar[i][j][k]==1){
                    for(int m=0; m<6; m++){
                        ans+= (ar[i+dx[m]][j+dy[m]][k+dz[m]]==2);
                    }
                }
            }
        }
    }

    return ;
}


int main(){
    
    txtio;
    
    ans=0, cnt=0;
    create_array();
    take_input();
    process();
    print(ans);

    

    return 0;   
}
