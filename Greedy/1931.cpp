#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Time{ //대문자로 처리
    int start;
    int end;
};
vector<Time> schedules;

bool cmp(Time t1, Time t2){
    if(t1.end == t2.end){
        return t1.start < t2.start;
    }
    return t1.end < t2.end;
}
int n;
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        int startTime;
        int endTime;
        cin >> startTime >> endTime;
        schedules.push_back({startTime, endTime});
    }
    sort(schedules.begin(),schedules.end(),cmp);

//    for(int i=0; i<schedules.size(); i++){
//        cout << schedules[i].start << ' ' << schedules[i].end << "\n";
//    }
    int cnt = 0;
    int tme = 0;
    for(int i=0; i<n; i++){
        if(schedules[i].start >= tme) {
            tme = schedules[i].end;
            cnt++;
        }
//        if(tme == 0){
//            tme = schedules[i].end;
//            cnt++;
//        } else{
//            if(tme <= schedules[i+1].start){
//                tme = schedules[i+1].end;
//                cnt++;
//            }else{
//                continue;
//            }
//        }

    }
    cout << cnt << "\n";
}