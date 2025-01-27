#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int arr[21][21];
int N;
int result = 987654321;
bool check[21];
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int get_result(){
    int link_power = 0;
    int start_power = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(check[i] && check[j]){
                link_power += arr[i][j];
            }
            else if(!check[i] && !check[j]){
                start_power += arr[i][j];
            }
        }
    }
    return abs(link_power - start_power);
}

void dfs(int cnt, int idx){

    if(cnt > N/2){
        return;
    }
    if(cnt > 0){
        result = min(result, get_result());
    }
    for(int i=idx; i<N; i++){
        check[i] = true;
        dfs(cnt+1, i+1);
        check[i] = false;
    }
}

int main(){

    First
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    dfs(0,0);

    cout << result;



}