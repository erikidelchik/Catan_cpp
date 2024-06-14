#include <iostream>
#include "player.hpp"
#include "board.hpp"

namespace ariel {

    class Catan {
    private:

        vector<Player*> players;

    public:

        Catan(Player &p1,Player &p2, Player &p3){
            players.push_back(&p1);
            players.push_back(&p2);
            players.push_back(&p3);
        }

        Board getBoard(){
            Board b;
            return b;
        }

        vector<Player*>& getPlayers(){
            return players;
        }

    };


}
