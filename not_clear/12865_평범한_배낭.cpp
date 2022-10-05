//12865_평범한 배낭 :: 2022_03_23__01:21
//https://www.acmicpc.net/problem/12865

// 14 100
// 61 5
// 62 0
// 41 3
// 12 2
// 71 8
// 55 2
// 34 8
// 41 7
// 17 0
// 24 3
// 18 0
// 65 2
// 66 2
// 93 9

#include<iostream>
using namespace std;

pair<int,int> arr[101][101];

void func(int line, int K, int W, int V, int& max){
    for(int i = 1; i < line; i++){
        for(int j = 1; j <= line; j++){
            if(arr[i][j].first + W > K || i == j){ continue; }
            arr[i][j].first += W;
            arr[i][j].second += V;
            if(arr[i][j].second > max) { max = arr[i][j].second; }
        }
    }
}

void print(int N){
    cout<<"\n----- | start | -----\n";
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) { cout<<arr[i][j].first<<"("<<arr[i][j].second<<") "; }
        cout<<" :: line : "<<i<<" ("<<arr[i][i].first<<")\n";
    }
    cout<<"\n----- | end | -----\n";
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    
    int N = 0, K = 0, W = 0, V = 0;
    int num1 = 0, num2 = 0;
    int max = 0;
    // while(1){

        cin>>N>>K;
        for(int i = 1; i <= N; i++){
            cin>>num1>>num2;
            if(K >= num1 && num2 >max) { max = num2; }
            pair<int,int> pair_e = make_pair(num1, num2);
            for(int j = 1; j <= N; j++) { arr[i][j] = pair_e; }
        }

        // if(K >= arr[1][1].first) { max = arr[1][1].second; }

        // print(N);

        for(int i = 1; i <= N; i++){
            func(i, K, arr[i][1].first, arr[i][1].second, max);
            // print(N);
            // cout<<"max : "<<max<<"\n";
        }

        cout<<max<<"\n";
    // }

    return 0;
}