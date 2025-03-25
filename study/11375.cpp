#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N,M;
vector<int> v[1001];
bool visited[1001]; //업무를 방문했는지 체크
int worker[1001]; //해당 직원이 담당하는 일 저장

bool dfs(int num){
    if(visited[num]) return false;
    visited[num] = true;

    for(auto i : v[num]){
        if(!worker[i] || dfs(worker[i])){
            worker[i] = num;
            return true;
        }
    }
    return false;
}

int bipartite_match(){
    int ans = 0;
    for(int i=1; i<=N; i++){
        memset(visited,false,sizeof(visited));
        if(dfs(i))
            ans++;
    }
    return ans;


}

int main(){
    First
    cin >> N >> M;

    int a,b;
    for(int i=1; i<=N; i++){
        cin >> a;
        for(int j=0; j<a; j++){
            cin >> b;
            v[i].push_back(b);
        }
    }

    cout << bipartite_match() << "\n";

}