#include <iostream>
using namespace std;

struct subforwardlist {
	int data;
	subforwardlist* next;
};

bool init(subforwardlist** sfl) {

	*sfl = NULL;
	return true;
}


bool push_back(subforwardlist** sfl, int d) {

	subforwardlist* tmp = new subforwardlist;
	tmp->data = d;
	tmp->next = NULL;
	subforwardlist* tmp1 = *sfl;
	while (*sfl != NULL) {
		sfl = &((*sfl)->next);
	}
	*sfl = tmp;
	return true;
}


int pop_back(subforwardlist** sfl) {

    if (*sfl != NULL) {
        subforwardlist* tmp = (*sfl);
        int e = 0;
        if (tmp->next != NULL){
            subforwardlist* prev = NULL;
            while (tmp->next != NULL) {
                prev = tmp;
                tmp = tmp->next;
            }
            e = tmp->data;
            prev->next = NULL;
            delete tmp;
            return e;
        }
        else {
            e = tmp->data;
            delete tmp;
            (*sfl) = NULL;
            return e;
        }
    }
    else
        return 0;
}


bool push_forward(subforwardlist** sfl, int d) {

	subforwardlist* tmp = new subforwardlist;
	tmp->next = (*sfl);
	tmp->data = d;
	*sfl = tmp;
	return true;
}


unsigned int size(subforwardlist** sfl) {

	unsigned int size = 0;
	while (*sfl != NULL) {
		sfl = &((*sfl)->next);
		size++;
	}
	return size;
}


int pop_forward(subforwardlist** sfl) {

    if (size(sfl) == 0) return false;
	subforwardlist* tmp = (*sfl)->next;
	int e = (*sfl)->data;
	delete *sfl;
	*sfl = tmp;
	return e;
}


bool push_where(subforwardlist** sfl, unsigned int where, int d) {

    if (where > size(sfl)+1)
        return false;

	subforwardlist* tmp = new subforwardlist;
	tmp->data = d;
	for (int i = 2; i < where; i++) {
		sfl = &((*sfl)->next);
	}
	tmp->next = (*sfl)->next;
	(*sfl)->next = tmp;
	return true;
}


bool erase_where(subforwardlist** sfl, unsigned int where) {

	for (int i = 2; i < where; i++) {
		sfl = &((*sfl)->next);
	}
	subforwardlist* tmp = (*sfl)->next->next;
	delete (*sfl)->next;
	(*sfl)->next = tmp;
	return true;
}


void clear(subforwardlist** sfl) {

	if (*sfl == NULL) return;
	clear(&((*sfl)->next));
	delete *sfl;
	*sfl = NULL;
	return;
}

void print(subforwardlist* sfl) {

	while (sfl != NULL) {
		cout << sfl->data << " ";
		sfl = (sfl)->next;
	}
	cout << endl;
	return;
}

