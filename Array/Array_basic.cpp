
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//실패율과 stage를 같이 가지는 구조

struct StageInfo{
    double failRate;
    int stageNumber;
};

//실패율 내림차순, 같을 경우 번호 오름차순
bool compare(StageInfo a,StageInfo b){
    if(a.failRate == b.failRate)
        return a.stageNumber < b.stageNumber;
    return a.failRate > b.failRate;
}


vector<int> solution(int N, vector<int> stages){
    vector<int> cnt;
    cnt.assign(N+1,0);

    //이부분 잘 체크
    for(int i=0; i<stages.size(); i++){
        if(stages[i] <= N){
            cnt[stages[i]-1] += 1;
        }

    }




}

