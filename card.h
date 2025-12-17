#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

// pomocnicze klasy do budowy karty
enum class Face {
    two, three, four, five,
    six, seven, eight, nine, ten,
    jack, queen, king, ace};

enum class Color {clover, spade, heart, diamond};

class card {
    Face face;
    Color color;
    bool visible = true; //zeby karty krupiera mogly byc zakryte

    public:
        card();
        card(Face f, Color c, bool v = true);
        void displayCard(); // wyświetlanie karty
        Face getFace();  // getter dla face'a
        void show();
        void hide();
        bool isVisible();
};

#endif //BLACKJACK_CARD_H