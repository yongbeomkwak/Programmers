#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s)
{
    if (n > s)
        return {-1};
    vector<int> answer;

    /*해당 수 s를 해당 개수 n으로 나누게 되면
        해당 차례에서 가장 최대 수 가됨
        n: 2 s=9
        candidate: {1,8},{2,7},{3,6} ,{4,5}
        s/n= 4  4 이전 1,2,3은 필요없음
        다음 n=1 s=s-s/n=(9-4)=5
        s/n=5
        answer={4,5}
        n과 s가 계속 줄어드므로 n이 줄어드는 폭이 s가 줄어드는 폭보다 큼
        s/n은 커짐 그러므로 자동적으로 오름차순
    */

    while (n != 0)
    {
        answer.push_back(s / n);
        s -= s / n;
        n--;
    }

    // sort(answer.begin(),answer.end());
    return answer;
}