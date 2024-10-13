#include "Circle.h"
#include "findDistance.cpp"
#include "Triangle.h"
#include <array>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace std;

void Circle::calculateMidpoint( ) {
	return;
}

void Circle::draw(sf::RenderWindow& window, sf::Color drawColor) {
	sf::CircleShape drawCircle(radius);
	drawCircle.setPosition(midpoint[0], midpoint[1]);
	drawCircle.setFillColor(drawColor);
	window.draw(drawCircle);
}

bool Circle::isCollidingCircle(Circle* checkCircle) {
	float sumRadius = radius + checkCircle->getRadius( );
	float centerDistance = findDistance(midpoint, checkCircle->getMidpoint( ));
	return centerDistance < sumRadius;
}

bool Circle::isCollidingTriangle(Triangle* checkTriangle) {
	for ( array<float, 2>& vertex : checkTriangle->getVertices( ) ) {
		float vertexDistance = findDistance(midpoint, vertex);
		if ( vertexDistance >= radius ) {
			continue;
		}
		return true;
	}
	return false;
}

Circle::Circle(array<float, 2> midpoint, float radius, float mass) {
	this->midpoint = midpoint;
	this->radius = radius;
	this->mass = mass;
}