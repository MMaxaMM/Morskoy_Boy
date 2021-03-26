#include<iostream>
#include<tchar.h>
#include<conio.h>
#include<assert.h>
#include <time.h>

#define t _T

//Функция генерации случайных чисел
inline int __fastcall Rand(int range_min, int range_max)
{
	return (unsigned)((double)rand() / ((double)RAND_MAX + 1) * ((double)range_max - (double)range_min) + (double)range_min);
}

//Макрос случайных чисел
#define URAND(Max) (unsigned)Rand( 0, (Max))

//Координаты
int X1, X2;//Промежуточные координаты

unsigned Count_P, Count_B; //Количество кораблей

struct Cells
{
	int Coord;
	unsigned status;
	//0 - пусто
	//1 - подбит корабль
	//2 - корабль
	//3 - мимо
	Cells()
	{
		Coord = 0;
		status = 0;
	}
};


//---------------------------------------------------
bool Repeats(Cells * Cell)
{
	//Проверка на повторы
	for (unsigned i = 0; i < 100; i++)
	{
		if (Cell[i].Coord = X1 && Cell[i].status != 0) return false;
	}
	return true;
}
//---------------------------------------------------

//---------------------------------------------------
bool Logic(int num, Cells* Cell)
{
	int x1 = X1 < X2 ? X1 : X2;
	int x2 = X1 < X2 ? X2 : X1;
	//Написал
	if (num == 4)
	{
		if ((x1 - x1 % 10) == (x2 - x2 % 10))
		{
			//Корабль расположен по горизонтали

			if (x2 - x1 != 3) return false;

			Cell[x1].status = 2;
			Cell[x1 + 1].status = 2;
			Cell[x1 + 2].status = 2;
			Cell[x1 + 3].status = 2;
			return true;
		}
		else if (x1 % 10 == x2 % 10)
		{
			//Корабль расположен по вертикали

			if (x2 - x1 != 30) return false;

			Cell[x1].status = 2;
			Cell[x1 + 10].status = 2;
			Cell[x1 + 20].status = 2;
			Cell[x1 + 30].status = 2;
			return true;
		}
		else return false;
	}

	//Написал
	if (num == 3)
	{
		if ((x1 - x1 % 10) == (x2 - x2 % 10))
		{
			//Корабль расположен по горизонтали

			if (x2 - x1 != 2) return false;

			if (x1 - 10 >= 0)
			{
				if (Cell[x1 - 10].status != 0) return false;
				if (Cell[x1 - 9].status != 0)  return false;
				if (Cell[x1 - 8].status != 0)  return false;
			}
			if (x2 + 10 < 100)
			{
				if (Cell[x2 + 10].status != 0) return false;
				if (Cell[x2 + 9].status != 0)  return false;
				if (Cell[x2 + 8].status != 0)  return false;
			}
			if ((x1 - 1 - (x1 - 1) % 10 == x1 - x1 % 10) && x1 != 0)
			{
				if (Cell[x1 - 1].status != 0) return false;
			}
			if ((x2 + 1 - (x2 + 1) % 10 == x2 - x2 % 10) && x2 != 99)
			{
				if (Cell[x2 + 1].status != 0) return false;
			}


			if ((x1 - 11 >= 0) && (x1 - 11 - (x1 - 11) % 10 == x1 - 10 - (x1 - 10) % 10))
			{
				if (Cell[x1 - 11].status != 0) return false;
			}
			if ((x1 + 9 < 100) && (x1 + 9 - (x1 + 9) % 10 == x1 + 10 - (x1 + 10) % 10))
			{
				if (Cell[x1 + 9].status != 0) return false;
			}
			if ((x2 - 9 >= 0) && (x2 - 9 - (x2 - 9) % 10 == x2 - 10 - (x2 - 10) % 10))
			{
				if (Cell[x2 - 9].status != 0) return false;
			}
			if ((x2 + 11 < 100) && (x2 + 11 - (x2 + 11) % 10 == x2 + 10 - (x2 + 10) % 10))
			{
				if (Cell[x2 + 11].status != 0) return false;
			}

			Cell[x1].status = 2;
			Cell[x1 + 1].status = 2;
			Cell[x1 + 2].status = 2;
			return true;
		}
		else if (x1 % 10 == x2 % 10)
		{
			//Корабль расположен по вертикали

			if (x2 - x1 != 20) return false;

			if (x1 - 10 >= 0)
			{
				if(Cell[x1-10].status != 0) return false;
			}
			if (x1 - 10 >= 0 && x1 % 10 != 0)
			{
				if(Cell[x1 - 11].status != 0) return false;
			}
			if (x1 % 10 != 0)
			{
				if(Cell[x1-1].status != 0) return false;
				if (Cell[x1 + 9].status != 0) return false;
				if (Cell[x1 + 19].status != 0) return false;
			}
			if (x2 + 10 < 100 && x2 % 10 != 0)
			{
				if(Cell[x2 + 9].status != 0) return false;
			}
			if (x2 + 10 < 100)
			{
				if(Cell[x2+10].status != 0) return false;
			}
			if (x2 % 10 != 9 && x2 + 10 < 100)
			{
				if(Cell[x2 + 11].status != 0) return false;
			}
			if (x2 % 10 != 9)
			{
				if(Cell[x1 +1].status != 0) return false;
				if (Cell[x1 + 11].status != 0) return false;
				if (Cell[x1 + 21].status != 0) return false;
			}
			if (x1 % 10 != 9 && x1 - 10 >= 0)
			{
				if(Cell[x1 - 9].status != 0) return false;
			}

			Cell[x1].status = 2;
			Cell[x1 + 10].status = 2;
			Cell[x1 + 20].status = 2;
			return true;
		}
		else return false;

	}

	//Написал
	if (num == 2)
	{
		if ((x1 - x1 % 10) == (x2 - x2 % 10))
		{
			//Корабль расположен по горизонтали

			if (x2 - x1 != 1) return false;

			if (x1 - 10 >= 0)
			{
				if (Cell[x1 - 10].status != 0) return false;
				if (Cell[x1 - 9].status != 0)  return false;
			}
			if (x2 + 10 < 100)
			{
				if (Cell[x2 + 10].status != 0) return false;
				if (Cell[x2 + 9].status != 0)  return false;
			}
			if ((x1 - 1 - (x1 - 1) % 10 == x1 - x1 % 10) && x1 != 0)
			{
				if (Cell[x1 - 1].status != 0) return false;
			}
			if ((x2 + 1 - (x2 + 1) % 10 == x2 - x2 % 10) && x2 != 99)
			{
				if (Cell[x2 + 1].status != 0) return false;
			}


			if ((x1 - 11 >= 0) && (x1 - 11 - (x1 - 11) % 10 == x1 - 10 - (x1 - 10) % 10))
			{
				if (Cell[x1 - 11].status != 0) return false;
			}
			if ((x1 + 9 < 100) && (x1 + 9 - (x1 + 9) % 10 == x1 + 10 - (x1 + 10) % 10))
			{
				if (Cell[x1 + 9].status != 0) return false;
			}
			if ((x2 - 9 >= 0) && (x2 - 9 - (x2 - 9) % 10 == x2 - 10 - (x2 - 10) % 10))
			{
				if (Cell[x2 - 9].status != 0) return false;
			}
			if ((x2 + 11 < 100) && (x2 + 11 - (x2 + 11) % 10 == x2 + 10 - (x2 + 10) % 10))
			{
				if (Cell[x2 + 11].status != 0) return false;
			}

			Cell[x1].status = 2;
			Cell[x1 + 1].status = 2;
			return true;
		}
		else if (x1 % 10 == x2 % 10)
		{
			//Корабль расположен по вертикали

			if (x2 - x1 != 10) return false;

			if (x1 - 10 >= 0)
			{
				if (Cell[x1 - 10].status != 0) return false;
			}
			if (x1 - 10 >= 0 && x1 % 10 != 0)
			{
				if (Cell[x1 - 11].status != 0) return false;
			}
			if (x1 % 10 != 0)
			{
				if (Cell[x1 - 1].status != 0) return false;
				if (Cell[x1 + 9].status != 0) return false;
			}
			if (x2 + 10 < 100 && x2 % 10 != 0)
			{
				if (Cell[x2 + 9].status != 0) return false;
			}
			if (x2 + 10 < 100)
			{
				if (Cell[x2 + 10].status != 0) return false;
			}
			if (x2 % 10 != 9 && x2 + 10 < 100)
			{
				if (Cell[x2 + 11].status != 0) return false;
			}
			if (x2 % 10 != 9)
			{
				if (Cell[x1 + 1].status != 0) return false;
				if (Cell[x1 + 11].status != 0) return false;
			}
			if (x1 % 10 != 9 && x1 - 10 >= 0)
			{
				if (Cell[x1 - 9].status != 0) return false;
			}

			Cell[x1].status = 2;
			Cell[x1 + 10].status = 2;
			return true;
		}
		else return false;
	}

	//Написал
	if (num == 1)
	{
			if (X1 - 10 >= 0)
			{
				if (Cell[X1 - 10].status != 0) return false;
			}
			if (X1 + 10 < 100)
			{
				if (Cell[X1 + 10].status != 0) return false;
			}
			if ((X1 - 1 - (X1 - 1) % 10 == X1 - X1 % 10) && X1 != 0)
			{
				if (Cell[X1 - 1].status != 0) return false;
			}
			if ((X1 + 1 - (X1 + 1) % 10 == X1 - X1 % 10) && X1 != 99)
			{
				if (Cell[X1 + 1].status != 0) return false;
			}


			if ((X1 - 11 >= 0) && (X1 - 11 - (X1 - 11) % 10 == X1 - 10 - (X1 - 10) % 10))
			{
				if (Cell[X1 - 11].status != 0) return false;
			}
			if ((X1 + 9 < 100) && (X1 + 9 - (X1 + 9) % 10 == X1 + 10 - (X1 + 10) % 10))
			{
				if (Cell[X1 + 9].status != 0) return false;
			}
			if ((X1 - 9 >= 0) && (X1 - 9 - (X1 - 9) % 10 == X1 - 10 - (X1 - 10) % 10))
			{
				if (Cell[X1 - 9].status != 0) return false;
			}
			if ((X1 + 11 < 100) && (X1 + 11 - (X1 + 11) % 10 == X1 + 10 - (X1 + 10) % 10))
			{
				if (Cell[X1 + 11].status != 0) return false;
			}

			Cell[X1].status = 2;
		return true;
	}
}
//---------------------------------------------------

//---------------------------------------------------
bool Coord(int num)
{
	if (num == 2)
	{
		char c1, c2, str[10];
		int x1, x2, y1, y2;
		scanf("%s", str);
		if (!sscanf(str, "%c%u-%c%u", &c1, &y1, &c2, &y2)) return false;
		c1 = toupper(c1);
		c2 = toupper(c2);
		x1 = (int)c1 - 64;
		x2 = (int)c2 - 64;
		if(x1<1 || x1>10 || x2 < 1 || x2>10 || y1 < 1 || y1>10 || y2 < 1 || y2>10 ) return false;
		X1 = (y1 - 1) * 10 + x1-1;
		X2 = (y2 - 1) * 10 + x2-1;
		if(X1 == X2) return false;
	}
	else
	{
		char c1, str[10];
		int x1, y1;
		scanf("%s", str);
		if (!sscanf(str, "%c%u", &c1, &y1)) return false;
		c1 = toupper(c1);
		x1 = (int)c1 - 64;
		if (x1 < 1 || x1>10 || y1 < 1 || y1>10) return false;
		X1 = (y1 - 1) * 10 + x1-1;
	}
	return true;
}
//---------------------------------------------------

//---------------------------------------------------
void Draw(Cells * Cell, bool Flag = true)
{
	if(Flag) system("cls");
	if(Flag) printf("                            Ваше поле\n");
	else     printf("                            Поле бота\n");
	printf("     A     B     C     D     E     F     G     H     I     J\n");
	printf("  |-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|\n");
	//---------------------------------------------------
	for (unsigned i = 0; i < 10; i++)
	{
		if(i+1<10) printf(" %d", i+1);
		else printf("%d", i+1);
		printf("|");
		//Выводим клетки
		//---------------------------------------------------
		for (unsigned j = 0; j < 10; j++)   
		{
			switch (Cell[i*10 + j].status)
			{
			case(0): 
				printf("     |");
				break;
			case(1):
				if (!Flag)
				{
					printf("     |");
					break;
				}
				printf(" XXX |");
				break;
			case(2):
				printf(" ### |");
				break;
			case(3): 
				printf("  M  |");
				break;
			}
		}
		printf("\n");
		printf("  |-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|\n");
	}
	printf("\n");
	//printf("|");
	//printf("     |");
	//printf(" ### |");
	//printf(" XXX |");
	//printf("  M  |");
	//printf("\n");
}
//---------------------------------------------------

//---------------------------------------------------
void Start_Player(Cells * Cells_Player)
{
	while (Count_P != 4)
	{
		Draw(Cells_Player);
		printf("Введите координаты четырёхпалубника\nПример: A1-A4\n");
		if(!Coord(2)) continue;
		if (!Logic(4, Cells_Player)) continue;
		Count_P = 4;
	}
	while (Count_P != 10)
	{
		Draw(Cells_Player);
		printf("Введите координаты трёхпалубников(по одному)\nПример: A1-A3\n");
		if (!Coord(2)) continue;
		if (!Logic(3, Cells_Player)) continue;
		Count_P += 3;
	}
	while (Count_P != 16)
	{
		Draw(Cells_Player);
		printf("Введите координаты двухпалубников(по одному)\nПример: A1-A2\n");
		if (!Coord(2)) continue;
		if (!Logic(2, Cells_Player)) continue;
		Count_P += 2;
	}
	while (Count_P != 20)
	{
		Draw(Cells_Player);
		printf("Введите координаты однопалубников(по одному)\nПример: A1\n");
		if (!Coord(1)) continue;
		if (!Logic(1, Cells_Player)) continue;
		Count_P++;
	}
}
//---------------------------------------------------

//---------------------------------------------------
void Start_Bot(Cells* Cells_Bot)
{
	bool vector;
	//True - горизонталь
	//False - вертикаль

	while (Count_B != 4)
	{
		vector = URAND(2);
		X1 = URAND(100);
		if (vector && X1 + 3 >= 100) continue;
		else if(!vector && X1 + 30 >= 100) continue;
		if (vector && ((X1 - X1%10) != (X1 + 3 - (X1+3)%10))) continue;
		else if(!vector && (X1 % 10 != (X1 + 30) % 10)) continue;
		if (vector) X2 = X1 + 3;
		else X2 = X1 + 30;
		if (!Logic(4, Cells_Bot)) continue;
		Count_B = 4;
		printf("%d %d\n", X1, X2);
	}
	while (Count_B != 10)
	{
		vector = URAND(2);
		X1 = URAND(100);
		if (vector && X1 + 2 >= 100) continue;
		else if (!vector && X1 + 20 >= 100) continue;
		if (vector && ((X1 - X1 % 10) != (X1 + 2 - (X1 + 2) % 10))) continue;
		else if (!vector && (X1 % 10 != (X1 + 20) % 10)) continue;
		if (vector) X2 = X1 + 2;
		else X2 = X1 + 20;
		if (!Logic(3, Cells_Bot)) continue;
		Count_B += 3;
		printf("%d %d\n", X1, X2);
	}
	while (Count_B != 16)
	{
		vector = URAND(2);
		X1 = URAND(100);
		if (vector && X1 + 1 >= 100) continue;
		else if (!vector && X1 + 10 >= 100) continue;
		if (vector && ((X1 - X1 % 10) != (X1 + 1 - (X1 + 1) % 10))) continue;
		else if (!vector && (X1 % 10 != (X1 + 10) % 10)) continue;
		if (vector) X2 = X1 + 1;
		else X2 = X1 + 10;
		if (!Logic(2, Cells_Bot)) continue;
		Count_B += 2;
		printf("%d %d\n", X1, X2);
	}
	while (Count_B != 20)
	{
		X1 = URAND(100);
		if (!Logic(1, Cells_Bot)) continue;
		Count_B++;
		printf("%d\n", X1);
	}
}
//---------------------------------------------------

//---------------------------------------------------
void Game()
{
	Cells Cells_Player[100], Cells_Bot[100];
	//Инициализация массивов
	for (unsigned i = 0; i < 100; i++)
	{
		Cells_Player[i].Coord = i;
		Cells_Bot[i].Coord = i;
	}

	//Start_Player(Cells_Player);
	Start_Bot(Cells_Bot);

	//Draw(Cells_Player); //Временно 
	Draw(Cells_Bot); //Временно

//	while (Count_P && Count_B)
//	{

//	}

	//Конец игры
	Count_P = Count_B = 0;
	//Результат

	system("pause");
}
//---------------------------------------------------

//---------------------------------------------------
void menu()
{
	unsigned choise(0);
	system("cls");
	_tprintf(t("%s"), t("Добро пожаловать!\n\n"));
	_tprintf(t("%s"), t("(1)Новая игра\n"));
	_tprintf(t("%s"), t("(2)О разработчике\n"));
	_tprintf(t("%s"), t("(0)Выход\n"));
	_tprintf(t("%s"), t("Ваш выбор: "));
	char str[10];
	scanf("%s", str);
	if (!sscanf(str, "%u", &choise)) return;
	switch (choise)
	{
	case(1): 
	{
		Game();
		break;
	}
	case(2):
	{
		system("cls");
		_tprintf(t("%s"), t("Ждите в следующих версиях!\n")); //Позже добавим
		system("pause");
		break;
	}
	case(0): exit(EXIT_SUCCESS);
	default:
		return;
	}
}
//---------------------------------------------------

void _tmain()
{
	system("title Морской бой v0.3");
	system("color A");
	_tsetlocale(LC_ALL, t("rus"));
	srand((unsigned)time(NULL));
	while(true) menu();
	exit(EXIT_SUCCESS);
}


//Эксперимент
//Четырёхпалубник
//   |-----|
//   | ... |
//   |-----|
//   | XXX |
//   |-----|
//   | ### |
//   |-----|
//   |  M  |
//   |-----|