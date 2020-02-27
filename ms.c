#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void mergesort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid = (low+high)/2;
		mergesort(a,low,mid);	
		mergesort(a,mid+1,high);
		combine(a,low,mid,high);
	}
}
void combine(int a[],int low,int mid,int high)
{
	int i,j,k,c[1000000];
	k = low;
	i = low;
	j = mid +1;
	
	while(i<=mid && j<=high)
	{
		if(a[i] <= a[j])
			c[k++] = a[i++];
		else
			c[k++] = a[j++];
	}
	while(i<= mid)
		c[k++] = a[i++];
	while(j<=high)
		c[k++] = a[j++];
	for(k=low;k<=high;k++)
		a[k] = c[k];
			
}
void main()
{
	int size,i;
	printf("Enter the Size of array\n");
	scanf("%d",&size);
	int arr[size];
	for(i=0;i<size;i++)
		arr[i] = rand()%100;
	clock_t start,end;
	double time;
	start = clock();
	mergesort(arr,0,size-1);
	end = clock();
	time = (double)(end-start)/CLOCKS_PER_SEC;
	printf("\nSorted array is\n");
	for(i=0;i<size;i++)	
		printf("%d\t",arr[i]);
	printf("\ntime taken : %f\n",time); 

}
