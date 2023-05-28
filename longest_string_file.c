#include<stdio.h>
#include<stdlib.h>

int count(char sen[100])
{
	int i,c=0;
	for(i=0;sen[i]!='\0';i++)
	{
		c++;
	}
	return c;
}


int main()
{
	FILE *f1,*f2;
	f1=fopen("line.txt","r");
	f2=fopen("ans.txt","a");
	char sen[100],show[100],*sp,c;
	int i,n,m,j,max=0;
	sp=show;

	while(!feof(f1))
	{
		fgets(sen,20,f1);
		m=count(sen);

		if(m>=max)
		{
			max=m;
			sp=sen;

		}

	}

		fputs(sp,f2);

		fclose(f1);
		fclose(f2);
	return 0;
}
