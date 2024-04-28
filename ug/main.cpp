#include <iostream>
#include <algorithm>
#include <string>

int LeapYearCheck(int year)	//первое задание
{
	if (year % 4 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int DateGapCalc(int frst_year, int frst_month, int frst_day, int scnd_year, int scnd_month, int scnd_day)
{
	int result = 0;
	int day_list[13]{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (scnd_year > frst_year)	//normalization
	{
		std::swap(frst_year, scnd_year);
		std::swap(frst_month, scnd_month);
		std::swap(frst_day, scnd_day);
	}

	if (frst_year == scnd_year)	//edge case
	{

		if (frst_month == scnd_month)	//edge case
		{
			result = std::abs(frst_day - scnd_day);
			if (frst_month == 2 && LeapYearCheck(frst_year) == 1 && std::max(scnd_day, frst_day) == 29)	//leap adjustment
			{
				result++;
			}
		}
		else
		{
			if (scnd_month > frst_month)	//normalization
			{
				std::swap(frst_month, scnd_month);
				std::swap(frst_day, scnd_day);
			}

			for (int i = frst_month; i < scnd_month; i++)
			{
				result += day_list[i];
			}
			result -= (frst_day + scnd_day);

			if (frst_month < 3 && LeapYearCheck(frst_year) == 1 && scnd_month > 2)	//leap adjustment
			{
				result++;
			}
		}

	}
	else
	{
		for (int i = frst_month; i <= 12; i++)	//frst_year
		{
			result += day_list[i];
		}
		for (int i = 1; i <= scnd_month; i++)	//scnd_year
		{
			result += day_list[i];
		}

		if (frst_month < 3 && LeapYearCheck(frst_year) == 1)	//leap adjustment
		{
			result++;
		}
		if (scnd_month < 3 && LeapYearCheck(scnd_year) == 1)
		{
			result++;
		}

		result += (frst_year - scnd_year - 1) * 365 + (frst_year - scnd_year) / 4;	//in between years calculation
	}

	return result;
}

double ArifAverage(int arr[], double size)	//второе задание
{
	double result = 0;

	for (int i = 0; i < size; i++)
	{
		result += double(arr[i]);
	}

	return result / double(size);
}

void ArrayNumTypeCount(int arr[], int size)	//третье задание
{
	int zero_count = 0, pos_count = 0, neg_count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0)
		{
			pos_count++;
		}
		else if (arr[i] < 0)
		{
			neg_count++;
		}
		else
		{
			zero_count++;
		}
	}

	std::cout << "ѕоложительных чисел: " << pos_count << "\nќтрицательных чисел: " << neg_count << "\nЌулей: " << zero_count << "\n";

}



void CreateSqrMtrx(int**& arr, int side)		//четвертое задание
{
	arr = new int* [side];
	for (int i = 0; i < side; i++)
	{
		arr[i] = new int[side];
	}
}
void CreateSqrMtrx(double**& arr, int side)
{
	arr = new double* [side];
	for (int i = 0; i < side; i++)
	{
		arr[i] = new double[side];
	}
}
void CreateSqrMtrx(char**& arr, int side)
{
	arr = new char* [side];
	for (int i = 0; i < side; i++)
	{
		arr[i] = new char[side];
	}
}
void DeleteSqrMtrx(int**& arr, int side)
{
	for (int i = 0; i < side; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}
void DeleteSqrMtrx(double**& arr, int side)
{
	for (int i = 0; i < side; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}
void DeleteSqrMtrx(char**& arr, int side)
{
	for (int i = 0; i < side; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}
void FillSqrMtrx(int**& arr, int side, std::string overload_type = "int")
{
	if (overload_type == "int")
	{
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				arr[i][j] = rand() % 1000;
			}
		}
	}
	else if (overload_type == "double")
	{
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				arr[i][j] = (rand() % 10000) / 10.0;
			}
		}
	}
	else if (overload_type == "char")
	{
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				arr[i][j] = char(rand() % 126);
			}
		}
	}
	else
	{
		std::cerr << "Error: incorrect function overload type\n";
	}
	
}
void PrintSqrMtrx(int**& arr, int side)
{
	for (int i = 0; i < side; i++)
	{
		for (int j = 0; j < side; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << "\n\n";
	}
}
int MaxSqrMtrx(int**& arr, int side)
{
	int result = arr[0][0];
	for (int i = 1, j = 1; i < side; i++, j++)
	{
		if (result > arr[i][j])
		{
			result = arr[i][j];
		}
	}
	return result;
}
double MaxSqrMtrx(double**& arr, int side)
{
	double result = arr[0][0];
	for (int i = 1, j = 1; i < side; i++, j++)
	{
		if (result > arr[i][j])
		{
			result = arr[i][j];
		}
	}
	return result;
}
char MaxSqrMtrx(char**& arr, int side)
{
	int result = int(arr[0][0]);
	for (int i = 1, j = 1; i < side; i++, j++)
	{
		if (result > int(arr[i][j]))
		{
			result = int(arr[i][j]);
		}
	}
	return char(result);
}
int MinSqrMtrx(int**& arr, int side)
{
	int result = arr[0][0];
	for (int i = 1, j = 1; i < side; i++, j++)
	{
		if (result < arr[i][j])
		{
			result = arr[i][j];
		}
	}
	return result;
}
double MinSqrMtrx(double**& arr, int side)
{
	double result = arr[0][0];
	for (int i = 1, j = 1; i < side; i++, j++)
	{
		if (result < arr[i][j])
		{
			result = arr[i][j];
		}
	}
	return result;
}
char MinSqrMtrx(char**& arr, int side)
{
	int result = int(arr[0][0]);
	for (int i = 1, j = 1; i < side; i++, j++)
	{
		if (result < int(arr[i][j]))
		{
			result = int(arr[i][j]);
		}
	}
	return char(result);
}
void SortSqrMtrx(int**& arr, int side)
{
	for (int i = 0; i < side; i++)
	{
		std::sort(arr[i], arr[i] + side);
	}
}


int CommonDevis(int num1, int num2, int div = 0)	//п€тое задание
{
	if (div == 0)
	{
		div = std::min(num1, num2);
	}

	if (num1 % div == 0 && num2 % div == 0)
	{
		return div;
	}
	else
	{
		div--;
		CommonDevis(num1, num2, div);
	}
}

int BullsAndCows(std::string guess_num = "", int tries = 0)	//шестое задание
{
	int r_num = 0, r_place = 0;
	std::string u_inp;
	
	
	if (guess_num == "")
	{
		guess_num = std::to_string(1000 + rand() % 9000);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	while (true)
	{
		std::cout << "¬ведите четырехзначное число: ";
		std::getline(std::cin, u_inp, '\n');

		for (int i = 0; i < 4; i++)
		{
			if (int(u_inp[i]) < 48 || int(u_inp[i]) > 57)
			{
				std::cerr << "Error: incorrect input choice\n";
				continue;
			}
		}
		break;
	}

	std::string norepeat_str = "";

	if (u_inp == guess_num)
	{
		std::cout << "¬ы выиграли\n";
		return tries;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (u_inp[i] == guess_num[j])
			{
				bool is_repeat = false;
				for (int v = 0; v < norepeat_str.length(); v++)
				{
					if (u_inp[i] == norepeat_str[v])
					{
						is_repeat = true;
					}
				}
				if (is_repeat == false)
				{
					norepeat_str += u_inp[i];
					r_num++;
				}
			}
		}
		if (u_inp[i] == guess_num[i])
		{
			r_place++;
		}
	}
	
	std::cout << "Ѕыки: " << r_num << '\n';
	std::cout << " оровы: " << r_place << '\n';

	BullsAndCows(guess_num, tries);

}


int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "ru");



	std::cout << "ѕервое задание\n";
	int frst_year, frst_month, frst_day;	//первое задание
	int scnd_year, scnd_month, scnd_day;
	int day_list[13]{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	bool exit = true;


	do
	{
		exit = true;

		std::cout << "¬ведите первый год: ";
		std::cin >> frst_year;
		std::cout << "¬ведите первый мес€ц: ";
		std::cin >> frst_month;
		std::cout << "¬ведите первый день: ";
		std::cin >> frst_day;

		std::cout << "¬ведите второй год: ";
		std::cin >> scnd_year;
		std::cout << "¬ведите второй мес€ц: ";
		std::cin >> scnd_month;
		std::cout << "¬ведите второй день: ";
		std::cin >> scnd_day;

		if (frst_year <= 0 || frst_month <= 0 || frst_day <= 0 || scnd_year <= 0 || scnd_month <= 0 || scnd_day <= 0)	//valid int check
		{
			std::cerr << "ќшибка: введЄнно негативное число или 0\n";
			exit = false;

		}

		if (frst_month > 12 || scnd_month > 12)	//valid month check
		{
			std::cerr << "ќшибка: значение мес€ца больше 12\n";
			exit = false;
		}

		if (frst_month == 2 && LeapYearCheck(frst_year) == 1)	//valid day check
		{
			if (frst_day > 29)
			{
				std::cerr << "ќшибка: значение дн€ больше доступного в мес€це\n";
				exit = false;
			}
		}
		else if (scnd_month == 2 && LeapYearCheck(scnd_year) == 1)
		{
			if (scnd_day > 29)
			{
				std::cerr << "ќшибка: значение дн€ больше доступного в мес€це\n";
				exit = false;
			}
		}
		else if (frst_day > day_list[frst_month] || scnd_day > day_list[scnd_month])
		{
			std::cerr << "ќшибка: значение дн€ больше доступного в мес€це\n";
			exit = false;
		}
	} while (!exit);

	std::cout << DateGapCalc(frst_year, frst_month, frst_day, scnd_year, scnd_month, scnd_day) << "\n\n";
	

	std::cout << "¬торое задание\n";
	int arr2[10];
	for (int i = 0; i < 10; i++)
	{
		arr2[i] = rand() % 50;

	}
	ArifAverage(arr2, 10);



	std::cout << "“ретье задание\n";
	int arr3[10];
	for (int i = 0; i < 10; i++)
	{
		if (rand() % 2 == 1)
		{
			arr3[i] = -100 + rand() % 201;
		}
		else
		{
			arr3[i] = 0;
		}
		
	}
	ArrayNumTypeCount(arr3, 10);

	

	std::cout << "„етвЄртое задание\n";	//четвертое заадние
	int size = 5;
	int** arr;
	CreateSqrMtrx(arr, size);
	FillSqrMtrx(arr, size);
	PrintSqrMtrx(arr, size);
	std::cout << "\n" << MaxSqrMtrx(arr, size);
	std::cout << "  " << MinSqrMtrx(arr, size) << "\n\n\n";
	SortSqrMtrx(arr, size);
	PrintSqrMtrx(arr, size);
	DeleteSqrMtrx(arr, size);


	std::cout << "ѕ€тое задание\n";	//п€тое задание
	int choice1, choice2;
	std::cout << "¬ведите первое число: ";
	std::cin >> choice1;
	std::cout << "¬ведите второе число: ";
	std::cin >> choice2;
	std::cout << CommonDevis(choice1, choice2) << '\n';


	std::cout << "Ўестое задание\n";	//шестое задание
	BullsAndCows();


	return 0;
}