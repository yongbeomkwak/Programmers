#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());

    int left = 0;                  //가장 무거운 사람
    int right = people.size() - 1; // 가장 가벼운 사람

    while (left <= right)
    {
        if (people[left] + people[right] <= limit) // 두 합이 limit보다 작거나 같으면
        {
            //왼쪽은 오른쪽으로 전진 ,오른쪽은 왼쪽으로 후진
            left++;
            right--;
        }
        else
        {
            left++; //그렇지 않으면 왼쪽(무거운놈)만 다음 오른쪽으로 이동
        }
        answer++;
    }

    return answer;
}