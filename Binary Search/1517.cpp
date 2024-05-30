#include <iostream>

using namespace std;

int a[250001];
int b[250001];
int c[500001];
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    int k = (n+1)/2;
    for(int i = 0; i < k; i++) cin >> a[i];
    for(int i = 0; i < k; i++) cin >> b[i];
    int aidx = 0, bidx = 0;
    for(int i=0; i<3; i++){
        cout << a[i] << ' ';
    }

    for(int i=0; i<3; i++){
        cout << b[i] << ' ';
    }
    for(int i = 0; i < n; i++){
        if(bidx == n/2) c[i] = a[aidx++]; //b 끝났으면 a값만 in
        else if(aidx == n/2) c[i] = b[bidx++];//위와 반대
        else if(a[aidx] <= b[bidx]) c[i] = a[aidx++]; //더 작은값을 in
        else c[i] = b[bidx++];// 위와 반대
    }
    for(int i = 0; i < n; i++) cout << c[i] << ' ';
}
