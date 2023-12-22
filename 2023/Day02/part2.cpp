#include <bits/stdc++.h>

#define txtio \
    freopen("in.txt", "r", stdin); \
    freopen("op2.txt", "w", stdout);
    
using namespace std;

void process(){
    int rgb[]={0, 0, 0};      // max - 12 13 14
    int mx_rgb[]={0, 0, 0};
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
                for(int i=0; i<3; i++){
                    mx_rgb[i]=max(mx_rgb[i], rgb[i]);
                    rgb[i]=0;
                }
            }
        }

        int power=1;
        for(int i=0; i<3; i++){
            power*=mx_rgb[i];
            mx_rgb[i]=0;
        }
        sum+=power;
    }
    
    cout<<sum<<endl;
}

int main(){

    txtio;
    process();

    return 0;
}