#include "arrayFunctions.cpp"
#include "Circle.h"
#include "Shape.h"
#include "Triangle.h"
#include <array>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

using namespace std;

Shape::Shape(vector<Triangle*> compTriangles, vector<Circle*> compCircles) {
	this->compTriangles = compTriangles;
	this->compCircles = compCircles;
}
Shape::Shape(vector<Circle*> compCircles) {
	this->compCircles = compCircles;
}
Shape::Shape(vector<Triangle*> compTriangles) {
	this->compTriangles = compTriangles;
}

Shape::Shape() {
}

void Shape::calculateMass( ) {
	float triangleMass = 0;
	float circleMass = 0;

	for ( Triangle*& compTriangle : compTriangles ) {
		triangleMass += compTriangle->getMass( );
	}
	for ( Circle*& compCircle : compCircles ) {
		circleMass += compCircle->getMass( );
	}
	
	mass = triangleMass + circleMass;
}

void Shape::calculateMidpoint( ) {
	
	float trianglesMass = 0;
	array<float, 2> trianglesMidpoint = { 0, 0 };

	for ( Triangle*& compTriangle: compTriangles ) {
		trianglesMidpoint += compTriangle->getMidpoint();
		trianglesMass += compTriangle->getMass( );
	}


	float circlesMass = 0;
	array<float, 2> circlesMidpoint = { 0, 0 };

	for ( Circle*& compCircle : compCircles ) {
		circlesMidpoint += compCircle->getMidpoint( );
		circlesMass += compCircle->getMass( );
	}

	midpoint = ( trianglesMidpoint * trianglesMass ) + ( circlesMidpoint * circlesMass );
	calculateMass( );
	midpoint /= mass;
}

void Shape::draw(sf::RenderWindow& window, sf::Color drawColor) {
	for ( Triangle*& drawTriangle : compTriangles ) {
		drawTriangle->draw(window, drawColor);
	}
	for ( Circle*& drawCircle : compCircles ) {
		drawCircle->draw(window, drawColor);
	}
}

//
//NOTE: for every collision check every triangle calculates lineSidePairs, once I implement frames the triangles will recalcualte only once per frame

bool Shape::isColliding(Shape& checkShape) {

	vector<Circle*> checkCompCircles = checkShape.getCompCircles( );

	vector<Triangle*> checkCompTriangles = checkShape.getCompTriangles( );

	//NOTE: V this line V  will be removed once frames are implemented
	for ( Triangle*& checkCompTriangle : checkCompTriangles ) { checkCompTriangle->findLineSidePairs( ); }

	for ( Triangle*& CompTriangle : compTriangles ) {

		//NOTE: V this line V  will be removed once frames are implemented
		CompTriangle->findLineSidePairs( );

		for ( Circle*& checkCompCircle : checkCompCircles ) {

			if ( CompTriangle->isCollidingCircle(checkCompCircle) ) {
				return true;
			}
		}

		for ( Triangle*& checkCompTriangle : checkCompTriangles ) {

			if ( CompTriangle->isCollidingTriangle(checkCompTriangle) ) {
				return true;
			}

		}

	}


	for ( Circle*& CompCircle : compCircles ) {

		for ( Triangle*& checkCompTriangle : checkCompTriangles ) {

			if ( CompCircle->isCollidingTriangle(checkCompTriangle) ) {
				return true;
			}

		}

		for ( Circle*& checkCompCircle : checkCompCircles ) {

			if ( CompCircle->isCollidingCircle(checkCompCircle) ) {
				return true;
			}
		}

	}
	return false;
}

vector<Shape> Shape::listColliding(vector<Shape>& checkShapeList) {
	vector<Shape> collidingShapes = vector<Shape> { {} };
	for ( Shape& checkShape : checkShapeList ) {
		if ( this->isColliding(checkShape) ) {
			collidingShapes.insert(collidingShapes.begin( ), checkShape);
		}
	}
	return collidingShapes;
}