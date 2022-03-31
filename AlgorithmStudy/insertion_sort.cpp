#include"selection.h"
#ifdef insertion_sort
/*��������(Insertion sort)�� �ڷ� �迭�� ��� ��Ҹ� �տ������� ���ʴ�� �̹� ���ĵ� �迭 �κа� ���Ͽ�, 

�ڽ��� ��ġ�� ã�� �����ϴ� ����̴�.*/
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

int comp(int arr[], int e) {
	for (int i = e-1; i >= 0; i--) {
		if (arr[i] < arr[e]) {
			return i;
		}
	}
	return -1;
}

void insert(int arr[], int inst_id, int e) {
	int temp;
	temp = arr[e];
	for (int i = e; i > inst_id + 1; i--) {
		arr[i] = arr[i - 1];
	}
	arr[inst_id + 1] = temp;
}

int main() {
	int N;
	int insert_id = 0;
	scanf("%d", &N);
	input(N);
	for (int i = 1; i < N; i++) {
		insert_id = comp(sort_list, i);
		insert(sort_list, insert_id, i);
		print(N);
	}
}

#endif