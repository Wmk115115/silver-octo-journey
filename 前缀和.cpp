#include<stdio.h>
int main(){
	int a[10], s[10];
	for(int i = 0; i < 10; i++) scanf("%d", &a[i]);
	
	s[0] = a[0];
	for(int i = 1; i < 10; i++) s[i] = s[i - 1] + a[i];
	
	for(int i = 0; i < 10; i++) printf("%d ",a[i]);
	printf("\n"); 
	for(int i = 0; i < 10; i++) printf("%d ",s[i]);
	return 0;
}
