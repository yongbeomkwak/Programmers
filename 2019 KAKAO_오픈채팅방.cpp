#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    vector<string> state;
    unordered_map<string, string> userInfo;

    for (int i = 0; i < record.size(); i++)
    {
        string command[3];
        int index = 0;
        stringstream ss(record[i]); // 벡터안에 문자열 한줄이 모두 stringstream에 들어감

        string temp;
        while (ss >> temp) //공백과 줄바꿈을 제외한 문자들 추출
        {
            command[index++] = temp; //"Enter uid1234 Muzi 가 차례대로 들어감"
        }

        if (command[0] == "Enter")
        {
            userInfo[command[1]] = command[2]; // command[1]=id, command[2]=닉네임
            answer.push_back(command[1]);      // id만 갖고있는다
            state.push_back("들어왔습니다.");  // Enter State 삽입
        }
        else if (command[0] == "Change")
        {
            userInfo[command[1]] = command[2]; //변경
        }
        else
        {
            answer.push_back(command[1]);   // id만 갖고 있는다.
            state.push_back("나갔습니다."); // Leave State 삽입
        }
    }

    for (int i = 0; i < answer.size(); i++)
    {
        answer[i] = userInfo[answer[i]] + "님이 " + state[i]; // answer에 저장된 id를 닉네임으로 바꾼후 +"님이 " +해당 상태
    }

    return answer;
}