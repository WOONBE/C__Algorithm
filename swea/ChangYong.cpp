#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//유니온 파인드
int T, N, M, ans;
int parent[101];


int find(int tar){
    if(tar == parent[tar]){ //자신이 가장 위의 노드이면, 비교하는부분 실수
        return tar;
    }
    int ret = find(parent[tar]); //아니면 가장 위의 노드 find
    parent[tar] = ret; //재귀 덜 돌게 값 설정
    return ret;
}

void setUnion(int a, int b){
    int t1 = find(a);
    int t2 = find(b);

    if(t1 == t2){
        return;
    }
    parent[t2] = t1;

}

void init()
{
    ans = 0;
}
void parentInit(){
    for(int i=1; i<=N; i++){
        parent[i] = i;
    }
}

void input()
{
    cin >> N >> M;

    parentInit();

    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        setUnion(a,b);
    }
}

void solve()
{
    for(int i=1; i<=N; i++){
        if(i == find(i))
        {
            ans++;
        }
    }

}

int main()
{
//    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        init();
        input();
        solve();
        cout << "#" << tc << " " << ans << endl;
    }
}