#include<stdio.h>
struct Student
{
	// �����ṹ��
    char num[5];
	char name[10];
	float score1;
    float score2;
    float score3;
    float score4;
};

int main()
{
	struct Student s[3];
    int i, max, ans = 0;
    for(i = 0; i < 3; i++){
    	scanf("%s",&s[i].num);
    	scanf("%s",&s[i].name);
    	scanf("%f",&s[i].score1);
        scanf("%f",&s[i].score2);
        scanf("%f",&s[i].score3);
        s[i].score4 = (s[i].score1 + s[i].score2 + s[i].score3) / 3;
    }
    float aver = (s[0].score4 + s[1].score4 + s[2].score4) / 3;
    max = s[0].score4;
    if(s[1].score4 > max){
    	max = s[1].score4;
        ans = 1;
    }
    else if(s[2].score4 > max){
    	max = s[2].score4;
        ans = 2;
    }
	// ͨ��ָ����ʽṹ���Ա
    struct Student* p = &s[ans];
    printf("ƽ���ɼ�Ϊ:%.2f\n���ѧ���ɼ�Ϊ:\n",aver);
	printf("ѧ��:%s\n����:%s\n�ɼ�:%.2f, %.2f, %.2f\n",p->num, p->name, p->score1, p->score2, p->score3);
	return 0;
}
