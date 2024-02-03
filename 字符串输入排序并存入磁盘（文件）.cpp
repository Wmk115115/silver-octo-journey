#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	FILE *fp;
	char str[3][10], temp[10];
	int i, j, k, n = 3;
	
	
	printf("Enter strings:\n");
	for(i = 0; i < 3; i++) gets(str[i]);              //input the file(free)
	
	
	/*for(i = 0; i < 3; i++){
		k = i;
		for(j = i + 1; j < n; j++){
			if(strcmp(str[k],str[j]) > 0) k = j;
		}
		if(k != i){                                      //sort(free)
			strcpy(temp,str[i]);
			strcpy(str[i],str[k]);
			strcpy(str[k],temp);
		}
	}*/
	
	
	if((fp = fopen("D:\\desktop\\Code-dev\\wenjian\\message.txt","w")) == NULL){
		printf("Can not open file!\n");                        //open the file(lock)
		exit(0);
	}
	
	
	printf("\nThe new sequence:\n");
	for(i = 0; i < n; i++){
		fputs(str[i],fp);                  //show on the screen(free)
		fputs("\n",fp);
		printf("%s\n",str[i]);
	}
	
	
	return 0;
}
