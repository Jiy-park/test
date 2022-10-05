//10830_행렬 제곱 :: 2022_05_13__02:27
//https://www.acmicpc.net/problem/10830

#include<iostream>
#include<array>
using namespace std;

#define ll long long int

array<array<ll,5>,5> Matrix_Multiple(const array<array<ll,5>, 5>& I_A1, const array<array<ll,5>, 5>& I_A2, int N){
    array<array<ll,5>, 5> O_A = {0};
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++) { O_A[i][j] += ((I_A1[i][k] * I_A2[k][j])%1000); }
            O_A[i][j] %= 1000;
        }
    }
    return O_A;
}

array<array<ll,5>,5> func(const array<array<ll,5>, 5>& I_A, int N, ll B){
    if(B == 1) { return I_A; }
    if(B == 2) { return Matrix_Multiple(I_A, I_A, N); }
    array<array<ll,5>, 5> O_A = func(I_A, N, B/2);
    if(B%2 == 0) { return Matrix_Multiple(O_A, O_A, N); }
    else{
        O_A = Matrix_Multiple(O_A, O_A, N);
        return Matrix_Multiple(I_A, O_A, N);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0;
    ll B = 0;
    int num = 0;
    array<array<ll,5>, 5> I_A = {0};
    array<array<ll,5>, 5> O_A = {0};

    cin>>N>>B;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) { cin>>I_A[i][j]; }
    }
     
    O_A = func(I_A, N, B);
    if(B == 1){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++) { O_A[i][j] %= 1000; }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) { cout<<O_A[i][j]<<" "; }
        cout<<"\n";
    }
    return 0;
}
