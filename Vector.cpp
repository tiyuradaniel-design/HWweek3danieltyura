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
		_elements = new int[n];
		_capacity = n;
		_size = 0;
		_resizeFactor = n;
	}
	~Vector()
	{
		delete[] _elements;
	}
	int size() const//return size of vector
	{
		return _size;
	}
	int capacity() const//return capacity of vector
	{
		return _capacity;
	}
	int resizeFactor() const//return vector's resizeFactor
	{
		return _resizeFactor;
	}
	bool empty() const//returns true if size = 0
	{
		return _size == 0;
	}

	//B
	//Modifiers
	void push_back(const int& val)//adds element at the end of the vector
	{
		if (_size == _capacity)
		{
			reserve(_capacity + _resizeFactor);
		}
		_elements[_size] = val;
		_size++;
	}
	int pop_back()//removes and returns the last element of the vector
	{
		int lastElement = _elements[_size - 1];
		_elements[_size - 1] = 0;
		_size--;
		return lastElement;
	}
	void reserve(const int n)//change the capacity
	{
		if (_capacity >= n)
		{
			return;
		}
		int* newElements = new int[n];
		for (int i = 0; i < _size; i++)
		{
			newElements[i] = _elements[i];
		}
		delete[] _elements;
		_elements = newElements;
		_capacity = n;
	}
	void resize(const int n)//change _size to n, unless n is greater than the vector's capacity
	{
		if (n > _capacity)
		{
			reserve(n);
		}
		_size = n;
	}
	void assign(const int val)//assigns val to all elemnts
	{
		for (int i = 0; i < _size; i++)
		{
			_elements[i] = val;
		}
	}
	void resize(const int n, const int& val)//same as above, if new elements added their value is val
	{
		if (n > _capacity)
		{
			reserve(n);
		}
		for (int i = _size; i < n; i++)
		{
			_elements[i] = val;
		}
		_size = n;
	}

	//C
	//The big three (d'tor is above)
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);

	//D
	//Element Access
	int& operator[](int n) const;//n'th element

};