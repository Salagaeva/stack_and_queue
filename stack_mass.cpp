#include <iostream>
#include <ctime>

const int array_size = 10000;

template <typename T>
struct stack_mass {
    T* hop;
    T mass[array_size];
    int counter_of_elm = 0;

    void add_element(T elm) {
        if (counter_of_elm == array_size) {
            std::cout << "Error: Стэк полн, элемент не может быть добавлен" << std::endl;
        } else {
            if (counter_of_elm == 0) {
                mass[0] = elm;
                hop = &mass[0];
                counter_of_elm++;
            } else {
                hop++;
                *hop = elm;
                counter_of_elm++;
            }
        }
    }

    T get_element() {
        if (counter_of_elm == 0) {
            std::cout << "Error: Стэк пуст, элемент не может быть извлечен" << std::endl;
            return -1;
        } else {
            if (counter_of_elm == 1) {
                hop = nullptr;
                counter_of_elm--;
                return mass[0];
            } else {
                T result = *hop;
                hop--;
                counter_of_elm--;
                return result;
            }
        }
    }
};

int main() {
    stack_mass<int> my_stack;

    my_stack.add_element(50);
    my_stack.add_element(23);
    my_stack.add_element(5);

    std::cout << my_stack.get_element() << std::endl;
    std::cout << my_stack.get_element() << std::endl;
    std::cout << my_stack.get_element() << std::endl;

    return 0;
}
