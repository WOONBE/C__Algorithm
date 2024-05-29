#include <iostream>


using namespace std;

int n;
int board[64][64];

void solve(int n, int x, int y){
    if(n == 1){
        cout << board[x][y];
        return;
    }

    bool zero = true;
    bool one = true;
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(board[i][j] == 1){
                zero = false;
            }
            else{
                one = false;
            }
        }
    }
    if(zero){
        cout << 0;
    }
    else if(one){
        cout << 1;

    }
    else{
        cout << "(";
        solve(n / 2, x, y); //왼쪽 위
        solve(n / 2, x, y + n / 2); //오른쪽 위
        solve(n / 2, x + n / 2, y); //왼쪽 아래
        solve(n / 2, x + n / 2, y + n / 2); //오른쪽 아래
        cout << ")";
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++){
            board[i][j] = s[j] - '0';
        }
    }
    solve(n,0,0);


}
