#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int arr[8];
vector<int> v;
bool visited[8];
int result;
int cnt = 0;
void solve(){
    if (v.size() == n) {
        int tmp = 0;
        for (int i = 0; i < n-1; i++) {
            tmp += abs(v[i + 1] - v[i]);
        }
        result = max(result, tmp);
        return;
    }
    for (int i = 0; i < n; i++) { //백트래킹
        if (!visited[i]) {
            visited[i] = 1;
            v.push_back(arr[i]);
            solve();
            v.pop_back();
            visited[i] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    solve();
    cout << result << "\n";


}