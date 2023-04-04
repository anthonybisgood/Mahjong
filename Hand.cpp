#include <vector>

#include "144Tiles.hpp"
#include "Tile.cpp"

class Hand {
   private:
    vector<Tile> hand;

   public:
    Hand() {
        hand = vector<Tile>();
    }
    Hand(vector<Tile>& tiles) {
        if (tiles.size() != 16) {
            throw "Hand must have 16 tiles";
        }
        this->hand = tiles;
    }

    void addTile(const Tile& t) {
        hand.push_back(t);
    }

    int size() const {
        return hand.size();
    }

    Tile get(const int& i) const {
        return hand[i];
    }

    Tile removeTile(const Tile& t) {
        for (int i = 0; i < hand.size(); i++) {
            if (hand[i] == t) {
                Tile removed = hand[i];
                hand.erase(hand.begin() + i);
                return removed;
            }
        }
        throw "Tile not found";
    }
};