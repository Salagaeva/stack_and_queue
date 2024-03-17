#include <iostream>
#include <list>
#include <ctime>

const int array_size = 100;

template <typename T>
struct queue_list {
    std::list<T> storage;

    void add_element(T element) {
        if (storage.size() >= array_size) {
            // Если размер очереди достиг предела, то не добавляем новый элемент
            std::cout << "Очередь переполнена, нельзя добавить элемент" << std::endl;
        }
        else {
            storage.push_back(element);
        }
    }

    T get_element() {
        if (storage.empty()) {
            // Если очередь пуста, сообщаем об этом и возвращаем дефолтное значение элемента
            std::cout << "Очередь пуста, нельзя извлечь элементы" << std::endl;
            return T();
        }
        else {
            // Извлекаем элемент из начала очереди и возвращаем его
            T front_element = storage.front();
            storage.pop_front();
            return front_element;
        }
    }
};


int main() {    
    queue_list<int> my_queue;

    // Тест скорости добавления элементов
    clock_t start = clock();
    for (int i = 0; i < array_size; i++) {
        my_queue.add_element(i);
    }
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Время, затраченное на добавление " << array_size << " элементов: " << std::fixed << time_taken << " секунд" << std::endl;

    // Очистим очередь
    my_queue = queue_list<int>();

    // Тест скорости извлечения элементов
    for (int i = 0; i < array_size; i++) {
        my_queue.add_element(i);
    }

    start = clock();
    for (int i = 0; i < array_size; i++) {
        my_queue.get_element();
    }
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Время, затраченное на извлечения " << array_size << " элементов: " << std::fixed << time_taken << " секунд" << std::endl;

    
    
    return 0;
}