#include <iostream>
using namespace std;

class subvector {
private:
int* mas;
unsigned int top;
unsigned int capacity;
	
public:
	subvector() {
        this-> mas = NULL;
        this->top = 0;
        this->capacity = 0;
   	}
	
	
bool push_back(int d) {
if (this ->top + 1 > this ->capacity) {
	int* p = new int[this ->capacity + 1];
	for (int i = 0; i < this ->capacity; i++) {
		*(p + i) = *(this -> mas + i);
	    }
	
	if (this ->capacity > 0) delete[] this ->mas;
	this ->capacity++;
	this ->mas = p;
	*(this ->mas + this ->top) = d;
	this ->top++;
	}
else {
    *(this ->mas + this ->top) = d;
    this ->top++;
}
return true;
}
	
	
bool pop_back() {
	if (this ->top > 0) {
            this ->top--;
            int s = *(this ->mas + this ->top);
            return s;
        }
        else {
            return 0;
        }
}

	
bool resize(unsigned int new_capacity) {
        if (new_capacity > 0) {
            int* p = new int[new_capacity];
            for (int i = 0; i < this ->top; i++) {
                *(p + i) = *(this ->mas + i);
            }
            if (this ->capacity > 0) delete[] this ->mas;
            this ->capacity = new_capacity;
            this ->mas = p;
            if (new_capacity < this ->top) this ->top = new_capacity;
            return true;
        }
        else {
            if (this ->capacity > 0) delete[] this ->mas;
            this -> mas = NULL;
            this ->top = 0;
            this ->capacity = 0;
            return true;
        }
}	   
	
	
void shrink_to_fit() {
	if (this ->capacity > this ->top) {
            if (this ->top > 0) {
                int* p = new int[this ->top];
                for (int i = 0; i < this ->top; i++) {
                    *(p + i) = *(this ->mas + i);
                }
                delete[] this ->mas;
                this ->capacity = this ->top;
                this ->mas = p;
            }
	else {
        	delete[] this ->mas;
                this -> mas = NULL;
                this ->top = 0;
                this ->capacity = 0;
            }
        }
}
	
	
void clear() {
        this ->top = 0;
}
};
