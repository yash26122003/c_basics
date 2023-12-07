#include<stdio.h>
#include<conio.h>
int main (){
	int x,n,i,j;
	printf("enter the no of elements in your array : ");
	scanf("%d",&x);
	int arr[x];
	for(n=0;n<x;n++){
		scanf("%d",&arr[n]);
	}
	printf("\n the array before sorting \n\n");
	for(n=0;n<x;n++){
		printf("%d\t",arr[n]);
	}
	printf("\n");
	for(i=0;i<x-1;i++){
		for(j=i+1;j<x;j++){
			if (arr[i]>arr[j]){
				int n=0;
				n=arr[i];
				arr[i]=arr[j];
				arr[j]=n;
			}
		}
	}
	printf("\n the array after sorting \n\n");
	for(n=0;n<x;n++){
		printf("%d\t",arr[n]);
	}
	return 0 ;
}
