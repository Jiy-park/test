//11723_집합 :: 2022_03_19__21:46
//https://www.acmicpc.net/problem/11723

#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, X = 0;
    string command;
    bool arr[21] = { 0, };

    cin>>N;

    for(int i = 0; i < N; i++){
        cin>>command;
        if(command == "add"){
            cin>>X;
            arr[X] = true;
        }   
        else if(command == "remove"){
            cin>>X;
            arr[X] = false;
        }
        else if(command == "check"){
            cin>>X;
            if(arr[X]) { cout<<"1\n"; }
            else { cout<<"0\n"; }
        }
        else if(command == "toggle"){
            cin>>X;
            arr[X] = !arr[X];
        }
        else if(command == "all"){
            for(int i = 1; i < 21; i++) { arr[i] = true; }
        }
        else{
            for(int i = 1; i < 21; i++) { arr[i] = false; }
        }
    }

    return 0;
}