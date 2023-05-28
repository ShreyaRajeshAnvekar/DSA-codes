#include<stdio.h>
#define r 5
#define c 5

int main()
{
    int arr[r][c],o,i,j,status;
    printf("Enter order of matrix\n");
    scanf("%d",&o);
    printf("Enter elements\n");
    for(i=0;i<o;i++)
    {
        for(j=0;j<o;j++)
            scanf("%d",&arr[i][j]);
    }
    for(i=0;i<o;i++)
    {
        for(j=0;j<o;j++)
           {
                printf("%d ",arr[i][j]);
           }printf("\n");
    }
    for(i=0;i<o;i++)
    {
        for(j=0;j<o;j++)
        {
            if(arr[i][j]==arr[j][i])
                status=0;
            if(arr[i][j]!=arr[j][i])
                status=1;
        }
        if(status==1)
        {
            printf("Non-symmetric\n");
            break;
        }
    }if(status==0)
        printf("Symmetric\n");
    return 0;
    //1 4 5 4 2 6 5 6 3
    //1 5 6 7 5 2 10 8 6 10 3 9 7 8 9 4
}

