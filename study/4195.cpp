#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
int T,F;
string s1, s2;
vector<int> parent;
vector<int> sze; //해당 노드를 부모로 가지는 노드들의 사이즈
unordered_map<string,int> mp; //이름, 노드번호
int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        parent[b] = a;
        sze[a] += sze[b];
    }
}

int main(){
    First
    cin >> T;
    while(T--){
        cin >> F;
        parent.assign(2 * F + 1,0);
        sze.assign(2 * F + 1,1);
        mp.clear();
        int node_num = 1;

        for(int i=0; i<F; i++){
            cin >> s1 >> s2;

            if(mp.find(s1) == mp.end()){
                mp[s1] = node_num;
                parent[mp[s1]] = mp[s1];
                node_num++;
            }
            if(mp.find(s2) == mp.end()){
                mp[s2] = node_num;
                parent[mp[s2]] = mp[s2];
                node_num++;
            }
            Union(mp[s1], mp[s2]);
            cout << sze[find(mp[s1])] << "\n";
        }
    }
    return 0;
}