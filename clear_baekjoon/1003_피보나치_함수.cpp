//1003_피보나치 함수 :: 2022_03_15__22:33
//https://www.acmicpc.net/problem/1003

#include<iostream>
using namespace std;

pair<int,int> fibo_count(pair<int,int>* memo, int N){
    if(memo[N].first != -1 && memo[N].second != -1) { return memo[N]; }
    memo[N].first = fibo_count(memo, N-1).first + fibo_count(memo, N-2).first;
    memo[N].second = fibo_count(memo, N-1).second + fibo_count(memo, N-2).second;
    return memo[N];
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 0, N = 0;
    pair<int,int> res;
    pair<int,int> memo[41];
    cin>>T;
    //first => count_0  second => count_1 
    //init_arr
    for(int i = 0; i < 41; i++){
        memo[i].first = -1;
        memo[i].second = -1;
    }    
    
    memo[0].first = 1;
    memo[0].second = 0;
    memo[1].first = 0;
    memo[1].second = 1;

    for(int i = 0; i < T; i++){
        cin>>N;
        res = fibo_count(memo, N);
        cout<<res.first<<" "<<res.second<<"\n";
    }
    return 0;
}


