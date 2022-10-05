//11047_동전0 :: 2022_09_23__15:02
//https://www.acmicpc.net/problem/11047
#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, K = 0, coin = 0;
    int answer = 0;
    stack<int> coins;

    cin>>N>>K;
    for(int i = 0; i < N; i++){
        cin>>coin;
        coins.push(coin);
    }

    while(!coins.empty()){
        if(K/coins.top() > 0) {
            answer += (K/coins.top());
            K %= coins.top();
        }
        coins.pop();
    }

    cout<<answer;

    return 0;    
}