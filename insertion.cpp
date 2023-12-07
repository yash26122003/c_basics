#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int arr[10000];

void insertion(int arr[] , int s ){
	int i , j , key;
	for( i=1 ; i<s ; i++){
		
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
}

int main(){
	
	int i;
	for(i=0; i<10000; i++){
		arr[i]=rand()%10000;
	}
	clock_t t,j;
	t = clock();
	insertion(arr , 10000);
	j = clock();
	
	
	for(i=0 ; i<10000; i++){
		printf(" %d ", arr[i]);
	}
	
    double tm= (double)(j-t)*1000/CLOCKS_PER_SEC;
    printf("\n The program took %.3f mili seconds to execute", tm);
	return 0;
}
