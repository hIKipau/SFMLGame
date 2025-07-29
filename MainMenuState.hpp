#pragma once
#include "State.hpp"

namespace hkp{

    class MainMenuState : public State {
      public:
        MainMenuState() = default;
        ~MainMenuState() = default;
        bool init();

        sf::Texture backgroundTexture;


    };

} //hkp

