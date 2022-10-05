//11724_연결 요소의 개수 :: 2022_03_13__21:22
//https://www.acmicpc.net/problem/11724

#include<iostream>
#include<queue>
using namespace std;

void print_arr(int** arr, int N){
    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < N+1; j++) { cout<<arr[i][j]<<" "; }
        cout<<"\n";    
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, M = 0;
    int count = 0;
    int vertex1 = 0, vertex2 = 0;
    int** arr;
    bool* vertex_list;
    queue<int> Q;

    cin>>N>>M; 

    //create_arr
    arr = new int*[N+1];
    for(int i = 0; i < N+1; i++) { arr[i] = new int[N+1]; }
    vertex_list = new bool[N+1];

    //init_arr
    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < N+1; j++) { arr[i][j] = 0; }
    }
    for(int i = 0; i < N+1; i++) { vertex_list[i] = false; }

    //input_data
    for(int i = 0; i < M; i++){
        cin>>vertex1>>vertex2;
        arr[vertex1][vertex2] = 1;
        arr[vertex2][vertex1] = 1;
    }

    //print_arr
    // print_arr(arr, N);

    for(int i = 1; i < N+1; i++){
        if(vertex_list[i] == false){
            Q.push(i);
            vertex_list[i] = true;
            count++;
            while(!Q.empty()){
                for(int j = 0; j < N+1; j++){
                    if(arr[Q.front()][j] == 1){
                        if(vertex_list[j] == false){
                            Q.push(j);
                            vertex_list[j] = true;
                        }
                    }
                }
                Q.pop();
            }
        }
    }

    //print_answer
    cout<<count;

    for(int i = 0; i < N+1; i++) { delete[] arr[i]; }
    delete[] arr;
    return 0;
}