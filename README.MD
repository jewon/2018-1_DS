# **2018-1학기 자료구조 실습**

## 학술대회 정보 관리 프로그램

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

### 20180418_5(8b23d5)
* MoreFeatures Application으로부터 분리
* Application의 기존 부가 기능 삭제

### 20180418_6(0c2719) : Lab5 Assigment Submit
* 탐색시 마지막 노드를 빼고 탐색하지 않는 버그 해결
* 빈 리스트 탐색시 nullptr역참조 오류 해결
* DoublyIterater와 겹치는 LinkedListType내의 코드들 삭제
* Operator 오버로딩으로 필요없어진 emum 삭제(각 ItemType에서)
* 리스트를 내림차순 > 오름차순으로 변경

### 20180421 (eef313)
* PaperIndex 관련 파일 삭제

##MidTerm Branch
### 20180421_2
* `Base`클래스 추가 : 리스트 할당, 삭제 관리 및 리스트 포인터 색인
  * 아직 작성만 하고 main에 사용되지 않음
  * 리스트 포인터 노드의 리스트는 일종의 싱글링크드리스트: `s_LP`, `p_LP`가 첫 노드 가리킴
  * `LinkedListType<> * Add()` : 리스트 새로 할당하고 할당한 리스트의 포인터를 반환해줌
  * `Delete(LinkedListType<> * )`: 파라미터 포인터가 가리키는 리스트를 할당 해제

## MidTermProject
### Refectoring
* `Base`클래스에 모든 리스트들의 시작포인터, 길이를 저장할 수 있게 한다.
  * 리스트 포인터 노드타입: 리스트 포인터와 다음 리스트포인터노드의 포인터(...)가 저장되어 있다.
  * 리스트 포인터 노드들의 첫 노드와 노드들의 갯수를 저장해둔다(SessionList, PaperList)
* 상위 객체가 하위 객체 리스트를 포함하는 게 아닌 하위 객체 리스트의 포인터를 포함하도록 변경
  * 리스트를 동적 할당 - Delete는 해당 객체가 소멸될 때 `MakeEmpty`

### TO FIX
* `LinkedListType::MakeEmpty()` 하는 중 이미 delete한 노드 참조 에러 (null역참조)
  * 추정 원인: 상위 객체를 추가, 변경하는 함수에서 하위 객체 리스트는 포인터만 복사되는 구조
  * `InfoChange`클래스 단순화: 하위 객체 바꿀 때에는 해당 타입의 템플릿만 호출

### TO ADD
* 논문 전체 출력
* 논문 저자로 통합검색
* 논문 통합검색 출력시 출력용 리스트에 추가하는 것이 아닌 Node포인터를 배열에 담기
