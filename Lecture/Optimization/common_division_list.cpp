//
// Created by 김헌우 on 2024/09/02.
//14252
#include <iostream>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n,num;


int main(){

    First
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i]; //pushback말고 직접 할당해줘야함(아니면 앞에 0이라 안들어감)
    }

    sort(v.begin(),v.end());
    //앞의 두 수를 보고 평가하면서 나아감
//    set<int> s;
//
//    for(int i=0; i<n-1; i++){
//        //공약수가 1 이상이면
//        if(gcd(v[i], v[i+1]) > 1){
//            s.insert(v[i]);
//            s.insert(v[i+1]);
//        }
//    }
    vector<pair<int,int>> v2; //공약수 구할 값 쌍을 담아둘것임
    for(int i=0; i<n-1; i++){
        if(gcd(v[i], v[i+1]) > 1){
            v2.push_back({v[i],v[i+1]});
        }
    }

//    for(auto i : v2){
//        cout << i.first << ' ' << i.second << "\n";
//    }

    int cnt = 0;
    int start = 0;
    int end = 0;
    for(auto i : v2){
        start = i.first;
        end = i.second;
        bool one_input = false;
        for(int j = start+1; j<end; j++){ //값이 포함되면 안됨(사이의 값들을 다 돌아보면서)
            int tmp = 0;
            if(gcd(start,j)==1) tmp++;
            if(gcd(end,j) == 1) tmp++;

            if(tmp > 1){
                cnt++;
                one_input = true;
                break;
            }

        }
        if(!one_input){ //이 분기문 잘못 넣어서 오류
            cnt += 2;
        }
    }
    cout << cnt << "\n";

}
