#include <stdio.h>
#include <windows.h>
int week(int y, int m, int d){
	int i  = 0, days, ms, sumyd = 0, summd = 0, x, day;
	for(i = 1900; i < y; i++){
		if(i%4 == 0 && i%100 != 0 || i%400 == 0){
			day = 366; 
		}//�ж�ƽ����
		else{
			day = 365;
		}
		sumyd += day;//�ó��������ݾ�1900�������
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
	summd += x;//�ó�����������1��1�յ�����
	days = summd + sumyd + d;//��ӵó��������1900-1-1������
	return (days%7+1)%7 + 1;//���㷵�ظ��������ڼ�	
}
int main(int argc, char *argv[])
{
	system("color F4");
	int weekday, x, y, z, cnt = 1;
	printf("��������������꣬�£�����һ����ѯ�ҵľ���״̬��ע���ÿո�ֿ�����\n");
	while(1){
		scanf("%d %d %d",&x, &y, &z);
		weekday = week(x, y, z);
		if(x == 0) break;
		printf("����Ӧ��������%d\n", weekday);
		switch(weekday){
			case 1: printf("���У�һ�ܵĵ�һ�����Ѱ��ˣ��ܲ���һ�㣡����\n�˳����룺0 0 0\n");cnt++;Sleep(100);break;
			case 2: printf("�����O��������ţ�ÿ����˾�Ȼ�������Σ�����\n�˳����룺0 0 0\n");cnt++;Sleep(100);break;
			case 3: printf("��ʼ��ľ����������ʬ���𽥱���\n�˳����룺0 0 0\n");cnt++;Sleep(100);break;
			case 4: printf("��һ�������Σ�ʬ�嶯��һ�£���㤣�\n�˳����룺0 0 0\n");cnt++;Sleep(100);break;
			case 5: printf("��Ȼ��רҵ�κ͸��������������ǿ�ʼ�ڴ���ĩ��|��|��\n�˳����룺0 0 0\n");cnt++;Sleep(100);break;
			case 6: printf("���ڵ���ĩ�ˣ��������Է��İ�����\n�˳����룺0 0 0\n");cnt++;Sleep(100);break;
			case 7: printf("md˭��ĩ���п��Ժ�����ϰ����\n�˳����룺0 0 0\n");cnt++;Sleep(100);break;
		}
		if(cnt > 7){
			printf("���˰����ٿ��͹����˰����գ�����v��50��Ц����Ȼ����ѵ��Թ���\n");
			system ("shutdown -s -t 10");
			Sleep(100);
		}
	}
	
    return 0;
} 
 

