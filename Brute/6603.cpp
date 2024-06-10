#include <iostream>
#include <cstring>
using namespace std;

int k;
int num[13];
int lotto[6];


void dfs(int start, int select_cnt){
    if(select_cnt == 6){
        for(int i=0; i<6; i++){
            cout << lotto[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for(int i=start; i < k; i++){
        lotto[select_cnt] = num[i];
        dfs(i+1, select_cnt+1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    while(1){
        cin >> k;
        memset(num, 0, sizeof(num));
        memset(lotto, 0, sizeof(lotto));

        if(k==0){
            break;
        }
        for(int i=0; i<k; i++){
            cin >> num[i];
        }
        dfs(0,0);
        cout << "\n";
    }


}
