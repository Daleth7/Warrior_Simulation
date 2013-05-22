#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <string>   //std::string
#include <iostream> //std::ostream
#include "warrior.h" /**So I can later make certian warriors*
                       *better with different environments. **/

enum condition { Desert , Woodland , Grassland , Highland , Artic , Tundra ,
 Rainforest , Raining = 0 , Windy , Snowing , Hailing , Normal };

namespace NAMES
{
    const std::string ecosytem[ 7 ] = { "Desert" , "Woodland" , "Grassland" ,
     "Highland" , "Artic" , "Tundra" , "Rainforest" } ,
    weather[ 5 ] = { "Raining" , "Windy" , "Snowing" , "Hailing" , "Normal" };
}

class Ecosystem;
class Weather;

class Environment
{
    friend std::ostream& operator<< ( std::ostream& , const Environment& );
    public:
        Environment( void );
        Environment( const Ecosystem& , const Weather& );
        Environment( const condition& , const condition& );
    private:
        //unsigned short disadvantage;
        const std::string ecosytemName , weatherName;
};

class Ecosystem
{
    friend Environment;
    friend std::ostream& operator<< ( std::ostream& , const Ecosystem& );
public:
    Ecosystem( void );
    Ecosystem( const condition& );
private:
    const std::string name;
};

class Weather
{
    friend Environment;
    friend std::ostream& operator<< ( std::ostream& , const Weather& );
public:
    Weather( void );
    Weather( const condition& );
private:
    const std::string name;
};

#endif // ENVIRONMENT_H
