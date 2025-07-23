#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

int N, C, M,a,b,c;
int can_shift[10001]; //적재 가능한 최대 무게 저장

struct box{
    int srt;
    int ed;
    int weight;
};

bool cmp(box a, box b){
    if(a.ed == b.ed){
        return a.srt < b.srt;
    }
    return a.ed < b.ed;
}

vector<box> boxes;


int main(){
    First
    cin >> N >> C;
    cin >> M;

    for(int i=1; i<=N; i++){
        can_shift[i] = 0;
    }

    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        boxes.push_back({a,b,c});
    }
    sort(boxes.begin(),boxes.end(),cmp);

    int result = 0;
    for(int i=0; i<boxes.size(); i++){
        int srt = boxes[i].srt;
        int ed = boxes[i].ed;
        int weight = boxes[i].weight;

        int mx_load = 0;
        for(int j=srt; j<ed; j++){
            mx_load = max(mx_load,can_shift[j]);
        }

        int can_shift_weight = min(C - mx_load,weight);

        if(can_shift_weight > 0){
            result += can_shift_weight;
            for(int j=srt; j<ed; j++){
                can_shift[j] += can_shift_weight;
            }
        }
    }
    cout << result << "\n";
}