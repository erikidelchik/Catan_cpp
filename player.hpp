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
	
	//rolls the dice and gives a resources (or takes if the result is 7) to all the players that deserve it,depends on the result.
        void rollDice(Board &board,vector<Player*>& players);
	
	//check if have enough resources to place a settlement, and place a settlement at the 
	//place with the name "place", that have a number "num", and on side "side" where side can be 0-5
	//where the top left settlement of this place represents side:0, the top settlement of this place represents side:1 and 
	//so on going clockwise
        void placeSettlement(Board &board,string place, int num,int side);
        
        //the same concept that placeSettlement func have. the top left side of this place represents side:0, and so on going clockwise.
        void placeRoad(Board &board,string place,int num,int side);
	
	//checks if the player have enough resources to build a city, and if he indeed owns a settlement in this location.
        void upgradeSettlement(Board &board,string place, int num,int side);

	//gives a player a random card from the deck, and adds it to his list of cards
        void buyCard(Catan& catan);
	
	//use the "free roads" card if a player have it, which gives the player 2 free roads
        void useFreeRoadsCard();
        
        //use the "monopoly" card if the player has it, and each other player that have the resource "resourceName" will lose one
        //of it, and give the current player 1 of it. "players" is the vector of all the players currently playing
        void useMonopolyCard(string resourceName,vector<Player*>& players);
        
        //use the "free Resources" card which gives a player 2 resources "name".
        void useFreeResourcesCard(string name);
        
        //use the "free Resources" card which gives a player 1 resource with the name "name1", and 1 "name2"
        void useFreeResourcesCard(string name1,string name2);
	
	//"other"- the player you want to trade with
	//"my" - vector of pairs of the names and amounts of the resources/cards you willing to give
	//"his" - vector of pairs of the names and amounts of the resources/cards the other player will give you
        void trade(Player &other,vector<pair<string,int>> my,vector<pair<string,int>> his);

    };

}

#endif
