//1676_팩토리얼 0의 개수 :: 2022_03_18__01:56
//https://www.acmicpc.net/problem/1676

#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0;
    int div_5 = 0, div_25 = 0, plus_5 = 0;
    cin>>N;

    div_5 = N/5;
    div_25 = N/25;
    if(div_25 >= 5) { plus_5 = div_25/5; }
    
    int res = div_5 + div_25 + plus_5;
    cout<<res;
    return 0;
}


