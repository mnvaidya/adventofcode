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

void seqq(int size, ...)
{
    va_list args;
    va_start(args, size);
    for (int i = 0; i < size; i++)
        cout << va_arg(args, int) << " ";
    va_end(args);
    cout << endl;
}


//------------------------------------


const int n=5000;          // grid size
char ar[n][n];
int rounds;

int dx[]={-1, -1, -1, 0, 1, 1, 1, 0};
int dy[]={-1, 0, 1, 1, 1, 0, -1, -1};
int point;                 // pointing to the direction

int mnx, mny, mxx, mxy;          // for the boundary

struct elf{
    int x, y;
    int prevx, prevy;
};

vector<elf> elves;

void create_array(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ar[i][j]='.';
        }
    }
    return;
}

void print_array(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<ar[i][j];
        }
        cout<<endl;
    }
}


void take_input(){
    int x, y; 
    x=y=n/2;
    string s;
    while(getline(cin,s)){
        int len = s.length();
        for(int j=0; j<len; j++){
            ar[x][j+y]=s[j];
            if(s[j]=='#'){
                elf obj;
                obj.x=obj.prevx=x;
                obj.y=obj.prevy=j+y;
                elves.push_back(obj);
            }
        }
        x++;
    }
    return;
}


int occupied_pos(int pos1x, int pos1y, int pos2x, int pos2y, int pos3x, int pos3y){
    int toret= ((ar[pos1x][pos1y]=='#' ) + (ar[pos2x][pos2y]=='#') + (ar[pos3x][pos3y]=='#'));
    return toret;
}


void process(){
    while(1){
        rounds++;
        // cout<<"== End of Round "<<rounds<<" =="<<endl;           // visualization
        int moved=0;              // total elves moved

        map<pair<int,int>, vector<elf*>> mp;

        for(int i=0; i<elves.size(); i++){
            int x = elves[i].x;              // current position
            int y = elves[i].y;

            int neg=0;
            for(int j=0; j<8; j++){
                int xx =x+dx[j], yy=y+dy[j];
                if(ar[xx][yy]=='#') neg++;
            }
            if(neg==0){
                continue;
            }
            else{
                int temp=point;
                bool move=false;

                for(int j=0; j<4; j++){
                    if(temp==0){          // n
                        if(occupied_pos(x-1, y-1, x-1, y, x-1, y+1)==0){
                            mp[{elves[i].x-1, elves[i].y}].push_back(&elves[i]);
                            move=true;
                        }
                    }
                    if(temp==1){
                        if(occupied_pos(x+1, y+1, x+1, y, x+1, y-1)==0){
                            mp[{elves[i].x+1, elves[i].y}].push_back(&elves[i]);
                            move=true;
                        }
                    }
                    if(temp==2){
                        if(occupied_pos(x+1, y-1, x, y-1, x-1, y-1)==0){
                            mp[{elves[i].x, elves[i].y-1}].push_back(&elves[i]);
                            move=true;
                        }
                    }
                    if(temp==3){
                        if(occupied_pos(x-1, y+1, x, y+1, x+1, y+1)==0){
                            mp[{elves[i].x, elves[i].y+1}].push_back(&elves[i]);
                            move=true;
                        }
                    }

                    if(move){
                        break;
                    }
                    temp++;
                    temp%=4;                  
                }
            }
        }

        // update the grid state
        for(auto it: mp){
            if(it.second.size()>1) continue;
            else{
                moved++;
                elf *temp = it.second.back();
                temp->prevx=temp->x;
                temp->prevy=temp->y;
                temp->x = it.first.first;
                temp->y = it.first.second;         // updated position of elf
            }
        }
        if(moved==0) break;
        create_array();
        for(int k=0; k<elves.size(); k++){
            elf temp = elves[k];
            int ux = temp.x, uy =temp.y;
            ar[ux][uy]='#';
            mnx = min(mnx, ux);
            mny = min(mny, uy);
            mxx = max(mxx, ux);
            mxy = max(mxy, uy);
        }
        // print_array();                  // visualization
        point++;
        point%=4;

        if(rounds==10) break;
    }
    return;
}


int calc_ans(){
    int ans=0;
    for(int i=mnx; i<=mxx; i++){
        for(int j=mny; j<=mxy; j++){
            if(ar[i][j]=='.') ans++;
        }
    }
    return ans;
}


int main(){
    
    txtio;
    point=0, rounds=0;
    mnx=mny=inf;
    mxx=mxy= -12;
    create_array();
    take_input();
    // print("== Initial State ==");                // visualization
    // print_array();
    process();

    int ans = calc_ans();
    print(ans);

    return 0;   
}