#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>



namespace hkp{

    class State{
      public:
        State()= default;
        ~State()= default;
        virtual bool init() = 0;
    };
} //hkp