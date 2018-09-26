#include <stdio.h>

int abs(int a){
	if(a < 0){
		a = -a;
	}
	return a;
}
int manhattan(int x,int y,int a,int b){
	return (abs(x-a) + abs(y-b));
}

int main()
{
	int size;
	int cars;
	int i,j;
	int a,b;
	int check = 0;
	int locX,locY;
	int bestX, bestY;
	int park_area[50][50];
	int best_dist = 0;
	int each_dist = 0;

	while(1){
		printf("Size: ");
		scanf("%d", &size);
		if (size > 50 || size < 1){
			printf("Size must be between 50 and 1\n");
		}
		else{
			break;
		}
	}

	for(i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			park_area[i][j] = 0;
		}
	}
	printf("Cars: ");
	scanf("%d", &cars);

	if(cars >= (size * size)){
		printf("Best Slot Found In: 0 0\n");
		return 0;
	}
	if(cars == 0){
		printf("Best Slot Found In: 1 1\n");
		return 0;
	}
	for (i = 0; i < cars; i++){
		printf("Locations: ");
		scanf("%d %d", &locX, &locY);
		park_area[locX - 1][locY - 1] = 1;
	}
	
	for(i = 0; i < size ; i++){
		for (j = 0; j < size; j++){
			each_dist = 98;
			if(park_area[i][j] ==  0){
				check = 1;
				for(a = 0; a < size; a++){
					for(b = 0; b < size; b++){
						if(park_area[a][b] == 1 && manhattan(i,j,a,b) < each_dist){
							each_dist = manhattan(i,j,a,b);
						}
					}
				}
				if(best_dist < each_dist){
					best_dist = each_dist;
					bestX = i + 1;
					bestY = j + 1;
				}
			} 
		}
	}
	if(check == 0){
		bestX = 0;
		bestY = 0;
	}

	printf("Best Slot Found In: %d %d\n", bestX, bestY);

	return 0;
}