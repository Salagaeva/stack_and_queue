#include <iostream>
#include <chrono> // Добавляем библиотеку <chrono> для работы с временем

const int array_size = 1000;

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
        }
        else {
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
        }
        else {
            // Возвращаем элемент и увеличиваем front_index
            return storage[front_index++];
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    queue_mass<int> my_queue;

    // Тест скорости добавления элементов
    auto start = std::chrono::high_resolution_clock::now(); // Используем high_resolution_clock для точности
    for (int i = 0; i < array_size; i++) {
        my_queue.add_element(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_taken = end - start;
    std::cout << "Время, затраченное на добавление " << array_size << " элементов: " << std::fixed << time_taken.count() << " секунд" << std::endl;

    // Очистим стек
    my_queue = queue_mass<int>();

    // Тест скорости извлечения элементов
    for (int i = 0; i < array_size; i++) {
        my_queue.add_element(i);
    }

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < array_size; i++) {
        my_queue.get_element();
    }
    end = std::chrono::high_resolution_clock::now();
    time_taken = end - start;
    std::cout << "Время, затраченное на извлечения " << array_size << " элементов: " << std::fixed << time_taken.count() << " секунд" << std::endl;

    return 0;
}