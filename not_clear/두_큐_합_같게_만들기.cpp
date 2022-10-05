//두 큐 합 같게 만들기 :: 2022_09_02__12:46
//https://school.programmers.co.kr/learn/courses/30/lessons/118667

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define ll long long int

ll sum_vector(vector<int>& v){
    ll sum = 0;
    for(auto& e : v) { sum += e; }
    return sum;
}

queue<int> make_q(vector<int>& v){
    queue<int> q;
    for(auto& e : v) { q.push(e); } 
    return q;
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    int count = 0;
    ll sum_queque1 = sum_vector(queue1);
    ll sum_queque2 = sum_vector(queue2);
    if((sum_queque1 + sum_queque2)%2 == 1) { return -1; }
    ll sum_half  = (sum_queque1 + sum_queque2)/2;
    queue<int> q1 = make_q(queue1);
    queue<int> q2 = make_q(queue2);
    queue<int> queue1_copy = q1;
    queue<int> queue2_copy = q2;

    while(1){
        if(sum_queque1 > sum_half){
            q2.push(q1.front());
            sum_queque2 += q1.front();
            sum_queque1 -= q1.front();
            q1.pop();
        }
        else if(sum_half < sum_queque2){
            q1.push(q2.front());
            sum_queque1 += q2.front();
            sum_queque2 -= q2.front();
            q2.pop();
        }
        else { return count; }
        if(queue1_copy == q1 || queue1_copy == q2 &&
            queue2_copy == q1 || queue2_copy == q2) { return -1; }
        count++;
    }
}

int main(){
    vector<int> v = { 1, 2, 3 };
    cout<<sum_vector(v);
    return 0;
}