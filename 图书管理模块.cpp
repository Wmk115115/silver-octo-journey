#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
//--------------------------------------------------------------------------------------
struct BOOK *list = NULL;
struct Bookinf{
	char name[20];
	int num;
};
struct BOOK{
	struct Bookinf data;
	struct BOOK *next;
};
struct BOOK *createHead(){//head
	struct BOOK *headNode = (struct BOOK*)malloc(sizeof(struct BOOK));
	headNode -> next = NULL;
	return headNode;
};
struct BOOK *createNode(struct Bookinf data){//node
	struct BOOK *newNode = (struct BOOK*)malloc(sizeof(struct BOOK));
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
}
struct BOOK *Search(struct BOOK *headNode,char *bookname){
	struct BOOK *posNode = headNode -> next;
	while(posNode != NULL && strcmp(posNode -> data.name,bookname)){
		posNode = posNode -> next;
	}
	return posNode;
}
void printlist(struct BOOK *headNode){//print
	struct BOOK *pMove = headNode -> next;
	printf("Name:\tNum:\t\n");
	while(pMove){
		printf("%s\t%d\t\n",pMove -> data.name,pMove -> data.num);
		pMove = pMove -> next;
	}
}
void sort(struct BOOK *headNode){
	for(struct BOOK *p = headNode -> next; p != NULL; p = p -> next){
		for(struct BOOK *q = headNode -> next; q -> next != NULL; q = q -> next){
			if(strcmp(q -> data.name,q -> next -> data.name) > 0){
				struct Bookinf tempdata = q -> data;
				q -> data = q -> next -> data;
				q -> next -> data = tempdata;
			}
		}
	}
	printlist(list);
}
void insertNode(struct BOOK *headNode,struct Bookinf data){
	struct BOOK *newNode = createNode(data);
	newNode -> next = headNode -> next;
	headNode -> next = newNode;
}
void Delete(struct BOOK *headNode,char *bookname){
	struct BOOK *posLeftNode = headNode;
	struct BOOK *posNode = headNode -> next;
	while(posNode != NULL && strcmp(posNode ->data.name,bookname)){
		posLeftNode = posNode;
		posNode = posLeftNode -> next;
	}
	if(posNode == NULL) return ;
	else {
		printf("Success!\n");
		posLeftNode -> next = posNode -> next;
		free(posNode);
		posNode = NULL;
	}
}
//--------------------------------------------------------------------------------------
void save(const char *filename,struct BOOK *headNode){
	FILE *fp = fopen("D:\\desktop\\Code-dev\\wenjian\\BookInformation.txt","w");
	struct BOOK *pMove = headNode -> next;
	while(pMove != NULL){
		fprintf(fp,"%s\t%d\n",pMove -> data.name,pMove -> data.num);
		pMove = pMove -> next;
	}
	fclose(fp);
}
void read(const char *filename,struct BOOK *headNode){
	FILE *fp = fopen("D:\\desktop\\Code-dev\\wenjian\\BookInformation.txt","r");
	if(fp == NULL){
		fp = fopen("D:\\desktop\\Code-dev\\wenjian\\BookInformation.txt","w+");
	}
	struct Bookinf tempdata;
	while(fscanf(fp,"%s\t%d\n",tempdata.name,tempdata.num) != EOF){
		insertNode(list,tempdata);
	}
	fclose(fp);
}
//--------------------------------------------------------------------------------------
void menu(){
	printf("                                                         Index\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("                                                       0. EXIT\n");
	printf("                                                       1. ADD\n");
	printf("                                                       2. ALL\n");
	printf("                                                       3.BORROW\n");
	printf("                                                       4.RETURN\n");
	printf("                                                       5. SORT\n");
	printf("                                                       6.DELETE\n");
	printf("                                                       7.SEARCH\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
}
//--------------------------------------------------------------------------------------
void reaction(){
	int key = 0;
	struct Bookinf tempBook; 
	struct BOOK *res = NULL;
	printf("Please choose number:");
	scanf("%d",&key);
	switch(key){
		case 0:
		printf("                                                       Exit success!\n");
		system("pause");
		exit (0);
		break;
		
		case 1:
		printf("                                                        ADD\n");
		printf("Please input book name and amount:\n");
		scanf("%s %d",tempBook.name,&tempBook.num);
		insertNode(list,tempBook);
		save("bookinf.txt",list);
		break;
		
		case 2:
		printf("                                                        ALL:\n");
		printlist(list);
		break;
		
		case 3:
		printf("                                                       BORROW:\n");
		printf("Please input the name:");
		scanf("%s",tempBook.name);
		res = Search(list,tempBook.name);
		if(res == NULL) printf("No\n");
		else {
			if(res -> data.num > 0){
				res -> data.num--;
				printf("Success!\n");
			}
		}
		save("bookinf.txt",list);
		break;
		
		case 4:
		printf("                                                       RETURN:\n");
		printf("Please input the name:");
		scanf("%s",tempBook.name);
		res = Search(list,tempBook.name);
		if(res == NULL) printf("Book Illegal!\n");
		else {
			res -> data.num++;
			printf("Success!\n");
		}
		save("bookinf.txt",list);
		break;
		
		case 5:
		printf("                                                        SORT:\n");
		sort(list);
		save("bookinf.txt",list);break;
		break;
		
		case 6:
		printf("                                                       DELETE:\n");
		printf("Please input the name:");
		scanf("%s",tempBook.name);
		Delete(list,tempBook.name);
		save("bookinf.txt",list);break;
		break;
		
		case 7:
		printf("                                                       SEARCH:\n");
		printf("Please input the name:");
		scanf("%s",tempBook.name);
		res = Search(list,tempBook.name);
		if(res == NULL) printf("No\n");
		else printf("%s",res -> data.name);
		break;
		
		defaut:printf("Error!");break;
	}
}
//--------------------------------------------------------------------------------------
int main(){
	system("color EA");
	list = createHead();
	read("bookinf.txt",list);
	while(1){
		menu();
		reaction();
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}
//--------------------------------------------------------------------------------------
