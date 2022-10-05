//17219_비밀번호 찾기 :: 2022_03_20__20:23
//https://www.acmicpc.net/problem/17219

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, M = 0;
    string str1, str2;
    unordered_map<string,string> m;
    cin>>N>>M;

    for(int j = 0; j < N; j++){
        cin>>str1>>str2;
        m.insert(make_pair(str1,str2));
    }
    for(int i = 0; i < M; i++){
        cin>>str1;
        unordered_map<string,string>::iterator it = m.find(str1);
        if(it != m.end()) { cout<<it->second<<"\n"; }
    }

    return 0;
}