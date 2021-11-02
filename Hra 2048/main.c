#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//vyrob pole
int pole[4][4] =
{
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0}
};

//pohybova funkcia
int pohyb(int pole[4][4], int vstup)
{
	//vyhodnot ktory smer uzivatel zvolil
	switch (vstup)
	{
		//hore
		case 1:
			//cele vykonaj dva-krat aby si zaistil všetko
			for (int p = 0; p < 2; p++) 
			{
				//najdi kde su cisla a posun ich/zluc podla pravidiel
				for (int y = 0; y < 4; y++)
				{
					for (int x = 0; x < 4; x++)
					{
						//pravidla ak nasiel cislo
						if (pole[y][x] != 0)
						{
							//ak nie je uplne navrchu
							if (y != 0)
							{
								//posuvaj hore pokym je nad tebou volne alebo nedojes navrch
								int n = y;
								while ((pole[n - 1][x] == 0) && (n > 0))
								{
									pole[n - 1][x] = pole[n][x];
									pole[n][x] = 0;
									n = n - 1;
								}
								//ak tam kde si sa dostal while cyklom nie je uplne navrch a cislo nad tebou je rovnake zluc
								if ((n > 0) && (pole[n][x] == pole[n - 1][x]))
								{
									pole[n - 1][x] = 2 * pole[n][x];
									pole[n][x] = 0;
								}
							}
						}
					}
				}
			}
			break;
		//dole
		case 2:
			//cele vykonaj dva-krat aby si zaistil všetko
			for (int p = 0; p < 2; p++)
			{
				//najdi kde su cisla a posun ich/zluc podla pravidiel
				for (int y = 0; y < 4; y++)
				{
					for (int x = 0; x < 4; x++)
					{
						//pravidla ak nasiel cislo
						if (pole[y][x] != 0)
						{
							//ak nie je uplne dole
							if (y != 3)
							{
								//posuvaj dole pokym je pod tebou volne alebo nedojes naspodok
								int n = y;
								while ((pole[n + 1][x] == 0) && (n < 3))
								{
									pole[n + 1][x] = pole[n][x];
									pole[n][x] = 0;
									n = n + 1;
								}
								//ak tam kde si sa dostal while cyklom nie je uplne dole a cislo pod tebou je rovnake zluc
								if ((n < 3) && (pole[n][x] == pole[n + 1][x]))
								{
									pole[n + 1][x] = 2 * pole[n][x];
									pole[n][x] = 0;
								}
							}
						}
					}
				}
			}
			break;
		//dolava
		case 3:
			//cele vykonaj dva-krat aby si zaistil všetko
			for (int p = 0; p < 2; p++)
			{
				//najdi kde su cisla a posun ich/zluc podla pravidiel
				for (int y = 0; y < 4; y++)
				{
					for (int x = 0; x < 4; x++)
					{
						//pravidla ak nasiel cislo
						if (pole[y][x] != 0)
						{
							//ak nie je uplne vlavo
							if (x != 0)
							{
								//posuvaj vlavo pokym je vlavo od neho volne alebo nedojes uplne vlavo
								int n = x;
								while ((pole[y][n - 1] == 0) && (n > 0))
								{
									pole[y][n - 1] = pole[y][n];
									pole[y][n] = 0;
									n = n - 1;
								}
								//ak tam kde si sa dostal while cyklom nie je uplne vlavo a cislo vlavo od toho je rovnake zluc
								if ((n > 0) && (pole[y][n] == pole[y][n - 1]))
								{
									pole[y][n - 1] = 2 * pole[y][n];
									pole[y][n] = 0;
								}
							}
						}
					}
				}
			}
			break;
		//doprava
		case 4:
			//cele vykonaj dva-krat aby si zaistil všetko
			for (int p = 0; p < 2; p++)
			{
				//najdi kde su cisla a posun ich/zluc podla pravidiel
				for (int y = 0; y < 4; y++)
				{
					for (int x = 0; x < 4; x++)
					{
						//pravidla ak nasiel cislo
						if (pole[y][x] != 0)
						{
							//ak nie je uplne napravo
							if (x != 3)
							{
								//posuvaj doprava pokym je vpravo od neho volne alebo nedojes uplne naparvo
								int n = x;
								while ((pole[y][n + 1] == 0) && (n < 3))
								{
									pole[y][n + 1] = pole[y][n];
									pole[y][n] = 0;
									n = n + 1;
								}
								//ak tam kde si sa dostal while cyklom nie je uplne napravo a cislo napravo od toho je rovnake zluc
								if ((n < 3) && (pole[y][n] == pole[y][n + 1]))
								{
									pole[y][n + 1] = 2 * pole[y][n];
									pole[y][n] = 0;
								}
							}
						}
					}
				}
			}
			break;
	}

	return 0;
}

int main()
{
	//daj 2 dvojky na nahodne miesta pola + zabran aby sa dvojky vygenerovali na seba
	srand(time(NULL));
	int nahodne_cisla[4] = { rand() % 4, rand() % 4 , rand() % 4 , rand() % 4 };
	while ((nahodne_cisla[0] == nahodne_cisla[2]) && (nahodne_cisla[1] == nahodne_cisla[3]))
	{
		if ((nahodne_cisla[3] < 4) && (nahodne_cisla[3] > 0))
		{
			nahodne_cisla[3] = nahodne_cisla[3] - 1;
		}
		else
		{
			nahodne_cisla[3] = nahodne_cisla[3] +1;
		}
	}
	pole[nahodne_cisla[0]][nahodne_cisla[1]] = 2;
	pole[nahodne_cisla[2]][nahodne_cisla[3]] = 2;
	//slucka hry
	hra:
		//vykresli hraciu plochu + naformatuj medzery podla velkosti cisla v hracej ploche
		system("cls");
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (pole[y][x] < 10)
				{
					printf("%d    ", pole[y][x]);
				}
				else if ((pole[y][x] > 10) && (pole[y][x] < 100))
				{
					printf("%d   ", pole[y][x]);
				}
				else if ((pole[y][x] > 100) && (pole[y][x] < 1000))
				{
					printf("%d  ", pole[y][x]);
				}
				else
				{
					printf("%d ", pole[y][x]);
				}
			}
			printf("\n\n");
		}

		//vypytaj si vstup od uzivatela + uzavri slucku
		printf("1 = hore, 2 = dole, 3 = dolava, 4 = doprava: ");
		int vstup;
		scanf_s("%d", &vstup);
		pohyb(pole, vstup);
		
		//vyber nahodne suradnice kam vlozis dalsiu dvojku
		srand(time(NULL));
		int nahodne_cisla1[2] = { rand() % 4, rand() % 4 };
		//ak je tam volne vloz ak nie genruj nahodne suradnice kym nenajdes volne miesto
		while (pole[nahodne_cisla1[0]][nahodne_cisla1[1]] != 0)
		{
			int nahodne_cisla1[2] = { rand() % 4, rand() % 4 };
		}
		pole[nahodne_cisla1[0]][nahodne_cisla1[1]] = 2;

		goto hra;

	return 0;
}