#include <iostream>
#include <time.h>

using namespace std;


class Deque {
public:
	Deque(int size, int data);  
	~Deque();   

	void push_first(int x);    
	void push_last(int x);     
	void pop_first(int& x);
	void pop_last(int& x);

	bool is_empty();

	void print();
	
private:
	int* Arr;
	int length, size;
	int first, last;
};

Deque::Deque(int size, int x) {
	this->size = size;
	Arr = new int[size];

	Arr[size / 2] = x;
	first = size / 2; last = size / 2; length = 1;
}

Deque::~Deque() {
	delete[] Arr;
}

void Deque::push_first(int x) {
	if (length + 1 == size)
		return;

	length++;

	first--;
	if (first < 0)
		first = size + first;

	Arr[first] = x;
}

void Deque::push_last(int x) {
	if (length + 1 == size)
		return;

	length++;

	last++;
	if (last == size)
		last = size - last;

	Arr[last] = x;
}

void Deque::pop_first(int& x) {
	if (is_empty())
		return;

	x = Arr[first];

	first++;
	if (first == size)
		first = size - first;

	length--;
}

void Deque::pop_last(int& x) {
	if (is_empty())
		return;

	x = Arr[last];

	last--;
	if (last < 0)
		last = size + last;

	length--;
}

bool Deque::is_empty() {
	return (length == 0);
}

void Deque::print() {
	if (is_empty()) {
		cout << "Deque empty!" << endl;
		return;
	}

	cout << "static_deque: ";
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
	Deque d2(50, 10);

	for (int i = 0; i < 30; i += 3) 
		d2.push_first( i - 20);
	
	for (int i = 0; i < 20 ; i+=2) 
		d2.push_last(i);

	d2.print();

	return 0;
}