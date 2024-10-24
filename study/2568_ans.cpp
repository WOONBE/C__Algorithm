#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> line;
int N;
vector<int> idx, ans, LIS;//idx는 lis length

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int s, e;
        cin >> s >> e;

        line.push_back({s, e});
    }

    sort(line.begin(), line.end());

    LIS.push_back(line[0].second);
    idx.push_back(0);

    for (int i = 1; i < N; ++i)
    {
        int Cur = line[i].second;

        if (LIS.back() < Cur)
        {
            idx.push_back(LIS.size());
            LIS.push_back(Cur);
        }

        else
        {
            int left = 0;
            int right = LIS.size() - 1;

            while (left < right)
            {
                int mid = (left + right) / 2;

                if (LIS[mid] < Cur)
                    left = mid + 1;

                else
                    right = mid;
            }

            LIS[left] = Cur;
            idx.push_back(left);
        }
    }

    cout << N - LIS.size() << '\n';

    int Cur = LIS.size() - 1;

    for (int i = idx.size()-1; i >= 0; --i)
    {
        if (Cur == idx[i]) //역추적할때 값을 줄여가면서 추적
            Cur--;
        else
            ans.push_back(line[i].first);
    }

    sort(ans.begin(), ans.end());
    for (size_t i = 0; i < ans.size(); ++i)
        cout << ans[i] << '\n';

    return 0;
}