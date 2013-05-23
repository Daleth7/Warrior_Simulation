#include <iostream>
#include "Environment.h"
int main()
{
    srand( ( unsigned ) time( NULL ) );
    Terrain ter1 , ter2 , ter3( Mountain );
    ter2.terrain_name = "Test";
    ter2.trees = 3;
    ter2.rocks = 15;
    ter2.min_tree_width = 1;
    ter2.max_tree_width = 2;
    ter2.min_tree_height = 1;
    ter2.max_tree_height = 10;
    ter2.min_rock_width = 1;
    ter2.max_rock_width = 5;
    ter2.min_rock_height = 1;
    ter2.max_rock_height = 5;
    ter2.generate_rocks();
    ter2.generate_trees();
    std::cout << ter1 << std::endl;
    std::cout << ter2 << std::endl;
    std::cout << ter3 << std::endl;
    std::cout << "Size of all trees" << std::endl;
    for( const auto &it : ter2.tree_info )
    {
        std::cout << "Width - " << it.first << " Height - " << it.second << std::endl;
    }
    std::cout << "Size of all rocks" << std::endl;
    for( const auto &it : ter2.rock_info )
    {
        std::cout << "Width - " << it.first << " Height - " << it.second << std::endl;
    }

    return ( 0 );
}
