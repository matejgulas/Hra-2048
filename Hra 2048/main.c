#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define hore 72
#define dole 80
#define dolava 75
#define doprava 77
#define escape 27
#define enter 13

#pragma warning(disable : 4996)

int vyber = 0;
int skore = 0;

//vyrob pole
int pole[4][4] =
{
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0}
};

//farby
void farba_tyrkysova()
{
	printf("\033[0;36m");
}
void farba_reset()
{
	printf("\033[0;37m");
}
void farba_zlta()
{
	printf("\033[0;33m");
}

//vykreslovanie menu
void vykreslenie_menu(vyber)
{
	system("cls");
	if (vyber == 0)
	{
		farba_reset();
		printf("----HRA 2048----\n\n");
		printf("NOVA HRA <---\n");
		printf("POKRACOVANIE \n");
		printf("STATISTIKY \n");
		farba_tyrkysova();
		printf("\n\n[Ovladaj sipkami, vyber potvrd enterom]");
		farba_reset();
	}
	else if (vyber == 1)
	{
		farba_reset();
		printf("----HRA 2048----\n\n");
		printf("NOVA HRA \n");
		printf("POKRACOVANIE <---\n");
		printf("STATISTIKY \n");
		farba_tyrkysova();
		printf("\n\n[Ovladaj sipkami, vyber potvrd enterom]");
		farba_reset();
	}
	else if (vyber == 2)
	{
		farba_reset();
		printf("----HRA 2048----\n\n");
		printf("NOVA HRA \n");
		printf("POKRACOVANIE \n");
		printf("STATISTIKY <---\n");
		farba_tyrkysova();
		printf("\n\n[Ovladaj sipkami, vyber potvrd enterom]");
		farba_reset();
	}
}

//pohybova funkcia
int pohyb(int pole[4][4], int vstup, int pole_plnosti[4][4])
{
	//vyhodnot ktory smer uzivatel zvolil
	switch (vstup)
	{
		//hore
		case hore:
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
									pole_plnosti[n - 1][x] = 1;
									pole[n][x] = 0;
									pole_plnosti[n][x] = 0;
									n = n - 1;
								}
								//ak tam kde si sa dostal while cyklom nie je uplne navrch a cislo nad tebou je rovnake zluc
								if ((n > 0) && (pole[n][x] == pole[n - 1][x]))
								{
									pole[n - 1][x] = 2 * pole[n][x];
									skore = skore + 2 * pole[n][x];
									pole_plnosti[n - 1][x] = 1;
									pole[n][x] = 0;
									pole_plnosti[n][x] = 0;
								}
							}
						}
					}
				}
			}
			break;
		//dole
		case dole:
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
									pole_plnosti[n + 1][x] = 1;
									pole[n][x] = 0;
									pole_plnosti[n][x] = 0;
									n = n + 1;
								}
								//ak tam kde si sa dostal while cyklom nie je uplne dole a cislo pod tebou je rovnake zluc
								if ((n < 3) && (pole[n][x] == pole[n + 1][x]))
								{
									pole[n + 1][x] = 2 * pole[n][x];
									skore = skore + 2 * pole[n][x];
									pole_plnosti[n + 1][x] = 1;
									pole[n][x] = 0;
									pole_plnosti[n][x] = 0;
								}
							}
						}
					}
				}
			}
			break;
		//dolava
		case dolava:
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
									pole_plnosti[y][n - 1] = 1;
									pole[y][n] = 0;
									pole_plnosti[y][n] = 0;
									n = n - 1;
								}
								//ak tam kde si sa dostal while cyklom nie je uplne vlavo a cislo vlavo od toho je rovnake zluc
								if ((n > 0) && (pole[y][n] == pole[y][n - 1]))
								{
									pole[y][n - 1] = 2 * pole[y][n];
									skore = skore + 2 * pole[n][x];
									pole_plnosti[y][n - 1] = 1;
									pole[y][n] = 0;
									pole_plnosti[y][n] = 0;
								}
							}
						}
					}
				}
			}
			break;
		//doprava
		case doprava:
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
									pole_plnosti[y][n + 1] = 1;
									pole[y][n] = 0;
									pole_plnosti[y][n] = 0;
									n = n + 1;
								}
								//ak tam kde si sa dostal while cyklom nie je uplne napravo a cislo napravo od toho je rovnake zluc
								if ((n < 3) && (pole[y][n] == pole[y][n + 1]))
								{
									pole[y][n + 1] = 2 * pole[y][n];
									skore = skore + 2 * pole[n][x];
									pole_plnosti[y][n + 1] = 1;
									pole[y][n] = 0;
									pole_plnosti[y][n] = 0;
								}
							}
						}
					}
				}
			}
			break;
	}

	return skore;
}

//hra
int nova_hra()
{
	skore = 0;
	system("cls");
	printf("Zadaj svoje meno: ");
	char meno[10];
	scanf_s("%s", meno, 10);

	farba_tyrkysova();
	printf("Vitaj %s!", meno);
	farba_reset();
	Sleep(1000);

	int vstup = 0; //!!!
	skore = 0;

	//vyrob pole
	int pole[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};

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
			nahodne_cisla[3] = nahodne_cisla[3] + 1;
		}
	}
	pole[nahodne_cisla[0]][nahodne_cisla[1]] = 2;
	pole[nahodne_cisla[2]][nahodne_cisla[3]] = 2;

	int pole_plnosti[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};
	int plnost = 0;
	
	//slucka hry
	int hra_bezi = 1;
	
	//vykresli hraciu plochu + naformatuj medzery podla velkosti cisla v hracej ploche
	system("cls");
	farba_reset();
	printf("------------------------   Skore: %d\n", skore);
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (pole[y][x] != 0)
			{
				farba_zlta();
				
				if (pole[y][x] < 10)
				{
					printf("  %d  |", pole[y][x]);
				}
				else if ((pole[y][x] > 10) && (pole[y][x] < 100))
				{
					printf(" %d  |", pole[y][x]);
				}
				else if ((pole[y][x] > 100) && (pole[y][x] < 1000))
				{
					printf(" %d |", pole[y][x]);
				}
				else
				{
					printf("%d |", pole[y][x]);
				}

			}

			else
			{
				farba_reset();

				if (pole[y][x] < 10)
				{
					printf("  %d  |", pole[y][x]);
				}
				else if ((pole[y][x] > 10) && (pole[y][x] < 100))
				{
					printf(" %d  |", pole[y][x]);
				}
				else if ((pole[y][x] > 100) && (pole[y][x] < 1000))
				{
					printf(" %d |", pole[y][x]);
				}
				else
				{
					printf("%d |", pole[y][x]);
				}

			}
		}
		farba_reset();
		printf("\n------------------------\n");
	}
	farba_tyrkysova();
	printf("\n[Pohyb: sipky, Ukoncenie hry: escape]");
	farba_reset();

	while (vstup != escape)
	{
		if (_kbhit())
		{
			if (hra_bezi == 1)
			{

				vstup = _getch();
				pohyb(pole, vstup, pole_plnosti);

				//over plnost
				plnost = 0;
				for (int y = 0; y < 4; y++)
				{
					for (int x = 0; x < 4; x++)
					{
						if (pole_plnosti[y][x] == 1)
						{
							plnost = plnost + 1;
						}
					}
				}
				
				if (plnost == 16)
				{
					hra_bezi = 0;
				}

				if (hra_bezi != 0)
				{
					//vyber nahodne suradnice kam vlozis dalsiu dvojku
					srand(time(NULL));
					int nahodne_cisla1[2] = { rand() % 4, rand() % 4 };
					//ak je tam volne vloz ak nie genruj nahodne suradnice kym nenajdes volne miesto
					while (pole[nahodne_cisla1[0]][nahodne_cisla1[1]] != 0)
					{
						nahodne_cisla1[0] = rand() % 4;
						nahodne_cisla1[1] = rand() % 4;
					}
					pole[nahodne_cisla1[0]][nahodne_cisla1[1]] = 2;
					pole_plnosti[nahodne_cisla1[0]][nahodne_cisla1[1]] = 1;
				}

				//vykresli hraciu plochu + naformatuj medzery podla velkosti cisla v hracej ploche
				system("cls");
				farba_reset();
				printf("------------------------   Skore: %d\n", skore);
				for (int y = 0; y < 4; y++)
				{
					for (int x = 0; x < 4; x++)
					{
						if (pole[y][x] != 0)
						{
							farba_zlta();

							if (pole[y][x] < 10)
							{
								printf("  %d  |", pole[y][x]);
							}
							else if ((pole[y][x] > 10) && (pole[y][x] < 100))
							{
								printf(" %d  |", pole[y][x]);
							}
							else if ((pole[y][x] > 100) && (pole[y][x] < 1000))
							{
								printf(" %d |", pole[y][x]);
							}
							else
							{
								printf("%d |", pole[y][x]);
							}

						}

						else
						{
							farba_reset();

							if (pole[y][x] < 10)
							{
								printf("  %d  |", pole[y][x]);
							}
							else if ((pole[y][x] > 10) && (pole[y][x] < 100))
							{
								printf(" %d  |", pole[y][x]);
							}
							else if ((pole[y][x] > 100) && (pole[y][x] < 1000))
							{
								printf(" %d |", pole[y][x]);
							}
							else
							{
								printf("%d |", pole[y][x]);
							}

						}
					}
					farba_reset();
					printf("\n------------------------\n");
				}
				farba_tyrkysova();
				printf("\n[Pohyb: sipky, Ukoncenie hry: escape]");
				farba_reset();

			}
			//koniec hry
			else
			{
				//uloz skore do statistik
				char retazec[2048];
				FILE* subor_statistiky_citaj = fopen("statistiky.txt","r");
				fscanf_s(subor_statistiky_citaj, "%s", &retazec, 2048);
				fclose(subor_statistiky_citaj);
				
				//vypis prehra a vrat do menu
				system("cls");
				farba_reset();
				printf("-----------PREHRA!-----------");
				printf("\n\n       -Skore: %d-\n", skore);
				printf("-----------------------------");
				Sleep(1000);
				main();
				
			}
		}
	}
	//ak stlacis escape, chod spat do menu
	main();
	return 0;
}

//statistiky
void statistiky()
{
	int vstup = 0;
	farba_reset();
	system("cls");
	farba_zlta();
	printf("-------Statistiky-----------\n\n");
	farba_tyrkysova();
	printf("Hrac  |  body\n");
	farba_reset();

	//nacitaj zo suboru
	FILE* subor_statistiky_citanie = fopen("statistiky.txt","r");

	//pokym nie si nakonci suboru, vykonaj nasledovne
	char riadok[1024];
	int n1 = 0; int n2 = 0;
	char hrac[50]; char body[50];
	while (fgets(riadok, sizeof(riadok), subor_statistiky_citanie) != NULL)
	{
		n1 = 0; n2 = 0;
		for (int i = 0; i < 10; i++)
		{
			if ((riadok[i] >= 'A') && (riadok[i] <= 'z'))
			{
				hrac[n1] = riadok[i];
				n1++;
			}
			else if ((riadok[i] >= '0') && (riadok[i] <= '9'))
			{
				body[n2] = riadok[i];
				n2++;
			}
		}
		hrac[n1] = '\0'; body[n2] = '\0';
		printf("%s : %s\n", hrac, body);
	}
	//zavri subor
	fclose(subor_statistiky_citanie);

	farba_tyrkysova();
	printf("\n[esc - navrat do menu]");
	farba_reset();

	//cakaj na uzivatela
	while (vstup != escape)
	{
		if (_kbhit)
		{
			vstup = _getch();
		}
	}
	//ak stlacil esc tak sa vrat do menu
	main();
}

//menu
int main()
{
	//vykresli menu
	vykreslenie_menu(vyber);

	//cakaj na vstup uzivatela
	int vstup = 0;
	while (vstup != enter)
	{
		if (_kbhit())
		{
			vstup = _getch();
			switch (vstup)
			{
			case hore:
				if (vyber != 0)
				{
					vyber = vyber - 1;
					vykreslenie_menu(vyber);
					break;
				}
			case dole:
				if (vyber < 2)
				{
					vyber = vyber + 1;
					vykreslenie_menu(vyber);
					break;
				}
			}
		}
	}
	//sprav to co uzivatel zvolil
	switch (vyber)
	{
	case 0:
		nova_hra();
		break;

	case 1:
		printf("Pokracovat");
		break;

	case 2:
		statistiky();
		break;
	}
	return 0;
}