#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "card.hpp"
#include <vector>
using namespace std;

namespace ariel{

    class Board;

    class Player{
        string name;
        vector<Card> cards =
                {Card("Knight"),Card("bigArmy"),Card("Monopoly"),Card("freeRoads"),Card("freeResources")};

        int freeSettlements = 2;
        int freeRoads = 2;

        int wood;
        int brick;
        int sheep;
        int wheat;
        int ore;

        vector<int*> resources = {&wood, &brick,&sheep,&wheat,&ore};
        vector<string> resourcesNames = {"wood","brick","sheep","wheat","ore"};

    public:
        int points;
        int numberOfRoads = 0;

        string getName() const{
            return name;
        }

        void printCards(){

            bool haveCards = false;
            for(Card& c:cards){
                if(c.getAmount()>0) {
                    haveCards = true;
                    cout << c.getName() << "(" << c.getAmount() << ") ";
                }
            }
            cout<<endl;

            if(!haveCards){
                cout<<getName()<<" does not have any cards\n";
            }


        }



        explicit Player(string name): name(name),points(0),wood(0),brick(0),sheep(0),wheat(0),ore(0){}

        void printResources() const{
            cout<<name<<"'s resources: ";
            cout<<"wood: "<<wood<<",";
            cout<<"brick: "<<brick<<",";
            cout<<"sheep: "<<sheep<<",";
            cout<<"wheat: "<<wheat<<",";
            cout<<"ore: "<<ore<<endl;
        }

        void printPoints() const{
            cout<<name<<" has "<<points<<" points\n";
        }

        void rollDice(Board &board,vector<Player*>& players);

        void placeSettlement(Board &board,string place, int num,int side);
        void placeRoad(Board &board,string place,int num,int side);

        void upgradeSettlement(Board &board,string place, int num,int side);

        void trade();

        void buyCard();

        void useFreeRoadsCard();
        void useMonopolyCard(string resourceName,vector<Player*>& players);
        void useFreeResourcesCard(string name);
        void useFreeResourcesCard(string name1,string name2);

    };

}

#endif