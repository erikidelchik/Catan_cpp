#include <iostream>
#include "player.hpp"
#include "board.hpp"
#include "deck.hpp"

namespace ariel {

    class Catan {
    private:

        Deck deck;
        vector<Player*> players;
        Board b;

    public:

        Catan(Player &p1,Player &p2, Player &p3){
            players.push_back(&p1);
            players.push_back(&p2);
            players.push_back(&p3);
        }

        string getCardFromDeck(){
            return deck.getCard();
        }

        Board getBoard(){
            return b;
        }

        vector<Player*>& getPlayers(){
            return players;
        }

        void printStats(){
            for(Player* player:players){
                player->printPoints();
            }
        }

    };


}
