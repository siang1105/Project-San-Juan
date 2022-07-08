#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "sanJuan.h"

void sellAndWinCard (int32_t choice, int32_t price, sproduce *allProduce, scard *allCard, sproduce *playerProduce, scard *playerCard){
    // int32_t winPrice = price[choice - 1];
    // printf("price = %d\n",price);
    while(price != 0){
        int32_t winRand = rand() % 29 + 1;
        int32_t check = checkcard(winRand, allProduce, allCard);
        if(check == 1){
            addcard(winRand, playerProduce, playerCard, allProduce, allCard);
        }
        else{
            continue;
        }
        price--;
    }
}

void jobRid(int32_t job, sjob *allJob){
    if(job == 1){
        allJob -> producer -= 1;
    }
    else if(job == 2){
        allJob -> builder -= 1;
    }
    else if(job == 3){
        allJob -> prospector -= 1;
    }
    else if(job == 4){
        allJob -> trader -= 1;
    }
    else if(job == 5){
         allJob -> councillor -= 1;
    }
}

int32_t* money(int32_t chooseOne){
    static int32_t A[5] = {1, 2, 2, 3, 3};
    static int32_t B[5] = {1, 1, 2, 2, 3};
    static int32_t C[5] = {1, 2, 2, 2, 3};
    static int32_t D[5] = {1, 1, 1, 2, 2};
    static int32_t E[5] = {1, 1, 2, 2, 2};
    printf("Indigo Plant / Sugar Mill / Tobacco Storage / Coffee Roaster / Silver Smelter\n");
    if(chooseOne == 1){
        for(int32_t i = 0; i < 5; i++){
            printf("     %d         ",A[i]);
        }
        printf("\n");
        // int32_t *ptr_A = A;
        return A;
    }
    if(chooseOne == 2){
        for(int32_t i = 0; i < 5; i++){
            printf("     %d         ",B[i]);
        }
        printf("\n");
        // int32_t *ptr_B = B;
        return B;
    }
    if(chooseOne == 3){
        for(int32_t i = 0; i < 5; i++){
            printf("     %d         ",C[i]);
        }
        printf("\n");
        // int32_t *ptr_C = C;
        return C;
    }
    if(chooseOne == 4){
        for(int32_t i = 0; i < 5; i++){
            printf("     %d         ",D[i]);
        }
        printf("\n");
        // int32_t *ptr_D = D;
        return D;
    }
    if(chooseOne == 5){
        for(int32_t i = 0; i < 5; i++){
            printf("     %d         ",E[i]);
        }
        printf("\n");
        // int32_t *ptr_E = E;
        return E;
    }
    return 0;
}

int32_t checkgoods(int32_t check, sgoods *playerGoods){
    if(check == 1){
        if(playerGoods -> indigoGoods != 0) return 1;
        else return 2;
    }
    if(check == 2){
        if(playerGoods -> sugarGoods != 0) return 1;
        else return 2;
    }
    if(check == 3){
        if(playerGoods -> tobaccoGoods != 0) return 1;
        else return 2;
    }
    if(check == 4){
        if(playerGoods -> coffeeGoods != 0) return 1;
        else return 2;
    }
    if(check == 5){
        if(playerGoods -> silverGoods != 0) return 1;
        else return 2;
    }
    return 0;
}


int32_t checkcard(int32_t check, sproduce *allPro, scard *allCard){
    if(check == 1){
        if(allPro -> indigoPlant != 0) return 1;
        else return 2;
    }
    if(check == 2){
        if(allPro -> sugarMill != 0) return 1;
        else return 2;
    }
    if(check == 3){
        if(allPro -> tobaccoStorage != 0) return 1;
        else return 2;
    }
    if(check == 4){
        if(allPro -> coffeeRoaster != 0) return 1;
        else return 2;
    }
    if(check == 5){
        if(allPro -> silverSmelter != 0) return 1;
        else return 2;
    }
    if(check == 6){
        if(allCard -> tower != 0) return 1;
        else return 2;
    }
    if(check == 7){
        if(allCard -> chapel != 0) return 1;
        else return 2;
    }
    if(check == 8){
        if(allCard -> smithy != 0) return 1;
        else return 2;
    }
    if(check == 9){
        if(allCard -> poorHouse != 0) return 1;
        else return 2;
    }
    if(check == 10){
        if(allCard -> blackMarket != 0) return 1;
        else return 2;
    }
    if(check == 11){
        if(allCard -> crane != 0) return 1;
        else return 2;
    }
    if(check == 12){
        if(allCard -> carpenter != 0) return 1;
        else return 2;
    }
    if(check == 13){
        if(allCard -> quarry != 0) return 1;
        else return 2;
    }
    if(check == 14){
        if(allCard -> well != 0) return 1;
        else return 2;
    }
    if(check == 15){
        if(allCard -> aqueduct != 0) return 1;
        else return 2;
    }
    if(check == 16){
        if(allCard -> marketStand != 0) return 1;
        else return 2;
    }
    if(check == 17){
        if(allCard -> marketHall != 0) return 1;
        else return 2;
    }
    if(check == 18){
        if(allCard -> tradingPost != 0) return 1;
        else return 2;
    }
    if(check == 19){
        if(allCard -> archive != 0) return 1;
        else return 2;
    }
    if(check == 20){
        if(allCard -> prefecture != 0) return 1;
        else return 2;
    }
    if(check == 21){
        if(allCard -> goldMine != 0) return 1;
        else return 2;
    }
    if(check == 22){
        if(allCard -> library != 0) return 1;
        else return 2;
    }
    if(check == 23){
        if(allCard -> statue != 0) return 1;
        else return 2;
    }
    if(check == 24){
        if(allCard -> victoryColumn != 0) return 1;
        else return 2;
    }
    if(check == 25){
        if(allCard -> hero != 0) return 1;
        else return 2;
    }
    if(check == 26){
        if(allCard -> guildHall != 0) return 1;
        else return 2;
    }
    if(check == 27){
        if(allCard -> cityHall != 0) return 1;
        else return 2;
    }
    if(check == 28){
        if(allCard -> trinmhalArch != 0) return 1;
        else return 2;
    }
    if(check == 29){
        if(allCard -> palace != 0) return 1;
        else return 2;
    }
    return 0;
}
void addcard(int32_t addcard, sproduce *playerPro, scard *playerCar, sproduce *allPro, scard *allCard){
    if(addcard == 1){
        playerPro -> indigoPlant += 1;
        allPro -> indigoPlant -= 1;
    }
    if(addcard == 2){
        playerPro -> sugarMill += 1;
        allPro -> sugarMill -= 1;
    }
    if(addcard == 3){
        playerPro -> tobaccoStorage += 1;
        allPro -> tobaccoStorage -= 1;
    }
    if(addcard == 4){
        playerPro -> coffeeRoaster += 1;
        allPro -> coffeeRoaster -= 1;
    }
    if(addcard == 5){
        playerPro -> silverSmelter += 1;
        allPro -> silverSmelter -= 1;
    }
    if(addcard == 6){
        playerCar -> tower += 1;
        allCard -> tower -= 1;
    }
    if(addcard == 7){
        playerCar -> chapel += 1;
        allCard -> chapel -= 1;
    }
    if(addcard == 8){
        playerCar -> smithy += 1;
        allCard -> smithy -= 1;
    }
    if(addcard == 9){
        playerCar -> poorHouse += 1;
        allCard -> poorHouse -= 1;
    }
    if(addcard == 10){
        playerCar -> blackMarket += 1;
        allCard -> blackMarket -= 1;
    }
    if(addcard == 11){
        playerCar -> crane += 1;
        allCard -> crane -= 1;
    }
    if(addcard == 12){
        playerCar -> carpenter += 1;
        allCard -> carpenter -= 1;
    }
    if(addcard == 13){
        playerCar -> quarry += 1;
        allCard -> quarry -= 1;
    }
    if(addcard == 14){
        playerCar -> well += 1;
        allCard -> well -= 1;
    }
    if(addcard == 15){
        playerCar -> aqueduct += 1;
        allCard -> aqueduct -= 1;
    }
    if(addcard == 16){
        playerCar -> marketStand += 1;
        allCard -> marketStand -= 1;
    }
    if(addcard == 17){
        playerCar -> marketHall += 1;
        allCard -> marketHall -= 1;
    }
    if(addcard == 18){
        playerCar -> tradingPost += 1;
        allCard -> tradingPost -= 1;
    }
    if(addcard == 19){
        playerCar -> archive += 1;
        allCard -> archive -= 1;
    }
    if(addcard == 20){
        playerCar -> prefecture += 1;
        allCard -> prefecture -= 1;
    }
    if(addcard == 21){
        playerCar -> goldMine += 1;
        allCard -> goldMine -= 1;
    }
    if(addcard == 22){
        playerCar -> library += 1;
        allCard -> library -= 1;
    }
    if(addcard == 23){
        playerCar -> statue += 1;
        allCard -> statue -= 1;
    }
    if(addcard == 24){
        playerCar -> victoryColumn += 1;
        allCard -> victoryColumn -= 1;
    }
    if(addcard == 25){
        playerCar -> hero += 1;
        allCard -> hero -= 1;
    }
    if(addcard == 26){
        playerCar -> guildHall += 1;
        allCard -> guildHall -= 1;
    }
    if(addcard == 27){
        playerCar -> cityHall += 1;
        allCard -> cityHall -= 1;
    }
    if(addcard == 28){
        playerCar -> trinmhalArch += 1;
        allCard -> trinmhalArch -= 1;
    }
    if(addcard == 29){
        playerCar -> palace += 1;
        allCard -> palace -= 1;
    }
}
void paymoney (int32_t paycard, sproduce *playerPro, scard *playerCar){
    if(paycard == 1) playerPro -> indigoPlant -= 1;
    if(paycard == 2) playerPro -> sugarMill -= 1;
    if(paycard == 3) playerPro -> tobaccoStorage -= 1;
    if(paycard == 4) playerPro -> coffeeRoaster -= 1;
    if(paycard == 5) playerPro -> silverSmelter -= 1;
    if(paycard == 6) playerCar -> tower -= 1;
    if(paycard == 7) playerCar -> chapel -= 1;
    if(paycard == 8) playerCar -> smithy -= 1;
    if(paycard == 9) playerCar -> poorHouse -= 1;
    if(paycard == 10) playerCar -> blackMarket -= 1;
    if(paycard == 11) playerCar -> crane -= 1;
    if(paycard == 12) playerCar -> carpenter -= 1;
    if(paycard == 13) playerCar -> quarry -= 1;
    if(paycard == 14) playerCar -> well -= 1;
    if(paycard == 15) playerCar -> aqueduct -= 1;
    if(paycard == 16) playerCar -> marketStand -= 1;
    if(paycard == 17) playerCar -> marketHall -= 1;
    if(paycard == 18) playerCar -> tradingPost -= 1;
    if(paycard == 19) playerCar -> archive -= 1;
    if(paycard == 20) playerCar -> prefecture -= 1;
    if(paycard == 21) playerCar -> goldMine -= 1;
    if(paycard == 22) playerCar -> library -= 1;
    if(paycard == 23) playerCar -> statue -= 1;
    if(paycard == 24) playerCar -> victoryColumn -= 1;
    if(paycard == 25) playerCar -> hero -= 1;
    if(paycard == 26) playerCar -> guildHall -= 1;
    if(paycard == 27) playerCar -> cityHall -= 1;
    if(paycard == 28) playerCar -> trinmhalArch -= 1;
    if(paycard == 29) playerCar -> palace -= 1;
}

int32_t checkjob(int32_t job, sjob *alljob){
    if(job == 1){
        if(alljob -> producer == 1){
            return 1;
        }
        else{
            return 2;
        }
    }
    if(job == 2){
        if(alljob -> builder == 1){
            return 1;
        }
        else{
            return 2;
        }
    }
    if(job == 3){
        if(alljob -> prospector == 1){
            return 1;
        }
        else{
            return 2;
        }
    }
    if(job == 4){
        if(alljob -> trader == 1){
            return 1;
        }
        else{
            return 2;
        }
    }
    if(job == 5){
        if(alljob -> councillor == 1){
            return 1;
        }
        else{
            return 2;
        }
    }
    return 0;
}

int32_t checkWin(sbuilded *bui){
    int32_t win = bui -> indigoPlant + bui -> sugarMill + bui -> tobaccoStorage + bui -> coffeeRoaster + 
    bui -> silverSmelter + bui -> tower + bui -> chapel + bui -> smithy + bui -> poorHouse + bui -> blackMarket + 
    bui -> crane + bui -> carpenter + bui -> quarry + bui -> well + bui -> aqueduct + bui -> marketStand +
    bui -> marketHall + bui -> tradingPost + bui -> archive + bui -> prefecture + bui -> goldMine + 
    bui -> library + bui -> statue + bui -> victoryColumn + bui -> hero + bui -> guildHall + bui -> cityHall +
    bui -> trinmhalArch + bui -> palace;
    if( win >= 12 ){
        return 1;
        // sleep(1);
        // printf(YELLOW);
        // printf("              遊戲結束 \n");
        // printf("---------Player %d is winner---------\n",p)ㄤ
        // exit(1);
    }
    return 0;
}

void subCard(sproduce *allProduce, scard *allCard){
    int32_t randCard = 0;
    int32_t check = 2;
    while(check == 2){
        randCard = rand() % 29 + 1;
        check = checkcard(randCard, allProduce, allCard);
    }
    if(check == 1){
        if(randCard == 1) allProduce -> indigoPlant -= 1;
        if(randCard == 2) allProduce -> sugarMill -= 1;
        if(randCard == 3) allProduce -> tobaccoStorage -= 1;
        if(randCard == 4) allProduce -> coffeeRoaster -= 1;
        if(randCard == 5) allProduce -> silverSmelter -= 1;
        if(randCard == 6) allCard -> tower -= 1;
        if(randCard == 7) allCard -> chapel -= 1;
        if(randCard == 8) allCard -> smithy -= 1;
        if(randCard == 9) allCard -> poorHouse -= 1;
        if(randCard == 10) allCard -> blackMarket -= 1;
        if(randCard == 11) allCard -> crane -= 1;
        if(randCard == 12) allCard -> carpenter -= 1;
        if(randCard == 13) allCard -> quarry -= 1;
        if(randCard == 14) allCard -> well -= 1;
        if(randCard == 15) allCard -> aqueduct -= 1;
        if(randCard == 16) allCard -> marketStand -= 1;
        if(randCard == 17) allCard -> marketHall -= 1;
        if(randCard == 18) allCard -> tradingPost -= 1;
        if(randCard == 19) allCard -> archive -= 1;
        if(randCard == 20) allCard -> prefecture -= 1;
        if(randCard == 21) allCard -> goldMine -= 1;
        if(randCard == 22) allCard -> library -= 1;
        if(randCard == 23) allCard -> statue -= 1;
        if(randCard == 24) allCard -> victoryColumn -= 1;
        if(randCard == 25) allCard -> hero -= 1;
        if(randCard == 26) allCard -> guildHall -= 1;
        if(randCard == 27) allCard -> cityHall -= 1;
        if(randCard == 28) allCard -> trinmhalArch -= 1;
        if(randCard == 29) allCard -> palace -= 1;
    }
}

void subCardP(int32_t num,sproduce *playerPro, scard *playerCar){
        if(num == 1) playerPro -> indigoPlant -= 1;
        if(num == 2) playerPro -> sugarMill -= 1;
        if(num == 3) playerPro -> tobaccoStorage -= 1;
        if(num == 4) playerPro -> coffeeRoaster -= 1;
        if(num == 5) playerPro -> silverSmelter -= 1;
        if(num == 6) playerCar -> tower -= 1;
        if(num == 7) playerCar -> chapel -= 1;
        if(num == 8) playerCar -> smithy -= 1;
        if(num == 9) playerCar -> poorHouse -= 1;
        if(num == 10) playerCar -> blackMarket -= 1;
        if(num == 11) playerCar -> crane -= 1;
        if(num == 12) playerCar -> carpenter -= 1;
        if(num == 13) playerCar -> quarry -= 1;
        if(num == 14) playerCar -> well -= 1;
        if(num == 15) playerCar -> aqueduct -= 1;
        if(num == 16) playerCar -> marketStand -= 1;
        if(num == 17) playerCar -> marketHall -= 1;
        if(num == 18) playerCar -> tradingPost -= 1;
        if(num == 19) playerCar -> archive -= 1;
        if(num == 20) playerCar -> prefecture -= 1;
        if(num == 21) playerCar -> goldMine -= 1;
        if(num == 22) playerCar -> library -= 1;
        if(num == 23) playerCar -> statue -= 1;
        if(num == 24) playerCar -> victoryColumn -= 1;
        if(num == 25) playerCar -> hero -= 1;
        if(num == 26) playerCar -> guildHall -= 1;
        if(num == 27) playerCar -> cityHall -= 1;
        if(num == 28) playerCar -> trinmhalArch -= 1;
        if(num == 29) playerCar -> palace -= 1;
}

// int32_t checkgoods(int32_t num, sgoods *good){
//     if(num == 1){
//         if(good -> indigoGoods == 0){
//             return 1;
//         }
//         else{
//             return 2;
//         }
//     }
//     if(num == 2){
//         if(good -> sugarGoods == 0){
//             return 1;
//         }
//         else{
//             return 2;
//         }
//     }
//     if(num == 3){
//         if(good -> tobaccoGoods == 0){
//             return 1;
//         }
//         else{
//             return 2;
//         }
//     }
//     if(num == 4){
//         if(good -> coffeeGoods == 0){
//             return 1;
//         }
//         else{
//             return 2;
//         }
//     }
//     if(num == 5){
//         if(good -> silverGoods == 0){
//             return 1;
//         }
//         else{
//             return 2;
//         }
//     }
// }

int32_t* Fmoney(int32_t chooseOne){
    static int32_t A[5] = {1, 2, 2, 3, 3};
    static int32_t B[5] = {1, 1, 2, 2, 3};
    static int32_t C[5] = {1, 2, 2, 2, 3};
    static int32_t D[5] = {1, 1, 1, 2, 2};
    static int32_t E[5] = {1, 1, 2, 2, 2};
    if(chooseOne == 1){
        // int32_t *ptr_A = A;
        return A;
    }
    if(chooseOne == 2){
        // int32_t *ptr_B = B;
        return B;
    }
    if(chooseOne == 3){
        // int32_t *ptr_C = C;
        return C;
    }
    if(chooseOne == 4){
        // int32_t *ptr_D = D;
        return D;
    }
    if(chooseOne == 5){
        // int32_t *ptr_E = E;
        return E;
    }
    return 0;
}

void checkNoCard(sproduce *allpro, scard *allCard){
    int32_t pro = allpro -> indigoPlant + allpro -> sugarMill + allpro -> tobaccoStorage + allpro -> coffeeRoaster + allpro -> silverSmelter;
    if(pro < 1){
        setProduce(allpro);
    }
    int32_t card = allCard -> tower + allCard -> chapel + allCard -> smithy + allCard -> poorHouse + allCard -> blackMarket + 
    allCard -> crane + allCard -> carpenter + allCard -> quarry + allCard -> well + allCard -> aqueduct + allCard -> marketStand +
    allCard -> marketHall + allCard -> tradingPost + allCard -> archive + allCard -> prefecture + allCard -> goldMine + 
    allCard -> library + allCard -> statue + allCard -> victoryColumn + allCard -> hero + allCard -> guildHall + allCard -> cityHall +
    allCard -> trinmhalArch + allCard -> palace;
    if(card < 1){
        setCard(allCard);
    }
}

int32_t calScore(sbuilded *bui){
    int32_t havePro = bui -> indigoPlant + bui -> sugarMill + bui -> tobaccoStorage + bui -> coffeeRoaster + bui -> silverSmelter;
    int32_t haveCar = bui -> tower + bui -> chapel + bui -> smithy + bui -> poorHouse + bui -> blackMarket + bui -> crane + bui -> carpenter + bui -> quarry + bui -> well + bui -> aqueduct + bui -> marketStand + bui -> marketHall + bui -> tradingPost + bui -> archive + 
        bui -> prefecture + bui -> goldMine + bui -> library + bui -> statue + bui -> victoryColumn + bui -> hero + bui -> guildHall + bui -> cityHall + bui -> trinmhalArch + bui -> palace;
    int32_t haveMem = bui -> statue + bui -> victoryColumn + bui -> hero;
    int32_t score = 0;
    if(bui -> indigoPlant != 0){
        score += bui -> indigoPlant * 1;
    }
    if(bui -> sugarMill != 0){
        score += bui -> sugarMill * 1;
    }
    if(bui -> tobaccoStorage != 0){
        score += bui -> tobaccoStorage * 2;
    }
    if(bui -> coffeeRoaster != 0){
        score += bui -> coffeeRoaster * 2;
    }
    if(bui -> silverSmelter != 0){
        score += bui -> silverSmelter * 3;
    }
    if(bui -> tower != 0){
        score += bui -> tower * 2;
    }
    if(bui -> chapel != 0){
        score += bui -> chapel * 2;
    }
    if(bui -> smithy != 0){
        score += bui -> smithy * 1;
    }
    if(bui -> poorHouse != 0){
        score += bui -> poorHouse * 1;
    }
    if(bui -> blackMarket != 0){
        score += bui -> blackMarket * 1;
    }
    if(bui -> crane != 0){
        score += bui -> crane * 1;
    }
    if(bui -> carpenter != 0){
        score += bui -> carpenter * 2;
    }
    if(bui -> quarry != 0){
        score += bui -> quarry * 2;
    }
    if(bui -> well != 0){
        score += bui -> well * 1;
    }
    if(bui -> aqueduct != 0){
        score += bui -> aqueduct * 2;
    }
    if(bui -> marketStand != 0){
        score += bui -> marketStand * 1;
    }
    if(bui -> marketHall != 0){
        score += bui -> marketHall * 2;
    }
    if(bui -> tradingPost != 0){
        score += bui -> tradingPost * 1;
    }
    if(bui -> archive != 0){
        score += bui -> archive * 1;
    }
    if(bui -> prefecture != 0){
        score += bui -> prefecture * 2;
    }
    if(bui -> goldMine != 0){
        score += bui -> goldMine * 1;
    }
    if(bui -> library != 0){
        score += bui -> library * 3;
    }
    if(bui -> statue != 0){
        score += bui -> statue * 3;
    }
    if(bui -> victoryColumn != 0){
        score += bui -> victoryColumn * 4;
    }
    if(bui -> hero != 0){
        score += bui -> hero * 5;
    }
    if(bui -> guildHall != 0){
        score += havePro * 2;
    }
    if(bui -> cityHall != 0){
        score += haveCar * 1;
    }
    if(bui -> trinmhalArch != 0){
        if(haveMem == 1) score += 4;
        if(haveMem == 2) score += 6;
        if(haveMem == 3) score += 8;
    }
    if(bui -> palace != 0){
        score += score / 4;
    }
    return score;
}

int32_t haveSmi(sbuilded * bui){
    if(bui -> smithy != 0){
        return 1;
    }
    return 0;
}

int32_t havePoor(sbuilded * bui){
    if(bui -> poorHouse != 0){
        return 1;
    }
    return 0;
}

int32_t haveQua(sbuilded * bui){
    if(bui -> quarry != 0){
        return 1;
    }
    return 0;
}

int32_t haveWel(sbuilded * bui){
    if(bui -> well != 0){
        return 1;
    }
    return 0;
}

int32_t haveAqu(sbuilded * bui){
    if(bui -> aqueduct != 0){
        return 1;
    }
    return 0;
}

int32_t haveMH(sbuilded * bui){
    if(bui -> marketHall != 0){
        return 1;
    }
    return 0;
}

int32_t whoWin2(int32_t p1, int32_t p2){
    if(p1 > p2){
        return 1;
    }
    if(p2 > p1){
        return 2;
    }
    else{
        return 3;
    }
}

int32_t whoWin3(int32_t p1, int32_t p2, int32_t p3){
    if(p1 > p2 && p1 > p3){
        return 1;
    }
    if(p2 > p1 && p2 > p3){
        return 2;
    }
    if(p3 > p1 && p3 > p2){
        return 3;
    }
    else{
        return 4;
    }
}

int32_t whoWin4(int32_t p1, int32_t p2, int32_t p3, int32_t p4){
    if(p1 > p2 && p1 > p3 && p1 > p4){
        return 1;
    }
    if(p2 > p1 && p2 > p3 && p2 > p4){
        return 2;
    }
    if(p3 > p1 && p3 > p2 && p3 > p4){
        return 3;
    }
    if(p4 > p1 && p4 > p2 && p4 > p3){
        return 4;
    }
    else{
        return 5;
    }
}

void seven(sproduce *playerProduce,scard *playerCard, int32_t haveto, int32_t R){
    int32_t all = playerProduce -> indigoPlant + playerProduce -> sugarMill + playerProduce -> tobaccoStorage + playerProduce -> coffeeRoaster + playerProduce -> silverSmelter + playerCard -> tower + playerCard -> chapel + playerCard -> smithy + 
        playerCard -> poorHouse + playerCard -> blackMarket + playerCard -> crane + playerCard -> carpenter + playerCard -> quarry + playerCard -> well + playerCard -> aqueduct + playerCard -> marketStand + playerCard -> marketHall + playerCard -> tradingPost + playerCard -> archive + 
        playerCard -> prefecture + playerCard -> goldMine + playerCard -> library + playerCard -> statue + playerCard -> victoryColumn + playerCard -> hero + playerCard -> guildHall + playerCard -> cityHall + playerCard -> trinmhalArch + playerCard -> palace;
    if(haveto != 1){
        if(all > 7){
            if(R == 1){
            printf("卡牌上限不得超過七張，所以系統已隨機幫你抽掉多出的卡牌\n");
            }
        }
        while(all > 7){
        subCard(playerProduce,playerCard);
        all--;
        }
        
    }
    if(haveto == 1){
        if(all > 12){
            if(R == 1){
            printf("因為你有塔樓，所以卡牌上限為12張，系統已隨機幫你抽掉多出的卡牌\n");
            }
        }
        while(all > 12){
        subCard(playerProduce,playerCard);
        all--;
        }
        
    }
    
}

int32_t haveTo(sbuilded *bui){
    if(bui -> tower != 0){
        return 1;
    }
    return 0;
}