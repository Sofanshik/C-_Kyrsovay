#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

template <class T>
class  Vector
{
public:

	typedef T* iterator;

	Vector();
	Vector(unsigned int size);
	Vector(unsigned int size, const T& initial);
	Vector(const Vector<T>& v);
	~Vector();

	unsigned int capacity() const;
	unsigned int size() const;
	bool empty() const;
	void show();
	iterator begin();
	iterator end();
	T& front();
	T& back();
	void push_back(const T& value);
	void push_front(const T& value);
	void push_to_index(const T& value, unsigned int index);

	void pop_back();
	void pop_front();
	void pop_of_index(unsigned int index);

	void reserve(unsigned int capacity);
	void resize(unsigned int size);

	T& operator[](unsigned int index);
	Vector<T>& operator=(const Vector<T>&);
	void clear();
private:
	unsigned int my_size;
	unsigned int my_capacity;
	T* buffer;
};

// Your code goes here ...
template<class T>
Vector<T>::Vector()
{
	my_capacity = 0;
	my_size = 0;
	buffer = 0;
}

template<class T>
Vector<T>::Vector(const Vector<T>& v)
{
	my_size = v.my_size;
	my_capacity = v.my_capacity;
	buffer = new T[my_size];
	for (unsigned int i = 0; i < my_size; i++)
		buffer[i] = v.buffer[i];
}

template<class T>
Vector<T>::Vector(unsigned int size)
{
	my_capacity = size;
	my_size = size;
	buffer = new T[size];
}

template<class T>
Vector<T>::Vector(unsigned int size, const T& initial)
{
	my_size = size;
	my_capacity = size;
	buffer = new T[size];
	for (unsigned int i = 0; i < size; i++)
		buffer[i] = initial;
}

template<class T>
Vector<T>& Vector<T>::operator = (const Vector<T>& v)
{
	delete[] buffer;
	my_size = v.my_size;
	my_capacity = v.my_capacity;
	buffer = new T[my_size];
	for (unsigned int i = 0; i < my_size; i++)
		buffer[i] = v.buffer[i];
	return *this;
}

template<class T>
typename Vector<T>::iterator Vector<T>::begin()
{
	return buffer;
}

template<class T>
typename Vector<T>::iterator Vector<T>::end()
{
	return buffer + size();
}

template<class T>
T& Vector<T>::front()
{
	return buffer[0];
}

template<class T>
T& Vector<T>::back()
{
	return buffer[my_size - 1];
}

template<class T>
void Vector<T>::push_back(const T& v)
{
	if (my_size >= my_capacity)
		reserve(my_capacity + 1);// +1 - were +5
	buffer[my_size++] = v;
}

template<class T>
void Vector<T>::push_front(const T& value)
{
	if (my_size >= my_capacity)
		reserve(my_capacity + 1);// +1 - were +5
	reverse(buffer, buffer + my_size);
	buffer[my_size++] = value;
	reverse(buffer, buffer + my_size);
}

template<class T>
void Vector<T>::push_to_index(const T& value, unsigned int index)
{
	if (my_size >= my_capacity)
		resize(my_size + 1);
	unsigned int second_capacity;
	T* Newbuffer = new T[second_capacity = my_capacity];
	//ѕроходимс€ по массиву, если нашли нужный индекс, перемещаем элемент на это место
	//и далее копируем в новый массив элементы старого.
	for (int i = 0; i < my_capacity; i++) {
		if (i == index) {
			Newbuffer[i] = value;
		}
		else if (i > index) {
			Newbuffer[i] = buffer[i - 1];
		}
		else {
			Newbuffer[i] = buffer[i];
		}
	}delete[] buffer;
	buffer = Newbuffer;
}

template<class T>
void Vector<T>::pop_back()
{
	buffer[my_size].~T();
	my_size--;
}

template<class T>
inline void Vector<T>::pop_front()
{
	reverse(buffer, buffer + my_size);
	buffer[my_size].~T();
	my_size--;
	reverse(buffer, buffer + my_size);
}

template<class T>
inline void Vector<T>::pop_of_index(unsigned int index)
{
	//написать трай катч если индекс = или < 0
	unsigned int second_capacity;
	T* Newbuffer = new T[second_capacity = my_capacity];
	//ѕроходимс€ по массиву, если нашли нужный индекс, перемещаем элемент на это место
	//и далее копируем в новый массив элементы старого.
	for (int i = 0; i < my_capacity; i++) {
		if (i == index) {
		}
		else if (i > index) {
			Newbuffer[i - 1] = buffer[i];
		}
		else {
			Newbuffer[i] = buffer[i];
		}
	}
	delete[] buffer;
	buffer = Newbuffer;
	my_size--;
}

template<class T>
void Vector<T>::reserve(unsigned int capacity)
{
	if (buffer == 0)
	{
		my_size = 0;
		my_capacity = 0;
	}
	T* Newbuffer = new T[capacity];
	//assert(Newbuffer);
	unsigned int l_Size = capacity < my_size ? capacity : my_size;
	//copy (buffer, buffer + l_Size, Newbuffer);

	for (unsigned int i = 0; i < l_Size; i++)
		Newbuffer[i] = buffer[i];

	my_capacity = capacity;
	delete[] buffer;
	buffer = Newbuffer;
}

template<class T>
unsigned int Vector<T>::size()const//
{
	return my_size;
}

template<class T>
bool Vector<T>::empty() const
{
	if (my_capacity <= 0 && my_size <= 0) {
		return false;
	}
	return true;
}

template<class T>
void Vector<T>::show()
{
	for (int i = 0; i < my_size; i++) {
		cout << buffer[i] << endl;
	}

}

template<class T>
void Vector<T>::resize(unsigned int size)
{
	reserve(size);
	my_size = size;
}

template<class T>
T& Vector<T>::operator[](unsigned int index)
{
	return buffer[index];
}

template<class T>
unsigned int Vector<T>::capacity()const
{
	return my_capacity;
}

template<class T>
Vector<T>::~Vector()
{
	delete[] buffer;
}
template <class T>
void Vector<T>::clear()
{
	my_capacity = 0;
	my_size = 0;
	buffer = 0;
	delete[] buffer; // add this string
}
