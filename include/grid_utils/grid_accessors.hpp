#ifndef GRID_ACCESSORS_HPP
# define GRID_ACCESSORS_HPP


// Accessors
#include <cstddef>
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

template <typename T>
typename grid<T>::iterator	grid<T>::search(T toSearch)const
{
	for (auto it = this->begin(); it != this->end(); it++)
		if (*it == toSearch)
			return it;
	return this->end();
}
#endif
