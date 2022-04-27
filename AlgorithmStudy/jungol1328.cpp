#include"selection.h"
// Stack 문제
#ifdef jungol1328
#include<stdio.h>
int N;
int arr[100000];
int solve[100000];
struct stack_ {
	int stack_index = -1;
	long int stack[100000];

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
};
typedef struct stack_ Stack;
Stack stack[2];
void input() {
	for (int i = 0; i < N; i++) {
		scanf("%d ", arr + i);
	}
}
void print_stack() {
	for (int i = 0; i <= stack[0].stack_index; i++) {
		printf("stack[0].stack[%d] = %d\n", i, stack[0].stack[i]);
	}
	for (int i = 0; i <= stack[1].stack_index; i++) {
		printf("stack[1].stack[%d] = %d\n", i, stack[1].stack[i]);
	}
}
void print_solve() {
	printf("Solve = ");
	for (int i = 0; i < N; i++) {
		printf("%d ", solve[i]);
	}
	printf("\n");
}

void print_ans() {
	for (int i = 0; i < N; i++) {
		printf("%d\n", solve[i]);
	}
}
// stack[0] : index / stack[1] : data
void calc() {
	for (int i = 0; i < N; i++) {
		// Stack이 비었다.
		if (stack[0].stack_index == -1 &&
			stack[1].stack_index == -1) {
			stack[0].push(i);
			stack[1].push(arr[i]);
		}
		// Stack이 비지 않았다.
		else {
			while (1) {
				if (arr[i]<=stack[1].stack[stack[1].stack_index] ||
					stack[1].stack_index == -1) {
					break;
				}
				int id = stack[0].pop();
				stack[1].pop();
				solve[id] = i + 1;
			}
			stack[0].push(i);
			stack[1].push(arr[i]);
		}
		//print_stack();
		//print_solve();
		//printf("=========================================\n");
	}
}
int main() {
	scanf("%d", &N);
	input();
	calc();
	print_ans();
}
#endif