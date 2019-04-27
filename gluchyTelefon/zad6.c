#include <stdio.h>

int main() {

	FILE *fp;
	char buff[255];
	fp = fopen("log", "w+");
	fprintf(fp, "New console\n");
	fclose(fp);
	popen("./NewTerminal.sh", "r");
}