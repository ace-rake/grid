#ifndef GRID_TRANSFORMERS_HPP
# define GRID_TRANSFORMERS_HPP

#include "grid.hpp"

template <typename T>
void	grid<T>::resize(size_t newY, size_t newX)
{
	grid<T> copy(newY, newX);
	copy = *this;
	_freeGrid();
	_size_y = newY;
	_size_x = newX;
	_createGrid();
	*this = copy;
}

#endif

