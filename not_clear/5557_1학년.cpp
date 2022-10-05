//1학년 :: 2022_09_02__20:14
//https://www.acmicpc.net/problem/5557

#include<iostream>
#include<queue>
using namespace std;

struct calc{
    bool visited = false;
    int minus = -1;
    int plus = -1;
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, num = 0, result = 0;
    long long int count = 0;
    queue<int> nums, sums;
    calc memo[21][21];

    cin>>N;
    for(int i = 0; i < N-1; i++){
        cin>>num;
        nums.push(num);
    }
    cin>>result;
    sums.push(nums.front());
    nums.pop();


    while(nums.size() > 1){
        int nf = nums.front();
        int process_count = sums.size();
        for(process_count; process_count > 0; process_count--){
            int sf = sums.front();
            if(memo[nf][sf].visited == false){
                if(sf - nf >= 0) { memo[nf][sf].minus = sf - nf; }
                if(sf + nf <= 20) { memo[nf][sf].plus = sf + nf; }
                memo[nf][sf].visited = true;
            }
            if(memo[nf][sf].minus != -1) { sums.push(memo[nf][sf].minus); }
            if(memo[nf][sf].plus != -1) { sums.push(memo[nf][sf].plus); }
            sums.pop();
        }
        nums.pop();
    }
    
    int nums_front = nums.front();
    while(!sums.empty()){
        if(sums.front() + nums_front == result) { count++; }
        if(sums.front() - nums_front == result) { count++; }
        sums.pop();
    } 

    cout<<count<<"\n";
    return 0;
}

