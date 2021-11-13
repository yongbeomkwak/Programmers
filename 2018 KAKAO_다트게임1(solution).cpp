#include <bits/stdc++.h>

using namespace std;

int solution(string dartResult)
{
    stringstream ss(dartResult); //defaultResult 스트링을 담음

    int sum[3] = {0, 0, 0};     //각 횟수별 점수를 담을 배열
    int options[3] = {1, 1, 1}; //각 횟수별 옵션을 담을 배열
    for (int i = 0; i < 3; i++)
    {
        int score;
        char bonus;
        char option;

        ss >> score; //score의 타입이 int이므로 문자열중 int가 되는 곳 끝까지 커서를 옮김
                     //ex) 123#5678 -> score에는 123이 담기게 된다.
                     //ss는 123의 3을 가르켜 다음은 커서 위치는 #가된다

        //get():현재 ss 위치 커서를 다음 위치로 옮겨 해당 칸의 값을 뽑아 낸다.
        bonus = ss.get(); //점수부분에서 커서를 한칸 뒤로 움직여 보너스 부분을 봄,S,D,T ->
        //get은 ASCII Code인 숫자지만 그것을 char 변수에 담으므로 알아서 S,D,T중 하나로 변환됨
        option = ss.get();
        //다시 커서를 옮겨 option쪽을 봄
        cout << score << " " << bonus << " " << option << endl;

        if (option != '*' && option != '#')
        { //만약 옵션 쪽을 봤는데 어느 옵션도 아니면
            //잘못 이동 (즉 옵션 값이 아님)
            //unget():커서를 한칸 앞으로 이동
            ss.unget(); //커서를 앞으로 이동
        }

        switch (bonus)
        { //bonus가 케이스별로 제곱을 시작한다
        case 'S':
            sum[i] += pow(score, 1);
            break;
        case 'D':
            sum[i] += pow(score, 2);
            break;
        case 'T':
            sum[i] += pow(score, 3);
            break;
        default:
            break;
        }

        switch (option)
        {
        case '*':
            //만약 i가 첫번째 순서가 아니면
            if (i > 0)
                options[i - 1] *= 2; //전 값도 2배
            options[i] *= 2;         //현재 값 2배
            break;
        case '#':
            options[i] = -options[i]; //현재 값 음수
            break;
        default:
            break;
        }
    }

    return sum[0] * options[0] + sum[1] * options[1] + sum[2] * options[2];
}
