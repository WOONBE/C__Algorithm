#include <bits/stdc++.h>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

int N,M,K,x,y,a,b;

int person[30001];
int candies[30001];
int parent[30001];


int Find(int x){
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x != y){
        parent[y] = x;
    }
}


int main(){
    First

    cin >> N >> M >> K;
    vector<int> dp(K,0);

    for(int i=0; i<N; i++){
        cin >> candies[i];
        parent[i] = i;
        person[i] = 1;
    }

    for(int i=0; i<M; i++){
        cin >> a >> b;
        a--,b--;
        Union(a,b);
    }

    for(int i=0; i<N; i++){
        if(parent[i] != i){
            int p = Find(i);
            person[p] += person[i];
            candies[p] += candies[i];
        }
    }

    for(int i=0; i<N; i++){
        if(parent[i] != i) continue;
        for(int j=K-1; j>=person[i]; j--){
            dp[j] = max(dp[j], dp[j-person[i]] + candies[i]);
        }
    }

    cout << dp[K-1] << "\n";
}
