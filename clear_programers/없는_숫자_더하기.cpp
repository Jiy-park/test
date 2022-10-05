//없는 숫자 더하기 :: 2022_09_02__19:25
//https://school.programmers.co.kr/learn/courses/30/lessons/86051

#include<iostream>
#include<vector>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;
    for(auto& e : numbers) { answer -= e; }
    return answer;
}

int main(){
    return 0;
}
