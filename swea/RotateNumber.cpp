//
// Created by 김헌우 on 2023/12/30.
//
#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    int N;
    int a[7][7];
    for(int tc=1; tc<=T; tc++) {
        cin >> N;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++)
                cin >> a[i][j];
        }
        cout << '#' << tc << "\n";

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++)
                cout << a[N-1-j][i];
            cout << " ";
            for(int j=0; j<N; j++)
                cout << a[N-1-i][N-1-j];
            cout << " ";
            for(int j=0; j<N; j++)
                cout << a[j][N-1-i];
            cout << " " << "\n";
        }
    }
}
