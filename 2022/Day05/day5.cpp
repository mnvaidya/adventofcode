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

//////////////////////////////


int main()
{

    txtio;

    int t = 503;
    vector<stack<char>> ar(10);

    char ch;
    while(1){
        int i;
        for(i=1; i<10; i++){
            while(1){
                cin>>ch;
                if(ch=='.')break;
                else ar[i].push(ch);
            }
        }
        if(i==10) break;
    }

    for(int i=1; i<10; i++){
        stack<char> s = ar[i];
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
    
    ifstream file;
    file.open("input.txt");
    if(!file.is_open()) {cout<<"unable to open the file"<<endl; return 0;}
    string s;

    for(int i=0; i<9; i++) {
        getline(file, s);
        //cout<<i<<endl;
    }
    

    while(getline(file, s)){
        //cout<<"the string is "<<s<<endl;
        stringstream ss(s);
        int num = -1, first=-1, second =-1;
        string word;
        int cnt=0;
        while(ss>>word){
            cnt++;
            if(word=="move" or word=="to" or word=="from") continue;
            int temp = stoi(word);
            if(cnt==2) num=temp;
            else if(cnt==4) first=temp;
            else if(cnt==6) second=temp;
        }
        cnt=0;
        //cout<<"num "<<num<<" first "<<first<<" second "<<second<<endl;

        if(num==1){
            ar[second].push(ar[first].top());
            ar[first].pop();
        }
        else{
            stack<char> temp2;

            for(int i=0; i<num; i++){
                temp2.push(ar[first].top());
                ar[first].pop();
            }

            while(!temp2.empty()){
                ar[second].push(temp2.top());
                temp2.pop();
            }
        }
        
    }

    cout<<"-----------------"<<endl;

    for(int i=1; i<10; i++){
        stack<char> s = ar[i];
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
    
    

    

    return 0;
}