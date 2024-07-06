#include <iostream>
#include <random>

namespace ariel{

    class Deck{

        vector<Card> deck;
        vector<Card> removedCards;

    public:
        Deck(){
            deck = {Card("Knight",14),Card("Monopoly",2),Card("freeRoads",2),Card("freeResources",5)};
        }

        string getCard(){
            if(deck.empty()){
                return "null";
            }

            random_device rd;
            mt19937 gen(rd());

            uniform_int_distribution<> dist(0, deck.size()-1);
            int result =  dist(gen);
            string cardChosen = deck[result].getName();
            deck[result].subAmount();
            if(deck[result].getAmount()==0){
                removedCards.push_back(deck[result]);
                deck.erase(deck.begin()+result);
                return cardChosen;
            }
            return cardChosen;

        }

    };

}