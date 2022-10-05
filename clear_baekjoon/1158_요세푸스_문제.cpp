//1158_요세푸스 문제 :: 2022_03_29__22:43
//https://www.acmicpc.net/problem/1158

#include<iostream>
#include<vector>
using namespace std;


class node{
public:
    node(int num) { m_num = num; }
    int m_num;
    bool check = false;
    node* m_next = nullptr;
};

class list{
public:
    list(int num){
        node* curr = head;
        curr->m_num = 1;
        for(int i = 2; i <= num; i++){
            curr->m_next = new node(i);
            curr = curr->m_next;
        }
        curr->m_next = head;
        tail = curr;             
    }
    
    node* erase(node* prev, node* curr){
        prev->m_next = curr->m_next;
        node* next = curr->m_next;
        delete curr;
        return next;
    }
    void func(int N, int K){
        vector<int> v;
        node* curr = head;
        node* prev = tail;
        while(v.size() != N-1){
            for(int i = 1; i < K; i++) { 
                prev = curr;
                curr = curr->m_next; 
            }
            v.push_back(curr->m_num);
            curr = erase(prev, curr);
        }
        v.push_back(curr->m_num);
        delete curr;

        for(int i = 0; i < N; i++) { 
            if(i == 0) { cout<<"<"; }
            if(i == N-1) { cout<<v[i]<<">"; }
            else { cout<<v[i]<<", "; }
        }
        
    }



    node* head = new node(1);
    node* tail = nullptr;
};


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, K = 0;
    list* l;

    cin>>N>>K;

    l = new list(N);
    l->func(N,K);
    

    return 0;
}