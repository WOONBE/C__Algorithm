#include<iostream>
#include<math.h>

using namespace std;

int N, answer = 987654321;

int population[11] = { 0, };
int map[11][11] = { 0, };
int vis[11] = { 0, };
int connect_city[11];

void Connect(int idx, int check) {//도시 연결

    for (int j = 1; j <= N; j++)
        if (map[idx][j] == 1 && vis[j] == check && connect_city[j] == 2) {
            connect_city[j] = check;
            Connect(j, check);
        }


}

bool ConnectCheck() {//도시 연결 여부 확인

    for (int i = 1; i <= N; i++)
        connect_city[i] = 2;

    for (int i = 1; i <= N; i++)
        if (vis[i] == 1) {
            connect_city[i] = 1;
            Connect(i, 1);
            break;
        }

    for (int i = 1; i <= N; i++)
        if (vis[i] == 0) {
            connect_city[i] = 0;
            Connect(i, 0);
            break;
        }

    for (int i = 1; i <= N; i++)
        if (connect_city[i] != vis[i])
            return false;

    return true;

}

void Divide(int num, int total, int a_total) {

    if (num == total) {
        if (ConnectCheck()) {//인구 수 비교
            int b_total = 0;

            for (int i = 1; i <= N; i++)
                if (vis[i] == 0)
                    b_total += population[i];

            if (answer > abs(a_total - b_total))
                answer = abs(a_total - b_total);

        }
        return;
    }

    for (int i = 1; i <= N; i++) {

        if (vis[i] == 0) {

            vis[i] = 1;
            Divide(num + 1, total, a_total + population[i]);
            vis[i] = 0;

        }

    }

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> population[i];

    for (int i = 1; i <= N; i++) {
        int number; cin >> number;

        for (int j = 0; j < number; j++) {
            int temp; cin >> temp;

            map[i][temp] = 1;
        }
    }

    for (int i = 1; i <= N / 2; i++) //도시 나누기
        Divide(0, i, 0);

    if (answer == 987654321)
        cout << -1 << endl;
    else
        cout << answer << endl;

    return 0;

}