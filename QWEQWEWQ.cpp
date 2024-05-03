/*
Создать файл, содержащий сведения об ассортименте игрушек в магазине.
Каждая запись содержит поля: название игрушки, цена, количество, возрастные границы, например 2 - 5, т.е. от 2 до 5 лет.
Количество записей произвольное. Написать программу, выводящую на экран следующую информацию:

- названия игрушек, которые подходят детям от 1 до 3 лет;
- стоимость самой дорогой игрушки и её наименование;
- названия игрушки, которые по стоимости не превышают x рублей и подходят ребёнку в возрасте от a до b лет.

Значения x, a, b ввести с терминала.
*/

#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <windows.h> //Шрифт консоли Lucida Console4f
using namespace std;
class ToysRange {

private:

    std::string t_name;
    double t_price;
    int t_qty;
    std::string age_limit;

public:

    //Геттеры

    string getToyName() const;
    double getToyPrice() const;
    int getToysQuantity() const;
    string getAgeLimit() const;

    //Вспомогательные функции

    bool checkAgeLimit(int a, int b) { //Метод проверки возрастного диапазона
        string s = getAgeLimit();
        int minAge = atoi(s.substr(0, s.find('-')).c_str());
        int maxAge = atoi(s.substr(s.find('-') + 1).c_str());
        if (minAge >= a && maxAge <= b) {
            return true;
        }
        return false;
    }

    //Методы класса

    string getToysForParticularChild() { //Метод вывода названия игрушек, которые подходят детям от 1 до 3 лет
        ifstream in("input.txt");
        if (!in.fail()) {
            bool flag = false;
            ToysRange toy;
            while (in >> toy) {
                if (toy.checkAgeLimit(1, 3)) {
                    cout << toy.getToyName() << "\n";
                    flag = true;
                }
            }
            if (!flag) {
                cout << "No any searched toys were found!\n";
            }
            in.close();
        }
        else {
            cout << "File input.txt wasn't found!\n";
        }
    }

    void getTheMostExpensiveToy() { //Метод вывода стоимости самой дорогой игрушки и ее наименования
        ifstream in("input.txt");
        if (!in.fail()) {
            double max;
            string name;
            ToysRange toy;
            while (in >> toy) {
                if (toy.getToyPrice() > max) {
                    max = toy.getToyPrice();
                    name = toy.getToyName();
                }
            }
            cout << "The most expensive toy price: " << max << "\n";
            cout << "The most expensive toy name: " << name << "\n";
            in.close();
        }
        else {
            cout << "File input.txt wasn't found!\n";
        }
    }

    void getToysNameByAgeLimit() { //Метод вывода названия игрушки стоимостью не больше x для заданного диапазона возрастов
        ifstream in("input.dat");
        if (!in.fail()) {
            int a, b;
            double x;
            bool flag = false;
            string name;
            ToysRange toy;
            cout << "Enter a maximum toy price: ";
            cin >> x;
            cout << "Enter an age limit:\n";
            cout << "a = ";
            cin >> a;
            cout << "b = ";
            cin >> b;
            while (in >> toy) {
                if (toy.checkAgeLimit(a, b) && toy.getToyPrice() <= x) {
                    cout << toy.getToyName() << "\n";
                    flag = true;
                }
            }
            if (!flag) {
                cout << "No any searched toys were found!\n";
            } in.close();
        }
        else {
            cout << "File input.txt wasn't found!\n";
        }
    }

    friend ifstream& operator>>(ifstream& in, ToysRange& toy) { //Дружественная функция перегрузки оператора ввода
        getline(in, toy.t_name);
        in >> toy.t_price >> toy.t_qty;

        getline(in, toy.age_limit);
        in.ignore();
        return in;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ToysRange toys;
    toys.getToysNameByAgeLimit();
    return 0;
}

string ToysRange::getToyName() const {
    return t_name;
}

double ToysRange::getToyPrice() const {
    return t_price;
}

int ToysRange::getToysQuantity() const {
    return t_qty;
}

string ToysRange::getAgeLimit() const {
    return age_limit;
}