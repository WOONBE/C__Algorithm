// 파일명: mysolution.cpp (또는 원하는 이름)

// 1. 필요한 헤더 파일들을 모두 포함합니다.
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

// 여기에 솔루션 구현에 필요한 헤더를 추가하세요.
// 예: #include <vector>, #include <string>, #include <unordered_map>
using namespace std;

// 2. 솔루션 코드와 메인 코드에서 공통으로 사용하는 구조체를 정의합니다.
struct RESULT
{
    int cnt;
    int IDs[5];
};


/////////////////////////////////////////////////////////////////////////
//                                                                     //
// 이 아래 부분에 직접 구현해야 할 솔루션 코드를 작성합니다.                     //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

//struct RESULT
//{
//    int cnt;
//    int IDs[5];
//};

struct Movie {
    int id;
    int genre;
    int total_score;
    int time_stamp;
    bool is_deleted;
};

struct Viewing_History {
    int mID;
    int rating;
};

struct Set_cmp {
    int total_score;
    int time_stamp;
    int mID;
    
    bool operator<(const Set_cmp& other) const {
        if (total_score != other.total_score) {
            return total_score > other.total_score;
        }
        return time_stamp > other.time_stamp;
    }
};

unordered_map<int, Movie> movie_info;

set<Set_cmp> genre_movie[6];

vector<Viewing_History> user_history[1001];

unordered_set<int> is_watched[1001];

int tme;

void init(int N)
{
    movie_info.clear();
    for (int i = 1; i <= 5; ++i) {
        genre_movie[i].clear();
    }
    for (int i = 1; i <= N; ++i) {
        user_history[i].clear();
        is_watched[i].clear();
    }
    tme = 0;
}

int add(int mID, int mGenre, int mTotal)
{
    if (movie_info.count(mID)) {
        return 0;
    }
    
    tme++;
    
    movie_info[mID] = {mID, mGenre, mTotal, tme, false};
    
    genre_movie[mGenre].insert({mTotal, tme, mID});

    return 1;
}

int erase(int mID)
{
    if (movie_info.find(mID) == movie_info.end() || movie_info[mID].is_deleted) {
        return 0;
    }

    Movie& movie = movie_info[mID];
    movie.is_deleted = true;
    
    genre_movie[movie.genre].erase({movie.total_score, movie.time_stamp, mID});

    return 1;
}

int watch(int uID, int mID, int mRating)
{
    if (movie_info.find(mID) == movie_info.end() || movie_info[mID].is_deleted) {
        return 0;
    }
   
    if (is_watched[uID].count(mID)) {
        return 0;
    }

    Movie& movie = movie_info[mID];
    
    genre_movie[movie.genre].erase({movie.total_score, movie.time_stamp, mID});
    movie.total_score += mRating;
    genre_movie[movie.genre].insert({movie.total_score, movie.time_stamp, mID});
    
    user_history[uID].push_back({mID, mRating});
    is_watched[uID].insert(mID);

    return 1;
}

RESULT suggest(int uID)
{
    int target_genre = 0;
    
    vector<Viewing_History> least_watched;
    vector<Viewing_History>& history = user_history[uID];
    for (int i = history.size() - 1; i >= 0 && least_watched.size() < 5; --i) {
        if (!movie_info[history[i].mID].is_deleted) {
            least_watched.push_back(history[i]);
        }
    }

    if (!least_watched.empty()) {

        int target_rating = 0;
        for (const auto& watched_movie : least_watched) {
            if (watched_movie.rating > target_rating) {
                target_rating = watched_movie.rating;
            }
        }

        for (const auto& watched_movie : least_watched) {
            if (watched_movie.rating == target_rating) {
                target_genre = movie_info[watched_movie.mID].genre;
                break;
            }
        }
    }

    RESULT ans;
    ans.cnt = 0;

    if (target_genre != 0) {

        for (const auto& movie_to_suggest : genre_movie[target_genre]) {
            if (is_watched[uID].count(movie_to_suggest.mID) == 0) {
                ans.IDs[ans.cnt++] = movie_to_suggest.mID;
                if (ans.cnt == 5) break;
            }
        }
    } else {

        vector<set<Set_cmp>::iterator> iterators(6);
        for(int i = 1; i <= 5; ++i) {
            iterators[i] = genre_movie[i].begin();
        }

        while (ans.cnt < 5) {
            int best_genre_idx = -1;

            for (int i = 1; i <= 5; ++i) {
                if (iterators[i] != genre_movie[i].end()) {
                    if (best_genre_idx == -1 || *iterators[i] < *iterators[best_genre_idx]) {
                        best_genre_idx = i;
                    }
                }
            }

            if (best_genre_idx == -1) break;

            const Set_cmp& candidate = *iterators[best_genre_idx];

            if (is_watched[uID].count(candidate.mID) == 0) {
                ans.IDs[ans.cnt++] = candidate.mID;
            }
            iterators[best_genre_idx]++;
        }
    }

    return ans;
}
/////////////////////////////////////////////////////////////////////////
//                                                                     //
// 이 아래는 제공된 main(드라이버) 코드입니다. 수정하지 마세요.              //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

#define CMD_INIT        (100)
#define CMD_ADD         (200)
#define CMD_ERASE       (300)
#define CMD_WATCH       (400)
#define CMD_SUGGEST     (500)

static bool run()
{
    int Q, N;
    int mID, mGenre, mTotal, mRating, uID;

    int ret = -1, cnt, ans;

    RESULT res;

    scanf("%d", &Q);

    bool okay = false;

    for (int q = 0; q < Q; ++q)
    {
        int cmd;
        scanf("%d", &cmd);

        switch(cmd)
        {
            case CMD_INIT:
                scanf("%d", &N);
                init(N);
                okay = true;
                break;
            case CMD_ADD:
                scanf("%d %d %d", &mID, &mGenre, &mTotal);
                ret = add(mID, mGenre, mTotal);
                scanf("%d", &ans);
                if (ret != ans)
                    okay = false;
                break;
            case CMD_ERASE:
                scanf("%d", &mID);
                ret = erase(mID);
                scanf("%d", &ans);
                if (ret != ans)
                    okay = false;
                break;
            case CMD_WATCH:
                scanf("%d %d %d", &uID, &mID, &mRating);
                ret = watch(uID, mID, mRating);
                scanf("%d", &ans);
                if (ret != ans)
                    okay = false;
                break;
            case CMD_SUGGEST:
                scanf("%d", &uID);
                res = suggest(uID);
                scanf("%d", &cnt);
                if (res.cnt != cnt)
                    okay = false;
                for (int i = 0; i < cnt; ++i)
                {
                    scanf("%d", &ans);
                    if (res.IDs[i] != ans)
                        okay = false;
                }
                break;
            default:
                okay = false;
                break;
        }
    }

    return okay;
}

int main()
{
    setbuf(stdout, NULL);
    // 로컬에서 테스트할 때 아래 주석을 풀고 사용하세요.
    // freopen("sample_input.txt", "r", stdin);

    int TC, MARK;

    scanf("%d %d", &TC, &MARK);
    for (int tc = 1; tc <= TC; ++tc)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}