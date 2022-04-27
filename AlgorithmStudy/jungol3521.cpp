#include"selection.h"
// Greedy ¹®Á¦
#ifdef jungol3521
#include <stdio.h>
#define N_mass 5
// 1 2 4 8 16
int arr[N_mass];
int arr_mass[N_mass] = { 1,2,4,8,16 };
int solve[N_mass];
int goal_mass;
void input() {
	for (int i = 0; i < N_mass; i++) {
		scanf("%d ", arr+i);
	}
	scanf("%d",&goal_mass);
}
void print() {
	printf("======== Test Print =========\n");
	printf("mass_list = ");
	for (int i = 0; i < N_mass; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("Goal_mass = %d\n", goal_mass);
	printf("\n=============================\n");
}
int calc() {
	for (int i = N_mass-1; i >= 0; i--) {
		//arr[4] / arr[3] / ... / arr[0]
		// j : Ãß °¹¼ö
		for (int j = 1; j <= arr[i]; j++) {
			if (j*arr_mass[i] > goal_mass) {
				solve[i]=j-1;
				goal_mass = goal_mass - (j - 1) * arr_mass[i];
				break;
			}
			if (j == arr[i]) {
				solve[i] = arr[i];
				goal_mass = goal_mass - arr[i] * arr_mass[i];
			}
		}
	}
	return goal_mass;
}
int main() {
	input();
	//print();
	if (calc() > 0) {
		printf("impossible\n");
	}
	else {
		int sum = 0;
		for (int i = 0; i < N_mass; i++) {
			sum = sum + solve[i];
		}
		printf("%d\n", sum);
	}
}
#endif