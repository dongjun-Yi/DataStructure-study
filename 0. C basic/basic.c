//자료형(정수, 실수, 문자형..)
//정수 : short, int, long
//변수의 영역 - 지역,전역
//변수의 수명
// 지역변수 - 함수내부에서 할당되어 함수종료 시 반환
//전역변수 - 컴파일러 시에 할당되고 프로그램 종료 시 반환
//static 변수(정적 변수) - 지역적, 전역적, 컴파일시 할당

#include <stdio.h>
int a = 1;

void f() {
	int i = 10;
	//static은 함수내부에서 선언 되었지만 컴파일시 메모리를 할당받음
	static int s = 0;
	printf("%d, %d, %d\n", ++a, ++i, ++s);
}

void main() {
	int x = 100;
	printf("%d, %d \n", ++a, ++x);
	f();
}