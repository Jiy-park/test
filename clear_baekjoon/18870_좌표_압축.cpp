//18870_좌표 압축 :: 2022_03_19__20:11
//https://www.acmicpc.net/problem/18870

#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, num = 0;
    vector<int> v;
    map<int,int> m;

    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>num;
        v.push_back(num);
        m.insert(pair<int,int>(num,0));
    }

    map<int,int>::iterator it;
    int count = 0;
    for(it = m.begin(); it != m.end(); it++){
        it->second = count;
        count++;
    }

    for(unsigned int i = 0; i < v.size(); i++) { cout<<m[v[i]]<<" "; }
    return 0;
}


