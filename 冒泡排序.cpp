#include<stdio.h>

int main(){
	int a[30];
	printf("请输入成绩：(用空格分开)") ;
	for(int i = 0; i < 30; i++) scanf("%d",&a[i]);
	int num = a[0];
	
	//for(int i = 0; i < 30; i++) printf("%d ",a[i]);
	
	for(int i = 29; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(a[j] > a[j + 1]){
			num = a[j + 1];
			a[j + 1] = a[j];
			a[j] = num;
			}
		}
	}
	for(int i = 29; i >= 0; i--){
		
		int n = 30 - i, cnt = 1;
		if(a[i] == a[i + 1]){
			cnt++;
			printf("第%3d名：%3d分,有%d人同分\n", n - 1, a[i], cnt);
		}
		else if(a[i] != a[i + 1]) printf("第%3d名：%3d分\n", 30 - i, a[i]);
		//printf("%d \n",a[i]);
	} 
	return 0;
} 
