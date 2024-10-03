#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
vector<int> v;
int main(){
    First

    cin >> n;
    int num;
    int target;
    v.resize(n,0);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cin >> target;

    //정렬시키고 시작
    sort(v.begin(), v.end());

    //종료 조건 : l_idx랑 r_idx가 만날때
    int l_idx = 0;
    int r_idx = n-1;
    int cnt = 0;
    //조건도 수정
    while(l_idx < r_idx) {
        //타겟보다 더 큰 수만큼 땡김 (이거 필요없을듯, 어차피 위에 조건에 적혀있음)
//        for(auto i : v){
//            if(i >= target){
//                r_idx --;
//            }
//        }
        //정답이면 cnt++
        if(v[l_idx] + v[r_idx] == target){
            cnt++;
//            l_idx++;
//            r_idx--;
        }
        if(v[l_idx] + v[r_idx] >= target){ //값이 더 크면 오른쪽 큰 값을 줄임(같거나 클때만 적용시켜야함)
            r_idx--;
        } else{ //값이 작으면 왼쪽 idx를 크게
            l_idx++;
        }
    }

    cout << cnt << "\n";


}