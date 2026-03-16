#pragma once

#include <iostream>

template <typename T, typename F>
void	iter(T *array, const std::size_t length, F function) {
	if(!array)
		return;
	for (std::size_t i = 0; i < length; i++)
		function(array[i]);
}
