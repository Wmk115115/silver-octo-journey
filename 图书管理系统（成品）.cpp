#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
struct User *list_u = NULL;
struct BOOK *list_b = NULL;
//--------------------------------------------------------------------------------------
struct Bookinf{
	char name[20];
	int num;
};
struct BOOK{
	struct Bookinf data;
	struct BOOK *next;
};
struct BOOK *createHead_b(){
	struct BOOK *headNode = (struct BOOK*)malloc(sizeof(struct BOOK));
	headNode -> next = NULL;
	return headNode;
};
struct BOOK *createNode_b(struct Bookinf data){
	struct BOOK *newNode = (struct BOOK*)malloc(sizeof(struct BOOK));
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
}
struct BOOK *Search_b(struct BOOK *headNode,char *bookname){
	struct BOOK *posNode = headNode -> next;
	while(posNode != NULL && strcmp(posNode -> data.name,bookname)){
		posNode = posNode -> next;
	}
	return posNode;
}
void printlist_b(struct BOOK *headNode){
	struct BOOK *pMove = headNode -> next;
	printf("Name:\tNum:\t\n");
	while(pMove){
		printf("%s\t%d\t\n",pMove -> data.name,pMove -> data.num);
		pMove = pMove -> next;
	}
}
void sort_b(struct BOOK *headNode){
	for(struct BOOK *p = headNode -> next; p != NULL; p = p -> next){
		for(struct BOOK *q = headNode -> next; q -> next != NULL; q = q -> next){
			if(strcmp(q -> data.name,q -> next -> data.name) > 0){
				struct Bookinf tempdata = q -> data;
				q -> data = q -> next -> data;
				q -> next -> data = tempdata;
			}
		}
	}
	printlist_b(list_b);
}
void insertNode_b(struct BOOK *headNode,struct Bookinf data){
	struct BOOK *newNode = createNode_b(data);
	newNode -> next = headNode -> next;
	headNode -> next = newNode;
}
void Delete_b(struct BOOK *headNode,char *bookname){
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
void save_b(const char *filename,struct BOOK *headNode){
	FILE *fp = fopen("D:\\desktop\\Code-dev\\wenjian\\BookInformation_A.txt","w");
	struct BOOK *pMove = headNode -> next;
	while(pMove != NULL){
		fprintf(fp,"%s\t%d\n",pMove -> data.name,pMove -> data.num);
		pMove = pMove -> next;
	}
	fclose(fp);
}
void read_b(const char *filename,struct BOOK *headNode){
	FILE *fp = fopen("D:\\desktop\\Code-dev\\wenjian\\BookInformation_A.txt","r");
	if(fp == NULL){
		fp = fopen("D:\\desktop\\Code-dev\\wenjian\\BookInformation_A.txt","w+");
	}
	struct Bookinf tempdata;
	while(fscanf(fp,"%s\t%d\n",tempdata.name,tempdata.num) != EOF){
		insertNode_b(list_b,tempdata);
	}
	fclose(fp);
}
//--------------------------------------------------------------------------------------
void menu_b(){
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
void reaction_b(){
	int key = 0;
	struct Bookinf tempBook; 
	struct BOOK *res_b = NULL;
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
		insertNode_b(list_b,tempBook);
		save_b("bookinf.txt",list_b);
		break;
		
		case 2:
		printf("                                                        ALL:\n");
		printlist_b(list_b);
		break;
		
		case 3:
		printf("                                                       BORROW:\n");
		printf("Please input the name:");
		scanf("%s",tempBook.name);
		res_b = Search_b(list_b,tempBook.name);
		if(res_b == NULL) printf("No\n");
		else {
			if(res_b -> data.num > 0){
				res_b -> data.num--;
				printf("Success!\n");
			}
		}
		save_b("bookinf.txt",list_b);
		break;
		
		case 4:
		printf("                                                       RETURN:\n");
		printf("Please input the name:");
		scanf("%s",tempBook.name);
		res_b = Search_b(list_b,tempBook.name);
		if(res_b == NULL) printf("Book Illegal!\n");
		else {
			res_b -> data.num++;
			printf("Success!\n");
		}
		save_b("bookinf.txt",list_b);
		break;
		
		case 5:
		printf("                                                        SORT:\n");
		sort_b(list_b);
		save_b("bookinf.txt",list_b);break;
		break;
		
		case 6:
		printf("                                                       DELETE:\n");
		printf("Please input the name:");
		scanf("%s",tempBook.name);
		Delete_b(list_b,tempBook.name);
		save_b("bookinf.txt",list_b);
		break;
		
		case 7:
		printf("                                                       SEARCH:\n");
		printf("Please input the name:");
		scanf("%s",tempBook.name);
		res_b = Search_b(list_b,tempBook.name);
		if(res_b == NULL) printf("No\n");
		else printf("%s",res_b -> data.name);
		break;
		
		defaut:printf("Error!");break;
	}
}
//--------------------------------------------------------------------------------------
void index(){
	list_b = createHead_b();
	read_b("bookinf.txt",list_b);
	while(1){
		menu_b();
		reaction_b();
		system("pause");
		system("cls");
	}
	system("pause");
}
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
struct User_inf{
	char name[20];
	char password[20];
};
struct User{
	struct User_inf data;
	struct User *next;
};
//--------------------------------------------------------------------------------------
struct User *createHead_u(){
	struct User *headNode = (struct User*)malloc(sizeof(struct User));
	headNode -> next = NULL;
	return headNode;
};
struct User *createNode_u(struct User_inf data){
	struct User *newNode = (struct User*)malloc(sizeof(struct User));
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
}
void insertNode_u(struct User *headNode,struct User_inf data){
	struct User *newNode = createNode_u(data);
	newNode -> next = headNode -> next;
	headNode -> next = newNode;
}
struct User *Search_u(struct User *headNode,char *username){
	struct User *posNode = headNode -> next;
	while(posNode != NULL && strcmp(posNode -> data.name,username)){
		posNode = posNode -> next;
	}
	return posNode;
}
//--------------------------------------------------------------------------------------
void save_u(const char *filename,struct User *headNode){
	FILE *fp = fopen("D:\\desktop\\Code-dev\\wenjian\\UserInformation_A.txt","w");
	struct User *pMove = headNode -> next;
	while(pMove != NULL){
		fprintf(fp,"%s\t%s\n",pMove -> data.name,pMove -> data.password);
		pMove = pMove -> next;
	}
	fclose(fp);
}
void read_u(const char *filename,struct User *headNode){
	FILE *fp = fopen("D:\\desktop\\Code-dev\\wenjian\\UserInformation_A.txt","r");
	if(fp == NULL){
		fp = fopen("D:\\desktop\\Code-dev\\wenjian\\UserInformation_A.txt","w+");
	}
	struct User_inf tempdata;
	while(fscanf(fp,"%s\t%s\n",tempdata.name,tempdata.password) != EOF){
		insertNode_u(list_u,tempdata);
	}
	fclose(fp);
}
//--------------------------------------------------------------------------------------
void menu_u(){
	printf("                                                           SYSTEM\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("                                                         0.EXIT\n");
	printf("                                                         1.Sign up\n");
	printf("                                                         2.Log in\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
}
//--------------------------------------------------------------------------------------
void reaction_u(){
	int key;
	char password[20];
	struct User_inf tempUser; 
	struct User *res_u = NULL;
	printf("Please choose number:");
	scanf("%d",&key);
	switch(key){
		case 0:
		printf("                                                       Exit success!\n");
		system("pause");
		exit (0);
		break;
		
		case 1:
		printf("                                                        Sign  up\n");
		printf("Please input user name and password:\n");
		scanf("%s %s",tempUser.name,tempUser.password);
		printf("Please input your new password again:\n");
		while(1){
			scanf("%s",password);
			if(strcmp(password,tempUser.password) == 0){
				printf("Success!\n");
				insertNode_u(list_u,tempUser);
				save_u("userinf.txt",list_u);
				break;
			}
			else {
				printf("Error!Please retry:\n");
				continue;
			}
		}
		break;
		
		case 2:
		printf("                                                         Log in\n");
		printf("Please input your name:\n");
		scanf("%s",tempUser.name);
		res_u = Search_u(list_u,tempUser.name);
		if(res_u == NULL) printf("Cannot Find!\n");
		else{
			printf("Please input your password:\n");
			scanf("%s",tempUser.password);
			if(strcmp(tempUser.password,res_u -> data.password) == 0){
				system("cls");
				index();
			}
			else printf("Error!\n");
		}
		break;
		
		defaut:printf("Error!\n");
	}
}
//--------------------------------------------------------------------------------------
int main(){
	system("color EA");
	list_u = createHead_u();
	read_u("userinf.txt",list_u);
	while(1){
		menu_u();
		reaction_u();
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}
//--------------------------------------------------------------------------------------
