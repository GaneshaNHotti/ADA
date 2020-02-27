#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void quicksort(int a[],int low, int high)
{
	int mid;
	if(low<high)
	{
		mid=partition(a,low,high);
		quicksort(a,low,mid-1);
		quicksort(a,mid+1,high);
	}
}

int partition(int a[],int low,int high)
{	
	int pivot,i,j,temp;
	pivot=a[low];
	i=low;
	j=high+1;
	while(i<=j)
	{
	do
	{
		i++;
	}while(pivot>a[i]);
	do
	{
		j--;
	}while(pivot<a[j]);
	if(i<j)
	{
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	}
	}
	temp=a[low];
	a[low]=a[j];
	a[j]=temp;
	return j;
}
    void main()
{
	int n,low,high,i;
	printf("Enter the Size of array\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		a[i] = rand()%100;
	clock_t start,end;
	double totaltime;
	low=0;
	high=n-1;
	start = clock();
	quicksort(a,low,high);
	end = clock();
	totaltime = (double)(end-start)/CLOCKS_PER_SEC;
	printf("\nSorted array is\n");
	for(i=0;i<n;i++)	
		printf("%d\t",a[i]);
	printf("\ntime taken : %f\n",totaltime); 

}
