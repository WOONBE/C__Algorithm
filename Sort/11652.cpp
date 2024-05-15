#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long temp;
    vector<long long > v;

    for(int i=0; i<n; i++){
        cin>> temp;
        v.push_back(temp);
    }

    sort(v.begin(),v.end());

    long long max = 0;
    long long cnt = 0;
    long long result = v[0];

    for (int i = 1; i < n; i++)
    {
        if (v[i] ==  v[i - 1])
        {
            cnt++;
            if (cnt > max)
            {
                max = cnt;
                result = v[i];
            }
        }
        else
            cnt = 0;
    }

    cout << result;
}
