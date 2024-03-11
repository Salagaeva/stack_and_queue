#include <iostream>
//тут базово задаю типо размерчик масивчику
const int array_size = 10000;
//Класс QueueArray представляет собой очередь, реализованную с использованием массива.
class Queue 
{
    //Модификатор private (закрытый) указывает на то, что свойства и методы доступны только внутри класса.
    private:
    int first, last, size;
    int arr[array_size];
    //Модификатор public (общий) указывает на то, что свойства и методы доступны без ограничений.
    public:
    Queue() 
    {
    first = 0;
    last = -1;
    size = 0;
    }
    //IsEmpty — проверяет, пуста ли очередь.
    bool isEmpty() {
        return size == 0;
}
//IsFull — проверяет, заполнена ли очередь.
bool isFull() 
{
    return size == array_size;
}
//Enqueue — позволяет добавить элемент в конец очереди. 
//тут проверяется заполнена ли очеред и мы увеличиваем last на 1, 
//чтобы указать на новую позицию, куда будет добавлен новый элемент.
//При этом используется операция % array_size для обеспечения цикличности добавления элементов.
void enqueue(int meaning) 
{
    if (isFull()) 
    {
        std::cout << "Очередь заполнена" << std::endl;
        return;
    }

    last = (last + 1) % array_size;
    //добавляется значение meaning в очередь по индексу last.
    arr[last] = meaning;
    //size увеличивается на 1, чтобы отслеживать общее количество элементов в очереди.
    size++;
}
//dequeue - это наоборот удаляет
//Переменная first указывает на индекс первого элемента в очереди. 
void dequeue() 
{
    if (isEmpty()) 
    {
        std::cout << "Очередь пуста" << std::endl;
        return;
    }
    //увеличиваю first на 1, чтобы указать на следующий элемент, который станет первым после 
    //извлечения текущего первого элемента.
    //% array_size используется для обеспечения цикличности индексов в массиве.
    first = (first + 1) % array_size;
    //После этого уменьшается значение переменной size на 1, чтобы отразить удаление одного элемента из очереди.
    size--;
}

int theFirstMeaning() 
{
    if (isEmpty()) 
    //В зависимости от результата этой проверки функция либо возвращает -1, 
    //если условие истинно, либо возвращает значение по индексу first в массиве arr, если условие ложно.
    {
        return -1;
    }

    return arr[first];
}

};

int main() 
{
Queue q;
q.enqueue(35);
q.enqueue(5);
q.enqueue(10);
q.enqueue(15);
q.enqueue(25);
q.enqueue(35);

std::cout << q.theFirstMeaning() << std::endl;
q.dequeue();
std::cout << q.theFirstMeaning() << std::endl;
q.dequeue();
std::cout << q.theFirstMeaning() << std::endl;

return 0;
}






