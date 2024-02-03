#include<stdio.h>
#include<windows.h>
#include<stdlib.h> 
#include<time.h>
int main(){
	system("color F4");
	srand((int)time(NULL));
	int a = rand()%100;
	int m, n = 10;
	printf("这是个猜数的游戏，丑话说在前头，你共有五次机会，猜对了没奖励，猜错了有惩罚，看着玩吧（doge\n");
	for(int cnt = 0; cnt <= 5; cnt++){
		printf("请输入数字："); 
		scanf("%d",&m);
		if(m < a) printf("小了，笨蛋，你只有%d次机会了，珍惜吧小子！\n",4 - cnt);
		if(m > a) printf("大了，笨蛋，你只有%d次机会了，珍惜吧小子！\n",4 - cnt);
		if(m == a) {
		    printf("你小子运气真好，蒙对了！");
			return 0;
		}
		if(cnt == 4){
			printf("没机会咯，笨蛋！！！！答案是%d\n开机去吧！！！！哈哈哈哈哈\n",a); 
			system ("shutdown -s -t 10");
			;
			for(int i = n; i > 0; i--){
		    printf(" \n\n\n\n\n\n\n\n\n\n\n\n\n                                                           %d\a",i);
		    Sleep(1000);
		    system("cls");
	}
	return 0;
		} 
	}
	system ("pause");
	
	
	return 0;
}
