/* 1.	"Konsola"
	wejscie: stdin
	modyfikacja/wyjscie: x:=x+1
	Sterowanie wszystkimi programami
*/	

#include <stdio.h>
#include <limits.h>
unsigned int result=0;

void print(int error){

	FILE *fp;
	char buff[255];
	fp = fopen("log", "w+");

	if(error==1)
		printf("Unsigned int overflow\n");

	else
		printf("Liczba po zad1: %u\n", result);

	//fclose(fp);
	//open("./NewTerminal.sh", "r");
}

int main()
{
	unsigned int input;
	int error;
	printf("Liczba unsigned 32 bity: ");
	scanf("%u", &input);
	
	if (input==UINT_MAX)
		error=1;

	else{	
		result=input+1;
		error=0;
	}
		

	print(error);
	return 0;
}
