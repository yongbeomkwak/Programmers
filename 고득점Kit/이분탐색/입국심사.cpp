#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
long long answer = 0;
/*ull bSearch(const int user_num,vector<bool>& isUsed,vector<ull>& times,const int time)
{

}
*/

long long solution(int n, vector<int> times)
{

    /*
        int smallest_element = *min_element(v.begin(),v.end());
        int largest_element  = *max_element(v.begin(),v.end());
    */
    sort(times.begin(), times.end());                         //오름차순 정렬
    long long left = 1;                                       //가장 최소시간
    long long right = (long long)times[times.size() - 1] * n; // 최대 시간 (오래걸린 시간 심사관에 모든 고객이 같을때)

    long long mid;
    while (left <= right)
    {

        // cout << mid << endl;
        long long done = 0;
        mid = (left + right) / 2; //기준시간
        for (int i = 0; i < times.size(); i++)
        {
            done += mid / times[i]; //현재 기준시간으로 각 심사관이 끝낸 인원 수
        }

        if (done < n) //끝낸 인원수가 n미만이면 기준 시간을 늘려야 하므로 left=mid+1
        {
            left = mid + 1;
        }
        else // 끝낸 인원수가 n이상이면 일단 처리는 다 끝냈음
        {
            if (mid <= right) //아직 mid(현재기준시간)이 right(최대시간)을 넘지 않았다면
            {
                answer = mid; //현재시간이 최솟값이 될 가능성
            }

            right = mid - 1; //최댓값 이동
        }
    }

    return answer;
}