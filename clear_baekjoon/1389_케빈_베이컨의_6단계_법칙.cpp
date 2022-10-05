//1389_케빈 베이컨의 6단계 법칙 :: 2022_04_02__01:04
//https://www.acmicpc.net/problem/1389

#include<iostream>
using namespace std;

#define INF 1000000

void print(int arr[][101], int N){
    cout<<"\n------ | start | ------\n";
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) { 
            if(arr[i][j] == INF) { cout<<"F "; }
            else { cout<<arr[i][j]<<" "; }
        }
        cout<<"\n";
    }
    cout<<"------ | end | ------\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, M = 0;
    int from = 0, to = 0;
    int arr[101][101] = { 0, };

    cin>>N>>M;

    //init_ arr
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++) { 
            if(i == j) { arr[i][j] = 0; }
            else {arr[i][j] = INF; }
        }
    } 

    for(int i = 0; i < M; i++){
        cin>>from>>to;
        arr[from][to] = 1;
        arr[to][from] = 1;
    }

    //print_arr
    // print(arr, N);

    for(int path = 1; path <= N; path++){
        for(int i = 1; i <= N; i++){
            if(i == path) { continue; }
            for(int j = 1; j <= N; j++){
                if(j == path || j == i) { continue; }
                if(arr[i][j] > arr[i][path] + arr[path][j]) { arr[i][j] = arr[i][path] + arr[path][j]; }
            }
        }
    }

    pair<int,int> min = make_pair(INF, 0);
    for(int i = 1; i <= N; i++){
        int sum = 0;
        for(int j = 1; j <= N; j++) { sum += arr[i][j]; }
        if(min.first > sum) { min.first = sum;      min.second = i; }
    }

    // print_arr
    // print(arr, N);

    cout<<min.second;
    return 0;
}
