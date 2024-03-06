#include <iostream>
#include <algorithm>


using namespace std;
int ans,n,m,k,r,c;
int notebook[40][40];
int sticker[10][10];

void rotate() {
    int tmp[12][12];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            tmp[i][j] = sticker[i][j];

    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
            sticker[i][j] = tmp[r - 1 - j][i];

    swap(r, c);
}


bool pastable(int x, int y) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (notebook[x + i][y + j] == 1 && sticker[i][j] == 1)
                return false;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[i][j] == 1)
                notebook[x + i][y + j] = 1;
        }
    }
    return true;
}

void init() {
	ans = 0;

}

void solve() {
	cin >> n >> m >> k;
	
	while(k--) {
        cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticker[i][j];
			}
		}
        for (int rot=0; rot < 4; rot++) {//4방향 돌림
            bool isPastable = false;
            for (int row = 0; row <= n - r; row++) { //시작점 설정
                if (isPastable) break; //이미 붙였으면 통과
                for (int col = 0; col <= m - c; col++) {
                    if (pastable(row, col)) {
                        isPastable = true;
                        break; //여기 브레이크 안해줬음
                    }
                }
               
            }if (isPastable) break;
            rotate();

        }

    }
   
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    init();
    solve();
  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { //이부분 오타로 헤맴
            ans += notebook[i][j];
        }
    }

    cout << ans << "\n";
	

}
