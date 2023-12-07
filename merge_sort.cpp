#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int arr[100000];
void merge(int a[], int l , int m , int r){
	
	int i,j;
	
	int n1= m-l+1;
	int n2 = r-m;
	
	int L[n1];
	int R[n2];
	
	for(i=0 ; i<=n1;i++){
		L[i]=a[l+i];
	}
	for(i=0 ; i<=n2;i++){
		R[i]=a[m+1+i];
	}
	
	int k=l;
	i=0;
	j=0;
	
	while(i < n1 && j < n2){
		if(L[i]<R[j]){
			a[k]=L[i];
			k++;
			i++;
		}
		else{
			a[k]=R[j];
			k++;
			j++;
		}
		
	}
	while (i < n1) {
		a[k]=L[i];
		k++;
		i++;
	}
	while (j < n2) {
		a[k]=R[j];
		k++;
		j++;
	}
	
	
}
void divide(int a[], int l , int r){
	if(l<r){
		int m=l+ (r-l)/2;
		divide(a , l , m);
		divide(a , m+1 , r);
		merge(a , l , m, r);
	}
	
	
}

int main(){
	
	int i;
	for(i=0; i<100000; i++){
		arr[i]=rand()%1000000;
	}
	clock_t t,j;
	t = clock();
	divide(arr , 0 , 99999);
	j = clock();
	
	
	for(i=0 ; i<100000; i++){
		printf(" %d ", arr[i]);
	}
	
    double tm= (double)(j-t)*1000/CLOCKS_PER_SEC;
    printf("\n The program took %.3f mili seconds to execute", tm);
	return 0;
}
