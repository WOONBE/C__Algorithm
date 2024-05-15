#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    vector<long long > v;

    long long temp;
    for(long long i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());

    cout << v[k-1];

}
