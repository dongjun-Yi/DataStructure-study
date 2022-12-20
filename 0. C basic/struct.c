//구조체 - 서로 다른 자료형의 데이터들의 연속적 모임
//구조체와 포인터

#include <stdio.h>
//구조체 정의문 - 사용자 정의 데이터 타입
struct test {
	int a;
	double x;
};

void main() {
	//구조체 선언
	struct test no; //구조체변수
	struct test* per = &no;
	no.a = 10;
	no.x = 3.14;
	printf("%d, %f\n", no.a, no.x);
	printf("%d, %f\n", per->a, per->x);
}