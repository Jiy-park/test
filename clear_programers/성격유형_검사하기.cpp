//성격유형 검사하기 :: 2022_09_02__12:46
//https://school.programmers.co.kr/learn/courses/30/lessons/118666?language=cpp

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> A = {
        {'R', 0},
        {'C', 0},
        {'J', 0},
        {'A', 0},
        {'T', 0},
        {'F', 0},
        {'M', 0},
        {'N', 0},
    };
    for(int i = 0; i < survey.size(); i++){
        switch(choices[i]){
        case 1:
            A[survey[i][0]] += 3; break;
        case 2:
            A[survey[i][0]] += 2; break;
        case 3:
            A[survey[i][0]] += 1; break;
        case 4:
            break;
        case 5:
            A[survey[i][1]] += 1; break;
        case 6:
            A[survey[i][1]] += 2; break;
        case 7:
            A[survey[i][1]] += 3; break;
        }
    }
    
    A['R'] < A['T'] ? answer += 'T' : answer += 'R';
    A['C'] < A['F'] ? answer += 'F' : answer += 'C';
    A['J'] < A['M'] ? answer += 'M' : answer += 'J';
    A['A'] < A['N'] ? answer += 'N' : answer += 'A';

    return answer;
}

int main(){
    vector<string> survey = {"AN", "CF", "MJ", "RT", "NA"};
    vector<int> choices = {5, 3, 2, 7, 5};
    cout<<solution(survey, choices)<<"\n";
    return 0;
}