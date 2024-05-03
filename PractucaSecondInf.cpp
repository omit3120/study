
#include <iostream>
#include <string>






class Toy {
protected:
	std::string NameOfToy;
	std::string Tematica;
	int lowerAgeReg;
	int highAgeReg;
	int priceOfToy;

	int point = 0;
public:

	Toy() {
		NameOfToy = "---";
		Tematica = "---";
		lowerAgeReg = 2; 
		highAgeReg = 5;
		priceOfToy = 1000;
	}
	//конструктор с параметрами
	Toy(std::string _NameOfToy, std::string _Tematica, int _lowerAgeReg, int _highAgeReg, int _priceOfToy) {
		this->NameOfToy = _NameOfToy;
		this->Tematica = _Tematica;
		if (_lowerAgeReg < 0) {
			std::cout << "Нижний уровень возрастного ограничения не может быть меньше 0" << std::endl;
			std::cout << "Нижний уровень ворзрасного ограничения будет установлен автоматически" << std::endl;
			this->lowerAgeReg = 0;
		}

		if (_highAgeReg == lowerAgeReg || _highAgeReg <= 0) {
			std::cout << "" << std::endl;
			std::cout << "" << std::endl;
			this->highAgeReg = 99;
		}
		this->lowerAgeReg = _lowerAgeReg;
		this->highAgeReg = _highAgeReg;

		this->priceOfToy = _priceOfToy;

	}

	~Toy() {//деструктор

	}

	virtual void outPutName() {//название класса виртуальной функцией для дальнейшего переопределения
		std::cout << "Class name - \"Toy\"";
	}

	void SetNameOfToy(std::string Name) {
		this->NameOfToy = Name;
	}

	void SetTematica(std::string Tematic) {
		this->Tematica = Tematic;
	}

	void SetlowerAgeReg(int lowerReg) {
		this->lowerAgeReg = lowerReg;
	}

	void SethighAgeReg(int highReg) {

		this->highAgeReg = highReg;
	}

	void SetPrice(int price) {
		this->priceOfToy = price;
	}

	std::string GetNameOfToy() {
		return this->NameOfToy;
	}

	std::string GetTematica() {
		return this->Tematica;
	}

	int GetlowerAgeReg() {
		return this->lowerAgeReg;
	}

	int GethighAgeReg() {
		return this->highAgeReg;

	}
	int GetPrice() {
		return this->priceOfToy;
	}
	// виртуальнафя функция для игры в игрушку основной класс
	virtual void Play() {
		std::cout << "---Вы играете с игрушкой---" << std::endl;
	}

	virtual void unpucking() {
		std::cout << "---Достаем игрушку---" << std::endl;
	}

	virtual void clearUp() {
		std::cout << "---Вы убрaли игрушку---" << std::endl;
	}
	//информация по игрушке
	virtual void Information() {
		std::cout << "information" << std::endl;
		std::cout << "Название игрушки - " << GetNameOfToy() << std::endl;
		std::cout << "Тематика - " << GetTematica() << std::endl;
		std::cout << "Возрастные ограничения от" << GetlowerAgeReg() << "до" << GethighAgeReg() << std::endl;
		std::cout << "Цена - " << GetPrice() << std::endl;

	}


	virtual int Inil() {
		return point;
	}
};



class Constructor : public Toy {
private:
	std::string manufacturer;
	int point = 1;
public:
	

	//конструктор 
	Constructor() : Toy() {
		manufacturer = "Просто китайские дети";
	}
	//using Toy::Toy;
	Constructor(std::string _NameOfToy, std::string _Tematica, int _LowerAgeReg, int _HighAgeReg, int _PriceOfToy, std::string _manufacturer) :Toy(_NameOfToy, _Tematica, _LowerAgeReg, _HighAgeReg, _PriceOfToy) {
		this->manufacturer = _manufacturer;

	}
	
	//деструктор
	~Constructor (){}

	std::string GetManufacturer() {
		return manufacturer;
	}

	void SetManufacturer(std::string manufactura) {
		this->manufacturer = manufactura;

	}

	void Information() {
		std::cout << "information" << std::endl;
		std::cout << "Название игрушки - " << GetNameOfToy() << std::endl;
		std::cout << "Тематика - " << GetTematica() << std::endl;
		std::cout << "Возрастные ограничения от " << GetlowerAgeReg() << " до " << GethighAgeReg() << std::endl;
		std::cout << "Цена - " << GetPrice() << std::endl;
		std::cout << "Производиель - " << GetManufacturer() << std::endl;

	}

	void outPutName() override {
		std::cout << "Class name - \"Constructor\" "<< std::endl;
	}

	void Play() override{
		std::cout << "---Вы играете с игрушкой---" << std::endl;
	}

	void unpucking() override{
		std::cout << "---Достаем игрушку---" << std::endl;
	}

	void clearUp() override{
		std::cout << "---Вы убрали игрушку---" << std::endl;
	}

	int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		// Равномерно распределяем рандомное число в нашем диапазоне
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	void Drpcetail() {
		std::cout << "Когда вы отходили покушать, то ваш питомец раскидал конструктор" << std::endl;
		std::cout << "Вы потеряли " << getRandomNumber(5, 20) << " деталей" << std::endl;
	}

	virtual int Inil() {
		return point;
	}
};


class Railway : public Toy {
private:
	std::string manufacturer;
	int point = 2;
public:
	Railway() : Toy() {
		manufacturer = "Крутые китайские дети";
	}
	Railway(std::string _NameOfToy, std::string _Tematica, int _LowerAgeReg, int _HighAgeReg, int _PriceOfToy, std::string _manufacturer) :Toy(_NameOfToy, _Tematica, _LowerAgeReg, _HighAgeReg, _PriceOfToy) {
		this->manufacturer = _manufacturer;
	}
	~Railway() {

	}

	void Information() {
		std::cout << "information" << std::endl;
		std::cout << "Название игрушки - " << NameOfToy << std::endl;
		std::cout << "Тематика - " << Tematica << std::endl;
		std::cout << "Возрастные ограничения от " << lowerAgeReg << " до " << highAgeReg << std::endl;
		std::cout << "Цена - " << priceOfToy << std::endl;
		std::cout << "Произвродитель - " << manufacturer << std::endl;

	}

	void outPutName() override {
		std::cout << "Class name - \"Railway\" " << std::endl;
	}

	void Play() override {
		std::cout << "---Вы играете с игрушкой---" << std::endl;
	}

	void unpucking() override {
		std::cout << "---Достаем игрушку---" << std::endl;
	}

	void clearUp() override {
		std::cout << "---Вы убрали игрушку---" << std::endl;
	}

	void chuxchux() {
		std::cout << "Поезд едет" << std::endl;
		for (int i = 0; i < 5; ++i) {
			std::cout << "Чух Чух" << std::endl;
		}
	}
	

	virtual int Inil() {
		return point;
	}
};


class Doll : public Toy {
private:
	std::string NameOfDoll;
	int point = 3;
public:
	Doll() : Toy() {
		NameOfDoll = "Cucla";
	}

	Doll(std::string _NameOfToy, std::string _Tematica, int _LowerAgeReg, int _HighAgeReg, int _PriceOfToy, std::string _nameofdoll) :Toy(_NameOfToy, _Tematica, _LowerAgeReg, _HighAgeReg, _PriceOfToy) {
		this->NameOfDoll = _nameofdoll;
	}


	~Doll() {//деструктор

	}

	void Information() {
		std::cout << "information" << std::endl;
		std::cout << "Название игрушки - " << NameOfToy << std::endl;
		std::cout << "Имя куклы - " << NameOfDoll << std::endl;
		std::cout << "Тематика - " << Tematica << std::endl;
		std::cout << "Возрастные ограничения от " << lowerAgeReg << " до " << highAgeReg << std::endl;
		std::cout << "Цена - " << priceOfToy << std::endl;
	}

	void cry() {
		std::cout << "Вы покормили куклу!" << std::endl;
	}


	void outPutName() override {
		std::cout << "Class name - \"Doll\" " << std::endl;
	}

	void Play() override {
		std::cout << "---Вы играете с игрушкой---" << std::endl;
	}

	void unpucking() override {
		std::cout << "---Достаем игрушку---" << std::endl;
	}

	void clearUp() override {
		std::cout << "---Вы убрали игрушку---" << std::endl;
	}

	virtual int Inil() {
		return point;
	}
		
};


class BoardGame : public Toy {
private:
	std::string GameName;
	int point = 4; 
public:
	BoardGame() : Toy() {
		std::string GameName = "Monopolia";
	}

	BoardGame(std::string _NameOfToy, std::string _Tematica, int _LowerAgeReg, int _HighAgeReg, int _PriceOfToy, std::string _GameName) :Toy(_NameOfToy, _Tematica, _LowerAgeReg, _HighAgeReg, _PriceOfToy) {
		
		this->GameName = _GameName;
	}

	~BoardGame() {

	}
	void Information() {
		std::cout << "information" << std::endl;
		std::cout << "Название игрушки - " << NameOfToy << std::endl;
		std::cout << "Название игры - " << GameName <<  std::endl;
		std::cout << "Тематика - " << Tematica << std::endl;
		std::cout << "Возрастные ограничения от " << lowerAgeReg << " до " << highAgeReg << std::endl;
		std::cout << "Цена - " << priceOfToy << std::endl;
	}

	int getRandomNumber(int min, int max)//функция для броска кубика
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		// Равномерно распределяем рандомное число в нашем диапазоне
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	void TheRollofTheDice() {
		do {
			std::cout << "---Бросаем кубик, нажмите Enter чтобы узнать число---" << std::endl;
		} while (getchar() != '\n');
		std::cout << "После броска выпало: " << getRandomNumber(1,6) <<  std::endl;
	}


	void outPutName() override {
		std::cout << "Class name - \"Boardgame\" " << std::endl;
	}

	void Play() override {
		std::cout << "---Вы играете с игрушкой---" << std::endl;
	}

	void unpucking() override {
		std::cout << "---Достаем игрушку---" << std::endl;
	}

	void clearUp() override {
		std::cout << "---Вы убрали игрушку---" << std::endl;
	}


	virtual int Inil() {
		return point;
	}
	
};


int main()
{
	system("chcp 1251");

	Constructor* p1;
	Railway* p2;
	Doll* p3;
	BoardGame* p4;

	std::string s;
	short N = 0;

	int i, i1, i2, i3, i4, a;
	std::string s1, s2, s3;
	char* end;
	int select = 0;
	Toy* array[10];
	int sel1 = 0, sel2 = 0;

	do {
		system("CLS");
		system("chcp 1251");
		std::cout << "Вас встречает базовый класс \"Игрушка\", который имеет 4 вариаций реализации." << std::endl;
		std::cout << "В этой программе вы можете создавать несколько прототипов + взаимодействовать с ними" << std::endl;
		std::cout << "Чтобы приступить к работе, нажмите Enter " << std::endl;
	} while (getchar() != '\n');

	do {
		system("CLS");
		system("chcp 1251");
		std::cout << "			---MENU---" << std::endl;
		std::cout << "---Создать новую игрушку (1)---" << std::endl;
		std::cout << "---Узнать информацию о созданных игрушках (2)---" << std::endl;
		std::cout << "---Взаимодействовать с созданными игрушками (3)---" << std::endl;
		std::cout << "---Закончить работу (4)---" << std::endl;
		std::cout << "Пункт - " << std::endl;

		std::cin >> select;

		switch (select)
		{
		case (1):
			if (N < 10) {
				system("CLS");
				std::cout << "Список игрушек, которые можно создать" << std::endl;
				std::cout << "Стандартная игрушка (1)" << std::endl;
				std::cout << "Конструктор (2)" << std::endl;
				std::cout << "Железная дорога (3)" << std::endl;
				std::cout << "Кулкла разговаривающая (4)" << std::endl;
				std::cout << "Настольная игра (5)" << std::endl;
				std::cout << "Пункт - " << std::endl;

				std::cin >> s;
				

				sel1 = strtol(s.c_str(), &end, 10);
				if (*end) {
					do {
						std::cout << "Пункта не существует" << std::endl;
						std::cin >> s;
						sel1 = strtol(s.c_str(), &end, 11);
					} while (*end);
				}
				switch (sel1)
				{
				case(1):
					std::cout << "Вы хотите создать класс со своими данными(1) или по умолчанию(2) ?" << std::endl;
					std::cin >> s;
					sel2 = strtol(s.c_str(), &end, 10);
					if (*end || sel2 <= 0 || sel2 >= 3) {
						do
						{
							std::cout << "Такого пункта не существует " << std::endl;
							std::cin >> s;
							sel2 = strtol(s.c_str(), &end, 11);
						} while (*end || sel2 <= 0 || sel2 >= 3);
					}
					if (sel2 == 1) {
						system("cls");
						std::cout << "Начнем заполнение параметров нашей игрушки" << std::endl;
						//записываем название
						std::cout << "Придумайте название игрушки - ";
						std::cin.ignore();
						getline(std::cin, s1);
						//записываем категорию
						std::cout << "Введите название категории игрушки - ";
						
						getline(std::cin, s2);
						//записываем мин возрастное ограничение
						std::cout << "Введите минимальное возрастное ограничение - ";
						std::cin >> s;
						i1 = strtol(s.c_str(), &end, 10);
						if (*end || i1 <= 0) {
							do
							{
								std::cout << "Введите данные корректно " << std::endl;
								std::cin >> s;
								i1 = strtol(s.c_str(), &end, 11);
							} while (*end || i1 <= 0);
						}
						//записываем максимальное возрастное ограничение
						std::cout << "Введите максимально возрастное ограничение - ";
						std::cin >> s;
						i2 = strtol(s.c_str(), &end, 10);
						if (*end || i2 <= 0) {
							do
							{
								std::cout << "Введите данные корректно " << std::endl;
								std::cin >> s;
								i1 = strtol(s.c_str(), &end, 11);
							} while (*end || i2 <= 0);
						}
						//записываем цену игрушкми
						std::cout << "Введите цену игрушки - ";

						std::cin >> s;
						i3 = strtol(s.c_str(), &end, 10);
						if (*end || i3 <= 0) {
							do
							{
								std::cout << "Введите данные корректно " << std::endl;
								std::cin >> s;
								i1 = strtol(s.c_str(), &end, 11);
							} while (*end || i3 <= 0);
						}
						array[N] = new Toy(s1, s2, i1, i2, i3);
						++N;
					}
					else if (sel2 == 2) {
						array[N] = new Toy();
						++N;
					}
					else {
						array[N] = new Toy();
						++N;
					}
					break;
				case(2):
					std::cout << "Вы хотите создать класс со своими данными(1) или по умолчанию(2) ?" << std::endl;
					std::cin >> s;
					sel2 = strtol(s.c_str(), &end, 10);
					if (*end || sel2 <= 0 || sel2 >= 3) {
						do
						{
							std::cout << "Такого пункта не существует " << std::endl;
							std::cin >> s;
							sel2 = strtol(s.c_str(), &end, 11);
						} while (*end || sel2 <= 0 || sel2 >= 3);
					}
					if (sel2 == 1) {
						system("cls");
						std::cout << "Начнем заполнение параметров нашей игрушки" << std::endl;
						//записываем название
						std::cout << "Придумайте название игрушки - ";
						std::cin.ignore();
						getline(std::cin, s1);
						//записываем категорию
						std::cout << "Введите название категории игрушки - ";
						getline(std::cin, s2);
						//записываем мин возрастное ограничение
						std::cout << "Введите минимальное возрастное ограничение - ";
						std::cin >> s;
						i1 = strtol(s.c_str(), &end, 10);
						if (*end || i1 <= 0) {
							do
							{
								std::cout << "Введите данные корректно " << std::endl;
								std::cin >> s;
								i1 = strtol(s.c_str(), &end, 11);
							} while (*end || i1 <= 0);
						}
						//записываем максимальное возрастное ограничение
						std::cout << "Введите максимально возрастное ограничение - ";
						std::cin >> s;
						i2 = strtol(s.c_str(), &end, 10);
						if (*end || i2 <= 0) {
							do
							{
								std::cout << "Введите данные корректно " << std::endl;
								std::cin >> s;
								i1 = strtol(s.c_str(), &end, 11);
							} while (*end || i2 <= 0);

						}
						std::cout << "Введите цену игрушки - ";
						std::cin >> s;
						i3 = strtol(s.c_str(), &end, 10);
						if (*end || i3 <= 0) {
							do
							{
								std::cout << "Введите данные корректно " << std::endl;
								std::cin >> s;
								i1 = strtol(s.c_str(), &end, 11);
							} while (*end || i3 <= 0);

						}
						std::cout << "Укажите производителя конструктора - ";
						std::cin.ignore();
						getline(std::cin, s3);
						array[N] = new Constructor(s1, s2, i1, i2, i3, s3);
						++N;
					}
					else if (sel2 == 2) {
						array[N] = new Constructor();
						++N;
					}
					else {
						array[N] = new Constructor();
						++N;
					}
					break;
				case(3):
					std::cout << "Вы хотите создать класс со своими данными(1) или по умолчанию(2) ?" << std::endl;
					std::cin >> s;
					sel2 = strtol(s.c_str(), &end, 10);
					if (*end || sel2 <= 0 || sel2 >= 3) {
						do
						{
							std::cout << "Такого пункта не существует " << std::endl;
							std::cin >> s;
							sel2 = strtol(s.c_str(), &end, 11);
						} while (*end || sel2 <= 0 || sel2 >= 3);
					}
					if (sel2 == 1) {
						system("cls");
						std::cout << "Начнем заполнение параметров нашей игрушки" << std::endl;
						//записываем название
						std::cout << "Придумайте название игрушки - ";
						std::cin.ignore();
						getline(std::cin, s1);
						//записываем категорию
						std::cout << "Введите название категории игрушки - ";
						
						getline(std::cin, s2);
						//записываем мин возрастное ограничение
						std::cout << "Введите минимальное возрастное ограничение - ";
						std::cin >> s;
						i1 = strtol(s.c_str(), &end, 10);
						if (*end || i1 <= 0) {
							do
							{
								std::cout << "Введите данные корректно " << std::endl;
								std::cin >> s;
								i1 = strtol(s.c_str(), &end, 11);
							} while (*end || i1 <= 0);
						}
						//записываем максимальное возрастное ограничение
						std::cout << "Введите максимально возрастное ограничение - ";
						std::cin >> s;
						i2 = strtol(s.c_str(), &end, 10);
						if (*end || i2 <= 0) {
							do
							{
								std::cout << "Введите данные корректно " << std::endl;
								std::cin >> s;
								i1 = strtol(s.c_str(), &end, 11);
							} while (*end || i2 <= 0);
						}
						//записываем цену игрушкми
						std::cout << "Введите цену игрушки - ";
						std::cin >> s;
						i3 = strtol(s.c_str(), &end, 10);
						if (*end || i3 <= 0) {
							do
							{
								std::cout << "Введите данные корректно" << std::endl;
								std::cin >> s;
								i1 = strtol(s.c_str(), &end, 11);
							} while (*end || i3 <= 0);

						}
						std::cout << "Укажите производителя игрушки \"Железная дорога\" - ";
						std::cin.ignore();
						getline(std::cin, s3);
						array[N] = new Railway(s1, s2, i1, i2, i3, s3);
						++N;
					}
					else if (sel2 == 2) {
						array[N] = new Railway();
						++N;
					}
					else {
						array[N] = new Railway();
						++N;
					}
					break;

				case(4):
					std::cout << "Вы хотите создать класс со своими данными(1) или по умолчанию(2) ?" << std::endl;
					std::cin >> s;
					sel2 = strtol(s.c_str(), &end, 10);
					if (*end || sel2 <= 0 || sel2 >= 3) {
						do
						{
							std::cout << "Такого пункта не существует " << std::endl;
							std::cin >> s;
							sel2 = strtol(s.c_str(), &end, 11);
						} while (*end || sel2 <= 0 || sel2 >= 3);
					}
					if (sel2 == 1) {
						system("cls");
						std::cout << "Начнем заполнение параметров нашей игрушки" << std::endl;
						//записываем название
						std::cout << "Придумайте название игрушки - ";
						std::cin.ignore();
						getline(std::cin, s1);
						//записываем категорию
						std::cout << "Введите название категории игрушки - ";
						
						getline(std::cin, s2);
						//записываем мин возрастное ограничение
						std::cout << "Введите минимальное возрастное ограничение - ";
						std::cin >> s;
						i1 = strtol(s.c_str(), &end, 10);
						if (*end || i1 <= 0) {
							do
							{
								std::cout << "Введите данные корректно " << std::endl;
								std::cin >> s;
								i1 = strtol(s.c_str(), &end, 11);
							} while (*end || i1 <= 0);
						}
						//записываем максимальное возрастное ограничение
						std::cout << "Введите максимально возрастное ограничение - ";
						std::cin >> s;
						i2 = strtol(s.c_str(), &end, 10);
						if (*end || i2 <= 0) {
							do
							{
								std::cout << "Введите данные корректно " << std::endl;
								std::cin >> s;
								i1 = strtol(s.c_str(), &end, 11);
							} while (*end || i2 <= 0);
						}
						//записываем цену игрушкми
						std::cout << "Введите цену игрушки - ";
						std::cin >> s;
						i3 = strtol(s.c_str(), &end, 10);
						if (*end || i3 <= 0) {
							do
							{
								std::cout << "Введите данные корректно" << std::endl;
								std::cin >> s;
								i1 = strtol(s.c_str(), &end, 11);
							} while (*end || i3 <= 0);

						}
						std::cout << "Введите имя куклы - ";
						std::cin.ignore();
						getline(std::cin, s3);
						array[N] = new Doll(s1, s2, i1, i2, i3, s3);
						++N;
					}
					else if (sel2 == 2) {
						array[N] = new Doll();
						++N;
					}
					else {
						array[N] = new Doll();
						++N;
					}
					break;
				case(5):
					std::cout << "Вы хотите создать класс со своими данными(1) или по умолчанию(2) ?" << std::endl;
					std::cin >> s;
					sel2 = strtol(s.c_str(), &end, 10);
					if (*end || sel2 <= 0 || sel2 >= 3) {
						do
						{
							std::cout << "Такого пункта не существует " << std::endl;
							std::cin >> s;
							sel2 = strtol(s.c_str(), &end, 11);
						} while (*end || sel2 <= 0 || sel2 >= 3);
					}
					if (sel2 == 1) {
						system("cls");
						std::cout << "Начнем заполнение параметров нашей игрушки" << std::endl;
						//записываем название
						std::cout << "Придумайте название игрушки - ";
						std::cin.ignore();
						getline(std::cin, s1);
						//записываем категорию
						std::cout << "Введите название категории игрушки - ";
						
						getline(std::cin, s2);
						//записываем мин возрастное ограничение
						std::cout << "Введите минимальное возрастное ограничение - ";
						std::cin >> s;
						i1 = strtol(s.c_str(), &end, 10);
						if (*end || i1 <= 0) {
							do
							{
								std::cout << "Введите данные корректно " << std::endl;
								std::cin >> s;
								i1 = strtol(s.c_str(), &end, 11);
							} while (*end || i1 <= 0);
						}
						
						std::cout << "Введите максимально возрастное ограничение - ";
						std::cin >> s;
						i2 = strtol(s.c_str(), &end, 10);
						if (*end || i2 <= 0) {
							do
							{
								std::cout << "Введите данные корректно " << std::endl;
								std::cin >> s;
								i1 = strtol(s.c_str(), &end, 11);
							} while (*end || i2 <= 0);
						}
						
						std::cout << "Введите цену игрушки - ";
						std::cin >> s;
						i3 = strtol(s.c_str(), &end, 10);
						if (*end || i3 <= 0) {
							do
							{
								std::cout << "Введите данные корректно - " << std::endl;
								std::cin >> s;
								i1 = strtol(s.c_str(), &end, 11);
							} while (*end || i3 <= 0);

						}
						std::cout << "Укажите название название настольной игры - ";
						std::cin.ignore();
						getline(std::cin, s3);
						array[N] = new BoardGame(s1, s2, i1, i2, i3, s3);
						++N;
					}
					else if (sel2 == 2) {
						array[N] = new BoardGame();
						++N;
					}
					else {
						array[N] = new BoardGame();
						++N;
					}
					break;
				}
			}
			else {
				std::cout << "Массив переполнен!" << std::endl;
			}
			break;
		case(2):
			if (N == 0) {
				std::cout << "Пока что вы не создали игрушку. Выводить нечего!" << std::endl;
				std::cout << "Нажмите Enter ,чтобы продолжить." << std::endl;
				getchar();
				while (getchar() != '\n');
			}
			else {
				for (int i = 0; i < N; ++i) {
					array[i]->outPutName(); std::cout << '\n' << std::endl;
					std::cout << "----------------\n" << std::endl;
					array[i]->Information();
					std::cout << '\n' << std::endl;
				}
				std::cout << "Нажмите Enter, чтобы продолжить" << std::endl;
				getchar();
				while (getchar() != '\n');
			}
			break;
		case 3:
			if (N == 0) {
				std::cout << "Вы не создали игрушку. Выводить нечего!" << std::endl;
				std::cout << "Нажмите Enter, чтобы продолжить" << std::endl;
				getchar(); 
				while (getchar() != '\n');
			}
			else {
				std::cout << "Перед вами появились созданные вами классы." << std::endl;
				std::cout << "Осуществите выбор, указав порядковый номер игрушки, который находится ниже" << std::endl;
				for (i = 0; i < N; ++i) {
					std::cout << "--------------" << std::endl;
					array[i]->outPutName();
					std::cout << "(" << i + 1 << ")" << std::endl;
					std::cout << "---------------" << std::endl;
				}
				std::cout << "Выбери класс, с которым хочешь работать - " << std::endl;
				std::cin >> sel1;

				// Проверка корректности ввода
				while (sel1 <= 0 || sel1 > N) {
					std::cout << "Не существует такого пункта" << std::endl;
					std::cin >> sel1;
				}

				do {
					system("CLS");
					std::cout << "		---Действия с игрушкой---" << std::endl;
					std::cout << "Взаимодействовать с игрушкой \"Достать игрушку\"	 (1) " << std::endl;
					std::cout << "Взаимодействовать с игрушкой \"Играть с игрушкой\" (2) " << std::endl;
					std::cout << "Взаимодействовать с игрушкой \" Убрать игрушку\"   (3)" << std::endl;
					std::cout << "Уникальное взаимодействие с игрушкой		 (4)" << std::endl;
					std::cout << "Закончить взаимодействие			 (5)" << std::endl;
					std::cout << "Пункт - " << std::endl;
					std::cin >> a;

					switch (a) {
					case 1:
						array[sel1 - 1]->unpucking();
						break;

					case 2:
						array[sel1 - 1]->Play();
						break;

					case 3:
						array[sel1 - 1]->clearUp();
						break;

					case 4:
						if (array[sel1 - 1]->Inil() == 1) {
							Constructor* p = dynamic_cast<Constructor*>(array[sel1 - 1]);
							if (p != nullptr) {
								p->Drpcetail();
							}
						}
						else if (array[sel1 - 1]->Inil() == 2) {
							Railway* p1 = dynamic_cast<Railway*>(array[sel1 - 1]);
							if (p1 != nullptr) {
								p1->chuxchux();
							}
						}
						else if (array[sel1 - 1]->Inil() == 3) {
							Doll* p2 = dynamic_cast<Doll*>(array[sel1 - 1]);
							if (p2 != nullptr) {
								p2->cry();
							}
						}
						else if (array[sel1 - 1]->Inil() == 4) {
							BoardGame* p3 = dynamic_cast<BoardGame*>(array[sel1 - 1]);
							if (p3 != nullptr) {
								p3->TheRollofTheDice();
							}
						}
						break;
					}

					std::cout << "Нажмите Enter, чтобы продолжить ";
					getchar(); 
					while (getchar() != '\n'); 

				} while (a != 5);
			}
			break;

		case(4):
			std::cout << "-----Пока-----" << std::endl;

			for (i = 0; i < N; i++) {
				delete array[i];
			}
			return 1;

		}
	}while (true);
	return 0;
}

