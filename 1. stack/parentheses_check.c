#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 5
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

int check_matching(const char* in) {
	StackType s;
	init_stack(&s);
	int n = strlen(in);
	char ch, open_ch;

	for (int i = 0;i < n;i++) {
		ch = in[i];
		switch (ch) {
		case '(': case '[': case '{': 
			push(&s, ch); break;
		case ')': case ']': case '}':
			if (is_empty(&s)) return 0;
			else {
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '[' && ch != ']') ||
					(open_ch == '{' && ch != '}')) {
					return 0;
				}
				break;
			}
		}
	}
	//push가 더 많이 된경우를 체크하기 위한 구문
	if (!is_empty(&s))
		return 0;
	return 1;
}

void main() {
	const char* p = "{A((i+1)]=0;}";
	if (check_matching(p) == 1)
		printf("괄호 검사 성공!\n");
	else
		printf("괄호 검사 실패!\n");
}