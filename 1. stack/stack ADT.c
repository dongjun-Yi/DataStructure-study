#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5
//해당 인덱스 값
typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

//초기화
void init_stack(StackType *s) {
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

element pop(StackType *s) {
	//underflow check
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

void main() {
	StackType s;
	init_stack(&s);
	push(&s, 10);push(&s, 20);push(&s, 30);
	printf("%d\n", pop(&s)); //30
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
}