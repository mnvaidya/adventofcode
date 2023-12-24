#include <bits/stdc++.h>

#define txtio \
    freopen("in.txt", "r", stdin); \
    freopen("op1.txt", "w", stdout);
    
using namespace std;

void process(){
    long long sum =0;
    string s, word;

    while(getline(cin, s)){
        stringstream ss(s);
        ss>>word;    // Card
        ss>>word;     // card number
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
                if(s.find(num)!=s.end()){
                    if(!temp) temp=1;
                    else temp*=2;
                }
            }
        }

        sum+=temp;
    }

    cout<<sum<<endl;
}

int main(){

    txtio;
    process();

    return 0;
}