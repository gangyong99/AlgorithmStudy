
#include"selection.h"
#ifdef queue
/*
��ó�����ǡ�
1. �־����� ����� ������ 3�����̴�.
2. "i a"�� a��� ���� ť�� �ִ´�.�̶�, a�� 10, 000 ������ �ڿ����̴�.
3. "o"�� ť���� �����͸� ����, �� �����͸� ����Ѵ�.���� ť�� ���������, "empty"�� ����Ѵ�.
4. "c"�� ť�� �ִ� �������� ���� ����Ѵ�.*/
#include<stdio.h>
int q[100];
int q_s = -1;
int q_e = -1;
char cmd;

void push(int insert_val) {
	q[++q_e] = insert_val;
}
int pop() {
	if (q_s < q_e) return q[++q_s];
	else return -1;
}
void numprint() {
	printf("%d\n", q_e-q_s);
}
int NCase() {
	int n;
	scanf("%d\n", &n);
	return n;
}
void each_case() {
	int insert_val, pop_val;
	scanf("%c ", &cmd);
	if (cmd == 'i') {
		scanf("%d\n", &insert_val);
		push(insert_val);
	}
	else if (cmd == 'o') {
		pop_val = pop();
		if (pop_val == -1) {
			printf("empty\n");
		}
		else {
			printf("%d\n", pop_val);
		}
	}
	else if (cmd == 'c') {
		numprint();
	}
}
int main()
{
	int num_case = NCase();
	for (int i = 0; i < num_case; i++) {
		each_case();
	}
}

#endif