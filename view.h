#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED
#include <SFML\Graphics.hpp>


using namespace sf;


View gameView;

        void getPlayerCoorinateForView(float X, float Y) {

            gameView.setCenter(300,200);

        }

#endif // VIEW_H_INCLUDED
