//1992_쿼드트리 :: 2022_04_02__01:30
//https://www.acmicpc.net/problem/1992

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void print(int arr[][65], int N){
    cout<<"\n----- | start | -----\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) { cout<<arr[i][j]<<" "; }
        cout<<"\n";
    }
    cout<<"----- | end | -----\n";
}

void func(int arr[][65], vector<string >& v, pair<int,int> sp, int to_Y, int to_X, int depth){
    int start = arr[sp.first][sp.second];
    bool clear = true;
    for(int i = sp.first; i < to_Y; i++){
        for(int j = sp.second; j < to_X; j++){
            if(arr[i][j] != start) {
                v.push_back("(");
                clear = false;
                func(arr, v, make_pair(sp.first, sp.second), to_Y/2, to_X/2, depth/2);
                func(arr, v, make_pair(sp.first, sp.second+depth/2), to_Y/2, to_X, depth/2);
                func(arr, v, make_pair(sp.first+depth/2, sp.second), to_Y, to_X/2, depth/2);
                func(arr, v, make_pair(sp.first+depth/2, sp.second+depth/2), to_Y, to_X, depth/2);
                v.push_back(")");
            }
            if(clear == false) { break; }
        }
        if(clear == false) { break; }
    }
    if(clear == true) { v.push_back(to_string(start)); }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0;
    string str;
    vector<string> v;
    int arr[65][65] = { 0, };

    cin>>N;
    
    for(int i = 0; i < N; i++){
        cin>>str;
        for(int j = 0; j < N; j++) { arr[i][j] = str[j]-48; }
    }

    // print_arr
    // print(arr, N);

    func(arr, v, make_pair(0,0), N, N, N);

    for(unsigned int i = 0; i < v.size(); i++) { cout<<v[i]; }


    return 0;
}
