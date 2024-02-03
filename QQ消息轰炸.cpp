#include<stdio.h>
#include<windows.h>
int main(){
	int Num = 5;
	FindWindow(NULL, "wumingyong");
	while(Num){
		SendMessage(FindWindow(NULL, "wumingyong"), WM_PASTE, NULL, NULL);
		SendMessage(FindWindow(NULL, "wumingyong"), WM_KEYDOWN, VK_RETURN, NULL);
		Num--;
	}
	return 0;
}
