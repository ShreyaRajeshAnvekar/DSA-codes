#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int *a, int l, int h, int mid);

void mergeSort(int *a, int l, int r, FILE *f2, FILE *f3);
void bubbleSort(int n, int *a, FILE *f2, FILE *f3);
void selectionSort(int n, int *a, FILE *f2, FILE *f3);

void merge(int *a, int l, int r, int m)
{
    int b[1000];
    int i,j,k;
    i=l;
    j=m+1;
    k=l;
    while (i<=m&&j<=r)
    {
        if (a[i]>a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    while (i<=m)
    {
        b[k]=a[i];
        i++;
        k++;
    }
    while (j<=r)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    for (int c=l;c<=r;c++)
    {
        a[c]=b[c];
    }
}

void mergeSort(int *a,int l,int r,FILE *f2,FILE *f3)
{

    if (l<r)
    {
        int m=(l + r)/2;
        mergeSort(a,l,m,f2,f3);
        mergeSort(a,m+1,r,f2,f3);
        merge(a,l,r,m);
    }

}

void bubbleSort(int n, int *a, FILE *f2, FILE *f3)
{
    int i,j,k;
    clock_t t1, t2;
    t1 = clock();
    for (i=0;i<n-1;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (a[j]<a[j+1])
            {
                k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;
            }
        }
    }
    t2=clock();
    printf("\nBubble Output\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
		fprintf(f2,"%d ",a[i]);
	}
    double t=(double)(t2-t1)/CLOCKS_PER_SEC;
    fprintf(f3, "Bubble sort takes %f seconds\n", t);
}

void selectionSort(int n, int *a, FILE *f2, FILE *f3)
{
    int i,j,k;
    clock_t t1, t2;
    t1 = clock();
    for (i=0;i<n-1;i++)
    {
        int min = i;
        for (j=i+1;j<n;j++)
        {
            if (a[j]<a[min])
            {
                min=j;
            }
        }
        k=a[i];
        a[i]=a[min];
        a[min]=k;
    }
    t2=clock();
    printf("\n Selection Output\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
		fprintf(f2,"%d ",a[i]);
	}

    double t=(double)(t2 - t1) / CLOCKS_PER_SEC;
    fprintf(f3, "Selection sort takes %f seconds\n", t);
}

int main()
{
    FILE *f1, *f2, *f3;
    f1=fopen("input.txt", "w");
    f2=fopen("output.txt", "w");
    f3=fopen("log.txt", "a+");
    clock_t t1, t2;
    int low, high, n;
    printf("Enter the range and total numbers to be generated: ");
    scanf("%d %d %d", &low, &high, &n);
    srand(time(0));
    for(int i=0;i<n;i++)
    {
        int num=(rand()%(high-low+1))+low;
        fprintf(f1,"%d\n",num);
    }
    fclose(f1);

    f1 = fopen("input.txt", "r");
    int a[1000];
    printf("\nRead from file:\n");
    for (int i = 0; i < n; i++)
    {
        fscanf(f1,"%d", &a[i]);
        printf("%d\n", a[i]);
    }
    fclose(f1);

    fprintf(f2,"Bubble sort\n");
    bubbleSort(n,a,f2,f3);
    fprintf(f2,"\n");
    fprintf(f2,"Selection sort\n");
    selectionSort(n,a,f2,f3);
    fprintf(f2,"\n");

    fprintf(f2,"Merge sort\n");
    t1=clock();
    mergeSort(a,0,n-1,f2,f3);
    t2 =clock();
    double t = (double)(t2 - t1) / CLOCKS_PER_SEC;
    fprintf(f3, "Merge sort takes %f seconds\n", t);

    printf("\nmerge output\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        fprintf(f2, "%d ", a[i]);
    }

    fclose(f2);
    fclose(f3);

    return 0;
}
