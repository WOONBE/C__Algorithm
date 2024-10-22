#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N;
vector<int> visited; //방문한 전구들 담아둘 배열
vector<int> a;
vector<int> b;
vector<pair<int,int>> light;
int max_cnt = 0;
//스위치와 전구 같은 번호
//2개이상 on일때 겹치면 안켜짐
//안 겹치면서 최대한 많은 전구를 켤때의 수를 구해야함
//출력은 가장 많은 경우인 번호를 오름차순 정렬, 2개 이상이면 하나만 출력
//교체되는 수
//조합 뽑아서 max일때의 visited 배열 출력


//1 1
//2 2 면 ok
//1 2
//2 1 이면 x
//i < i+1, arr[i] > arr[i+1] 이면 불가

//가능한지 판단하는 함수
bool canChoose(){

//    sort(visited.begin(),visited.end());

    for(int i=0; i<visited.size(); i++){
        for(int j=i+1; j<visited.size(); j++){
            if(light[visited[i]].first < light[visited[j]].first &&   light[visited[i]].second < light[visited[j]].second ){
                return true;
            }
        }
    }
    return false;
}
void dfs(int cur, int cnt){

    if(cnt >=N){
        //선택 가능한 max값인지 판별하는 함수랑 max랑 비교
        if(canChoose()){
            max_cnt = max(max_cnt, visited.size());
            for(auto i : visited){
                cout << max_cnt <<"\n";
                sort(visited.begin(),visited.end());
                cout << i+1 << ' ';
            }
        }
        return;
    }

    for(int i=cur; i<N; i++){
        if(visited[i]) continue;
        visited.push_back(i);
        dfs(i+1,cnt+1);
        visited.pop_back();
    }
}

int main(){
    First

    cin >> N;
    for(int i=0; i<N; i++){
        int a1;
        cin >> a1;
        a.push_back(a1);
    }
    for(int i=0; i<N; i++){
        int b1;
        cin >> b1;
        b.push_back(b1);
    }
    for(int i=0; i<N; i++){
        int a2 = a[i];
        int b2 = b[i];
        light.push_back({a2,b2});
    }

//    for(int i=0; i<N; i++){
//        cout << light[i].first << ' ' << light[i].second << "\n";
//    }
    dfs(0,0);


}