#include <iostream>
#include "board.hpp"

namespace ariel{

    Board::Board() {

        roadMap = setRoadMap();
        settlementMap = setSettlementMap();
        initBoard();
    }


    void Board::initBoard() {
        //init settlements
        for(int i=0;i<5;i++){
            int n=0;
            for(Place &j:myBoard[i]){
                if(i<=1) {
                    for (int k = 0; k < 6; k++) {
                        if (k <= 2)
                            j.getSettlements()[k] = &getSettlementMap()[i][n + k];

                        else {
                            j.getSettlements()[k] = &getSettlementMap()[i + 1][n + k - 2 * (k % 3)];
                        }
                    }
                    n += 2;
                }
                else if(i==2){
                    for (int k = 0; k < 6; k++) {
                        if (k <= 2)
                            j.getSettlements()[k] = &getSettlementMap()[i][n + k];

                        else {
                            j.getSettlements()[k] = &getSettlementMap()[i + 1][n + k - 2 * (k % 3)-1];
                        }
                    }
                    n+=2;
                }

                else{
                    for(int k=0;k<6;k++){
                        if(k<=2){
                            j.getSettlements()[k] = &getSettlementMap()[i][n + k + 1];
                        }
                        else{
                            j.getSettlements()[k] = &getSettlementMap()[i + 1][n + k - 2 * (k % 3)-1];
                        }
                    }
                    n+=2;
                }

            }
        }

        //init roads
        int row=0;
        for(int i=0;i<5;i++){
            int p=0;
            for(Place &j:myBoard[i]){
                if(i<=1){
                    for(int k=0;k<6;k++){
                        if(k==0 || k==1){
                            j.getRoads()[k] = &getRoadMap()[row][p+k];
                        }
                        else if(k==2 || k==5){
                            j.getRoads()[k] = &getRoadMap()[row+1][p/2+5%k];
                        }
                        else if(k==3 || k==4){
                            j.getRoads()[k] = &getRoadMap()[row+2][p+5%k];
                        }
                    }
                    p+=2;
                }
                else if(i==2){
                    for(int k=0;k<6;k++){
                        if(k==0 || k==1){
                            j.getRoads()[k] = &getRoadMap()[row][p+k];
                        }
                        else if(k==2 || k==5){
                            j.getRoads()[k] = &getRoadMap()[row+1][p/2+5%k];
                        }
                        else if(k==3 || k==4){
                            j.getRoads()[k] = &getRoadMap()[row+2][p+5%k-1];
                        }
                    }
                    p+=2;
                }
                else{
                    for(int k=0;k<6;k++){
                        if(k==0 || k==1){
                            j.getRoads()[k] = &getRoadMap()[row][p+k+1];
                        }
                        else if(k==2 || k==5){
                            j.getRoads()[k] = &getRoadMap()[row+1][p/2+5%k];
                        }
                        else if(k==3 || k==4){
                            j.getRoads()[k] = &getRoadMap()[row+2][p+5%k-1];
                        }
                    }
                    p+=2;
                }
            }
            row+=2;
        }

    }

    vector<vector<Buildable>> Board::setRoadMap() {
        int a[] = {6,4,8,5,10,6,10,5,8,4,6};

        vector<vector<Buildable>> newMap(11);
        for(int i=0;i<11;i++){
            newMap[i] = vector<Buildable>(a[i]);
        }

        return newMap;
    }

    vector<vector<Buildable>> Board::setSettlementMap() {
        int a[6] = {7,9,11,11,9,7};
        vector<vector<Buildable>> newMap(6);
        for(int i=0;i<6;i++){
            newMap[i] = vector<Buildable>(a[i]);
        }

        return newMap;

    }


}