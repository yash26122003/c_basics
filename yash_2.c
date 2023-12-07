#include<stdio.h>
#include<conio.h>
int main()
{
	int mat[3][3];
	int j,i ;
	for(j=0;j<3;j++){
		for(i=0;i<3;i++){
			scanf("%d",&mat[j][i]);
		}
	}
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(mat[i][j]!=0)
			{
			
			printf("%d %d %d\n",i,j,mat[i][j]);
		}
		}
	}
	return 0;
}
