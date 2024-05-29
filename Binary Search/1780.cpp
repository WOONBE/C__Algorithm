#include <iostream>
using namespace std;

int n;
int arr[2200][2200];
int num[3];

bool check(int x, int y, int n){
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(arr[x][y] != arr[i][j]){
                return false;
            }
        }
    }
    return true;
}

void solve(int x, int y, int z){
    if(check(x,y,z)){ //내부가 다 같은 값이면
        num[arr[x][y] + 1] += 1; //그 값들 count
        return;
    }
    int n = z/3; //아닌 경우는 분할
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            solve(x + i*n, y + j*n, n);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    solve(0,0,n);
    for(int i=0; i<3; i++){
        cout << num[i] << "\n";
    }

}
