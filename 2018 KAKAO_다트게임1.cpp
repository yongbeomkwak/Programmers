#include <bits/stdc++.h>

#define endl "\n"
using namespace std;

int solution(string dartResult)
{
    int answer = 0;
    vector<int> scores;
    int ten_count = 0; //숫자가 연속으로 2번 나오면 10이라는 소리

    for (const char &chr : dartResult)
    {
        if (chr == 'S' || chr == 'D' || chr == 'T') //보너스 S,D,T 면 제곱해야함
        {
            ten_count = 0;  //숫자가 아닌 알파벳이므로 카운트 0으로 변경
            if (chr == 'D') //D일 경우 마지막 값 제곱
            {
                scores[scores.size() - 1] = (int)pow(scores[scores.size() - 1], 2);
            }
            else if (chr == 'T') //T일 경우 마지막 값 세제곱
            {
                scores[scores.size() - 1] = (int)pow(scores[scores.size() - 1], 3);
            }
        }
        else if (chr == '*' || chr == '#') //옵션 * 또는 #일 경우
        {
            ten_count = 0; //역시 점수가 아니므로 카운트 0으로
            if (chr == '*')
            {
                if (scores.size() == 1) //현재 담은 점수 개수가 1개 뿐이면 첫번째만 2배
                {
                    scores[0] *= 2; //2배
                }
                else //아닐 경우 현재 점수와 이전 점수 2배
                {
                    scores[scores.size() - 1] *= 2;
                    scores[scores.size() - 2] *= 2;
                }
            }
            else //#일경우 현재 점수 음수로 변경
            {
                scores[scores.size() - 1] *= -1;
            }
        }
        else //점수 일경우
        {
            ten_count++;        //연속으로 나올 수 있으므로 카운트 증가
            if (ten_count == 2) //만약 ten_count가 2라는건 현재 점수가 10
            {
                scores[scores.size() - 1] = 10; //현재 점수 10으로 변경
                ten_count = 0;                  // 다시 초기화
                continue;                       // 벡터에 담으면 안되므로 continue
            }
            scores.push_back((int)(chr - '0')); //해당 값 int로 변경하여 점수 벡터에 삽입
        }
    }

    for (const int &score : scores) //점수 합산
    {
        answer += score;
    }

    return answer;
}