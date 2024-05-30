#include <iostream>

using namespace std;


char arr[3200][6300];
int n;
void drawStar(int x, int y){

    arr[x][y] = '*';
    arr[x+1][y-1] = '*';
    arr[x+1][y+1] = '*';
    for(int i=0; i<5; i++){
        arr[x+2][y-2+i] = '*';
    }
}
void func(int n, int x, int y){

    if(n==3){ //3줄 모으면 return
        drawStar(x,y);
        return;
    }

    func(n/2,x,y);
    func(n/2,x+n/2, y-n/2); //왼쪽
    func(n/2,x+n/2, y+n/2); //오른쪽

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<2*n; j++){
            arr[i][j] = ' '; //배열 초기화
        }
    }
    func(n,0,n-1);
    for(int i=0; i<n; i++){
        for(int j=0; j<2*n-1; j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }
}