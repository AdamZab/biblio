/* 4.	"Jajko"
	Wejscie: Interfejs znakowy (linux kernel module over chrdev)
	Modyfikacja/wyjscie: Liczba ciagu Fibonacciego odpowiadajaca otrzymanemu numerowi
*/	

#include <stdio.h>


unsigned int fibo(unsigned int input){

	if(input<3)
		return 1;

	else
		return fibo(input-1)+fibo(input-2);
}

int main(){

	unsigned int input;
	char max=47;
	printf("Liczba unsigned 32 bity: ");
	scanf("%u", &input);

	FILE *fp;
		char buff[255];
		fp = fopen("log", "w+");

	if(input>max)
		fprintf(fp,"Unsigned int overflow\n");	

	else{
		fibo(input);			
		fprintf(fp,"Liczba po zad4: %u\n", fibo(input));
	}

	fclose(fp);
	popen("./NewTerminal.sh", "r");
	return 0;
}