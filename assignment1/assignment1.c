#include <stdio.h>
#include <stdlib.h>

int main()
{
	int q = 0;
	int m = 0;
	int year = 0, cons_year = 0;
	int k = 0;
	int j = 0;
	int end_year = 0;
	int finalDay = 0;
	int count = 0;
	int checker = 0;

	printf("Enter date [year month day]: ");
	scanf("%d %d %d", &year, &m, &q);
	//check valid
	if(m < 1 || m > 12 || year < 0 || year > 9999){
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	}
	if(m == 2){
		if(q > 28 || q < 0){
			printf("Invalid date.\n");
			return EXIT_FAILURE;
		}
	}
	if(m == 2 || m == 4 || m == 6 || m == 9 || m == 11){
		if(q > 30 || q < 0){
			printf("Invalid date.\n");
			return EXIT_FAILURE;
		}
	}
	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 12){
		if(q > 31 || q < 0){
			printf("Invalid date.\n");
			return EXIT_FAILURE;
		}
	}
	printf("Enter end year: ");
	scanf("%d", &end_year);
	if (end_year < year)
	{
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	}

	cons_year = year + 1;

	if(m == 1 || m == 2){
		m += 12;
		year -= 1;
		end_year -= 1;
	}
	k = year % 100;
	j = (year - k) / 100;
	finalDay = (q + ((13 * (m+1))/5) + k + (k / 4) + (j / 4) + (5 * j)) % 7;
	// Count same days
	while(year < end_year){
		year += 1;
		k = year % 100;
		j = (year - k) / 100;
		checker = (q + ((13 * (m+1))/5) + k + (k / 4) + (j / 4) + (5 * j)) % 7;
		if(checker == finalDay){
			count += 1;
		}
	}
	if(m == 13 || m == 14){
		end_year += 1;
	}

	
	if(finalDay == 0){
		printf("It's a Saturday.\n");
	}
	if(finalDay == 1){
		printf("It's a Sunday.\n");
	}
	if(finalDay == 2){
		printf("It's a Monday.\n");
	}
	if(finalDay == 3){
		printf("It's a Tuesday.\n");
	}
	if(finalDay == 4){
		printf("It's a Wednesday.\n");
	}
	if(finalDay == 5){
		printf("It's a Thursday.\n");
	}
	if(finalDay == 6){
		printf("It's a Friday.\n");
	}
	printf("Same day-and-month on same weekday between %d and %d: %d\n", cons_year, end_year, count);

	return EXIT_SUCCESS;
}