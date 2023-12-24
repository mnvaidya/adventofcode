#include <bits/stdc++.h>

#define txtio \
    freopen("in.txt", "r", stdin); \
    freopen("op2.txt", "w", stdout);
    
using namespace std;
char ar[140][140];
int n = 140;      // n*n grid

map<int, vector<int>> mp;     

void input(){
    string s; 
    int row =0;

    while(getline(cin, s)){
        int n= s.length();
        for(int col=0; col<n; col++){
            ar[row][col]=s[col];
        }
        row++;
    }

    return;
}

void process(){

    for(int i=0; i<n; i++){
        int row = i; 
        int col1=-1, col2=-1;
        int num = 0;

        for(int j=0; j<n; j++){
            if(ar[i][j]>='0' and ar[i][j]<='9'){
                col1=j;
                while(ar[i][j]>='0' and ar[i][j]<='9'){
                    col2=j; 
                    num=num*10+(ar[i][j]-'0');
                    j++;
                }
                j--;

                // [row, col1]  [row, col2]
                int temp=0;
                if((col1-1)>=0 and (row-1)>=0 and ar[row-1][col1-1]=='*') temp= (((row-1)<<16) + col1-1);
                if((col1-1)>=0 and ar[row][col1-1]=='*') temp=(((row)<<16) + col1-1);
                if((col1-1)>=0 and (row+1)<n and ar[row+1][col1-1]=='*') temp=(((row+1)<<16) + col1-1);

                if((col2+1)<n and (row-1)>=0 and ar[row-1][col2+1]=='*') temp=(((row-1)<<16) + col2+1);
                if((col2+1)<n and ar[row][col2+1]=='*') temp=(((row)<<16) + col2+1);
                if((col2+1)<n and (row+1)<n and ar[row+1][col2+1]=='*') temp=(((row+1)<<16) + col2+1);

                for(int k=col1; k<=col2; k++){
                    if((row-1)>=0 and ar[row-1][k]=='*') temp=(((row-1)<<16) + k);
                    if((row+1)<n and ar[row+1][k]=='*') temp=(((row+1)<<16) + k);
                }

                mp[temp].push_back(num);
                temp=0;
                num=0;
            }
        }
    }

    long long sum =0;
    for(auto it: mp){
        if(it.second.size()==2){
            sum+=(it.second[0]*it.second[1]);
        }
    }
    cout<<sum<<endl;
}

int main(){

    txtio;
    input();
    process();

    return 0;
}