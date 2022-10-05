//9184_신나는 함수 실행 :: 2022_03_16__19:48
//https://www.acmicpc.net/problem/9184

#include<iostream>
using namespace std;

int func(int arr[][21][21], int a, int b, int c){
    if(a<=0 || b<=0 || c<=0) { return 1; }
    if(a>20 || b>20 || c>20) { return arr[20][20][20]; } 
    if(a<b && b<c){ 
        if(arr[a][b][c] == -1) { arr[a][b][c] = func(arr, a, b, c-1) + func(arr, a, b-1, c-1) - func(arr, a, b-1, c); }
        return arr[a][b][c];
    }
    if(arr[a][b][c] == -1) { arr[a][b][c] = func(arr, a-1, b, c) + func(arr, a-1, b-1, c) + func(arr, a-1, b, c-1) - func(arr, a-1, b-1, c-1); }
    return arr[a][b][c];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a = 0, b = 0, c = 0;
    int res = 0;
    int arr[21][21][21];

    //init_arr
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 21; j++){
            for(int k = 0; k < 21; k++) { arr[i][j][k] = -1; }
        }
    }
    arr[0][0][0] = 1;
    arr[20][20][20] = 1048576;
    while(1){
        cin>>a>>b>>c;
        if(a==-1 && b==-1 && c==-1) { break; }
        res = func(arr, a, b, c);
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<res<<"\n";
    }
    return 0;
}


