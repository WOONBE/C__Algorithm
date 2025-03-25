#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N,C,M,from,to,weight;
int a,b,c,ans,truck_weight[2001];
struct Box{
    int from;
    int to;
    int weight;
};
vector<Box> v;

bool cmp(Box A, Box B){
    if(A.to == B.to){
        return A.from < B.from;
    }
    return A.to < B.to;
}
int main(){
    First

    cin >> N >> C;
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        v.push_back({a,b,c});
    }

    sort(v.begin(),v.end(),cmp);

//    for(auto i : v){
//        cout << i.from << ' ' << i.to << ' ' << i.weight << ' ';
//    }

    for(int i=0; i<v.size(); i++){
        from = v[i].from;
        to = v[i].to;
        weight = v[i].weight;
        int mx_weight = 0;
        for(int j=from; j<to; j++){
            mx_weight = max(mx_weight,truck_weight[j]);
        }
        int can_shift = min(weight,C-mx_weight);

        for(int j=from; j<to; j++){
            truck_weight[j] += can_shift;
        }
        ans += can_shift;
    }
    cout << ans << "\n";

}