#include <bits/stdc++.h>
using namespace std;

int solution(string name)
{
    int answer = 0;
    int len = name.length();
    int target_idx;
    int move = len - 1;
    for (int i = 0; i < name.size(); i++)
    {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1); // 현재 i위치 상하를 이용하여 조절한 하여 마춘 후
        target_idx = i + 1;                              //다음 위치

        while (target_idx < len && name[target_idx] == 'A') // 다음 변경할 것을 찾기위한 이동
        {
            target_idx++; //연속으로 A 넘어감
        }

        //여기서 target_idx는 다음 고쳐야할 위치
        int a = i;                //왼쪽에서
        int b = len - target_idx; //오른쪽 끝에서 타겟까지 거리

        // 현재 A가 아닌게 i와 target_idx인데 ,
        // 원점 기준 a(i로 이동) a(다시원점) b(target_idx로 이동)
        // 또는 b(target_idx로 이동) b(다시 원점) a(i로 이동)
        // 2개중 짧은거
        // 0 -> a -> a -> b
        // 0 -> b -> b -> a ,
        //둘 중 최솟 값
        move = min(move, a + b + min(a, b)); // a+b는
    }

    return answer + move; //상하 + 좌우
}