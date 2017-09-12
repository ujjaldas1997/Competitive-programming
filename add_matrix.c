#include<stdio.h>
#include<pthread.h>
#include<error.h>
#include<stdlib.h>
#define r 2
#define c 3
struct mat{
	int (*a)[r][c];
	int (*b)[r][c];
	int (*d)[r][c];
	int m, n;
};
struct element{
	int a;
	int b;
	int d;
};
void* add_element(void* pelement){
	struct element* e1 = pelement;
	(*e1).d = (*e1).a + (*e1).b;
	pthread_exit(NULL);
}
void* add_row(void* pmat){
	struct mat *mat1 = pmat;
	int i = 0, m = mat1->m, n = mat1->n;
	for(i = 0; i < n; ++i){
		pthread_t add_e;
		struct element e1;
		e1.a = (*mat1->a)[m][i];
		e1.b = (*mat1->b)[m][i];
		e1.d = (*mat1->d)[m][i];
		if(pthread_create(&add_e, NULL, add_element, &e1) != 0){
			perror("Unable to create thread\n");
			exit(0);
		}
		pthread_join(add_e, NULL);
		(*mat1->d)[m][i] = e1.d;
		//(*(*mat1).d)[m][i] = (*(*mat1).a)[m][i] + (*(*mat1).b)[m][i];
	}
	pthread_exit(0);
}
int main()
{
	int a[r][c] = {1, 2, 3, 4, 5, 6};
	int b[r][c] = {1, 2, 3, 4, 5, 6};
	int d[r][c] = {0, 0, 0, 0, 0, 0};
	pthread_t add_mat[r];
	struct mat mat1;
	mat1.a = &a;
	mat1.b = &b;
	mat1.d = &d;
	int i = 0;
	for(i = 0; i < r; ++i){
		mat1.m = i;
		mat1.n = c;
		if(pthread_create(&add_mat[i], NULL, add_row, &mat1) != 0){
			perror("Unable to create thread\n");
			exit(1);
		}
		pthread_join(add_mat[i], NULL);
	}
	for(i = 0; i < r; ++i){
		int j = 0;
		for(j = 0; j < c; ++j)
			printf("%d ", d[i][j]);
		printf("\n");
	}
	pthread_exit(NULL);
}
