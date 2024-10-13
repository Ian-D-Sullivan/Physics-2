#pragma once
#include <array>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <tuple>

using namespace std;

class Circle;

class Triangle{

private:

	//self explanitory data regarding simple characteristics of a triangle 

	array<array<float, 2>, 3> vertices = { { {0,0},{0,0},{0,0} } }; 

	array<float, 2> midpoint = { {0, 0} };

	float mass = 0;

	void calculateMidpoint ( );

	/*
	Triangle Triangle collision detection relies on finding a dividing line between the Triangles
	The edges of the Triangles work as dividing the lines 
	Points A and B form a line and C is used to check the side of the line the triangle is on
	Cy <= ( slopeAB * ( Cx - Ax)) + Ay ) detects the side of the line that point C is on (true == up, false == down)
	finally the data (slope, pointA, sideC) is stored in a tuple for quicker access when doing multiple collision detections
	the proccess is repeated 3 times for each possible edge
	*/

	bool findSideOfLine(float, array<float, 2>, array<float, 2>);

	array<tuple<float, array<float, 2>, bool>, 3> lineSidePairs;

	

public:

	void findLineSidePairs();

	//basic getters

	array<tuple<float, array<float, 2>, bool>, 3> getLineSidePairs( ) { return lineSidePairs; }

	float getMass( ) { return mass; }

	array<float, 2> getMidpoint( ) { return midpoint; }

	array<array<float, 2>, 3> getVertices( ) const { return vertices; }

	//used to draw shape to a window using SFML

	void draw(sf::RenderWindow&, sf::Color = sf::Color(255, 255, 255, 255));

	//checks for collision between other shapes

	bool isCollidingCircle(Circle*);

	bool isCollidingTriangle(Triangle*);

	//constructor

	Triangle(array<array<float, 2>, 3>, float);

};

