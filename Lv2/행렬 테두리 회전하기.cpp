#include <bits/stdc++.h>

using namespace std;
typedef vector<vector<int>> vvi;

vvi global_matrix; //이전 상태를 저장할 전역 행렬

void print(vvi& tmp)
{
    const int r=tmp.size();
    const int c=tmp[0].size();
    cout << r << " " << c << endl;
    
    
     for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            cout << tmp[i][j] << " ";
        }
        cout << endl;
    }
   
}


vvi init(const int r,const int c)
{
    vvi ret(r+1,vector<int>(c+1,0));
    
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
           int & tmp=ret[i][j];
            tmp=(i-1)*c+j;
        }
    }
    
    return ret;
}

int rotation(const int r1,const int r2,const int c1,const int c2,vvi& matrix)
{
    vector<int> switched;
    
    //-> (오른쪽으로 이동 )
    
    for(int i=c1+1;i<=c2;i++)
    {
        matrix[r1][i]=global_matrix[r1][i-1]; // 전역행렬 왼쪽 값으로  현재 행렬 오른쪽으로 채움 
        switched.push_back(global_matrix[r1][i-1]); //움직인 값
    }
    
    
    /*
        |
        V (아래로)
    */ 
    
    for(int i=r1+1;i<=r2;i++) 
    {
        matrix[i][c2]=global_matrix[i-1][c2]; //마찬가지로 전영행렬 윗 값으로 현재행렬 아래 값을 채움
        switched.push_back(global_matrix[i-1][c2]);
    }
    
    //<- 오른쪽을 이동
    for(int i=c2-1;i>=c1;i--)
    {
        matrix[r2][i]=global_matrix[r2][i+1]; //전역 오른쪽을 현재 왼쪽에 넣음
        switched.push_back(global_matrix[r2][i+1]);
    }
    
    /*
        ^
        |  위로 
    */
    
    for(int i=r2-1;i>=r1;i--)
    {
        matrix[i][c1]=global_matrix[i+1][c1];
        switched.push_back(global_matrix[i+1][c1]);
    }
    
    return *(min_element(switched.begin(),switched.end()));
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vvi matrix=init(rows,columns);
    //print(matrix);
    global_matrix=matrix;
    matrix[0][0]=3;
    cout  << matrix[0][0] << " "<< global_matrix[0][0] <<endl;
    for(vector<int>& query:queries)
    {
        const int r1=query[0];
        const int c1=query[1];
        const int r2=query[2];
        const int c2=query[3];
        answer.push_back(rotation(r1,r2,c1,c2,matrix));
        global_matrix=matrix; //전역 행렬을 한번회전 후 행렬로 다시 덮어준다.
    }
  
    
    return answer;
}