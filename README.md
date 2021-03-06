# Programmers

## Setting
- [#include <bits/stdc++.h>](https://raeyoungii.github.io/bits-stdc++.h/)
-  [climits](https://docs.microsoft.com/ko-kr/cpp/c-language/cpp-integer-limits?view=msvc-160)

##  0.  Base

0. cpp_kor_utf.cpp
  - 한글 문자 자르기
1.  arrayinit.cpp
    -   배열 초기화 방법(fill,memset)
2.  StringStream.cpp
    - 문자열 다루는 기본 스킬 

3.  벡터 최소값 최댓값 ,최대합 
~~~c++
        int smallest_element = *min_element(v.begin(),v.end());
          int largest_element  = *max_element(v.begin(),v.end());
        int sum=accumulate(v.begin(),v.end(),0); // 0은 초기값 , int 범위를 넘어가면 쓰레기값이 들어가니 주의
~~~
4.  [builtin.cpp](http://www.secmem.org/blog/2019/10/19/handy-function-about-bit/)
    - (32비트)기준 1과 0 개수 카운팅
~~~c++
int num1=__builtin_popcount(x)// 1의 개수
int left_zeros=<<__builtin_clz(x);//가장 왼쪽 1을 기준 왼쪽 0개수
int right_zeros=__builtin_ctz(x);//가장 오른쪽 1을 기준으로 오른쪽 0 개수
~~~
  


  
##  1.  2021 KAKAO_신규_이이디_추천
-   비트연산 이용 대소문자 변호나
-   strchr(문자열,문자) :포함 여부 
    -    char* strchr (char* str, int c);
         해당 문자열(str)에 해당 문자 c가 존재하면 해당 존재하는 곳 포인터 없으면 Null

##  2.  2021 KAKAO_숫자_문자열과_영단어
-   [regex](https://modoocode.com/303)
-   regex_replace(문자열,regex(패턴),대체할 문자열)
-   stoi(string) -> string -> int

##  3.  2018 KAKAO_비밀지도
-   bitset<비트수>(십진수).to_string():해당 십진수를 해당 비트수에 해당되는 이진수로 문자열 리턴

##  4.  2018 KAKAO_다트게임1(solution)
-   [stringstream](https://www.cplusplus.com/reference/sstream/stringstream/)
-   '>>' operator , .get(), .unget()

##  5. 2020 KAKAO_문자열 압축
-   string.substr(start,count) 
    -   start index부터 count개 까지 짜른 값을 리턴
    -   만약 count를 안적고 start만 명시하면 항상 끝까지 자름
-  [to_string(type)](https://www.cplusplus.com/reference/string/to_string/): 해당 type(정수형,부동소수점 형)을 string로 

##  6.  2019 KAKAO_오픈채팅
-  stringstream

##  7-1).  2020 KAKAO_Self괄호변환
-   string.erase(index,count):해당 위치로 부터 count개 제거
-   string.push_back(char): 해당 'char' 문자를 뒤에 삽입

##  7-2) 2020 KAKAO_괄호변환
-   괄호 쉽게 뒤집기
-   string.substr(index,count) or string.substr(index)

## 8.   2018 KAKAO_[1차]뉴스 클러스트링
-   [대소문자 변환](https://hoho325.tistory.com/314)
    -   toupper(char) tolower(char)  +=(소) ,-= 32(대)  |=32(소)
    -   [벡터간 집합연산](https://1coding.tistory.com/124)
    -   [교집합 차집합 참고](https://unluckyjung.github.io/cpp/2020/04/24/Set_Func/)
        -   반드시 두 벡터 v1,v2는 정령 후 사용  result는 결과를 담을 벡터
        - merge(v1.begin(),v1.end(),v2.begin(),v2.end(),result.begin());
          - merge는 중복 허용 **합집합** 
        - set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),result.begin());
          - set_union은 중복 허용 X **합집합**

        -   교집합 set_intersection()

                vector<int> buff(vec1.size() + vec2.size());
                auto iter = set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), buff.begin());
                buff.erase(iter, buff.end());

        -   차집합 set_difference()

                vector<int> buff(vec1.size() + vec2.size());
                auto iter = set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), buff.begin());
                buff.erase(iter, buff.end());

##  9.  2019 KAKAO_튜플Self
-   [char 숫자인지 확인](https://www.delftstack.com/ko/howto/cpp/how-to-determine-if-a-string-is-number-cpp/)
    -   isdigit(char c) : true or false  
- stoi(str): string -> int 

## 10. 2018 KAKAO_캐쉬Self
-   transform(str.begin(),str.end(),str.begin(),::toupper)
    -   transform사용
    -   해당 문자열 전체를 대문자로
    -   해당 문자열 전채를  소문자로(::tolower)
          
            transform(
             입력한 변수의 first 위치, 
             입력한 변수의 last 위치까지, 
             저장할 변수의 first 위치, 
             변환할 방법이 있는 함수
            ); 

##  11. 2021 KAKAO_메뉴 리뉴얼
-   DP
-   백트래킹

## 12. 2020 KAKAO_수식최대화
-   next_permutation(v.begin(),v.end()): 오르참순 정렬된 벡터의 모든 순열 
-   prev_permutation(v.begin(),v.end()): 내리참순 정렬된 벡터의 모든 순열 
-   do while과 자주 사용된다. 둘다 다음 순열이 있을 시 true리턴 없으면 false리턴
-   str.c_str(): string -> char *  변환
-   atoi(char *): char * -> int로 변환

##  13. 2018 KAKAO_[1차]프렌즈 블록
-   2x2 블록 제거하여  위 블록 떨어트리는 방법

## 14. 2019 KAKAO_후보키
-   비트 연산을 이용한 중복확인 및 비트를 이용한 반복문을 통해 모든 조합을 순회

## 15. 2017 KAKAO_카카오 프렌즈 컬러링북
-   BFS를 이용한 상하좌우 탐색

##  16 2018 KAKAO_[3차]n진수 게임
-   간단한 진법화(Invert)함수를 사용하여 해당 숫자를 n진수로 나타낼수 있음


## 17 2018 KAKAO_[3차]파일명 정렬
- [문자열 정렬](https://w51014.tistory.com/19)
  - str.c_str(): string -> char *  변환를 사용하여 매개변수 자리에 넣어준다.
  - strcmp(char *a,char *b) 
    - 문자열 비교 함수

  - strcasecmp(char *a,char *b) 
    - 대소문자를 무시하는 문자열 비교 함수
  - strncasecmp(char *a,char *b,int n) 
    - 대소문자를 무시하고, 지정한 길이만큼 문자열을 비교하는 함수

  -   리턴 값 해석
    > 0보다 작음	
    >>   string1이 string2보다 작음
    
    >  0 
    >>  string1이 string2와 같음
    
    >  0보다 큼	
    >>  string1이 string2보다 큼

## 18. 2018 KAKAO_[3차]방금 그곡
-   str.find("해당문자열"): str에서 해당 문자열 찾기
    -   못찾을 경우 string::npos 반환
    -   찾을 경우 해당 매칭 문자열 첫글자 인덱스 반환


##  19. 2021 KAKAO_순위 검색
-   istringstream 와 >> 를 이용하여 띄어쓰기 기준으로 계속 꺼내기
-   [이진탐색](https://codingwell.tistory.com/50)
    -   lower 나 upper 모두 사용전 **오름차순 정렬 필수**
    -   lower_bound(v.begin(),v.end(),key): 해당 위치를 가르키는 Iterator 리턴 
    -   
        -   v의 시작 부터 v 끝까지 중 key를 찾음, 만약  key가 없으면 key값 보다 큰 정수중 가장 작은 값의 위치를 찾아냄

    -   upper_bound(v.begin(),v.end().key):해당 위치를 가리크는 Iterator 리턴
        
        - key값을 초과하는 첫번 째 원소 위치 리턴
##  20. 2021 KAKAO_거리두기 확인하기
-   BFS

##  21. 2017 KAKAO_ 단체 사진 찍기
-   모든 경우의 수 (DFS)

##  22. 2022 KAKAO_주차 요금 계산
-   map의 iterator를 이용하여 key와 value 접근
-   (*it).first -> key , (*it).second ->value

##  23. 2022 KAKAO_k진수에서 소수 개수 구하기
-   진법 변환 invert 함수
-   소수 판별 isPrime 함수
-   해당 char 포인터에서 해당 문자 모든 위치 찾기(strchr(char *,char))

         char *pch = strchr(str, '0'); //'0' 위치를 찾음
        while(pch!=NULL)
        {

            pos.push_back(pch-str); //인덱스 
            pch =strchr(pch+1, '0'); //다음 
        }

##  24. 2022 KAKAO_양궁대회
-   백트래킹,DFS, for문에 이중조건
-   가장 중요한 것은 재귀 함수 사용시 변수를 &(래퍼런스) 전달의 중요성 , 복사되니깐 시간초과 ㅈㄴ 남

##  25. 2022 KAKAO_신고 결과 받기
-   Set.count(i): i개수  얻기 0 or 1 


##  26 같은 숫자는 싫어
- unique 와 erase를 이용하여 중복원소를 제거
- 완전한 중복 제거는 정렬 후에 사용해야한다.
- unique(v.begin(),v.end())

        v={1,1,2,3,4,5,5,6} 일 때 
        중복되는 수는 뒤로 밀림 그러믈
        v={1,2,3,4,5,6,1,5} 된다.
        unique는 뒤에 있는 1을 가르킴, 가장 첫 중복숫자
        그 숫자부터 끝까지 전부 중복숫자이므로 end까지 erase로 제거
- v.erase(unique(v.begin(),v.end()),v.end());