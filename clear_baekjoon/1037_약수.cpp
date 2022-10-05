//1037_약수 :: 2022_03_30__12:02
//https://www.acmicpc.net/problem/1037

#include<iostream>
#include<vector>
#include<algorithm>  
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, num = 0;
    vector<int> v;
    
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    if(N%2 == 0) { cout<<v[N/2]*v[N/2 - 1]; }
    else { cout<<v[N/2]*v[N/2]; }
 
    return 0;
}