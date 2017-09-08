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
        float w,h,dx,dy,speed; // ���������� ������
        int dir; // ����������� �������� ������
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

        void update(float time); //������� "���������" ������� ������. update - ����������. ��������� � ���� ����� SFML , ���������� ���� �������� ����������, ����� ��������� ��������.

        float getPlayerCoordinateX () {return x;}
        float getPlayerCoordinateY () {return y;}

        void setPlayerCoordinateX (float X) { x = X;}
        void setPlayerCoordinateY (float Y) { y = Y;}

        void interactionWithMap(float time);

        };


Player::Player(String F, float X, float Y)
                {
                  dx=0;dy=0;speed=0;dir=0;
                  File = F;//��� �����+����������

                  image.loadFromFile("images/" + File);//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������. � ����� ������ "hero.png" � ��������� ������ ���������� image.loadFromFile("images/hero/png");
                  image.createMaskFromColor(Color(220, 254, 186));//������� �������� �����-����� ����, ��� ���� ��� ���������� �� ��������.
                  texture.loadFromImage(image);//���������� ���� ����������� � ��������
                  w = texture.getSize().x/3;
                  h = texture.getSize().y/4;
                  sprite.setTexture(texture);//�������� ������ ���������
                  x = X; y = Y;//���������� ��������� �������
                  sprite.setTextureRect(IntRect(0,0,w,h)); //������ ������� ���� ������������� ��� ������ ������ ����, � �� ���� ����� �����. IntRect - ���������� �����
                }



 Player::~Player()
    {

    }


void Player::update(float time)
        {
            switch (dir)//��������� ��������� � ����������� �� �����������. (������ ����� ������������� �����������)
                {
                case 0: dx = speed; dy = 0; break;//�� ���� ������ ������������� ��������, �� ������ ��������. ��������, ��� �������� ���� ������ ������
                case 1: dx = -speed; dy = 0; break;//�� ���� ������ ������������� ��������, �� ������ ��������. ����������, ��� �������� ���� ������ �����
                case 2: dx = 0; dy = speed; break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� �������� ���� ������ ����
                case 3: dx = 0; dy = -speed; break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� �������� ���� ������ �����
                case 4: dx = 0; dy = 0; break; // ����� �� �����
                }

            x += dx*time;//�� �������� �� �������� �����. ���� ��������� �� ����� �������� �������� ��������� � ��� ��������� ��������
            y += dy*time;//���������� �� ������

            speed = 0;//�������� ��������, ����� �������� �����������.

            sprite.setPosition(x,y); //������� ������ � ������� x y , ����������. ���������� ������� � ���� �������, ����� �� ��� ������ ����� �� �����.

        }

    void Player::interactionWithMap(float time)

            {
                // ���������� ���������� ��� 8�� ����� �������.
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

            //STRARR - �����, b ������, 0 �����, a ������, m �������, c �����, M ������, L ����� ����, R ����� �����
            //INTARR 0 �����, 1 ������, 2 �����, 3 ������, 4 �������, 5 �����, 6 ������, 7 ����� ����, 8 ����� �����


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

                //��������� �������
             if (TileMap[iLT][jLT] == 1) TileMap[iLT][jLT] = 0;
             else if (TileMap[iLI][jLI] == 1) TileMap[iLI][jLI] = 0;
             else if (TileMap[iLB][jLB] == 1) TileMap[iLB][jLB] = 0;
             else if (TileMap[iRT][jRT] == 1) TileMap[iRT][jRT] = 0;
             else if (TileMap[iRI][jRI] == 1) TileMap[iRI][jRI]  = 0;
             else if (TileMap[iRB][jRB] == 1) TileMap[iRB][jRB] = 0;
             else if (TileMap[iIT][jIT] == 1) TileMap[iIT][jIT] = 0;
             else if (TileMap[iIB][jIB] == 1) TileMap[iIB][jIB] = 0;
             else {};

                //��������� ������
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
