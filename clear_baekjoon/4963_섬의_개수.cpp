//4963_섬의 개수 :: 2022_03_13__22:32
//https://www.acmicpc.net/problem/4963

#include<iostream>
#include<queue>
using namespace std;

void print_arr(int** arr, int H, int W){
    cout<<"\n-------\n";
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) { cout<<arr[i][j]<<" "; }
        cout<<"\n";
    }
    cout<<"-------\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int W = 0, H = 0;
    int XP[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int YP[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int** arr;
    queue<pair<int,int>> Q;
    while(1){
        int island = 1;

        // cout<<"\n========| strat |========\n";
        cin>>W>>H;
        if(W==0 && H==0) { break; }
        //create_arr
        arr = new int*[H];
        for(int i = 0; i < H; i++) { arr[i] = new int[W]; }

        //init_arr
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++) { arr[i][j] = 0; }
        }

        //input_data
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++) { cin>>arr[i][j]; }
        }

        //print_arr
        // print_arr(arr, H, W);
        
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(arr[i][j] == 1){
                    island++;
                    arr[i][j] = island;
                    Q.push(make_pair(i, j));
                    while(!Q.empty()){
                        for(int k = 0; k < 8; k++){
                            if(Q.front().first+YP[k] < 0 || Q.front().first+YP[k] >= H ||
                                Q.front().second+XP[k] < 0 || Q.front().second+XP[k] >= W) {
                                    continue;
                            }
                            else{
                                if(arr[Q.front().first+YP[k]][Q.front().second+XP[k]] == 1){
                                    arr[Q.front().first+YP[k]][Q.front().second+XP[k]] = island;
                                    Q.push(make_pair(Q.front().first+YP[k], Q.front().second+XP[k]));
                                }
                            }
                        }
                        Q.pop();
                    }
                }
                
            }
        }

        cout<<island-1<<"\n";

        //delete_arr
        for(int i = 0; i < H; i++) { delete[] arr[i]; }
        delete[] arr;
        // cout<<"\n========| end |========\n";
    }

    return 0;
}