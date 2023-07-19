//
// Created by 김헌우 on 2023/07/19.
//1922 Union find, Kruscal

#include "bits/stdc++.h"
#define MAX 100000 + 1
using namespace std;

int N, M, Answer;
int Parent[MAX];
vector<pair<int, pair<int, int>>> Edge;


int Find(int x){
    if (Parent[x] == x) return x;
    else return Parent[x] = Find(Parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);

    if (x != y) Parent[y] = x;
}

bool SameParent(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x == y) return true;
    else return false;
}

void Solution(){
    sort(Edge.begin(), Edge.end());
    for (int i = 1; i <= N; i++)
    {
        Parent[i] = i;        // 초기값 설정
    }

    for (int i = 0; i < M; i++)
    {
        if (SameParent(Edge[i].second.first, Edge[i].second.second) == false) //부모가 다르다면
        {
            Union(Edge[i].second.first, Edge[i].second.second);//union 해준다
            Answer = Answer + Edge[i].first;
        }
    }

    cout << Answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {int a, b, c;
        cin >> a >> b >> c;
        Edge.push_back(make_pair(c, make_pair(a, b)));
    }
    Solution();

}

