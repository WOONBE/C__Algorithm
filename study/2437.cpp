#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N;
vector<long long > v;
long long num_sum=0;
int main(){
    First

    cin >> N;

    for(int i=0; i<N; i++){
        long long num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(),v.end());

    for(int i=0; i<v.size(); i++){
        if(v[i] > num_sum +1){
            break;
        }
        num_sum += v[i];
    }

    cout << num_sum + 1;
    return 0;





}