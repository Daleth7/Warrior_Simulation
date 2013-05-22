#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
enum default_terrain { Forest , Jungle , Plain , Mountain , Hill , Rocky };

class Terrain
{
public:
    Terrain( void );
    Terrain( const default_terrain& );
    const unsigned short generate_random_number( const unsigned short& , const unsigned short& ) const;
    void generate_trees( void );
    void generate_rocks( void );
    friend std::ostream& operator<< ( std::ostream& , const Terrain& );

    std::string terrain_name;
    unsigned short elevation , trees , rocks ,
    min_tree_width , max_tree_width ,
    min_tree_height , max_tree_height ,
    min_rock_width , max_rock_width ,
    min_rock_height , max_rock_height;
    std::vector<std::pair<unsigned short , unsigned short> > tree_info , rock_info;
};
#endif // ENVIRONMENT_H
