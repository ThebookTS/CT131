//BookTs

//thuat toan song song
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// 2. Viet ham con tro; Se goi cac ham nay khi chung ta tao thread
void *print_hello(void *args) 
{
	printf("Hello, ");  
	fflush(stdout);
	return(0);
}

// 3. Chuong trinh chinh
int main()
{
	// 3.1 Khai bao cac bien kieu pthread_t  
	pthread_t tid;
	// 3.2 Tao thread thuc hien cac nhiem Ô cac ham con tro pthread_create()
	if (pthread_create(&tid, NULL, print_hello, NULL)) 
	{
		perror("pthread_create() failed");
    	exit(1);
	}
	// 3.3 Dong bo hoa thread chinh voi cac thread con pthread_join()
	if(pthread_join(tid, NULL)) 
	{
		perror("pthread_join() failed"); exit(1); 
	}
  	printf(" World!\n");
  	fflush(stdout);
 	exit(0);
	return 0;
}

