#include<stdio.h>
int main(){
	int a[10] = {8,10,23,37,41,55,68,72,89,95};
	int n, sta, i, j, num;
	scanf("%d",&n);
	for(i = 9; i > 0; i--){
		for(j = 0; j < i; j++){
			if(a[j] > a[j+1]){
				num = a[j + 1];
				a[j + 1] = a[j];
				a[j] = num;
			}
		}
	}//√∞≈›≈≈–Ú …˝–Ú 
	
	
	if(n > a[5]){
		for(i = 6; i < 10; i++){
			if(n == a[i]){
				printf("sta=%3d\n",i+1);
				break;
			}
			else if(i == 9) printf("No such number!");
		}
		
	}
	else if(n == a[5]) printf("sta=  5");
	else{
		for(i = 4; i >= 0; i--){
			if(n == a[i]){
				printf("sta=%3d\n",i+1);
				break;
			}
			else if(i == 0) printf("No such number!\n");
		}
	}//’€∞Î≤È’“ 
	return 0;
}
