#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

const int MAX_SIZE = 200;
int W, H;
int board[MAX_SIZE][MAX_SIZE];
int scores[2]; // scores[0]: Player 1, scores[1]: Player 2
bool visited[MAX_SIZE][MAX_SIZE];
int blocks[2];
bool isRemovable = false;
void init(int w, int h) {
    W = w;
    H = h;
    memset(board, 0, sizeof(board));
    scores[0] = scores[1] = 0;
}

// Helper to check boundaries
bool isValid(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

// Directions for adjacent cells
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int removeConnectedBlocks(int player) {
    int totalScore;
    int directions[4][2] = {
            {0, 1},   // 오른쪽
            {1, 0},   // 아래
            {1, 1},   // 우하향
            {1, -1}
    };
    set<pair<int, int>> toRemove; // 삭제할 좌표들을 중복 없이 저장

    // 연결된 블록 찾기
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (board[i][j] >= 1) {
                for (int dir = 0; dir < 4; dir++) {
                    vector<pair<int, int>> connected;
                    int x = i, y = j;

                    // 연결된 블록 탐색
                    while (isValid(x, y) && board[x][y] == board[i][j]) {
                        connected.push_back({x, y});
                        x += directions[dir][0];
                        y += directions[dir][1];
                    }

                    // 5개 이상의 블록이 연결된 경우, 삭제할 블록들로 추가
                    if (connected.size() >= 5) {
                        // 현재 탐색한 방향의 블록들만 저장
                        for (auto coord : connected) {
                            toRemove.insert(coord);
                        }
                    }
                }
            }
        }
    }

    // 삭제된 블록 수만큼 점수 추가
    totalScore = 0;

    if(toRemove.size() > 0){
        isRemovable = true;
    }else{
        isRemovable = false;
    }

    for (auto coord : toRemove) {
        int x = coord.first, y = coord.second;
        if (board[x][y] == player) {  // 현재 플레이어의 블록일 때만 점수 증가
            scores[player - 1] += 1; // 점수 추가
            totalScore += 1;
        }
        board[x][y] = 0;  // 해당 블록 삭제
    }

    // 블록 떨어뜨리기: 빈 곳을 채운다
    for (int j = 0; j < W; j++) {
        int emptyRow = H - 1;
        for (int i = H - 1; i >= 0; i--) {
            if (board[i][j] != 0) {
                board[emptyRow--][j] = board[i][j];
            }
        }
        while (emptyRow >= 0) {
            board[emptyRow--][j] = 0;
        }
    }

    return totalScore;
}



int dropBlocks(int mPlayer, int mCol) {
    int player = mPlayer;

    for (int colOffset = 0; colOffset < 3; colOffset++) {
        int col = mCol + colOffset;
        for (int i = H - 1; i >= 0; i--) {
            if (board[i][col] == 0) {
                board[i][col] = player;
                break;
            }
        }
    }

    int score = 0;
    while (true) {

        int myScore = removeConnectedBlocks(player);


        // 점수가 더 이상 발생하지 않으면 종료
        if (!isRemovable) break;

        score += myScore; // 플레이어 1의 점수만 계산
    }

    scores[player - 1] += score;
    return score;
}


int changeBlocks(int mPlayer, int mCol) {
    int player = mPlayer;
    int player2 = (player == 1) ? 2 : 1;
    int opponent = (player == 1) ? 2 : 1;

    for (int i = H - 1; i >= 0; i--) {
        if (board[i][mCol] == opponent) {
            queue<pair<int, int>> q;
            q.push({i, mCol});

            while (!q.empty()) {
                auto coord = q.front();
                q.pop();
                int x = coord.first, y = coord.second;
                board[x][y] = player;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (isValid(nx, ny) && board[nx][ny] == opponent) {
                        q.push({nx, ny});
                    }
                }
            }
            break;
        }else{
            return 0;
        }
    }

    int score = 0;
    while (true) {

        int myScore = removeConnectedBlocks(player);


        // 점수가 더 이상 발생하지 않으면 종료
        if (!isRemovable) break;

        score += myScore; // 플레이어 1의 점수만 계산
    }

    scores[player - 1] += score;
    return score;
}

int getResult(int mBlockCnt[2]) {
    mBlockCnt[0] = mBlockCnt[1] = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (board[i][j] == 1) mBlockCnt[0]++;
            else if (board[i][j] == 2) mBlockCnt[1]++;
        }
    }

    if (scores[0] > scores[1]) return 1;
    if (scores[1] > scores[0]) return 2;
    return 0;
}

int main() {

    init(40,120);

//
//    vector<vector<int>> input = {
//            {200, 1, 5, 0}, {200, 2, 21, 0}, {400, 0, 3, 3}, {200, 1, 9, 0},
//            {200, 2, 18, 6}, {200, 1, 11, 5}, {200, 2, 5, 0}, {200, 1, 22, 0},
//            {200, 2, 16, 0}, {200, 1, 2, 6}, {200, 2, 6, 0}, {200, 1, 2, 0},
//            {200, 2, 15, 0}, {200, 1, 0, 5}, {200, 2, 24, 0}, {200, 1, 12, 0},
//            {200, 2, 5, 0}, {200, 1, 13, 0}, {200, 2, 12, 0}, {200, 1, 13, 0},
//            {200, 2, 15, 0}, {200, 1, 1, 0}, {200, 2, 11, 0}, {200, 1, 1, 0},
//            {200, 2, 16, 0}, {200, 1, 23, 0}, {200, 2, 2, 5}, {200, 1, 21, 0},
//            {200, 2, 18, 12}, {200, 1, 9, 0}
//    };

//    vector<vector<int>> input = {
//            {200, 1, 6, 0}, {200, 2, 3, 0}, {200, 1, 10, 0}, {200, 2, 7, 0},
//            {200, 1, 1, 0}, {200, 2, 5, 0}, {200, 1, 4, 0}, {200, 2, 3, 0},
//            {200, 1, 11, 0}, {200, 2, 5, 5}, {200, 1, 10, 0}, {300, 2, 0, 0},
//            {200, 1, 5, 0}, {200, 2, 2, 0}, {200, 1, 1, 0}, {200, 2, 4, 0},
//            {200, 1, 3, 0}, {200, 2, 8, 0}, {200, 1, 10, 0}, {200, 2, 8, 5},
//            {200, 1, 5, 0}, {200, 2, 1, 0}, {200, 1, 9, 5}, {200, 2, 2, 0},
//            {200, 1, 12, 5}, {200, 2, 5, 10}, {200, 1, 6, 10}, {200, 2, 12, 0},
//            {200, 1, 12, 0}, {300, 2, 0, 0}, {200, 1, 10, 0}, {200, 2, 3, 0},
//            {300, 1, 9, 6}, {200, 2, 5, 5}, {200, 1, 9, 0}, {400, 1, 20, 19},
//            {200, 2, 5, 0}, {200, 1, 10, 0}, {200, 2, 9, 0}, {200, 1, 0, 0},
//            {200, 2, 4, 5}, {200, 1, 1, 0}, {200, 2, 11, 5}, {200, 1, 2, 0},
//            {200, 2, 4, 0}, {200, 1, 0, 0}, {200, 2, 6, 0}, {200, 1, 12, 0},
//            {200, 2, 12, 0}, {200, 1, 5, 0}, {200, 2, 7, 0}, {200, 1, 1, 10},
//            {300, 2, 12, 0}, {200, 1, 12, 0}, {200, 2, 4, 5}, {200, 1, 11, 0},
//            {200, 2, 9, 0}, {200, 1, 9, 11}, {200, 2, 1, 5}, {200, 1, 3, 0},
//            {400, 1, 30, 26}, {200, 2, 5, 0}, {200, 1, 5, 0}, {200, 2, 2, 0},
//            {200, 1, 6, 0}, {300, 2, 1, 0}, {200, 1, 1, 0}, {200, 2, 1, 0},
//            {200, 1, 9, 0}, {200, 2, 3, 0}, {300, 1, 10, 0}, {400, 1, 45, 35},
//            {200, 2, 11, 0}, {200, 1, 11, 0}, {200, 2, 11, 0}, {300, 1, 8, 0},
//            {300, 2, 13, 0}, {200, 1, 7, 5}, {200, 2, 8, 0}, {200, 1, 12, 0},
//            {200, 2, 7, 0}, {200, 1, 9, 0}, {400, 1, 49, 50}, {200, 2, 7, 6},
//            {200, 1, 0, 14}, {200, 2, 1, 5}, {200, 1, 0, 0}, {200, 2, 0, 0},
//            {200, 1, 9, 0}, {200, 2, 8, 10}, {200, 1, 11, 0}, {200, 2, 3, 0},
//            {400, 0, 37, 39}
//    };

    vector<vector<int>> input = {
            {300, 1, 11, 0}, {200, 2, 7, 0}, {200, 1, 11, 0}, {300, 2, 7, 0},
            {200, 1, 24, 0}, {200, 2, 30, 0}, {200, 1, 17, 0}, {200, 2, 6, 0},
            {400, 0, 9, 9}, {200, 1, 27, 6}, {200, 2, 23, 0}, {200, 1, 9, 0},
            {200, 2, 4, 6}, {200, 1, 23, 0}, {200, 2, 27, 6}, {200, 1, 23, 0},
            {200, 2, 35, 0}, {200, 1, 14, 6}, {200, 2, 32, 6}, {200, 1, 30, 0},
            {300, 2, 6, 0}, {200, 1, 29, 0}, {200, 2, 25, 5}, {200, 1, 32, 6},
            {400, 2, 10, 4}, {200, 2, 14, 0}, {300, 1, 1, 0}, {200, 2, 7, 0},
            {200, 1, 18, 0}, {200, 2, 35, 0}, {200, 1, 15, 0}, {200, 2, 25, 0},
            {200, 1, 31, 0}, {200, 2, 15, 0}, {200, 1, 10, 0}, {200, 2, 1, 0},
            {200, 1, 24, 0}, {200, 2, 15, 0}, {200, 1, 22, 0}, {200, 2, 10, 0},
            {200, 1, 29, 5}, {200, 2, 21, 0}, {200, 1, 9, 0}, {300, 2, 31, 0},
            {200, 1, 35, 0}, {200, 2, 11, 0}, {200, 1, 0, 0}, {200, 2, 2, 0},
            {200, 1, 29, 0}, {200, 2, 27, 0}, {200, 1, 7, 0}, {200, 2, 28, 0},
            {200, 1, 2, 0}, {300, 2, 19, 9}, {200, 1, 14, 0}, {200, 2, 27, 0},
            {200, 1, 3, 0}, {200, 2, 15, 0}, {300, 1, 4, 6}, {200, 2, 15, 0},
            {300, 1, 13, 0}, {200, 2, 31, 0}, {200, 1, 11, 7}, {200, 2, 13, 6},
            {200, 1, 6, 0}, {300, 2, 2, 0}, {200, 1, 19, 7}, {200, 2, 36, 0},
            {200, 1, 1, 0}, {200, 2, 6, 0}, {200, 1, 15, 0}, {300, 2, 32, 0},
            {200, 1, 13, 0}, {300, 2, 33, 0}, {200, 1, 9, 0}, {200, 2, 28, 0},
            {200, 1, 0, 0}, {300, 2, 15, 0}, {300, 1, 10, 0}, {200, 2, 18, 6},
            {200, 1, 21, 0}, {200, 2, 4, 5}, {300, 1, 0, 0}, {200, 2, 18, 0},
            {200, 1, 32, 0}, {200, 2, 10, 0}, {200, 1, 12, 0}, {400, 2, 52, 59},
            {200, 2, 33, 0}, {200, 1, 25, 0}, {200, 2, 7, 11}, {200, 1, 23, 0},
            {200, 2, 24, 0}, {200, 1, 4, 0},  {200, 2, 24, 0}, {200, 1, 16, 0},
            {200, 2, 15, 0}, {200, 1, 9, 0},  {200, 2, 24, 0}, {200, 1, 14, 0},
            {200, 2, 13, 0}, {200, 1, 33, 0}, {300, 2, 18, 0}, {200, 1, 22, 0},
            {300, 2, 20, 0}, {200, 1, 10, 6}, {400, 2, 59, 70}, {400, 2, 59, 70},
            {200, 2, 7, 0},  {300, 1, 31, 14}, {300, 2, 15, 0}, {300, 1, 21, 0},
            {300, 2, 22, 0}, {200, 1, 2, 0},  {200, 2, 9, 5},  {200, 1, 37, 0},
            {200, 2, 35, 0}, {200, 1, 22, 0}, {200, 2, 20, 0}, {200, 1, 22, 5},
            {200, 2, 8, 5},  {200, 1, 0, 0},  {200, 2, 34, 5}, {200, 1, 7, 0},
            {200, 2, 7, 0},  {200, 1, 21, 0}, {400, 2, 67, 55}

    };





    for (const auto& row : input) {
        int command = row[0];
        int player = row[1];
        int col = row[2];
        int unused = row[3]; // 사용되지 않는 인수

        if (command == 200) {
            // dropBlocks 함수 호출
            cout << "dropBlocks(" << player << ", " << col << ") = " << dropBlocks(player, col) << endl;

            if(player == 2 && col == 7 && unused == 0){
                for(int i=0; i<H; i++){
                    for(int j=0; j<W; j++){
                        cout << board[i][j] << ' ';
                    }cout << "\n";
                }
            }
//
            cout << "\n";
//            if(player == 1 && col == 31 && unused == 14){
//                for(int i=0; i<H; i++){
//                    for(int j=0; j<W; j++){
//                        cout << board[i][j] << ' ';
//                    }cout << "\n";
//                }
//            }
//            cout << "\n";
//            if(player == 1 && col == 6 && unused == 10){
//                for(int i=0; i<H; i++){
//                    for(int j=0; j<W; j++){
//                        cout << board[i][j] << ' ';
//                    }cout << "\n";
//                }
//            }
//            cout << "\n";




        } else if (command == 300) {
            // changeBlocks 함수 호출
            cout << "changeBlocks(" << player << ", " << col << ") = " << changeBlocks(player, col) << endl;

            if(player == 1 && col == 31 && unused == 14){
                for(int i=0; i<H; i++){
                    for(int j=0; j<W; j++){
                        cout << board[i][j] << ' ';
                    }cout << "\n";
                }
            }
        } else if(command == 400){
                cout << "\n";
                cout << getResult(blocks) << "\n";
                cout << blocks[0] << ' ' << blocks[1] << "\n";
        }
    }

}











