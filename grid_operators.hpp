#ifndef GRID_OPERATORS_HPP
# define GRID_OPERATORS_HPP


// Operator overloads
#include "grid.hpp"
#include <iostream>
#include <ostream>
template <typename T>
void	grid<T>::operator=(T other)
{
	this->fill(other);
}

template <typename T>
void	grid<T>::operator=(const grid<T> & other)
{
	_freeGrid();
	_size_x = other.getSizeX();
	_size_y = other.getSizeY();
	_createGrid();
	for (int y = 0; y < _size_y; y++)
		for (int x = 0; x < _size_x; x++)
			at(y, x) = other.at(y, x);
}


// << operator
template <typename T>
std::ostream& operator<<(std::ostream & o, const grid<T> & g)
{
	size_t xSize = g.getSizeX();
	size_t ySize = g.getSizeY();
	for (int y = 0; y < ySize; ++y)
	{
		for (int x = 0; x < xSize; ++x)
			std::cout << "[" << g.at(y, x) << "]";
		std::cout << std::endl;
	}
	return o;
}
template <>
inline ostream& operator<<(ostream & o, const grid<bool> & g)
{
	size_t xSize = g.getSizeX();
	size_t ySize = g.getSizeY();
	for (int y = 0; y < ySize; ++y)
	{
		for (int x = 0; x < xSize; ++x)
		{
			std::cout << "[" << (g.at(y, x) == true ? "\033[32;1m1" : "\033[31;1m0") << "\033[0m]";
		}
		std::cout << std::endl;
	}
	return o;
}

#endif

