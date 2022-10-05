//1629_곱셈 :: 2022_04_11__01:01
//https://www.acmicpc.net/problem/1629

#include<iostream>
using namespace std;

#define ll long long int

ll func(int A, int B, int C){
    if(B == 1) { return A%C; }
    ll A_half_B = 0;
    if(B%2 == 0){
        A_half_B = func(A, B/2, C);
        return (A_half_B%C*A_half_B%C)%C;
    }
    else{
        A_half_B = func(A, (B-1)/2, C);
        return (A%C * (A_half_B%C*A_half_B%C)%C) % C;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int A = 0, B = 0, C = 0;

    cin>>A>>B>>C;

    ll res = func(A,B,C);

    cout<<res;
    return 0;
}