/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;



vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input); 
    string temp;
    while (getline(ss, temp, delimiter)) {  //ss의 값을 delimitder를 만난 면 temp 그 이전 것 을 담음 
        answer.push_back(temp);
    }
    return answer;
}





int main()
{
    string a ="333 333 333";
    string b ="444 \n 124";
    
    stringstream ss1(a); //해당 문자열을 a로 ss1을 최고하
    stringstream ss2;
    ss2.str(b); //해당 문자열 b로 ss2를 초기화 
    
    string temp1,temp2;
    
    while(ss1>>temp1) //끝까지 뽑아 내서 출력 (공백과 줄바꿈은 무시하고 출력해줌)
    {
        cout << temp1 <<endl;
    }
    
    while(ss2>>temp2)
    {
        cout << temp2 <<endl;
    }
    
    

    return 0;
}
