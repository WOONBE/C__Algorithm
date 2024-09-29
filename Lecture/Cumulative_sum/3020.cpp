//
// Created by 김헌우 on 2024/09/26.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define First ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
long long N,H;
vector<long long> height;

//vector<long long > arr; //1차원으로 변환
vector<long long> line; //1 ,-1 표시한거 합한거 넣어놓음
vector<long long> prefix; //line 배열의 누적합 계산

void input(){
    cin >> N >> H;
    height.resize(N,0);
//    arr.resize(N+1, vector<long long>(H+1,0));
    line.resize(H+1);
    prefix.resize(H+1);
    for(long long i=0; i<N; i++){
        cin >> height[i];
    }
}

int main(){
    First
    input();

    //1,-1 매핑
    for(long long i=0; i<N; i++){
        //밑에서 부터
        if(i%2 == 0){
            line[0] += 1; //시작점 1
            line[height[i]] -= 1;
        }
        //위에서 부터
        else if(i%2 == 1){
            //끝에 -1은 필요없음
            line[H- height[i]] += 1;
        }
    }
//    for(long long i=0; i<N;i++){
//        for(long long j=0; j<H; j++){
//            cout << arr[i][j] << ' ';
//        }cout << "\n";
//    }

//    for(long long i=0; i<H; i++){
//        line[i] = 0;
//        for(long long j=0; j<N; j++){
//            line[i] += arr[j][i];
//        }
//    }

//    for(long long i=0; i<=H; i++){
//        cout << line[i] << ' ';
//    }

    prefix[0] = line[0];
    for(long long i=1; i<H; i++){
        prefix[i] = prefix[i-1] + line[i];
    }

//    for(long long i=0; i<H; i++){
//        cout << prefix[i] << ' ';
//    }

    long long min_value = *min_element(prefix.begin(),prefix.begin()+H);
    long long min_cnt = count(prefix.begin(),prefix.begin()+H,min_value); //end아님(+1해줘서)

//    for(long long i=0; i<H; i++){
//        if(prefix[i] == min_value){
//            min_cnt++;
//        }
//    }

    cout << min_value << ' ' << min_cnt <<"\n";


}
