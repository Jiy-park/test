//1932_정수 삼각형 :: 2022_03_17__15:13
//https://www.acmicpc.net/problem/1932

#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0;

    int arr[500][500] = { 0, };
    int cost = 0;
    int res = 0;

    cin>>N>>arr[0][0];

    for(int i = 1; i < N; i++){
        for(int j = 0; j <= i; j++){
            cin>>cost; 
            if(j != 0 && j != i) { arr[i][j] = max(arr[i-1][j-1], arr[i-1][j]) + cost; }
            else if(j == 0) { arr[i][j] = arr[i-1][j] + cost; }
            else { arr[i][j] = arr[i-1][j-1] + cost; }
        }    
    }

    for(int i = 0; i < N; i++){
        if(arr[N-1][i] > res) { res = arr[N-1][i]; }
    }

    cout<< res;
    return 0;
}


