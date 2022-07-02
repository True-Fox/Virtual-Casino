#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
typedef struct gamble
{
	int amt;
	int chip;
	int bet;
}gamble;

int rand_int(int a, int b)
{
	srand(time(0));
    return rand() % (b - a + 1) + a;
}

void rand_int2(int *computer1, int *computer2, int *computer3)
{
    srand(time(0));
	*computer1 = rand() % 10;
	*computer2 = rand() % 10;
	*computer3 = rand() % 10;
}

void delay(float seconds)
{
	float milli = 1000 * seconds;
	float time = clock();
	while (clock() < time + milli);
}

void print_str(char *a, float time)
{
	for(int i = 0; *(a+i) != '\0'; i++)
	{
		printf("%c", *(a+i));
		delay(time);
	}
}

int spin()
{
	srand(time(0));
	int num = (rand() % 36) + 1;
    
	print_str("The ball is moving", 0.05);
	for (int j = 0; j < 3; j++)
    {
		printf(".");
    	delay(1);
	}


    printf("The ball landed on %d!!!\n\n", num);
	delay(0.5);
	
	return num;
}

void PlayCraps(gamble* data)
{
	int die1, die2, roll, die3, die4, roll1;
	die1 = rand_int(1, 6);
	die2 = rand_int(1, 6);
	roll = die1 + die2;
	
	printf("You rolled a %i\n", roll);
	delay(1.0);
	
	if(roll == 7 || roll == 11)
	{
		printf("\nYou have won %d chips\n", data -> bet);
		data -> chip += data -> bet;
		delay(0.5);
		return;
	}
	else if(roll == 2 || roll == 3 || roll == 12)
	{
		printf("\nYou have lost your bet. You lost %d chips\n",data -> bet);
		data -> chip -= data -> bet;
		delay(0.5);
		return;
	}
	else
	{
		do
		{
			die3 = rand_int(1, 6);
			die4 = rand_int(1, 6);
			roll1 = die3 + die4;
			
			printf("You rolled a %i\n", roll1);
			
			if(roll1 == roll)
			{
				printf("\nYou have won %d chips\n", data -> bet);
				data -> chip += data -> bet;
				delay(0.5);
				return;
			}
			
			delay(1.0);
		}while(roll1 != 7);
			
		printf("\nYou have lost your bet. You lost %d chips\n", data -> bet);
		data -> chip -= data -> bet;
		delay(0.5);
	}
}

void buy_x(int x, gamble* data)
{
	if(data -> amt < (x * 11))
	{
		print_str("Not enough balance\n", 0.05);
	}
	else
	{
		data -> amt = data -> amt - (11 * x);
		data -> chip += x;
		printf("You have bought %d chips\n", x);
		delay(0.5);
	}
}

void sell_x(int x, gamble* data)
{
	if(x > data -> chip || x <= 0)
	{
		print_str("You don't have enough chips to sell\n", 0.05);
	}
	else
	{
		data -> amt = data -> amt + (10 * x);
		data -> chip -= x;
		printf("You have sold %d chips\n", x);
		delay(0.5);
	}
}

void check_bal(gamble* data)
{
	printf("You have %d$ left\n", data -> amt);
	printf("You have %d chips left\n", data -> chip);
	delay(0.5);
}

void PlayRoulette(gamble* data)
{
	int num = 0, f = 0, choice, y;
	
	do
	{
		f = 0;
		print_str("\nWhat do you want to bet on?\nFor 1 and 2, payout is 1 to 1. For 3, payout is 35 to 1\n", 0.05);
		printf("1. Bet on odd or even\n2. Bet on low (1 - 18) or high (19 - 36)\n");
		printf("3. Bet on a specific number (1 - 36)\n");
		print_str("Enter your choice: ", 0.05);
    	
		int count;
    	scanf("%d", &count);

    	switch(count)
    	{
    	case 1:
			do
			{
				y = 0;
				print_str("\nEnter a 1 to bet on odd and 2 to bet on even: ", 0.05);
    			scanf("%d", &choice);
				
				if (choice != 1 && choice != 2)
				{
					y = 1;
					print_str("Please enter valid choice\n", 0.05);
				}
			}while(y);
				
    		num = spin();
			
			if ((num % 2 == 0 && choice == 2) || (num % 2 != 0 && choice == 1))
			{
				printf("You have won your bet. You get %d more chips\n", data -> bet);
				delay(0.5);
				data -> chip += data -> bet;
			}
			else
			{
				printf("You have lost your bet. You lose %d chips\n", data -> bet);
				delay(0.5);
				data -> chip -= data -> bet;
			}
			break;

		case 2:
			do
			{
				y = 0;
				print_str("\nEnter 1 to bet on low (1 - 18) or 2 to bet on high (19 - 36): ", 0.05);
    			scanf("%d", &choice);
				
				if (choice != 1 && choice != 2)
				{
					y = 1;
					print_str("Please enter valid choice\n", 0.05);
				}
			}while(y);
				
			num = spin();
			
			if ((num >= 1 && num <= 18 && choice == 1) || (num >= 19 && num <= 36 && choice == 2))
			{
				printf("You have won your bet. You get %d more chips\n", data -> bet);
				delay(0.5);
				data -> chip += data -> bet;
			}
			else
			{
				printf("You have lost your bet. You lose %d chips\n", data -> bet);
				delay(0.5);
				data -> chip -= data -> bet;
			}
			break;

		case 3:
			do
			{
				print_str("Enter the number that you want to bet on: ", 0.05);
				y = 0;
    			scanf("%d", &choice);
				
				if (choice < 1 || choice > 36)
				{
					y = 1;
					print_str("Please enter valid choice\n", 0.05);
				}
			}while(y);
			
			num = spin();
			
			if (choice == num)
			{
				printf("You have won your bet. You get %d more chips\n", (data -> bet) * 35);
				data -> chip += (data -> bet) * 35;
				delay(0.5);
			}
			else
			{
				printf("You have lost your bet. You lose %d chips\n", data -> bet);
				data -> chip -= data -> bet;
				delay(0.5);
			}
			break;
		
		default:
			print_str("Invalid choice!!!", 0.05);
			f = 1;
		}
	}while (f);
}

void PlaySlotMachine(gamble* data)
{
	int deposit1;
	int decision;
	int new_los;

	int computer1;
	int computer2;
	int computer3;
	rand_int2(&computer1, &computer2, &computer3);
	
	int guess1;
	print_str("Guess a number from 0 to 9 : ", 0.05);
	scanf("%d", &guess1);
	printf("\n\n");
	
	while(guess1 > 9 || guess1 < 0)
	{
		print_str("Please enter an integer greater than 0 and less than 10 \n", 0.05);
		print_str("Enter Again : ", 0.05);
		scanf("%d", &guess1);
	}
	printf("\n\n");
	
	print_str("Slot machine is running", 0.05);
	for (int j = 0; j < 3; j++)
    {
		printf(".");
    	delay(1);
	}
	
	printf("\n\n\n ***   %d %d %d   *** are the numbers on the slot machine\n\n\n", computer1, computer2, computer3);
	
	if(guess1 == computer1  && guess1 == computer2 && guess1 == computer3)
	{  
		print_str("Congratulations you won!!\n", 0.05);
		printf("You have won %d chips", data -> bet * 50);
		printf("\n");
		delay(0.5);
				
		data -> bet = data -> bet * 50;
		data -> chip += data -> bet;
	}
	else
	{		
		printf("You have lost %d chips",data->bet);
		printf("\n");
		delay(0.5);
		
		data->chip -= data ->bet;		
	}
}