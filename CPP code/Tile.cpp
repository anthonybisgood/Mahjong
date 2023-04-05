
#ifndef TILE_HPP
#define TILE_HPP

#include <string>

using namespace std;

class Tile {
   private:
    // suit indicates the tile type, rank indicates the number on the tile
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

    /**
     * @brief Compares two tiles, first by suit, then by rank
     * 
     * @param other The other tile to compare
     * @return true if the tiles are equal
     * @return false if the tiles are not equal
     */
    bool operator==(const Tile& other) const {
        return suit == other.suit && rank == other.rank;
    }

    /**
     * @brief Compares two tiles, first by suit, then by rank
     * 
     * @param other The other tile to compare
     * @return true if this tile is less than the other tile
     * @return false if this tile is greater than the other tile
     */
    bool operator<(const Tile& other) const {
        if (suit == other.suit) {
            return rank < other.rank;
        }
        return suit < other.suit;
    }

    string toString() const {
        if (suit == "None")
            return "No tiles to pick up, draw from the wall";
        return suit + " " + to_string(rank);
    }
};

#endif