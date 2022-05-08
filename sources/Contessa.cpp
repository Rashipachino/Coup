#include "Contessa.hpp"
#include "Game.hpp"
#include "Assassin.hpp"

void Contessa::block(Player &p){//can block assassanation turn "Assassinated" to "Alive"
    if(p.role() != "Assassin"){
        throw invalid_argument("Contessa can only block an Assasin");
    }
    if(p.get_last_move() != "Coup"){
        throw invalid_argument("Too late Contessa");
    }
    else{
        this->game->set_status(p.get_history()->get_name(), "Alive");
        this->last_move = "Coup Blocked";
    }
} 
string Contessa::role(){
    return "Contessa";
}
