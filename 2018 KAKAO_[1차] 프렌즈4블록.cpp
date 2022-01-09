#include <bits/stdc++.h>

using namespace std;

#define endl "\n"


int solution(int m, int n, vector<string> board) {
   int answer = 0, i = 0, j = 0;
   bool keep = true;
   
    while(keep)
    {
        keep=false;
        bool arr[30][30]={false,};
        
        for(i=0;i<m-1;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(board[i][j] == ' ') //이미 조건을 만족하여 사라진 것 
                    continue;
                char target = board[i][j];
                if(target==board[i+1][j] && target==board[i][j+1] && target ==board[i+1][j+1]) //4개 모두 같다면
                {
                    arr[i][j] = true;
                    arr[i][j + 1] = true;
                    arr[i + 1][j] = true;
                    arr[i + 1][j + 1] = true;
                    keep = true; // 계속 탐색 
                }
            }
        } //터트릴 꺼 찾기
        
        
         for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(arr[i][j] == true) //true 면 찾은 것
                {
                    answer++; // 증가 
                    
                    for(int k = i - 1; k >= 0; k--)
                    {
                        //위에 것을 떨어 트려야하므로
                        //[k+1][j] 아래 [k][j] 위
                        //[k+1][j]=[k][j];
                        
                        board[k + 1][j] = board[k][j];
                        board[k][j] = ' '; //떨어트렸으므로 빈칸
                    }
                }
            }
        }
        
        
        
        
    }
        

    
    
    
    return answer;
    
}