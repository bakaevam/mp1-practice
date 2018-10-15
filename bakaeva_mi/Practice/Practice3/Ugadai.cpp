#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main() {
	char regim, ocenka;
	int n, i, a, n1, n2;

	n1 = 1;
	n2 = 1000;
	do
	{
		printf("Select game mode (1 or 2) \n");
		scanf(" %c ", &regim);
	} while ((regim != 1) || (regim != 2));

	switch (regim) {
	case '1':

		srand((unsigned int)time(0));
		n = (n2 - n1) / RAND_MAX * rand() + n1;

		i = 0;
		do
		{
			i++;
			printf(" Computer: Enter your number \n");
			scanf(" User: %d ", a);

			if (n > a) printf(" Computer: Your number is less (n>a)");
			if (n < a) printf(" Computer: Your number is greater (n<a)");
			if (n = a)
			{
				printf(" Computer: GUESSED!");
				printf(" Number of attempts = %d ", i);
				return;
			}
		} while (a != 0);

	case  '2':

		do
		{
			printf("Computer: Enter your number (1-1000) \n");
			scanf(" User: %d ", &n);
		} while ((n < n1) || (n > n2));

		do {
			i++;
			a = (n2 - n1) / RAND_MAX * rand() + n1;
			printf(" Computer: I think this number is %d", a);

			printf(" User: Your number - ");
			scanf(" %c ", ocenka);

			switch (ocenka) {
			case '>':
				n2 = a;
				a = (n2 - 1) / RAND_MAX * rand() + n1;
				break;
			case '<':
				n1 = a;
				a = (n2 - n1) / RAND_MAX * rand() + n1;

			case '=':
				printf(" User: GUESSED!");
				printf(" Number of attempts = %d ", i);
				return;

			} while (a != 0);
		}
	}
}