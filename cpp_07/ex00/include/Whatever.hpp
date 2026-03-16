#pragma once

template <typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const min(T &a, T &b){
	if(a < b)
		return a;
	return b;
}

template <typename T>
T const max(T &a, T &b){
	if(a > b)
		return a;
	return b;
}
