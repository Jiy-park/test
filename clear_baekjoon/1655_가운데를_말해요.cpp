//1655_가운데를 말해요 :: 2022_05_09__13:24
//https://www.acmicpc.net/problem/1655

#include<iostream>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    multiset<int> ms;
    int N = 0, num = 0;
    cin>>N;
    cin>>num;
    ms.insert(num);
    set<int>::iterator it = ms.begin();
    cout<<*it<<"\n";
    for(int i = 1; i < N; i++){
        cin>>num;
        ms.insert(num);
        if(ms.size()%2 == 1) { it++; }
        if(num < *it) { it--; }
        cout<<*it<<"\n";
    }
    return 0;
}
