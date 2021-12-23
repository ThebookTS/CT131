//BookTs

//hien thi thoi gian thuc
#include <stdio.h>
#include <time.h>
#include <windows.h>

int thoigian(time_t)
{
	time_t curtime;
	time(&curtime);
	printf("Thoi gian hien tai %s", ctime(&curtime));
}
int main ()
{
	system("color 2");//doi mau chu
	int ctime;
	for(;;){
	thoigian(ctime);
	Sleep(1000);
	system("cls");
	}
	return(0);
}
