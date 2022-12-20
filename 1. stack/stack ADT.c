#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5
//�ش� �ε��� ��
typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

//�ʱ�ȭ
void init_stack(StackType *s) {
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

element pop(StackType *s) {
	//underflow check
	if (is_empty(s)) {
		printf("���� ���� ����\n");
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