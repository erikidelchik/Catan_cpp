#ifndef PLACE_HPP
#define PLACE_HPP

#include <iostream>
#include "buildable.hpp"

using namespace std;

namespace ariel{

    class Place{
    private:
        string name;
        string resourceName;
        int num;
        //pointers to the roads around this place
        vector<Buildable*> roads;
        //pointers to the settlements arount this place
        vector<Buildable*> settlements;

    public:

        vector<Buildable*> &getRoads(){
            return roads;
        }

        vector<Buildable*> &getSettlements(){
            return settlements;
        }

        Place(string name,string resource,int num): name(name),resourceName(resource),num(num),roads(6),settlements(6){};

        string getName() const{
            return name;
        }
        string getResourceName() const{
            return resourceName;
        }
        int getNum() const{
            return num;
        }
        void printName(){
            cout<<name;
        }


        ~Place() = default;

    };
}

#endif
