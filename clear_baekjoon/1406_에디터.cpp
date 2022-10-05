//1406_에디터 :: 2022_03_29__17:38
//https://www.acmicpc.net/problem/1406

#include<iostream>
#include<deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    deque<char> D1, D2;
    string str;
    char command, ch;
    int N = 0, num = 0;

    cin>>str;
    for(int i = 0; i < str.length(); i++) { D1.push_back(str[i]); }

    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>command;
        if(command == 'L'){
            if(D1.size() == 0) { continue; }
            else{
                D2.push_front(D1.back());
                D1.pop_back();
            }
        }
        else if(command == 'D'){
            if(D2.size() == 0) { continue; }
            else{
                D1.push_back(D2.front());
                D2.pop_front();
            }
        }
        else if(command == 'B'){
            if(D1.size() == 0) { continue; }
            else{
                D1.pop_back();
            }
        }
        else {//command == P
            cin>>ch;
            D1.push_back(ch);
        }
    }
    while(!D1.empty()) { 
        cout<< D1.front();
        D1.pop_front();
    }
    while(!D2.empty()) { 
        cout<< D2.front();
        D2.pop_front();
    }

    return 0;
}