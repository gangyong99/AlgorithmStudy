
#include"selection.h"
#ifdef stack
/*<ó������>
�־��� ����� ������ 3�����̴�.
1. "i a"�� a��� ���� ���ÿ� �ִ´�.�̶�, a�� 10, 000 ������ �ڿ����̴�.
2. "o"�� ���ÿ��� �����͸� ����, �� �����͸� ����Ѵ�.���� ������ ���������, "empty"�� ����Ѵ�.
3. "c"�� ���ÿ� �׿��ִ� �������� ���� ����Ѵ�.*/

#include<stdio.h>
int stack[100];
int stack_index = -1;
char cmd;
void push(int input) {
	stack[++stack_index] = input;
}
int pop() {
	if (stack_index >= 0) {
		return stack[stack_index--];
	}
	else {
		return -1;
	}
}
void each_case() {
	int insert_val, pop_val;
	scanf("%c ",&cmd);
	//printf("cmd = %c \n", cmd);

	if (cmd == 'i') {
		scanf("%d\n",&insert_val);
		push(insert_val);
	}
	else if(cmd == 'o') {
		pop_val = pop();
		if (pop_val == -1) {
			printf("empty\n");
		}
		else {
			printf("%d\n", pop_val);
		}
	}
	else if (cmd == 'c') {
		printf("%d\n", stack_index + 1);
	}
}
int NCase() {
	int n;
	scanf("%d\n", &n);
	return n;
}
int main() {
	int num_case = NCase();
	//printf("num_case = %d\n", num_case);
	for (int i = 0; i < num_case; i++) {

		//printf("case = %d\n", i);
		each_case();
		
		//printf("Index = %d\n", stack_index);
		for (int j = 0; j < stack_index + 1; j++) {
			//printf("stack[%d]=%d\n", j, stack[j]);
		}
	}
}
#endif