#pragma once

#include <array>
#include <vector>

using namespace std;

//assignment
//vector
template <typename _Ty, size_t N>
void operator+=(array<_Ty, N>& leftSide, array<_Ty, N> rightSide) {
	for ( int i = 0; i < N; i++ ) {
		leftSide [i] += rightSide [i];
	}
}

template <typename _Ty, size_t N>
void operator-=(array<_Ty, N>& leftSide, array<_Ty, N> rightSide) {
	for ( int i = 0; i < N; i++ ) {
		leftSide [i] -= rightSide [i];
	}
}

template <typename _Ty, size_t N>
void operator*=(array<_Ty, N>& leftSide, array<_Ty, N> rightSide) {
	for ( int i = 0; i < N; i++ ) {
		leftSide [i] *= rightSide [i];
	}
}

template <typename _Ty, size_t N>
void operator/=(array<_Ty, N>& leftSide, array<_Ty, N> rightSide) {
	for ( int i = 0; i < N; i++ ) {
		leftSide [i] /= rightSide [i];
	}
}

//scaler

template <typename _Ty, size_t N>
void operator+=(array<_Ty, N>& leftSide, float rightSide) {
	for ( int i = 0; i < N; i++ ) {
		leftSide [i] += rightSide;
	}
}

template <typename _Ty, size_t N>
void operator-=(array<_Ty, N>& leftSide, float rightSide) {
	for ( int i = 0; i < N; i++ ) {
		leftSide [i] -= rightSide;
	}
}

template <typename _Ty, size_t N>
void operator*=(array<_Ty, N>& leftSide, float rightSide) {
	for ( int i = 0; i < N; i++ ) {
		leftSide [i] *= rightSide;
	}
}

template <typename _Ty, size_t N>
void operator/=(array<_Ty, N>& leftSide, float rightSide) {
	for ( int i = 0; i < N; i++ ) {
		leftSide [i] /= rightSide;
	}
}


//arithmatic
//vector
template <typename _Ty, size_t N>
array<_Ty, N> operator+(array<_Ty, N> leftSide, array<_Ty, N> rightSide) {
	array<_Ty, N> resultArray = leftSide;
	resultArray += rightSide;
	return resultArray;
}

template <typename _Ty, size_t N>
array<_Ty, N> operator-(array<_Ty, N> leftSide, array<_Ty, N> rightSide) {
	array<_Ty, N> resultArray = leftSide;
	resultArray -= rightSide;
	return resultArray;
}

template <typename _Ty, size_t N>
array<_Ty, N> operator*(array<_Ty, N> leftSide, array<_Ty, N> rightSide) {
	array<_Ty, N> resultArray = leftSide;
	resultArray *= rightSide;
	return resultArray;
}

template <typename _Ty, size_t N>
array<_Ty, N> operator/(array<_Ty, N> leftSide, array<_Ty, N> rightSide) {
	array<_Ty, N> resultArray = leftSide;
	resultArray /= rightSide;
	return resultArray;
}

//scaler
template <typename _Ty, size_t N>
array<_Ty, N> operator+(array<_Ty, N> leftSide, float rightSide) {
	array<_Ty, N> resultArray = leftSide;
	resultArray += rightSide;
	return resultArray;
}

template <typename _Ty, size_t N>
array<_Ty, N> operator-(array<_Ty, N> leftSide, float rightSide) {
	array<_Ty, N> resultArray = leftSide;
	resultArray -= rightSide;
	return resultArray;
}

template <typename _Ty, size_t N>
array<_Ty, N> operator*(array<_Ty, N> leftSide, float rightSide) {
	array<_Ty, N> resultArray = leftSide;
	resultArray *= rightSide;
	return resultArray;
}

template <typename _Ty, size_t N>
array<_Ty, N> operator/(array<_Ty, N> leftSide, float rightSide) {
	array<_Ty, N> resultArray = leftSide;
	resultArray += rightSide;
	return resultArray;
}


//vector = array

template <typename _Ty, size_t N>
void copy(vector<_Ty>& vec, array<_Ty, N> arr) {
	vec.clear( );
	vec.insert(vec.end( ), arr.begin( ), arr.end( ));
}
