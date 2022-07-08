#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#define BLACK  "\033[1;0m"
#define RED  "\033[1;31m"
#define BLUE  "\033[1;34m"
#define GREEN  "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define PURPLE  "\033[1;35m"

typedef struct goods{
    int32_t indigoGoods;
    int32_t sugarGoods;
    int32_t tobaccoGoods;
    int32_t coffeeGoods;
    int32_t silverGoods;
}__attribute__ ((__packed__)) sgoods;


typedef struct builded{
    int32_t indigoPlant;
    int32_t sugarMill;
    int32_t tobaccoStorage;
    int32_t coffeeRoaster;
    int32_t silverSmelter;
    int32_t tower;
    int32_t chapel;
    int32_t smithy;
    int32_t poorHouse;
    int32_t blackMarket;
    int32_t crane;
    int32_t carpenter;
    int32_t quarry;
    int32_t well;
    int32_t aqueduct;
    int32_t marketStand;
    int32_t marketHall;
    int32_t tradingPost;
    int32_t archive;
    int32_t prefecture;
    int32_t goldMine;
    int32_t library;
    int32_t statue;
    int32_t victoryColumn;
    int32_t hero;
    int32_t guildHall;
    int32_t cityHall;
    int32_t trinmhalArch;
    int32_t palace;
}__attribute__ ((__packed__)) sbuilded;

typedef struct produce{
    int32_t indigoPlant;
    int32_t sugarMill;
    int32_t tobaccoStorage;
    int32_t coffeeRoaster;
    int32_t silverSmelter;
}__attribute__ ((__packed__)) sproduce;

typedef struct job{
    int32_t producer;
    int32_t builder;
    int32_t prospector;
    int32_t trader;
    int32_t councillor;
}__attribute__ ((__packed__)) sjob;

typedef struct card{
    int32_t tower;
    int32_t chapel;
    int32_t smithy;
    int32_t poorHouse;
    int32_t blackMarket;
    int32_t crane;
    int32_t carpenter;
    int32_t quarry;
    int32_t well;
    int32_t aqueduct;
    int32_t marketStand;
    int32_t marketHall;
    int32_t tradingPost;
    int32_t archive;
    int32_t prefecture;
    int32_t goldMine;
    int32_t library;
    int32_t statue;
    int32_t victoryColumn;
    int32_t hero;
    int32_t guildHall;
    int32_t cityHall;
    int32_t trinmhalArch;
    int32_t palace;
}__attribute__ ((__packed__)) scard;


//print.c
void introduce();
void printgame();
void atten();
void atten();
void printProCard(sproduce *playerCard,sgoods *playerGood);
void printAllCard(sproduce *playerPro, scard *playerCar);
void printAllGoods(sgoods *playerGoods);
void printJod(sjob *allJob);
void printBuildedProCard(sbuilded * playerBui,sgoods *playerGood);
void printBuildedCard(sbuilded * playerBui);

//setCard.c
void setJob(sjob *allJob);
void setGoods(sgoods *goods);
void setProduce(sproduce *allProduce);
void setCard(scard *allCard);
void setPlayerPro(sproduce *playerProduce);
void setPlayerCard(scard *playerCard);
void setPlayerBuiled(sbuilded *builded);
void poker(sproduce *allProduce, scard *allCard, sproduce *playerPro, scard *playerCard);

//works.c
void sellAndWinCard (int32_t choice, int32_t price, sproduce *allProduce, scard *allCard, sproduce *playerProduce, scard *playerCard);
void jobRid(int32_t job, sjob *allJob);
int32_t* money(int32_t forth);
int32_t checkgoods(int32_t check, sgoods *playerGoods);
int32_t checkcard(int32_t check, sproduce *allPro, scard *allCard);
void addcard(int32_t addcard, sproduce *playerPro, scard *playerCar, sproduce *allPro, scard *allCard);
void paymoney (int32_t paycard, sproduce *playerPro, scard *playerCar);
int32_t checkjob(int32_t job, sjob *alljob);
int32_t checkWin(sbuilded *bui);
void subCard(sproduce *allProduce, scard *allCard);
void subCardP(int32_t num,sproduce *playerPro, scard *playerCar);
int32_t* Fmoney(int32_t chooseOne);
void checkNoCard(sproduce *allpro, scard *allCard);
int32_t calScore(sbuilded *bui);
int32_t haveSmi(sbuilded *bui);
int32_t havePoor(sbuilded *bui);
int32_t haveQua(sbuilded *bui);
int32_t haveWel(sbuilded *bui);
int32_t haveAqu(sbuilded * bui);
int32_t haveMH(sbuilded * bui);
int32_t whoWin2(int32_t p1, int32_t p2);
int32_t whoWin3(int32_t p1, int32_t p2, int32_t p3);
int32_t whoWin4(int32_t p1, int32_t p2, int32_t p3, int32_t p4);
void seven(sproduce *playerProduce,scard *playerCard, int32_t haveto, int32_t R);
int32_t haveTo(sbuilded *bui);

//jobActFG.c
void jobActFG(int32_t job, sproduce *playerProduce, scard *playerCard, sbuilded *builded, sproduce *allProduce, scard *allCard, sgoods *playerGoods, int32_t p);

//jobActFN.c
void jobActFN(int32_t job, sproduce *playerProduce, scard *playerCard, sbuilded *builded, sproduce *allProduce, scard *allCard, sgoods *playerGoods, int32_t p);

//jobActRG.c
void jobActRG(int32_t job, sproduce *playerProduce, scard *playerCard, sbuilded *builded, sproduce *allProduce, scard *allCard, sgoods *playerGoods);

//jobActRN.c
void jobActRN(int32_t job, sproduce *playerProduce, scard *playerCard, sbuilded *builded, sproduce *allProduce, scard *allCard, sgoods *playerGoods);
