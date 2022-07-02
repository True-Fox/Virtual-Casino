#ifndef HEADER_H
#define HEADER_H

typedef struct gamble
{
	int amt;
	int chip;
	int bet;
}gamble;

void delay(float seconds);
void print_str(char *a, float time);
int spin();
int rand_int(int a, int b);
void PlayCraps(gamble* data);
void buy_x(int x, gamble* data);
void sell_x(int x, gamble* data);
void check_bal(gamble* data);
void PlayRoulette(gamble* data);
void PlaySlotMachine(gamble* data);
void rand_int2(int *computer1, int *computer2, int *computer3);

#endif 