#include <iostream>
using namespace std;
int a[1000005], b[1000005], arr[1000005];

int anum, bnum;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int aidx = 0;
    int bidx = 0;

    cin >> anum >> bnum;

    for(int i=0; i<anum; i++){
        cin >> a[i];
    }
    for(int i=0; i<bnum; i++){
        cin >> b[i];
    }
    //값 in하고 idx 1씩 증가
    for(int i=0; i<anum+bnum; i++){
        if(aidx == anum)
            arr[i] = b[bidx++]; //이미 a값 다 in시
        else if(bidx == bnum)
            arr[i] = a[aidx++]; //이미 b값 다 in시
        else if(a[aidx] <= b[bidx])
            arr[i] = a[aidx++];
        else
            arr[i] = b[bidx++];
    }
    for(int i=0; i<anum+bnum; i++){
        cout << arr[i] << ' ';
    }
}
