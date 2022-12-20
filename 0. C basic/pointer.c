//배열 - 동일한 데이터 타입의 연속적인 모임
//포인터 - 주소
//배열과 포인터 - 배열의 이름은 그 배열의 시작 주소
#include <stdio.h>

int main() {
	int i;
	int* p = &i;
	int ar[5] = { 10,20,30,0,0 };//초기화, 선언+할당
	int* q = ar; //ar == &ar[0]
	printf("%p, %p, %p\n", q, ar, &ar[0]);
	printf("%p, %p, %p\n", q + 1, ar + 1, &ar[1]);

	for (i = 0;i < 5;i++)
		printf("%p, %p, %p\n", q+i, ar+i, &ar[i]);

	printf("%d, %d\n", ar[0], ar[1]);
	printf("%d, %d\n", *q, *(q+1));

	for (i = 0;i < 5;i++)
		printf("%3d, %3d, %3d", ar[i], *(q+i), *(ar+i));
	printf("\n");
	//q=q+1;, ar=ar+1은 불가능 ->변수에는 대입가능, 배열은 변수가 아닌 값이 정해진 상수이기 때문에 대입이 불가능 
	//ex) 1=1+1 -> 불가능!
	q++;//ar++; 불가능

	//%u는 unsigned, %p는 16진수
	printf("%3d, %p\n", i, p);
	return 0;
}