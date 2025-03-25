#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N;

struct ball{
    int color;
    int size;
    int idx;
};
vector<ball> v;
bool cmp(ball a, ball b){
    if(a.size == b.size){
        return a.color < b.color;
    }
    return a.size < b.size;
}
int c[200001]; //색이 같은 공들 무게 합
int s[200001]; //사이즈가 같은 공들 무게 합
int ans[200001]; //정답 저장
int main(){
    First

    cin >> N;

    int clr,sze,idx;

    for(int i=0; i<N; i++){
        cin >> clr >> sze;
        v.push_back({clr,sze,i});
    }

    sort(v.begin(),v.end(),cmp);

//    for(auto i : v){
//        cout << i.color << i.size << i.idx << ' ';
//    }

    int sum = 0;
    for(int i=0; i<N; i++){
        int size = v[i].size;
        int color = v[i].color;
        int idx = v[i].idx;

        if(i != 0 && v[i-1].size == v[i].size && v[i-1].color == v[i].color){
            ans[idx] = ans[v[i-1].idx];
        }else{
            ans[idx] = sum - c[color] - s[size];
        }

        c[color] += size;
        s[size] += size;
        sum += size;
    }

    for(int i=0; i<N; i++){
        cout << ans[i] << "\n";
    }
}