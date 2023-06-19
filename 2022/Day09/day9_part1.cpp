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
    freopen("output1.txt", "w", stdout);

const int mod = 1e9 + 7;
const int MOD = 5; // mod_division
const int modd = 998244353;
const int inf = INT_MAX;
const int neg_inf = INT_MIN;
const ll INF = 1e18;
using namespace std;

////////////////////////////////



const int n=1000, m=1000;                // just a random size of the grid
int ar[n][m];
int hi, hj, ti, tj;
int prev_hi, prev_hj;

void create_array(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ar[i][j]=0;
        }
    }
}


bool valid(){
    int dist= abs(hi-ti)+abs(hj-tj);
    if(dist==2){
        if(abs(hi-ti)==2 or abs(hj-tj)==2) return false;
    }
    return dist<=2;
}


void update_pos(){
    if(valid()) return ;
    else{
        // move T to previous position of H
        ti=prev_hi;
        tj=prev_hj;
    }
}


void move(int i, int j, int steps){           // row, col, steps
    for(int k=0; k<steps; k++){
        prev_hi = hi;
        prev_hj = hj;
        hi+=i, hj+=j;             // moving H

        update_pos();             // update position of T
        ar[ti][tj]=1;             // mark it as visited by T
    }
}


void process(){
    string s;
    while(getline(cin, s)){
        stringstream ss(s);
        string dir, steps;
        ss>>dir; ss>>steps;
        int step = stoi(steps);

        if(dir=="R"){            // right
            move(0, 1, step);
        }
        else if(dir=="U"){        // up 
            move(-1, 0, step);
        }
        else if(dir=="L"){         // left
            move(0, -1, step);
        }
        else{                    // down
            move(1, 0, step);
        }
    }

    return ;
}


void print_array(){
    print("------");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<ar[i][j];
        }
        cout<<endl;
    }
    print("------");
}



int calc_ans(){
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans+=ar[i][j];
        }
    }

    return ans;
}



int main(){
    
    txtio;

    create_array();

    prev_hi=hi=ti=n/2;
    prev_hj=hj=tj=m/2;              // starting positions
    ar[ti][tj]=1;
    
    process();
    
    // print_array();                 // 1-> visited by Tail
    int ans = calc_ans();
    print(ans);
    

    return 0;   
}