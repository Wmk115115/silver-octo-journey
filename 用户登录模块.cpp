#include<stdio.h>
#include<malloc.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
//--------------------------------------------------------------------------------------
struct User *list = NULL;
struct User_inf{
	char name[20];
	char password[20];
};
struct User{
	struct User_inf data;
	struct User *next;
};
//--------------------------------------------------------------------------------------
struct User *createHead(){
	struct User *headNode = (struct User*)malloc(sizeof(struct User));
	headNode -> next = NULL;
	return headNode;
};
struct User *createNode(struct User_inf data){
	struct User *newNode = (struct User*)malloc(sizeof(struct User));
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
}
void insertNode(struct User *headNode,struct User_inf data){
	struct User *newNode = createNode(data);
	newNode -> next = headNode -> next;
	headNode -> next = newNode;
}
struct User *Search(struct User *headNode,char *username){
	struct User *posNode = headNode -> next;
	while(posNode != NULL && strcmp(posNode -> data.name,username)){
		posNode = posNode -> next;
	}
	return posNode;
}
//--------------------------------------------------------------------------------------
void save(const char *filename,struct User *headNode){
	FILE *fp = fopen("D:\\desktop\\Code-dev\\wenjian\\UserInformation.txt","w");
	struct User *pMove = headNode -> next;
	while(pMove != NULL){
		fprintf(fp,"%s\t%s\n",pMove -> data.name,pMove -> data.password);
		pMove = pMove -> next;
	}
	fclose(fp);
}
void read(const char *filename,struct User *headNode){
	FILE *fp = fopen("D:\\desktop\\Code-dev\\wenjian\\UserInformation.txt","r");
	if(fp == NULL){
		fp = fopen("D:\\desktop\\Code-dev\\wenjian\\UserInformation.txt","w+");
	}
	struct User_inf tempdata;
	while(fscanf(fp,"%s\t%s\n",tempdata.name,tempdata.password) != EOF){
		insertNode(list,tempdata);
	}
	fclose(fp);
}
//--------------------------------------------------------------------------------------
void menu(){
	printf("                                                           SYSTEM\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("                                                         0.EXIT\n");
	printf("                                                         1.Sign up\n");
	printf("                                                         2.Log in\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
}
//--------------------------------------------------------------------------------------
void reaction(){
	int key;
	char password[20];
	struct User_inf tempUser; 
	struct User *res = NULL;
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
				insertNode(list,tempUser);
				save("userinf.txt",list);
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
		res = Search(list,tempUser.name);
		if(res == NULL) printf("Cannot Find!\n");
		else{
			printf("Please input your password:\n");
			scanf("%s",tempUser.password);
			if(strcmp(tempUser.password,res -> data.password) == 0) printf("Success!");
			else printf("Error!\n");
		}
		break;
		
		defaut:printf("Error!\n");
	}
}
//--------------------------------------------------------------------------------------
int main(){
	system("color EA");
	list = createHead();
	read("userinf.txt",list);
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
