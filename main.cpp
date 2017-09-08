#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.h"
#include "view.h"
#include "player.h"

using namespace sf;
using namespace std;



int main()
{
    int CurrentFrame = 0;

    MakeTileMapArr(MapOne);

    Clock clock;

    RenderWindow window(VideoMode(600, 400), "ORGANI!!!");
    gameView.reset(FloatRect(0,0,600,400));


    //std::cout << TileMap[HEIGHT_MAP][WIDTH_MAP];




    Player newPlayer("player.png",100,100);

        Image map_image;
        map_image.loadFromFile("images/texturaImage.png");
        Texture map_texture;

        map_texture.loadFromImage(map_image);
        int mapTextureSizeX = map_texture.getSize().x/10;
       //int mapTextureSizeY = map_texture.getSize().y;
        int mapTextureWidth = map_texture.getSize().x/10;
        int mapTextureHight = map_texture.getSize().y;

        //STRARR - пусто, b банана, 0 глина, a яблоко, m мухомор, c вишня, M магнит, L рычаг лево, R рычаг право D door
        //INTARR 0 пусто, 1 банана, 2 глина, 3 яблоко, 4 мухомор, 5 вишня, 6 магнит, 7 рычаг лево, 8 рычаг право 9 Door

        Sprite s_map;
        s_map.setTexture(map_texture);

        int widthT = newPlayer.texture.getSize().x/3;
        int hightT = newPlayer.texture.getSize().y/4;





    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;   // БЛОК СКОРОСТИ ИГРЫ




        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
                {
                    newPlayer.dir = 1;
                    newPlayer.speed = 0.2;
                    CurrentFrame ++; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
                    if (CurrentFrame == 3) CurrentFrame = 0; // если пришли к третьему кадру - откидываемся назад.
                    newPlayer.sprite.setTextureRect(IntRect(widthT * CurrentFrame,hightT * 0, widthT, hightT));
                    getPlayerCoorinateForView(newPlayer.getPlayerCoordinateX(),newPlayer.getPlayerCoordinateY());

                }

        if (Keyboard::isKeyPressed(Keyboard::Right))
                {
                    newPlayer.dir = 0;
                    newPlayer.speed = 0.2;
                    CurrentFrame ++; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
                    if (CurrentFrame == 3) CurrentFrame = 0; // если пришли к третьему кадру - откидываемся назад.
                    newPlayer.sprite.setTextureRect(IntRect(widthT * (int)CurrentFrame,hightT * 2,widthT,hightT));
                    getPlayerCoorinateForView(newPlayer.getPlayerCoordinateX(),newPlayer.getPlayerCoordinateY());


                }

        if (Keyboard::isKeyPressed(Keyboard::Up))
                {
                    newPlayer.dir = 3;
                    newPlayer.speed = 0.2;
                    CurrentFrame ++; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
                    if (CurrentFrame == 3) CurrentFrame = 0; // если пришли к третьему кадру - откидываемся назад.
                    newPlayer.sprite.setTextureRect(IntRect(widthT * (int)CurrentFrame,hightT*1,widthT,hightT));
                    getPlayerCoorinateForView(newPlayer.getPlayerCoordinateX(),newPlayer.getPlayerCoordinateY());


                }

        if (Keyboard::isKeyPressed(Keyboard::Down))
                {
                    newPlayer.dir = 2;
                    newPlayer.speed = 0.2;
                    CurrentFrame++; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
                    if (CurrentFrame == 3) CurrentFrame = 0; // если пришли к третьему кадру - откидываемся назад.
                    newPlayer.sprite.setTextureRect(IntRect(widthT * (int)CurrentFrame,hightT * 1,widthT,hightT));
                    getPlayerCoorinateForView(newPlayer.getPlayerCoordinateX(),newPlayer.getPlayerCoordinateY());

                }


        newPlayer.interactionWithMap(time);
        newPlayer.update(time);

        //if (Keyboard::isKeyPressed(Keyboard::Left)) {herosprite.move(-0.5,0);}
       // if (Keyboard::isKeyPressed(Keyboard::Right)) {herosprite.move(0.5,0);}
        //if (Keyboard::isKeyPressed(Keyboard::Up)) {herosprite.move(0, -0.5);}
        //if (Keyboard::isKeyPressed(Keyboard::Down)) {herosprite.move(0, 0.5);}


        window.setView(gameView);
        window.clear();

        //STRARR - пусто, b банана, 0 глина, a яблоко, m мухомор, c вишня, M магнит, L рычаг лево, R рычаг право D door
        //INTARR 0 пусто, 1 банана, 2 глина, 3 яблоко, 4 мухомор, 5 вишня, 6 магнит, 7 рычаг лево, 8 рычаг право 9 door

        for (int i = 0; i < iMap; i++)
        for (int j = 0; j < jMap; j++)
            {
                if (TileMap[i][j] == 0)  s_map.setTextureRect(IntRect(mapTextureSizeX * 0,0,mapTextureWidth,mapTextureHight));
                if (TileMap[i][j] == 1)  s_map.setTextureRect(IntRect(mapTextureSizeX * 1,0,mapTextureWidth,mapTextureHight));
                if (TileMap[i][j] == 2)  s_map.setTextureRect(IntRect(mapTextureSizeX * 2,0,mapTextureWidth,mapTextureHight));
                if (TileMap[i][j] == 3)  s_map.setTextureRect(IntRect(mapTextureSizeX * 3,0,mapTextureWidth,mapTextureHight));
                if (TileMap[i][j] == 4)  s_map.setTextureRect(IntRect(mapTextureSizeX * 4,0,mapTextureWidth,mapTextureHight));
                if (TileMap[i][j] == 5)  s_map.setTextureRect(IntRect(mapTextureSizeX * 5,0,mapTextureWidth,mapTextureHight));
                if (TileMap[i][j] == 6)  s_map.setTextureRect(IntRect(mapTextureSizeX * 6,0,mapTextureWidth,mapTextureHight));
                if (TileMap[i][j] == 7)  s_map.setTextureRect(IntRect(mapTextureSizeX * 7,0,mapTextureWidth,mapTextureHight));
                if (TileMap[i][j] == 8)  s_map.setTextureRect(IntRect(mapTextureSizeX * 8,0,mapTextureWidth,mapTextureHight));
                if (TileMap[i][j] == 9)  s_map.setTextureRect(IntRect(mapTextureSizeX * 9,0,mapTextureWidth,mapTextureHight));

                    s_map.setPosition(j * 20, i * 20);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

                    window.draw(s_map);//рисуем квадратики на экран
            }


        window.draw(newPlayer.sprite);
        window.display();
    }

    return 0;
}
