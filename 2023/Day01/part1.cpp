#include <bits/stdc++.h>

#define txtio \
    freopen("in.txt", "r", stdin); \
    freopen("op1.txt", "w", stdout);
    
using namespace std;


void process(){
    long long sum = 0;
    string s;

    while(getline(cin, s)){
        int digit1= -1, digit2= -1;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i]>='0' and s[i]<='9'){
                // digit
                if(digit1==-1) digit1=(s[i]-'0');
                digit2=(s[i]-'0');
            }
        }

        int curr_num = digit1*10+digit2;
        sum+=curr_num;
    }

    cout<<sum<<endl;
}

int main(){

    txtio;
    process();

    return 0;
}