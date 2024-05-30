#include <iostream>
#include <algorithm>

using namespace std;

int n,m,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    int team = 0;
    team = min(n/2, m); //남는 인원 : 전체 - 팀*3(인원수)
    int extra = n + m - (3 * team);
    if(k <= extra) //남는 인원이 차출 인원보다 많으면 그냥 팀 리턴
        cout << team;
    else{ //
        team = team - ((k-extra + 2)/3);
        cout << team;
    }
    return 0;


}
