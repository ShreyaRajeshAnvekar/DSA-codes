#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void push(FILE *f1, FILE *f2, FILE *f3)
{
    int r;
    fscanf(f1, "%d", &r);
    printf("%d\n", r);
    fprintf(f2, "%d\n", r);
    fprintf(f3, "%d\n", r);

}

void display(FILE *f2)
{
    int r;
    fseek(f2,0,SEEK_END);
    fscanf(f2, "%d",&r);

        printf("%d\t", r);
}

void pop(FILE *f2, FILE *f4)
{
    int r;
    fseek(f2,0,SEEK_END);
    fscanf(f2, "%d", &r);
    {
        fprintf(f4, "%d\n", r);

}
}

int main()
{
    FILE *f1, *f2, *f3, *f4, *f5;
    clock_t t1, t2, t;
    f1 = fopen("input.txt", "w");

    int i, low, high, n, ch;
    printf("Enter the range and total numbers to be generated: ");
    scanf("%d %d %d", &low, &high, &n);
    srand(time(0));
    int *r = malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        r[i] = (rand() % (high - low + 1)) + low;
        fprintf(f1, "%d\n", r[i]);
    }
    fclose(f1);

    f1 = fopen("input.txt", "r");
    f2 = fopen("stack.txt", "a+");
    f3 = fopen("push.txt", "a+");
    f4 = fopen("pop.txt", "a+");
    f5 = fopen("operation.txt", "w");

    if (f1 == NULL || f2 == NULL || f3 == NULL || f4 == NULL || f5 == NULL)
    {
        printf("File doesn't exist or cannot be opened.\n");
        exit(1);
    }

    while (1)
    {
        printf("\nStack Menu\n");
        printf("1: Push 2: Pop 3: Display 4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            {push(f1, f2, f3);
            fprintf(f5, " push %d\n", r);}
            break;
        case 2:
            {pop(f2, f4);
            fprintf(f5, " pop %d\n", r);}
            break;
        case 3:
            display(f2);
            break;
        case 4:
            {fclose(f1);
            fclose(f2);
            fclose(f3);
            fclose(f4);
            fclose(f5);}
            free(r);
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;

}


