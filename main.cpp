#include <iostream>
#include "catan.hpp"

using namespace std;
using namespace ariel;

int main() {


    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan catan(p1,p2,p3);
    Board b = catan.getBoard();

    p1.placeSettlement(b,"Pasture",11,2);
    p2.upgradeSettlement(b,"Pasture",11,2);
    p2.placeSettlement(b,"Forest",11,4);
    p1.rollDice(b,catan.getPlayers());
    p1.placeRoad(b,"Fields",4,3);

    for(int i=0;i<30;i++){
        p1.rollDice(b,catan.getPlayers());
        p2.rollDice(b,catan.getPlayers());
    }
    p1.printResources();
    p2.printResources();

    p1.trade(p2,{{"sheep",2}},{{"wood",3}});

    p1.printResources();
    p2.printResources();

    catan.printStats();




}
