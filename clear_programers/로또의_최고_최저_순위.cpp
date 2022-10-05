//로또의 최고 순위와 최저 순위 :: 2022_09_02__20:14
//https://school.programmers.co.kr/learn/courses/30/lessons/77484

#include<iostream>
#include<vector>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero_count = 0;
    int win_count = 7;
    bool arr[46] = { false, };
    for(auto& e : win_nums) { arr[e] = true; }
    for(auto& e : lottos){
        if(e == 0) { zero_count++; }
        else if(arr[e] == true) { win_count--; }
    }

    if(win_count == 7) { win_count = 6; }
    if(zero_count == 6) { zero_count = 5; }
    answer.push_back(win_count - zero_count);
    answer.push_back(win_count);

    return answer;
}

int main(){
    return 0;
}
