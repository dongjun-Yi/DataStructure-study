//�迭 - ������ ������ Ÿ���� �������� ����
//������ - �ּ�
//�迭�� ������ - �迭�� �̸��� �� �迭�� ���� �ּ�
#include <stdio.h>

int main() {
	int i;
	int* p = &i;
	int ar[5] = { 10,20,30,0,0 };//�ʱ�ȭ, ����+�Ҵ�
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
	//q=q+1;, ar=ar+1�� �Ұ��� ->�������� ���԰���, �迭�� ������ �ƴ� ���� ������ ����̱� ������ ������ �Ұ��� 
	//ex) 1=1+1 -> �Ұ���!
	q++;//ar++; �Ұ���

	//%u�� unsigned, %p�� 16����
	printf("%3d, %p\n", i, p);
	return 0;
}