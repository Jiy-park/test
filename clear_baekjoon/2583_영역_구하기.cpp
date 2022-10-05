//2583_영역 구하기 :: 2022_03_30__01:21
//https://www.acmicpc.net/problem/2583

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void print(int arr[][101], int M, int N){
    for(int i = 0; i < M; i++){
        for(int j = 0;  j < N; j++) { cout<<arr[i][j]; }
        cout<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, M = 0, K = 0;
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
    int arr[101][101] = { 0, };
    int xp[4] = {1, 0, -1, 0};
    int yp[4] = {0, 1, 0, -1};
    vector<int> v;
    queue<pair<int,int>> Q;

    cin>>M>>N>>K;
    for(int i = 0; i < K; i++){
        cin>>n1>>n2>>n3>>n4;
        for(int y = n2; y < n4; y++){
            for(int x = n1; x < n3; x++) { arr[y][x] = 1; }
        }
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j] == 0) { 
                int count = 1;
                Q.push(make_pair(i,j)); 
                arr[i][j] = 1;
                while(!Q.empty()){
                    int y = Q.front().first, x = Q.front().second;
                    for(int k = 0; k < 4; k++){
                        if(y+yp[k] >= M || y+yp[k] < 0 || x+xp[k] >= N || x+xp[k] < 0) { continue; }
                        if(arr[y+yp[k]][x+xp[k]] == 0) {
                            count++;
                            arr[y+yp[k]][x+xp[k]] = 1;
                            Q.push(make_pair(y+yp[k], x+xp[k]));
                        }
                    }
                    Q.pop();
                }
                v.push_back(count);
            }
        }
    }
    sort(v.begin(), v.end());
    cout<<v.size()<<"\n";
    for(unsigned int i = 0; i < v.size(); i++) { cout<<v[i]<<" "; }

    return 0;
}