#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int num[10];
int arr[10];


void func(int index, int cnt) {
    if (cnt == m) {  // m개의 수를 모두 선택했으면 출력
        for (int i = 0; i < m; i++) {
            cout << num[arr[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = index; i < n; i++) {
        arr[cnt] = i;
        func(i + 1, cnt + 1); //오름차순으로 수를 구하기에 뒤로 갈 필요가 없다
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);

    func(0, 0);
}
