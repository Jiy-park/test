//9461_파도반 수열 :: 2022_03_16__21:16
//https://www.acmicpc.net/problem/9461

#include<iostream>
using namespace std;
#define ll long long int

ll func(ll* arr, int N){
    if(arr[N] != -1) { return arr[N]; }
    arr[N] = func(arr, N-1) + func(arr, N-5);
    return arr[N];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 0, N = 0;
    ll res = 0;
    ll arr[101];
    
    //init_arr
    for(int i = 0; i < 101; i++) { arr[i] = -1; }
    // init_arr
    arr[0] = 0;     arr[1] = 1;
    arr[2] = 1;     arr[3] = 1;
    arr[4] = 2;
    cin>>T;
    
    for(int i = 0; i < T; i++){
        cin>>N;
        res = func(arr, N);
        cout<<res<<"\n";
    }
    return 0;
}


