#include <iostream>
#include <deque>
#include <ctime>
#include <cstdlib>


#define MAX_PANCAKES 50

typedef int DataType;

class Deque {
private:
    int left, right;
    DataType data[MAX_PANCAKES];

public:
    Deque() {
        MakeNull();
    }

    void MakeNull() {
        left = 0;
        right = MAX_PANCAKES - 1;
    }

    bool Empty() {
        return (right + 1) % MAX_PANCAKES == left;
    }

    bool Full() {
        return (right + 2) % MAX_PANCAKES == left;
    }

    DataType ReadLeft() {
        return data[left];
    }

    DataType ReadRight() {
        return data[right];
    }

    bool InRight(DataType x) {
        if (Full()) return false;
        right = (right + 1) % MAX_PANCAKES;
        data[right] = x;
        return true;
    }

    bool InLeft(DataType x) {
        if (Full()) return false;
        left = left ? left - 1 : MAX_PANCAKES - 1;
        data[left] = x;
        return true;
    }

    DataType OutLeft() {
        int temp = left;
        left = (left + 1) % MAX_PANCAKES;
        return data[temp];
    }

    DataType OutRight() {
        int temp = right;
        right = right ? right - 1 : MAX_PANCAKES - 1;
        return data[temp];
    }
};



int main() {
    system("chcp 1251");
    system("cls");
    int start = 8, end = 15;// переменные которые задают диапазон съед блинов
    Deque pancakes;
    int countofchildren;
    int eaten = 0;//переменная для подсчета съеденных блинов
   

    std::cout << "Введите количество внуков, которые будут есть блины(от 2 до 4): " << std::endl;
    std::cin >> countofchildren;

    if (countofchildren < 2 || countofchildren > 4) {
        std::cout << "Введено неверное количество внуков! " << std::endl;
        return 1;
    }


    // начнем заполнение дека справа блинами, до 25 блинов
    for (int i = 0; i < MAX_PANCAKES; ++i) {
        std::string paintOnpancake[] = { "Цветочек", "Котик", "Грибочек" };
        std::string paintpanc = paintOnpancake[rand() % 3];//задем рисунок каждому блину, который будет печься

        int x = 0;
        pancakes.InRight(i);//заполнение дека справа циклом
        
        // внуки приходят и сразу переворачивают стопку, блин сверху горячий
        if ((i - 1) % 25 == 0) {
            std::cout << "Бабушка зовет внуков за стол!!!" << std::endl;

            //с помощью rand задам диапазон от 8 до 15
            for (int j = 0; j < countofchildren; ++j) {
                x += rand() % (end - start) + start;
                
            }
            while (eaten != x) {
                pancakes.OutLeft() - (countofchildren * 2);
                std::cout << paintOnpancake << std::endl;
                pancakes.OutRight() - (countofchildren * 2);
                std::cout << paintOnpancake << std::endl;

            }
        }
    }
}