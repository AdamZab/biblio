/* 2.	"Argument"
	Wejscie: argument do programu, parsowana pomoca getopt
	Modyfikacja/wyjscie: x:=lustrzane odbicie bitow, np dla 6(110):=3(011)
*/	

#include <stdio.h>
unsigned int result=0;

int main()
{
	
	unsigned int result=0, input, mask=0;
	int i,maxi=0;
	printf("Liczba unsigned 32 bity: ");
	scanf("%u", &input);

	for(i=31;i>=0;--i){			
		mask|=(1<<i);

		if(input&mask){

			if(maxi==0){
				maxi=i;
			}

			result|=1<<(maxi-i);
		}

		mask&=~(1<<i);		
	}

	FILE *fp;
	char buff[255];
	fp = fopen("log", "w+");
	fprintf(fp, "Liczba po zad2: %u\n", result);
	fclose(fp);
	popen("./NewTerminal.sh", "r");
	return 0;
}
