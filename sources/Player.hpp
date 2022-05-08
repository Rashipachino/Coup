#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Game.hpp"
using namespace coup;
using namespace std;

    class Player
    {
        protected:
           int coin_count;
           string name;
           Game* game;
           string last_move;
           Player* history;
        public:
            Player(Game &game, string name){
                this->name = name;
                this->coin_count = 0;
                this->game = &game;
                this->game->set_players(name);
                this->game->set_status(name, "Alive");
            }
            void income();
            void foreign_aid();
            virtual void coup(Player &p);
            int coins() const; 
            virtual string role(); //add virtual 
            void set_coins(int c);
            Game* get_game();
            string get_name();
            string get_last_move();
            void set_last_move(string move);
            Player* get_history();
            void set_history(Player* new_history);
    };

#endif
