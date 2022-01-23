#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<int, int> >::iterator vi;

void runTask(vector<pair<int, int> > &comb) // first:현재 진행도, second:Step(개발속도)
{
    for (int i = 0; i < comb.size(); i++)
    {
        comb[i].first += comb[i].second;
    }
}

void init(vector<pair<int, int> > &comb, vector<int> &p, vector<int> &s)
{
    for (int i = 0; i < p.size(); i++)
    {
        comb.push_back({p[i], s[i]});
    }
}

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    vector<pair<int, int> > comb;

    init(comb, progresses, speeds);

    while (comb.size() != 0) //모든 작업이 끝날 때 까지 반복
    {
        int cnt = 0;

        if ((*(comb.begin())).first < 100) //가장 앞 진행 정도가 100이 되지않을 시
        {
            runTask(comb); //모든 진도 진행
            continue;
        }

        while ((*(comb.begin())).first >= 100 && !comb.empty())
        // 가장 앞 진행도가 100이상일 때
        //여기서 중요한 것은 cob.empty()기 빠지면 무한 루프를 돈다.
        //.first가 아무것도 없어도 가장 마지막으로 지워진 녀석을 계속 가르킴
        //모두 워진게 있는지 확인
        {
            cnt++;                    //같은 일에 몇개의 진도가 해결될지 증가
            comb.erase(comb.begin()); //진행 끝났으므로 앞에서 빼주고
        }

        if (cnt != 0)
            answer.push_back(cnt); //해당 루프에 끝난 프로그래스를 삽입
    }

    return answer;
}