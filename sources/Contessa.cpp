#include "Contessa.hpp"
#include "Game.hpp"
#include "Assassin.hpp"
const int one = 1;

void Contessa::block(Player &p){//can block assassanation turn "Assassinated" to "Alive"
    if(this->game->players().size() == one){
        throw invalid_argument("too few players");
    }    
    if(p.role() != "Assassin"){
        throw invalid_argument("Contessa can only block an Assasin");
    }
    if(p.get_last_move() != "Assassinate"){
        throw invalid_argument("Too late Contessa");
    }
    this->game->set_status(p.get_history()->get_name(), "Alive");
    this->last_move = "Coup Blocked";
} 
string Contessa::role(){
    return "Contessa";
}
