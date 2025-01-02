#ifndef GRID_ACCESSORS_HPP
# define GRID_ACCESSORS_HPP


#include <cstddef>
// Accessors
template <typename T>
T &	grid<T>::at(size_t y, size_t x)const
{
	if (_outOfBounds(y, x))
		_throwOutOfBounds();
	return _grid[y][x];
}

template <typename T>
T &	grid<T>::at(pair<int, int> coords)const
{
	return at(coords.first, coords.second);
}
#endif

