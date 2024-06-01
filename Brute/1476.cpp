#include <iostream>

using namespace std;

int e,s,m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> e >> s >> m;
    int year = 1;

    while(1){
        if((e - year) % 15 == 0 && (s - year) % 28 == 0 && (m - year) % 19 == 0 ){
            cout << year << "\n";
            break;
        } else{
            year++;
        }
    }
}
