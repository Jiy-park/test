//9095_1,2,3 더하기 :: 2022_03_20__01:41
//https://www.acmicpc.net/problem/9095

#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 0, N = 0;
    int arr[11] = { 0, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274 };
    cin>>T;
    for(int i = 0; i < T; i++){
        cin>>N;
        cout<<arr[N]<<"\n";
    }
    return 0;
}