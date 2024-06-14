#include <iostream>
#include "catan.hpp"

using namespace std;
using namespace ariel;

int main() {


    Player p1("dudi");
    Player p2("haim");
    Player p3("amit");
    Catan catan(p1,p2,p3);
    Board b = catan.getBoard();

    p1.placeSettlement(b,"Pasture",11,2);
    p1.upgradeSettlement(b,"Pasture",11,3);
    p2.placeSettlement(b,"Forest",11,4);
    p1.rollDice(b,catan.getPlayers());
    p1.placeRoad(b,"Fields",4,3);

    p1.buyCard();
    p1.printCards();



    p1.printResources();
    p2.printResources();


}
