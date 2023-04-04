#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "144Tiles.hpp"
#include "Tile.cpp"

using namespace std;

class Dealer {
   private:
    const vector<Tile> tiles = {
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

    void shuffleTiles() {
        lastTile = Tile("None", -1);
        random_device rd;
        currGame = tiles;
        mt19937 g(rd());
        shuffle(currGame.begin(), currGame.end(), g);
    }

   public:
    Dealer() {
        shuffleTiles();
    }

    Tile deal() {
        Tile t = currGame.back();
        currGame.pop_back();
        return t;
    }

    Tile getLastTile() const {
        return lastTile;
    }

    void setLastTile(const Tile& t) {
        lastTile = t;
    }
};