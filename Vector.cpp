#include "Vector.h"
#include <iostream>

class Vector
{
private:
	//Fields
	int* _elements;
	int _capacity; //Total memory allocated
	int _size; //Size of vector to access
	int _resizeFactor; // how many cells to add when need to reallocate
public:

	//A
	Vector(int n = 2)
	{
		if (n < 2)
		{
			n = 2;
		}
		this->_elements = new int[n];
		this->_capacity = n;
		this->_size = 0;
		this->_resizeFactor = n;
	}
	~Vector()
	{
		delete[] this->_elements;
		this->_capacity = 0;
		this->_size = 0;
		this->_resizeFactor = 0;
	}
	int size() const//return size of vector
	{
		return this->_size;
	}
	int capacity() const//return capacity of vector
	{
		return this->_capacity;
	}
	int resizeFactor() const//return vector's resizeFactor
	{
		return this->_resizeFactor;
	}
	bool empty() const//returns true if size = 0
	{
		return this->_size == 0;
	}

	//B
	//Modifiers
	void push_back(const int& val)//adds element at the end of the vector
	{
		if (this->_size == this->_capacity)
		{
			reserve(this->_capacity + this->_resizeFactor);
		}
		this->_elements[this->_size] = val;
		this->_size++;
	}
	int pop_back()//removes and returns the last element of the vector
	{
		int lastElement = this->_elements[this->_size - 1];
		this->_elements[this->_size - 1] = 0;
		this->_size--;
		return lastElement;
	}
	void reserve(const int n)//change the capacity
	{
		if (this->_capacity >= n)
		{
			return;
		}
		int* newElements = new int[n];
		for (int i = 0; i < this->_size; i++)
		{
			newElements[i] = this->_elements[i];
		}
		delete[] this->_elements;
		this->_elements = newElements;
		this->_capacity = n;
	}
	void resize(const int n)//change _size to n, unless n is greater than the vector's capacity
	{
		if (n > this->_capacity)
		{
			reserve(n);
		}
		this->_size = n;
	}
	void assign(const int val)//assigns val to all elemnts
	{
		for (int i = 0; i < this->_size; i++)
		{
			this->_elements[i] = val;
		}
	}
	void resize(const int n, const int& val)//same as above, if new elements added their value is val
	{
		if (n > this->_capacity)
		{
			reserve(n);
		}
		for (int i = this->_size; i < n; i++)
		{
			this->_elements[i] = val;
		}
		this->_size = n;
	}

	//C
	//The big three (d'tor is above)
	Vector(const Vector& other)
	{
		this->_elements = new int[other._capacity];
		for (int i = 0; i < other._size; i++)
		{
			this->_elements[i] = other._elements[i];
		}
		this->_capacity = other._capacity;
		this->_size = other._size;
		this->_resizeFactor = other._resizeFactor;
	}
	Vector& operator=(const Vector& other)
	{
		this->~Vector();
		this->_elements = new int[other._capacity];
		for (int i = 0; i < other._size; i++)
		{
			this->_elements[i] = other._elements[i];
		}
		this->_capacity = other._capacity;
		this->_size = other._size;
		this->_resizeFactor = other._resizeFactor;
		return *this;
	}

	//D
	//Element Access
	int& operator[](int n) const//n'th element
	{
		if (n >= this->_size || n < 0) {
			throw std::out_of_range("Index out of bounds");
		}
		return this->_elements[n];
	}


};