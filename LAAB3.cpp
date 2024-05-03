#include <iostream>

template <typename T>//создаем собственный тип

void Sort(T arr[], int sz) {//создаем функцию, наш тип распространяется только на массив, так как работа только с ним
	for (int i = 0; i < sz - 1; ++i) {//передвижэение по массиву
		for (int j = 0; j < sz - i - 1; ++j) {// сортировка
			if (arr[j] > arr[j + 1]) {
				T temp = arr[j];
				arr[j] = arr[j + 1]; 
				arr[j + 1] = temp;
			}
		}
	}
}

int main(void) {
	int a;
	int intarr[] = { 3,45,123,312,64,67,1,2,32,12,3 };
	char chararr[] = { 'g', 'e', 'e', 'k', 's', 'f', 'o', 'r', 'g', 'e', 'e', 'k', 's' };
	

	int sizeintarr = sizeof(intarr) / sizeof(intarr[0]);
	int sizechararr = sizeof(chararr) / sizeof(chararr[0]);


	Sort(intarr, sizeintarr);
	Sort(chararr, sizechararr);


	do {
		system("cls");
		std::cout << "Select func" << std::endl;
		std::cout << "func (1) sort int arr " << std::endl;
		std::cout << "func (2) sort char arr " << std::endl;
		std::cout << "func (3) exit " << std::endl;
		std::cout << "U select - " << std::endl;
		std::cin >> a;

		switch (a)
		{
			case(1):
				
				do {
					system("cls");
					std::cout << "Sort int array: " << std::endl;
					for (int i = 0; i < sizeintarr; ++i) {
						std::cout << intarr[i] << " ";
					}
				} while (getchar() != '\n');
				break;

			case(2):
				do {
					system("cls");
					std::cout << "Sort char array: " << std::endl;
					for (int i = 0; i < sizechararr; ++i) {
						std::cout << chararr[i] << " ";
					}
				} while (getchar() != '\n');
				break;

			case(3):
				system("cls");
				std::cout << "Bye!" << std::endl;
				return 1;
		}

	} while (getchar() != 3);


	return 0;
}