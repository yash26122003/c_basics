#include<stdio.h>
#include<conio.h>
int main()
{
	int mat[4][5];
	int j,i ;
	for(j=0;j<4;j++){
		for(i=0;i<5;i++){
			scanf("%d",&mat[j][i]);
		}
	}
	int x=0;
	int sp[3][5];
	for(j=0;j<4;j++){
		for(i=0;i<5;i++){
			if(mat[j][i]!=0){
				sp[x][0]=j;
				sp[x][1]=i;
				sp[x][2]=mat[j][i];
				x++;
				
			}
		}
	}
	for(j=0;j<5;j++){
		for(i=0;i<3;i++){
			printf("%d",sp[i][j]);
		}printf("\n");
	}
	return 0;
}
