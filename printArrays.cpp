
#include "Circle.h"
#include "Shape.h"
#include "Triangle.h"
#include <array>
#include <iosfwd>
#include <iostream>
#include <vector>

using namespace std;

template <typename _Ty, size_t N>
inline ostream& operator<<(ostream& os, array<_Ty, N> printArray) {
	os << "< ";
	for ( _Ty& posN : printArray ) {
		os << posN;
		os << ", ";
	}
	os << ">";
	return os;
}

template <typename _Ty>
inline ostream& operator<<(ostream& os, vector<_Ty> printVector) {
	os << "< ";
	for (_Ty& posN : printVector ) {
		os << posN;
		os << ", ";
	}
	os << ">";
	return os;
}


inline static ostream& operator<<(ostream& os, Triangle* printShape) {
	os << printShape->getVertices( );
	return os;
}

inline static ostream& operator<<(ostream& os, Circle* printShape) {
	os << printShape->getMidpoint( );
	return os;
}

inline static ostream& operator<<(ostream& os, Shape printShape) {
	os << "< ";
	for (Circle*& posN : printShape.getCompCircles()) {
		os << posN;
		os << ", ";
	}
	for (Triangle*& posN : printShape.getCompTriangles() ) {
		os << posN;
		os << ", ";
	}
	os << ">";
	return os;
}
