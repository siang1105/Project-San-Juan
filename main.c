#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "sanJuan.h"

int main(){
    srand(time(NULL));
    printgame();
    int32_t choose = 0;
    printf(BLACK);
    printf("Please input your choice: ");
    scanf("%d",&choose);
    if(choose == 2){
        atten();
    }
    else if(choose == 3){
        introduce();
    }

    else if(choose == 4){
        printf(PURPLE);
        printf("GoodBye\n");
        return 0;
    }
    else if(choose == 1){
        int32_t people = 0;
        printf("請輸入遊戲難易度(簡單：1 正常：2) : ");
        int32_t easy = 0;
        scanf("%d",&easy);
        printf("Please input the number of people(2-4): ");
        scanf("%d",&people);
        if(people < 2 || people > 4){
            printf(YELLOW);
            printf("The game is for 2-4 people\n");
            return 0;
        }
        if(people == 2){
            sjob allJob;
            sproduce allProduce;
            scard allCard;
            sgoods p1Goods;
            sgoods p2Goods;
            sproduce p1Pro;
            sproduce p2Pro;
            sbuilded p1Bui;
            sbuilded p2Bui;
            scard p1Card;
            scard p2Card;
            setCard(&allCard);
            setProduce(&allProduce);
            setJob(&allJob);
            setGoods(&p1Goods);
            setGoods(&p2Goods);
            setPlayerBuiled(&p1Bui);
            setPlayerBuiled(&p2Bui);
            setPlayerPro(&p1Pro);
            setPlayerPro(&p2Pro);
            setPlayerCard(&p1Card);
            setPlayerCard(&p2Card);
            allProduce.indigoPlant -= 2;
            printf("發牌中........\n");
            sleep(2);
            poker(&allProduce, &allCard, &p1Pro, &p1Card);
            poker(&allProduce, &allCard, &p2Pro, &p2Card);
            int32_t governor = 1;
            int32_t randJob = 0;
            int32_t check = 2;
            while(1){
                while(governor == 1){
                    int32_t tow1 = haveTo(&p1Bui);
                    int32_t tow2 = haveTo(&p2Bui);
                    seven(&p1Pro, &p1Card, tow1, 1);
                    seven(&p2Pro, &p2Card, tow2, 2);
                    printf("\n");
                    printf("------Player 1 is governor------\n");
                    printf("\n");
                    sleep(1);
                    printAllCard(&p1Pro, &p1Card);
                    sleep(1);
                    printBuildedCard(&p1Bui);
                    sleep(1);
                    printAllGoods(&p1Goods);
                    sleep(1);
                    // printf(BLUE);
                    // printf("Player 1:\n");
                    // printf(BLACK);
                    printJod(&allJob);//記得把被選的工作去掉
                    printf("Please choose one(1-5): ");
                    int32_t choJob = 0;
                    scanf("%d",&choJob);
                    jobRid(choJob, &allJob);
                    jobActRG(choJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(choJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    // checkWin(1,&p1Bui);
                    // checkWin(2,&p2Bui);
                    // printf("endddddd\n");
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    // printJod(&allJob);
                    jobRid(randJob, &allJob);
                    jobActFG(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods, 2);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    //測試到2
                    // printJod(&allJob);
                    // checkWin(1,&p1Bui);
                    // checkWin(2,&p2Bui);
                    // printf(BLUE);
                    // printf("Player 1:\n");
                    // printf(BLACK);
                    // sleep(1);
                    // printAllCard(&p1Pro, &p1Card);
                    // sleep(1);
                    // printBuildedCard(&p1Bui);
                    // sleep(1);
                    printAllGoods(&p1Goods);
                    sleep(1);
                    printJod(&allJob);//記得把被選的工作去掉
                    printf("Please choose one(1-5): ");
                    choJob = 0;
                    scanf("%d",&choJob);
                    jobRid(choJob, &allJob);
                    jobActRG(choJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(choJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    int32_t win1 = checkWin(&p1Bui);
                    int32_t win2 = checkWin(&p2Bui);
                    if(win1 == 1 || win2 == 1){
                        int32_t p1 = calScore(&p1Bui);
                        int32_t p2 = calScore(&p2Bui);
                        int32_t who = whoWin2(p1,p2);
                        sleep(1);
                        printf(YELLOW);
                        printf("              遊戲結束 \n");
                        printf("-----------------分數---------------------\n");
                        printf("Player 1 : %d\n",calScore(&p1Bui));
                        printf("Player 2 : %d\n",calScore(&p2Bui));
                        if(who != 3){
                        printf("---------Player %d is winner---------\n",who);
                        exit(1);
                        }
                        else{
                            printf("-----------平手------------\n");
                            exit(1);
                        }
                    }
                    setJob(&allJob);
                    checkNoCard(&allProduce, &allCard);
                    printf(YELLOW);
                    printf("<此回合結束，輸入1進行下一回合>：\n");
                    int32_t next = 0;
                    scanf("%d",&next);
                    printf(BLACK);
                    governor = 2;
                }
                while(governor ==2){
                    int32_t tow1 = haveTo(&p1Bui);
                    int32_t tow2 = haveTo(&p2Bui);
                    seven(&p1Pro, &p1Card, tow1, 1);
                    seven(&p2Pro, &p2Card, tow2, 2);
                    printf("\n");
                    // sleep(1);
                    printf("------Player 2 is governor------\n");
                    // sleep(1);
                    printf("\n");                    // printf(RED);
                    // printf("Player 2:\n");
                    // printf(BLACK);
                    check = 2;
                    randJob = 0;
                    while(check == 2){
                        randJob = rand() % 5 + 1;
                        check = checkjob(randJob, &allJob);
                    }
                    jobRid(randJob, &allJob);
                    jobActFG(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    // checkWin(1,&p1Bui);
                    // checkWin(2,&p2Bui);
                    // printAllCard(&p1Pro,&p1Card);
                    // sleep(1);
                    // printBuildedCard(&p1Bui);
                    // sleep(1);
                    printAllGoods(&p1Goods);
                    sleep(1);
                    printJod(&allJob);//記得把被選的工作去掉
                    printf("Please choose one(1-5): ");
                    int32_t choJob = 0;
                    scanf("%d",&choJob);
                    jobRid(choJob, &allJob);
                    jobActRG(choJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(choJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    check = 2;
                    randJob = 0;
                    while(check == 2){
                        randJob = rand() % 5 + 1;
                        check = checkjob(randJob, &allJob);
                    }
                    jobRid(randJob, &allJob);
                    jobActFG(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    int32_t win1 = checkWin(&p1Bui);
                    int32_t win2 = checkWin(&p2Bui);
                    if(win1 == 1 || win2 == 1){
                        int32_t p1 = calScore(&p1Bui);
                        int32_t p2 = calScore(&p2Bui);
                        int32_t who = whoWin2(p1,p2);
                        sleep(1);
                        printf(YELLOW);
                        printf("              遊戲結束 \n");
                        printf("-----------------分數---------------------\n");
                        printf("Player 1 : %d\n",calScore(&p1Bui));
                        printf("Player 2 : %d\n",calScore(&p2Bui));
                        if(who != 3){
                            printf("---------Player %d is winner---------\n",who);
                            exit(1);
                        }
                        else{
                            printf("-----------平手------------\n");
                            exit(1);
                        }
                    }
                    setJob(&allJob);
                    checkNoCard(&allProduce, &allCard);
                    printf(YELLOW);
                    printf("<此回合結束，輸入1進行下一回合>：\n");
                    int32_t next = 0;
                    scanf("%d",&next);
                    printf(BLACK);
                    sleep(1);
                    governor = 1;
                }
            }
        }
        else if(people == 3){
            sjob allJob;
            sproduce allProduce;
            scard allCard;
            sgoods p1Goods;
            sgoods p2Goods;
            sgoods p3Goods;
            sproduce p1Pro;
            sproduce p2Pro;
            sproduce p3Pro;
            sbuilded p1Bui;
            sbuilded p2Bui;
            sbuilded p3Bui;
            scard p1Card;
            scard p2Card;
            scard p3Card;
            setCard(&allCard);
            setProduce(&allProduce);
            setJob(&allJob);
            setGoods(&p1Goods);
            setGoods(&p2Goods);
            setGoods(&p3Goods);
            setPlayerBuiled(&p1Bui);
            setPlayerBuiled(&p2Bui);
            setPlayerBuiled(&p3Bui);
            setPlayerPro(&p1Pro);
            setPlayerPro(&p2Pro);
            setPlayerPro(&p3Pro);
            setPlayerCard(&p1Card);
            setPlayerCard(&p2Card);
            setPlayerCard(&p3Card);
            allProduce.indigoPlant -= 3;
            printf("發牌中........\n");
            sleep(2);
            poker(&allProduce, &allCard, &p1Pro, &p1Card);
            poker(&allProduce, &allCard, &p2Pro, &p2Card);
            poker(&allProduce, &allCard, &p3Pro, &p3Card);
            int32_t governor = 1;
            int32_t randJob = 0;
            int32_t check = 2;
            while(1){
                    while(governor == 1){
                    int32_t tow1 = haveTo(&p1Bui);
                    int32_t tow2 = haveTo(&p2Bui);
                    int32_t tow3 = haveTo(&p3Bui);
                    seven(&p1Pro, &p1Card, tow1, 1);
                    seven(&p2Pro, &p2Card, tow2, 2);
                    seven(&p3Pro, &p3Card, tow3, 3);
                    printf("\n");
                    printf("------Player 1 is governor------\n");
                    printf("\n");
                    sleep(1);
                    printAllCard(&p1Pro, &p1Card);
                    sleep(1);
                    printBuildedCard(&p1Bui);
                    sleep(1);
                    printAllGoods(&p1Goods);
                    sleep(1);
                    // printf(BLUE);
                    // printf("Player 1:\n");
                    // printf(BLACK);
                    printJod(&allJob);//記得把被選的工作去掉
                    printf("Please choose one(1-5): ");
                    int32_t choJob = 0;
                    scanf("%d",&choJob);
                    jobRid(choJob, &allJob);
                    sleep(1);
                    jobActRG(choJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(choJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActFN(choJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    // checkWin(1,&p1Bui);
                    // checkWin(2,&p2Bui);
                    // printf("endddddd\n");
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    // printJod(&allJob);
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods, 2);
                    sleep(1);
                    jobActFN(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    //測試到2
                    // printJod(&allJob);
                    // checkWin(1,&p1Bui);
                    // checkWin(2,&p2Bui);
                    // printf(BLUE);
                    // printf("Player 1:\n");
                    // printf(BLACK);
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    // printJod(&allJob);
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods, 3);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    int32_t win1 = checkWin(&p1Bui);
                    int32_t win2 = checkWin(&p2Bui);
                    int32_t win3 = checkWin(&p3Bui);
                    if(win1 == 1 || win2 == 1 || win3 == 1){
                        int32_t p1 = calScore(&p1Bui);
                        int32_t p2 = calScore(&p2Bui);
                        int32_t p3 = calScore(&p3Bui);
                        int32_t who = whoWin3(p1,p2,p3);
                        sleep(1);
                        printf(YELLOW);
                        printf("              遊戲結束 \n");
                        printf("-----------------分數---------------------\n");
                        printf("Player 1 : %d\n",calScore(&p1Bui));
                        printf("Player 2 : %d\n",calScore(&p2Bui));
                        printf("Player 3 : %d\n",calScore(&p3Bui));
                        if(who != 4){
                            printf("---------Player %d is winner---------\n",who);
                            exit(1);
                        }
                        else{
                            printf("------------平手-----------\n");
                            exit(1);
                        }
                    }
                    
                    setJob(&allJob);
                    checkNoCard(&allProduce, &allCard);
                    printf(YELLOW);
                    printf("<此回合結束，輸入1進行下一回合>：\n");
                    int32_t next = 0;
                    scanf("%d",&next);
                    printf(BLACK);
                    governor = 2;
                }
                while(governor ==2){
                    int32_t tow1 = haveTo(&p1Bui);
                    int32_t tow2 = haveTo(&p2Bui);
                    int32_t tow3 = haveTo(&p3Bui);
                    seven(&p1Pro, &p1Card, tow1, 1);
                    seven(&p2Pro, &p2Card, tow2, 2);
                    seven(&p3Pro, &p3Card, tow3, 3);
                    printf("\n");
                    // sleep(1);
                    printf("------Player 2 is governor------\n");
                    // sleep(1);
                    printf("\n");                    // printf(RED);
                    // printf("Player 2:\n");
                    // printf(BLACK);
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActFN(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    // checkWin(1,&p1Bui);
                    // checkWin(2,&p2Bui);
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    // printJod(&allJob);
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods, 3);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    printAllCard(&p1Pro,&p1Card);
                    sleep(1);
                    printBuildedCard(&p1Bui);
                    sleep(1);
                    printAllGoods(&p1Goods);
                    sleep(1);
                    printJod(&allJob);//記得把被選的工作去掉
                    printf("Please choose one(1-5): ");
                    int32_t choJob = 0;
                    scanf("%d",&choJob);
                    jobRid(choJob, &allJob);
                    sleep(1);
                    jobActRG(choJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(choJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActFN(choJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    int32_t win1 = checkWin(&p1Bui);
                    int32_t win2 = checkWin(&p2Bui);
                    int32_t win3 = checkWin(&p3Bui);
                    if(win1 == 1 || win2 == 1 || win3 == 1){
                        int32_t p1 = calScore(&p1Bui);
                        int32_t p2 = calScore(&p2Bui);
                        int32_t p3 = calScore(&p3Bui);
                        int32_t who = whoWin3(p1,p2,p3);
                        sleep(1);
                        printf(YELLOW);
                        printf("              遊戲結束 \n");
                        printf("-----------------分數---------------------\n");
                        printf("Player 1 : %d\n",calScore(&p1Bui));
                        printf("Player 2 : %d\n",calScore(&p2Bui));
                        printf("Player 3 : %d\n",calScore(&p3Bui));
                        if(who != 4){
                            printf("---------Player %d is winner---------\n",who);
                            exit(1);
                        }
                        else{
                            printf("------------平手-----------\n");
                            exit(1);
                        }
                    }
                    setJob(&allJob);
                    checkNoCard(&allProduce, &allCard);
                    printf(YELLOW);
                    printf("<此回合結束，輸入1進行下一回合>：\n");
                    int32_t next = 0;
                    scanf("%d",&next);
                    printf(BLACK);
                    sleep(1);
                    governor = 3;
                }
                while(governor == 3){
                    int32_t tow1 = haveTo(&p1Bui);
                    int32_t tow2 = haveTo(&p2Bui);
                    int32_t tow3 = haveTo(&p3Bui);
                    seven(&p1Pro, &p1Card, tow1, 1);
                    seven(&p2Pro, &p2Card, tow2, 2);
                    seven(&p3Pro, &p3Card, tow3, 3);
                    printf("\n");
                    // sleep(1);
                    printf("------Player 3 is governor------\n");
                    // sleep(1);
                    printf("\n");
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    // printJod(&allJob);
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods, 3);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    printAllCard(&p1Pro,&p1Card);
                    sleep(1);
                    printBuildedCard(&p1Bui);
                    sleep(1);
                    printAllGoods(&p1Goods);
                    sleep(1);
                    printJod(&allJob);//記得把被選的工作去掉
                    printf("Please choose one(1-5): ");
                    int32_t choJob = 0;
                    scanf("%d",&choJob);
                    jobRid(choJob, &allJob);
                    sleep(1);
                    jobActRG(choJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(choJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActFN(choJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActFN(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    int32_t win1 = checkWin(&p1Bui);
                    int32_t win2 = checkWin(&p2Bui);
                    int32_t win3 = checkWin(&p3Bui);
                    if(win1 == 1 || win2 == 1 || win3 == 1){
                        int32_t p1 = calScore(&p1Bui);
                        int32_t p2 = calScore(&p2Bui);
                        int32_t p3 = calScore(&p3Bui);
                        int32_t who = whoWin3(p1,p2,p3);
                        sleep(1);
                        printf(YELLOW);
                        printf("              遊戲結束 \n");
                        printf("-----------------分數---------------------\n");
                        printf("Player 1 : %d\n",calScore(&p1Bui));
                        printf("Player 2 : %d\n",calScore(&p2Bui));
                        printf("Player 3 : %d\n",calScore(&p3Bui));
                        if(who != 4){
                            printf("---------Player %d is winner---------\n",who);
                            exit(1);
                        }
                        else{
                            printf("------------平手-----------\n");
                            exit(1);
                        }
                    }
                    setJob(&allJob);
                    checkNoCard(&allProduce, &allCard);
                    printf(YELLOW);
                    printf("<此回合結束，輸入1進行下一回合>：\n");
                    int32_t next = 0;
                    scanf("%d",&next);
                    printf(BLACK);
                    sleep(1);
                    governor = 1;
                }
            }
        }
        else if(people == 4){
            sjob allJob;
            sproduce allProduce;
            scard allCard;
            sgoods p1Goods;
            sgoods p2Goods;
            sgoods p3Goods;
            sgoods p4Goods;
            sproduce p1Pro;
            sproduce p2Pro;
            sproduce p3Pro;
            sproduce p4Pro;
            sbuilded p1Bui;
            sbuilded p2Bui;
            sbuilded p3Bui;
            sbuilded p4Bui;
            scard p1Card;
            scard p2Card;
            scard p3Card;
            scard p4Card;
            setCard(&allCard);
            setProduce(&allProduce);
            setJob(&allJob);
            setGoods(&p1Goods);
            setGoods(&p2Goods);
            setGoods(&p3Goods);
            setGoods(&p4Goods);
            setPlayerBuiled(&p1Bui);
            setPlayerBuiled(&p2Bui);
            setPlayerBuiled(&p3Bui);
            setPlayerBuiled(&p4Bui);
            setPlayerPro(&p1Pro);
            setPlayerPro(&p2Pro);
            setPlayerPro(&p3Pro);
            setPlayerPro(&p4Pro);
            setPlayerCard(&p1Card);
            setPlayerCard(&p2Card);
            setPlayerCard(&p3Card);
            setPlayerCard(&p4Card);
            allProduce.indigoPlant -= 4;
            printf("發牌中........\n");
            sleep(2);
            poker(&allProduce, &allCard, &p1Pro, &p1Card);
            poker(&allProduce, &allCard, &p2Pro, &p2Card);
            poker(&allProduce, &allCard, &p3Pro, &p3Card);
            poker(&allProduce, &allCard, &p4Pro, &p4Card);
            int32_t governor = 1;
            int32_t randJob = 0;
            int32_t check = 2;
            while(1){
                    while(governor == 1){
                    int32_t tow1 = haveTo(&p1Bui);
                    int32_t tow2 = haveTo(&p2Bui);
                    int32_t tow3 = haveTo(&p3Bui);
                    int32_t tow4 = haveTo(&p4Bui);
                    seven(&p1Pro, &p1Card, tow1, 1);
                    seven(&p2Pro, &p2Card, tow2, 2);
                    seven(&p3Pro, &p3Card, tow3, 3);
                    seven(&p4Pro, &p4Card, tow4, 4);
                    printf("\n");
                    printf("------Player 1 is governor------\n");
                    printf("\n");
                    sleep(1);
                    printAllCard(&p1Pro, &p1Card);
                    sleep(1);
                    printBuildedCard(&p1Bui);
                    sleep(1);
                    printAllGoods(&p1Goods);
                    sleep(1);
                    // printf(BLUE);
                    // printf("Player 1:\n");
                    // printf(BLACK);
                    printJod(&allJob);//記得把被選的工作去掉
                    printf("Please choose one(1-5): ");
                    int32_t choJob = 0;
                    scanf("%d",&choJob);
                    jobRid(choJob, &allJob);
                    sleep(1);
                    jobActRG(choJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(choJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActFN(choJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    jobActFN(choJob, &p4Pro, &p4Card, &p4Bui, &allProduce, &allCard, &p4Goods,4);
                    sleep(1);
                    // checkWin(1,&p1Bui);
                    // checkWin(2,&p2Bui);
                    // printf("endddddd\n");
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    // printJod(&allJob);
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods, 2);
                    sleep(1);
                    jobActFN(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    jobActFN(randJob, &p4Pro, &p4Card, &p4Bui, &allProduce, &allCard, &p4Goods,4);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    //測試到2
                    // printJod(&allJob);
                    // checkWin(1,&p1Bui);
                    // checkWin(2,&p2Bui);
                    // printf(BLUE);
                    // printf("Player 1:\n");
                    // printf(BLACK);
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    // printJod(&allJob);
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods, 3);
                    sleep(1);
                    jobActFN(randJob, &p4Pro, &p4Card, &p4Bui, &allProduce, &allCard, &p4Goods,4);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    // printJod(&allJob);
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p4Pro, &p4Card, &p4Bui, &allProduce, &allCard, &p4Goods,4);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActFN(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    int32_t win1 = checkWin(&p1Bui);
                    int32_t win2 = checkWin(&p2Bui);
                    int32_t win3 = checkWin(&p3Bui);
                    int32_t win4 = checkWin(&p4Bui);
                    if(win1 == 1 || win2 == 1 || win3 == 1 || win4 == 1){
                        int32_t p1 = calScore(&p1Bui);
                        int32_t p2 = calScore(&p2Bui);
                        int32_t p3 = calScore(&p3Bui);
                        int32_t p4 = calScore(&p4Bui);
                        int32_t who = whoWin4(p1,p2,p3,p4);
                        sleep(1);
                        printf(YELLOW);
                        printf("              遊戲結束 \n");
                        printf("-----------------分數---------------------\n");
                        printf("Player 1 : %d\n",calScore(&p1Bui));
                        printf("Player 2 : %d\n",calScore(&p2Bui));
                        printf("Player 3 : %d\n",calScore(&p3Bui));
                        printf("Player 4 : %d\n",calScore(&p4Bui));
                        if(who != 5){
                            printf("---------Player %d is winner---------\n",who);
                            exit(1);
                        }
                        else{
                            printf("----------平手----------\n");
                            exit(1);
                        }
                    }
                    setJob(&allJob);
                    checkNoCard(&allProduce, &allCard);
                    printf(YELLOW);
                    printf("<此回合結束，輸入1進行下一回合>：\n");
                    int32_t next = 0;
                    scanf("%d",&next);
                    printf(BLACK);
                    governor = 2;
                }
                while(governor ==2){
                    int32_t tow1 = haveTo(&p1Bui);
                    int32_t tow2 = haveTo(&p2Bui);
                    int32_t tow3 = haveTo(&p3Bui);
                    int32_t tow4 = haveTo(&p4Bui);
                    seven(&p1Pro, &p1Card, tow1, 1);
                    seven(&p2Pro, &p2Card, tow2, 2);
                    seven(&p3Pro, &p3Card, tow3, 3);
                    seven(&p4Pro, &p4Card, tow4, 4);
                    printf("\n");
                    // sleep(1);
                    printf("------Player 2 is governor------\n");
                    // sleep(1);
                    printf("\n");                    // printf(RED);
                    // printf("Player 2:\n");
                    // printf(BLACK);
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActFN(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    jobActFN(randJob, &p4Pro, &p4Card, &p4Bui, &allProduce, &allCard, &p4Goods,4);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    // checkWin(1,&p1Bui);
                    // checkWin(2,&p2Bui);
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    // printJod(&allJob);
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods, 3);
                    sleep(1);
                    jobActFN(randJob, &p4Pro, &p4Card, &p4Bui, &allProduce, &allCard, &p4Goods,4);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    // printJod(&allJob);
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p4Pro, &p4Card, &p4Bui, &allProduce, &allCard, &p4Goods, 4);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActFN(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    printAllCard(&p1Pro,&p1Card);
                    sleep(1);
                    printBuildedCard(&p1Bui);
                    sleep(1);
                    printAllGoods(&p1Goods);
                    sleep(1);
                    printJod(&allJob);//記得把被選的工作去掉
                    printf("Please choose one(1-5): ");
                    int32_t choJob = 0;
                    scanf("%d",&choJob);
                    jobRid(choJob, &allJob);
                    sleep(1);
                    jobActRG(choJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(choJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActFN(choJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    jobActFN(choJob, &p4Pro, &p4Card, &p4Bui, &allProduce, &allCard, &p4Goods,4);
                    sleep(1);
                    int32_t win1 = checkWin(&p1Bui);
                    int32_t win2 = checkWin(&p2Bui);
                    int32_t win3 = checkWin(&p3Bui);
                    int32_t win4 = checkWin(&p4Bui);
                    if(win1 == 1 || win2 == 1 || win3 == 1 || win4 == 1){
                        int32_t p1 = calScore(&p1Bui);
                        int32_t p2 = calScore(&p2Bui);
                        int32_t p3 = calScore(&p3Bui);
                        int32_t p4 = calScore(&p4Bui);
                        int32_t who = whoWin4(p1,p2,p3,p4);
                        sleep(1);
                        printf(YELLOW);
                        printf("              遊戲結束 \n");
                        printf("-----------------分數---------------------\n");
                        printf("Player 1 : %d\n",calScore(&p1Bui));
                        printf("Player 2 : %d\n",calScore(&p2Bui));
                        printf("Player 3 : %d\n",calScore(&p3Bui));
                        printf("Player 4 : %d\n",calScore(&p4Bui));
                        if(who != 5){
                            printf("---------Player %d is winner---------\n",who);
                            exit(1);
                        }
                        else{
                            printf("----------平手----------\n");
                            exit(1);
                        }
                    }
                    setJob(&allJob);
                    checkNoCard(&allProduce, &allCard);
                    printf(YELLOW);
                    printf("<此回合結束，輸入1進行下一回合>：\n");
                    int32_t next = 0;
                    scanf("%d",&next);
                    printf(BLACK);
                    sleep(1);
                    governor = 3;
                }
                while(governor == 3){
                    int32_t tow1 = haveTo(&p1Bui);
                    int32_t tow2 = haveTo(&p2Bui);
                    int32_t tow3 = haveTo(&p3Bui);
                    int32_t tow4 = haveTo(&p4Bui);
                    seven(&p1Pro, &p1Card, tow1, 1);
                    seven(&p2Pro, &p2Card, tow2, 2);
                    seven(&p3Pro, &p3Card, tow3, 3);
                    seven(&p4Pro, &p4Card, tow4, 4);
                    printf("\n");
                    // sleep(1);
                    printf("------Player 3 is governor------\n");
                    // sleep(1);
                    printf("\n");
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    // printJod(&allJob);
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods, 3);
                    sleep(1);
                    jobActFN(randJob, &p4Pro, &p4Card, &p4Bui, &allProduce, &allCard, &p4Goods,4);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    // printJod(&allJob);
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p4Pro, &p4Card, &p4Bui, &allProduce, &allCard, &p4Goods,4);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActFN(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    printAllCard(&p1Pro,&p1Card);
                    sleep(1);
                    printBuildedCard(&p1Bui);
                    sleep(1);
                    printAllGoods(&p1Goods);
                    sleep(1);
                    printJod(&allJob);//記得把被選的工作去掉
                    printf("Please choose one(1-5): ");
                    int32_t choJob = 0;
                    scanf("%d",&choJob);
                    jobRid(choJob, &allJob);
                    sleep(1);
                    jobActRG(choJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(choJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActFN(choJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    jobActFN(choJob, &p4Pro, &p4Card, &p4Bui, &allProduce, &allCard, &p4Goods,4);
                    sleep(1);
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActFN(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    jobActFN(randJob, &p4Pro, &p4Card, &p4Bui, &allProduce, &allCard, &p4Goods,4);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    int32_t win1 = checkWin(&p1Bui);
                    int32_t win2 = checkWin(&p2Bui);
                    int32_t win3 = checkWin(&p3Bui);
                    int32_t win4 = checkWin(&p4Bui);
                    if(win1 == 1 || win2 == 1 || win3 == 1 || win4 == 1){
                        int32_t p1 = calScore(&p1Bui);
                        int32_t p2 = calScore(&p2Bui);
                        int32_t p3 = calScore(&p3Bui);
                        int32_t p4 = calScore(&p4Bui);
                        int32_t who = whoWin4(p1,p2,p3,p4);
                        sleep(1);
                        printf(YELLOW);
                        printf("              遊戲結束 \n");
                        printf("-----------------分數---------------------\n");
                        printf("Player 1 : %d\n",calScore(&p1Bui));
                        printf("Player 2 : %d\n",calScore(&p2Bui));
                        printf("Player 3 : %d\n",calScore(&p3Bui));
                        printf("Player 4 : %d\n",calScore(&p4Bui));
                        if(who != 5){
                            printf("---------Player %d is winner---------\n",who);
                            exit(1);
                        }
                        else{
                            printf("----------平手----------\n");
                            exit(1);
                        }
                    }
                    setJob(&allJob);
                    checkNoCard(&allProduce, &allCard);
                    printf(YELLOW);
                    printf("<此回合結束，輸入1進行下一回合>：\n");
                    int32_t next = 0;
                    scanf("%d",&next);
                    printf(BLACK);
                    sleep(1);
                    governor = 4;
                }
                while(governor == 4){
                    int32_t tow1 = haveTo(&p1Bui);
                    int32_t tow2 = haveTo(&p2Bui);
                    int32_t tow3 = haveTo(&p3Bui);
                    int32_t tow4 = haveTo(&p4Bui);
                    seven(&p1Pro, &p1Card, tow1, 1);
                    seven(&p2Pro, &p2Card, tow2, 2);
                    seven(&p3Pro, &p3Card, tow3, 3);
                    seven(&p4Pro, &p4Card, tow4, 4);
                    printf("\n");
                    // sleep(1);
                    printf("------Player 4 is governor------\n");
                    // sleep(1);
                    printf("\n");
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActFN(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    jobActFN(randJob, &p4Pro, &p4Card, &p4Bui, &allProduce, &allCard, &p4Goods,4);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    printAllCard(&p1Pro,&p1Card);
                    sleep(1);
                    printBuildedCard(&p1Bui);
                    sleep(1);
                    printAllGoods(&p1Goods);
                    sleep(1);
                    printJod(&allJob);//記得把被選的工作去掉
                    printf("Please choose one(1-5): ");
                    int32_t choJob = 0;
                    scanf("%d",&choJob);
                    jobRid(choJob, &allJob);
                    sleep(1);
                    jobActRG(choJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(choJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActFN(choJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    jobActFN(choJob, &p4Pro, &p4Card, &p4Bui, &allProduce, &allCard, &p4Goods,4);
                    sleep(1);
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    jobActFN(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods,3);
                    sleep(1);
                    jobActFN(randJob, &p4Pro, &p4Card, &p4Bui, &allProduce, &allCard, &p4Goods,4);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    randJob = (rand() % 5) + 1;
                    check = checkjob(randJob, &allJob);
                    // printf("rand = %d , check  = %d \n",randJob,check);
                    while(check == 2){
                        // printf("into\n");
                        randJob = (rand() % 5) + 1;
                        // printf("rand = %d",randJob);
                        // sleep(2);
                        check = checkjob(randJob, &allJob);
                    }
                    // printJod(&allJob);
                    jobRid(randJob, &allJob);
                    sleep(1);
                    jobActFG(randJob, &p3Pro, &p3Card, &p3Bui, &allProduce, &allCard, &p3Goods, 3);
                    sleep(1);
                    jobActFN(randJob, &p4Pro, &p4Card, &p4Bui, &allProduce, &allCard, &p4Goods,4);
                    sleep(1);
                    jobActRN(randJob, &p1Pro, &p1Card, &p1Bui, &allProduce, &allCard, &p1Goods);
                    sleep(1);
                    jobActFN(randJob, &p2Pro, &p2Card, &p2Bui, &allProduce, &allCard, &p2Goods,2);
                    sleep(1);
                    int32_t win1 = checkWin(&p1Bui);
                    int32_t win2 = checkWin(&p2Bui);
                    int32_t win3 = checkWin(&p3Bui);
                    int32_t win4 = checkWin(&p4Bui);
                    if(win1 == 1 || win2 == 1 || win3 == 1 || win4 == 1){
                        int32_t p1 = calScore(&p1Bui);
                        int32_t p2 = calScore(&p2Bui);
                        int32_t p3 = calScore(&p3Bui);
                        int32_t p4 = calScore(&p4Bui);
                        int32_t who = whoWin4(p1,p2,p3,p4);
                        sleep(1);
                        printf(YELLOW);
                        printf("              遊戲結束 \n");
                        printf("-----------------分數---------------------\n");
                        printf("Player 1 : %d\n",calScore(&p1Bui));
                        printf("Player 2 : %d\n",calScore(&p2Bui));
                        printf("Player 3 : %d\n",calScore(&p3Bui));
                        printf("Player 4 : %d\n",calScore(&p4Bui));
                        if(who != 5){
                            printf("---------Player %d is winner---------\n",who);
                            exit(1);
                        }
                        else{
                            printf("----------平手----------\n");
                            exit(1);
                        }
                    }
                    setJob(&allJob);
                    checkNoCard(&allProduce, &allCard);
                    printf(YELLOW);
                    printf("<此回合結束，輸入1進行下一回合>：\n");
                    int32_t next = 0;
                    scanf("%d",&next);
                    printf(BLACK);
                    sleep(1);
                    governor = 1;
                }
            }
        }
        else{
            printf(BLUE);
            printf("沒有這個選項！\n");
            return 0;
        }
    
    }
}

