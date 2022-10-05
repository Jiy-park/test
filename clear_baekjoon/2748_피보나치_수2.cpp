//2748_피보나치 수 2 :: 2022_03_16__00:47
//https://www.acmicpc.net/problem/2748

#include<iostream>
using namespace std;
#define ll long long int
ll fibo(ll* arr, int N){
    if(arr[N] != -1) { return arr[N]; }
    arr[N] = fibo(arr, N-2) + fibo(arr, N-1);
    return arr[N];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0;
    ll res = 0;
    ll arr[91];
    
    //init_arr
    fill_n(arr, 91, -1);
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    
    cin>>N;

    res = fibo(arr, N);

    cout<<res<<"\n";

    return 0;
}


