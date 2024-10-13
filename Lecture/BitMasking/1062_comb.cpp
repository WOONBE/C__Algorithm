#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N,K;
bool visited[26] = {0,};
int maxWord = 0;
vector<string> words;

int cntWord(){
    int cnt = 0;

    for(auto str : words){
        bool readable = true; //초기화 위치 확실히
        for(char c : str){
            if(!visited[c-'a']){
                readable = false;
                break;
            }
        }
        if(readable) cnt++;
    }
    return cnt;
}

void dfs(int idx, int toLearn){
    if(toLearn == 0){
        maxWord = max(maxWord, cntWord());
        return;
    }

    for(int i=idx; i<26; i++){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i+1, toLearn-1);
        visited[i] = false;
    }

}

int main(){

    cin >> N >> K;
    words.resize(N);

    if(K < 5){
        cout << 0 << "\n";
        return 0;
    }
    if(K == 26){
        cout << N << "\n";
        return 0;
    }

    for(int i=0; i<N; i++){
        cin >> words[i];
    }
    visited['a' - 'a'] = true;
    visited['n' - 'a'] = true;
    visited['t' - 'a'] = true;
    visited['i' - 'a'] = true;
    visited['c' - 'a'] = true;

    dfs(0,K-5);

    cout << maxWord << "\n";

}
