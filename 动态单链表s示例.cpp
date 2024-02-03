#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct Employee)
struct Employee{
	int num;
	float pay;
	struct Employee *next;
};
int n;
struct Employee *creat(){
	struct Employee *head;
	struct Employee *p1, *p2;
	n = 0;
	p1 = p2 = (struct Employee * ) malloc(LEN);
	scanf("%d %f",&p1 -> num, &p1 -> pay);
	head = NULL;
	while(p1 -> num != 0){
		n = n + 1;
		if(n == 1) head = p1;
		else p2 -> next = p1;
		p2 = p1;
		p1 = (struct Employee * ) malloc(LEN);
		scanf("%d %f",&p1 -> num, &p1 -> pay);
	}
	p2 -> next = NULL;
	return head;
}
void print(struct Employee *head){
	struct Employee *p;
	printf("The linked list:\n");
	p = head;
	if(head != NULL)
	do{
		printf("%d,%.2f\n",p -> num, p -> pay);
		p = p -> next;
	}while(p != NULL);
}

/*void search(struct Employee){
	struct Employee *p;
	p = head;
	
} */

int main(){
	struct Employee *head;
	head = creat();
	print(head);
	
	struct Employee *p1, *p2;
	p1 = head;
	if(head != NULL){
		do{
			p2 = p1 -> next;
			if(p2 -> pay == 100) p1 -> next = p2 -> next;
			p1 = p1 -> next;
		}while(p2 -> next != NULL);
		//if(head -> pay == 100) head = head -> next;
	}
	
	print(head);
	return 0;
}
