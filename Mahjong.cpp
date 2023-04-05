#include <iostream>
#include <string>
#include <vector>

#include "Dealer.cpp"
#include "Player.cpp"

using namespace std;

class Mahjong {
   private:
    vector<Player> players;
    Dealer dealer;

    void dealInitial() {
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < players.size(); j++) {
                dealTile(players[j]);
            }
        }
    }
    /**
     * @brief Deals a tile to a player, if the player gets flowers or seasons,
     * it will deal another tile. If the dealer is out of tiles (16 remaining), it will exit
     *
     * @param p
     */
    void dealTile(Player& p) {
        if (dealer.getNumTiles() == 16) {
            cout << "Dealer is out of tiles" << endl;
            exit(-1);
        }
        while (p.addTile(dealer.deal()) == false) {
        }
    }

    bool isGameOver() {
        return false;
    }

    void playerTurn(Player& p) {
        // draw from pile or last tile
        // if draw from last tile, check if they are allowed (pong, kong, chi, hu)
        cout << "Draw from pile or from last played? (p/l)" << endl;
        string action;
        cin >> action;
        if (action == "p") {
            dealTile(p);
            cout << "Your hand: " << p.toString() << endl;
        } else {
            Tile lastTile = dealer.getLastTile();
            cout << "Last played tile: " << lastTile.toString() << endl;
            cout << "What would you like to do? (c/p/k/h)" << endl;
            string action;
            cin >> action;
            //chi
            if (action == "c") {
                p.addTile(lastTile);
                bool canChi = chiAction(p, lastTile);
                if (!canChi) {
                    cout << "You cannot chi" << endl;
                    p.removeTile(lastTile);
                }
                // add to dead hand
                
            // pong
            } else if (action == "p") {
                p.addTile(lastTile);
                bool canPong = p.pong(lastTile);
            // kong
            } else if (action == "k") {
                
            // hu
            } else if (action == "h") {
                
            }
            
        }
        // discard tile, dealer will add to last played
    }

    bool chiAction(Player& p, Tile& lastTile) {
        // check if the player has the tiles to chi
        // if they do, remove the tiles from the player's hand and add it to players dead hand
        cout << "First tile you want to chi with: " << endl;
        int firstTileIndex;
        cin >> firstTileIndex;
        cout << "Second tile you want to chi with: " << endl;
        int secondTileIndex;
        cin >> secondTileIndex;
        bool canChi = p.chi(firstTileIndex, secondTileIndex, lastTile);
        return canChi;
    }

    bool pongAction(Player& p, Tile& lastTile) {
        // check if the player has the tiles to pong
        // if they do, remove the tiles from the player's hand and add it to players dead hand
        bool canPong = p.pong(lastTile);
        return canPong;
    }

   public:
    Mahjong(Player p1, Player p2, Player p3, Player p4) {
        dealer = Dealer();
        this->players = {p1, p2, p3, p4};
    }

    void play() {
        dealer.shuffleTiles();
        dealInitial();
        int currPlayer = 0;
        while (!isGameOver()) {
            playerTurn(players[currPlayer]);
            currPlayer = (currPlayer+1) % players.size();
        }   
        

    }

    string toString() {
        string res = "";
        for (int i = 0; i < players.size(); i++) {
            res += players[i].toString();
            res += "\n";
        }
        return res;
    }
};

int main() {
    Player p1 = Player("p1", 0, "east");
    Player p2 = Player("p2", 0, "south");
    Player p3 = Player("p3", 0, "west");
    Player p4 = Player("p4", 0, "north");
    Mahjong game = Mahjong(p1, p2, p3, p4);
    game.play();
    cout << game.toString() << endl;
}
