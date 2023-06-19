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




int main(){

    txtio;


    vector<string> oper_char(4);          // for + and *
    vector<ll> oper_num(4);           // constant       // if -1 -> means same as old
    vector<ll> divs(4);                // constant
    vector<ll> True(4), False(4);        // constant for each monkey

    vector<multiset<ll>> ar(4);          // total 4 monkeys in the input
    vector<ll> ans(4, 0);               // final answer


    ifstream file("input.txt");
    if(!file.is_open()){
        cout<<"error in opening file"<<endl;
        return 0;
    }

    string word, num, worry, op, op2, div, tr, fal, s;
    ll op22, monk, div2, tr2, fal2;

    for(int i=0; i<4; i++){

        for(int j=0; j<6; j++){
            getline(cin, s); 

            stringstream ss(s);
            if(j==0){
                ss>>word;       // Monkey
                ss>>num;
                num.pop_back();    // :
                monk=stoi(num);
            }
            else if(j==1){                // only for the first round
                // Starting items     // take items
                ss>>word; ss>>word;
                ss>>worry;
                if(worry[worry.length()-1]==','){
                    bool take = 1;
                    while(take){
                        if(worry[worry.length()-1]==',') worry.pop_back();
                        else take=0;
                        ll ins = stoi(worry);
                        ar[monk].insert(ins);
                        if(take) ss>>worry;
                    }
                }
                else{
                    ll ins = stoi(worry);
                    ar[monk].insert(ins);
                }
            }
            else if(j==2){
                ss>>word; ss>>word; ss>>word; ss>>word;
                ss>>op;         // operator (add or multiply)
                oper_char[i]=op;
                ss>>op2;         // number
                if(op2!="old") {
                    op22=stoi(op2);
                    oper_num[i]=op22;
                }
                else oper_num[i]=-1;
            }
            else if(j==3){
                // Test:
                ss>>word; ss>>word; ss>>word;
                ss>>div;
                div2=stoi(div);
                divs[i]=div2;
            }
            else if(j==4){
                // if true:
                ss>>word, ss>>word, ss>>word, ss>>word, ss>>word;
                ss>>tr;
                tr2=stoi(tr);
                True[i]=tr2;
            }
            else if(j==5){
                // if false:
                ss>>word, ss>>word, ss>>word, ss>>word, ss>>word;
                ss>>fal;
                fal2=stoi(fal);
                False[i]=fal2;
            }
        }
    }


    // for(int i=0; i<4; i++) cout<<oper_char[i]<<" "; cout<<endl;
    // for(int i=0; i<4; i++) cout<<oper_num[i]<<" "; cout<<endl;
    // for(int i=0; i<4; i++) cout<<divs[i]<<" "; cout<<endl;
    // for(int i=0; i<4; i++) cout<<True[i]<<" "; cout<<endl;
    // for(int i=0; i<4; i++) cout<<False[i]<<" "; cout<<endl;



    for(int i=0; i<1000; i++){

        for(int mon=0; mon<4; mon++){
            ll len = 1LL* (int)ar[mon].size();
            ans[mon]+=len;
            for(auto first: ar[mon]){
                // operation
                ll second = (oper_num[mon]==-1)? first: oper_num[mon];
                ll temp = (oper_char[mon]=="*")? 1LL*first*second: first+second;
                // temp/=3;            // no longer needed

                if(!(temp%divs[mon])) ar[True[mon]].insert(temp);
                else ar[False[mon]].insert(temp);
            }

            ar[mon].clear();
        }
        
    }



    for(int i=0; i<4; i++) cout<<ans[i]<<" "; cout<<endl;
    sort(ans.begin(), ans.end());
    ll anss = ans[2]*ans[3];
    print(anss);
        
        

        



    
   
    

    

    return 0;
}