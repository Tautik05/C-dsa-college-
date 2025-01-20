#include<stdio.h>
void insertion(int arr[],int n)
{
	int i,j,temp;

	for(i=1;i<n;i++)
	{
		j=i;
		while(j>0 && arr[j-1]>arr[j])
		{
			temp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
			j--;
		}
	}
	printf("sorted elements:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
}

void main()
{
	int n,i,j;
	int arr[65];
	printf("enter the number of elements :");
	scanf("%d",&n);
	printf("enter %d integers\n",n);
	for(i=0;i<n;i++)
	{
		printf("a[%d]: ",i);
		scanf("%d",&arr[i]);
	}
	insertion(arr,n);
}