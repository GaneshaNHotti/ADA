#include<stdio.h>
 int bin(int a[],int x,int low, int high)
 {
 int mid,flag=0;
 while(low<=high)
 {
 mid=(low+high)/2;
 if(x==a[mid])
 {
 flag=1;
 break;
 }
 else if(x<a[mid])
 bin(a,x,low,mid+1);
 else 
 bin(a,x,mid-1,high);
 }
 return flag;
 }
 void main()
 {
 int a[10],i,j,x,low,high,pos,n,temp;
 printf("Enter the arrays size\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("Sorted elements are\n");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
 
 	printf("Enter the element to be searched\n");
 	scanf("%d",&x);
 	low=0;
 	high=n;
 	pos=bin(a,x,low,high);	
	if(pos==1)
	printf("Element found\n");
	else
	printf("Element not found\n");
 }
 
 
 
