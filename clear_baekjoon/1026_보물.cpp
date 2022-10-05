//1026_보물 :: 2022_03_29__13:43
//https://www.acmicpc.net/problem/1026

#include<iostream>
#include<set> 
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, num = 0;
    int sum = 0;
    multiset<int, greater<int>> s1;//내림차순
    multiset<int> s2;//오름차순

    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>num;
        s2.insert(num);
    }

    for(int i = 0; i < N; i++){
        cin>>num;
        s1.insert(num);
    }
    set<int>::iterator it1, it2;

    for(it1 = s1.begin(), it2 = s2.begin(); it1 != s1.end(); it1++,it2++){
        sum += ((*it1) * (*it2));
    }

    cout<<sum;
    return 0;
}