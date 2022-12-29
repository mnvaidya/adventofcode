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





const int n=1000, m=1000;                // just a random size of the grid
char ar[n][m];
int sx, sy;


struct knot{
    int row, col;
    int prev_hi, prev_hj;
};

// for 10 knots
knot knots[10];              // knot[0] - H        // knot[9] - T

void create_array(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ar[i][j]='.';
        }
    }
}


void print_array(){                   // for visualization
    print("------");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(sx==i and sy==j and ar[i][j]=='.') cout<<'s';
            else cout<<ar[i][j];
        }
        cout<<endl;
    }
    print("------");
}




bool valid(knot k, knot prevk){
    int dist = abs(k.row-prevk.row) + abs(k.col-prevk.col);
    if(dist==2){
        if(abs(k.row-prevk.row)==2 or abs(k.col-prevk.col)==2) return false;
    }

    return dist<=2;
}


int getDist(int hi, int hj, int ti, int tj){
    int dist = abs(hi-ti)+abs(hj-tj);
    return dist;
}


void update_pos(knot& k, knot& prevk, int l){
    if(valid(k, prevk)) return;
    else{
        k.prev_hi = k.row;
        k.prev_hj = k.col;

        // check if the prevk and k are in the same row or column
        bool is = (k.row==prevk.row) || (k.col==prevk.col) ;       
        
        if(is){
            pair<int,int> temps[]={{k.row+1, k.col+1}, {k.row+1, k.col-1}, {k.row-1, k.col+1}, {k.row-1, k.col-1}, {k.row, k.col+1}, {k.row, k.col-1}, {k.row+1, k.col}, {k.row-1, k.col}};

            int dist=inf;
            int newrow=k.row; int newcol=k.col;

            for(int i=0; i<8; i++){            
                int take = getDist(prevk.row, prevk.col, temps[i].first, temps[i].second);
                if(take<dist){
                    dist=take;
                    newrow = temps[i].first;
                    newcol = temps[i].second;
                }
            }
            k.row = newrow;
            k.col = newcol;

            assert(k.row==prevk.row || k.col==prevk.col);
        }
        else{
            // diagonal movement required
            pair<int,int> temps[]={{k.row+1, k.col+1}, {k.row+1, k.col-1}, {k.row-1, k.col+1}, {k.row-1, k.col-1}};

            int dist=inf;
            int newrow=k.row; int newcol=k.col;

            for(int i=0; i<4; i++){            
                int take = getDist(prevk.row, prevk.col, temps[i].first, temps[i].second);
                if(take<dist){
                    dist=take;
                    newrow = temps[i].first;
                    newcol = temps[i].second;
                }
            }
            k.row = newrow;
            k.col = newcol;
        }
    }

    return;
}


void move(int i, int j, int steps){           // row, col, steps
    for(int k=0; k<steps; k++){
        // update H ie. knots[0]
        knots[0].prev_hi=knots[0].row;
        knots[0].prev_hj=knots[0].col;
        knots[0].row+=i;
        knots[0].col+=j;

        // for each step, update each knot
        for(int l=1; l<10; l++){
            update_pos(knots[l], knots[l-1], l);
        }
        ar[knots[9].row][knots[9].col]='#';
    }

    // ar[knots[0].row][knots[0].col]='H';               // for visualization
    // for(int l=1; l<10; l++){
    //     if(ar[knots[l].row][knots[l].col]=='.') ar[knots[l].row][knots[l].col] = '0'+l;        // just for visualization
    // }
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
        // cout<<"== "<<s<<" =="<<endl;              // for visualization    // to see the visualization, uncomment this
        // print_array(); 
        // create_array();
    }

    return ;
}




int calc_ans(){
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ar[i][j]=='#') ans++;
        }
    }

    return ans;
}



int main(){
    
    txtio;

    create_array();

    for(int i=0; i<10; i++){         // starting pos of 10 knots
        knots[i].row=knots[i].prev_hi=n/2;
        knots[i].col=knots[i].prev_hj=m/2;
    }
    sx = knots[9].row;
    sy = knots[9].col;
    ar[knots[9].row][knots[9].col]='#'; 

    
    process();
    
    print_array();                 // 1-> visited by Tail
    int ans = calc_ans();
    print(ans);
    

    return 0;   
}