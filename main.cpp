#include <iostream>
#include "catan.hpp"

using namespace std;
using namespace ariel;

int main() {


    Player p1("moshe");
    Player p2("haim");
    Player p3("amit");
    Catan catan(p1,p2,p3);
    Board b = catan.getBoard();

    p1.placeSettlement(b,"Pasture",11,2);
    p1.placeRoad(b,"Pasture",11,0);
    p1.placeRoad(b,"Pasture",11,1);
    
    p2.placeSettlement(b,"Forest",11,4);
    p2.placeRoad(b,"Forest",11,0);
    p2.placeRoad(b,"Forest",11,1);
    
    p3.placeSettlement(b,"Mountains",10,2);
    p3.placeRoad(b,"Mountains",10,0);
    p3.placeRoad(b,"Mountains",10,1);
    
    p1.rollDice(b,catan.getPlayers());
    p1.placeRoad(b,"Fields",4,3);
	
    p1.printResources();
    p2.printResources();
    p3.printResources();
    p1.printCards();
    catan.printStats();




}
