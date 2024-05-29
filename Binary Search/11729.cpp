#include <iostream>

using namespace std;

void move(int from, int to, int num){
    if(num == 1){
        cout << from << ' ' << to << "\n";
        return; //리턴해줘야함
    }
    move(from, 6-from-to,num-1);
    cout << from << ' ' << to << "\n";
    move(6-from-to, to, num-1);
}

int k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    cout << (1<<k) - 1 << "\n";
    move(1,3,k);
}
