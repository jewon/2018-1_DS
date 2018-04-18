# **2018-1학기 자료구조 실습**

## Master Branch

### 20180418_1(a15dde)  
* 더블 링크드리스트로 LinkedListType 수정, DoublyIterater 사용

### 20180418_2(ddbd19)
* LinkedListType::Get(T item)이 Call by Ref로 받도록 수정(T &item)

### 20180418_3(9f5917)
* 주석 Doxygen에 맞춰서 수정
* 사용하지 않는 함수 일부 삭제
* DoublyIterator<T>의 GetCurrentNode()의 반환형을 NodeType<T>에서 T로 수정

### 20180418_4(8b23d5)
* 쓰지 않는 코드 및 주석 삭제

## *MoreFeatures Branch (Merged)*

### 20180418_4(8b23d5)
* MoreFeatures Application으로부터 분리
* Application의 기존 부가 기능 삭제

### 20180418_5
* 탐색시 마지막 노드를 빼고 탐색하지 않는 버그 해결
* 빈 리스트 탐색시 nullptr역참조 오류 해결
* DoublyIterater와 겹치는 LinkedListType내의 코드들 삭제
* Operator 오버로딩으로 필요없어진 emum 삭제(각 ItemType에서)
* 리스트를 내림차순 > 오름차순으로 변경

## TermProject Branch

## ISSUE
### TO FIX
* `LinkedListType::MakeEmpty()` 하는 중 이미 delete한 노드 참조 에러 (null역참조)
  * 원인을 못찾음
### TO ADD
* 논문 전체 출력
* 논문 저자로 통합검색
* 논문 통합검색 출력시 출력용 리스트에 추가하는 것이 아닌 Node포인터를 배열에 담기
