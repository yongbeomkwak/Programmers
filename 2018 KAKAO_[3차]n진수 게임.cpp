#include <bits/stdc++.h>

char List[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };




using namespace std;

string Invert(int num,int n)
{
    //들어온 숫자 num을 n진법으로 전환하여 R_value에 담아 리턴한다
    string R_value="";
    while(num/n!=0)
    {
        string tmp=R_value; //잠시 저장
        R_value=List[num%n]; // 나머지 연산에 해당되는 숫자를 해당 진법으로 변환 
        R_value+=tmp; //저장한거 뒤로 불러옴
        num/=n; //나눗셈연산 한것으로 다시 변경 
    }
    
    //마지막 작업 또는 num/n!=0을 만족 시키지 않을 경우 첫 작업 
    string tmp=R_value;
    R_value=List[num%n];
    R_value+=tmp;
    return R_value;
}


string solution(int n, int t, int m, int p) {
    /*
    n=진법 (2~16)
    t=미리 구해야할 숫자 개수(0<=1000)
    m=참가 인원(2~100)
    p=나의 순서 (1<=p<=n)
    */
    string answer = "";
    string res="";
    int cnt=0;
    //구해야하는 숫자 * 참가인원 까지에 해당하는 숫자 구해야함 
    for(int i=0;i<t*m;i++) res+=Invert(i,n); //t*m범위 까지 모든 숫자를 해당 진법화 하여 쭈욱 나열하여 res에 저장
    for(int j=p-1;j<res.length(),cnt<t;j+=m) //나의 첫 순서 부터 m만큼 순서 증가하여 내 순서만 체크,  p-1인 이유는 string은 0부터 시작하므로
    {
        answer+=res[j];
        cnt++;
    }
    return answer;
}