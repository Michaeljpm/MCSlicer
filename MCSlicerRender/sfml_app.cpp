#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include "coords.h"
#include "driver.h"


using namespace std;

void readinpoints(vector<coords> &endpoints, driver &d)
{
	
	
	
		d.findendpoints(endpoints);
		//infile >> temp.x >> temp.y >> trash >> temp.x1 >> temp.y1 >> trash;
		//endpoints.push_back(temp);
	
}

void printvec(vector<coords>& endpoints)
{
	for (int x = 0; x < endpoints.size(); x++)
	{
		cout << endpoints.at(x).x<< " " << endpoints.at(x).y<< ", " << endpoints.at(x).x1 << " " <<endpoints.at(x).y1 << endl;
	}
}

void makeLine(vector<coords>& endpoints, sf::RenderWindow &window, int xscale, int yscale, double multi)
{
	for (int x = 0; x < endpoints.size(); x++)
	{
		sf::VertexArray line(sf::Lines, 2);
		line[0].position = sf::Vector2f((endpoints.at(x).x+xscale)*multi , (endpoints.at(x).y+yscale)*multi);
		line[1].position = sf::Vector2f((endpoints.at(x).x1+xscale)*multi, (endpoints.at(x).y1+yscale)*multi);
		window.draw(line);
	}
}

int main()
{
	driver d;
	d.readstl();
	d.setZ(12);
	int xscale = 60;
	int yscale = 60;
	double multi = 2;
	vector<coords> endpoints;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
	sf::Text height;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	height.setFont(font);
	height.setString("Height " + to_string(d.getZ()));

	readinpoints(endpoints,d);
	printvec(endpoints);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Right:
					d.setZ(d.getZ() + .01);
					endpoints.clear();
					readinpoints(endpoints, d);
					break;
				case sf::Keyboard::Left:
					d.setZ(d.getZ() - .01);
					endpoints.clear();
					readinpoints(endpoints, d);
					break;
				case sf::Keyboard::D:
					xscale++;
					break;
				case sf::Keyboard::A:
					xscale--;
					break;
				case sf::Keyboard::S:
					yscale++;
					break;
				case sf::Keyboard::W:
					yscale--;
					break;
				case sf::Keyboard::Up:
					multi+= 0.1;
					break;
				case sf::Keyboard::Down:
					multi-= 0.1;
					break;
				}
			}
        }

        window.clear();
		height.setString("Height " + to_string(d.getZ()));
		makeLine(endpoints, window,xscale,yscale,multi);
		window.draw(height);
        window.display();
    }

    return 0;
}