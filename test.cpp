#include "doctest.h"
#include "catan.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("test building on same spot"){
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan catan(p1,p2,p3);
    Board b = catan.getBoard();

    p1.placeSettlement(b,"Pasture",11,2);
    p2.placeSettlement(b,"Pasture",11,2);

}

TEST_CASE("trading"){
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan catan(p1,p2,p3);
    Board b = catan.getBoard();

    p1.placeSettlement(b,"Pasture",11,2);
    p2.placeSettlement(b,"Mountains",10,2);

    for(int i=0;i<100;i++){
        p1.rollDice(b,catan.getPlayers());
    }

    p1.printResources();
    p2.printResources();

    p1.trade(p2,{{"sheep",2}},{{"ore",1}});

    p1.printResources();
    p2.printResources();

}

