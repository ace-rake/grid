#ifndef GRID_GETTERS_HPP
# define GRID_GETTERS_HPP


// Getters
template <typename T>
size_t	grid<T>::getSizeY()const
{
	return _size_y;
}

template <typename T>
size_t	grid<T>::getSizeX()const
{
	return _size_x;
}

template <typename T>
T&	grid<T>::get(int y, int x)const
{
	return _grid[y][x];
}

template <typename T>
bool	grid<T>::isMalloced()const
{
	return _isMalloced;
}

#endif
