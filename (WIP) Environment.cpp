#include "Environment.h"

Terrain::Terrain( void ) : terrain_name( "Not Specified" ) ,
elevation( 0 ) , trees( 0 ) , rocks( 0 ) ,
min_tree_width( 0 ) , max_tree_width( 0 ) ,
min_tree_height( 0 ) , max_tree_height( 0 ) ,
min_rock_width( 0 ) , max_rock_width( 0 ) ,
min_rock_height( 0 ) , max_rock_height( 0 ) {}

Terrain::Terrain( const default_terrain &ter ) : Terrain()
{
    //going to put all the defaults here
}

const unsigned short Terrain::generate_random_number( const unsigned short &min , const unsigned short &max ) const
{
    return( rand() % ( max - min + 1 ) + min );
}

void Terrain::generate_trees( void )
{
    std::pair<unsigned short , unsigned short> temp;
    for( auto i = 0; i < trees; ++i )
    {
        temp.first = generate_random_number( min_tree_width , max_tree_width );
        temp.second = generate_random_number( min_tree_height , max_tree_height );
        tree_info.push_back( temp );
    }
}

void Terrain::generate_rocks( void )
{
    std::pair<unsigned short , unsigned short> temp;
    for( auto i = 0; i < rocks; ++i )
    {
        temp.first = generate_random_number( min_rock_width , max_rock_width );
        temp.second = generate_random_number( min_rock_height , max_rock_height );
        rock_info.push_back( temp );
    }
}

std::ostream& operator<< ( std::ostream &stm , const Terrain &ter )
{
    return( stm << "Terrain         - " << ter.terrain_name
                << "\nElevation       - " << ter.elevation
                << "\nTrees           - " << ter.trees
                << "\nRocks           - " << ter.rocks );
}
