#include <bits/stdc++.h>

#define txtio \
    freopen("in.txt", "r", stdin); \
    freopen("op2.txt", "w", stdout);
    
using namespace std;


void process(){
    long long sum = 0;
    string s;

    string ar[]={"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    while(getline(cin, s)){
        int digit1= -1, digit2= -1;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i]>='0' and s[i]<='9'){
                // digit
                if(digit1==-1) digit1=(s[i]-'0');
                digit2=(s[i]-'0');
                // continue;
            }
    
            string window1 ="", window2="", window3="";
            if((i+1)<n and (i+2)<n){
                window1=s[i];
                window1+=s[i+1];
                window1+=s[i+2];
            }
            if((i+3)<n) window2=window1+s[i+3];
            if((i+4)<n) window3=window2+s[i+4];

            // cout<<"window1:"<<window1<<" window2:"<<window2<<" window3:"<<window3<<" ";

            int temp=-1;
            for(int j=0; j<9; j++){
                if(ar[j]==window1 or ar[j]==window2 or ar[j]==window3) temp=j+1;
                if(temp!=-1){
                    if(digit1==-1) digit1=temp;
                    digit2=temp;
                }
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