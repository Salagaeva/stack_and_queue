#include <iostream>

const int array_size = 10000;

template <typename T>
struct queue_mass {
    T storage[array_size];
    int front_index;
    int back_index;

    // Конструктор инициализирует индексы front_index и back_index
    queue_mass() : front_index(0), back_index(-1) {}

    // Добавление элемента в очередь
    void add_element(T element) {
        // Проверяем, не полна ли очередь
        if (back_index == array_size - 1) {
            std::cout << "Queue is full" << std::endl;
        } else {
            // Увеличиваем back_index и добавляем элемент
            storage[++back_index] = element;
        }
    }

    // Получение элемента из очереди
    T get_element() {
        // Проверяем, не пуста ли очередь
        if (front_index > back_index) {
            std::cout << "Queue is empty" << std::endl;
            return T();
        } else {
            // Возвращаем элемент и увеличиваем front_index
            return storage[front_index++];
        }
    }
};

int main() {    
    queue_mass<int> my_queue;
    
    my_queue.add_element(50);
    my_queue.add_element(9);
    my_queue.add_element(15);

    std::cout << my_queue.get_element() << std::endl;
    std::cout << my_queue.get_element() << std::endl;
    std::cout << my_queue.get_element() << std::endl;

    return 0;
}
