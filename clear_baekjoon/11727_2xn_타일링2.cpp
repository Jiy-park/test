//11727_2xn 타일링2 :: 2022_03_18__02:40
//https://www.acmicpc.net/problem/11727

#include<iostream>
using namespace std;

int func(int* arr, int N){
    if(arr[N] != -1) { return arr[N]; }
    if(N%2 == 0){ arr[N] = (2*func(arr,N-1)+1)%10007; }
    else { arr[N] = (2*func(arr,N-1)-1)%10007; }
    return arr[N];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0;
    int res = 0;
    int* arr;
    
    cin>>N;

    //create_arr
    arr = new int[N+1];

    //init_arr
    arr[0] = 0;     arr[1] = 1;
    arr[2] = 3;     arr[3] = 5;
    for(int i = 4; i < N+1; i++) { arr[i] = -1; }
    
    res = func(arr, N);
    cout<<res;

    //delete_arr
    delete[] arr;
    return 0;
}


