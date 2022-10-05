//9251_LCS :: 2022_09_14__12:39
//https://www.acmicpc.net/problem/9251

#include<iostream>
using namespace std;

int arr[1002][1002] = {0, };

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s1, s2;
    int answer = 0;
    cin>>s1>>s2;

    for(int i = 0; i < s1.size(); i++){
        for(int j = 0; j < s2.size(); j++){
            if(s1[i] == s2[j]) { arr[i+1][j+1] = arr[i][j] + 1; }
            else { arr[i+1][j+1] = max(arr[i][j+1], arr[i+1][j]); }
        }
    }

    cout<<arr[s1.size()][s2.size()];
    return 0;
}