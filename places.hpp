#ifndef PLACES_HPP
#define PLACES_HPP

#include <iostream>
#include "place.hpp"

using namespace std;
namespace ariel{

    class Forest: public Place{
    public:
        explicit Forest(int n): Place("Forest","wood",n){}
    };

    class Hills: public Place{
    public:
        explicit Hills(int n): Place("Hills","brick",n){}
    };

    class Pasture: public Place{
    public:
        explicit Pasture(int n): Place("Pasture","sheep",n){}
    };

    class Fields: public Place{
    public:
        explicit Fields(int n): Place("Fields","wheat",n){}
    };

    class Mountains: public Place{
    public:
        explicit Mountains(int n): Place("Mountains","ore",n){}
    };

    class Desert:public Place{
    public:
        Desert(): Place("Desert","None",0){}
    };

    class Sea: public Place{
    public:
        Sea(): Place("Sea","None",0){}
    };

}

#endif