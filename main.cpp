#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string>
#include "gift_wrapping.hpp"
int main()
{
    
    //Visualization (rendering) window
    //Random points generation
    //Add point on mouse click
    //Delete point on mouse click
    //Move point using mouse move
    //Clear scene

    srand(time(nullptr));

    char answer;
    std::cout << "Do you want randomly generated points (y/n)";
    std::cin >> answer;
    
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "Basic Framework"
    );

    if (answer == 'y'){

        sf::CircleShape Points [6] = {
        sf::CircleShape (5.f),
        sf::CircleShape (5.f),
        sf::CircleShape (5.f),
        sf::CircleShape (5.f),
        sf::CircleShape (5.f),
        sf::CircleShape (5.f)};

        for (int i = 0;i<6;i++){
        float x = rand()%600;
        float y = rand()%400;
        Points[i].setPosition({x,y});  
        }

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();

        for (int i = 0; i < 6; i++)
        {
            window.draw(Points[i]);
        }
       

        window.display();
    }
    }
    else {
        std::vector<sf::CircleShape> points;

    
        while (window.isOpen())
{
    int selectedPoint = -1;
    bool dragging = false;
    
    while (const std::optional event = window.pollEvent())
    {

        if (const auto* mousePressed =
        event->getIf<sf::Event::MouseButtonPressed>())
{
    if (mousePressed->button == sf::Mouse::Button::Left)
    {
        float mouseX = static_cast<float>(mousePressed->position.x);
        float mouseY = static_cast<float>(mousePressed->position.y);

        for (int i = 0; i < points.size(); i++)
        {
            float x = points[i].getPosition().x;
            float y = points[i].getPosition().y;

            if (mouseX >= x && mouseX <= x + 10 &&
                mouseY >= y && mouseY <= y + 10)
            {
                selectedPoint = i;
                dragging = true;
                break;
            }
        }
    }
}



if (const auto* mouseMoved =
        event->getIf<sf::Event::MouseMoved>())
{
    if (dragging && selectedPoint != -1)
    {
        points[selectedPoint].setPosition({
            static_cast<float>(mouseMoved->position.x),
            static_cast<float>(mouseMoved->position.y)
        });
    }
}



if (const auto* mouseReleased =
        event->getIf<sf::Event::MouseButtonReleased>())
{
    if (mouseReleased->button == sf::Mouse::Button::Left)
    {
        dragging = false;
        selectedPoint = -1;
    }
}
        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
{
    if (keyPressed->code == sf::Keyboard::Key::C)
    {
        points.clear();
    }

    if (keyPressed->code == sf::Keyboard::Key::G)
    {
        std::vector<sf::Vector2f> positions;

        for (const auto& point : points)
        {
            positions.push_back(point.getPosition());
        }

        std::vector<sf::Vector2f> hull = giftWrapping(positions);
    }
}
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }

        if (const auto* mousePressed =
                event->getIf<sf::Event::MouseButtonPressed>())
        {
            if (mousePressed->button == sf::Mouse::Button::Left)
            {
                sf::CircleShape point(5.f);

                point.setPosition({
                    static_cast<float>(mousePressed->position.x),
                    static_cast<float>(mousePressed->position.y)
                });

                points.push_back(point);
            }
        }

        if (const auto* mousePressed =
        event->getIf<sf::Event::MouseButtonPressed>())
{
    if (mousePressed->button == sf::Mouse::Button::Right)
    {
        float mouseX = static_cast<float>(mousePressed->position.x);
        float mouseY = static_cast<float>(mousePressed->position.y);

        for (int i = 0; i < points.size(); i++)
        {
            float pointX = points[i].getPosition().x;
            float pointY = points[i].getPosition().y;

            if (mouseX >= pointX && mouseX <= pointX + 10 &&
                mouseY >= pointY && mouseY <= pointY + 10)
            {
                points.erase(points.begin() + i);
                break;
            }
        }
    }
}
    }

    window.clear();

    for (const auto& point : points)
    {
        window.draw(point);
    }

    window.display();
}

    }


    return 0;
}