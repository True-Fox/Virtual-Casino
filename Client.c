#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main()
{
	gamble* game = (gamble*) malloc(sizeof(gamble));
	game -> amt = 10000; 
	game -> chip = 0; 
	game -> bet = 0;
	
	system("cls");
	
	char intro[] = "Welcome to the virtual casino!! Play the games of chance, like roulette, craps and slot machine.\n\nChips or casino tokens are small discs used as terms of currency in casinos.You can buy a chip for $11 and sell it for $10.\n\nYou have $10000 right now.\n";
	print_str(intro, 0.05);
	
	char menu[] = "1. Buy chips\n2. Sell chips\n3. Play Craps\n4. Craps Rules\n5. Play Roulette\n6. Roulette Rules\n7. Play Slot Machine\n8. Slot Machine Rules\n9. Check balance\n10. Quit\n";
	char cho[] = "Enter your choice: ";
	char buy[] = "Enter number of chips you want to buy: ";
	char sell[] = "Enter number of chips you want to sell: ";
	char bet[] = "Enter number of chips you want to bet: ";
	char low[] = "You don't have enough chips\n";
	char valid[] = "Please enter valid number of chips\n";
	char thanks[] = "Thanks for playing\n";
	char wrong[] = "Wrong choice\n";
	char equal[] = "=========================================================================================================================================================\n";
	
	int choice;
	
	do
	{
		printf("%s", equal);
		printf("%s", menu);
		print_str(cho, 0.05);
		scanf("%d", &choice);
		
		int x, y, b;
		
		switch(choice)
		{
		case 1: 
			do
			{
				b = 0;
				printf("%s", equal);
				print_str(buy, 0.05);
				scanf("%d",&x);
				
				if (x < 1)
				{
					print_str("Please enter a valid number of chips\n", 0.05);
					b = 1;
				}
				else
				{
					buy_x(x, game);
				}
			}while (b);
			break;
		
		case 2:
			do
			{
				b = 0;
				printf("%s", equal);
				print_str(sell, 0.05);
				scanf("%d", &x);
				
				if (x < 1)
				{
					print_str("Please enter a valid number of chips\n", 0.05);
					b = 1;
				}
				else
				{
					sell_x(x, game);
				}
			}while (b);
			break;
			
		case 3:
			if (game -> chip == 0)
			{
				print_str("Please buy the chips first\n", 0.05);
				break;
			}
				
			do
			{
				y = 0;
				
				printf("%s", equal);
				print_str(bet, 0.05);
				scanf("%d", &(game -> bet));

				if(game -> bet < 1)
				{
					y = 1;
					print_str("Please enter a valid number of chips.\n", 0.05);
				}
				else if (game -> bet > game -> chip)
				{
					y = 1;
					print_str(low, 0.05);
				}
				else
				{
					PlayCraps(game);
				}
			}while (y);
			break;
			
		case 4:
			printf("%s", equal);
			print_str("1) Roll a pair of fair six-sided dice.\n2) If you roll a 7 or 11, you win!\n3) If you roll a 2, 3, or 12, you lose.\n4) Otherwise, record what you've rolled. Let this sum be k; also known as your point.\n5) If you rolled a point, continue rolling the pair of dice until you get either your point (k) or a sum of seven on the two dice.\n6) If k comes up first, you win!\n7) If 7 comes up first, you lose.\n", 0.05);
			break;
			
		case 5:
			if (game -> chip == 0)
			{
				print_str("Please buy the chips first\n", 0.05);
				break;
			}				
				
			do
			{
				y = 0;
				
				printf("%s", equal);
				print_str(bet, 0.05);
				scanf("%d", &(game -> bet));
				
				if(game -> bet < 1)
				{
					y = 1;
					print_str("Please enter a valid number of chips.\n", 0.05);
				}
				else if (game -> bet > game -> chip)
				{
					y = 1;
					print_str(low, 0.05);
				}
				else
				{
					PlayRoulette(game);
				}
			}while (y);
			break;
			
		case 6:
			printf("%s", equal);
			print_str("Roulette is a game in which a ball is dropped on to a revolving wheel with numbered compartments from 1 to 36, the player betting on the number at which \nthe ball comes to rest.\n", 0.05);
			break;
			
		case 7:
			if (game -> chip == 0)
			{
				print_str("Please buy the chips first\n", 0.05);
				break;
			}				
				
			do
			{
				y = 0;
				printf("%s", equal);
				print_str(bet, 0.05);
				scanf("%d", &(game -> bet));
				
				if(game -> bet < 1)
				{
					y = 1;
					print_str("Please enter a valid number of chips.\n", 0.05);
				}
				else if (game -> bet > game -> chip)
				{
					y = 1;
					print_str(low, 0.05);
				}
				else
				{
						PlaySlotMachine(game);
				}
			}while(y);
			break;
			
		case 8: 
			printf("%s", equal);
			print_str("Slot machine contains three random number generators. The user will bet on a number from 0 to 9. If all the three generators show the same number\nentered by the user, the user wins 50 times the chips he/she has bet\n", 0.05);
			break;
			
		case 9:
			printf("%s", equal);
			printf("You have $%d left\n", game -> amt);
			printf("You have %d chips left\n", game -> chip);
			delay(0.5);
			break;
			
		case 10:
			printf("%s", equal);
			print_str(thanks, 0.05);
			printf("Your balance is $%d\n", (game -> amt) +(10*(game -> chip)));
			printf("%s", equal);
			delay(0.5);
			break;
			
		default:
			print_str(wrong, 0.05);
		}
	}while(choice != 10);
	
	system("pause");
	
	return 0;
}
			
	
	