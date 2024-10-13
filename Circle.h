#pragma once
#include <array>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace std;

class Triangle;

class Circle{

private:

	float radius;

	array<float, 2> midpoint;

	float mass;

	virtual void calculateMidpoint ( );

public:

	float getMass( ) { return mass; }

	array<float, 2> getMidpoint() { return midpoint; }

	void draw(sf::RenderWindow&, sf::Color = sf::Color(255, 255, 255, 255));

	float getRadius( ) { return radius; }

	bool isCollidingCircle(Circle*);

	bool isCollidingTriangle(Triangle*);

	Circle(array<float, 2>, float, float);

};