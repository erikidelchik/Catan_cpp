#include <iostream>
using namespace std;

namespace ariel{

    class Card{
        string name;
        int amount = 0;
    public:



        explicit Card(string name): name(name) {}

        string getName() const{
            return name;
        };

        int getAmount() const{
            return amount;
        }

        void addAmount(){
            amount++;
        }

        void subAmount(){
            amount--;
        }


    };


}