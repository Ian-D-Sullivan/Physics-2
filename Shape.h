#pragma once
#include <array>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "Circle.h"
#include "Triangle.h"

using namespace std;

class Shape
{

private:

	vector<Triangle*> compTriangles ;

	vector<Circle*> compCircles;

protected:

	array<float, 2> midpoint = array<float, 2>{{0, 0}};

	float mass = 1;

	array<float, 2 > velocityT = array<float, 2>{{0, 0}};

	float velocityR = 0;

	virtual void calculateMidpoint( );

	void calculateMass( );

public:

	Shape(vector<Triangle*>, vector<Circle*>);
	Shape(vector<Circle*>);
	Shape(vector<Triangle*>);
	Shape();

	bool isColliding(Shape&);

	vector<Shape> listColliding(vector<Shape>&);

	virtual void draw(sf::RenderWindow&, sf::Color = sf::Color(255, 255, 255, 255));

	vector<Triangle*> getCompTriangles( ) { return compTriangles; }

	vector<Circle*> getCompCircles( ) { return compCircles; }

	float getMass( ) const { return mass; }

	array<float, 2> getMidpoint( ) { calculateMidpoint( ); return midpoint; }

};

