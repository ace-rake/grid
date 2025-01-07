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

#endif

