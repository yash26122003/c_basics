#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int arr[10000];

void bubble(int arr[] , int s ){
	int i , j , temp;
	for( i=0 ; i<s ; i++){
		
		int flag=0;
		
		for( j=0 ; j<s-1-i ; j++){
			
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag = 1;
			}
			
		}
		
		if(flag==0){
			break;
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
