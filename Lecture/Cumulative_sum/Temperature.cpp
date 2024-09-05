//
// Created by 김헌우 on 2024/09/03.
//2559


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int a,b; //전체 숫자, 간격

int main(){

    First

    cin >> a >> b;
    vector<int> v(a+1);
    for(int i=0; i<a; i++){
        cin >> v[i];
    }

    vector<int> prefix(a);

    //누적합을 설정
    prefix[0] = v[0];
    for(int i=1; i<a; i++){
        prefix[i] = prefix[i-1] + v[i];
    }

    vector<int> answer;
    for(int i=b-1; i<a; i++){ //이 부분의 시작 코드 수정해줘야함(그냥 b로 하면 터짐)
        answer.push_back(prefix[i] - prefix[i-b]);

    }

    sort(answer.begin(),answer.end(),greater<int>());

    int max_sum = *max_element(answer.begin(), answer.end());
//    cout << answer[0] << "\n";
    cout << max_sum << "\n";


}
