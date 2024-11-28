#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define First ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct point{
    int student_num;
    int score;
};
bool cmp(point a, point b){
    if(a.score == b.score){
        return a.student_num < b.student_num;
    }
    return a.score > b.score;
}
vector<point> v[4];
vector<int> tot(100001);
int N,score;
int main(){
    First
    cin >> N;
    for(int i=0; i<3; i++){
        for(int j=0; j<N; j++){
            cin >> score;
            v[i].push_back({j,score}); //0, 300  1 100 2 400
            tot[j] += score;
        }
    }
    for (int i = 0; i < N; i++) v[3].push_back({i, tot[i]});

    for (int i = 0; i < 4; i++) {
        sort(v[i].begin(), v[i].end(), cmp); 
        int arr[100001] = {0}, rank = 1, temp = 1;
        int top = v[i].front().score;
        arr[v[i].front().student_num] = rank; //등수 매핑

        for (int j = 1; j < v[i].size(); j++) {
            if (v[i][j].score < top) {
                rank += temp; temp = 1;
                arr[v[i][j].student_num] = rank;
                top = v[i][j].score;
            }
            //같은 경우
            else {
                arr[v[i][j].student_num] = rank;
                temp++;
            }
        }
        for (int j = 0; j < v[i].size(); j++)
            cout << arr[j] << " ";
        cout << "\n";
    }
    return 0;
}
