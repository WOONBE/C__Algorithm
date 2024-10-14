#include <bits/stdc++.h>
using namespace std;

int N, M, G, R;
int a[51][51];
int b[51][51];
int time1[51][51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans = 0;

vector<pair<int, int>> ground;
vector<int> state;
queue<pair<int, int>> q;
queue<pair<int, int>> q2;
void bfs() {
   int now = 1;
   int tans = 0;
   while (true) {
      while (!q.empty()) {
         int x = q.front().first;
         int y = q.front().second;
         q.pop();
         if (a[x][y] == 5)continue;
         for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
            if (a[nx][ny] == 0)continue;
            if (a[nx][ny] <= 2) {
               a[nx][ny] = a[x][y];
               time1[nx][ny] = now;
               q2.push({ nx,ny });
               continue;
            }
            if (a[nx][ny] == 5)continue;
            if (time1[nx][ny] != now)continue;
            if (a[nx][ny] != a[x][y]) {
               tans++;
               a[nx][ny] = 5;
            }
         }
      }
      now++;
      if (q2.empty())break;
      while (!q2.empty()) {
         q.push(q2.front());
         q2.pop();
      }
   }
   ans = max(ans, tans);
}

void distribute(int idx, int gsum, int rsum) {
   if (idx >= ground.size()) {
      if (gsum == G && rsum == R) {
         for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
               a[i][j] = b[i][j];
               time1[i][j] = 0;
            }
         }
         for (int i = 0; i < ground.size(); i++) {
            int x = ground[i].first, y = ground[i].second;
            if (state[i] >= 1) {
               a[x][y] = state[i] + 2;
               q.push({ x,y });
            }
         }
         bfs();
      }
      return;
   }

   for (int i = 0; i < 3; i++) {
      state.push_back(i);
      if (i == 1) {
         distribute(idx + 1, gsum + 1, rsum);
      } else if (i == 2) {
         distribute(idx + 1, gsum, rsum + 1);
      } else {
         distribute(idx + 1, gsum, rsum);
      }
      state.pop_back();  // 추가된 상태를 제거
   }

   // state.push_back(0);
   // distribute(idx + 1, gsum, rsum);
   // state.pop_back();
   //
   // state.push_back(1);
   // distribute(idx + 1, gsum + 1, rsum);
   // state.pop_back();
   //
   //
   // state.push_back(2);
   // distribute(idx + 1, gsum, rsum + 1);
   // state.pop_back();
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

   cin >> N >> M >> G >> R;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         cin >> a[i][j];
         b[i][j] = a[i][j];
         if (a[i][j] == 2)ground.push_back({ i,j });
      }
   }

   distribute(0, 0, 0);

   cout << ans << '\n';

}