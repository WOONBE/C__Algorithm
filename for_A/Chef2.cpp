#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
int arr[20][20];


int main()
{
    int tc;
    int t;
    cin >> t;
    for (tc = 1; tc <= t; tc++)
    {
        int n;
        cin >> n;
        vector<int>a(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < n / 2; i++) {
            a[i] = 1;
        }

        sort(a.begin(), a.end());

        int min = 987654321;

        do {
            int one = 0;
            int two = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i] == 0 && a[j] == 0) one += arr[i][j];
                    else if (a[i] == 1 && a[j] == 1) two += arr[i][j];
                }
            }

            int ans = abs(one-two);
            
            if (ans < min) 
                min = ans;
        } while (next_permutation(a.begin(), a.end()));

        cout << "#" << tc << " " << min << '\n';


    }
    return 0;
}
