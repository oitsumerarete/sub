#include <iostream>
using namespace std;

struct subvector {
	int* mas;
	unsigned int top;
	unsigned int capacity;
};


bool init(subvector* qv) {

	qv->mas = NULL;
	qv->top = 0;
	qv->capacity = 0;
	return true;
};


bool push_back(subvector* qv, int d) {

	if (qv->top + 1 > qv->capacity) {
		int* p = new int[qv->capacity + 1];
		for (int i = 0; i < qv->capacity; i++) {
			*(p + i) = *(qv->mas + i);
		}
		if (qv->capacity > 0) delete[] qv->mas;
		qv->capacity++;
		qv->mas = p;
		*(qv->mas + qv->top) = d;
		qv->top++;
	}
	else {
		*(qv->mas + qv->top) = d;
		qv->top++;
	}
	return true;
}


int pop_back(subvector* qv) {

	if (qv->top > 0) {
		qv->top--;
		int e = *(qv->mas + qv->top);
		return e;
	}
	else {
		return 0;
	}
}


bool resize(subvector* qv, unsigned int new_capacity) {

	if (new_capacity > 0) {
		int* p = new int[new_capacity];
		for (int i = 0; i < qv->top; i++) {
			*(p + i) = *(qv->mas + i);
		}
		if (qv->capacity > 0) delete[] qv->mas;
		qv->capacity = new_capacity;
		qv->mas = p;
		if (new_capacity < qv->top) qv->top = new_capacity;
		return true;
	}
	else
	{
		if (qv->capacity > 0) delete[] qv->mas;
		init(qv);
		return true;
	}
}

void shrink_to_fit(subvector* qv) {

	if (qv->capacity > qv->top) {
		if (qv->top > 0) {
			int* p = new int[qv->top];
			for (int i = 0; i < qv->top; i++) {
				*(p + i) = *(qv->mas + i);
			}
			delete[] qv->mas;
			qv->capacity = qv->top;
			qv->mas = p;
		}
		else {
			delete[] qv->mas;
			init(qv);
		}
	}
}


void clear(subvector* qv) {

	qv->top = 0;
}


void destructor(subvector* qv) {

	delete[] qv->mas;
	init(qv);
}


