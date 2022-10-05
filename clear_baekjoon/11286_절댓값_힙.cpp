//11286_절댓값 힙 :: 2022_03_19__21:21
//https://www.acmicpc.net/problem/11286

#include<iostream>
#include<queue>
using namespace std;

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.first == b.first) { return a.second > b.second; }
        return a.first > b.first;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, num = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> PQ;

    cin>>N;

    for(int i = 0; i < N; i++){
        cin>>num;
        switch(num){
        case 0:
            if(PQ.empty()) { cout<<"0\n"; }
            else{
                cout<<PQ.top().second<<"\n";
                PQ.pop();
            }
            break;
        default:
            PQ.push(make_pair(abs(num), num));
            break;
        }
    }
    return 0;
}


