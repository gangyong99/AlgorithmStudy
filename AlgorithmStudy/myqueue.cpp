
#include"selection.h"
#ifdef queue
/*
≪처리조건≫
1. 주어지는 명령은 다음의 3가지이다.
2. "i a"는 a라는 수를 큐에 넣는다.이때, a는 10, 000 이하의 자연수이다.
3. "o"는 큐에서 데이터를 빼고, 그 데이터를 출력한다.만약 큐가 비어있으면, "empty"를 출력한다.
4. "c"는 큐에 있는 데이터의 수를 출력한다.*/
#include<stdio.h>
int q[100];
int q_s = -1;
int q_e = -1;
char cmd;

void push(int insert_val) {
	q[++q_e] = insert_val;
}
int pop() {
	if (q_s < q_e) return q[++q_s];
	else return -1;
}
void numprint() {
	printf("%d\n", q_e-q_s);
}
int NCase() {
	int n;
	scanf("%d\n", &n);
	return n;
}
void each_case() {
	int insert_val, pop_val;
	scanf("%c ", &cmd);
	if (cmd == 'i') {
		scanf("%d\n", &insert_val);
		push(insert_val);
	}
	else if (cmd == 'o') {
		pop_val = pop();
		if (pop_val == -1) {
			printf("empty\n");
		}
		else {
			printf("%d\n", pop_val);
		}
	}
	else if (cmd == 'c') {
		numprint();
	}
}
int main()
{
	int num_case = NCase();
	for (int i = 0; i < num_case; i++) {
		each_case();
	}
}

#endif