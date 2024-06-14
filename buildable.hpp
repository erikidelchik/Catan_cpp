#ifndef BUILDABLE_HPP
#define BUILDABLE_HPP

#include <iostream>
#include "player.hpp"


using namespace std;

namespace ariel {

    class Buildable {
    protected:
        string name;
        Player* owner;


    public:
        Buildable(){
            owner = nullptr;
        }

        explicit Buildable(Player &p): owner(&p){};

        string getOwner() const{
            if(owner)
                return this->owner->getName();
            return "none";
        }


        string getName() const{
            return name;
        }


        ~Buildable() = default;


    };

    class Road: public Buildable{
    public:
        explicit Road(Player &p): Buildable(p){
            name = "Road";
        };
    };

    class Settlement: public Buildable{
    public:
        explicit Settlement(Player &p): Buildable(p){
            name = "Settlement";
        };
    };

    class City: public Buildable{
    public:
        explicit City(Player &p): Buildable(p){
            name = "City";
        };
    };




}

#endif