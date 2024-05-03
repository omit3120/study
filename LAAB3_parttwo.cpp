#include <iostream>
#include <limits>
template <typename T>
class Deque {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
    };

    Node* front;
    Node* rear;
    size_t size;

public:
    Deque() : front(nullptr), rear(nullptr), size(0) {}

    ~Deque() {
        while (!isEmpty()) {
            front = nullptr;
            rear = nullptr;
            
        }
    }

    bool isEmpty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }

    void pushFront(const T& data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    void pushBack(const T& data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        size++;
    }

    bool popFront(T& data) {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return false;
        }
        Node* temp = front;
        data = front->data;
        if (front == rear) {
            front = nullptr;
            rear = nullptr;
        }
        else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
        size--;
        return true;
    }

    bool popBack(T& data) {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return false;
        }
        Node* temp = rear;
        data = rear->data;
        if (front == rear) {
            front = nullptr;
            rear = nullptr;
        }
        else {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
        size--;
        return true;
    }

    void printDeque(const Deque<T>& deque) {
        if (deque.isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return;
        }
        do {
            std::cout << "Deque elements: ";
            for (Node* current = deque.front; current != nullptr; current = current->next) {
                std::cout << current->data << " ";
            }
            std::cout << std::endl;
        } while (getchar()!= '\n');
        
    }

    friend void charMenu();
    friend void intMenu();
};


void charMenu() {
    Deque<char> myDeque;
    int select;
    do {


        system("cls");
        std::cout << "Char Menu" << std::endl;
        std::cout << "1. Push front" << std::endl;
        std::cout << "2. Push back" << std::endl;
        std::cout << "3. Pop front" << std::endl;
        std::cout << "4. Pop back" << std::endl;
        std::cout << "5. Print deque" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Comand: ";
        std::cin >> select;

        if (std::cin.fail() || select > 6 || select < 1) {
            do {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cin >> select;
            } while (std::cin.fail() || select > 6 || select < 1);
        }


        switch (select)
        {
        case 1:
            system("cls");
            char m;

            while (true) {
                std::cout << "Input element: ";
                if (std::cin >> m) {
                    std::cin.ignore(10, '\n');
                    break;
                }
                else {
                    std::cout << "Error: Invalid input" << std::endl;
                    std::cin.clear();
                    
                }
            }
            do {
                std::cout << "Press Enter to continue!" << std::endl;
                myDeque.pushFront(m);
            } while (getchar() != '\n');
            break;
        case 2:
            system("cls");
            char a;
            while (true) {
                std::cout << "Input element: ";
                if (std::cin >> m) {
                    std::cin.ignore(10, '\n');
                    break;
                }
                else {
                    std::cout << "Error: Invalid input" << std::endl;
                    std::cin.clear();
                }
            }
            do {
                std::cout << "Press Enter to continue!" << std::endl;
                myDeque.pushFront(m);
            } while (getchar() != '\n');
            break;
            do {
                std::cout << "Enter ur element: " << std::endl; std::cin >> a;
                std::cout << "Press Enter to continue!" << std::endl;
                myDeque.pushBack(a);
            } while (getchar() != '\n');

            break;
        case 3:
            system("cls");
            char elemOfdel;
            system("cls");
            if (myDeque.isEmpty()) {
                do {
                    std::cout << "Error. Deque is empty" << std::endl;
                    getchar();
                } while (getchar() != '\n');
                
            }
            else {
                do {
                    myDeque.popFront(elemOfdel);
                    std::cout << "Delete element is: " << elemOfdel << " " << std::endl;
                    std::cout << "Press Enter to continue!" << std::endl;
                    getchar();
                } while (getchar() != '\n');
            }
            break;

        case 4:
            system("cls");
            char elemOfdelsec;
            if (myDeque.isEmpty()) {
                do {
                    std::cout << "Error. Deque is empty" << std::endl;
                    getchar();
                } while (getchar() != '\n');

            }
            else {
                do {
                    myDeque.popBack(elemOfdelsec);
                    std::cout << "Delete element is: " << elemOfdelsec << " " << std::endl;
                    std::cout << "Press Enter to continue!" << std::endl;
                    getchar();
                } while (getchar() != '\n');
                
            }
            break;
            

        case 5:
            system("cls");
            if (myDeque.isEmpty()) {
                do {
                    std::cout << "Error. Deque is empty" << std::endl;
                    getchar();
                } while (getchar() != '\n');

            }
            
            else {
                do {
                    myDeque.printDeque(myDeque);
                    std::cout << "Press Enter to continue!" << std::endl;
                } while (getchar() != '\n');
                break;
            } 
        case 6:
            system("cls");
            while (!myDeque.isEmpty()) {
                char temp;
                myDeque.popFront(temp);
            }
            break;
        }

    } while (select != 6);

}

void intMenu() {
    Deque<int> myDeque;
    int select;
    do {
        

        system("cls");
        std::cout << " Int Menu" << std::endl;
        std::cout << "1. Push front" << std::endl;
        std::cout << "2. Push back" << std::endl;
        std::cout << "3. Pop front" << std::endl;
        std::cout << "4. Pop back" << std::endl;
        std::cout << "5. Print deque" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Comand: ";

        std::cin >> select;

        if (std::cin.fail() || select > 6 || select < 1) {
            do {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cin >> select;
            } while (std::cin.fail() || select > 6 || select < 1);
        }


        switch (select)
        {
        case 1:
            system("cls");
            int m;

            while (true) {
                std::cout << "Input element: ";
                if (std::cin >> m) {
                    break;
                }
                else {
                    std::cout << "Error: Invalid input" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            do {
                std::cout << "Press Enter to continue!" << std::endl;
                myDeque.pushFront(m);
                getchar();
            } while (getchar() != '\n');
            break;
        case 2:
            system("cls");
            int a;

            while (true) {
                std::cout << "Input element: ";
                if (std::cin >> a) {
                    break;
                }
                else {
                    std::cout << "Error: Invalid input" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            do {
                std::cout << "Press Enter to continue!" << std::endl;
                myDeque.pushFront(a);
                getchar();
            } while (getchar() != '\n');
            break;
        case 3:
            system("cls");
            int elemOfdel;
            if (myDeque.isEmpty()) {
                do {
                    std::cout << "Error. Deque is empty" << std::endl;
                    getchar();
                } while (getchar() != '\n');

            }
            else {
                do {
                    myDeque.popFront(elemOfdel);
                    std::cout << "Delete element is: " << elemOfdel << " " << std::endl;
                    std::cout << "Press Enter to continue!" << std::endl;
                    getchar();
                } while (getchar() != '\n');
            }
            break;

        case 4:
            system("cls");
            int elemOfdelsec;
            if (myDeque.isEmpty()) {
                do {
                    std::cout << "Error. Deque is empty" << std::endl;
                    getchar();
                } while (getchar() != '\n');

            }
            else {
                do {
                    myDeque.popBack(elemOfdelsec);
                    std::cout << "Delete element is: " << elemOfdelsec << " " << std::endl;
                    std::cout << "Press Enter to continue!" << std::endl;
                    getchar();
                } while (getchar() != '\n');
            }
            break;

        case 5:
            system("cls");
            if (myDeque.isEmpty()) {
                do {
                    std::cout << "Error. Deque is empty" << std::endl;
                    getchar();
                } while (getchar() != '\n');

            }
            else {
                do {
                    myDeque.printDeque(myDeque);
                    std::cout << "Press Enter to continue!" << std::endl;

                } while (getchar() != '\n');
            } 
            break;
        case 6:
            system("cls");
            while (!myDeque.isEmpty()) {
                int temp;
                myDeque.popFront(temp);
            }
            break;
        }

    } while (select != 6);

}



int main(void) {
    
    int menu;
    
    do {
        std::cout << "Menu Deque(choise what function u will use)" << std::endl;
        std::cout << "1. Int Deque" << std::endl;
        std::cout << "2. Char Deque" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Comand: ";

        std::cin >> menu;


        if (std::cin.fail() || menu > 3 || menu < 1) {
            do {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cin >> menu;
            } while (std::cin.fail() || menu > 3 || menu < 1);
        }

        switch (menu)
        {
        case 1:intMenu(); break;
        case 2:charMenu(); break;
        case 3: break;
        }
    } while (menu != 3);
    return 0;
}