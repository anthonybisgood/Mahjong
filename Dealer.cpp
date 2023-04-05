#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "144Tiles.hpp"

using namespace std;

class Dealer {
   private:
    vector<Tile> tiles = {
        B1, B2, B3, B4, B5, B6, B7, B8, B9,
        B1, B2, B3, B4, B5, B6, B7, B8, B9,
        B1, B2, B3, B4, B5, B6, B7, B8, B9,
        B1, B2, B3, B4, B5, B6, B7, B8, B9,
        C1, C2, C3, C4, C5, C6, C7, C8, C9,
        C1, C2, C3, C4, C5, C6, C7, C8, C9,
        C1, C2, C3, C4, C5, C6, C7, C8, C9,
        C1, C2, C3, C4, C5, C6, C7, C8, C9,
        D1, D2, D3, D4, D5, D6, D7, D8, D9,
        D1, D2, D3, D4, D5, D6, D7, D8, D9,
        D1, D2, D3, D4, D5, D6, D7, D8, D9,
        D1, D2, D3, D4, D5, D6, D7, D8, D9,
        EAST, SOUTH, WEST, NORTH,
        EAST, SOUTH, WEST, NORTH,
        EAST, SOUTH, WEST, NORTH,
        EAST, SOUTH, WEST, NORTH,
        RD, GD, WD,
        RD, GD, WD,
        RD, GD, WD,
        RD, GD, WD,
        Spring, Summer, Autumn, Winter,
        Plum, Orchid, Chrysanthemum, Bamboo};
    vector<Tile> currGame;
    Tile lastTile = Tile("None", -1);

   public:
    Dealer() {
        shuffleTiles();
    }

    /**
     * @brief Shuffles the tiles and sets the current game to the shuffled tiles
     *
     */
    void shuffleTiles() {
        lastTile = Tile("None", -1);
        random_device rd;
        currGame = tiles;
        mt19937 g(rd());
        shuffle(currGame.begin(), currGame.end(), g);
    }

    /**
     * @brief Deals a tile to the player from the current pool
     *
     * @return Tile
     */
    Tile deal() {
        Tile t = currGame.back();
        currGame.pop_back();
        return t;
    }

    /**
     * @brief Returns the last tile a player put down
     *
     * @return Tile
     */
    Tile getLastTile() const {
        return lastTile;
    }

    /**
     * @brief Set the Last Tile to the tile a player put down
     *
     * @param t tile to set
     */
    void setLastTile(const Tile& t) {
        lastTile = t;
    }

    /**
     * @brief Returns number of tiles left in the current game
     *
     * @return int
     */
    int getNumTiles() const {
        return currGame.size();
    }
};