#ifndef GRID_INSERTERS_HPP
# define GRID_INSERTERS_HPP

#include "grid.hpp"
#include <cstddef>
template <typename T>
void	grid<T>::insert(T t, size_t y, size_t x)
{
	if (_outOfBounds(y, x))
		_throwOutOfBounds();	
	at(y, x) = t;
}

template <typename T>
void	grid<T>::insert(T t, pair<int, int> p)
{
	insert(t, p.first, p.second);
}

template <typename T>
void	grid<T>::insertRow(T t, size_t y)
{
	if (_outOfYBounds(y))
		_throwOutOfBounds();
	for (size_t x = 0; x < _size_x; ++x)
		insert(t, y, x);
}

template <typename T>
void	grid<T>::insertColumn(T t, size_t x)
{
	if (_outOfXBounds(x))
		_throwOutOfBounds();
	for (size_t y = 0; y < _size_y; ++y)
		insert(t, y, x);
}

template <typename T>
void	grid<T>::fill(T t)
{
	for (int y = 0; y < _size_y; ++y)
		for (int x = 0; x < _size_x; ++x)
			insert(t, y, x);
}

template <typename T>
void	grid<T>::insertString(string str, size_t y)
{
	if (_outOfYBounds(y))
		_throwOutOfBounds();
	if (_outOfXBounds(str.size()))
		cout <<  "WARNING:"  << "String is too long, some data will be lost" << endl;
	for (int x = 0; x < (str.size() > _size_x? _size_x: str.size()); x++)
		insert(str[x], y, x);

}
#endif

