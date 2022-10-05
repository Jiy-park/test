//1991_트리 순회 :: 2022_04_11__11:18
//https://www.acmicpc.net/problem/1991

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void preorder_traversal(int arr[][2], int root){
    char root_ch = (char)(root+65);

    cout<<root_ch;
    if(arr[root][0] != 0) { preorder_traversal(arr, arr[root][0]); }
    if(arr[root][1] != 0) { preorder_traversal(arr, arr[root][1]); }
}
void inorder_traversal(int arr[][2], int root){
    char root_ch = (char)(root+65);

    if(arr[root][0] != 0) { inorder_traversal(arr, arr[root][0]); }
    cout<<root_ch;
    if(arr[root][1] != 0) { inorder_traversal(arr, arr[root][1]); }
}
void postorder_traversal(int arr[][2], int root){
    char root_ch = (char)(root+65);

    if(arr[root][0] != 0) { postorder_traversal(arr, arr[root][0]); }
    if(arr[root][1] != 0) { postorder_traversal(arr, arr[root][1]); }
    cout<<root_ch;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int arr[26][2] = { 0, };
    int N = 0;
    char root, left, right;
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>root>>left>>right;
        if(left != '.') { arr[root-65][0] = left-65; }
        if(right != '.') { arr[root-65][1] = right-65; }
    }
    preorder_traversal(arr,0);
    cout<<"\n";
    inorder_traversal(arr,0);
    cout<<"\n";
    postorder_traversal(arr,0);

    return 0;
}