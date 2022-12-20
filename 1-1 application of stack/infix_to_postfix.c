#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10
//�ش� �ε��� ��
typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

//�ʱ�ȭ
void init_stack(StackType* s) {
	s->top = -1;
}

//overflow check �Լ�
int is_full(StackType* s) {
	return s->top == MAX_STACK_SIZE - 1;
}

//undeflow check �Լ�
int is_empty(StackType* s) {
	return s->top == -1;
}

void push(StackType* s, element item) {
	//overflow check
	if (is_full(s))
		printf("���� ��ȭ ����\n");

	else
		s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	//underflow check
	if (is_empty(s)) {
		printf("���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

int peek(StackType* s) {
	return s->data[s->top];
}

int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

void infix_to_postfix(char c[]) {
	char ch, top_op;
	int len = strlen(c);
	StackType s;
	init_stack(&s);

	for (int i = 0;i < len;i++) {
		ch = c[i];
		switch (ch) {
		case '+': case '-': case '*': case '/':
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
				printf("%c", pop(&s));
			}
			push(&s, ch);
			break;
		case '(':
			push(&s, ch);
			break;
		case')':
			top_op = pop(&s);
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default:
			printf("%c", ch);
			break;
		}
	}
	while (!is_empty(&s))
		printf("%c", pop(&s));
}

void main() {
	char* s = "(2+3)*4+9";
	printf("����ǥ��� %s \n", s);
	printf("����ǥ��� ");
	infix_to_postfix(s);
	printf("\n");
}