#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int m;
int state;

int main(){
    First

    cin >> m;
    string cal;
    int num;
    while(m--){
        cin >> cal;

        if(cal == "add"){
            cin >> num;
            state |= 1<<(num-1);

        }else if(cal == "remove"){
            cin >> num;
            state &= ~(1<<(num-1));

        }else if(cal == "check"){
            cin >> num;
            cout << ((state >> (num-1)) & 1) << "\n";
        }else if(cal == "toggle"){
            cin >> num;
            state ^= 1<<(num-1);

        }else if(cal == "all"){
            state = 0xfffff;
        }else{
            state = 0;

        }
    }






}
