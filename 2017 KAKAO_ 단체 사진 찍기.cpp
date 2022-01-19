#include <bits/stdc++.h>

using namespace std;

int answer;
bool selected[8];
char people[8]={'A','C','F','J','M','N','R','T'};
    
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

void DFS(const int cnt,char arr[],vector<string>& data) //현재 인원 수,자리 공간 배열,요구 조건
{
    if(cnt==8) //모두 담았을 때  
    { 
      
      for(int i=0;i<data.size();i++)  
      {
          //정보 형식: N~F=0 , N:조건 요구 사람(0), ~(1),타겟 사람(2),조건식=(3),거리(4)
          // 인덱스 0 2 3 4 만 사용
          char ask=data[i][0];
          char target=data[i][2];
          char oper=data[i][3];
          int dist=data[i][4]-'0'; //char to int
          dist++; // 거리=인덱스1-인덱스2 -1  이므로
       
          // 123 일때 1과2의 거리는 0 , 1과 3의 거리는 1이다.
          // 3-1= 2  -1 =거리=1 성립
          //그렇다면 거리+1=인덱스1-인덱스2  이므로 ++ 시켜준다 
          
          int idx,iidx; //-1로 초기화
          idx=iidx=-1;
          for(int j=0;j<8;j++)
          {
              if(ask==arr[j]) idx=j; //현재 조건 요청자의 위치를 찾는다. 
              if(target==arr[j]) iidx=j; //현재 타겟의 위치를 찾는다
              if(idx!=-1&&iidx!=-1) break; //모두 찾앗다면 break; 
          }
          if(oper=='='&&abs(idx-iidx)!=dist) return; //해당 oper가 = 이고 해당 위치 차이(거리)가 같지 않을 때 조건을 성립하지 못햇을 때  
          if(oper=='<'&&abs(idx-iidx)>=dist) return; // <인데 같거나 크면 조건 성립 x
          if(oper=='>'&&abs(idx-iidx)<=dist) return; // >인데 작거나 같으면 조건 성립 x
          
        
   
      }

         answer++; //모든 검증 끝나면 경우의 수 1 증가
         return;
    }
    
    for(int i=0;i<8;i++)
    {
        if(selected[i]==true) continue;
        selected[i]=true;
        arr[cnt]=people[i];
        DFS(cnt+1,arr,data);
        selected[i]=false;
    }
}


int solution(int n, vector<string> data) {
    answer=0;
    char arr[8] = {NULL,};
    DFS(0,arr,data);
    
    
    
    return answer;
}