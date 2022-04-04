#include"selection.h"
#ifdef bubble_sort

#include<stdio.h>

int sort_list[100];

void input(int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d ", sort_list + i);
	}
}

void print(int n) {
	//printf("SORT_LIST = ");
	for (int i = 0; i < n; i++) {
		printf("%d ", sort_list[i]);
	}
	printf("\n");
}
bool comp(int arr[], int pre, int post) {
	if (arr[pre] <= arr[post]) {
		return 0;
	}
	else {// arr[pre] > arr[post]
		return 1;
	}
}

void swap(int arr[],int pre, int post) {
	int temp;
	temp = arr[pre];
	arr[pre] = arr[post];
	arr[post] = temp;
}

int main() {
	int N;
	bool swap_flag = 0;
	scanf("%d", &N);
	input(N);
	// if N = 3 : j = 2 1 À¸·Î µ¼.
	for (int j = N-1; j > 0; j--) {
		// N = 3, j = 2 : i = 0 1	/ (0<->1) (1<->2)
		// N = 3, j = 1 : i = 0		/ (0<->1)
		for (int i = 0; i < j; i++) {
			swap_flag = comp(sort_list, i, i + 1);
			if (swap_flag) swap(sort_list, i, i + 1);
		}
		print(N);
	}
}
#endif