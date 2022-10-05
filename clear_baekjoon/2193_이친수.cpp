//2193_이친수 :: 2022_04_02__21:31
//https://www.acmicpc.net/problem/2193

#include<iostream>
using namespace std;

#define ll long long int

ll func(ll* arr, int N){
    if(arr[N] != -1) { return arr[N]; }
    arr[N] = func(arr, N-1) + func(arr, N-2);
    return arr[N];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0;
    ll arr[91] = { 0, };

    cin>>N;

    fill_n(arr, N+1, -1);

    arr[0] = 0;     arr[1] = 1;      
    arr[2] = 1;     arr[3] = 2;


    cout<<func(arr, N);


    return 0;
}
