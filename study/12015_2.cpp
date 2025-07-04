#include <bits/stdc++.h>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
vector<int> v;
int N,num;
int main(){
    First
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> num;

        if(v.size() == 0){
            v.push_back(num);
        }else{
            if(v.back() < num){
                v.push_back(num);
            }else{
                int left = 0;
                int right = v.size();

                while(left <= right){
                    int mid = (left+right)/2;

                    if(v[mid] >= num){
                        right = mid-1;
                    }else{
                        left = mid + 1;
                    }
                }
                v[left] = num;
            }
        }
    }
    cout << v.size() << "\n";
}