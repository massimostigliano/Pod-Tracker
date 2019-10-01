#include<stdio.h>
#include<string.h>

void emptyDate(int podAmount,int month, int day, int year);
void worstDate(int worst,int year,int month);
void bestDate( int best, int year,int month,int day);


int podAmount;
int podsPerBox;
int boxes;
int worst = 0;
int best = 0;
int days_in_month[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int day, month, year;


int main(int argc, char* argv[]) {
	
	printf("\nPlease enter number of pod boxes:");
	scanf_s("%d", &boxes);
	printf("\nEnter number of pods per box:");
	scanf_s("%d", &podsPerBox);
	podAmount = podsPerBox * boxes;
	printf("Enter the date:(ex.12.9.1999)");
	scanf_s("%d.%d.%d", &month, &day, &year);
	
	emptyDate(podAmount,month,day,year);
	return 0;
}

void emptyDate(int podAmount, int month, int day,int year) {
	worst = podAmount * 2;
	best = podAmount * 3;
	printf("\nYou will run out of pods in %d - %d days.\n", worst, best);
	worstDate(worst,year,month);
	bestDate(best,year,month,day);
	
}

void worstDate(int worst, int year, int month) {
	for (int i = 0; i < worst; i++) {
		day++;
		if (day > days_in_month[month]) {
			day = 1;
			month++;
		}
		if (month > 12) {
			month = 1;
			year++;
			if (year % 4 == 0)
			{
				days_in_month[2] = 29;
			}
			else {
				days_in_month[2] = 28;
			}
		}
		

	}
	printf("%d.%d.%d ", month, day, year);
	
	

}
void bestDate(int best, int year, int month, int day) {
	for (int i = 0; i < best; i++) {
		day++;
		if (day > days_in_month[month]) {
			day = 1;
			month++;
		}

		if (month > 12) {
			
			month = 1;
			year++;
			if (year % 4 == 0)
			{
				days_in_month[2] = 29;

			}
			else {
				days_in_month[2] = 28;

			}
		}


	}
	printf("- %d.%d.%d", month, day, year);
}
