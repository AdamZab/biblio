/* 5.	"Netlink"
	Wejscie: Generic netlink
	Modyfikacja/wyjscie: Jeżeli liczba jest parzysta-> x=x/2, jezeli nie-> przeksztalcenie bitowe
	według schematu ABCD ->BDAC, gdzie ABCD to 8bitowe czastki liczby wejsciowej
*/	

#include <stdio.h>


int main(){

	unsigned int input, result=0, mask=0;
	int i;
	printf("Liczba unsigned 32 bity: ");
	scanf("%u", &input);

	if(input%2==0)
		result=input/2;

	else{

		for(i=31;i>=0;--i){
			mask|=(1<<i);	

			if(i>=24 && input&mask){
				result|=(1<<i-16);	
			}

			else if(i<24 && i>=16 && input&mask){		
				result|=(1<<i+8);	
			}

			else if(i<15 && i>=8 && input&mask){			
				result|=(1<<(i-8));
			}

			else if (i<8 && input&mask) {		
				result|=(1<<i+16);
			}

			mask&=~(1<<i);
		}
	}
	FILE *fp;
	char buff[255];
	fp = fopen("log", "w+");
	fprintf(fp, "Liczba po zad5: %u\n", result);
	fclose(fp);
	popen("./NewTerminal.sh", "r");
	return 0;
}
