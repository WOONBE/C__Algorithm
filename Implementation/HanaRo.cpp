#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
#define endl "\n"
#define MAX 1000 + 1

typedef long long ll;


using namespace std;

typedef struct
{
	ll x;
	ll y;
}Pos;

ll N;
ll Answer;
ll Parent[MAX];

double E;
Pos P[MAX];
vector < pair<ll, pair<ll, ll>>>  Edge;



void Initialize() {
	memset(Parent, 0, sizeof(Parent));
	N = 0;
	Answer = 0;
	E = 0.0;
	Edge.clear();
	for (int i = 0; i < MAX; i++) {
		P[i].x = -1;
		P[i].y = -1;
	}
}
ll Calc_Dist(const Pos& a, const Pos& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void Input()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		ll a;
		cin >> a;
		P[i].x = a;
	}
	for (int i = 1; i <= N; i++) {
		ll b;
		cin >> b;
		P[i].y = b;
	}

	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ll Dist = Calc_Dist(i, j);
			Edge.push_back(make_pair(Dist, make_pair(i, j)));
		}
		
	*/cin >> E; //입력 위치 실수
}

void MakeEdges() {
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			ll Dist = Calc_Dist(P[i], P[j]);
			Edge.push_back(make_pair(Dist, make_pair(i, j)));
		}
	}
}

int find(int x) {
	if (Parent[x] == x)
		return x;
	int ret = find(Parent[x]);
	Parent[x] = ret;
	return ret;
}

bool isSameParent(int x, int y) {
	x = find(x);
	y = find(y);

	if (x != y)
		return false;
	else {
		return true;
	}

}

void Union_find(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return;
	}
	Parent[y] = x;
	return;
}

void Solve() {
	sort(Edge.begin(), Edge.end());

	for (int i = 1; i <= N; i++) {
		Parent[i] = i;
	}
	for (int i = 0; i < Edge.size(); i++) {
		int from = Edge[i].second.first;
		int to = Edge[i].second.second;
		if (!isSameParent(from, to)) { // 부모가 같은지 확인하는 함수 수정
			Union_find(from, to);
			Answer += Edge[i].first; // Answer를 계속 누적시키고 마지막에 한 번에 반올림하여 처리
		}
	}
	Answer = round(Answer * E);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(0);
	
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		Initialize();
		Input();
		MakeEdges();
		Solve();
		cout << '#' << tc << " " << Answer << endl;

	}
	return 0 ;
}


