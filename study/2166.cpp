#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<pair<int,int>> v;
int N,x,y;

double solve(int x, int y){
    double a = v[0].first;
    double b= v[0].second;
    double c = v[x].first;
    double d = v[x].second;
    double e = v[y].first;
    double f = v[y].second;

    return (a*d +  c * f + e * b - c * b - e * d - a * f)/2;
}
int main(){
    First

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> x >> y;
        v.push_back({x,y});
    }

    double result = 0;

    for(int i=1; i<N-1; i++){
        result += solve(i,i+1);
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(result) << "\n";

}