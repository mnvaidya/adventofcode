#include <bits/stdc++.h>

#define txtio \
    freopen("in.txt", "r", stdin); \
    freopen("op2.txt", "w", stdout);
    
using namespace std;

const int n = 207;
int ar[n]={1};     // for n cards

void process(){
    string s, word;

    for(int i=1; i<n; i++) ar[i]=1;

    while(getline(cin, s)){
        stringstream ss(s);
        ss>>word;    // Card
        ss>>word;     
        word.pop_back();     // card number
        int card_n = stoi(word);

        set<int> s;
        bool bar_found=false;
        int temp =0;

        while(ss>>word){
            if(word=="|"){
                bar_found=true;
                continue;
            }
            int num = stoi(word);
            if(!bar_found) s.insert(num);
            else{
                if(s.find(num)!=s.end()) temp++;
            }
        }

        for(int i=card_n+1; i<=card_n+temp; i++){
            ar[i]+=ar[card_n];
        }
    }

    long long sum =0;
    for(int i=1; i<=n; i++){
        sum+=ar[i];
    }
    cout<<sum<<endl;
}

int main(){

    txtio;
    process();

    return 0;
}