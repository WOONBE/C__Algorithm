#include <iostream>
#include <algorithm>


using namespace std;
int length[1001];
int length1[1001];
int sum_length[1001];

int arr[1001];
int n;
int sum = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int k = 0; k < n; k++) {
        length[k] = 1;
        for (int i = 0; i < k; i++) {
            if (arr[i] < arr[k]) {
                length[k] = max(length[k], length[i] + 1);
            }
        }
    }
    for (int k = n-1; k >= 0; k--) {
        length1[k] = 1;
        for (int i = n-1; i >k; i--) {
            if (arr[i] < arr[k]) {
                length1[k] = max(length1[k], length1[i] + 1);
            }
        }
    }
    for(int i=0; i<n; i++){
        sum_length[i] = length[i] + length1[i];
        sum = max(sum,sum_length[i]);

    }

    cout << sum -1 << "\n";
}
