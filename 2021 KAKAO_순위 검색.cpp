#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
unordered_map<string,vector<int>> scores;

//모든 조합 
void comb(string *p,int score) {
    string s = "";
    for (int i = 0; i < (1 << 4); i++) { //언어 직군 경력 소울푸드 4가지를 가지고 모든 조합
        s = "";
        for (int j = 0; j < 4; j++) {
            if (i & (1 << j)) // i안에 (1<<j)가 있을 경우 
                s += p[j];
            else  //0일때 
                s += '-'; //조합이 안들어 있을경우 -로
        }
        scores[s].push_back(score); // 해쉬맵에서 s를 키로 갖고있는 벡터에 점수를 삽입
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string s[4],str="";
    
    
    for(int i=0;i<info.size();i++)
    {
        istringstream iss(info[i]);
        iss >> s[0] >>  s[1] >> s[2] >> s[3] >> str;
        comb(s,stoi(str)); //길이 4인 배열에 언어,직군,경력,소울 푸드 그리고 점수를 매개변수로 보내준다.
 
    }
    
    for(auto& m :scores)
    {
        sort(m.second.begin(),m.second.end()); //  이진 탐색을 위한 정렬
    }
    
    
    
    for(int i=0;i<query.size();i++)
    {
        istringstream ss(query[i]);
         string queryInfos[4];
         string queryScore;
         string trash;
         // 언어 and 포지션 and 경력 and 푸드 and 점수
         // 여기서 and를 trash에 넣어줌 나머지는  queryInfos 배열에 점수는 queryScore에
         ss >> queryInfos[0] >> trash >> queryInfos[1] >> trash >> queryInfos[2] >> trash >> queryInfos[3] >> queryScore;
        
        vector<int> tmp=scores[queryInfos[0]+queryInfos[1]+queryInfos[2]+queryInfos[3]];
        //해당 조건에 대한 벡터를 얻어옴
        if(tmp.size()!=0)
        {
            auto itt=lower_bound(tmp.begin(),tmp.end(),stoi(queryScore)); 
            //현재 tmp가 존재하면 오름차순으로 정렬되 었이다
            //queryScore와 같거나 큰 숫자중 가장작은값의 위치를 가리키는 포인트 반환
            
            answer.push_back(tmp.size()-(itt-tmp.begin())); 
            
            //해당 위치에서 시작위치를 빼면 인덱스 값이 나옴
            // ex 1 2 3 4 에서 3을 찾은 후 begin() 을 빼면 인덱스 값 2가 나옴
            //우리는 해당 점수 이상인 인원수를 알고 싶으로 전체 사이즈에서  인덱스 값을 빼준다.
            // 4 -2 = 2명을 찾아냄 
        }
        else //해당 점수 벡터가 없으면 가능한 인원 0명
        {
            answer.push_back(0);
        }
        
        
         
    }
    
    return answer;   
}