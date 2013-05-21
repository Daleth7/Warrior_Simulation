#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <string>   //std::string
#include <iostream> //std::ostream

class Ecosystem;
class Weather;

class Environment
{
    public:
        Environment( void );
        Environment( const Ecosystem& , const Weather& );
        Environment( const Ecosystem& , const std::string& );
        Environment( const Ecosystem& , const unsigned short& );
        Environment( const std::string& , const Weather& );
        Environment( const std::string& , const std::string& );
        Environment( const std::string& , const unsigned& );
        Environment( const unsigned short& , const Weather& );
        Environment( const unsigned short& , const std::string& );
        Environment( const unsigned short& , const unsigned short& );

        friend std::ostream& operator<< ( std::ostream& , const Environment& );

    protected:
        unsigned short disadvantage;
        const const std::string ecosytemName , weatherName;
};

class Desert;
class Woodland;
class Grassland;
class Highland;
class Artic;
class Tundra;
class Rainforest;

class Ecosystem : public Environment
{
public:
    Ecosystem( void );
    Ecosystem( const std::string& );
    Ecosystem( const unsigned short& );
    Ecosystem( const Desert& );
    Ecosystem( const Woodland& );
    Ecosystem( const Grassland& );
    Ecosystem( const Highland& );
    Ecosystem( const Artic& );
    Ecosystem( const Tundra& );
    Ecosystem( const Rainforest& );
};

class Desert : public Ecosystem
{
public:
    Desert( void );
};

class Woodland : public Ecosystem
{
public:
    Woodland( void );
};

class Grassland : public Ecosystem
{
public:
    Grassland( void );
};

class Highland : public Ecosystem
{
public:
    Highland( void );
};

class Artic : public Ecosystem
{
public:
    Artic( void );
};

class Tundra : public Ecosystem
{
public:
    Tundra( void );
};

class Rainforest : public Ecosystem
{
public:
    Rainforest( void );
};

class Raining;
class Windy;
class Snowing;
class Hailing;

class Weather : public Environment
{
public:
    Weather( void );
    Weather( const std::string& );
    Weather( const unsigned short& );
    Weather( const Raining& );
    Weather( const Windy& );
    Weather( const Snowing& );
    Weather( const Hailing& );
};

class Raining : public Weather
{
    Raining( void );
};

class Windy : public Weather
{
    Windy( void );
};

class Snowing : public Weather
{
    Snowing( void );
};

class Hailing : public Weather
{
    Hailing( void );
};
#endif // ENVIRONMENT_H
