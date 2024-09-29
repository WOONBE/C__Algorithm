//
// Created by 김헌우 on 2024/09/28.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int> parent;
vector<int> Rank;
int n,m;
int cal, a,b;
int Find(int x){
    if(parent[x] == x) return x; //아까부터 이부분 계속 틀림
    return parent[x] = Find(parent[x]);

}

void Union(int x, int y){
    int a = Find(x);
    int b = Find(y);

    if(x == y) return;

    if(Rank[a] > Rank[b]){
        parent[b] = a;
    }
    else if(Rank[a] < Rank[b]){
        parent[a] = b;
    }
    else{
        if(Rank[a] == Rank[b]){
            parent[b] = a;
            Rank[a] ++;
        }

    }
}

bool Same_Parent(int x, int y){
    return Find(x) == Find(y);
}


void solve(){
    cin >> n >> m;
    parent.resize(n+1,0);
    Rank.resize(n+1,0);

    for(int i=1; i<=n;i++){
        parent[i] = i;
    }


    for(int i=0; i< m; i++){
        cin >> cal >> a >> b;

        //union
        if(cal == 0){
            Union(a,b);
        }
        //sameparent
        if(cal == 1){
            if(Same_Parent(a,b)){
                cout << "YES" << "\n";
            }
            else{
                cout << "NO" << "\n";
            }
        }

    }

}

int main(){
    First
    solve();







}