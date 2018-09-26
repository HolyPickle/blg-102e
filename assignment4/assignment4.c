#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct instruction_s{
	int step;
	int index;
};

char* get_word(char* s, int n){
	char* word;
	char* new_s;
	word = (char*) malloc(20 * sizeof(char));
	new_s = (char*) malloc(200 * sizeof(char));
	int check = 1, a = 0;
	int space_check = 0;
	int len, x = 0;
	len = strlen(s);

	for (int i = 0; i < len; i++){
		if(!(ispunct(s[i]))){
			new_s[x] = tolower(s[i]);
			x++;
		}
	}
	new_s[x + 1] = '\0';
	
	for (int i = 0; i < 200; ++i){
		if (check == n){
			if(new_s[i] != ' ' && new_s[i] != '\n' && new_s[i] != '\r'){
				word[a] = new_s[i];
				a++;
			}
			else{
				break;
			}
		}
		else if(new_s[i] == ' ' && space_check == 0){
			check++;
			space_check = 1;
		}
		else{
			space_check = 0;
		}
	}
	return word;
}

void get_sentence(char** lines, struct instruction_s* instructions,
				  int n_instructions, char* sentence){
	int a = -1;
	for (int i = 0; i < n_instructions; ++i){
		a += ((instructions + i)->step);
	}
	strcpy(sentence, lines[a]);
}

int main(int argc, char** argv)
{
	FILE *iPtr;
	FILE *bPtr;

	bPtr = fopen(argv[1], "r");
	iPtr = fopen(argv[2], "r");
	
	int count = 0;
	char *sentence;
	sentence = (char*) malloc(200 * sizeof(char));
	struct instruction_s *instPtr;
	instPtr = (struct instruction_s*) malloc(200 * sizeof(struct instruction_s));


	char **book = malloc(10000 *sizeof(char*));
	for (int i = 0; i < 10000; i++){
		book[i] = malloc(100* sizeof(char));
	}
	for (int i = 0; i < 10000 && !feof(bPtr); ++i){
		fgets(book[i], 200, bPtr);
	}
	for(int i=0; !feof(iPtr); i++){
		count++;
		fscanf(iPtr,"%d %d\n", &(instPtr+i)->step, &(instPtr+i)->index);
		get_sentence(book,instPtr,count,sentence);
		printf("%s ",get_word(sentence, ((instPtr+i)->index)));
	}
	printf("\n");
	
	fclose(iPtr);
	fclose(bPtr);
	free(book);
	free(instPtr);
	free(sentence);

	return 0;
}