#include <iostream> 
#include <locale.h> 
#include <list> 
#include <ctime> 
#include <chrono> 
 
const int array_size = 1000; 
 
template <typename T> 
struct stack_mass { 
    T* hop; 
    T mass[array_size]; 
    int counter_of_elm = 0; 
 
    void add_element(T elm) { 
        if (counter_of_elm == 0) { 
            mass[0] = elm; 
            hop = &mass[0]; 
            counter_of_elm++; 
        } 
        else { 
            hop++; 
            *hop = elm; 
            counter_of_elm++; 
        } 
    } 
 
    T get_element() { 
        if (counter_of_elm == 0) { 
            std::cout << "error"; 
            return -1; 
        } 
        else { 
            if (counter_of_elm == 1) { 
                hop = nullptr; 
                counter_of_elm--; 
                return mass[0]; 
            } 
            else { 
                T result = *hop; 
                hop--; 
                counter_of_elm--; 
                return result; 
            } 
        } 
    } 
}; 
 
int main() { 
    setlocale(LC_ALL, "Russian"); 
    stack_mass<int> my_stack; 
    // Тест скорости добавления элементов 
    auto start = std::chrono::high_resolution_clock::now(); // Используем high_resolution_clock для точности 
    for (int i = 0; i < array_size; i++) { 
        my_stack.add_element(i); 
    } 
    auto end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> time_taken = end - start; 
    std::cout << "Время, затраченное на добавление " << array_size << " элементов: "<< std::fixed << time_taken.count() << " секунд" << std::endl; 
 
    // Очистим стек 
    my_stack = stack_mass<int>(); 
 
    // Тест скорости извлечения элементов 
    for (int i = 0; i < array_size; i++) { 
        my_stack.add_element(i); 
    } 
 
    start = std::chrono::high_resolution_clock::now(); 
    for (int i = 0; i < array_size; i++) { 
        my_stack.get_element(); 
    } 
    end = std::chrono::high_resolution_clock::now(); 
    time_taken = end - start; 
    std::cout << "Время, затраченное на извлечения " << array_size << " элементов: " << std::fixed << time_taken.count() << " секунд" << std::endl; 
 
    return 0; 
}