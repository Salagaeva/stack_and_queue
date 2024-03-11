#include <iostream>
#include <list>
#include <locale.h>
#include <ctime>

const int array_size = 10000;

template <typename t>
struct stack_mass {
    t* hop;
    t mass[array_size];
    int counter_of_elm = 0;

    void add_element(t elm) {
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

    t get_element() {
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
                t result = *hop;
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
    my_stack.add_element(7);
    my_stack.add_element(8);

    std::cout << my_stack.get_element() << std::endl;
    std::cout << my_stack.get_element() << std::endl;
    std::cout << my_stack.get_element() << std::endl;

    return 0;
}
