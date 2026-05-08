cmake_minimum_required(VERSION 3.10)
project(Blackjack)

set(CMAKE_CXX_STANDARD 20)

add_executable(Blackjack main.cpp
        game.cpp
        game.h
        card.cpp
        card.h
        person.h
        player.cpp
        player.h
        hand.cpp
        hand.h
        deck.cpp
        deck.h
        croupier.cpp
        croupier.h
        person.cpp
        move.h)
