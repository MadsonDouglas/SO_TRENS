#include "trem.h"
#include <QtCore>

sem_t site1,site2,site3,site4,site5,site6,site7;

/*
    site_1(470, 130)
    site_2(260, 190)
    site_3(410, 190)
    site_4(540, 190)
    site_5(670, 190)

    site_6(330, 250)
    site_7(600, 250)
*/
//Construtor
Trem::Trem(int ID, int x, int y)
{
    this->ID = ID;
    this->y = y;
    this->x = x;
    this->velocidade = 200;

    sem_init(&site1,1,1);
    sem_init(&site2,1,1);
    sem_init(&site3,1,1);
    sem_init(&site4,1,1);
    sem_init(&site5,1,1);
    sem_init(&site6,1,1);
    sem_init(&site7,1,1);
}

void Trem::setTrainVelocity(int value)
{
    this->velocidade = value;
}

void Trem::run()
{
    while(true){
        if(velocidade == 200)
            while(velocidade == 200) msleep(1);

        switch(ID)
        {
        case 1:     //Trem 1
            if (y == 190 && x < 330)
            {


                x+=10;
            } else if (x == 330 && y < 310)
            {


                y+=10;
            } else if (x > 60 && y == 310){


                x-=10;
            }
            else
                y-=10;

            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if (y == 190 && x < 600)
            {

                x+=10;
            }
            else if (x == 600 && y < 310)
                y+=10;
            else if (x > 330 && y == 310)
            {
                x-=10;
            }
            else
            {
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3: //Trem 3
            if (y == 190 && x < 870)
            {
                x+=10;
            }
            else if (x == 870 && y < 310)
                y+=10;
            else if (x > 600 && y == 310)
            {
                x-=10;
            }  else  {
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4: //Trem 4
            if (y == 70 && x < 470)
            {
                x+=10;
            }
            else if (x == 470 && y < 190)
            {
                y+=10;
            }
            else if (x > 200 && y == 190)
            {
                x-=10;
            }
            else
            {
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5: //Trem 5
            if (y == 70 && x < 740)
            {

                x+=10;
            }
            else if (x == 740 && y < 190)
            {

                y+=10;
            }
            else if (x > 470 && y == 190)
            {

                x-=10;
            }
            else
                y-=10;

            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(this->velocidade);
    }


    sem_destroy(&site1);
    sem_destroy(&site2);
    sem_destroy(&site3);
    sem_destroy(&site4);
    sem_destroy(&site5);
    sem_destroy(&site6);
    sem_destroy(&site7);
}
