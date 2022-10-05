//11779_최소비용 구하기2 :: 2022_09_26__00:39
//https://www.acmicpc.net/problem/11779
#include<iostream>
#include <string>
#include <vector>
#include<cmath>
using namespace std;


bool solution(int x) {
    bool answer = true;
    int n1 = x;
    int n2 = 0;
    while(x > 0){
        n2 += x%10;
        x /= 10;
    }
    
    return n1%n2 == 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    bool s = true;
    cout<<s<<!s;
    s = !s;
    cout<<s;
    return 0;
}