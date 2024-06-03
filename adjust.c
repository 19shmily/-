#include<stdio.h>

#define sub 2

int* judg_max(int* a, int* b)
{
	return *a > *b ? a : b;
}
int* judg_min(int* a, int* b)
{
	return *a < *b ? a : b;
}

void adjust(int* x1, int* y1, int* x2, int* y2, int* x3, int* y3, int* x4, int* y4)
{
	int* tmp = NULL;
	if (*x1 - *x2 <= 2 && *x1 - *x2 >= -2)
	{
		tmp = judg_max(x1, x4);
		*tmp -= sub;
		tmp = judg_min(x1, x4);
		*tmp += sub;
		tmp = judg_max(x2, x3);
		*tmp -= sub;
		tmp = judg_min(x2, x3);
		*tmp += sub;
		tmp = judg_max(y1, y2);
		*tmp -= sub;
		tmp = judg_min(y1, y2);
		*tmp += sub;
		tmp = judg_max(y3, y4);
		*tmp -= sub;
		tmp = judg_min(y3, y4);
		*tmp += sub;
	}
	else if (*x1 - *x4 <= 2 && *x1 - *x4 >= -2)
	{
		tmp = judg_max(x1, x2);
		*tmp -= sub;
		tmp = judg_min(x1, x2);
		*tmp += sub;
		tmp = judg_max(x3, x4);
		*tmp -= sub;
		tmp = judg_min(x3, x4);
		*tmp += sub;
		tmp = judg_max(y1, y4);
		*tmp -= sub;
		tmp = judg_min(y1, y4);
		*tmp += sub;
		tmp = judg_max(y2, y3);
		*tmp -= sub;
		tmp = judg_min(y2, y3);
		*tmp += sub;
	}
	else
	{
		//取x的最大
		tmp = judg_max(x1, x2);
		tmp = judg_max(tmp, x3);
		tmp = judg_max(tmp, x4);
		*tmp -= sub;
		//取x的最小
		tmp = judg_min(x1, x2);
		tmp = judg_min(tmp, x3);
		tmp = judg_min(tmp, x4);
		*tmp += sub;
		//取y的最大
		tmp = judg_max(y1, y2);
		tmp = judg_max(tmp, y3);
		tmp = judg_max(tmp, y4);
		*tmp -= sub;
		//取y的最小
		tmp = judg_min(y1, y2);
		tmp = judg_min(tmp, y3);
		tmp = judg_min(tmp, y4);
		*tmp += sub;
	}
	return;
}

//int main()
//{
//	int x1 = 3, x2 = 9, x3 = 9, x4 = 3;
//	int y1 = 3, y2 = 3, y3 = 6, y4 = 6;
//	adjust(&x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
//	printf("%d %d %d %d %d %d %d %d ", x1, y1, x2, y2, x3, y3, x4, y4);
//	return 0;
//}