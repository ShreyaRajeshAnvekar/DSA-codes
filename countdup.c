#include<stdio.h>

void check(int arr[])
{
    int i,j,k,key,count,copy[25],high=0,mode;
    for (i=0;i<25;i++)
    {
        key=arr[i];
        count=0;
        int isCounted = 0;
        for (j=0;j<i;j++)
        {
            if(key==arr[j])
            {
                isCounted=1;
                break;
            }
        }
        if (!isCounted)
        {
            for(j=i,k=0;j<25;j++,k++)
            {
                if(key==arr[j])
                {
                    count++;
                }

            }
            printf("%d occurs %d times\n",key,count);
     if (count > high)
            {
                high=count;
                mode=key;
            }
    }
    }
 printf("The number repeated the most is %d\n",mode);
}

int main()
{
    int arr[25], i;
    printf("Enter 25 numbers\n");
    for (i=0;i<25;i++)
    {
        scanf("%d",&arr[i]);
    }
    check(arr);
    return 0;
}
//1 4 5 7 8 9 0 3 2 5 7 1 2 3 5 6 8 9 0 3 2 1 6 8 3
