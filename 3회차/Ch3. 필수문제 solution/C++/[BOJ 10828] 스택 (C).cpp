#include<stdio.h>
#include<string.h>

int stack[10101];
int main(void) {
	int n; scanf("%d", &n);
	int top = -1;
	for (int i = 1; i <= n; i++) {
		char s[10]; scanf("%s", s);
		if (strcmp(s, "push") == 0) {
			int x; scanf("%d", &x);
			stack[++top] = x;
		}
		else if (strcmp(s, "pop") == 0) {
			if (top == -1) printf("-1\n");
			else {
				printf("%d\n", stack[top--]);
			}
		}
		else if (strcmp(s, "size") == 0) {
			printf("%d\n", top + 1);
		}
		else if (strcmp(s, "empty") == 0) {
			if (top == -1) printf("1\n");
			else printf("0\n");
		}
		else {
			if (top == -1) printf("-1\n");
			else printf("%d\n", stack[top]);
		}
	}
}