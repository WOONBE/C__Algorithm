#include <bits/stdc++.h>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

bool isPrime[4000001];
int N;
vector<int> v;
int main(){
    First

    cin >> N;
    memset(isPrime, true,sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2; i*i<=N; i++){
        if(isPrime[i]){
            for(int j=i*i; j<=N; j+=i){
                isPrime[j] = false;
            }
        }
    }

    for(int i=2; i<=N; i++){
        if(isPrime[i]){
            v.push_back(i);
        }
    }

    int left = 0;
    int right = 0;
    int cnt = 0;
    int sum = 0;
    while(right < v.size()){
        sum += v[right];

        while(sum >= N){
            if(sum == N) cnt++;

            sum -= v[left];
            left++;
        }
        right++;
    }
    cout << cnt << "\n";
}