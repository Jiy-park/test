//11279_최대 힙 :: 2022_03_19__20:56
//https://www.acmicpc.net/problem/11279

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, num = 0;
    vector<int> v;
    cin>>N;
    make_heap(v.begin(), v.end());

    for(int i = 0; i < N; i++){
        cin>>num;
        switch(num){
        case 0:
            if(v.empty()) { cout<<0<<"\n"; }
            else{
                cout<<v[0]<<"\n";
                pop_heap(v.begin(), v.end());
                v.pop_back();
            }
            break;
        default:
            v.push_back(num);
            push_heap(v.begin(), v.end());
            break;
        }
    }
    return 0;
}