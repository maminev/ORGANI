#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>
//#include <iostream>
using namespace sf;
using namespace std;

class Player{
        private:
        float x,y;

        public:
        float w,h,dx,dy,speed; // Координаты игрока
        int dir; // направление движения игрока
        String File;
        Image image;
        Texture texture;
        Sprite sprite;
        sf::Vector2f leftTop;
        sf::Vector2f leftIntermidiate;
        sf::Vector2f leftBottom;
        sf::Vector2f rightTop;
        sf::Vector2f rightIntermidiate;
        sf::Vector2f rightBottom;

        Player(String F, float X, float Y);
        ~Player();

        void setPlayerColor(sf::Color colPl);

        void update(float time); //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.

        float getPlayerCoordinateX () {return x;}
        float getPlayerCoordinateY () {return y;}

        void setPlayerCoordinateX (float X) { x = X;}
        void setPlayerCoordinateY (float Y) { y = Y;}

        void interactionWithMap(float time);

        };


Player::Player(String F, float X, float Y)
                {
                  dx=0;dy=0;speed=0;dir=0;
                  File = F;//имя файла+расширение

                  image.loadFromFile("images/" + File);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта. В нашем случае "hero.png" и получится запись идентичная image.loadFromFile("images/hero/png");
                  image.createMaskFromColor(Color(220, 254, 186));//убираем ненужный темно-синий цвет, эта тень мне показалась не красивой.
                  texture.loadFromImage(image);//закидываем наше изображение в текстуру
                  w = texture.getSize().x/3;
                  h = texture.getSize().y/4;
                  sprite.setTexture(texture);//заливаем спрайт текстурой
                  x = X; y = Y;//координата появления спрайта
                  sprite.setTextureRect(IntRect(0,0,w,h)); //Задаем спрайту один прямоугольник для вывода одного льва, а не кучи львов сразу. IntRect - приведение типов
                }



 Player::~Player()
    {

    }


void Player::update(float time)
        {
            switch (dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
                {
                case 0: dx = speed; dy = 0; break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что персонаж идет только вправо
                case 1: dx = -speed; dy = 0; break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что персонаж идет только влево
                case 2: dx = 0; dy = speed; break;//по иксу задаем нулевое значение, по игреку положительное. получается, что персонаж идет только вниз
                case 3: dx = 0; dy = -speed; break;//по иксу задаем нулевое значение, по игреку отрицательное. получается, что персонаж идет только вверх
                case 4: dx = 0; dy = 0; break; // стоит на месте
                }

            x += dx*time;//то движение из прошлого урока. наше ускорение на время получаем смещение координат и как следствие движение
            y += dy*time;//аналогично по игреку

            speed = 0;//зануляем скорость, чтобы персонаж остановился.

            sprite.setPosition(x,y); //выводим спрайт в позицию x y , посередине. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.

        }

    void Player::interactionWithMap(float time)

            {
                // определяем координаты для 8ми точек спрайта.
                leftTop.x = getPlayerCoordinateX();
                leftTop.y = getPlayerCoordinateY();
                leftIntermidiate.x  = getPlayerCoordinateX();
                leftIntermidiate.y = getPlayerCoordinateY()+h/2;
                leftBottom.x = getPlayerCoordinateX();
                leftBottom.y = getPlayerCoordinateY()+h;
                rightTop.x = getPlayerCoordinateX() + w;
                rightTop.y = getPlayerCoordinateY();
                rightIntermidiate.x  = getPlayerCoordinateX() + w;
                rightIntermidiate.y = getPlayerCoordinateY()+h/2;
                rightBottom.x = getPlayerCoordinateX() + w;
                rightBottom.y = getPlayerCoordinateY()+h;



                int iLT = leftTop.y/20;
                int jLT = leftTop.x/20;
                int iLI = leftIntermidiate.y/20;
                int jLI = leftIntermidiate.x/20;
                int iLB = leftBottom.y/20;
                int jLB = leftBottom.x/20;

                int iIT = leftTop.y/20;
                int jIT = (leftTop.x + w/2)/20;

                int iIB = leftBottom.y/20;
                int jIB = (leftBottom.x + w/2)/20;

                int iRT = rightTop.y/20;
                int jRT = rightTop.x/20;
                int iRI = rightIntermidiate.y/20;
                int jRI = rightIntermidiate.x/20;
                int iRB = rightBottom.y/20;
                int jRB = rightBottom.x/20;


               /* system("cls");
                cout << "Player was interractive coordinates as iRT  " << iRT << "  and jRT  " << jRT << endl;
                cout << "Player was interractive coordinates as iRI  " << iRI << "  and jRI  " << jRI << endl;
                cout << "Player was interractive coordinates as iRB  " << iRB << "  and jRB  " << jRB << endl;
                cout << "Player was interractive coordinates as iLT  " << iLT << "  and jLT  " << jLT << endl;
                cout << "Player was interractive coordinates as iLI  " << iLI << "  and jLI  " << jLI << endl;
                cout << "Player was interractive coordinates as iLB  " << iLB << "  and jLB  " << jLB << endl;
                cout << "Player was interractive coordinates as iIT  " << iIT << "  and jIT  " << jIT << endl;
                cout << "Player was interractive coordinates as iIB  " << iIB << "  and jIB  " << jIB << endl; */

            //STRARR - пусто, b банана, 0 глина, a яблоко, m мухомор, c вишня, M магнит, L рычаг лево, R рычаг право
            //INTARR 0 пусто, 1 банана, 2 глина, 3 яблоко, 4 мухомор, 5 вишня, 6 магнит, 7 рычаг лево, 8 рычаг право


                  if (TileMap[iLT][jLT] == 2 && dir == 1) {dir=4; setPlayerCoordinateX(getPlayerCoordinateX() + 5);}
             else if (TileMap[iLI][jLI] == 2 && dir == 1) {dir=4; setPlayerCoordinateX(getPlayerCoordinateX() + 5);}
             else if (TileMap[iLB][jLB] == 2 && dir == 1) {dir=4; setPlayerCoordinateX(getPlayerCoordinateX() + 5);}

             else if (TileMap[iRT][jRT] == 2 && dir == 0) {dir=4; setPlayerCoordinateX(getPlayerCoordinateX() - 5);}
             else if (TileMap[iRI][jRI] == 2 && dir == 0) {dir=4; setPlayerCoordinateX(getPlayerCoordinateX() - 5);}
             else if (TileMap[iRB][jRB] == 2 && dir == 0) {dir=4; setPlayerCoordinateX(getPlayerCoordinateX() - 5);}

             else if (TileMap[iLT][jLT] == 2 && dir == 3) {dir=4; setPlayerCoordinateY(getPlayerCoordinateY() + 5);}
             else if (TileMap[iIT][jIT] == 2 && dir == 3) {dir=4; setPlayerCoordinateY(getPlayerCoordinateY() + 5);}
             else if (TileMap[iRT][jRT] == 2 && dir == 3) {dir=4; setPlayerCoordinateY(getPlayerCoordinateY() + 5);}

             else if (TileMap[iLB][jLB] == 2 && dir == 2) {dir=4; setPlayerCoordinateY(getPlayerCoordinateY() - 5);}
             else if (TileMap[iIB][jIB] == 2 && dir == 2) {dir=4; setPlayerCoordinateY(getPlayerCoordinateY() - 5);}
             else if (TileMap[iRB][jRB] == 2 && dir == 2) {dir=4; setPlayerCoordinateY(getPlayerCoordinateY() - 5);}
             else {};

                //ПОДЕДАНИЕ БАНАБОВ
             if (TileMap[iLT][jLT] == 1) TileMap[iLT][jLT] = 0;
             else if (TileMap[iLI][jLI] == 1) TileMap[iLI][jLI] = 0;
             else if (TileMap[iLB][jLB] == 1) TileMap[iLB][jLB] = 0;
             else if (TileMap[iRT][jRT] == 1) TileMap[iRT][jRT] = 0;
             else if (TileMap[iRI][jRI] == 1) TileMap[iRI][jRI]  = 0;
             else if (TileMap[iRB][jRB] == 1) TileMap[iRB][jRB] = 0;
             else if (TileMap[iIT][jIT] == 1) TileMap[iIT][jIT] = 0;
             else if (TileMap[iIB][jIB] == 1) TileMap[iIB][jIB] = 0;
             else {};

                //ПОДЕДАНИЕ грибов
             if (TileMap[iLT][jLT] == 4) {TileMap[iLT][jLT] = 0; setPlayerColor(sf::Color::Red);}
             else if (TileMap[iLI][jLI] == 4) {TileMap[iLI][jLI] = 0; setPlayerColor(sf::Color::Yellow);}
             else if (TileMap[iLB][jLB] == 4) {TileMap[iLB][jLB] = 0; setPlayerColor(sf::Color::Green);}
             else if (TileMap[iRT][jRT] == 4) {TileMap[iRT][jRT] = 0; setPlayerColor(sf::Color(173,24,196));}
             else if (TileMap[iRI][jRI] == 4) {TileMap[iRI][jRI] = 0; setPlayerColor(sf::Color(2,218,216));}
             else if (TileMap[iRB][jRB] == 4) {TileMap[iRB][jRB] = 0; setPlayerColor(sf::Color(229,77,253));}
             else if (TileMap[iIT][jIT] == 4) {TileMap[iIT][jIT] = 0; setPlayerColor(sf::Color(218,164,2));}
             else if (TileMap[iIB][jIB] == 4) {TileMap[iIB][jIB] = 0; setPlayerColor(sf::Color(253,177,145));}
             else {};

           }


    void Player::setPlayerColor(sf::Color colPl)
        {
            sprite.setColor(colPl);
        }

#endif // PLAYER_H_INCLUDED
