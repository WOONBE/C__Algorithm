//
// Created by 김헌우 on 2024/03/09.
//중간 경로 구할때 nxt라는 배열 따로 둬서 출력
#include <iostream>
#include <vector>

using namespace std;
const int INF = 100000000;
int dis[101][101];
int nxt[105][105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;

    cin >> n >> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i==j) dis[i][j] = 0;
            else dis[i][j] = INF;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b],c);
        nxt[a][b] = b;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){ //이부분 범위 잘못 설정해서 드럽게 오래 걸림
                if(dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = min((dis[i][k] + dis[k][j]) , dis[i][j]);
                    nxt[i][j] = nxt[i][k];

                }
            }
        }
    }





    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            if(dis[i][j] == INF) cout << "0 ";
            else cout << dis[i][j]<< " ";
        cout << "\n";
    }
    for(int i=1; i<=n ; i++){
        for(int j =1; j<=n; j++){
            if(dis[i][j] == 0 || dis[i][j] == INF){
                cout << "0\n";
                continue;
            }
            vector<int> path;
            int st = i;
            while(st != j){
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);
            cout << path.size() << ' ';
            for(auto x : path)
                cout << x << ' ';
            cout << "\n";
        }
    }

}
