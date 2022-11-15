#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



void RandomFillArray(int** arr, int rows, int cols);
void Show2DArray(int** arr, int rows, int cols);
void From2Dto1D(int** arr, int* arr_general, int rows, int cols, int temp);
void Show1DArray(int* arr, int size);
void CommonArrayAC(int* arr1, int* arr2, int size1, int size2, int* arr3);
void NegativeCommonArray(int* arr1, int* arr2, int* arr3, int size1, int size2, int size3, int* arr_general_negative, int size_gen);
void CommonArray(int* arr1, int* arr2, int* arr3, int size1, int size2, int size3, int* arr_general, int size);
void UniqElem(int* arr, int size, int* arr_uniq, int size_uniq);
void From2to1Array(int* arr1, int* arr2, int* arr3, int size1, int size2, int size3);
void DeleteArrays(int* arrA, int* arrB, int* arrC, int* arrA_general, int* arrB_general, int* arrC_general,
	int* arrAB_general, int* arrAC_general, int* arrABC_general, int* arrABC_uniq, int* arr_general_negative,
	int* arr_general);


int main()
{
	srand(time(NULL));

	int rowsA, rowsB, rowsC;
	int colsA, colsB, colsC;
	int sizeA = 0;

	cout << "Enter rows for A, B, C: ";
	cin >> rowsA >> rowsB >> rowsC;

	cout << "Enter cols for A, B, C: ";
	cin >> colsA >> colsB >> colsC;

	int** arrA = new int* [rowsA];
	for (int i = 0; i < rowsA; i++)
	{
		arrA[i] = new int[colsA];
	}

	int** arrB = new int* [rowsB];
	for (int i = 0; i < rowsB; i++)
	{
		arrB[i] = new int[colsB];
	}

	int** arrC = new int* [rowsC];
	for (int i = 0; i < rowsC; i++)
	{
		arrC[i] = new int[colsC];
	}

	RandomFillArray(arrA, rowsA, colsA);
	RandomFillArray(arrB, rowsB, colsB);
	RandomFillArray(arrC, rowsC, colsC);

	cout << "\n";
	Show2DArray(arrA, rowsA, colsA);
	cout << "\n";
	Show2DArray(arrB, rowsB, colsB);
	cout << "\n";
	Show2DArray(arrC, rowsC, colsC);

	int* arrA_general = new int[(colsA * rowsA)];
	int* arrB_general = new int[(colsB * rowsB)];
	int* arrC_general = new int[(colsC * rowsC)];
	int temp = 0;

	From2Dto1D(arrA, arrA_general, rowsA, colsA, temp);
	From2Dto1D(arrB, arrB_general, rowsB, colsB, temp);
	From2Dto1D(arrC, arrC_general, rowsC, colsC, temp);

	cout << "\n";

	int sizeAB = (colsA * rowsA) + (colsB * rowsB);
	int* arrAB_general = new int[sizeAB];

	From2to1Array(arrA_general, arrB_general, arrAB_general, rowsA * colsA, rowsB * colsB, sizeAB);

	int sizeABC = sizeAB + colsC * rowsC;
	int* arrABC_general = new int[sizeABC];

	From2to1Array(arrAB_general, arrC_general, arrABC_general, sizeAB, rowsC * colsC, sizeABC);
	cout << "\n";

	int size_uniq = 0;
	int* arrABC_uniq = new int[size_uniq];

	UniqElem(arrABC_general, sizeABC, arrABC_uniq, size_uniq);
	cout << "\n";


	int size_arrAC_general = 0;
	int* arrAC_general = new int[size_arrAC_general];

	CommonArrayAC(arrA_general, arrC_general, colsA * rowsA, colsC * rowsC, arrAC_general);
	cout << "\n";

	int size_arr_general_negative = 0;
	int* arr_general_negative = new int[size_arr_general_negative];

	NegativeCommonArray(arrA_general, arrB_general, arrC_general, rowsA * colsA, rowsB * colsB, rowsC * colsC, arr_general_negative, size_arr_general_negative);
	cout << "\n";

	int size = 0;
	int* arr_general = new int[size];

	CommonArray(arrA_general, arrB_general, arrC_general, rowsA * colsA, rowsB * colsB, rowsC * colsC, arr_general, size);
	cout << "\n";

	DeleteArrays(*arrA, *arrB, *arrC, arrA_general, arrB_general, arrC_general,
		arrAB_general, arrAC_general, arrABC_general, arrABC_uniq, arr_general_negative,
		arr_general);
}

void RandomFillArray(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int num = rand() % 21 - 10;
			arr[i][j] = num;
		}
	}
}

void Show2DArray(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

void From2Dto1D(int** arr, int* arr_general, int rows, int cols, int temp)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr_general[temp] = arr[i][j];
			temp++;
		}
	}
}

void Show1DArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

void CommonArrayAC(int* arr1, int* arr2, int size1, int size2, int* arr3)
{
	int size3 = 0;

	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (arr1[i] == arr2[j])
			{
				arr3[size3] = arr1[i];
				size3++;
			}
		}
	}

	cout << "Array with common elements for A and C: ";

	for (int i = 0; i < size3; i++)
	{
		cout << arr3[i] << " ";
	}
}

void NegativeCommonArray(int* arr1, int* arr2, int* arr3, int size1, int size2, int size3, int* arr_general_negative, int size_gen)
{
	int general_num;

	for (int i = 0; i < size1; i++)
	{
		if (arr1[i] < 0)
		{
			for (int j = 0; j < size2; j++)
			{
				if (arr1[i] == arr2[j])
				{
					general_num = arr2[j];

					for (int k = 0; k < size3; k++)
					{
						if (general_num == arr3[k])
						{
							arr_general_negative[size_gen] = general_num;
							size_gen++;
						}
					}
				}
			}
		}
	}

	int* check_arr = new int[size_gen];

	for (int i = 0; i < size_gen; i++)
	{
		check_arr[i] = -1;
	}

	bool check = false;
	int count = 0;

	for (int i = 0; i < size_gen; i++)
	{
		for (int j = 0; j < size_gen; j++)
		{
			if (i == check_arr[j])
			{
				check = false;
				break;
			}
			else
			{
				check = true;
			}
		}
		if (check)
		{
			for (int k = i; k < size_gen - 1; k++)
			{
				if (arr_general_negative[i] == arr_general_negative[k + 1])
				{
					check_arr[count] = k + 1;
					count++;
				}
			}
		}
	}

	int temp = 0;
	for (int i = 0; i < count; i++)
	{
		for (int j = (count - 1); i >= (i + 1); i--)
		{
			if (check_arr[j] < check_arr[j - 1])
			{
				temp = check_arr[j];
				check_arr[j] = check_arr[j - 1];
				check_arr[j - 1] = temp;
			}
		}
	}

	int* new_arr = new int[size_gen - count];
	int num1 = 0, num2 = 0;

	for (int i = 0; i < count; i++)
	{
		for (int j = num1; j < check_arr[i]; j++)
		{
			new_arr[num2] = arr_general_negative[j];
			num2++;
		}
		num1 = check_arr[i] + 1;
	}

	cout << "Array with common negative elements for all: ";

	for (int i = 0; i < size_gen - count; i++)
	{
		cout << new_arr[i] << " ";
	}
}

void CommonArray(int* arr1, int* arr2, int* arr3, int size1, int size2, int size3, int* arr_general, int size)
{
	int general_num;

	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (arr2[j] == arr1[i])
			{
				general_num = arr2[j];
				for (int k = 0; k < size3; k++)
				{
					if (general_num == arr3[k])
					{
						arr_general[size] = general_num;
						size++;
					}
				}
			}
		}
	}

	cout << "Array with common elements for all: ";

	for (int i = 0; i < size; i++)
	{
		cout << arr_general[i] << " ";
	}
}

void UniqElem(int* arr, int size, int* arr_uniq, int size_uniq)
{
	for (int i = 0; i < size; ++i)
	{
		int currentElementValue = arr[i];
		bool hasEquals = false;

		for (int j = 0; j < size; j++)
		{
			if (i == j)
			{
				continue;
			}

			if (currentElementValue == arr[j] && i != j)
			{
				hasEquals = true;
			}
		}
		if (!hasEquals)
		{
			arr_uniq[size_uniq] = currentElementValue;
			size_uniq++;
		}
	}

	cout << "Array with unique elements: ";
	for (int i = 0; i < size_uniq; i++)
	{
		cout << arr_uniq[i] << " ";
	}
}

void From2to1Array(int* arr1, int* arr2, int* arr3, int size1, int size2, int size3)
{
	for (int i = 0; i < size1; i++)
	{
		arr3[i] = arr1[i];
	}

	for (int i = size1; i < size3; i++)
	{
		arr3[i] = arr2[i - size1];
	}
}

void DeleteArrays(int* arrA, int* arrB, int* arrC, int* arrA_general, int* arrB_general, int* arrC_general,
	int* arrAB_general, int* arrAC_general, int* arrABC_general, int* arrABC_uniq, int* arr_general_negative,
	int* arr_general)
{
	/*delete[] arrABC_uniq;
	delete[] arr_general_negative;
	delete[] arr_general;
	delete[] arrA;
	delete[] arrB;
	delete[] arrC;
	delete[] arrA_general;
	delete[] arrB_general;
	delete[] arrC_general;
	delete[] arrAB_general;
	delete[] arrAC_general;
	delete[] arrABC_general;*/
}
////-------------------------------------------------------------------------