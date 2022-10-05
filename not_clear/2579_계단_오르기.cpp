//2579_계단 오르기 :: 2022_03_17__15:13
//https://www.acmicpc.net/problem/2579

#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, score = 0;
    int high_score = 0;
    pair<int, int> arr[301];

    cin>>N>>score;
    arr[0].first = 0;     arr[0].second = -2;
    arr[1].first = score;     arr[1].second = -1;
    
    for(int i = 2; i < N+1; i++){
        cin>>score;
        if(arr[i-1].second == i-2 || arr[i-2].first >= arr[i-1].first){
            arr[i].first = arr[i-2].first + score;
            arr[i].second = i-2;
        }
        else{
            arr[i].first = arr[i-1].first + score;
            arr[i].second = i-1;
        }
        if(arr[i].first > high_score) { high_score = arr[i].first; }
    }

    cout<<high_score;

    return 0;
}


