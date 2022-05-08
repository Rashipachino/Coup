#include "Player.hpp"

void Player::income(){
    if(this->game->turn() != this->name){
        throw invalid_argument("Player is out of turn");
    }
    if(coin_count == 10){
        throw invalid_argument("Player must coup");
    }
    else{  
        coin_count++;
        this->last_move = "Income";
        this->game->update_turn();
    }
}
void Player::foreign_aid(){
    if(this->game->turn() != this->name){
        throw invalid_argument("Player is out of turn");
    }
    if(coin_count == 10){
        throw invalid_argument("Player must coup");
    }
    else{
        coin_count+=2;
        this->last_move = "Foreign_aid";
        this->game->update_turn(); 
    }
   
}
void Player::coup(Player &p){
    if(this->game->turn() != this->name){
        throw invalid_argument("Player is out of turn");
    }
    if(coin_count < 7){
        throw invalid_argument("Not enough coins to coup");
    }
    if(p.get_game()->get_status(p.get_name()) == "Dead"){
        throw invalid_argument("Player to coup is already dead");
    }
    else{
       p.get_game()->set_status(p.get_name(), "Dead"); //kill character
        this->coin_count -= 7;
        this->last_move = "Coup";
        this->game->update_turn();
        this->history = &p;
    }
}
int Player::coins() const{
    return coin_count;
}
string Player::role(){
    return "Player";
}
void Player::set_coins(int c){
    coin_count = c;
    if(coin_count < 0){
        throw invalid_argument("Coin count is negative thus invalid");
    }
}
Game* Player::get_game(){
    return game;
}
string Player::get_name(){
    return name;
}
string Player::get_last_move(){
    return last_move;
}
void Player::set_last_move(string move){
    this->last_move = move;
}
Player* Player::get_history(){
    return this->history;
}
void Player::set_history(Player* new_history){
    this->history = new_history;
}

