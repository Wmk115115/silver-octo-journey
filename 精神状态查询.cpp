#include <stdio.h>
#include <windows.h>
int week(int y, int m, int d){
	int i  = 0, days, ms, sumyd = 0, summd = 0, x, day;
	for(i = 1900; i < y; i++){
		if(i%4 == 0 && i%100 != 0 || i%400 == 0){
			day = 366; 
		}//判断平闰年
		else{
			day = 365;
		}
		sumyd += day;//得出输入的年份距1900年的天数
	}
	if(y%4 == 0 && y%100 != 0 || y%400 == 0){
			x = 29;
		}
		else{
			x = 28;
		}
	while(m){
		switch(m){
		case 1:ms = 31;break;
		case 3:ms = 31;break;
		case 4:ms = 30;break;
		case 5:ms = 31;break;
		case 6:ms = 30;break;
		case 7:ms = 31;break;
		case 8:ms = 31;break;
		case 9:ms = 30;break;
		case 10:ms = 31;break;
		case 11:ms = 30;break;
		case 12:ms = 31;break;
		}
		summd += ms;
		m--;		
	}
	summd += x;//得出输入该天距离1月1日的天数
	days = summd + sumyd + d;//相加得出该天距离1900-1-1的天数
	return (days%7+1)%7 + 1;//计算返回该天是星期几	
}
int main(int argc, char *argv[])
{
	system("color F4");
	int weekday, x, y, z, cnt = 1;
	printf("现在你可以输入年，月，日来一键查询我的精神状态（注意用空格分开）：\n");
	while(1){
		scanf("%d %d %d",&x, &y, &z);
		weekday = week(x, y, z);
		if(x == 0) break;
		printf("这天应该是星期%d\n", weekday);
		switch(weekday){
			case 1: printf("不行，一周的第一天最难蚌了，受不了一点！！！\n退出代码：0 0 0\n");cnt++;Sleep(100);break;
			case 2: printf("满课誒，你敢相信，每天早八居然还有满课！！！\n退出代码：0 0 0\n");cnt++;Sleep(100);break;
			case 3: printf("开始麻木。。。。。尸体逐渐冰凉\n退出代码：0 0 0\n");cnt++;Sleep(100);break;
			case 4: printf("有一节体育课，尸体动了一下（惊悚）\n退出代码：0 0 0\n");cnt++;Sleep(100);break;
			case 5: printf("虽然被专业课和高数课塞满，但是开始期待周末（|。|）\n退出代码：0 0 0\n");cnt++;Sleep(100);break;
			case 6: printf("终于到周末了！！！可以放心摆烂了\n退出代码：0 0 0\n");cnt++;Sleep(100);break;
			case 7: printf("md谁周末还有考试和晚自习啊。\n退出代码：0 0 0\n");cnt++;Sleep(100);break;
		}
		if(cnt > 7){
			printf("够了啊，再看就过分了啊（恼）除非v我50（笑）不然给你把电脑关了\n");
			system ("shutdown -s -t 10");
			Sleep(100);
		}
	}
	
    return 0;
} 
 

