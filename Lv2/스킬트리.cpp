#include <bits/stdc++.h>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;

    for (string &s : skill_trees)
    {
        vector<bool> used(skill.size(), false); //스킬 배움 여부
        bool flag = true;                       //통과 플래그
        for (const char &c : s)
        {
            if (skill.find(c) != string::npos) //만약 스킬 트리에 선행스킬이 있다면
            {
                int idx = skill.find(c); //해당 인덱스를 찾고
                if (idx == 0)            // 0이면 기초스킬이 므로
                {
                    used[0] = true; //배움
                }
                else //이닐 경우 선행 스킬 확인 해야함
                {
                    for (int i = 0; i < idx; i++) //현재 스킬 이전 선행스킬들 확인
                    {
                        if (!used[i]) //선행 스킬들 중 하나라도 배운게 없다면
                        {
                            cout << s << endl;
                            flag = false; //잘못된 스킬트리
                            break;
                        }
                    }
                    if (!flag)
                        break;        //스킬트리 뒷 내용 볼필요 없음
                    used[idx] = true; //이전에 이상 없다면 배울 수 있음
                }
            }
        }
        if (flag)
            answer++; //끝까지 문제 없다면 증가
    }
    return answer;
}