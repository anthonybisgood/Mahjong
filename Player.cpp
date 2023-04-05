#include <iostream>
#include <string>
#include <vector>

#include "Hand.cpp"

using namespace std;

class Player {
   private:
    int score;
    string name;
    Hand hand;
    /** deadHand is a hand that contains all the tiles that have been "used" 
     * (pong/chi/kong) that cannot be used by another player
    */
    Hand deadHand;
    Hand flowersHand;
    vector<string> flowerSeasons = {"Plum", "Orchid", "Chrysanthemum", "BambooFlower", "Spring", "Summer", "Autumn", "Winter"};

    /**
     * @brief Adds the tile to the dead hand and removes it from the player's hand
     *
     * @param t
     */
    void addToDeadHand(const Tile& t) {
        removeTile(t);
        deadHand.addTile(t);
    }

   public:
    Player(string name, int score, string position) {
        this->name = name;
        this->score = score;
        this->hand = Hand();
        this->deadHand = Hand();
        this->position = position;
        this->numFlowers = 0;
    }

    /**
     * @brief Clears both players hands
     *
     */
    void clearHand() {
        hand.clear();
        deadHand.clear();
    }

    /**
     * @brief Forms a "Straight" with 3 tiles
     * 
     * @param index1 
     * @param index2 
     * @param t 
     */
    bool chi(int index1, int index2, Tile& t) {
        Tile t1 = hand.get(index1);
        Tile t2 = hand.get(index2);
        if (t1.getSuit() != t2.getSuit() || t2.getSuit() != t.getSuit()) {
            cout << "Tiles are not the same suit" << endl;
            return false;
        }
        int t1Rank = t1.getRank();
        int t2Rank = t2.getRank();
        int insertTileRank = t.getRank();
        int smallestRank = min(t1Rank, min(t2Rank, insertTileRank));
        int largestRank = max(t1Rank, max(t2Rank, insertTileRank));
        int middleRank = t1Rank + t2Rank + insertTileRank - smallestRank - largestRank;
        if (!(smallestRank + 1 == middleRank && middleRank + 1 == largestRank)) {
            cout << "Tiles are not in a straight" << endl;
            return false;
        }
        addToDeadHand(t1);
        addToDeadHand(t2);
        addToDeadHand(t);
        return true;
    }

    /**
     * @brief Adds the tile to the player's hand, if the tile is a flower or season,
     * it will add it to the dead hand. Returns true if the tile was added to the hand,
     * false if it was added to the dead hand.
     *
     * @param t tile to add
     * @return true
     * @return false
     */
    bool addTile(const Tile& t) {
        if (find(flowerSeasons.begin(), flowerSeasons.end(), t.getSuit()) != flowerSeasons.end()) {
            flowersHand.addTile(t);
            return false;
        } else {
            hand.addTile(t);
            return true;
        }
    }

    /**
     * @brief Removes the tile from the hand, if tile not in hand, throws error
     *
     * @param t tile to remove
     */
    void removeTile(const Tile& t) {
        try {
            hand.removeTile(t);
        } catch (const char* msg) {
            cout << msg << endl;
        }
    }

    /**
     * @brief Adds the score to the player's score
     *
     * @param score score to add
     * @return int
     */
    int addScore(const int& score) {
        this->score += score;
        return this->score;
    }

    /**
     * @brief Returns the score of the player
     *
     * @return int
     */
    int getScore() const {
        return this->score;
    }

    string toString() {
        string res = name + " " + to_string(score) + "\n";
        res += deadHand.toString();
        res += " \n";
        res += hand.toString();
        return res;
    }
};