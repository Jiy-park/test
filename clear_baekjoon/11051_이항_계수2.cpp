//11051_이항 계수2 :: 2022_04_03__00:58
//https://www.acmicpc.net/problem/11051

#include<iostream>
using namespace std; 

int arr[1001][501] = { 0, };

int nCk(int N, int K){
    if(K > N-K) { K = N-K; }
    if(arr[N][K] != 0) { return arr[N][K]; }
    arr[N][K] = (nCk(N-1, K-1)%10007 + nCk(N-1, K))%10007; 
    return arr[N][K];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, K = 0;
    

    cin>>N>>K;
    
    for(int i = 1; i < 1001; i++) { arr[i][0] = 1; }
    arr[1][1] = 1;      arr[2][1] = 2;      arr[2][2] = 1;

    cout<<nCk(N, K);
    return 0;
}
