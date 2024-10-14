//
// Created by 김헌우 on 2024/09/14.
//19942 조합
#include <iostream>
#include <vector>
#include <algorithm>
//60분
using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<vector<int>> v; //입력 받음
vector<int> visited; //어떤거 방문했는지 cnt
vector<int> ans;
int n;

//고려 사항 : 조건 x시 -1,하고 밑에 그냥 빈칸, 그냥 int로 해도 될듯, 식재료 번호 오름차순

int min_a,min_b,min_c,min_d;
int min_price = 987654321;
void dfs(int idx, int cnt,int a, int b, int c, int d, int price){
    if(cnt >= 1 && a >= min_a && b >= min_b && c >= min_c && d >= min_d){
//        min_price = min(min_price, price); //이 부분에서 헤맴(최솟값은 잘 구해지는데 조건 다른게 필요해서 주석)
        if(price < min_price){
            min_price = price;
            ans.clear();
            for(int i=0; i<n; i++){
                if(visited[i] == 1 ){
                    ans.push_back(i+1); //번호는 1부터 시작
                }
            }
        }
        //사전순 조합부분에서 문제생겼음
        else if(price == min_price){
            vector<int> cur;
            for(int i=0; i<n; i++){
                if(visited[i] == 1){
                    cur.push_back(i+1);
                }
            }
            if(cur < ans){
                ans = cur;
            }
        }
    }
    //방식은 비슷한데 번호 저장을 위해서 push_back 사용
    for(int i=idx; i<n; i++){
        // if(visited[i]) continue;
        // visited[i] = 1;
        dfs(i+1,cnt+1,a + v[i][0], b + v[i][1], c + v[i][2], d + v[i][3], price + v[i][4]);
        // visited[i] = 0;
    }
}

//n, 영양분 6개, 그 6개에 해당하는 가격, 입력 헷갈렸음
void input(){
    cin >> n;
    v.resize(n,vector<int>(5));
    visited.resize(n);

    cin >> min_a >> min_b >> min_c >> min_d;

    for(int i=0; i<n; i++){
        cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3] >> v[i][4];
    }

}
int main(){
    First

    input();
    dfs(0,0,0,0,0,0,0);


    if(min_price == 987654321){
        cout << -1 << "\n";
    }else{
        //최소값과 visited 정렬하여 리턴
        cout << min_price << "\n"; //min은 잘 구함
        sort(ans.begin(),ans.end());
        for (int i : ans) {
            cout << i << ' '; // 1-based index로 출력
        }

    }
    cout << "\n";

}