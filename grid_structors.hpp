#ifndef GRID_STRUCTORS_HPP
# define GRID_STRUCTORS_HPP

// Constructor
#include "grid.hpp"
#include <cstddef>
template <typename T>
grid<T>::grid(size_t size_y, size_t size_x): _size_y(size_y), _size_x(size_x)
{
	_createGrid();
}

// Copy constructor
template <typename T>
grid<T>::grid(grid<T> & other)
{
	_deepCopy(other);
}

// Destructor
template <typename T>
grid<T>::~grid(void)
{
	_freeGrid();
}

template <typename T>
void	grid<T>::_freeGrid()
{
	if (!_isMalloced)
		return ;
	for (int y = 0; y < _size_y; ++y)
		delete[] _grid[y];
	delete[] _grid;
	_isMalloced = false;
	
}

template <typename T>
void	grid<T>::_createGrid()
{
	if (_isMalloced)
		_freeGrid();
	_grid = new T*[_size_y];
	for (int i = 0; i < _size_y; i++)
		_grid[i] = new T[_size_x]{};
	_isMalloced = true;
}

template <typename T>
void	grid<T>::_deepCopy(grid<T> const & other)
{
	this->resize(other.getSizeY(), other.getSizeX());
	*this = other;
}

#endif

