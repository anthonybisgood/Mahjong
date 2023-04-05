#include <algorithm>
#include <vector>

#include "144Tiles.hpp"

class Hand {
   private:
    vector<Tile> hand;
    /**
     * @brief Returns the index of the tile in the hand, -1 if not found
     *
     * @param t tile to find
     * @return int
     */
    int contains(const Tile& t) const {
        for (int i = 0; i < hand.size(); i++) {
            if (hand[i] == t) {
                return i;
            }
        }
        return -1;
    }

   public:
    Hand() {
        hand = vector<Tile>();
    }

    /**
     * @brief Adds a tile to the hand and sorts it
     *
     * @param t tile to add
     */
    void addTile(const Tile& t) {
        hand.push_back(t);
        sort(hand.begin(), hand.end());
    }

    /**
     * @brief Returns the size of the hand
     *
     * @return int
     */
    int size() const {
        return hand.size();
    }

    /**
     * @brief Returns the tile at the given index
     *
     * @param i
     * @return Tile
     */
    Tile get(const int& i) const {
        return hand[i];
    }

    /**
     * @brief Removes the tile from the hand and returns it.
     * If the tile is not in the hand it throws an error
     *
     * @param t tile to remove
     * @return Tile
     */
    Tile removeTile(const Tile& t) {
        int tileIndex = contains(t);
        if (tileIndex == -1) {
            throw "Tile not found";
        }
        Tile removed = hand[tileIndex];
        hand.erase(hand.begin() + tileIndex);
        return removed;
    }

    /**
     * @brief Clears the hand
     *
     */
    void clear() {
        hand.clear();
    }

    /**
     * @brief returns the count of elements that equal t 
     * 
     * @param t 
     * @return int 
     */
    int getCount(const Tile& t) {
        int numOfElements = count(hand.begin(), hand.end(), t);
        return numOfElements;
    }

    string toString() const {
        string res = "[";
        if (hand.size() == 0) {
            return res + "]";
        }
        res += hand[0].toString();
        for (int i = 1; i < hand.size(); i++) {
            res += ", " + hand[i].toString();
        }
        res += "]";
        return res;
    }
};