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
        cout << s[0] << s[1] << s[2] << s[3] << str <<endl;
    }
    

    
    return answer;   
}