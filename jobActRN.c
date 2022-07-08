#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 
#include <unistd.h>
#include "sanJuan.h"

void jobActRN(int32_t job, sproduce *playerProduce, scard *playerCard, sbuilded *builded, sproduce *allProduce, scard *allCard, sgoods *playerGoods){
    if(job == 1){
        int32_t aqu = haveAqu(builded);
        int32_t wel = haveWel(builded);
        sleep(1);
        printf("你可以選擇一棟生產建築來生產貨物，一棟生產建築只能生產一份貨物\n");
        sleep(1);
        printBuildedProCard(builded,playerGoods);
        sleep(1);
        int32_t allPro = builded -> indigoPlant + builded -> sugarMill + builded -> tobaccoStorage + builded -> coffeeRoaster + builded -> silverSmelter;
        if(allPro != 0){
            if(allPro > 1 && aqu == 1){
                int32_t count = 2;
                printf("因為你有溝渠(Aqueduct)，所以可以多生產一樣貨物(2樣)\n");
                sleep(1);
                printf("注意：一張一張選，每種建築物只能生產一項貨物\n");
                while(count--){
                    printf("輸入卡號<1-5>: ");
                    int32_t card = 0;
                    scanf("%d", &card);
                    if(card == 1){
                        playerGoods -> indigoGoods += 1;
                        subCard(allProduce,allCard);
                    }
                    if(card == 2){
                        playerGoods -> sugarGoods += 1;
                        subCard(allProduce,allCard);
                    }
                    if(card == 3){
                        playerGoods -> tobaccoGoods += 1;
                        subCard(allProduce,allCard);
                    }
                    if(card == 4){
                        playerGoods -> coffeeGoods += 1;
                        subCard(allProduce,allCard);
                    }
                    if(card == 5){
                        playerGoods -> silverGoods += 1;
                        subCard(allProduce,allCard);
                    }
                }
                if(wel == 1){
                    sleep(1);
                    int32_t check2 = 2;
                    printf("因為你有水井(Well),所以生產兩個貨物以上可額外獲得一張隨機卡牌\n");
                    sleep(1);
                    while(check2 == 2){
                        int32_t randNum = rand() % 29 + 1;
                        int32_t check2 = checkcard(randNum, allProduce, allCard);
                        if(check2 == 1){
                            addcard(randNum, playerProduce, playerCard, allProduce, allCard);
                            break;
                        }
                    }
                }
            }
            else{
                printf("輸入卡號<1-5> 若不生產請輸入0: ");
                int32_t card;
                scanf("%d",&card);
                if(card == 1){
                    playerGoods -> indigoGoods += 1;
                }
                if(card == 2){
                    playerGoods -> sugarGoods += 1;
                }
                if(card == 3){
                    playerGoods -> tobaccoGoods += 1;
                }
                if(card == 4){
                    playerGoods -> coffeeGoods += 1;
                }
                if(card == 5){
                    playerGoods -> silverGoods += 1;
                }
            }
        }
        else{
            printf("你沒有生產建築/生產建築上已經有貨物了，因此無法生產貨物\n");
        }
        sleep(1);
        printAllCard(playerProduce,playerCard);
        sleep(1);
        printBuildedCard(builded);
        sleep(1);
        printAllGoods(playerGoods);
        sleep(1);
    }
    else if(job == 2){
        // printf("Player 2 chooses builder\n");
        sleep(1);
        printf("選擇一棟建築來建造, 所需支付的手牌為括號內的數字 \n");
        printf("注意 卡號<6-29>每一種建築只能建造一棟，若不建造請輸入0\n");
        sleep(1);
        printAllCard(playerProduce, playerCard);
        sleep(1);
        printBuildedCard(builded);
        int32_t smi = haveSmi(builded);
        int32_t qua = haveQua(builded);
        int32_t card = 0;
        printf("卡號<1-29>: ");
        scanf("%d",&card);
        if(card == 1){
            if(smi == 1){
                printf("因為你有鐵匠鋪(Smithy)，所以建造生產建築時可以少支付一張手牌\n");
                sleep(1);
                builded -> indigoPlant += 1;//這張也要減掉？
                subCardP(card,playerProduce, playerCard);
                printf("You don’t need to pay\n");
            }
            else{
                builded -> indigoPlant += 1;//這張也要減掉？
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 1 card\n");
                printf("卡號<1-29>: ");
                int32_t paycard;
                scanf("%d",&paycard);
                paymoney(paycard, playerProduce, playerCard);
            }
        }
        if(card == 2){
            if(smi == 1){
                printf("因為你有鐵匠鋪(Smithy)，所以建造生產建築時可以少支付一張手牌\n");
                sleep(1);
                builded -> sugarMill += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 1 card\n");
                printf("注意：一次只能選一張\n");
                printf("卡號<1-29>: ");
                int32_t paycard = 0;
                scanf("%d", &paycard);
                paymoney(paycard, playerProduce, playerCard);
            }
            else{
                builded -> sugarMill += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 2 card\n");
                printf("注意：一次只能選一張\n");
                printf("卡號<1-29>: ");
                int32_t paycard = 0;
                scanf("%d", &paycard);
                paymoney(paycard, playerProduce, playerCard);
                paycard = 0;
                printf("卡號<1-29>: ");
                scanf("%d",&paycard);
                paymoney(paycard, playerProduce, playerCard);
            }
            
        }
        if(card == 3){
            if(smi == 1){
                printf("因為你有鐵匠鋪(Smithy)，所以建造生產建築時可以少支付一張手牌\n");
                sleep(1);
                builded -> tobaccoStorage += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 2 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 2;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded -> tobaccoStorage += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 3 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 3;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            
        }
        if(card == 4){
            if(smi == 1){
                printf("因為你有鐵匠鋪(Smithy)，所以建造生產建築時可以少支付一張手牌\n");
                sleep(1);
                builded-> coffeeRoaster += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 3 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 3;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded-> coffeeRoaster += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 4 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 4;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
        }
        if(card == 5){
            if(smi == 1){
                printf("因為你有鐵匠鋪(Smithy)，所以建造生產建築時可以少支付一張手牌\n");
                sleep(1);
                builded-> silverSmelter += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 4 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 4;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded-> silverSmelter += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 5 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 5;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
        }
        if(card == 6){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded-> tower += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 2 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 2;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded-> tower += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 3 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 3;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            } 
        }
        if(card == 7){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded-> chapel += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 2 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 2;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded-> chapel += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 3 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 3;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            } 
        }
        if(card == 8){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded -> smithy += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You don’t need to pay\n");
            }
            else{
                builded -> smithy += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 1 card\n");
                printf("卡號<1-29>: ");
                int32_t paycard;
                scanf("%d",&paycard);
                paymoney(paycard, playerProduce, playerCard);
            } 
        }
        if(card == 9){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded -> poorHouse += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 1 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 1;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded -> poorHouse += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 2 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 2;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }  
        }
        if(card == 10){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded -> blackMarket += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 1 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 1;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded -> blackMarket += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 2 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 2;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
        }
        if(card == 11){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded -> crane += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 1 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 1;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded -> crane += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 2 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 2;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
        }
        if(card == 12){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded-> carpenter += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 2 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 2;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded-> carpenter += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 3 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 3;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
        }
        if(card == 13){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded-> quarry += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 3 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 3;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded-> quarry += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 4 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 4;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
        }
        if(card == 14){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded -> well += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 1 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 1;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded -> well += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 2 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 2;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }  
        }
        if(card == 15){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded-> aqueduct += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 2 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 2;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded-> aqueduct += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 3 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 3;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }   
        }
        if(card == 16){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded -> marketStand += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 1 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 1;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded -> marketStand += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 2 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 2;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
        }
        if(card == 17){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded-> marketHall += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 3 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 3;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded-> marketHall += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 4 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 4;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
        }
        if(card == 18){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded -> tradingPost += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 1 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 1;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded -> tradingPost += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 2 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 2;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
        }
        if(card == 19){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded -> archive += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You don’t need to pay\n");
            }
            else{
                builded -> archive += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 1 card\n");
                printf("卡號<1-29>: ");
                int32_t paycard;
                scanf("%d",&paycard);
                paymoney(paycard, playerProduce, playerCard);
            }
        }
        if(card == 20){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded-> prefecture += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 2 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 2;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded-> prefecture += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 3 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 3;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
        }
        if(card == 21){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded -> goldMine += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You don’t need to pay\n");
            }
            else{
                builded -> goldMine += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 1 card\n");
                printf("卡號<1-29>: ");
                int32_t paycard;
                scanf("%d",&paycard);
                paymoney(paycard, playerProduce, playerCard);
            } 
        }
        if(card == 22){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded-> library += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 4 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 4;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded-> library += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 5 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 5;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            } 
        }
        if(card == 23){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded-> statue += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 2 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 2;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded-> statue += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 3 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 3;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            } 
        }
        if(card == 24){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded-> victoryColumn += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 3 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 3;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded-> victoryColumn += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 4 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 4;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
        }
        if(card == 25){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded-> hero += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 4 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 4;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded-> hero += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 5 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 5;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
        }
        if(card == 26){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded-> guildHall += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 5 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 5;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded-> guildHall += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 6 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 6;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }  
        }
        if(card == 27){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded-> cityHall += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 5 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 5;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded-> cityHall += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 6 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 6;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }    
        }
        if(card == 28){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded-> trinmhalArch += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 5 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 5;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded-> trinmhalArch += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 6 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 6;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            
        }
        if(card == 29){
            if(qua == 1){
                printf("因為你有採石場(Quarry)，所以建造特殊建築時可以少支付一張手牌\n");
                sleep(1);
                builded-> palace += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 5 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 5;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
            else{
                builded-> palace += 1;
                subCardP(card,playerProduce, playerCard);
                printf("You need to pay 6 card\n");
                printf("注意：一次只能選一張\n");
                int32_t count = 6;
                int32_t paycard = 0;
                while(count--){
                    paycard = 0;
                    printf("卡號<1-29>: ");
                    scanf("%d",&paycard);
                    paymoney(paycard, playerProduce, playerCard);
                }
            }
        }
        int32_t have = playerProduce -> indigoPlant + playerProduce -> sugarMill + playerProduce -> tobaccoStorage + playerProduce -> coffeeRoaster + playerProduce -> silverSmelter + playerCard -> tower + playerCard -> chapel + playerCard -> smithy + 
        playerCard -> poorHouse + playerCard -> blackMarket + playerCard -> crane + playerCard -> carpenter + playerCard -> quarry + playerCard -> well + playerCard -> aqueduct + playerCard -> marketStand + playerCard -> marketHall + playerCard -> tradingPost + playerCard -> archive + 
        playerCard -> prefecture + playerCard -> goldMine + playerCard -> library + playerCard -> statue + playerCard -> victoryColumn + playerCard -> hero + playerCard -> guildHall + playerCard -> cityHall + playerCard -> trinmhalArch + playerCard -> palace;
        int32_t poo = havePoor(builded);
        if(poo == 1){
            if(have <= 1){
                printf("因為你有救濟院(Poor House)，所以可抽取1張卡牌加入手牌\n");
                sleep(1);
                int32_t check2 = 2;
                while(check2 == 2){
                    int32_t randNum = rand() % 29 + 1;
                    int32_t check2 = checkcard(randNum, allProduce, allCard);
                    if(check2 == 1){
                        addcard(randNum, playerProduce, playerCard, allProduce, allCard);
                        break;
                    }
                }
            }
        }
        sleep(1);
        printAllCard(playerProduce,playerCard);
        sleep(1);
        printBuildedCard(builded);
        sleep(1);
    }
    // else if(job == 3){
    //     printf("Player 2 chooses prospector\n");
    // }
    else if(job == 4){
        int32_t MH = haveMH(builded);
        sleep(1);
        // printf("Player 2 chooses trader\n");
        int32_t randMoney = rand() % 5 + 1;
        int32_t *price = money(randMoney);
        sleep(1);
        printf("你可以選擇一樣貨物賣出，若你沒有任何貨物，則會自動跳過\n");
        sleep(1);
        int32_t allGoods = playerGoods -> indigoGoods + playerGoods -> sugarGoods + playerGoods -> tobaccoGoods + playerGoods -> coffeeGoods + playerGoods -> silverGoods;
        printAllGoods(playerGoods);
        sleep(1);
        int32_t winPrice = 0;
        if(allGoods != 0){
            printf("卡號<1-5>: ");
            int32_t card = 0;
            scanf("%d", &card);
            if(card == 1){
                // printf("card = 1\n");
                // printAllCard(playerProduce,playerCard);
                playerGoods -> indigoGoods -= 1;
                sellAndWinCard (card, *(price + (card-1)), allProduce, allCard, playerProduce, playerCard);
                printf("你已賣出染料廠(Indigo Plant)的貨物！\n");
            }
            if(card == 2){
                playerGoods -> sugarGoods -= 1;
                sellAndWinCard (card, *(price + (card-1)), allProduce, allCard, playerProduce, playerCard);
                printf("你已賣出蔗糖廠(Sugar Mill)的貨物！\n");
            }
            if(card == 3){
                playerGoods -> tobaccoGoods -= 1;
                sellAndWinCard (card, *(price + (card-1)), allProduce, allCard, playerProduce, playerCard);
                printf("你已賣出菸草廠(Tobacco Storage)的貨物！\n");
            }
            if(card == 4){
                playerGoods -> coffeeGoods -= 1;
                sellAndWinCard (card, *(price + (card-1)), allProduce, allCard, playerProduce, playerCard);
                printf("你已賣出咖啡廠(Coffee Roaster)的貨物！\n");
            }
            if(card == 5){
                playerGoods -> silverGoods -= 1;
                sellAndWinCard (card, *(price + (card-1)), allProduce, allCard, playerProduce, playerCard);
                printf("你已賣出白銀廠(Silver Smelter)的貨物！\n");
            }
            if(MH == 1){
                printf("因為你有因為你有市場(Market Hall)，所以可以額外多一張卡牌\n");
                sleep(1);
                int32_t check2 = 2;
                while(check2 == 2){
                    int32_t randNum = rand() % 29 + 1;
                    int32_t check2 = checkcard(randNum, allProduce, allCard);
                    if(check2 == 1){
                        addcard(randNum, playerProduce, playerCard, allProduce, allCard);
                        break;
                    }
                }
                // sleep(1);
            }
        }
        sleep(1);
        printAllCard(playerProduce,playerCard);
        sleep(1);
        printBuildedCard(builded);
        sleep(1);
    }
    else if(job == 5){
        // printf("Player 2 chooses councillor\n");
        printf("你可以抽取兩張並選擇一張卡牌，在這裡系統已經幫你選好\n");
        int32_t randNum = rand() % 29 + 1;
        int32_t check = checkcard(randNum, allProduce, allCard);
        while(check != 1){
            randNum = rand() % 29 + 1;
            check = checkcard(randNum, allProduce, allCard);
        }
        if(check == 1){
            addcard(randNum, playerProduce, playerCard, allProduce, allCard);
        }
        //牌庫要減掉，確認牌庫有排才可以發牌
        sleep(1);
        printAllCard(playerProduce,playerCard);
        sleep(1);
        printBuildedCard(builded);
        sleep(1);
    }
}