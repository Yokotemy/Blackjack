#include "game.h"
#include <iostream>

int main() {
    player p; croupier c; deck d; game g;
    g.setUpGame(p);
    while(p.getBalance() > 0) {
        g.start(p, c, d);
        std::cout << "Grasz dalej? (1/0): "; int go; std::cin >> go;
        if(!go) break;
    }
    return 0;
}
