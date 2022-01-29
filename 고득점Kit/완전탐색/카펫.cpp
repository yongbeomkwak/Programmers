#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    int sum = brown + yellow;

    for (int h = 3;; h++) // 무한루프
    {
        if (!(sum % h))
        {
            int w = sum / h;
            if (((h - 2) * (w - 2)) == yellow)
            {
                //왜 2냐
                // h-2 = 지붕과 껍데기 날리고
                // w-2 =왼쪽과 오른쪽 측면 날리면
                // 나머지를 가운데로 생각
                // 그값이 yellow와 같다면 찾은거
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
    }
    return answer;
}