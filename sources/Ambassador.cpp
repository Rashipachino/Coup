#include "Ambassador.hpp"
#include "Game.hpp"

    void Ambassador::transfer(Player &p1, Player &p2){ //can transfer points from one player to another
        if(this->game->turn() != this->name){ //not this player's turn
            throw invalid_argument("Player is out of turn");
        }
        if(coins() == 10){ //player must coup with 10 coins in hand
            throw invalid_argument("Player must coup");
        }
        if(p1.get_game()->get_status(p1.get_name()) == "Dead" || p2.get_game()->get_status(p2.get_name()) == "Dead"){ //one or both of players are dead
            throw invalid_argument("Player is dead, therefore, cannot be transfered to/from");
        }
        else{
            p1.set_coins(p1.coins()-1);
            p2.set_coins(p2.coins()+1);
            this->last_move = "Transfer";
            this->game->update_turn();
        }
    }
    void Ambassador::block(Player &p1){ //can only block captain
        if(p1.get_game()->get_status(p1.get_name()) != "Alive"){
            throw invalid_argument("Player is dead or almost dead, cannot be blocked");
        }
        if(p1.role() != "Captain"){
            throw invalid_argument("Ambassador can only block a Captain");
        }
        if(p1.get_last_move().substr(0,4) != "Steal"){
            throw invalid_argument("Too late Ambassador");
        }
        else{
            p1.set_coins(p1.coins()-2); //reduce captain's coin count;
            
        }
    }
    string Ambassador::role(){
        return "Ambassador";
    }
