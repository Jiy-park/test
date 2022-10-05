//18258_큐2 :: 2022_03_22__09:36
//https://www.acmicpc.net/problem/18258

#include<iostream>
#include<deque>
using namespace std;
    
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    deque<int> D;
    int N = 0;
    int X = 0;
    string command;
    
    cin>>N;

    for(int i = 0; i < N; i++){
        cin>>command;
        if(command == "push") { 
            cin>>X;
            D.push_back(X);
        }
        else if(command == "pop"){
            if(D.empty()) { cout<<"-1\n"; }
            else { 
                cout<<D.front()<<"\n";
                D.pop_front(); 
            }
        }
        else if(command == "size") { cout<<D.size()<<"\n"; } 
        else if(command == "empty"){
            if(D.empty()) { cout<<"1\n"; }
            else { cout<<"0\n"; }
        }
        else if(command == "front"){
            if(D.empty()) { cout<<"-1\n"; }
            else {  cout<<D.front()<<"\n"; }
        }
        else if(command == "back"){
            if(D.empty()) { cout<<"-1\n"; }
            else { cout<<D.back()<<"\n"; }
        }
    }

    return 0;
}