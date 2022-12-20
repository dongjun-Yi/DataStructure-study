#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 5
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
	//push�� �� ���� �Ȱ�츦 üũ�ϱ� ���� ����
	if (!is_empty(&s))
		return 0;
	return 1;
}

void main() {
	const char* p = "{A((i+1)]=0;}";
	if (check_matching(p) == 1)
		printf("��ȣ �˻� ����!\n");
	else
		printf("��ȣ �˻� ����!\n");
}