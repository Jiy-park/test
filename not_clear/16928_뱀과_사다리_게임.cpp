//16928_뱀과 사다리 게임 :: 2022_03_20__20:23
//https://www.acmicpc.net/problem/16928

#include<iostream>
using namespace std;

void print_arr(pair<int,int>* arr, bool first){
    int count = 0;
    if(first){
        cout<<"\n-----| first_start |-----\n";
        for(int i = 1; i < 11; i++) { cout<<i<<" "; }
        cout<<"\n";
        for(int i = 1; i < 101; i++){
            cout<<arr[i].first<<" ";
            count++;
            if(count == 10) { cout<<"\n"; count = 0; }
        }
        cout<<"\n-----| first_end |-----\n";
    }
    else{
        cout<<"\n-----| second_start |-----\n";
        for(int i = 1; i < 11; i++) { cout<<i<<" "; }
        cout<<"\n";
        for(int i = 1; i < 101; i++){
            cout<<arr[i].second<<" ";
            count++;
            if(count == 10) { cout<<"\n"; count = 0; }
        }
        cout<<"\n-----| second_end |-----\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, M = 0;
    int start = 0, destination = 0;
    bool check_arr[101] = { 0, };
    pair<int,int> arr[101];//first = 최소 회수      second = 목적지

    //init_arr
    int count = 0;
    int num = 1;
    for(int i = 2; i < 101; i++){
        arr[i].first = num;
        arr[i].second = 1;
        count++;
        if(count == 6){
            num++;
            count = 0;
        }
    }
    cin>>N>>M;
    for(int i = 0; i < N+M; i++){
        cin>>start>>destination;
        arr[start].second = destination;
    }
    // //print_arr
    // print_arr(arr, true);
    // print_arr(arr, false);
    
    for(int pos = 1; pos < 101; pos++){
        num = 1;
        count = 0;
        if(arr[pos+1].first > arr[pos].first + 1) { arr[pos+1].first = arr[pos].first + 1; }
        if(arr[pos+1].second != 1 && check_arr[pos+1] == false){
            int dest = arr[pos+1].second;
            if(arr[dest].first > arr[pos+1].first){
                arr[dest].first = arr[pos+1].first;
                for(int i = dest+1; i < 101; i++){
                    if(arr[i].first > arr[dest].first+num) { arr[i].first = arr[dest].first+num; }
                    count++;
                    if(count == 6){
                        num++;
                        count = 0;
                    }
                }
            }
            check_arr[pos+1] = true;
        }
    }

    cout<<arr[100].first;
    //print_arr
    print_arr(arr, true);
    print_arr(arr, false);

    return 0;
}