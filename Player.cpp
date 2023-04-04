#include <iostream>
#include <vector>

#include "Hand.cpp"
#include "Tile.cpp"

using namespace std;

class Player {
   private:
    int score;
    string name;
    Hand hand;

   public:
    Player(string name, int score) {
        this->name = name;
        this->score = score;
        this->hand = Hand();
    }

    void setHand(const Hand& hand) {
        this->hand = hand;
    }

    void clearHand() {
        hand = Hand();
    }

    void addTile(const Tile& t) {
        hand.addTile(t);
    }

    Tile removeTile(const Tile& t) {
        return hand.removeTile(t);
    }

    string toString() {
        string res = name + " " + to_string(score) + " ";
        for (int i = 0; i < hand.size(); i++) {
            res += hand.get(i).toString() + " ";
        }
        return res;
    }
};
