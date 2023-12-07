#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>



int main(){
	
	int i;
	for(i=0; i<1000; i++){
		arr[i]=rand()%10000;
	}
	time_t t,j;
	t = time(NULL);
	quick(arr , 0 , 999);
	j = time(NULL);
	
	
	for(i=0 ; i<1000; i++){
		printf(" %d ", arr[i]);
	}
	
    double time_taken = ((double)difftime(j,t))/CLOCKS_PER_SEC; 
    printf("\n The program took %f seconds to execute", time_taken);
	return 0;
}
