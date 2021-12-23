//BookTs
#include<stdio.h>

void reserve()
{
	char s;
	scanf("%c",&s);
	if(s!='\n')
	{
		reserve();
		printf("%c",s);
	}

}

int main()
{
	printf("Nhap chuoi vo de dao nguoc\n");
	reserve();

	return 0;
}


