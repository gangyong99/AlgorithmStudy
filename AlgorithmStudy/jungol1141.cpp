#include "selection.h"
#ifdef jungol1141
/*농부 시현이의 N(1≤N≤80,000)마리의 소들은 "bad hair day"를 맞이하였다. 
각 소들이 자신들의 촌스런 머리 모양을 부끄러워 하자, 시현이는 소들이 다른 소들의 머리 모양을 얼마나 알 수 있는지를 알고자 했다.
i번째 소들은 키가 hi(1≤hi≤1,000,000,000) 이며, 동쪽(오른쪽)을 바라보고 서있다. 
따라서, i번째 소는 자신의 앞 ( i+1, i+2,...)의 소들의 머리 모양만 볼 수 있으며, 앞에 자신의 키보다 작은 소들만 볼 수 있다.​
*/
#include <stdio.h>
long int stack[1000000];
long int stack_index = -1;
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
void input(int N, int arr[]) {
	for (int i = 0; i < N; i++) {
		scanf("%d ", arr+i);
	}
}
void print(int N, int arr[]) {
	printf("Printing....\n");
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	printf("\nPrint Completed !\n");
}
void print_stack() {
	for (int i = 0; i <= stack_index; i++) {
		printf("stack[%d] = %d\n",i, stack[i]);
	}
	printf("============\n");
}
long long calc(int N, int arr[]) {
	long long return_val = 0;
	for (int i = 0; i < N; i++) {
		//printf("N=%d\n", i);
		//printf("stack_index = %d\n",stack_index);
		//printf("STACK_INDEX-1 : stack[%d] = %d\n", stack_index - 1, stack[stack_index - 1]);
		//printf("STACK_INDEX   : stack[%d] = %d\n", stack_index, stack[stack_index]);
		//printf("INPUT arr[%d] = %d\n", i, arr[i]);
		// stack에 지금 마지막으로 있는 것보다 작으면 투입
		while ( stack_index > -1 && arr[i] >= stack[stack_index] ) {
			pop();
			//printf("pop\n");
			//print_stack();
		}
		return_val = return_val + (stack_index+1);
		push(arr[i]);
		//print_stack();
		//printf("======N=%d=======\n", i);
	}
	return return_val;
}
int main() {
	int N;
	int arr[80000];
	scanf("%d", &N);
	input(N, arr);
	//print(N, arr);
	printf("%ld\n",calc(N, arr));
}
#endif