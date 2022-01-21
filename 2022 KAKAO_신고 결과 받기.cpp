#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer(id_list.size(), 0);  //유저 수만큼 0으로 초기화
    unordered_map<string, set<string> > um; // key:신고한 유저 value: 신고당한 유저들
    unordered_map<string, int> reports;     // key:신고받은 유저, value:신고 받은횟수

    for (const string s : report)
    {
        stringstream ss(s);
        string tmp[2];
        ss >> tmp[0] >> tmp[1]; // 0:신고한 사람 , 1:신고 받은 사람

        if (um[tmp[0]].count(tmp[1]) == 0) //신고자가 해당 사람을 처음 신고햇다면
        {
            um[tmp[0]].insert(tmp[1]); //신고했으므로 set에 추가
            if (reports.find(tmp[1]) == reports.end())
                reports[tmp[1]] = 1; //처음으로 신고 받았으면 1
            else
                reports[tmp[1]]++; // 아니면 ++
        }
    }

    for (int i = 0; i < answer.size(); i++)
    {
        string reporter = id_list[i];      //신고자
        if (um.find(reporter) != um.end()) //신고자가 신고한 사람이 있다면
        {
            for (auto it = um[reporter].begin(); it != um[reporter].end(); it++) //해당 신고 당한 사람들 set을 돌며
            {
                string badUser = *it; //신고 받은사람

                if (reports[badUser] >= k) //해당 신고 받은 사람의 신고 횟수가 k이상일 경우
                {
                    answer[i]++; //증가
                }
            }
        }
    }

    return answer;
}