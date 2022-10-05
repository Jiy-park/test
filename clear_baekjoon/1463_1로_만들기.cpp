//1463_1로 만들기 :: 2022_03_16__00:33
//https://www.acmicpc.net/problem/1463

#include<iostream>
using namespace std;

int func(int* arr, int N){
    if(arr[N] != -1) { return arr[N]; }
    if(N%3 == 0 && N%2 == 0) { arr[N] = min(func(arr, N-1), min(func(arr, N/2), func(arr, N/3))) + 1; }
    else if(N%3 == 0) { arr[N] = min(func(arr, N-1), func(arr, N/3)) + 1; }
    else if(N%2 == 0) { arr[N] = min(func(arr, N-1), func(arr, N/2)) + 1; }
    else { arr[N] = func(arr, N-1) + 1; }
    return arr[N];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0;
    int* arr;
    int res = 0;
    cin>>N;

    //create_arr
    arr = new int[N+1];
    
    //init_arr
    for(int i = 0; i < N+1; i++) { arr[i] = -1; }
    arr[0] = 0;
    arr[1] = 0;
    for(int i = 2; i < 4; i++){
        if(i > N) { break; }
        arr[i] = 1;
    }

    res = func(arr, N);
    cout<<res<<"\n";

    //delete_arr
    delete[] arr;
    return 0;
}


