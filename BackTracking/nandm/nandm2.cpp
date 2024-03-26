

#include <iostream>

using namespace std;
int arr[8];
bool visited[8];
int n, m;

void input() {
    cin >> n >> m;

}
void func(int k, int idx) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << "\n";
    }
    for (int i = idx; i <= n; i++) {
        if (!visited[i]) {
            arr[k] = i;
            visited[i] = 1;
            func(k + 1,i+1);
            visited[i] = 0;
        }
    }
}

int main()
{
    input();
    func(0,1);

    
}

