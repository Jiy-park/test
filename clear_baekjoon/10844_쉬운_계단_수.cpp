//10844_쉬운 계단 수 :: 2022_03_23__01:21
//https://www.acmicpc.net/problem/10844

#include<iostream>
using namespace std;
#define ll long long int

ll func(ll arr[][10], int N, int index){
    if(arr[N][index] != 0) { return arr[N][index]; }
    
    for(int i = 2; i < 8; i++) { arr[N][i] = (func(arr, N-1, i-1) + func(arr, N-1, i+1) % 1000000000); }
    arr[N][1] = (func(arr, N-1, 2) + func(arr, N-2, 1)) % 1000000000;
    arr[N][8] = (func(arr, N-1, 7) + func(arr, N-2, 8)) % 1000000000;
    arr[N][9] = func(arr, N-1, 8) % 1000000000;

    for(int i = 1; i < 10; i++) { arr[N][0] += arr[N][i]; }
    return arr[N][index] % 1000000000;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0;
    ll arr[101][10] = { 0, };

    //init_arr
    for(int i = 1; i <= 2; i++){
        for(int j = 1; j < 10; j++) { arr[i][j] = i; }
    }
    arr[2][9] = 1;      arr[2][0] = 17;     arr[1][0] = 9;

    cin>>N;

    cout<<func(arr, N, 0);

    return 0;
}