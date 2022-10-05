//9375_패션왕 신해빈 :: 2022_03_17__15:13
//https://www.acmicpc.net/problem/9375

#include<iostream>
#include<map>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 0, N = 0;
    string str1, str2;
    map<string,int> m;
    cin>>T; 

    for(int i = 0; i < T; i++){
        cin>>N; 
        int count = 0;
        for(int j = 0; j < N; j++){
            cin>>str1>>str2;
            if(m.find(str2) == m.end()) { m.insert(make_pair(str2,0)); }    
            else { m[str2] += 1; }
        }
        for(int j = 1; j <= m.size(); j++){

        }


        m.clear();
    }
    
    return 0;
}


