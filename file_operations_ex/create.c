#include <stdio.h>
// CREATE A BLANK DATA FILE
struct clientData
{
	unsigned int acctNum;
	char lastName[15];
	char firstName[10];
	double balance;
};

int main(void)
{
	unsigned int i;

	struct clientData blankClient = {0, "", "", 0.0};

	FILE *cfPtr;
	cfPtr = fopen("credit.dat", "wb");

	for(i = 1; i <= 100; i++){
		fwrite(&blankClient, sizeof(struct clientData), 1, cfPtr);
	}
	fclose(cfPtr);

	return 0;
}