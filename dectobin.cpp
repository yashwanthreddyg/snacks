#include<stdio.h>
#include<malloc.h>
int reverse(int num)
{
	int *a =(int*)malloc(100*sizeof(int));
	int i,c,k=0,count=0;
	while(num!=0)
	{
		c = num%10;
		a[k] = c;
		k++;
		num=num/10;
		count=count+1;
	}
	    for(i=0;i<count;i++)
		printf("%d",a[i]);
}
int main()
{
	int num;
	printf("Enter Number\n");
	scanf("%d",&num);
	reverse(num);
}