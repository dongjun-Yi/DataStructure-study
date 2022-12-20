#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//������ ����о� : ���� X
//���� : �̷� ã�� ������ ���� �� �� 
#define MAX_STACK_SIZE 100
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
	printf("���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", pal);
	if (check_Pal(&s, pal))
		printf("ȸ���Դϴ�.\n");
	else
		printf("ȸ���̾ƴմϴ�.\n");
}