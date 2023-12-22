#include <bits/stdc++.h>

#define txtio \
    freopen("in.txt", "r", stdin); \
    freopen("op1.txt", "w", stdout);
    
using namespace std;

void process(){
    int rgb[]={0, 0, 0};      // max - 12 13 14
    string s; 
    int sum = 0;

    while(getline(cin, s)){
        stringstream ss(s);
        string word="";
        ss>>word;       // Game
        ss>>word;
        word.pop_back();
        string game_id=word;

        int valid_sets=0;       
        int total_sets=0;
        bool set_complete= 0;

        while(ss>>word){
            int cnt = stoi(word);
            ss>>word;     // red/green/blue
            if(word.back()==';' or ss.eof()) set_complete=1, total_sets++;
            if(word.back()==';' or word.back()==',') word.pop_back();

            if(word=="red") rgb[0]=cnt;
            else if(word=="green") rgb[1]=cnt;
            else rgb[2]=cnt;

            if(set_complete){
                if(rgb[0]<=12 and rgb[1]<=13 and rgb[2]<=14){
                    // valid
                    valid_sets++;
                }
                set_complete=0;
                rgb[0]=0, rgb[1]=0, rgb[2]=0;
            }
        }
        if(valid_sets==total_sets) sum+=stoi(game_id);
    }
    
    cout<<sum<<endl;
}

int main(){

    txtio;
    process();

    return 0;
}