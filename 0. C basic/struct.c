//����ü - ���� �ٸ� �ڷ����� �����͵��� ������ ����
//����ü�� ������

#include <stdio.h>
//����ü ���ǹ� - ����� ���� ������ Ÿ��
struct test {
	int a;
	double x;
};

void main() {
	//����ü ����
	struct test no; //����ü����
	struct test* per = &no;
	no.a = 10;
	no.x = 3.14;
	printf("%d, %f\n", no.a, no.x);
	printf("%d, %f\n", per->a, per->x);
}