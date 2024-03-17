#include <iostream>
#include <list>
#include <locale.h>
#include <chrono>

const int array_size = 100;

template <typename T>
struct stack_list {
    std::list<T> storage;

    void push_element(T element) {
        if (storage.size() >= array_size) {
            std::cout << "Stack is full, can not add an element" << std::endl;
        }
        else {
            storage.push_back(element);
        }
    }

    T pop_element() {
        if (storage.empty()) {
            std::cout << "Stack is empty, can not extract elements" << std::endl;
            return T();
        }
        else {
            T top_element = storage.back();
            storage.pop_back();
            return top_element;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    stack_list<int> my_stack;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < array_size; i++) {
        my_stack.push_element(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_taken = end - start;
       std::cout << "Время, затраченное на добавление " << array_size << " элементов: " << std::fixed << time_taken.count() << " секунд" << std::endl;


    // Clear the stack
    my_stack = stack_list<int>();

    for (int i = 0; i < array_size; i++) {
        my_stack.push_element(i);
    }

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < array_size; i++) {
        my_stack.pop_element();
    }
    end = std::chrono::high_resolution_clock::now();
    time_taken = end - start;
    std::cout << "Время, затраченное на извлечение  " << array_size << " элементов: " << time_taken.count() << " секунд" << std::endl;

    return 0;
}

