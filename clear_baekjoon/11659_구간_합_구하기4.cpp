//11659_구간 합 구하기4 :: 2022_03_18__16:51
//https://www.acmicpc.net/problem/11659

#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, M = 0;
    int num = 0;
    int start = 0, end = 0;
    int arr[100001] = { 0, };

    cin>>N>>M;

    for(int i = 1; i < N+1; i++){
        cin>>num;
        arr[i] = arr[i-1]+num;
    }

    for(int i = 0; i < M; i++){
        cin>>start>>end;
        cout<<arr[end] - arr[start-1]<<"\n";
    }
    return 0;
}


