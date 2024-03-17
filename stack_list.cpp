#include <iostream>
#include <list>
#include <locale.h>
#include <ctime>

const int array_size = 10000;

template <typename T>
struct stack_list { // Определение структуры стека на основе списка
    std::list<T> storage; // Хранение элементов стека в виде списка

    void push_element(T element) {
        if (storage.size() >= array_size) {
            // Если размер очереди достиг предела, то не добавляем новый элемент
            std::cout << "Stack is full, can not add an element" << std::endl;
        } else {// Метод добавления элемента в стек
        storage.push_back(element); // Добавление элемента в конец списка
    }
    }

    T pop_element() { // Метод извлечения элемента из стека
        if (storage.empty()) { // Проверка на пустоту стека
            std::cout << "Stack is empty, can not extract elements" << std::endl; // Вывод сообщения об ошибке
            return T(); // Возвращение значения по умолчанию
        }
        else {
            T top_element = storage.back(); // Получение верхнего элемента стека
            storage.pop_back(); // Удаление верхнего элемента из списка
            return top_element; // Возвращение извлеченного элемента
        }
    }
};

int main() {    
    stack_list<int> my_stack; // Создание объекта стека

    my_stack.push_element(20); // Добавление элемента в стек
    my_stack.push_element(7);
    my_stack.push_element(15);

    std::cout << my_stack.pop_element() << std::endl; // Извлечение и вывод элемента
    std::cout << my_stack.pop_element() << std::endl;
    std::cout << my_stack.pop_element() << std::endl;

    return 0;
}

