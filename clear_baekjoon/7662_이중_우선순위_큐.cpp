//7662_이중 우선순위 큐 :: 2022_03_18__22:40
//https://www.acmicpc.net/problem/7662

#include<iostream>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    multiset<int> ms;
    int T = 0, K = 0;
    char command;
    int N = 0;

    cin>>T;

    for(int i = 0; i < T; i++){
        cin>>K;
        for(int j = 0; j < K; j++){
            cin>>command>>N;
            switch(command){
            case 'I':
                ms.insert(N);
                break;
            case 'D':
                if(ms.empty()) { break; }
                else{
                    if(N == 1) { 
                        multiset<int>::iterator end = ms.end();
                        end--;
                        ms.erase(end); 
                    }
                    else { ms.erase(ms.begin()); }
                }
                break;
            }
        }
        if(ms.empty()) { cout<<"EMPTY\n"; }
        else { 
            multiset<int>::iterator end = ms.end();
            end--;
            cout<<*end<<" "<<*ms.begin()<<"\n"; 
        }
        ms.clear();
    }
    return 0;
}