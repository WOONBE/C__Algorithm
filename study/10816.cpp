#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
int N,M,num;
int arr[500001];
int main(){
    First
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr,arr+N);
    cin >> M;
    while(M--){
        cin >> num;
        cout << upper_bound(arr,arr+N,num) - lower_bound(arr,arr+N,num) << ' ';
    }
}