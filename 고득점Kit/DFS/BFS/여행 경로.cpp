#include <bits/stdc++.h>

using namespace std;

vector<string> answer;

bool dfs(string now, vector<bool> &use, vector<vector<string> > &tickets, const int use_tickets)
{
    answer.push_back(now);
    if (use_tickets == tickets.size())
        return true; //모든 티켓 다 사용 시

    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets[i][0] == now && use[i] == false) //출발 지역이 일치하고 사용하지 않았다면
        {
            use[i] = true; //사용
            string arri = tickets[i][1];
            bool t = dfs(arri, use, tickets, use_tickets + 1); //다음 행성지, , ,사용 횟수 증가
            if (t)
                return true; // 찾았다면 true
            use[i] = false;  //통과가 안됬다면 다시 사용하기 위해 false
        }
    }

    //여기 까지 내려왔다면 현재 티켓 다시 되돌리기
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string> > tickets)
{

    vector<bool> use(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    dfs("ICN", use, tickets, 0);

    return answer;
}