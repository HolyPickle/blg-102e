#include <stdio.h>

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

	int segment;
	char ring;
	int target;
	int check = 0;

	
	printf("Target: ");
	scanf("%d", &target);
	//printf("\n");

	while(target != 0){
		printf("Throw: ");
		scanf("%d %c", &segment, &ring);
		if( check == 0 && ring != 'D'){
			printf("Points: %d\n", target);
		}
		else{
			check = 1;
			if(total_point(segment, target, ring) >= 0 && total_point(segment, target, ring) != 1){
				if(total_point(segment, target, ring) == 0 && ring != 'D'){
					printf("Points: %d\n", target);
				}
				else{
					target = total_point(segment, target, ring);
					printf("Points: %d\n", target);
				}
			}
			else{
				printf("Points: %d\n", target);
			}
		}
	}
	return 0;
}