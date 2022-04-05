#include"selection.h"
#ifdef jungol2858
#include<stdio.h>

int input(char bracket_arr[],int num_arr[]) {
	int N = 0;
	num_arr[0] = 1;
	while (scanf("%c", bracket_arr + N) != EOF) {
		if (N > 0) {
			if (bracket_arr[N] == '(') {
				num_arr[N] = num_arr[N - 1] + 1;
			}
			else if (bracket_arr[N] == ')') {
				num_arr[N] = num_arr[N - 1] - 1;
			}
		}
		N++;
	}
	return N;
}
int scan(int arr[],int N) {
	int num_pod = 0;
	int down_flag = 0;
	for (int i = 1; i < N; i++) {
		// pre < post : 증가 시,
		if (arr[i] > arr[i-1]) {
			down_flag = 0;
		}// pre > post : 감소 시,
		else if (arr[i] < arr[i-1]) {
			// 한번만 감소 시,
			if (down_flag == 0) {
				num_pod = num_pod + arr[i];
			}// 한번 이상 감소 시,
			else if (down_flag > 0) {
				num_pod = num_pod + 1;
			}
			down_flag++;
		}
	}
	return num_pod;
}
void print(char bracket_arr[], int num_arr[],int N) {
	for (int i = 0; i < N; i++) {
		printf("%c", bracket_arr[i]);
	}
	printf("\n");
	for (int i = 0; i < N; i++) {
		printf("%d", num_arr[i]);
	}
	printf("\n");
}
int main() {
	char bracket_arr[100000];
	int num_arr[100000];
	int N = 0;
	N = input(bracket_arr, num_arr);
	//printf("Num = %d\n", N);
	//print(bracket_arr, num_arr, N);
	printf("%d\n",scan(num_arr, N));
}

#endif