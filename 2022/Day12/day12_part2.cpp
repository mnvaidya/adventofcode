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



const int n=41, m=167;            //41 rows and 167 chars on each row
char ar[n][m];
bool vis[n][m];
int mn_steps[n][m];


bool valid(int x, int y, char from){
    if(x<0 or x>=n or y<0 or y>=m) return false;
    else if(vis[x][y]==true) return false;
    else{
        if(from=='S') from='a';
        char to=ar[x][y];
        if(ar[x][y]=='E') to='z';
        if(to > (char)(from+1)) return false;
    }
    return true;
}

void bfs(int sx, int sy, int ex, int ey, queue<pair<int,int>>q){          // bfs on 2d grid      // no diagonal movement
    int ans=0;                   // steps

    // queue<pair<int, int>>q;
    // q.push({sx, sy});
    // vis[sx][sy]=true;
    // mn_steps[sx][sy]=0;  

    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;   
        q.pop();

        if(a==ex and b==ey){
            // reached our destination
            return;
        }
        char cur_ch = ar[a][b];
        int cur_steps = mn_steps[a][b];

        //left        
        if(valid(a, b-1, cur_ch)) mn_steps[a][b-1]=min(mn_steps[a][b-1], cur_steps+1), q.push({a, b-1}), vis[a][b-1]=true;
    
        //right
        if(valid(a, b+1, cur_ch)) mn_steps[a][b+1]=min(mn_steps[a][b+1], cur_steps+1), q.push({a, b+1}), vis[a][b+1]=true;
        
        //up
        if(valid(a-1, b, cur_ch)) mn_steps[a-1][b]=min(mn_steps[a-1][b], cur_steps+1), q.push({a-1, b}), vis[a-1][b]=true;
     
        //down
        if(valid(a+1, b, cur_ch)) mn_steps[a+1][b]=min(mn_steps[a+1][b], cur_steps+1), q.push({a+1, b}), vis[a+1][b]=true;
       
    }
}



int main(){
    
    txtio;

    int sx, sy, ex, ey;                 // positions of S and E
    string s;
    queue<pair<int, int>>q;     

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mn_steps[i][j]=100000;
            vis[i][j]=false;
        }
    }   

    for(int i=0; i<n; i++){                 // take the input
        getline(cin, s);
        for(int j=0; j<m; j++){
            ar[i][j]=s[j];
            if(s[j]=='S') sx=i, sy=j; 
            if(s[j]=='E') ex=i, ey=j;

            if(ar[i][j]=='a') q.push({i, j}), vis[i][j]=true, mn_steps[i][j]=0;
        }
    }
    
    bfs(sx, sy, ex, ey, q);
    cout<<mn_steps[ex][ey]<<endl;    

    
    

    return 0;   
}