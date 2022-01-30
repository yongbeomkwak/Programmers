#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    int len = people.size();
    sort(people.begin(), people.end(), greater<int>()); //내림차순 정렬 왼쪽이 가장 큰 수
    int left = 0;                                       //왼쪽 출발
    int right = len - 1;                                //오른쪽 출발

    /* for(const int &i:people)
     {
         cout << i << " ";
     }
     cout << endl;*/
    int sum = 0;          //현재 까지 더한 몸무게
    while (left <= right) //둘이 겹칠 때 까지
    {
        sum += (people[left] + people[right]); //최댓값과 쵯솟값을 더 하자

        if (left == right) //겹치면 한명 남은 것
        {
            answer++; // 보트 하나 증가
            break;
        }
        if (sum > limit) //더한 값이 크다 ? 그러면 최댓값만 보트 태워 보내야함
        {
            answer++; //보트 증가
            sum = 0;  //더한 값 초기화
            left++;   //최댓값 이동
        }
        else if (sum == limit) //같다? 더한 애들 보트 태워 보내자
        {
            answer++; //보트 하나 증가
            sum = 0;  //더한값 초기화
            left++;   // 최댓값 이동
            right--;  //최솟값 이동
        }
        else //더한값이 제한 값보다 작다?  그다음 최솟값을 담아야함.
        {
            sum += people[right]; // 최솟값만 일단 담고
            right--;              //최솟값 이동
            continue;
        }
    }

    return answer;
}