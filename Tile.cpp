
#ifndef TILE_HPP
#define TILE_HPP

#include <string>

using namespace std;

class Tile {
   private:
    string suit;
    int rank;

   public:

    Tile(string suit, int rank) {
        this->suit = suit;
        this->rank = rank;
    }

    string getSuit() const {
        return suit;
    }

    int getRank() const {
        return rank;
    }

    void setRank(int rank) {
        this->rank = rank;
    }

    bool operator==(const Tile& other) const {
        return suit == other.suit && rank == other.rank;
    }

    string toString() const {
        return suit + " " + to_string(rank);
    }
};

#endif