//10867_중복 빼고 정렬하기 :: 2022_03_29__17:45
//https://www.acmicpc.net/problem/10867

#include<iostream>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    set<int> s;
    int N = 0, num = 0;

    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>num;
        s.insert(num);
    }
    set<int>::iterator it;
    for(it = s.begin(); it != s.end(); it++) { cout<<*it<<" "; }  

    return 0;
}


