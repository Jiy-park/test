//10026_적록색약 :: 2022_03_20__18:47
//https://www.acmicpc.net/problem/10026

#include<iostream>
#include<queue>
using namespace std;

void print_arr(int arr[][100], int N){
    cout<<"\n----------| strat |----------\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) { cout<<arr[i][j]<<" "; }
        cout<<"\n";
    }
    cout<<"\n----------| end |----------\n";
}

int func(int arr[][100], int N){
    queue<pair<int,int>> Q;
    int count = 0;
    int yp[4] = {0, 1, 0, -1};
    int xp[4] = {1, 0, -1, 0};

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j] != -3) { 
                Q.push(make_pair(i,j)); 
                int island = arr[i][j];
                arr[i][j] = -3;
                while(!Q.empty()){
                    int Y = Q.front().first, X = Q.front().second;
                    for(int k = 0; k < 4; k++){
                        if(Y+yp[k] < 0 || Y+yp[k] >= N || X+xp[k] < 0 || X+xp[k] >= N) { continue; }
                        if(arr[Y+yp[k]][X+xp[k]] == island) { 
                            Q.push(make_pair(Y+yp[k],X+xp[k])); 
                            arr[Y+yp[k]][X+xp[k]] = -3;
                        }
                    }
                    Q.pop();
                }
                count++;
            }
        }
    }

    return count;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0;
    int res1 = 0, res2 = 0;
    int arr_1[100][100] = {0, };
    int arr_2[100][100] = {0, };//적록색약
    char ch;
    
    cin>>N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>ch;
            if(ch == 'G') { arr_1[i][j] = -1; }
            else if(ch == 'B') {
                arr_1[i][j] = -2;
                arr_2[i][j] = -2;
            }
        }
    }
    // //print_arr
    // print_arr(arr_1, N);
    // print_arr(arr_2, N);

    res1 = func(arr_1, N);
    res2 = func(arr_2, N);


    // cout<<"\n--------------| after |--------------\n";
    // print_arr(arr_1, N);
    // print_arr(arr_2, N);
    

    cout<<res1<<" "<<res2;
    return 0;
}