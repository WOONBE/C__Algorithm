#include <iostream>
#include <vector>
#include <queue>

#define MAX 32001

using namespace std;

vector<int> compare[MAX];
int inDegree[MAX];


void topologySort(int n){
    int result[MAX];
    queue<int> q;
    for(int i=1; i <= n; i ++){
        if(inDegree[i]==0) q.push(i);
    }
    for(int i=1; i <=n; i++){
        if(q.empty()){
            //cout<<"사이클이 발생"<<endl;
            return;
        }
        int x = q.front();
        q.pop();
        result[i] = x;
        for(int i= 0; i < compare[x].size(); i ++){
            int y = compare[x][i];
            if(--inDegree[y] == 0)
                q.push(y);
        }
    }
    for(int i =1; i<=n; i++) {
        printf("%d ", result[i]);
    }
}


int main() {
    int n; // 학생 수
    int m; // 키를 비교한 횟수
    cin >> n;
    cin >> m;
    for(int i=0; i < m; i++){
        int num1, num2;
        scanf("%d %d",&num1, &num2);
        compare[num1].push_back(num2);
        inDegree[num2]++;
    }
    topologySort(n);

}