#include<stdio.h>
int main(){
	int a[4][4], s[4][4];
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++) scanf("%d",&a[i][j]);
	}
	
	s[0][0] = a[0][0];
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(i == 0) s[i][j] = s[i][j - 1] + a[i][j];
			else if(j == 0) s[i][j] = s[i - 1][j] + a[i][j];
			else if(i != 0 && j != 0) s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}
	
	printf("\n");
	
	for(int i = 0; i < 4; i++){
		
		for(int j = 0; j < 4; j++){
			printf("%d ",s[i][j]);
		}
		
		printf("\n");
	}
	return 0;
}
