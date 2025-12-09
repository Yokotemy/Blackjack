cmake_minimum_required(VERSION 4.0)
project(Blackjack)

set(CMAKE_CXX_STANDARD 20)

add_executable(Blackjack main.cpp
        Game.cpp
        Game.h
        Card.cpp
        Card.h
        Person.h
        Player.cpp
        Player.h
        Hand.cpp
        Hand.h
        Deck.cpp
        Deck.h
        croupier.cpp
        croupier.h
        person.cpp)
