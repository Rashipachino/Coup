#include "Ambassador.hpp"
#include "Game.hpp"
const int ten = 10;

    void Ambassador::transfer(Player &p1, Player &p2){ //can transfer points from one player to another
        if(this->game->players().size() == 1){
            throw invalid_argument("too few players");
        }
        if(this->game->turn() != this->name){ //not this player's turn
            throw invalid_argument("Player is out of turn");
        }
        if(coins() >= ten){ //player must coup with 10 coins in hand
            throw invalid_argument("Player must coup");
        }
        if(p1.get_game()->get_status(p1.get_name()) == "Dead" || p2.get_game()->get_status(p2.get_name()) == "Dead"){ //one or both of players are dead
            throw invalid_argument("Player is dead, therefore, cannot be transfered to/from");
        }
        if(p1.coins() < 1){
            throw invalid_argument("No coins to transer");
        }
        p1.set_coins(p1.coins()-1);
        p2.set_coins(p2.coins()+1);
        this->last_move = "Transfer";
        this->game->update_turn();
    }
    void Ambassador::block(Player &p1){ //can only block captain
        if(this->game->players().size() == 1){
            throw invalid_argument("too few players");
        }   
        if(p1.get_game()->get_status(p1.get_name()) != "Alive"){
            throw invalid_argument("Player is dead or almost dead, cannot be blocked");
        }
        if(p1.role() != "Captain"){
            throw invalid_argument("Ambassador can only block a Captain");
        }
        if(p1.get_last_move() != "Steal"){
            throw invalid_argument("Too late Ambassador");
        }
        p1.get_history()->set_coins(p1.get_history()->coins()+2);
        p1.set_coins(p1.coins()-2); //reduce captain's coin count;
    }
    string Ambassador::role(){
        return "Ambassador";
    }
