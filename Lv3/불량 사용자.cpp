#include <bits/stdc++.h>

using namespace std;

bool check[9] = {
    false,
};

unordered_set<string> s;
vector<string> uid, bid;
int len;
void dfs(const int idx) //현재 금지 아이디 인덱스
{
    if (idx == len) // banned user들을 모두 걸러냈을 때
    {
        string tmp = "";
        for (int i = 0; i < uid.size(); i++)
        {
            if (check[i])
                tmp += uid[i];
        }
        s.insert(tmp); //헤당 유저 아이디들을 모두 더하여 하나의 문자열로 생각한다
        return;
    }

    for (int i = 0; i < uid.size(); i++)
    {
        bool isMatch = true;
        if (check[i])
            continue; // 만약 사용하면 넘어감

        if (uid[i].length() != bid[idx].length())
            continue;
        //현재 유저 아이디와 금지 아이디 길이가 다르면 같은 유저일 수 없음 넘어감

        for (int k = 0; k < uid[i].length(); k++) //금지 유저 찾기
        {
            if (bid[idx][k] == '*')
                continue; //*은 넘어감

            if (bid[idx][k] != uid[i][k]) //다를 경우  같을 수 없음 탐색 끝냄
            {
                isMatch = false;
                break;
            }
        }

        if (isMatch) //찾앗으면
        {
            check[i] = true;  //해당 유저 사용 표시
            dfs(idx + 1);     //다음 꺼 탐색
            check[i] = false; //완전 탐색
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    uid = user_id;
    bid = banned_id;
    len = banned_id.size();
    dfs(0);

    return s.size();
}