#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX = 12;
int n,k,m,l;
// prerequisite[i] = i번째 과목의 선수과목 집합
int prerequisite[MAX];
// classes[i] = i번째 학기에 개설되는 과목 집합
int classes[10];
int cache[10][1 << MAX];

//정수 num의 이진수 표현에서 켜진 비트의 수를 반환한다.
int bitCount(int num){
    if(num == 0) return 0;
    return num%2 + bitCount(num/2);
}

int graduate(int semester, int taken){ //현재 학기, 들은 과목수
    // k개 이상의 과목을 이미 들은 경우
    if(bitCount(taken) >= k) return 0;
    // m학기가 전부 지난 경우
    if(semester == m) return INF;

    // 메모이제이션
    int ret = cache[semester][taken];
    if(ret != -1) return ret;
    ret = INF;

    // 이번 학기(semester)에 들을 수 있는 과목 중 아직 듣지 않은 과목들을 찾는다.
    int canTake = (classes[semester] & ~taken);
    // 선수 과목을 다 듣지 않은 과목들을 걸러낸다.
    for(int i=0;i<n;i++)
        if((canTake & (1 << i)) && (taken & prerequisite[i]) != prerequisite[i])
            canTake &= ~(1 << i);

    for(int take=canTake;take>0;take=((take-1) & canTake)){
        if(bitCount(take) > l) continue;
        ret = min(ret, graduate(semester+1, taken | take) +1);
    }

    ret = min(ret, graduate(semester+1, taken));
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        memset(prerequisite, 0, sizeof(prerequisite));
        memset(classes, 0, sizeof(classes));
        memset(cache, -1, sizeof(cache));
        cin >> n >> k >> m >> l;

        for(int i=0;i<n;i++){
            // i번째 과목의 선수과목 개수
            int preN;
            cin >> preN;
            for(int j=0;j<preN;j++){
                int subN;
                cin >> subN;
                // i번째 과목의 선수과목 번호에 대한 비트를 켠다.
                prerequisite[i] |= (1 << subN);
            }
        }

        for(int i=0;i<m;i++){
            // i번째 학기의 과목 개수
            int classN;
            cin >> classN;
            for(int j=0;j<classN;j++){
                int subN;
                cin >> subN;
                // i번째 학기의 과목 번호에 대한 비트를 켠다.
                classes[i] |= (1 << subN);
            }
        }

        int result = graduate(0,0);
        if(result == INF)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << result << endl;
    }

    return 0;
}