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

   // Тест скорости добавления элементов
    clock_t start = clock();
    for (int i = 0; i < array_size; i++) {
        my_stack.push_element(i);
    }
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Время, затраченное на добавление " << array_size << " элементов: " << time_taken << " секунд" << std::endl;

    // Очистим стек
    my_stack = stack_list<int>();

    // Тест скорости извлечения элементов
    for (int i = 0; i < array_size; i++) {
        my_stack.push_element(i);
    }

    start = clock();
    for (int i = 0; i < array_size; i++) {
        my_stack.pop_element();
    }
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Время, затраченное на извлечения " << array_size << " элементов: " << time_taken << " секунд" << std::endl;

    
    
    return 0;
}
