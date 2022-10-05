//10815_숫자 카드 :: 2022_03_29__13:20
//https://www.acmicpc.net/problem/10815

#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, M = 0, num = 0;
    unordered_set<int> s;
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>num;
        s.insert(num);
    }
    
    cin>>M;
    for(int i = 0; i < M; i++){
        cin>>num;
        if(s.find(num) == s.end()) { cout<<"0 "; }
        else { cout<<"1 "; }
    }
    return 0;
}