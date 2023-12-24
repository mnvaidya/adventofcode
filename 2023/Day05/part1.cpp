#include <bits/stdc++.h>

#define txtio \
    freopen("in.txt", "r", stdin); \
    freopen("op1.txt", "w", stdout);
#define ll long long 

using namespace std;

map<pair<ll, ll>, pair<ll, ll>> sts, stf, ftw, wtl, ltt, tth, htl;
vector<ll> seeds;

void process(){
    string s, word;
    getline(cin, s);    // seeds: ...
    stringstream ss(s);
    ss>>word;     // seeds:

    while(ss>>word){
        // taking seeds numbers
        ll seed_n = stoll(word);
        seeds.push_back(seed_n);
    }

    getline(cin, s);       // blank line (2nd line)

    int mp_cnt=-1;
    map<pair<ll, ll>, pair<ll, ll>> temp;

    while(getline(cin, s)){
        if(s.length()==0){
            if(mp_cnt==0) sts=temp;
            else if(mp_cnt==1) stf=temp;
            else if(mp_cnt==2) ftw=temp;
            else if(mp_cnt==3) wtl=temp;
            else if(mp_cnt==4) ltt=temp;
            else if(mp_cnt==5) tth=temp;
            else htl=temp;

            temp.clear();
            continue;
        }
        else if(s[0]=='s' or s[0]=='f' or s[0]=='w' or s[0]=='l' or s[0]=='t' or s[0]=='h'){
            mp_cnt++;
            continue;
        }

        stringstream ss(s);
        ss>>word; ll dest = stoll(word); 
        ss>>word; ll source = stoll(word); 
        ss>>word; ll range = stoll(word);

        temp[make_pair(source, source+range-1)]=make_pair(dest, dest+range-1);
    }

    htl=temp;
    temp.clear();
}

ll lookUp(ll key, map<pair<ll, ll>, pair<ll, ll>> mp){
    for(auto it: mp){
        ll start = it.first.first, end = it.first.second;
        if(key>=start and key<=end){
            ll to_add = it.second.first - it.first.first;
            key+=to_add;
            break;
        }
    }
    return key;
}

int main(){

    txtio;
    process();

    ll mn_location = LLONG_MAX;
    for(int i=0; i<seeds.size(); i++){
        ll seed = seeds[i];

        ll soil = lookUp(seed, sts);
        ll fertilizer = lookUp(soil, stf);
        ll water = lookUp(fertilizer, ftw);
        ll light = lookUp(water, wtl);
        ll temperature = lookUp(light, ltt);
        ll humidity = lookUp(temperature, tth);
        ll location = lookUp(humidity, htl);
        mn_location= min(mn_location, location);

        // cout<<seed<<" "<<soil<<" "<<fertilizer<<" "<<water<<" "<<light<<" "<<temperature<<" "<<humidity<<" "<<location<<endl;
    }

    cout<<mn_location<<endl;

    return 0;
}