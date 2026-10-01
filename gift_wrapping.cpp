#include "gift_wrapping.hpp"
#include <iostream>

std::vector<sf::Vector2f> giftWrapping(
    const std::vector<sf::Vector2f>& points
)
{
    std::vector<sf::Vector2f> hull;

    // Gift Wrapping algorithm will go here
    // find extrema

    int leftmost = 0;

    for (int i = 1; i < points.size() ; i++){

        if (points[i].x < points[leftmost].x){
            leftmost = i;
        }
        
    }

    std::cout << "Leftmost point: "
          << points[leftmost].x << ", "
          << points[leftmost].y << std::endl;

    return hull;
}