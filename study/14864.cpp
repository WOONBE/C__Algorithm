#include <iostream>
#include <algorithm>
#include <vector>



using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N,M,fir,sec;
vector<int> v(100001,0);
int grade_cnt[100001];
int main(){
    First

    cin >> N >> M;

    for(int i=1; i<=N; i++){
        v[i] = i;
    }
    for(int i=0; i<M; i++){
        cin >> fir >> sec;
        v[fir]++;
        v[sec]--;
    }

    for(int i=1; i<=N; i++){
        grade_cnt[v[i]]++;
    }

    for(int i=1; i<=N; i++){
        if(grade_cnt[i] >= 2){
            cout <<  -1 << "\n";
            return 0;
        }
    }

    for(int i=1; i<=N; i++){
        cout << v[i] << ' ';
    }


}