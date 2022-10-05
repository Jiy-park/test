//10816_숫자 카드2 :: 2022_03_28__18:36
//https://www.acmicpc.net/problem/10816

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unordered_map<int,int> m;
    int N = 0, M = 0, num = 0;

    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>num;
        if(m.find(num) == m.end()) { m.insert(make_pair(num,1)); }
        else { m[num]++; }
    }
    
    cin>>M;
    for(int i = 0; i < M; i++){
        cin>>num;
        if(m.find(num) != m.end()) { cout<<m[num]<<" "; }
        else { cout<<"0 "; }
    }

    return 0;
}