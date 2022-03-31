#include"selection.h"
#ifdef selection_sort
/*
* http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=426&sca=2070
선택 정렬(selection sort)이란 내부정렬 알고리즘의 하나로 다음 순서대로 실행하여 정렬을 한다.

1. 주어진 수열 중에 최소값(같은 값이 여러 개 있는 경우 처음 값)을 찾는다.
2. 찾은 최소값을 맨 앞의 값과 자리를 바꾼다.
3. 맨 앞의 값을 뺀 나머지 수열을 같은 방법으로 전체 개수-1번 반복 실행한다.

n개의 주어진 수열을 위와 같은 방법으로 정렬한다.

수열이 주어지면 선택정렬의 과정을 한 단계씩 출력한다.​ */
#include<stdio.h>

int sort_list[100];

void input(int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d ", sort_list+i);
	}
}

void print(int n) {
	//printf("SORT_LIST = ");
	for (int i = 0; i < n; i++) {
		printf("%d ", sort_list[i]);
	}
	printf("\n");
}
int find_min(int arr[],int s, int e) {
	int min = 1000;
	int min_id = 0;
	for (int i = s; i < e; i++) {
		if (arr[i] < min) {
			min = arr[i];
			min_id = i;
		}
	}
	//printf("found min value = %d\n", arr[min_id]);
	return min_id;
}

void swap(int arr[],int a,int b) {
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int main() {
	int N;
	scanf("%d", &N);
	input(N);
	//print(N);
	for (int i = 0; i < N - 1; i++) {
		int min_id = find_min(sort_list, i, N);
		//printf("min_id = %d\n", min_id);
		swap(sort_list, i, min_id);
		print(N);
	}
	//printf("min_id = %d\n",find_min(sort_list, N));
	// test swap
	//swap(sort_list, 1, 2);
	//print(N);
}

#endif