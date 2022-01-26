#   Sort

1.  K번째수
    -   [vector.assign](https://modoocode.com/183): 벡터 자르기 및 , 특정 값으로 벡터 할당
    -   벡터에 새로운 내용을 집어 넣는다. 벡터 객체에 이전에 있었던 원소들은 모두 삭제하고, 인자로 받은 새로운 내용을 집어 넣는다.
    -   void assign(InputIterator first,    InputIterator last);
    - void assign(size_type n, const T& u);

2.  H-Index

-  [count_if(Iterater start,Iterator end,cmp)](https://hsdevelopment.tistory.com/338)
   -  cmp(bool 함수) 조건에 맞는 STL안의 내용물의 갯수를 리턴
-   [count(Iterater start,Iterator end,const n)](https://hsdevelopment.tistory.com/338)
    -   STL안의 내용물 중 n값과 일치하는 갯수 리턴