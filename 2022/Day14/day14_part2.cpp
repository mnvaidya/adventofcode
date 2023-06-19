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


const int n=180, m=700;                   // size of grid
int ans;
char ar[n][m];

void create_array(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            if(i==170) ar[i][j]='#';
            else ar[i][j]='.';
            if(j==500 and i==0) ar[i][j]='+';           // sand pouring point
        }
    }
}

void print_array(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            cout<<ar[i][j];
        }
        cout<<endl;
    }
}

void put_rocks(int fx, int fy, int sx, int sy, int difx, int dify){
    bool stop=false;

    for(fx;;fx+=difx){
        for(fy;;fy+=dify){
            ar[fx][fy]='#';
            if(fx==sx and fy==sy){
                stop=true;
            }
            if(fy==sy) break;
        }
        if(stop) break;
    }
    return;
}


void take_input(){
    string s; 
    while(getline(cin, s)){
        s+=" .";
        stringstream ss(s);
        string word;
        vector<pair<int,int>> ar;
        while(1){
            ss>>word;
            if(word==".") break;
            else if(word=="->") continue;
            else{
                // take y, x
                int y=0, x=0;
                bool comma =false;
                for(int i=0; i<word.length(); i++){
                    if(word[i]==',') comma = true;
                    else if(!comma) y = y*10+(word[i]-'0');
                    else x = x*10+(word[i]-'0');
                }
                ar.push_back({x, y});
            }
        }

        // process the ar array
        for(int i=0; i<ar.size()-1; i++){
            int fx = ar[i].first, fy = ar[i].second, sx = ar[i+1].first, sy = ar[i+1].second;
            int difx= sx-fx , dify = sy-fy;
            if(difx<0) difx=-1;
            else if(difx>0) difx=1;
            if(dify<0) dify =-1;
            else if(dify>0) dify=1;

            put_rocks(fx, fy, sx, sy, difx, dify);
        }
    }
}

bool down(int x, int y){
    return ar[x][y]=='.';
}

bool left(int x, int y){
    return ar[x][y]=='.';
}

bool right(int x, int y){
    return ar[x][y]=='.';
}


void process(){
    while(1){
        ans++;
        bool flag=true;
        int x=0, y=500;          // initial position of sand

        while(1){
            if(down(x+1, y)) x++;
            else if(left(x+1, y-1)) x++, y--;
            else if(right(x+1, y+1)) x++, y++;
            else flag=false;
            if(!flag) break;
        }
        ar[x][y]='o';
        if(x==0 and y==500) return;
    }

    return ;
}


int main(){
    

    txtio;
    create_array();
    take_input();
    
    ans=0;
    process();
    print_array();             
    print(ans);
    

    return 0;   
}