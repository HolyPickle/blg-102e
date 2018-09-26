#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int throw_point(int segment, char ring){
	int point;

	switch(ring){
		case 'S':
			point = segment;
			break;
		case 'D':
			point = 2 * segment;
			break;
		case 'T':
			point = 3 * segment;
			break;
		case 'I':
			point = 50;
			break;
		case 'O':
			point = 25;
			break;
	}  
	return point;
}

int total_point(int segment, int current_point, char ring){
	int minus_point;
	minus_point = throw_point(segment,ring);

	current_point = current_point - minus_point;

	return current_point;
}

int main()
{	
	FILE *ptr = fopen("deneme.txt","w");
	srand(time(NULL));
	char harfler[5] = "STDIO";
	int segment;
	char ring;
	int target = 101;
	int check = 0;
	int randomInt;
	
	fprintf(ptr,"Target: 101\n\n");

	while(target != 0){
		if(target == 1){
			return 0;
		}
		segment = (rand() % 20) + 1;
		randomInt = rand() % 5;
		ring = harfler[randomInt];

		fprintf(ptr,"Throw: %d %c\n", segment, ring);
		//scanf("%d %c", &segment, &ring);
		
		if( check == 0 && ring != 'D'){
			fprintf(ptr,"Points: %d\n", target);
		}
		else{
			check = 1;
			if(total_point(segment, target, ring) >= 0 && total_point(segment, target, ring) != 1){
				if(total_point(segment, target, ring) == 0 && ring != 'D'){
					fprintf(ptr,"Points: %d\n", target);
				}
				else{
					target = total_point(segment, target, ring);
					fprintf(ptr,"Points: %d\n", target);
				}
			}
			else{
				fprintf(ptr,"Points: %d\n", target);
			}
		}
	}
	return 0;
}