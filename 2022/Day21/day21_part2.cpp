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




struct node{
    ll val;
    int op;          // 0+  1-  2*  3/
    string name, expr;                  // expression till this node     (root's expres)
    node* parent, *left, *right;
};


node* createNode(node* parent, int val, string name, int op){
    node* newnode = new node();
    newnode->val = val;
    newnode->name = name;
    newnode->expr="";
    newnode->op = op;
    newnode->parent=parent;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}



vector<node*> bfs(node* root){
    node* temp = root;  
    if(!root){
        cout<<"empty tree"<<endl;
        return vector<node*>{};
    }

    vector<node*> ar;
    queue<node*> q;
    q.push(temp);
    q.push(NULL);

    while(!q.empty()){
        node* top = q.front();
        q.pop();

        if(!top){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<top->name<<" ";
            ar.push_back(top);
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
        
    }

    reverse(ar.begin(), ar.end());
    return ar;
}


// map<node*, bool> vis;
// bool cycle(node* root){
//     node* temp = root;  
//     if(!root){
//         cout<<"empty tree"<<endl;
//         return false;
//     }

//     queue<node*> q;
//     q.push(temp);
//     q.push(NULL);

//     while(!q.empty()){
//         node* top = q.front();
//         q.pop();

//         if(vis[top]) return true;
//         vis[top]=true;

//         if(!top){
//             cout<<endl;
//             if(!q.empty()) q.push(NULL);
//         }
//         else{
//             if(top->left) q.push(top->left);
//             if(top->right) q.push(top->right);
//         }
        
//     }

//     return false;
// }



void processTree(node* root, vector<node*> &ar){
    for(node* temp: ar){
        if(temp->op==-1){
            // leaf node 
            continue;
        }
        if(temp->op==0){
            temp->val= temp->left->val + temp->right->val;
        }
        else if(temp->op==1){
            temp->val= temp->left->val - temp->right->val;
        }
        else if(temp->op==2){
            temp->val= temp->left->val * temp->right->val;
        }   
        else{
            temp->val= temp->left->val / temp->right->val;
        }
    }

    return ;
}


void form_expr(node* root, vector<node*>&ar){
    for(node* temp:ar){
        if(temp->op==-1) continue;          // leaf node

        string ch="";
        switch(temp->op){
            case 0: ch="+"; break;
            case 1: ch="-"; break;
            case 2: ch="*"; break;
            case 3: ch="/"; break;
        }

        if(temp->name=="lptd:"){
            temp->expr="(x"+ch+to_string(temp->right->val)+")";
        }
        else if(temp->left->expr!=""){
            temp->expr = temp->left->expr+ch+to_string(temp->right->val)+")";
        }
        else if(temp->right->expr!=""){
            temp->expr = temp->right->expr+ch+to_string(temp->left->val)+")";
        }
    }

    cout<<"root->expr"<<endl;
    cout<<root->left->expr<<endl;

    cout<<root->right->val<<endl;
}





map<string, node*> mp;

int main(){

    txtio;

    node* root = createNode(NULL, -1, "root:", 0);         // addition as per given tc
    mp["root:"]=root;

    ifstream file;
    file.open("input.txt");
    if(!file.is_open()) cout<<"error in opening file"<<endl;

    string s;

    while(getline(cin, s)){

        node* temp=NULL;
        stringstream ss(s);
        string word, first, second;
        ss>>word;           // parent
        if(mp.find(word)==mp.end()){
            // create a new node
            temp = createNode(NULL, -1, word, -1);          // unknown value till now
            mp[word]=temp;
        }
        else temp =mp[word];

        ss>>first;
        if(first[0]>='0' and first[0]<='9'){
            // value and a leaf node
            ll value = 1LL* stoi(first);
            temp->val = value;
            
        }
        else{
            // naN

            node* leftchild=NULL,*rightchild=NULL;
            first+=':';
            if(mp.find(first)==mp.end()){
                leftchild= createNode(temp, -1, first, -1);
                mp[first]=leftchild;
            }
            else leftchild = mp[first];

            string opr;
            ss>>opr;

            if(opr=="-") temp->op = 1;
            else if(opr=="+") temp->op=0;
            else if(opr=="*") temp->op=2;
            else temp->op=3;

            ss>>second;
            second+=':';
            if(mp.find(second)==mp.end()){
                rightchild=createNode(temp, -1, second, -1); 
                mp[second]=rightchild;
            }
            else rightchild=mp[second];

            leftchild->parent=temp;
            temp->left=leftchild;
            rightchild->parent=temp;
            temp->right=rightchild;
        }

    }

    node* humn = mp["humn:"];
    vector<node*> ar= bfs(root);
    processTree(root, ar);
    // print(ans);
    

    



    form_expr(root, ar);




    return 0;
}