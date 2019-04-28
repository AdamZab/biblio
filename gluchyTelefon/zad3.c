/* 3.	"Pipe"
	Wejscie: nazwany pipe
	Modyfikacja/wyjscie: nastepna liczba pierwsza
*/	

#include <stdio.h>
#include <limits.h>
unsigned int result=0;

void print(int error){

	FILE *fp;
	char buff[255];
	fp = fopen("log", "w+");

	if(error==1)
		fprintf(fp,"Unsigned int overflow\n");

	else
		fprintf(fp,"Liczba po zad3: %u\n", result);

	fclose(fp);
	popen("./NewTerminal.sh", "r");
}

int main()
{

	unsigned int input;
	int i,test,error=0;
	printf("Liczba unsigned 32 bity: ");
	scanf("%u", &input);

	for(i=1;(i+result)<UINT_MAX;++i){		
		result=input+i;

		if(result==UINT_MAX||result==0){
			error=0;
			break;
			}

			for(test=result-1;test>=2;test--){
				
				if(result%test==0){
					break;
				}

			}

		if(input==0)
			result=1;

		if(test==1)
			break;
	}				
					
	print(error);
	return 0;
}
