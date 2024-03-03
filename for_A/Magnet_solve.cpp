

#include <iostream>
using namespace std;
int T, K;
int wheels[4][8]; // [x][y] : x번째 바퀴의 y톱니
int dir[4]; //각 번호의 방향


void initDir()
{
    for (int i = 0; i < 4; i++)
    {
        dir[i] = 0; }
}
void input()
{
    cin >> K;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> wheels[i][j];
        }
    } }
//
void setDir(int idx)
{

    //왼쪽 톱니
    int tmp = idx;

    while (true)
    {
        tmp--;
        if (tmp < 0)
            break;
        if (wheels[tmp][2] != wheels[tmp + 1][6])
            dir[tmp] = -dir[tmp + 1];
        else
            break; }

    // 오른쪽 톱니
    tmp = idx;
    //
    while (true)
    {
        tmp++;
        if (tmp > 3)
            break;
        if (wheels[tmp][6] != wheels[tmp - 1][2])
            dir[tmp] = -dir[tmp - 1];
        else
            break; }
}

//
void spin(int idx, int d)
{
    int tmp;
    //
    if (d == 1)
    {
        tmp = wheels[idx][7];
        for (int i = 7; i >= 1; i--)
        {
            wheels[idx][i] = wheels[idx][i - 1];
        }
        wheels[idx][0] = tmp;
    }
        //
    else if (d == -1)
    {
        tmp = wheels[idx][0];
        for (int i = 0; i < 7; i++)
        {
            wheels[idx][i] = wheels[idx][i + 1];
        }
        wheels[idx][7] = tmp;
    }
}
int solve() {
    int ans = 0;
    int idx = 0;
    int d = 0;
    for (int i = 0; i < K; i++)
    {
        cin >> idx >> d;
//dir
        initDir();
        idx -= 1; //0번부터 시작하게
        dir[idx] = d;
        setDir(idx);
        for (int j = 0; j < 4; j++)
        {
            spin(j, dir[j]);
        }
    }
    if (wheels[0][0] == 1)
        ans += 1;
    if (wheels[1][0] == 1)
        ans += 2;
    if (wheels[2][0] == 1)
        ans += 4;
    if (wheels[3][0] == 1)
        ans += 8;
    return ans; }


int main() {
    // freopen("sample_input.txt", "r", stdin);
    cin >> T;
    int ans = 0;
    for (int tc = 1; tc <= T; tc++)
    {
        initDir();
        input();
        ans = solve();
        cout << "#" << tc << ' ' << ans << '\n';
    }
    return 0;
}