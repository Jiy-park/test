//10757_큰 수 A+B :: 2022_09_19__23:56
//https://www.acmicpc.net/problem/10757
#include<iostream>
#include<algorithm>
using namespace std;

// 48 = 0
// 49 = 1


string sum(string& a, string& b){
    string c;
    int carry = 0;
    if(a.size() < b.size()) { swap(a,b); }
    int ai = a.size()-1;
    int bi = b.size()-1;   
    
    while(1){
        int sum = 0;
        if(bi < 0){
            if(ai < 0) { 
                if(carry == 1) { c += '1'; }     
                break;     
            }
            else{
                if(carry == 1){
                    sum = (a[ai]-'0') + carry;
                    if(sum < 10) { carry = 0; }
                    else { 
                        sum -= 10;   
                        carry = 1; 
                    }
                    c += (char)(sum + 48);
                }
                else { c += a[ai]; }
            }
        }
        else{
            sum = (a[ai]-'0') + (b[bi]-'0') + carry;
            if(sum < 10) { carry = 0; }
            else { 
                sum -= 10;   
                carry = 1; 
            }
            c += (char)(sum + 48);
        }
        ai--;   bi--;
    }
    reverse(c.begin(), c.end());
    return c;
}   

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string a;
    string b;

    cin>>a>>b;
    cout<<sum(a, b);
  

    return 0;    
}