#include <bits/stdc++.h>

using namespace std;

int getNN(const int n, const int idx)
{
    int ret = n;
    for (int i = 1; i < idx; i++)
    {
        ret = ret * 10 + n; // if(n=5) ,idx=2 면 55임 , n=5 idx=3면 555
    }
    return ret;
}

int solution(int N, int number)
{
    if (N == number)
        return 1;
    vector<unordered_set<int> > DP(9);
    // dp[i]는 : i개의 N을 이용하여 만들 수 있는 수들
    //중복되어야 하지 않으므로 set 사용
    DP[1].insert(N); // N을 1개 사용하여 만들 수 있는 것 N뿐
    // DP[2]=N을 2번  사용 ,  NN 또는 N (연산) N  구조

    for (int k = 2; k <= 8; k++) // 2 부터 최대 8개 까지 사용 가능  , 1개는 위에서 이미 처리함
    {
        for (int i = 1; i < k; i++)
        {
            for (int j = 1; j < k; j++)
            {
                if (i + j != k)
                    continue;             // i+j이  k개를 만들 수 있어야함
                for (const int a : DP[i]) // i 안에 들어있는 set을 하나씩 꺼내서
                {
                    for (const int b : DP[j])
                    {
                        //합 차 나눗셈 곱셈 연산을 하고 , 차와 나눗셈은 예외가 있으므로 처리
                        DP[k].insert(a + b);
                        if (a - b > 0)
                            DP[k].insert(a - b);
                        if (a / b > 0)
                            DP[k].insert(a / b);
                        DP[k].insert(a * b);
                    }
                }
            }
        }
        DP[k].insert(getNN(N, k)); // N=5 , 55(k=2) 555(k=3) 5555(k=4) 같이 해당 k에 맞게 추가

        if (DP[k].count(number))
            return k; // nuber가 k번째 셋에 있을 때 k가 최소사용
    }

    return -1;
}