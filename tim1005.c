#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void positiveness(int *a) {
	if (*a < 0) *a *= -1;
}

int main() {
	size_t *n = (size_t*)malloc(sizeof(size_t)); scanf("%zu", n);
	int *list = (int*)calloc(*n, sizeof(int));
	int i, sum = 0; for (i = 0; i < *n; i++) {
		scanf("%d", (list+i));
		sum += *(list+i);
	}

	//bitmask starts down
	int ret = 10000000;
	for (i = 0; i < (1<< *n); i++) {
		int group_one = 0, j;
		for (j = 0; j < *n; j++)
			if (i&(1<<j)) 
				group_one += *(list+j);
		int group_two = sum-group_one;
		int diff = group_two-group_one; positiveness(&diff);
		ret = ret<diff?ret:diff;
	}
	printf("%d\n", ret);
return 0;
}
