#include <bits/stdc++.h>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
int N,M,num;
int arr[100001];
int main(){
    First
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr,arr+N);
    cin >> M;
    while(M--){
        int left = 0;
        int right = N-1;
        int value = 0;
        cin >> num;
        while(left <= right){
            int mid = (left+right)/2;
            if(arr[mid] == num){
                value = 1;
                break;
            }else {
                if (arr[mid] >= num) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }
        }
        cout << value << "\n";
    }

}