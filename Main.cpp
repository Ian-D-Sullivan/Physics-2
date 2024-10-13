#include "Shape.h"
#include "Triangle.h"
#include <array>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <vector>
#include <SFML/Graphics/Color.hpp>

using namespace std;

int main( ) {
    Triangle A(array<array<float, 2>, 3>{{{300, 300}, { 400,300 }, { 300, 200 }}}, 1);
    Triangle B(array<array<float, 2>, 3>{{{200, 400}, { 200,200 }, { 350, 250 }}}, 1);
    Shape AS(vector<Triangle*>{{&A}});
    Shape BS(vector<Triangle*>{{&B}});
    sf::RenderWindow window( sf::VideoMode(600, 600), "Physics-2" );

    cout << AS.isColliding(BS);

    while ( window.isOpen( ) ) {

        sf::Event event;

        while ( window.pollEvent(event) )

            if ( event.type == sf::Event::Closed ) 

                window.close( );

        window.clear( );
        AS.draw(window, sf::Color(255, 0, 0));
        BS.draw(window, sf::Color(0, 0, 255));
        window.display( );
    }
    return 0;
}
