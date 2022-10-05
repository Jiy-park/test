#include<iostream>
using namespace std;
int** CreateArr(int N, int M){
    int** arr;
    arr = new int*[N+2];
    for(int i = 0; i < N+2; i++) { arr[i] = new int[M+2]; }

    for(int i = 0; i < N+2; i++){
        if(i == 0 || i == N+1){
            for(int j = 0; j <= M+1; j++) { arr[i][j] = 0; }
        }
        else{         
            for(int j = 0; j < M+1; j++) { 
                if(j == 0){
                    arr[i][0] = 0; 
                    arr[i][M+1] = 0; 
                }
                else { cin>>arr[i][j]; }     
            }     
        }
    }
    return arr;
}
void PrintArr(int N, int M, int**arr){
    for(int i = 0; i < N+2; i++){
        for(int j = 0; j < M+2; j++) { cout<<arr[i][j]; }
        cout<<"\n";
    }
}

bool Check_I_Block(int& tetroSum, int& maxSum, int** arr, int i, int j){
    for(int s = 0; s < 2; s++){//회전 하면서
        tetroSum = 0;
        switch(s){
        case 0://수평 일자
            for(int r = 0; r < 4; r++){
                if(arr[i][j+r] == 0) { return false; }
                else { tetroSum += arr[i][j+r]; }
            }
            if(maxSum < tetroSum) { maxSum = tetroSum; }
            break;
        case 1://수직 일자
            for(int r = 0; r < 4; r++){
                if(arr[i+r][j] == 0) { return false; }
                else { tetroSum += arr[i+r][j]; }
            }
            if(maxSum < tetroSum) { maxSum = tetroSum; }
            break;
        }
    }
    return true;
}

bool Check_O_Block(int& tetroSum, int& maxSum, int** arr, int i, int j){
    tetroSum = 0;
    if(arr[i+1][j] == 0 || arr[i][j+1] == 0) { return false; }
    else{
        tetroSum += arr[i][j];
        tetroSum += arr[i][j+1];
        tetroSum += arr[i+1][j];
        tetroSum += arr[i+1][j+1];
    }
    if(maxSum < tetroSum) { maxSum = tetroSum; }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 0, M = 0;
    int tetroSum = 0, maxSum = 0;
    cin>>N>>M;

    int** arr = CreateArr(N, M);    
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++){
            for(int k = 0; k < 5; k++){//테트로 개수만큼, 0 = 바, 1 = 네모, 2 = ㄴ, 3 = ㄹ, 4 = ㅗ
                switch(k){
                case 0://바
                    Check_I_Block(tetroSum, maxSum, arr, i, j);
                    break;
                case 1://네모
                    Check_O_Block(tetroSum, maxSum, arr, i, j);
                    break;
                case 2://ㄴ
                    tetroSum = 0;
                    for(int r = 0; r < 2; r++){//대칭
                        switch(r){
                        case 0:
                            for(int s = 0; s < 4; s++){//회전
                                for(int t = 0; t < 4; t++){//한번
                                    switch(t){
                                    case 0:
                                        tetroSum += arr[i][j];
                                        break; 
                                    case 1:
                                        if(arr[i][j])
                                    case 2:
                                    case 3:
                                    }
                                }
                            }
                            break;
                        case 1:
                            break;
                        }
                    }
                    break;
                case 3:
                    break;
                case 4:
                    break;  
                }
            }
        }
    }

    cout<<"\n\n"<<maxSum<<"\n";



    for(int i = 0; i < N+2; i++) { delete[] arr[i]; }
    delete[] arr;

    return 0;
}