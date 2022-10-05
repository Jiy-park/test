//1149_RGB거리 :: 2022_03_16__21:16
//https://www.acmicpc.net/problem/1149

#include<iostream>
using namespace std;

enum {
    Red = 0, Green, Blue
};

void print_arr(int arr[][3], int N){
    cout<<"\n------|  print_start |------\n";
    for(int i = 1; i < N+1; i++) { cout<<arr[i][Red]<<" "<<arr[i][Green]<<" "<<arr[i][Blue]<<"\n"; }
    cout<<"------|  print_end |------\n";
}
void func(int arr[][3], int start, int end, int RGB, int cost, int& last_cost){
    if(start == end) {
        if (last_cost > cost+arr[start][RGB]) { last_cost = cost+arr[start][RGB]; }
    }
    else{
        switch(RGB){
        case Red:
            func(arr, start+1, end, Green, cost+arr[start][RGB], last_cost);
            func(arr, start+1, end, Blue, cost+arr[start][RGB], last_cost);
            break;
        case Green:
            func(arr, start+1, end, Red, cost+arr[start][RGB], last_cost);
            func(arr, start+1, end, Blue, cost+arr[start][RGB], last_cost);
            break;
        case Blue:
            func(arr, start+1, end, Red, cost+arr[start][RGB], last_cost);
            func(arr, start+1, end, Green, cost+arr[start][RGB], last_cost);
            break;
        }   
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0;
    int R = 0, G = 0, B = 0; 
    int last_cost = INT32_MAX;
    bool fisrt_save = true;
    int arr[1001][3];

    cin>>N;

    for(int i = 1; i < N+1; i++){
        cin>>R>>G>>B;
        arr[i][Red] = R;
        arr[i][Green] = G;
        arr[i][Blue] = B;
    } 

    // //print_arr
    // print_arr(arr, N);
    
    for(int i = 0; i < 3; i++){
        func(arr, 1, N, i, 0, last_cost);
    }
    cout<<last_cost<<"\n";
    return 0;
}


