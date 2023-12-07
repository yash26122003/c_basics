#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int arr[10000];

void bubble(int arr[] , int s ){
	int i , j , temp , min;
	for( i=0 ; i<s-1 ; i++){
		
		min=arr[i];
		
		for( j=i+1 ; j<s ; j++){
			
			if(arr[j]<arr[min]){
				min=j;
			}
			
		}
		
		if(min!=i){
			temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}
	
	}
}

int main(){
	
	int i;
	for(i=0; i<10000; i++){
		arr[i]=rand()%10000;
	}
	clock_t t,j;
	t = clock();
	bubble(arr , 10000);
	j = clock();
	
	
	for(i=0 ; i<10000; i++){
		printf(" %d ", arr[i]);
	}
	
    double tm= (double)(j-t)*1000/CLOCKS_PER_SEC;
    printf("\n The program took %.3f mili seconds to execute", tm);
	return 0;
}
