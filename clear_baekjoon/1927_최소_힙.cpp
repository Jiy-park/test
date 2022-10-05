//1927_최소 힙 :: 2022_03_18__19:46
//https://www.acmicpc.net/problem/1927

#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue<int, vector<int>, greater<int>> PQ;
    int N = 0, num = 0;

    cin>>N;
    
    for(int i = 0; i < N; i++){
        cin>>num;
        if(num == 0){
            if(PQ.empty()) { cout<<"0\n"; }
            else{
                cout<<PQ.top()<<"\n";
                PQ.pop();
            }
        }
        else { PQ.push(num); }
    }
    return 0;
}


