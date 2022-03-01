#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> lines)
{
    int answer = 0;
    vector<int> t_start, t_end;

    for (const string &s : lines)
    {
        string h, m, sec, ms;
        int ih, im, is, process;

        h = s.substr(11, 2);
        m = s.substr(14, 2);
        sec = s.substr(17, 2);
        ms = s.substr(20, 3);
        process = stof(s.substr(24, 5)) * 1000;

        ih = stoi(h) * 3600 * 1000; //모두 밀리 초로 변경
        im = stoi(m) * 60 * 1000;
        is = stoi(sec) * 1000 + stoi(ms);

        // end time =ih+im+is
        // start time= end time - process +1
        t_start.push_back(ih + im + is - process + 1);
        t_end.push_back(ih + im + is);
    }

    for (int i = 0; i < lines.size(); i++)
    {
        int end_time = t_end[i] + 1000; //현재 응답종료 의 1초 후 시간과 현재 응답 시간요소 부터 끝까지
        int cnt = 0;
        for (int j = i; j < lines.size(); j++) // j=i 부터
        {
            if (end_time > t_start[j])
                cnt++; //응답시간의 시작시간이 현재 응답의 종료 시간보다 작으면 해당 구간에 존재
        }

        answer = max(answer, cnt);
    }

    return answer;
}