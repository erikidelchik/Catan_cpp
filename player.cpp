#include <iostream>
#include "buildable.hpp"
#include "catan.hpp"

#include <random>


namespace ariel{

    void Player::placeSettlement(Board &board, string place, int num,int side) {

        if((brick>=1 && wood>=1 && sheep>=1 && wheat>=1) || freeSettlements>0){

            for(int i=0;i<5;i++){
                int k=0;
                for(Place& j: board.getBoard()[i]){
                    if(j.getName()==place && j.getNum()==num){
                        if(j.getSettlements()[side]->getOwner()=="none"){
                            if(freeSettlements>0)
                                freeSettlements--;
                            else {
                                brick -= 1;
                                wood -= 1;
                                sheep -= 1;
                                wheat -= 1;
                            }
                            Settlement settlement(*this);
                            *j.getSettlements()[side] = settlement;
                            points+=1;
                            return;

                        }
                        else{
                            cout<<j.getSettlements()[side]->getOwner()<<" already have a settlement here";
                            return;
                        }
                    }
                    k++;
                }
            }
            cout<<"Place does not exist\n";

        }
        else{
            cout<<this->getName()<<" does not have enough resources to build a settlement\n";
        }

    }

    void Player::placeRoad(Board &board,string place,int num,int side){
        if(wood>=1 && brick>=0 || freeRoads>0){
            for(int i=0;i<5;i++){
                for(Place& j:board.getBoard()[i]){
                    if(j.getName()==place && j.getNum()==num){
                        //check if no one have a road there
                        if(j.getRoads()[side]->getOwner()=="none"){
                            Road road(*this);
                            *j.getRoads()[side] = road;
                            if(freeRoads>0)
                                freeRoads--;
                            else {
                                brick -= 1;
                                wood -= 1;
                            }

                            //every 5 roads grant 1 point
                            if(numberOfRoads%5==0 && numberOfRoads>0){
                                points++;
                            }
                            return;

                        }
                        else{
                            cout<<j.getRoads()[side]->getOwner()<<" already have a road here\n";
                            return;
                        }
                    }
                }
            }
            cout<<"Place does not exist\n";
        }
        else{
            cout<<this->getName()<<" does not have enough resources to build a road\n";
        }
    }


    void Player::rollDice(Board &board,vector<Player*>& players) {
        random_device rd;
        mt19937 gen(rd());

        uniform_int_distribution<> dist(2, 12);
        int result =  dist(gen);


        cout<<this->getName()<<" rolled "<<result<<endl;

        if(result == 7){
            for(Player*& player: players){
                //take half amount of a random resource from each player that have >=7 of that resource (beside the player that rolled the dice)
                if(player->getName()!=this->getName()){
                    for(int r=0;r<5;r++){
                        if(*player->resources[r]>=7){
                            int amountLost = *player->resources[r]/2;
                            *player->resources[r]-= amountLost;
                            cout<<player->getName()<<" lost "<<amountLost<<" "<<resourcesNames[r]<<endl;
                            break;
                        }
                    }
                }
            }
            return;
        }


        for(int i=0;i<5;i++) {
            for (Place place: board.getBoard()[i]){
                if(result==place.getNum()){
                    for(Buildable* b: place.getSettlements()){
                        if(b->getName()=="Settlement") {
                            for (int r = 0; r < 5; r++) {
                                if (place.getResourceName() == resourcesNames[r]) {
                                    for(int p=0;p<3;p++) {
                                        if(players[p]->getName()==b->getOwner()) {
                                            (*players[p]->resources[r])++;
                                            cout << b->getOwner() << " got +1 " << place.getResourceName() << endl;
                                        }
                                    }
                                }
                            }
                        }

                        else if(b->getName()=="City") {
                            for (int r = 0; r < 5; r++) {
                                if (place.getResourceName() == resourcesNames[r]) {
                                    for(int p=0;p<3;p++) {
                                        if(players[p]->getName()==b->getOwner()) {
                                            (*players[p]->resources[r])+=2;
                                            cout << b->getOwner() << " got +2 " << place.getResourceName() << endl;
                                        }
                                    }
                                }
                            }
                        }


                    }
                }
            }
        }
    }

    void Player::upgradeSettlement(Board &board,string place, int num,int side){
        if(ore>=3 && wheat>=2){
            for(int i=0;i<board.getBoard().size();i++){
                for(Place& j:board.getBoard()[i]){
                    if(j.getName()==place && j.getNum()==num){
                        for(int k=0;k<j.getSettlements().size();k++) {
                            if (j.getSettlements()[k]->getOwner() == this->getName() && j.getSettlements()[k]->getName()=="Settlement") {
                                City city(*this);
                                *j.getSettlements()[k] = city;
                                ore-=3;
                                wheat-=2;
                                cout<<"upgrade complete!\n";
                                points+=1;
                                return;
                            }
                        }
                        //if the player had no settlement here
                        cout<<"upgrade failed: "<<this->getName()<<" doest not have a settlement here\n";
                        return;
                    }
                }
            }
        }
        else{
            cout<<this->getName()<<" does not have enough resources to build a city\n";
        }

    }

    void Player::buyCard() {
        string cardNames[4] = {"Knight","Monopoly","freeRoads","freeResources"};
        random_device rd;
        mt19937 gen(rd());

        uniform_int_distribution<> dist(0, 3);
        int result =  dist(gen);

        if(sheep>=1 && ore>=1 && wheat>=1){
            sheep-=1;
            ore-=1;
            wheat-=1;

            string card = cardNames[result];
            for(int i=0;i<cards.size();i++){
                if(cards[i].getName()==card){
                    cards[i].addAmount();
                    if(cards[i].getName()=="Knight" && cards[i].getAmount()==3){
                        points+=2;
                        cards[i+1].addAmount();
                    }
                    cout<<getName()<<" got the "<<card<<" card\n";
                    break;
                }
            }


        }
        else{
            cout<<getName()<<" does not have enough resources to buy a card\n";
        }

    }

    void Player::useFreeRoadsCard(){
        for(Card& card:cards){
            if(card.getName()=="freeRoads"){
                if(card.getAmount()>0) {
                    card.subAmount();
                    freeRoads += 2;
                    cout<<getName()<<" got 2 free roads\n";
                    break;
                }
                else{
                    cout<<getName()<<" does not have this card\n";
                }
            }
        }
    }

    void Player::useMonopolyCard(string resourceName,vector<Player*>& players) {
        for(Card& card:cards){
            if(card.getName()=="Monopoly"){
                if(card.getAmount()==0){
                    cout<<getName()<<" does not have the monopoly card\n";
                    return;
                }
            }
        }

        for(Player*& player:players){
            if(player->getName()!=this->getName()){
                for(int r=0;r<resources.size();r++){
                    if(resourceName==player->resourcesNames[r]){
                        if(*(player->resources[r])>0){
                            (*player->resources[r])--;
                            (*this->resources[r])++;
                            cout<<player->getName()<<" gave "<<getName()<<"1 "<<resourcesNames[r]<<endl;
                        }
                        else{
                            cout<<player->getName()<<" does not have this resource\n";
                        }
                    }
                }
            }
        }
    }

    void Player::useFreeResourcesCard(string name) {
        for(Card& card:cards){
            if(card.getName()=="freeResources"){
                if(card.getAmount()==0){
                    cout<<getName()<<" does not have the freeResources card\n";
                    return;
                }
            }
        }

        for(int r=0;r<resourcesNames.size();r++){
            if(resourcesNames[r]==name){
                (*resources[r])+=2;
                cout<<getName()<<" got 2 "<<resourcesNames[r]<<endl;
                return;
            }
        }
    }

    void Player::useFreeResourcesCard(string name1, string name2) {
        for(Card& card:cards){
            if(card.getName()=="freeResources"){
                if(card.getAmount()==0){
                    cout<<getName()<<" does not have the freeResources card\n";
                    return;
                }
            }
        }

        for(int r=0;r<resourcesNames.size();r++){
            if(resourcesNames[r]==name1){
                (*resources[r])++;
                cout<<getName()<<" got 1 "<<resourcesNames[r]<<endl;
            }
            if(resourcesNames[r]==name2){
                (*resources[r])++;
                cout<<getName()<<" got 1 "<<resourcesNames[r]<<endl;
            }
        }
    }


}