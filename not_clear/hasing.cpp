#include<iostream>
#include<vector>
// #include<cmath>


using namespace std;
unsigned long long pow_31(int x){
    unsigned long long result = 1;
    for(int i = 0; i < x; i++) { result *= (31%1234567891); }
    return result;   
}


int main(){
    int L = 0; 
    unsigned long long sum = 0, H = 0;
    string str;
    vector<int> arr;
    
    
    cin>>L>>str;
    
    for(unsigned int i = 0; i < str.size(); i++) { arr.push_back((str[i])-96); } 
    for(int i = 0; i < L; i++) { sum += (arr[i] * pow_31(i)); }

    // H = sum % 1234567891; 
    cout<<sum;   
    

    return 0;
}