#include<stdio.h>
#include<windows.h>
#include<stdlib.h> 
#include<time.h>
int main(){
	system("color F4");
	srand((int)time(NULL));
	int a = rand()%100;
	int m, n = 10;
	printf("���Ǹ���������Ϸ����˵��ǰͷ���㹲����λ��ᣬ�¶���û�������´����гͷ���������ɣ�doge\n");
	for(int cnt = 0; cnt <= 5; cnt++){
		printf("���������֣�"); 
		scanf("%d",&m);
		if(m < a) printf("С�ˣ���������ֻ��%d�λ����ˣ���ϧ��С�ӣ�\n",4 - cnt);
		if(m > a) printf("���ˣ���������ֻ��%d�λ����ˣ���ϧ��С�ӣ�\n",4 - cnt);
		if(m == a) {
		    printf("��С��������ã��ɶ��ˣ�");
			return 0;
		}
		if(cnt == 4){
			printf("û���Ῡ������������������%d\n����ȥ�ɣ�����������������\n",a); 
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
