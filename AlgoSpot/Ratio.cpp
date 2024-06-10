#include <iostream>

using namespace std;

int T;
int n,m;

long long mx_game = 2000000000;

int win_ratio(long long tot_game, long long win_game){
    return (win_game/tot_game) * 100;
}

int needGame(long long games, long long wonGames){
    if(win_ratio(games,wonGames) == win_ratio(games+mx_game, wonGames+mx_game)){
        return -1;
    }
    long long mn = 0;
    long long mx = mx_game;

    while (mn + 1< mx){
        long long mid = (mn+mx) / 2;
        if(win_ratio(games,wonGames) == win_ratio(games+mid,wonGames+mid)){
            mn = mid;
        } else{
            mx = mid;
        }
    }
    return mx;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> n >> m;
        cout << needGame(n,m) << "\n";
    }

}
