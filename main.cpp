//Практическая работа №4
//Выполнили: 
// Голубев Иван
// Горохова Полина
// Мухамедов Максим

#include <iostream>

using namespace std;

// Класс для смежного представления массива
class ContiguousArray {
private:
    int* array; // Указатель на массив
    int size;   // Текущий размер массива

public:
    ContiguousArray() {
        array = nullptr;
        size = 0;
    }

    // Добавление элемента в массив
    void addElement(int element) {
        int* temp = new int[size + 1]; // Создание нового массива большего размера
        for (int i = 0; i < size; ++i) {
            temp[i] = array[i]; // Копирование элементов из старого массива
        }
        temp[size] = element; // Добавление нового элемента
        ++size; // Увеличение размера массива
        delete[] array; // Освобождение памяти, занятой старым массивом
        array = temp; // Обновление указателя на новый массив
    }

    // Удаление элемента из массива по индексу
    void removeElement(int index) {
        if (index < 0 || index >= size) {
            cout << "Недопустимый индекс." << endl;
            return;
        }
        int* temp = new int[size - 1]; // Создание нового массива меньшего размера
        for (int i = 0, j = 0; i < size; ++i) {
            if (i != index) {
                temp[j++] = array[i]; // Копирование элементов, кроме удаляемого
            }
        }
        --size; // Уменьшение размера массива
        delete[] array; // Освобождение памяти, занятой старым массивом
        array = temp; // Обновление указателя на новый массив
    }

    // Печать содержимого массива
    void printArray() {
        cout << "Смежное представление: ";
        for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // Деструктор для освобождения памяти
    ~ContiguousArray() {
        delete[] array;
    }
};

// Класс для связного представления массива
class LinkedListArray {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head; // Указатель на начало связного списка

public:
    LinkedListArray() {
        head = nullptr;
    }

    // Добавление элемента в массив
    void addElement(int element) {
        Node* newNode = new Node(); // Создание нового узла
        newNode->data = element; // Присвоение значения узлу
        newNode->next = head; // Новый узел становится началом списка
        head = newNode; // Обновление указателя на начало списка
    }

    // Удаление элемента из массива по значению
    void removeElement(int value) {
        Node* temp = head;
        Node* prev = nullptr;

        // Поиск удаляемого узла
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        // Если удаляемый узел найден
        if (temp != nullptr) {
            // Если удаляемый узел находится в начале списка
            if (prev == nullptr) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp; // Освобождение памяти, занимаемой удаляемым узлом
        } else {
            cout << "Элемент не найден." << endl;
        }
    }

    // Печать содержимого массива
    void printArray() {
        cout << "Связное представление: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Деструктор для освобождения памяти
    ~LinkedListArray() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    int choice;
    cout << "Выберите представление массива: (укажите только число)" << endl;
    cout << "1. Смежное представление" << endl;
    cout << "2. Связное представление" << endl;
    cin >> choice;

    if (choice == 1) {
        ContiguousArray array;
        int element;
        char ans;
        do {
            cout << "Введите элемент для добавления: ";
            cin >> element;
            array.addElement(element);
            array.printArray();
            cout << "Хотите добавить еще элемент? (Введите 'y', если да, и 'n', если нет): ";
            cin >> ans;
        } while (ans == 'y');

        int index;
        cout << "Введите индекс элемента, который вы хотите удалить: ";
        cin >> index;
        array.removeElement(index);
        array.printArray();
    } else if (choice == 2) {
        LinkedListArray array;
        int element;
        char ans;
        do {
            cout << "Введите элемент для добавления: ";
            cin >> element;
            array.addElement(element);
            array.printArray();
            cout << "Хотите добавить еще элемент? (Введите 'y', если да, и 'n', если нет): ";
            cin >> ans;
        } while (ans == 'y');

        int value;
        cout << "Введите значение элемента, который вы хотите удалить: ";
        cin >> value;
        array.removeElement(value);
        array.printArray();
    } else {
        cout << "Недопустимый выбор." << endl;
    }

    return 0;
}
