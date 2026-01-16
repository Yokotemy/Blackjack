#include "game.h"
#include "move.h"
#include <iostream>

void game::setUpGame(player &p) {
    std::string n; int d;
    std::cout << "=== BLACKJACK ===\n";
    std::cout << "Podaj imie: "; std::cin >> n; p.setName(n);
    std::cout << "Podaj depozyt: "; std::cin >> d; p.addBalance(d);
}

std::string game::getHint(int pS, int dV) const {
    if (pS >= 17) return "STAND";
    if (pS <= 11) return "HIT";
    if (pS >= 13 && dV <= 6) return "STAND";
    return "HIT";
}

void game::displayState(player &p, croupier &c, bool showFull) const {
    std::cout << "--- STOL ---  " << std::endl;
    std::cout << "KRUPIER: ";
    if(!showFull) {
        c.getHand().getCard(0).displayCard();
        std::cout << " [???]";
    } else {
        c.getHand().displayHand();
        std::cout << " (Suma: " << c.getHand().calculateHand() << ")";
    }
    std::cout << "\n GRACZ: "; p.getHand().displayHand();
    std::cout << " (Suma: " << p.getHand().calculateHand() << ")\n";
}

void game::start(player &p, croupier &c, deck &d) {
    int bet;
    std::cout << "Balans: " << p.getBalance() << " | Zaklad: "; std::cin >> bet;
    if (bet > p.getBalance()) bet = p.getBalance();
    p.subBalance(bet);

    p.takeCard(d); p.takeCard(d);
    c.takeCard(d); c.takeCard(d);
    c.getHand().getCard(1).hide();

    bool endP = false;
    while(!p.isBusted() && !endP) {
        displayState(p, c, false);
        std::cout << "Ruch [h/s/d]: "; char ch; std::cin >> ch;

        if(ch == 'h') {
            HitStrategy s; 
            std::cout << "Akcja: " << s.getMoveName() << "\n";
            p.takeCard(d);
        }
        else if(ch == 's') {
            StandStrategy s;
            std::cout << "Akcja: " << s.getMoveName() << "\n";
            endP = true;
        }
        else if(ch == 'd') {
            DoubleStrategy s;
            std::cout << "Akcja: " << s.getMoveName() << "\n";
            p.subBalance(bet);
            bet *= 2;
            p.takeCard(d);
            endP = true;
        }
    }
    c.getHand().getCard(1).show();
    if(!p.isBusted()) {
        c.playTurn(d);
    }

    std::cout << "\n========== KONIEC RUNDY ==========\n";
    std::cout << "KRUPIER: "; c.getHand().displayHand();
    std::cout << " (" << c.getHand().calculateHand() << ")" << (c.isBusted() ? " BUST!" : "") << "\n";
    std::cout << "GRACZ:   "; p.getHand().displayHand();
    std::cout << " (" << p.getHand().calculateHand() << ")" << (p.isBusted() ? " BUST!" : "") << "\n";

    int ps = p.getHand().calculateHand();
    int cs = c.getHand().calculateHand();

    std::cout << "WYNIK: ";
    if (p.isBusted()) std::cout << "Przegrana (BUST)";
    else if (cs > 21) { std::cout << "Wygrana (KRUPIER BUST)"; p.addBalance(bet * 2); }
    else if (ps > cs) { std::cout << "Wygrana!"; p.addBalance(bet * 2); }
    else if (ps == cs) { std::cout << "Remis (Push)"; p.addBalance(bet); }
    else std::cout << "Przegrana";
    std::cout << "\n==================================\n";

    p.clear(); c.clear();
}
