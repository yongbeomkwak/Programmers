#include <bits/stdc++.h>

using namespace std;
#define MAX 10000000001
#define STAR '*'
#define DOT '.'
typedef long long ll;
typedef struct _INFO
{
    ll y, x;
} info;

ll min_x = MAX;
ll max_x = -MAX;
ll min_y = MAX;
ll max_y = -MAX;
// 최대 최소 설정 좌표계
vector<info> v;

vector<string> solution(vector<vector<int>> line)
{
    vector<string> answer;
    const int n = line.size();
    for (int i = 0; i < n - 1; i++)
    {
        const ll A = line[i][0];
        const ll B = line[i][1];
        const ll E = line[i][2];
        for (int j = i + 1; j < n; j++)
        {
            const ll C = line[j][0];
            const ll D = line[j][1];
            const ll F = line[j][2];
            const ll deno = (ll)(A * D) - (ll)(B * C);
            const ll nume1 = (ll)(B * F) - (ll)(E * D);
            const ll nume2 = (ll)(E * C) - (ll)(A * F);
            //모든 교점 구하고 타입 캐스팅 ..
            if (deno == 0)
                continue; // AD-BC ==0 다시
            if (nume1 % deno != 0 || nume2 % deno != 0)
                continue; //둘중 하나 정수 아니면 패스

            ll x = (nume1 / deno);
            ll y = (nume2 / deno);

            min_x = min_x > x ? x : min_x;
            max_x = max_x < x ? x : max_x;
            min_y = min_y > y ? y : min_y;
            max_y = max_y < y ? y : max_y;
            //지속 적으로 최대 최소 좌표계 계산

            v.push_back({y, x}); // 조건 만족 시 해당  교점 y,x 저장
        }
    }

    answer = vector<string>(max_y - min_y + 1, string(max_x - min_x + 1, DOT));
    //해당 최대와 최소 좌표로 DOT=. 으로 채움
    for (info &i : v)
    {
        //이후 해당 좌표를 좌표이동 하여 *로
        /*

        y=0 (가장 위쪽을 기준으로) y가 클수록 max_y와 거리가 좁고, y가 작을수록 max_y와 거리가 커야하므로 max_y-i.y가 맞음

        x=0(가장 왼쪽을 기준으로) x가 클수록 min_x와 거리가 크고, x가 작을수록 min_x로 부터 거리가 작음 , 그러므로  i.x-min_x에서 빼줌


        간단히 2차원 행열 증가 방향이(우하향 방향이므로, 행은 출발이(위), 열은(왼쪽)

        0을 포함한 양의 정수가 되기 위해서는 max_y에서 i.y를 빼주고

        x는 i.x에서 min_x를 빼주면 됨

        */
        answer[max_y - i.y][i.x - min_x] = '*';
    }

    return answer;
}