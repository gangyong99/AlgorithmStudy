#include"selection.h"
#ifdef jungol1328_timeover
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
			int pop_start = -1;
			for (int j = 0; j <= stack[0].stack_index; j++) {
				//현재 arr[j]값보다 stack[j]값이 작으면,
				//이 값부터 현재 최상단 stack까지는 pop 가능
				if (arr[i] > stack[1].stack[j]) {
					pop_start = j;
					printf("Pop_Start = %d\n", pop_start);
					printf("stack[0].stack_index = %d\n", stack[0].stack_index);
					break;
				}
			}
			//arr[j] > stack[j] 조건이 만족된 경우, POP
			if (pop_start != -1) {
				int pop_end = stack[0].stack_index;
				for (int j = pop_start; j <= pop_end; j++) {
					int id = stack[0].pop();
					printf("id = %d\n", id);

					stack[1].pop();
					solve[id] = i + 1;
				}
			}
			stack[0].push(i);
			stack[1].push(arr[i]);
		}
		print_stack();
		print_solve();
		printf("=========================================\n");
	}
}
int main() {
	scanf("%d", &N);
	input();
	calc();
}
#endif