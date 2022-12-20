#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//스택의 응용분야 : 접시 X
//과제 : 미로 찾기 지나온 길을 찍어볼 것 
#define MAX_STACK_SIZE 100
//해당 인덱스 값
typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

//초기화
void init_stack(StackType* s) {
	s->top = -1;
}

//overflow check 함수
int is_full(StackType* s) {
	return s->top == MAX_STACK_SIZE - 1;
}

//undeflow check 함수
int is_empty(StackType* s) {
	return s->top == -1;
}

void push(StackType* s, element item) {
	//overflow check
	if (is_full(s))
		printf("스택 포화 에러\n");

	else 
		s->data[++(s->top)] = item;
		
}

element pop(StackType* s) {
	//underflow check
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

int check_Pal(StackType* s, char pal[]) {
	int cnt = 0;
	char p;
	int len = strlen(pal);
	for (int i = 0;i < len;i++) {
		push(s, pal[i]);
	}
	
	for (int i = 0;i < len / 2;i++) {
		p = pop(s);
		if (pal[i] != p)
			return 0;
	}
	return 1;

}

void main() {
	StackType s;
	init_stack(&s);
	char pal[20];
	printf("문자열을 입력하시오 : ");
	scanf("%s", pal);
	if (check_Pal(&s, pal))
		printf("회문입니다.\n");
	else
		printf("회문이아닙니다.\n");
}