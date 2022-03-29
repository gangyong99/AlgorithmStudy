/*<처리조건>

주어진 명령은 다음의 3가지이다.
1. "i a"는 a라는 수를 스택에 넣는다.이때, a는 10, 000 이하의 자연수이다.
2. "o"는 스택에서 데이터를 빼고, 그 데이터를 출력한다.만약 스택이 비어있으면, "empty"를 출력한다.
3. "c"는 스택에 쌓여있는 데이터의 수를 출력한다.*/

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
	int insert_var, pop_var;
	scanf("%c ",&cmd);
	//printf("cmd = %c \n", cmd);

	if (cmd == 'i') {
		scanf("%d\n",&insert_var);
		push(insert_var);
	}
	else if(cmd == 'o') {
		pop_var = pop();
		if (pop_var == -1) {
			printf("empty\n");
		}
		else {
			printf("%d\n", pop_var);
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