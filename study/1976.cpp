#include <bits/stdc++.h>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

int arr[201][201];
int parent[201];
int N,M,num;
vector<int> cities;
int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        parent[b] = a;
    }
}

bool isSameParent(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        return false;
    }else{
        return true;
    }
}
int main(){
    First
    cin >> N;
    cin >> M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<=N; i++){
        parent[i] = i;
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(arr[i][j]){
                Union(i,j);
            }
        }
    }
    for(int i=0; i<M; i++){
        cin >> num;
        cities.push_back(num);
    }
    bool flag = true;

    int root = find(cities[0]);
    for(int i=1; i<M; i++){
        if(root != find(cities[i])){
            flag = false;
            break;
        }
    }

    if(flag){
        cout <<"YES" << "\n";
    }else cout << "NO" << "\n";
}