#include <stdio.h>
#define MAX_STACK_SIZE 10
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

int eval(char *c) {
	int op1, op2, value;
	char ch;
	StackType s;
	init_stack(&s);

	int len = strlen(c);

	for (int i = 0;i < len;i++) {
		ch = c[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0';
			push(&s, value);
		}
		else {
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) {
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}

void main() {
	int result;
	printf("후위표기식은 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("결과값은 %d\n", result);
}