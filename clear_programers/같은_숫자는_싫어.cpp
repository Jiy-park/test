//같은 숫자는 싫어 :: 2022_09_02__19:00
//https://school.programmers.co.kr/learn/courses/30/lessons/12906

#include<iostream>
#include<vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int prev = -1;
    for(auto& e : arr){
        if(e == prev) { continue; }
        else { 
            answer.push_back(e); 
            prev = e;
        }
    }

    return answer;
}

int main(){
    vector<int> v = { 1,1,3,3,0,1,1 };

    vector<int> v2 = solution(v);
    
    for(auto&e : v2) { cout<<e<<" "; }
    return 0;
}
