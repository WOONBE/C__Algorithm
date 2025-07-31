#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

vector<int> parent;
int n,m,a,b;

int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b) {
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
    cin >> n >> m;
    parent.assign(n,0);

    for(int i=0; i<n; i++){
        parent[i] = i;
    }

    int flag = 0;
    for(int i=1; i<=m; i++){
        cin >> a >> b;
        if(!isSameParent(find(a),find(b))){
            Union(find(a),find(b));
        }else{
            if(!flag){
                flag = i;
            }
        }
    }
    cout << flag << "\n";
}