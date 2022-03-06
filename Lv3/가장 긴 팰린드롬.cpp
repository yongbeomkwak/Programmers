#include <iostream>
#include <string>

#define MAX 2501
int dp[MAX][MAX];
using namespace std;
int solution(string s)
{

    int n = s.length();
    if (n == 1)
        return 1;
    int answer = 1;

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1; //자기자신 회문
    }

    for (int i = 1; i < n; i++) // dp[0][1] :1번째 2번째 글자로  회문 가능하냐
    {
        if (s[i] == s[i - 1])
            dp[i - 1][i] = 1;
    }

    // dp[i][j] =i번째부터 j까지 회문이냐?
    for (int i = 2; i < n; i++) //회문길이 i=2 -> 길이가 3일때, i=n-1 ,길이가 n일 때
    {
        for (int j = 0; j < n - i; j++) // j:해당 길이 i일 때 출발 가능한 범위
        // abcd 에서 해당길이가 i=2라는 뜻은
        //전체 길이가 3이 될수 있는 회문
        // abc bcd 즉 출발지점은 0~1 까지이다.
        // j =0  j<n(4)-i(2)
        {
            // cout << i << " "<< j << " " << i+j <<endl;
            if (s[j] == s[j + i] && dp[j + 1][i + j - 1]) //끝값 이 같고 ,해당 사이 값이 같을경우
            {
                answer = max(answer, i + 1);
                dp[j][j + i] = 1; // j~ i+j까지 회문
            }
        }
    }

    return answer;
}