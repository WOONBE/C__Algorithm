#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int> words; //각 배열 안에 단어들이 어떤 단어가 나오는지 매핑한 비트마스킹을 위한 숫자가 있음
int maxWordCnt = 0;
int learnWord = 0; //현재 매핑된 알파벳들을 마스킹한 숫자

int N,K;

//지금 learned 상태에서 단어 몇개 읽을 수 있는지 확인
int countWord(){
    int cnt =0;
    for(auto word : words){
        if((word & learnWord) == word){
            cnt++;
        }

    }
    return cnt;
}
//현재 idx랑 배우는게 가능한 알파벳 갯수
void dfs(int idx, int toLearn){
    if(toLearn == 0){
        maxWordCnt = max(maxWordCnt,countWord());
    }

    for(int i=idx; i<26; i++){
        if(learnWord & (1<<i)) continue; //이미 체크됐으면 넘김
        learnWord |= (1<<i);
        dfs(i+1, toLearn-1);
        learnWord &= ~(1<<i);
    }
}


int main(){
    First

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

    //고정되는 단어 5개는 미리 매핑
    learnWord |= (1<<('a' - 'a'));
    learnWord |= (1<<('n' - 'a'));
    learnWord |= (1<<('t' - 'a'));
    learnWord |= (1<<('i' - 'a'));
    learnWord |= (1<<('c' - 'a'));


    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        int state = 0;
        for(char c : str){
            if(state & (1<<(c-'a'))) continue;
            state |= (1<<(c-'a'));
        }
        words[i] = state;
    }

    dfs(0,K-5);

    cout << maxWordCnt << "\n";

}
