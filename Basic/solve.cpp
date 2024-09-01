//
// Created by SSAFY on 2024-08-22.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v = {1,5,5,6,6,0,-1,9,8,11};

bool compare(int a, int b) {
    return a > b;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    sort(v.begin(),v.end(), compare);

    v.erase(unique(v.begin(),v.end()), v.end());


    for(auto i : v) {
        cout << i << ' ';
    }


}