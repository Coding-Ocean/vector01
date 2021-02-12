#if 0

#include"libOne.h"
void gmain() {
    window(1000, 1000);
    while (notQuit) {
    }
}

#else

#include"libOne.h"
struct UNKO {
    int img = 0;
    float px=0, py=0, vx=0, vy=0, deg=0;
    int hp=0;
};
void gmain() {
    window(1920, 1080, full);
    int img1 = loadImage("assets\\unkoWhite.png");
    int img2 = loadImage("assets\\unko.png");
    const int num = 256;
    int deg = 0;
    angleMode(DEGREES);
    UNKO unko[num];
    int i = 0;
    rectMode(CENTER);
    while (notQuit) {
        //”­ŽË
        if (isPress(MOUSE_LBUTTON)) {
            for (i = 0; i < num; i++) {
                if (unko[i].hp == 0) {
                    unko[i].img = img1;
                    unko[i].px = mouseX+sin(deg) * 20;
                    unko[i].py = -50;
                    unko[i].vx = 0;
                    unko[i].vy = 10;
                    unko[i].deg = 0;
                    unko[i].hp = 1;
                    deg+=6;
                    i = num;
                }
            }
        }
        if (isPress(MOUSE_RBUTTON)) {
            for (i = 0; i < num; i++) {
                if (unko[i].hp == 0) {
                    unko[i].img = img1;
                    unko[i].px = width/2;
                    unko[i].py = height/2;
                    unko[i].vx = sin(deg)*5;
                    unko[i].vy = -cos(deg)*5;
                    unko[i].deg = deg;
                    unko[i].hp = 1;
                    deg += 6;
                    i = num;
                }
            }
        }
        //ˆÚ“®
        for (i = 0; i < num; i++) {
            if (unko[i].hp > 0) {
                unko[i].px += unko[i].vx;
                unko[i].py += unko[i].vy;
                if (unko[i].py <-50 ||
                    unko[i].py > height + 50 ||
                    unko[i].px > width + 50 ||
                    unko[i].px < -50
                    ) {
                    unko[i].hp = 0;
                }
            }
        }
        //•`‰æ
        clear(200,200,0);
        imageColor(143, 105, 68);
        for (i = 0; i < num; i++) {
            if (unko[i].hp > 0) {
                image(unko[i].img, unko[i].px, unko[i].py, unko[i].deg);
            }
        }
    }
}

#endif