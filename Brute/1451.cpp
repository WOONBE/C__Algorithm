#include <iostream>
#include <string>


using namespace std;
int arr[101][101];
int n,m;
long long Max = -1;
int getSum(int sx, int sy, int ex, int ey){
    int sum = 0;
    for(int i=sx; i<=ex; i++){
        for(int j=sy; j<= ey; j++){
            sum+=arr[i][j];
        }
    }
    return sum;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c;
            cin >> c;
            arr[i][j] = c-'0';
        }
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            long long square1 = getSum(0, 0, i, m - 1);
            long long square2 = getSum(i + 1, 0, j, m - 1);
            long long square3 = getSum(j + 1, 0, n - 1, m - 1);
            Max = max(Max, square1*square2*square3);
        }
    }

    //2번 모양
    for (int i = 0; i < m - 2; i++) {
        for (int j = i + 1; j < m - 1; j++) {
            long long square1 = getSum(0, 0, n - 1, i);
            long long square2 = getSum(0, i + 1, n - 1, j);
            long long square3 = getSum(0, j + 1, n - 1, m - 1);
            Max = max(Max, square1*square2*square3);
        }
    }

    //3번 모양
    for (int i = m - 1; i > 0; i--) {
        for (int j = 0; j < n - 1; j++) {
            long long square1 = getSum(0, i, n - 1, m - 1);
            long long square2 = getSum(0, 0, j, i - 1);
            long long square3 = getSum(j + 1, 0, n - 1, i - 1);
            Max = max(Max, square1*square2*square3);
        }
    }

    //4번 모양
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            long long square1 = getSum(0, 0, n - 1, i);
            long long square2 = getSum(0, i + 1, j, m - 1);
            long long square3 = getSum(j + 1, i + 1, n - 1, m - 1);
            Max = max(Max, square1*square2*square3);
        }
    }

    //5번 모양
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            long long square1 = getSum(0, 0, i, m - 1);
            long long square2 = getSum(i + 1, 0, n - 1, j);
            long long square3 = getSum(i + 1, j + 1, n - 1, m - 1);
            Max = max(Max, square1*square2*square3);
        }
    }

    //6번 모양
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < m - 1; j++) {
            long long square1 = getSum(i, 0, n - 1, m - 1);
            long long square2 = getSum(0, 0, i - 1, j);
            long long square3 = getSum(0, j + 1, i - 1, m - 1);
            Max = max(Max, square1*square2*square3);
        }
    }
    cout << Max << endl;

}
