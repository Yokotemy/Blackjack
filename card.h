#ifndef CARD_H
#define CARD_H

#include <string>

enum class Face { two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };
enum class Color { clover, spade, heart, diamond };

class card {
    Face face;
    Color color;
    bool visible;

public:
    card();
    card(Face f, Color c, bool v = true);
    void displayCard() const;
    Face getFace() const;
    int getVal() const;
    void show();
    void hide();
    bool isVisible() const;
};

#endif
