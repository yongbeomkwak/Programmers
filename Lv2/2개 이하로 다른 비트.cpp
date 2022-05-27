#include <bits/stdc++.h>

using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for (long long n : numbers)
    {
        if (n % 2 == 0)
            answer.push_back(n + 1);
        else
        {
            //홀수는 최상위 비트 바로 직전 자리를 올려주면
            //최상위 비트도 변하고 ,직전 비트도 변하므로 2개가 변함
            /*
            ex)
            0111 (7)  왼쪽에서 두번째 (최상위)직전 비트 +1
            1011 (11) 만족
         
            */ 
            long long bit = 1;
            while (1)
            {
                if ((bit & n) == 0)
                    break;
                bit <<= 1; //계속 왼쪽으로 밀면서 틀릴 때 까지
            }
            bit >>= 1; //한번만 오른쪽으로 옮겨 최상위 직전비트 위치를 만든후 
            answer.push_back(n + bit); //더함
        }
    }

    // cout << bitset<50>(1000000000000000).to_string();

    return answer;
}