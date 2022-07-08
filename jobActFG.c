#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 
#include <unistd.h>
#include "sanJuan.h"


void jobActFG(int32_t job, sproduce *playerProduce, scard *playerCard, sbuilded *builded, sproduce *allProduce, scard *allCard, sgoods *playerGoods, int32_t p){
    if(job == 1){
        sleep(1);
        printf(YELLOW);
        printf("Player %d 選擇的是生產者(producer)\n",p);
        printf(BLACK);
        sleep(1);
        printf("\n");
        int32_t allPro = builded -> indigoPlant + builded -> sugarMill + builded -> tobaccoStorage + builded -> coffeeRoaster + builded -> silverSmelter;
        int32_t check = 0;
        int32_t card = 0;
        if(allPro != 0){
            if(allPro == 1){
                while(check == 0){
                        card = 1;
                        if(card == 1 && playerGoods -> indigoGoods == 0){
                            if(builded -> indigoPlant != 0){
                                playerGoods -> indigoGoods += 1;
                                subCard(allProduce,allCard);
                                printf("Player %d produces on Indigo Plant\n",p);
                                check = 1;
                                break;
                            }
                        }
                        card = 2;
                        if(card == 2 && playerGoods -> sugarGoods == 0){
                            if(builded -> sugarMill != 0){
                                playerGoods -> sugarGoods += 1;
                                subCard(allProduce,allCard);
                                check = 1;
                                printf("Player %d produces on Sugar Mill\n",p);
                                break;
                            }
                        }
                        card = 3;
                        if(card == 3 && playerGoods -> tobaccoGoods == 0){
                            if(builded -> tobaccoStorage != 0){
                                playerGoods -> tobaccoGoods += 1;
                                subCard(allProduce,allCard);
                                check = 1;
                                printf("Player %d produces on Tobacco Storage\n",p);
                                break;
                            }
                        }
                        card = 4;
                        if(card == 4 && playerGoods -> coffeeGoods == 0){
                            if(builded -> coffeeRoaster != 0){
                                playerGoods -> coffeeGoods += 1;
                                subCard(allProduce,allCard);
                                check = 1;
                                printf("Player %d produces on Coffee Roaster\n",p);
                                break;
                            }
                        }
                        card = 5;
                        if(card == 5 && playerGoods -> silverGoods == 0){
                            if(builded -> silverSmelter != 0){
                                playerGoods -> silverGoods += 1;
                                subCard(allProduce,allCard);
                                check = 1;
                                printf("Player %d produces on Silver Smelter\n",p);
                                break;
                            }
                        }
                        printf("Player %d doesn’t produce any good\n",p);
                        check = 1;
                    }
            }
            else{
                int32_t count = 2;
                check = 0;
                while(count--){
                    while(check != 1){
                        card = 1;
                        if(card == 1){
                            if(builded -> indigoPlant != 0){
                                if(playerGoods -> indigoGoods == 0){
                                    playerGoods -> indigoGoods += 1;
                                    subCard(allProduce,allCard);
                                    check = 1;
                                    printf("Player %d produces on Indigo Plant\n",p);
                                    break;
                                }
                            }
                        }
                        card = 2;
                        if(card == 2){
                            if(builded -> sugarMill != 0){
                                if(playerGoods -> sugarGoods == 0){
                                    playerGoods -> sugarGoods += 1;
                                    subCard(allProduce,allCard);
                                    check = 1;
                                    printf("Player %d produces on Sugar Mill\n",p);
                                    break;
                                }
                            }
                        }
                        card = 3;
                        if(card == 3){
                            if(builded -> tobaccoStorage != 0){
                                if(playerGoods -> tobaccoGoods == 0){
                                    playerGoods -> tobaccoGoods += 1;
                                    subCard(allProduce,allCard);
                                    check = 1;
                                    printf("Player %d produces on Tobacco Storage\n",p);
                                    break;
                                }
                            }
                        }
                        card = 4;
                        if(card == 4){
                            if(builded -> coffeeRoaster != 0){
                                if(playerGoods -> coffeeGoods == 0){
                                    playerGoods -> coffeeGoods += 1;
                                    subCard(allProduce,allCard);
                                    check = 1;
                                    printf("Player %d produces on Coffee Roaster\n",p);
                                    break;
                                }
                            }
                        }
                        card = 5;
                        if(card == 5){
                            if(builded -> silverSmelter != 0){
                                if(playerGoods -> silverGoods == 0){
                                    playerGoods -> silverGoods += 1;
                                    subCard(allProduce,allCard);
                                    check = 1;
                                    printf("Player %d produces on Silver Smelter\n",p);
                                    break;
                                }
                            }
                        }
                        check = 1;
                    }
                }
            }
        }
        else{
            printf("Player %d doesn’t produce any good\n",p);
        }
        printf("\n");
        sleep(1);
    }
    else if(job == 2){
        sleep(1);
        printf(YELLOW);
        printf("Player %d 選擇的是建築師(builder)\n",p);
        printf(BLACK);
        sleep(1);
        printf("\n");
        // printAllCard(playerProduce, playerCard);
        int32_t check = 2;
        int32_t check02 = 2;
        int32_t card = 0;
        while(check == 2){
            card = rand() % 29 + 1;
            check = checkcard(card, playerProduce, playerCard);
        }
        int32_t have = playerProduce -> indigoPlant + playerProduce -> sugarMill + playerProduce -> tobaccoStorage + playerProduce -> coffeeRoaster + playerProduce -> silverSmelter + playerCard -> tower + playerCard -> chapel + playerCard -> smithy + 
        playerCard -> poorHouse + playerCard -> blackMarket + playerCard -> crane + playerCard -> carpenter + playerCard -> quarry + playerCard -> well + playerCard -> aqueduct + playerCard -> marketStand + playerCard -> marketHall + playerCard -> tradingPost + playerCard -> archive + 
        playerCard -> prefecture + playerCard -> goldMine + playerCard -> library + playerCard -> statue + playerCard -> victoryColumn + playerCard -> hero + playerCard -> guildHall + playerCard -> cityHall + playerCard -> trinmhalArch + playerCard -> palace;
        // printf("card = %d have = %d \n",card,have);
        if(card == 1){
            builded -> indigoPlant += 1;
            subCardP(card,playerProduce, playerCard);
            printf("Player %d builed Indigo Plant\n",p);
        }
        else if(card == 2 && have > 1){
            builded -> sugarMill += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 1;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Sugar Mill\n",p);
        }
        else if(card == 3 && have > 2){
            builded -> tobaccoStorage += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 2;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Tobacco Storage\n",p);
            
        }
        else if(card == 4 && have > 3){
            builded-> coffeeRoaster += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 3;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Coffee Rosater\n",p);
        }
        else if(card == 5 && have > 4){
            builded-> silverSmelter += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 4;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Silver Smelter\n",p);
        }
        else if(card == 6 && have > 2){
            builded-> tower += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 2;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Tower\n",p);
        }
        else if(card == 7 && have > 2){
            builded-> chapel += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 2;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Chapel\n",p);
        }
        else if(card == 8){
            builded -> smithy += 1;
            subCardP(card,playerProduce, playerCard);
            printf("Player %d builed Smithy\n",p);
        }
        else if(card == 9 && have > 1){
            builded -> poorHouse += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 1;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Poor House\n",p);
        }
        else if(card == 10 && have > 1){
            builded -> blackMarket += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 1;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Black Market\n",p);
        }
        else if(card == 11 && have > 1){
            builded -> crane += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 1;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Crane\n",p);
        }
        else if(card == 12 && have > 2){
            builded-> carpenter += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 2;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Carpenter\n",p);
        }
        else if(card == 13 && have > 3){
            builded-> quarry += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 3;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Quarry\n",p);
        }
        else if(card == 14 && have > 1){
            builded -> well += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 1;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Well\n",p);
        }
        else if(card == 15 && have > 2){
            builded-> aqueduct += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 2;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Aqueduct\n",p);
        }
        else if(card == 16 && have > 1){
            builded -> marketStand += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 1;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Market Stand\n",p);
        }
        else if(card == 17 && have > 3){
            builded-> marketHall += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 3;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Market Hall\n",p);
        }
        else if(card == 18 && have > 1){
            builded -> tradingPost += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 1;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Trading Post\n",p);
        }
        else if(card == 19){
            builded -> archive += 1;
            subCardP(card,playerProduce, playerCard);
            printf("Player %d builed Archive\n",p);
        }
        else if(card == 20 && have > 2){
            builded-> prefecture += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 2;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Prefecture\n",p);
        }
        else if(card == 21){
            builded -> goldMine += 1;
            subCardP(card,playerProduce, playerCard);
            printf("Player %d builed Gold Mine\n",p);
        }
        else if(card == 22 && have > 4){
            builded-> library += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 4;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Library\n",p);
        }
        else if(card == 23 && have > 2){
            builded-> statue += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 2;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Statue\n",p);
        }
        else if(card == 24 && have > 3){
            builded-> victoryColumn += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 3;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Victory Column\n",p);
        }
        else if(card == 25 && have > 4){
            builded-> hero += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 4;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Hero\n",p);
        }
        else if(card == 26 && have > 5){
            builded-> guildHall += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 5;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Guild Hall\n",p);
        }
        else if(card == 27 && have > 5){
            builded-> cityHall += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 5;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed City Hall\n",p);
        }
        else if(card == 28 && have > 5){
            builded-> trinmhalArch += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 5;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Trinmhal Arch\n",p);
        }
        else if(card == 29 && have > 5){
            builded-> palace += 1;
            subCardP(card,playerProduce, playerCard);
            int32_t paycard = 0;
            int32_t count = 5;
            while(count--){
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                check02 = 2;
            }
            printf("Player %d builed Palace\n",p);
        }
        else{
            printf("Player %d doesn’t build any building\n",p);
        }
        printf("\n");
        sleep(1);
    }
    else if(job == 3){
        sleep(1);
        printf(YELLOW);
        printf("Player %d 選擇的是礦工(prospector)\n",p);
        printf(BLACK);
        sleep(1);
        printf("\n");
        printf("Player %d can get a random card\n",p);
        int32_t randNum = rand() % 29 + 1;
        int32_t check = checkcard(randNum, allProduce, allCard);
        while(check != 1){
            randNum = rand() % 29 + 1;
            check = checkcard(randNum, allProduce, allCard);
        }
        if(check == 1){
            addcard(randNum, playerProduce, playerCard, allProduce, allCard);
        }
        printf("\n");
        sleep(1);
        // printAllCard(playerProduce,playerCard);
    }
    else if(job == 4){
        sleep(1);
        printf(YELLOW);
        printf("Player %d 選擇的是商人(trader)\n",p);
        printf(BLACK);
        sleep(1);
        printf("\n");
        int32_t randMoney = rand() % 5 + 1;
        // printf("%d\n",randMoney);
        int32_t *price = Fmoney(randMoney);
        int32_t allGoods = playerGoods -> indigoGoods + playerGoods -> sugarGoods + playerGoods -> tobaccoGoods + playerGoods -> coffeeGoods + playerGoods -> silverGoods;
        int32_t winPrice = 0;
        int32_t check = 2;
        int32_t card = 0;
        if(allGoods != 0){
            if(allGoods == 1){
                while(check == 2){
                    card = rand() % 5 + 1;
                    check = checkgoods(card, playerGoods);
                }
                if(card == 1){
                    playerGoods -> indigoGoods -= 1;
                    sellAndWinCard (card, *(price + (card-1)), allProduce, allCard, playerProduce, playerCard);
                    printf("Player %d sells Indigo Plant Good\n",p);
                }
                if(card == 2){
                    playerGoods -> sugarGoods -= 1;
                    sellAndWinCard (card, *(price + (card-1)), allProduce, allCard, playerProduce, playerCard);
                    printf("Player %d sells Sugar Mill Good\n",p);
                }
                if(card == 3){
                    playerGoods -> tobaccoGoods -= 1;
                    sellAndWinCard (card, *(price + (card-1)), allProduce, allCard, playerProduce, playerCard);
                    printf("Player %d sells Tobacco Storage Good\n",p);
                }
                if(card == 4){
                    playerGoods -> coffeeGoods -= 1;
                    sellAndWinCard (card, *(price + (card-1)), allProduce, allCard, playerProduce, playerCard);
                    printf("Player %d sells Coffee Roaster Good\n",p);
                }
                if(card == 5){
                    playerGoods -> silverGoods -= 1;
                    sellAndWinCard (card, *(price + (card-1)), allProduce, allCard, playerProduce, playerCard);
                    printf("Player %d sells Silver Smelter Good\n",p);
                }
            }   
            else{
                check = 2;
                int32_t count = 2;
                while(count--){
                    while(check == 2){
                        card = rand() % 5 + 1;
                        check = checkgoods(card, playerGoods);
                    }
                    if(card == 1){
                        if(playerGoods -> indigoGoods != 0){
                            playerGoods -> indigoGoods -= 1;
                            sellAndWinCard (card, *(price + (card-1)), allProduce, allCard, playerProduce, playerCard);
                            printf("Player %d sells Indigo Plant Good\n",p);
                        }
                    }
                    if(card == 2){
                        if(playerGoods -> sugarGoods != 0){
                            playerGoods -> sugarGoods -= 1;
                            sellAndWinCard (card, *(price + (card-1)), allProduce, allCard, playerProduce, playerCard);
                            printf("Player %d sells Sugar Mill Good\n",p);
                        }
                    }
                    if(card == 3){
                        if(playerGoods -> tobaccoGoods != 0){
                            playerGoods -> tobaccoGoods -= 1;
                            sellAndWinCard (card, *(price + (card-1)), allProduce, allCard, playerProduce, playerCard);
                            printf("Player %d sells Tobacco Storage Good\n",p);
                        }
                    }
                    if(card == 4){
                        if(playerGoods -> coffeeGoods != 0){
                            playerGoods -> coffeeGoods -= 1;
                            sellAndWinCard (card, *(price + (card-1)), allProduce, allCard, playerProduce, playerCard);
                            printf("Player %d sells Coffee Roaster Good\n",p);
                        }
                    }
                    if(card == 5){
                        if(playerGoods -> silverGoods){
                            playerGoods -> silverGoods -= 1;
                            sellAndWinCard (card, *(price + (card-1)), allProduce, allCard, playerProduce, playerCard);
                            printf("Player %d sells Silver Smelter Good\n",p);
                        }
                    }
                }
            }
        }
        else{
            printf("Player %d doesn’t sell any goods\n",p);
        }
        printf("\n");
        sleep(1);
        // printAllCard(playerProduce,playerCard);

    }
    else if(job == 5){
        sleep(1);
        printf(YELLOW);
        printf("Player %d 選擇的是議員(councillor)\n",p);
        sleep(1);
        printf(BLACK);
        printf("\n");
        printf("Player %d can get a random card\n",p);
        int32_t randNum = rand() % 29 + 1;
        int32_t check = checkcard(randNum, allProduce, allCard);
        while(check != 1){
            randNum = rand() % 29 + 1;
            check = checkcard(randNum, allProduce, allCard);
        }
        if(check == 1){
            addcard(randNum, playerProduce, playerCard, allProduce, allCard);
        }
        sleep(1);
        printf("\n");
    }
    // printAllCard(playerProduce,playerCard);
}