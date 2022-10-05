//2775_부녀회장이 될테야 :: 2022_03_15__22:54
//https://www.acmicpc.net/problem/2775

#include<iostream>
using namespace std;

int func(int arr[][15], int K, int N){
    if(arr[K][N] != 0) { return arr[K][N]; }
    arr[K][N] = func(arr, K-1, N) + func(arr, K, N-1);
    return arr[K][N];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 0, K = 0, N = 0;
    int res = 0;
    int arr[15][15] = { 0, };

    //init_arr
    for(int i = 1; i < 15; i++) { arr[0][i] = i; }
    for(int i = 0; i < 15; i++) { arr[i][1] = 1; }

    cin>>T;

    for(int i = 0; i < T; i++){
        cin>>K>>N;
        res = func(arr, K, N);
        cout<<res<<"\n";
    }
    return 0;
}


