#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N;
vector<vector<int>> arr;
int main(){


    cin >> N;
    arr.resize(N,vector<int>(N,0));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];

        }
    }
    //0이랑 1팀으로 나눠서 1일때 더하고 0일때 다른곳 더해서 서로 빼는 방식으로 풀이
    int ans = 987654321;
    for(int state=1; state<(1<<N); state++){
        int s_sum=0; //1이면 스타트팀 추가
        int l_sum=0; //0이면 링크팀 추가

        vector<int> start_team,link_team;

        for(int j=0; j<N; j++){
            if(state & (1<<j)){
                start_team.push_back(j);
            }
            else{
                link_team.push_back(j);
            }
        }
        if(start_team.size()>0 && link_team.size()>0){
            for (int i = 0; i < start_team.size(); i++) {
                for (int j = 0; j < start_team.size(); j++) {
                    if(i==j) continue;
                    s_sum += arr[start_team[i]][start_team[j]];
                }
            }

            for (int i = 0; i < link_team.size(); i++) {
                for (int j = 0; j < link_team.size(); j++) {
                    if(i==j) continue;
                    l_sum += arr[link_team[i]][link_team[j]];
                }
            }

            ans = min(ans, abs(s_sum - l_sum));
        }


    }

    cout << ans << "\n";






}