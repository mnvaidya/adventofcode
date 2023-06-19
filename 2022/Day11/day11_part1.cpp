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



map<ll, ll> mp;



int main(){

    txtio;

    vector<multiset<int>> ar(8);          // total 7 monkeys in the input
    vector<int> ans(8, 0);               // final answer

    ifstream file("input.txt");
    if(!file.is_open()){
        cout<<"error in opening file"<<endl;
        return 0;
    }

    string s;
    for(int i=0; i<=20; i++){                  // data reapeated 21 times
        // cout<<"round "<<i+1<<endl;
        // total 6 lines for 1 monkey + 1 empty line

        string word, num, worry, op, op2, div, tr, fal;
        int op22, monk, div2, tr2, fal2;

        for(int monkey=0; monkey<8; monkey++){

            for(int j=0; j<6; j++){
                getline(cin, s); 

                stringstream ss(s);
                if(j==0){
                    ss>>word;       // Monkey
                    ss>>num;
                    num.pop_back();    // :
                    monk=stoi(num);
                }
                else if(j==1 and i==1){                // only for the first round
                    // Starting items     // take items
                    ss>>word; ss>>word;
                    ss>>worry;
                    if(worry[worry.length()-1]==','){
                        bool take = 1;
                        while(take){
                            if(worry[worry.length()-1]==',') worry.pop_back();
                            else take=0;
                            int ins = stoi(worry);
                            ar[monk].insert(ins);
                            if(take) ss>>worry;
                        }
                    }
                    else{
                        int ins = stoi(worry);
                        ar[monk].insert(ins);
                    }
                }
                else if(j==2){
                    ss>>word; ss>>word; ss>>word; ss>>word;
                    ss>>op;         // operator (add or multiply)
                    ss>>op2;         // number
                    if(op2!="old") op22=stoi(op2);
                }
                else if(j==3){
                    // Test:
                    ss>>word; ss>>word; ss>>word;
                    ss>>div;
                    div2=stoi(div);
                }
                else if(j==4){
                    // if true:
                    ss>>word, ss>>word, ss>>word, ss>>word, ss>>word;
                    ss>>tr;
                    tr2=stoi(tr);
                }
                else if(j==5){
                    // if false:
                    ss>>word, ss>>word, ss>>word, ss>>word, ss>>word;
                    ss>>fal;
                    fal2=stoi(fal);
                }
            }

            // process for monkey i
            int len = ar[monk].size();
            ans[monk]+=len;
            for(auto first: ar[monk]){
                // operation
                ll second = (op2=="old")? first: op22;
                ll temp = (op=="*")? first*second: first+second;
                temp/=3;

                if((temp%div2)==0) ar[tr2].insert(temp);
                else ar[fal2].insert(temp);
            }

            ar[monk].clear();

            // A round finishes here
        }
    }   



    sort(ans.begin(), ans.end());
    ll anss = ans[6]*ans[7];
    print(anss);

        
        

        



    
   
    

    

    return 0;
}