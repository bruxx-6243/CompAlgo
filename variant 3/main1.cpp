#include <iostream>

using namespace std;

struct Data {
	double data;
	Data* prev;
	Data* next;
};

class Deque_dynamic {
public:
	Deque_dynamic();
	~Deque_dynamic();

	void Add_first(double data);
	void Add_last(double data);
	void Get_first(double &data);
	void Get_last(double &data);

	bool is_empty();

	void print();
private:
	Data* first;
	Data* last;
};

Deque_dynamic::Deque_dynamic() {
	first = NULL;
	last  = NULL;
}

Deque_dynamic::~Deque_dynamic() {
	double x;
	while (!is_empty())
		Get_first(x);
}

void Deque_dynamic::Add_first(double data) {
	Data* n = new Data;
	n->prev = NULL;
	n->next = first;
	n->data = data;

	if (is_empty()) {
		last = n;
	}
	else {
		first->prev = n;
	}

	first = n;
}

void Deque_dynamic::Add_last(double data) {
	Data* n = new Data;
	n->prev = last;
	n->next = NULL;
	n->data = data;

	if (is_empty()) {
		first = n;
	}
	else {
		last->next = n;
	}

	last = n;
}

void Deque_dynamic::Get_first(double &data) {
	if (is_empty())
		return;
	
	data = first->data;

	if (first == last) {
		delete first; last = NULL; first = NULL;
	}
	else {
		Data* cur = first;
		first = first->next;
		first->prev = NULL;
		delete cur;
	}
}

void Deque_dynamic::Get_last(double &data) {
	if (is_empty())
		return;

	data = last->data;

	if (first == last) {
		delete last; first = NULL; first = NULL;
	}
	else {
		Data* cur = last;
		last = last->prev;
		last->next = NULL;
		delete cur;
	}
}

bool Deque_dynamic::is_empty() {
	return (first == NULL && last == NULL);
}

void Deque_dynamic::print() {
	if (is_empty()) {
		cout << "Deque empty!" << endl;
		return;
	}

	cout << "Deque_dynamic: ";
	Data* cur = first;
	while (cur) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

class Deque_static {
public:
	Deque_static(int size, double data);
	~Deque_static();

	void Add_first(double data);
	void Add_last(double data);
	void Get_first(double& data);
	void Get_last(double& data);

	bool is_empty();

	void print();
private:
	double* A;
	int first, last, length, size;
};

Deque_static::Deque_static(int size, double data) {
	this->size = size;
	A = new double[size];
	A[size / 2] = data;
	first = size / 2; last = size / 2; length = 1;
}

Deque_static::~Deque_static() {
	delete[] A;
}

void Deque_static::Add_first(double data) {
	if (length + 1 == size)
		return;

	length++;

	first--;
	if (first < 0)
		first = size + first;

	A[first] = data;
}

void Deque_static::Add_last(double data) {
	if (length + 1 == size)
		return;

	length++;

	last++;
	if(last == size)
		last = size - last;

	A[last] = data;
}

void Deque_static::Get_first(double& data) {
	if (is_empty())
		return;

	data = A[first];

	first++;
	if (first == size)
		first = size - first;

	length--;
}

void Deque_static::Get_last(double& data) {
	if (is_empty())
		return;

	data = A[last];

	last--;
	if (last < 0)
		last = size + last;

	length--;
}

bool Deque_static::is_empty() {
	return (length == 0);
}

void Deque_static::print() {
	if (is_empty()) {
		cout << "Deque empty!" << endl;
		return;
	}

	cout << "Deque_static: ";
	for (int i = first; i != last;) {
		cout << A[i] << " ";

		i++;
		if (i == size)
			i = size - i;
	}
	cout << endl;
}


int main() {
	Deque_dynamic d1;
	Deque_static d2(100, 9);

	for (int i = 0; i < 30; i += 3) {
		d1.Add_first(i - 20);
		d2.Add_first(i - 15);
	}
	

	for (int i = 0; i < 20; i += 2) {
		d1.Add_last(i);
		d2.Add_last(i);
	}
		
	d1.print();
	d2.print();

	return 0;
}