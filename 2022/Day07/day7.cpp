#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstdarg>
#include <typeinfo>
#include <tuple>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
template <typename T> string type_name();

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

////////////////////////////////



int cnt=0;
set<pair<int,string>> st;
int max_avail = 70000000;
int needed = 30000000;

int rootdirvalue = 0;

struct node{              // represents either dir/file

    string name;                 // dir/file name
    int val, sum;                 // val-> for each file       sum-> for dir
    node* parent;                // parent of this dir
    string type;                  // is it dir or file?
    vector<node*> children;            // directories and files inside this dir

};


node* createNode(string name, int val, node* parent, string type){
    node* newnode = new node();
    newnode->name = name;
    newnode->val = val;
    newnode->sum = 0;
    newnode->parent = parent;
    newnode->type = type;
    parent->children.push_back(newnode);

    vector<node*> newnodevect;
    newnode->children = newnodevect;

    return newnode;
}

node* findChild(string namee, node* root){
    node* temp = root;
    // root has an array of its children, just traverse that to find the child
    int n = (temp->children).size();

    for(int i=0; i<n; i++){
        if((temp->children[i])->name == namee) return (temp->children)[i];
    }

    return nullptr;
}

// void node_info(node* root){
//     cout<<"Dir/file : "<<root->name<<" Size: "<<root->val<<endl;
//     for(int i=0; i<(int)root->children.size(); i++){
//         cout<<root->children[i]->name<<"("<<root->children[i]->val<<"), ";
//     }
//     cout<<endl;

//     return;
// }

// void bfs(node* root){
//     if(!root) return ;
//     node* temp = root;

//     print("printing the tree: ");


//     queue<node*> q;
//     q.push(temp);

//     while(!q.empty()){
//         node* top = q.front();
//         q.pop();

//         // node info 
//         node_info(top);
//         for(int i=0; i<(int)top->children.size(); i++) q.push(top->children[i]);
//     }
// }


void dfs(node* root, int space){
    if(!root) return;
    // for(int i=0; i<space; i++) cout<<" ";       // visualization
    
    // cout<<"-"<<root->name<<" ("<<root->type;
    // if(root->type=="file") cout<<", size="<<root->val<<")"<<endl;       // visualization purpose
    // else cout<<")"<<endl;

    root->sum+=root->val;

    for(int i=0; i<(int)root->children.size(); i++){
        dfs(root->children[i], space+2);
        root->sum+=root->children[i]->sum;
    }


    //cout<<"the totalSize for "<<root->name<<" : "<<root->sum<<endl; 
    if(root->sum<=100000 and root->type=="dir") cnt++;
    if(root->type=="dir") st.insert({root->sum, root->name});
}





int main()
{

    txtio;

    node* root = new node();           // root dir /
    root->name="/";
    root->val = 0;
    root->parent = nullptr;
    node* root2 = root;
    root->type = "dir";

    ifstream file;
    file.open("input.txt");
    if(!file.is_open()) {cout<<"unable to open the file"<<endl; return 0;}
    string s;

    getline(cin, s);

    while(getline(cin, s)){
        stringstream ss(s);
        string word;
            ss>>word;
            if(word=="$"){
                ss>>word;

                if(word=="cd"){
                    ss>>word;
                    // word is dirname
                    if(word==".."){
                        root= root->parent;
                    }
                    else{
                        // check if that dir is present or not
                        node* dir = findChild(word, root);
                        if(!dir){
                            // create it
                            node* new_dir = createNode(word, 0, root, "dir");
                            root=new_dir;
                        }
                        else root=dir;
                    }
                }
                else if(word=="ls"){
                    continue;
                }
            }
            else{
                    if(word=="dir"){
                        ss>>word;
                        node* dir = findChild(word, root);
                        if(!dir){
                            node* new_dir = createNode(word, 0, root, "dir");
                        }
                    }
                    else{
                        int value = stoi((string)word);
                        ss>>word;
                        // word is a file name
                        node* file = findChild(word, root);
                        if(!file){
                            node* new_file = createNode(word, value, root, "file");
                        }
                    }
                }

    }

    // cout<<"\n\n"<<endl;
    dfs(root2, 0);


    // print("total directories having size <= 100000 are ");
    // print(cnt);


    // cout<<"\n";
    ll total_sum =0;

    for(auto it=st.begin(); it!=st.end(); it++){
        // cout<<it->first<<" "<<it->second<<endl;
        total_sum+=it->first;
        rootdirvalue= it->first;
    }

    
    int have= max_avail - rootdirvalue;
    if(have> needed) needed=0;
    else needed = (needed-have);

    for(auto it=st.begin(); it!=st.end(); it++){
        if(it->first>=needed){
            // cout<<"the answer is: "<<it->first<<endl;
            cout<<it->first<<endl;
            break;
        }
    }



    

    return 0;
}