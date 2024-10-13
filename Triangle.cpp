#include "arrayFunctions.cpp"
#include "Circle.h"
#include "Triangle.h"
#include <array>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <tuple>

using namespace std;

// averages position of vertices

void Triangle::calculateMidpoint( ) {
	midpoint = { {0,0} };
	for ( array<float, 2>& vertex : vertices ) {
		midpoint += vertex;
	}
	midpoint /= 3;
}

void Triangle::draw(sf::RenderWindow& window, sf::Color drawColor) {
	sf::ConvexShape drawTriangle;
	drawTriangle.setPointCount(3);
	drawTriangle.setPoint(0, sf::Vector2f(vertices[0][0], vertices[0][1]));
	drawTriangle.setPoint(1, sf::Vector2f(vertices[1][0], vertices[1][1]));
	drawTriangle.setPoint(2, sf::Vector2f(vertices[2][0], vertices[2][1]));
	drawTriangle.setFillColor(drawColor);
	window.draw(drawTriangle);
}

// defines a function for a point slope line with A and B then checks if Cy is greater than f(Cx)

bool Triangle::findSideOfLine(float slope, array<float, 2> A, array<float, 2> C) {
	if ( C[1] <= ( slope * ( C[0] - A[0] ) ) + A[1] ) {
		return false;
	}
	return true;
}

// calculates and stores data for slopeAB, pointA, and sideC in a tuple

void Triangle::findLineSidePairs( ) {
	for ( int i = 0; i < 3; i++ ) {
		get<0>(lineSidePairs[i]) = ( vertices[i][1] - vertices[( i + 1 ) % 3][1] ) / ( vertices[i][0] - vertices[( i + 1 ) % 3][0] );
		get<1>(lineSidePairs[i]) = vertices[i];
		get<2>(lineSidePairs[i]) = findSideOfLine(get<0>(lineSidePairs[i]), vertices[i], vertices[( i + 2 ) % 3]);
	}
}

//when checking for collision both triangles need to be tested for dividing edges

bool Triangle::isCollidingTriangle(Triangle* checkTriangle) {
	
	array<array<float, 2>, 3> checkVertices = checkTriangle->getVertices( );

	array<tuple<float, array<float, 2>, bool>, 3> checkLineSidePairs = checkTriangle->getLineSidePairs();

	for ( int i = 0; i < 3; i++ ) {
		for ( int j = 0; j < 3; j++) {
			if ( findSideOfLine(get<0>(lineSidePairs[i]), get<1>(lineSidePairs[i]), checkVertices[j]) == get<2>(lineSidePairs[i]) ) {
				break;
			}
			if ( j == 2 ) {
				return false;
			}
		}
	}

	for ( int i = 0; i < 3; i++ ) {
		for ( int j = 0; j < 3; j++ ) {
			if ( findSideOfLine(get<0>(checkLineSidePairs[i]), get<1>(checkLineSidePairs[i]), vertices[j]) == get<2>(checkLineSidePairs[i]) ) {
				break;
			}
			if ( j == 2 ) {
				return false;
			}
		}
	}

	return true;
}

//not that complicated 

bool Triangle::isCollidingCircle(Circle* checkCircle) {
	return checkCircle->isCollidingTriangle(this);
}

Triangle::Triangle(array<array<float, 2>, 3> verteces, float mass) {
	this->vertices = verteces;
	this->mass = mass;
}