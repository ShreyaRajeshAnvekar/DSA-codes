#include<stdio.h>
#define R 3
#define C 3

void read(int (*arr)[C] )
{
	int i,j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			scanf("%d",*(arr+i)+j);
		}
	}
}

void display(int (*arr)[C] )
{
	int i,j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			printf("%d  ",*(*(arr+i)+j));
		}
		printf("\n");
	}
}

void mul(int (*a)[C],int (*b)[C])
{
	int sum[3][3];
	int i,j,k;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
		    sum[i][j]=0;
			for(k=0;k<R;k++)
		{
				//(sum+i)+j=(*(sum+i)+j)+((*(a+i)+k) * (*(b+k)+j)));
			sum[i][j]=sum[i][j]+((a[i][k])*(b[k][j]));
		}
		}
	}
	printf("Answer\n");
	display(sum);
}

int main()
{
	int a[R][C],b[R][C];
	printf("Enter the elements of 1st matrix\n");
	read(a);
	printf("Enter the elements of 1st matrix\n");
	read(b);
	printf("1st matrix\n");
	display(a);
	printf("\n");
	printf("2nd matrix\n");
	display(b);
	mul(a,b);
	return 0;
}
