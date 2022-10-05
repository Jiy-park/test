//2448_별찍기11 :: 2022_05_01__05:45
//https://www.acmicpc.net/problem/2448

#include<iostream>
using namespace std;

bool board[3100][6200] = { 0, };

void draw(pair<int,int> sp){
    int y = sp.first;
    int x = sp.second;

    board[y][x] = true;
    board[y+1][x-1] = true;
    board[y+1][x+1] = true;
    for(int i = -2; i <= 2; i++) { board[y+2][x+i] = true; }
}

void func(pair<int,int> sp, int N, int K){
    if(K == 1) { draw(sp);}
    else{
        func(sp, N/2, K/2);
        func(make_pair(sp.first+N/2, sp.second-N/2), N/2, K/2);
        func(make_pair(sp.first+N/2, sp.second+N/2), N/2, K/2);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0;
    cin>>N;

    func(make_pair(0, N-1) ,N, N/3);

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= 2*N-2; j++){
            if(board[i][j] == false) { cout<<" "; }
            else { cout<<"*"; }
        }
        cout<<"\n";
    }
    return 0;
}
