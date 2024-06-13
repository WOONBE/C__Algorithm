#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int n;
vector<int> v;
void input(){
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
}
int Solve(){
    stack<int> remain;

    v.push_back(0); //가상의 right 넣음
    int ans = 0;

    for(int i=0; i<v.size(); i++){

        while(!remain.empty() && v[remain.top()] >= v[i]){
            int height = remain.top();
            remain.pop();
            int width = -1;
            if(remain.empty()){
                width = i;
            } else{
                width = (i - remain.top() - 1);
            }
            ans = max(ans, v[height] * width);
        }
        remain.push(i);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> n;
        v.clear();
        input();
        cout << Solve() << "\n";
    }
}
