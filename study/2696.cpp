#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
int T,M,N,num;
int main(){
    First

    cin >> T;

    while(T--){
       priority_queue<int> mx_q; //최대힙
       priority_queue<int,vector<int>,greater<>> min_q; //최소힙
       cin >> M;
        cout << (M + 1) / 2 << "\n";
       int cnt = 0;//10개마다 줄 바꿈 필요해서

       for(int i=1; i<=M; i++){
           cin >> num;

           if(mx_q.size() == min_q.size()){
               mx_q.push(num);
           }else{
               min_q.push(num);
           }

           if(!min_q.empty() && mx_q.top()>min_q.top()){
               int mx_val = mx_q.top(); mx_q.pop();
               int min_val = min_q.top(); min_q.pop();
               mx_q.push(min_val);
               min_q.push(mx_val);
           }
           if(i % 2){
               cout << mx_q.top() << ' ';
               cnt++;
//               if(cnt % 10 == 0){
//                   cout << "\n";
//               }
           }
       }
        cout << "\n";
    }

}