#include <iostream>
#include <algorithm>
#include <queue>
#11286

int n, x;

using namespace std;

class cmp {
public:
	bool operator() (int a, int b) {
		if (abs(a) != abs(b)) { //서로 다르면 절댓값이 큰 수부터
			return abs(a) > abs(b);
			
		}
		return a > b;
	}
	

};



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int, vector<int>, cmp > pq;
	cin >> n;

	while (n--) {

		cin >> x;
		if (x == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << "\n"; //여기 pop을 안해줬음
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}

}
