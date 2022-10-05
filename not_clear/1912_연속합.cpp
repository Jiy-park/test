//1912_연속합 :: 2022_03_30__01:21
//https://www.acmicpc.net/problem/1912

#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, num = 0;
    int arr[100000] = { 0, };

    cin>>N;
    for(int i = 0; i < N; i++) { 
        cin>>num;
        arr[i] = num;
    }

    int max = arr[0];
    int sum = arr[0];
    for(int i = 1; i < N; i++){
        if(sum+arr[i] >= max) { 
            sum += arr[i];
            max = sum;
        }
        else{
            for(int j = 1; i+j < N; j++){
                if(arr[i] < arr[i+j]) { 
                    i += j; 
                    break;
                }
                if(i+j == N-1) { i+=j; }
            }
            sum = arr[i];
        }
    }

    cout<<max;

    return 0;
}