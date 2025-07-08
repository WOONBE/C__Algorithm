#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
vector<ll> v;
ll n;
//왼쪽, 중간 걸친부분(늘려가면서 계산), 오른쪽 중에 제일 큰걸로 값 갱신
ll find_max_width(ll left, ll right){
    if(left == right){
        return v[left]; //수정
    }

    ll mid = (left+right)/2;

    ll left_width = find_max_width(left, mid);
    ll right_width = find_max_width(mid+1,right);

    ll mid_height = v[mid];
    ll mid_left = mid;
    ll mid_right = mid;
    ll mid_width = mid_height;
    while(mid_left > left ||mid_right < right){ //수정
        if(mid_right < right && ((mid_left == left) || v[mid_left-1] < v[mid_right+1])){
            mid_right++;
            mid_height = min(mid_height,v[mid_right]);
        }else{
            mid_left--;
            mid_height = min(mid_height,v[mid_left]);
        }
        mid_width = max(mid_width,(mid_right-mid_left+1) * mid_height);
    }
    return max(max(left_width,right_width),mid_width);
}

int main(){
    First
    while(true){
        cin >> n;
        if(n == 0){
            break;
        }
        v.assign(n,0);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        cout << find_max_width(0,n-1) << "\n";
    }
}