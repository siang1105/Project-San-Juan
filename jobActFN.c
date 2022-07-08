#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 
#include <unistd.h>
#include "sanJuan.h"

void jobActFN(int32_t job, sproduce *playerProduce, scard *playerCard, sbuilded *builded, sproduce *allProduce, scard *allCard, sgoods *playerGoods, int32_t p){
    if(job == 1){
        printf("\n");
        sleep(1);
        int32_t allPro = builded -> indigoPlant + builded -> sugarMill + builded -> tobaccoStorage + builded -> coffeeRoaster + builded -> silverSmelter;
        int32_t check = 0;
        int32_t card = 0;
        if(allPro != 0){
            while(check != 1){
                card = 1;
                if(card == 1){
                    if(builded -> indigoPlant != 0 && playerGoods -> indigoGoods != 0){
                        playerGoods -> indigoGoods += 1;
                        check = 1;
                        printf("Player %d produces on Indigo Plant\n",p);
                        break;
                    }
                }
                card = 2;
                if(card == 2){
                    if(builded -> sugarMill != 0 && playerGoods -> sugarGoods != 0){
                        playerGoods -> sugarGoods += 1;
                        check = 1;
                        printf("Player %d produces on Sugar Mill\n",p);
                        break;
                    }
                }
                card = 3;
                if(card == 3){
                    if(builded -> tobaccoStorage != 0 && playerGoods -> tobaccoGoods != 0){
                        playerGoods -> tobaccoGoods += 1;
                        check = 1;
                        printf("Player %d produces on Tobacco Storage\n",p);
                        break;
                    }
                }
                card = 4;
                if(card == 4){
                    if(builded -> coffeeRoaster != 0 && playerGoods -> coffeeGoods != 0){
                        playerGoods -> coffeeGoods += 1;
                        check = 1;
                        printf("Player %d produces on Coffee Roaster\n",p);
                        break;
                    }
                }
                card = 5;
                if(card == 5){
                    if(builded -> silverSmelter != 0){
                        playerGoods -> silverGoods += 1;
                        check = 1;
                        printf("Player %d produces on Silver Smelter\n",p);
                        break;
                    }
                }
                check = 1;
                break;
            }
        }
        else{
            printf("Player %d doesn’t produce any good\n",p);
        }
        printf("\n");
        sleep(1);
        // printBuildedProCard(builded);
        // printAllCard(playerProduce,playerCard);
    }
    else if(job == 2){
        printf("\n");
        sleep(1);
        int32_t have = playerProduce -> indigoPlant + playerProduce -> sugarMill + playerProduce -> tobaccoStorage + playerProduce -> coffeeRoaster + playerProduce -> silverSmelter + playerCard -> tower + playerCard -> chapel + playerCard -> smithy + 
        playerCard -> poorHouse + playerCard -> blackMarket + playerCard -> crane + playerCard -> carpenter + playerCard -> quarry + playerCard -> well + playerCard -> aqueduct + playerCard -> marketStand + playerCard -> marketHall + playerCard -> tradingPost + playerCard -> archive + 
        playerCard -> prefecture + playerCard -> goldMine + playerCard -> library + playerCard -> statue + playerCard -> victoryColumn + playerCard -> hero + playerCard -> guildHall + playerCard -> cityHall + playerCard -> trinmhalArch + playerCard -> palace;
        // printf("have = %d\n",have);
        // printAllCard(playerProduce,playerCard);
        int32_t check = 2;
        int32_t check02 = 2;
        int32_t card = 0;
        int32_t ok = 0;
        while(ok == 0){
            // check = 2;
            // while(check == 2){
            //     card = rand() % 29 + 1;
            //     check = checkcard(card, playerProduce, playerCard);
            // }
            card = 1;
            if(card == 1 && have > 1 && playerProduce -> indigoPlant != 0){
                builded -> indigoPlant += 1;
                subCardP(card,playerProduce, playerCard);
                int32_t paycard = 0;
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                printf("Player %d builed Indigo Plant\n",p);
                ok = 1;
                break;
            }
            card = 2;
            if(card == 2 && have > 2 && playerProduce ->  sugarMill != 0){
                builded -> sugarMill += 1;
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
                printf("Player %d builed Sugar Mill\n",p);
                ok = 1;
                break;
            }
            card = 3;
            if(card == 3 && have > 3 && playerProduce -> tobaccoStorage != 0){
                builded -> tobaccoStorage += 1;
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
                printf("Player %d builed Tobacco Storage\n",p);
                ok = 1;
                break;
            }
            card = 4;
            if(card == 4 && have > 4 && playerProduce -> coffeeRoaster != 0){
                builded-> coffeeRoaster += 1;
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
                printf("Player %d builed Coffee Rosater\n",p);
                ok = 1;
                break;
            }
            card = 5;
            if(card == 5 && have > 5 && playerProduce -> silverSmelter != 0){
                builded-> silverSmelter += 1;
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
                printf("Player %d builed Silver Smelter\n",p);
                ok = 1;
                break;
            }
            card = 6;
            if(card == 6 && have > 3 && playerCard -> tower != 0){
                builded-> tower += 1;
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
                printf("Player %d builed Tower\n",p);
                ok = 1;
                break;
            }
            card = 7;
            if(card == 7 && have > 3 && playerCard -> chapel != 0){
                builded-> chapel += 1;
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
                printf("Player %d builed Chapel\n",p);
                ok = 1;
                break;
            }
            card = 8;
            if(card == 8 && have > 1 && playerCard -> smithy != 0){
                builded -> smithy += 1;
                subCardP(card,playerProduce, playerCard);
                int32_t paycard = 0;
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                printf("Player %d builed Smithy\n",p);
                ok = 1;
                break;
            }
            card = 9;
            if(card == 9 && have > 2 && playerCard -> poorHouse != 0){
                builded -> poorHouse += 1;
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
                printf("Player %d builed Poor House\n",p);
                ok = 1;
                break;
            }
            card = 10;
            if(card == 10 && have > 2 && playerCard -> blackMarket != 0){
                builded -> blackMarket += 1;
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
                printf("Player %d builed Black Market\n",p);
                ok = 1;
                break;
            }
            card = 11;
            if(card == 11 && have > 2 && playerCard -> crane != 0){
                builded -> crane += 1;
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
                printf("Player %d builed Crane\n",p);
                ok = 1;
                break;
            }
            card = 12;
            if(card == 12 && have > 3 && playerCard -> carpenter != 0){
                builded-> carpenter += 1;
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
                printf("Player %d builed Carpenter\n",p);
                ok = 1;
                break;
            }
            card = 13;
            if(card == 13 && have > 4 && playerCard -> quarry != 0){
                builded-> quarry += 1;
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
                printf("Player %d builed Quarry\n",p);
                ok = 1;
                break;
            }
            card = 14;
            if(card == 14 && have > 2 && playerCard -> well != 0){
                builded -> well += 1;
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
                printf("Player %d builed Well\n",p);
                ok = 1;
                break;
            }
            card = 15;
            if(card == 15 && have > 3 && playerCard -> aqueduct !=0){
                builded-> aqueduct += 1;
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
                printf("Player %d builed Aqueduct\n",p);
                ok = 1;
                break;
            }
            card = 16;
            if(card == 16 && have > 2 && playerCard -> marketStand != 0){
                builded -> marketStand += 1;
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
                printf("Player %d builed Market Stand\n",p);
                ok = 1;
                break;
            }
            card = 17;
            if(card == 17 && have > 4 && playerCard -> marketHall != 0){
                builded-> marketHall += 1;
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
                printf("Player %d builed Market Hall\n",p);
                ok = 1;
                break;
            }
            card = 18;
            if(card == 18 && have > 2 && playerCard -> tradingPost != 0){
                builded -> tradingPost += 1;
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
                printf("Player %d builed Trading Post\n",p);
                ok = 1;
                break;
            }
            card = 19;
            if(card == 19 && have > 1 && playerCard -> archive != 0){
                builded -> archive += 1;
                subCardP(card,playerProduce, playerCard);
                int32_t paycard = 0;
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                printf("Player %d builed Archive\n",p);
                ok = 1;
                break;
            }
            card = 20;
            if(card == 20 && have > 3 && playerCard -> prefecture != 0){
                builded-> prefecture += 1;
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
                printf("Player %d builed Prefecture\n",p);
                ok = 1;
                break;
            }
            card = 21;
            if(card == 21 && have > 1 && playerCard -> goldMine != 0){
                builded -> goldMine += 1;
                subCardP(card,playerProduce, playerCard);
                int32_t paycard = 0;
                while(check02 == 2){
                paycard = rand() % 29 + 1;
                check02 = checkcard(paycard, playerProduce, playerCard);
                }
                paymoney(paycard, playerProduce, playerCard);
                printf("Player %d builed Gold Mine\n",p);
                ok = 1;
                break;
            }
            card = 22;
            if(card == 22 && have > 5 && playerCard -> library != 0){
                builded-> library += 1;
                subCardP(card,playerProduce, playerCard);
                int32_t paycard = 0;
                int32_t count = 5;
                while(count--){
                    while(check02 == 2){
                    paycard = rand() % 29 + 1;
                    check02 = checkcard(paycard, playerProduce, playerCard);//我要死了
                    }
                    paymoney(paycard, playerProduce, playerCard);
                    check02 = 2;
                }
                printf("Player %d builed Library\n",p);
                ok = 1;
                break;
            }
            card = 23;
            if(card == 23 && have > 3 && playerCard -> statue != 0){
                builded-> statue += 1;
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
                printf("Player %d builed Statue\n",p);
                ok = 1;
                break;
            }
            card = 24;
            if(card == 24 && have > 4 && playerCard -> victoryColumn != 0){
                builded-> victoryColumn += 1;
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
                printf("Player %d builed Victory Column\n",p);
                ok = 1;
                break;
            }
            card = 25;
            if(card == 25 && have > 5 && playerCard -> hero != 0){
                builded-> hero += 1;
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
                printf("Player %d builed Hero\n",p);
                ok = 1;
                break;
            }
            card = 26;
            if(card == 26 && have > 6 && playerCard -> guildHall != 0){
                builded-> guildHall += 1;
                subCardP(card,playerProduce, playerCard);
                int32_t paycard = 0;
                int32_t count = 6;
                while(count--){
                    while(check02 == 2){
                    paycard = rand() % 29 + 1;
                    check02 = checkcard(paycard, playerProduce, playerCard);
                    }
                    paymoney(paycard, playerProduce, playerCard);
                    check02 = 2;
                }
                printf("Player %d builed Guild Hall\n",p);
                ok = 1;
                break;
            }
            card = 27;
            if(card == 27 && have > 6 && playerCard -> cityHall != 0){
                builded-> cityHall += 1;
                subCardP(card,playerProduce, playerCard);
                int32_t paycard = 0;
                int32_t count = 6;
                while(count--){
                    while(check02 == 2){
                    paycard = rand() % 29 + 1;
                    check02 = checkcard(paycard, playerProduce, playerCard);
                    }
                    paymoney(paycard, playerProduce, playerCard);
                    check02 = 2;
                }
                printf("Player %d builed City Hall\n",p);
                ok = 1;
                break;
            }
            card = 28;
            if(card == 28 && have > 6 && playerCard -> trinmhalArch != 0){
                builded-> trinmhalArch += 1;
                subCardP(card,playerProduce, playerCard);
                int32_t paycard = 0;
                int32_t count = 6;
                while(count--){
                    while(check02 == 2){
                    paycard = rand() % 29 + 1;
                    check02 = checkcard(paycard, playerProduce, playerCard);
                    }
                    paymoney(paycard, playerProduce, playerCard);
                    check02 = 2;
                }
                printf("Player %d builed Trinmhal Arch\n",p);
                ok = 1;
                break;
            }
            card = 29;
            if(card == 29 && have > 6 && playerCard -> palace != 0){
                builded-> palace += 1;
                subCardP(card,playerProduce, playerCard);
                int32_t paycard = 0;
                int32_t count = 6;
                while(count--){
                    while(check02 == 2){
                    paycard = rand() % 29 + 1;
                    check02 = checkcard(paycard, playerProduce, playerCard);
                    }
                    paymoney(paycard, playerProduce, playerCard);
                    check02 = 2;
                }
                printf("Player %d builed Palace\n",p);
                ok = 1;
                break;
            }
            printf("Player %d doesn’t build any building\n",p);
            ok = 1;
            break;
        }

        printf("\n");
        sleep(1);
        // printf("******\n");
        // printAllCard(playerProduce,playerCard);
    }
    else if(job == 4){
        printf("\n");
        sleep(1);
        int32_t randMoney = rand() % 5 + 1;
        int32_t *price = Fmoney(randMoney);
        int32_t allGoods = playerGoods -> indigoGoods + playerGoods -> sugarGoods + playerGoods -> tobaccoGoods + playerGoods -> coffeeGoods + playerGoods -> silverGoods;
        int32_t winPrice = 0;
        int32_t check = 2;
        int32_t card = 0;
        if(allGoods != 0){
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
            printf("Player %d doesn’t sell any good\n",p);
        }
        sleep(1);
        printf("\n");
    }
    else if(job == 5){
        sleep(1);
        printf("\n");
        int32_t randNum = rand() % 29 + 1;
        int32_t check = checkcard(randNum, allProduce, allCard);
        while(check != 1){
            randNum = rand() % 29 + 1;
            check = checkcard(randNum, allProduce, allCard);
        }
        if(check == 1){
            addcard(randNum, playerProduce, playerCard, allProduce, allCard);
        }
        printf("Player %d can get a random card\n",p);
        printf("\n");
        sleep(1);
        //牌庫要減掉，確認牌庫有排才可以發牌
        // printAllCard(&playerProduce, &playerCard);
    }
    
}