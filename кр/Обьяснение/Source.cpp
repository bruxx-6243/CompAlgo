+#include <iostream>
#include <time.h>

using namespace std;

//Класс статической двойной очереди:
class Deque {
public:
	Deque(int size, int data);	//Инициализация с начальным элементом
	~Deque();					//Очищение памяти

	void push_first(int x);		//Функция добавляет элемент в начало очереди
	void push_last(int x);		//Функция добавляет элемент в конец  очереди
	void pop_first(int& x);		//Функция берет элемент из начала очереди
	void pop_last(int& x);		//Функция берет элемент из конца  очереди

	bool is_empty();			//Проверка на то что очередь пуста

	void print();				//Вывод очереди в консоль
private:
	int* Arr;					//Указатель на массив очереди
	int length, size;			//Текущая длина очереди и Полная длина массива очереди
	int first, last;			//Значения на первый и последний элемент очереди
};

Deque::Deque(int size, int x) {
	this->size = size;			
	Arr = new int[size];

	Arr[size / 2] = x;									//Первый элемент очереди положим в середину массива
	first = size / 2; last = size / 2; length = 1;		//Начало = середина, Конец = середина, длина = 1
}

Deque::~Deque() {
	delete[] Arr;				//Освобождение памяти
}

void Deque::push_first(int x) {
	if (length + 1 == size) {			//Проверка на переполнение очереди
		cout << "Deque overflows!" << endl;
		return;
	}

	length++;

	first--;
	if (first < 0)						//Зацикливание очереди
		first = size + first;

	Arr[first] = x;
}

void Deque::push_last(int x) {
	if (length + 1 == size) {			//Проверка на переполнение очереди
		cout << "Deque overflows!" << endl;
		return;
	}
		

	length++;

	last++;
	if (last == size)					//Зацикливание очереди
		last = size - last;

	Arr[last] = x;
}

void Deque::pop_first(int& x) {
	if (is_empty()) {					//Проверка на пустоту очереди
		cout << "Deque empty!" << endl;
		return;
	}

	x = Arr[first];

	first++;
	if (first == size)					//Зацикливание очереди
		first = size - first;

	length--;
}

void Deque::pop_last(int& x) {
	if (is_empty()) {					//Проверка на пустоту очереди
		cout << "Deque is empty!" << endl;
		return;
	}

	x = Arr[last];

	last--;
	if (last < 0)						//Зацикливание очереди
		last = size + last;

	length--;
}

bool Deque::is_empty() {
	return (length == 0);
}

void Deque::print() {
	if (is_empty()) {					//Проверка на пустоту очереди
		cout << "Deque is empty!" << endl;
		return;
	}

	cout << "Deque_static: ";
	for (int i = first; i != last;) {
		cout << Arr[i] << " ";

		i++;
		if (i == size)
			i = size - i;
	}
	cout << endl;
}


int main() {
	srand(time(NULL));
	Deque d2(50, rand() % 1000);		//Создаем очередь на 50 элементов с случайным начальным числом

	for (int i = 0; i < 50 / 2; i++)	//Добавление в начало очереди 25 элементов
		d2.push_first(rand() % 1000);
	
	for (int i = 0; i < 50 / 2; i++)	//Добавление в конец очереди 25 элементов
		d2.push_last(rand() % 1000);

	d2.print();							//Вывод очереди в консоль

	return 0;
}