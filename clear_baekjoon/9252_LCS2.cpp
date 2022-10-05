//9252_LCS2 :: 2022_09_14__20:50
//https://www.acmicpc.net/problem/9252

#include<iostream>
#include<stack>
using namespace std;

int arr[1002][1002] = {0, };

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s1, s2;
    stack<char> stack;
    cin>>s1>>s2;

    for(int i = 0; i < s1.size(); i++){
        for(int j = 0; j < s2.size(); j++){
            if(s1[i] == s2[j]) { arr[i+1][j+1] = arr[i][j] + 1; }
            else { arr[i+1][j+1] = max(arr[i][j+1], arr[i+1][j]); }
        }
    }
    cout<<arr[s1.size()][s2.size()]<<"\n";
    if(arr[s1.size()][s2.size()] != 0) {
        for(int i= s1.size(), j = s2.size(); i > 0; ){
            if(arr[i][j] == arr[i-1][j]) { i--; }
            else if(arr[i][j] == arr[i][j-1]) { j--; }
            else { stack.push(s1[i-1]); i--; j--; }
        }
        while(!stack.empty()){
            cout<<stack.top();
            stack.pop();
        }
    }
    
    cout<<"\n";
    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++) { cout<<arr[i][j]<<" "; }
        cout<<"\n";
    }



    return 0;
}