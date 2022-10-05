//2294_동전2 2022_03_31::20:39
//https://www.acmicpc.net/problem/2294
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int func(int* arr, vector<int>& v, int K){
    if(arr[K] != 100010) { return arr[K]; }
    for(unsigned int i = 0; i < v.size(); i++){
        if(v[i] > K) { continue; }
        arr[K] = min(arr[K], func(arr, v, v[i]) + func(arr, v, K-v[i]));
    }
    if(arr[K] == 100010) { arr[K] = 100011; }
    return arr[K];
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N = 0, K = 0, num = 0;
    int arr[100001];
    vector<int> v;

    fill_n(arr, 100001, 100010);

    cin>>N>>K;
    for(int i = 0; i < N; i++){
        cin>>num;
        arr[num] = 1;
        v.push_back(num);
    }
    arr[0] = 0;
    sort(v.begin(), v.end(), greater<int>());


    int res = func(arr, v, K);
    if(res == 100011 || res == 100010) { cout<<"-1"; }
    else { cout<<res; }


    return 0;
}