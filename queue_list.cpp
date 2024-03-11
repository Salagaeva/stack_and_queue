
#include <iostream>
#include <list>
#include <locale.h>
#include <ctime>

const int array_size = 10000;

template <typename T>
struct queue_list {
    std::list<T> storage;

    void add_element(T element) {
        storage.push_back(element);
    }

    T get_element() {
        if (storage.empty()) {
            std::cout << "Queue is empty" << std::endl;
            return T();
        }
        else {
            T front_element = storage.front();
            storage.pop_front();
            return front_element;
        }
    }
};

int main() {    
    queue_list<int> my_queue;
    
    my_queue.add_element(50);
    my_queue.add_element(9);
    my_queue.add_element(15);

    std::cout << my_queue.get_element() << std::endl;
    std::cout << my_queue.get_element() << std::endl;
    std::cout << my_queue.get_element() << std::endl;

    return 0;
}





