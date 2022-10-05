//1958_LCS3 :: 2022_09_14__22:23
//https://www.acmicpc.net/problem/1958

#include<iostream>
using namespace std;

int arr[101][101][101] = {0,};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s1, s2, s3;
    cin>>s1>>s2>>s3;

    for(int i = 0; i < s1.size(); i++){
        for(int j = 0; j < s2.size(); j++){
            for(int k = 0; k < s3.size(); k++){
                if(s1[i] == s2[j] && s2[j] == s3[k]) { arr[i+1][j+1][k+1] = arr[i][j][k] + 1; }
                else { arr[i+1][j+1][k+1] = max(arr[i+1][j+1][k], max(arr[i+1][j][k+1], arr[i][j+1][k+1])); }
            }
        }   
    }

    cout<<arr[s1.size()][s2.size()][s3.size()];
    return 0;
}