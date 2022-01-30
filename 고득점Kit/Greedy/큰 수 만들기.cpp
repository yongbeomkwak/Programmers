#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k)
{
    string answer = "";

    int req = number.size() - k; //목표 자릿수
    int i = 0;                   //현재 위치
    int right_end = k;           //
    cout << number.size() << endl;

    while (answer.size() != req)
    {

        int _max = -1;
        // cout <<answer << " " << i << " " << left_end <<endl;
        for (int j = i; j <= right_end; j++)
        //현재 위치부터 오른쪽 끝 범위 까지 최댓값을 찾는다(Greedy)
        {
            if (_max < number[j] - '0')
            {
                _max = number[j] - '0'; //찾았으면 최댓값을 바꾸고
                i = j + 1;              //현재위치를 찾은값 다음으로 이동
            }
        }
        answer += number[i - 1];
        // i는 다음 while문의 현재 위치이므로 현재 정답에는 바로 이전값이 현재 루프의 찾은값
        right_end++; //값을 하나 찾았으므로 오른쪽 끝위치를 뒤로 미룬다
    }

    return answer;
}