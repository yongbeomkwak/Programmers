#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer(2, 0);

    priority_queue<int> pq1;                             //내림차순  top():최댓값
    priority_queue<int, vector<int>, greater<int> > pq2; // 오름차순
    int cnt = 0;                                         //전체 큐에 담고 있는 개수

    for (const string &s : operations)
    {
        string opers[2];
        stringstream ss(s);
        ss >> opers[0] >> opers[1];
        int val = stoi(opers[1]);

        if (cnt == 0)
        {
            while (!pq1.empty())
                pq1.pop();
            while (!pq2.empty())
                pq2.pop();
        }

        if (opers[0] == "I") // 삽입
        {
            pq1.push(val);
            pq2.push(val);
            cnt++;
        }
        else
        {
            if (cnt == 0)
                continue; //큐에 아무것도 없을 시 반복

            if (opers[1] == "1") //최댓값 삭제
            {
                pq1.pop();
                cnt--;
            }
            else //최솟값 삭제
            {
                pq2.pop();
                cnt--;
            }
        }
    }
    if (cnt != 0) //힙이 비어있지 않으면
    {
        answer[0] = pq1.top();
        answer[1] = pq2.top();
    }

    return answer;
}