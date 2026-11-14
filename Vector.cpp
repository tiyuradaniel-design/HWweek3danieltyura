#include "Vector.h"

class Vector
{
private:
	int* _elements;
	int _size;
	int _capacity;
	int _resizeFactor;
public:
	Vector(int n) 
	{
		_size = 0;
		_capacity = n;
		_resizeFactor = 2;
		_elements = new int[_capacity];
	}
	~Vector() 
	{
		delete[] _elements;
	}
	int size() 
	{
		return _size;
	}
	int capacity() 
	{
		return _capacity;
	}
	int resizeFactor() 
	{
		return _resizeFactor;
	}
	bool empty() 
	{
		return _size == 0;
	}

};