//14938_서강 그라운드 :: 2022_05_05__01:57
//https://www.acmicpc.net/problem/14938

#include<iostream>
#include<vector>
using namespace std;

#define MAX 16

void print(int arr[][101], int N){
    cout<<"\n----------| START |----------\n";
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) { 
            if(arr[i][j] >= MAX) { cout<<"INF "; }
            else { cout<<arr[i][j]<<" "; }
        }
        cout<<"\n";
    }
    cout<<"----------| END |----------\n";
}

void print_v(vector<int>* v, int N){
    cout<<"\n----------| VECTOR_START |----------\n";
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < v[i].size(); j++) { cout<<v[i][j]<<" "; }
        cout<<"\n";
    }
    cout<<"----------| VECTOR_END |----------\n";
}

void FW(int arr[][101], int N){
    for(int pass = 1; pass <= N; pass++){
        for(int from = 1; from <= N; from++){
            if(pass == from) { continue; }
            for(int to = from; to <= N; to++){
                if(from == to ) { continue; }
                if(arr[from][to] > arr[from][pass]+arr[pass][to]) { 
                    arr[from][to] = arr[from][pass] + arr[pass][to];
                    arr[to][from] = arr[from][pass] + arr[pass][to];
                }
            }
        }
    }
}

int check_max_item(int arr[][101], int item[101], int N, int M){
    //check
    // vector<int> v[101];
    int max_item = 0;
    int sum_item = 0;
    for(int i = 1; i <= N; i++){
        //check
        // v[i].push_back(i);
        sum_item = item[i];
        for(int j = 1; j <= N; j++){
            if(arr[i][j] > M || i == j) { continue; }
            else { sum_item += item[j]; }   // v[i].push_back(j); }//check
        }
        if(sum_item > max_item) { max_item = sum_item; }
    }
    //check
    //print_v(v, N);
    return max_item;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, M = 0, R = 0, T = 0;
    int arr[101][101] = { 0, };
    int item[101] = { 0, };
    int from = 0, to = 0, cost = 0;

    //init_arr
    cin>>N>>M>>R;
    for(int i = 1; i <= N; i++) { cin>>item[i]; }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j) { arr[i][j] = 0; }
            else { arr[i][j] = MAX; }
        }
    }
    for(int i = 0; i < R; i++){
        cin>>from>>to>>cost;
        arr[from][to] = cost;
        arr[to][from] = cost;
    }

    //init_check
    //print(arr, N);

    FW(arr, N);

    //print(arr, N);

    cout<<check_max_item(arr, item, N, M);
    return 0;
}
