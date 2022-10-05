//1620_나는야 포켓몬 마스터 이다솜 :: 2022_04_01__23:51
//https://www.acmicpc.net/problem/1620

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, K = 0, num = 0;
    vector<string> v;
    string str;
    unordered_map<string,string> m;
    v.push_back("0");

    cin>>N;
    cin>>K;

    for(int i = 1; i <= N; i++){
        cin>>str;
        v.push_back(str);
        m.insert(make_pair(str, to_string(i)));
    }

    for(int i = 0; i < K; i++){
        cin>>str;
        if(m.find(str) != m.end()) { cout<<m[str]<<"\n"; }
        else { cout<<v[stoi(str)]<<"\n"; }
    }

    return 0;
}
