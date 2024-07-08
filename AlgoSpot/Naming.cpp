#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> ret;

vector<int> getPartialMatch(string N){
    int m = N.size();
    vector<int> pi(m,0);
    int begin = 1, matched = 0;
    while(begin + matched < m){
        if(N[begin + matched] == N[matched]){
            matched++;
            pi[begin+matched -1] = matched;
        } else{
            if(matched == 0) begin++;
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched -1];
            }
        }
    }
    return pi;
}

vector<int> getPrefixSuffix(string s){
    vector<int> ret, pi= getPartialMatch(s);
    int k = s.size();
    while(k >0){
        ret.push_back(k);
        k = pi[k-1]; //접두사 길이를 하나씩 줄이면서 판별
    }
    return ret;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, s1, s2;
    cin >> s1 >> s2;
    s = s1 + s2;

    vector<int> ret= getPrefixSuffix(s);
    for(int i=ret.size()-1;i>=0;i--)
        cout << ret[i] << " ";
    cout << endl;

    return 0;





}
