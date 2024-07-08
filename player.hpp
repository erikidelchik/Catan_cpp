#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "card.hpp"
#include <vector>

using namespace std;

namespace ariel{

    class Board;
    class Catan;

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
        int points;
        int numberOfRoads = 0;

        vector<int*> resources = {&wood, &brick,&sheep,&wheat,&ore};
        vector<string> resourcesNames = {"wood","brick","sheep","wheat","ore"};

    public:


        string getName() const{
            return name;
        }

        void printCards(){
            string str;
            bool haveCards = false;
            for(Card& c:cards){
                if(c.getAmount()>0) {
                    haveCards = true;
                    str+= c.getName() +"(" + to_string(c.getAmount()) + ") ";
                }
            }

            if(!haveCards){
                cout<<getName()<<" does not have any cards\n";
            }
            else{
                cout<<getName()<<"'s cards: "<<str<<endl;
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


        void buyCard(Catan& catan);

        void useFreeRoadsCard();
        void useMonopolyCard(string resourceName,vector<Player*>& players);
        void useFreeResourcesCard(string name);
        void useFreeResourcesCard(string name1,string name2);

        void trade(Player &other,vector<pair<string,int>> my,vector<pair<string,int>> his);

    };

}

#endif
