#include "Captain.hpp"
#include "Game.hpp"

void Captain::block(Player &p){
    if(p.get_game()->get_status(p.get_name()) != "Alive"){
            throw invalid_argument("Player is dead or almost dead, cannot be blocked");
        }
        if(p.role() != "Captain"){
            throw invalid_argument("Captain can only block a Captain");
        }
        if(p.get_last_move() != "Steal"){
            throw invalid_argument("Too late Captain");
        }
        else{
            p.set_coins(p.coins()-2); //reduce captain's coin count;
            p.get_history()->set_coins(p.get_history()->coins()+2); //add back coins to player stolen from
        }
} //can block like ambassador
void Captain::steal(Player &p){
    if(this->game->turn() != this->name){
        throw invalid_argument("Player is out of turn");
    }
    if(p.get_game()->get_status(p.get_name()) != "Alive"){
            throw invalid_argument("Player is dead or almost dead, cannot be blocked");
        }
    if(coins() == 10){
        throw invalid_argument("Player must coup");
    }    
    else if(p.coins() == 1){
        set_coins(coins() + 1);
        p.set_coins(p.coins() - 1);
    }
    else if(p.coins() >= 2){
        set_coins(coins() + 2);
        p.set_coins(p.coins() - 2);
    }    
    this->last_move = "Steal";
    this->history = &p;
    p.get_game()->update_turn();
}
string Captain::role(){
    return "Captain";
}

