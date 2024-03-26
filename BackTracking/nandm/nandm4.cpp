

#include <iostream>

using namespace std;
int arr[10];
bool visited[8];
int n, m;

void input() {
    cin >> n >> m;

}
void func(int k,int idx) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return; 
    }
    if (k != 0) idx = arr[k - 1]; // k != 0일 경우 st = arr[k-1] 오름차순 정렬
    for (int i = idx; i <= n; i++) {
        
            arr[k] = i;
            func(k + 1,idx+1);
            
        }
    }


int main()
{
    input();
    func(0,1);

    
}

