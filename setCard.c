#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "sanJuan.h"

void setJob(sjob *allJob){
    allJob -> producer = 1;
    allJob -> builder = 1;
    allJob -> prospector = 1;
    allJob -> trader = 1;
    allJob -> councillor = 1;

}
void setGoods(sgoods *goods){
    goods -> indigoGoods = 0;
    goods -> sugarGoods = 0;
    goods -> tobaccoGoods = 0;
    goods -> coffeeGoods = 0;
    goods -> silverGoods = 0;
}

void setProduce(sproduce *allProduce){
    allProduce -> indigoPlant = 10;
    allProduce -> sugarMill = 8;
    allProduce -> tobaccoStorage = 8;
    allProduce -> coffeeRoaster = 8;
    allProduce -> silverSmelter = 8;
}
void setPlayerBuiled(sbuilded *builded){
    builded -> indigoPlant = 1;
    builded -> sugarMill = 0;
    builded -> tobaccoStorage = 0;
    builded -> coffeeRoaster = 0;
    builded -> silverSmelter = 0;
    builded -> tower = 0;
    builded -> chapel = 0;
    builded -> smithy = 0;
    builded -> poorHouse = 0;
    builded -> blackMarket = 0;
    builded -> crane = 0;
    builded -> carpenter = 0;
    builded -> quarry = 0;
    builded -> well = 0;
    builded -> aqueduct = 0;
    builded -> marketStand = 0;
    builded -> marketHall = 0;
    builded -> tradingPost = 0;
    builded -> archive = 0;
    builded -> prefecture = 0;
    builded -> goldMine = 0;
    builded -> library = 0;
    builded -> statue = 0;
    builded -> victoryColumn = 0;
    builded -> hero = 0;
    builded -> guildHall = 0;
    builded -> cityHall = 0;
    builded -> trinmhalArch = 0;
    builded -> palace = 0;
}
void setCard(scard *allCard){
    allCard -> tower = 3;
    allCard -> chapel = 3;
    allCard -> smithy = 3;
    allCard -> poorHouse = 3;
    allCard -> blackMarket = 3;
    allCard -> crane = 3;
    allCard -> carpenter = 3;
    allCard -> quarry = 3;
    allCard -> well = 3;
    allCard -> aqueduct = 3;
    allCard -> marketStand = 3;
    allCard -> marketHall = 3;
    allCard -> tradingPost = 3;
    allCard -> archive = 3;
    allCard -> prefecture = 3;
    allCard -> goldMine = 3;
    allCard -> library = 3;
    allCard -> statue = 3;
    allCard -> victoryColumn = 3;
    allCard -> hero = 3;
    allCard -> guildHall = 2;
    allCard -> cityHall = 2;
    allCard -> trinmhalArch = 2;
    allCard -> palace = 2;
}

void setPlayerPro(sproduce *playerProduce){
    playerProduce -> indigoPlant = 0;
    playerProduce -> sugarMill = 0;
    playerProduce -> tobaccoStorage = 0;
    playerProduce -> coffeeRoaster = 0;
    playerProduce -> silverSmelter = 0;
}

void setPlayerCard(scard *playerCard){
    playerCard -> tower = 0;
    playerCard -> chapel = 0;
    playerCard -> smithy = 0;
    playerCard -> poorHouse = 0;
    playerCard -> blackMarket = 0;
    playerCard -> crane = 0;
    playerCard -> carpenter = 0;
    playerCard -> quarry = 0;
    playerCard -> well = 0;
    playerCard -> aqueduct = 0;
    playerCard -> marketStand = 0;
    playerCard -> marketHall = 0;
    playerCard -> tradingPost = 0;
    playerCard -> archive = 0;
    playerCard -> prefecture = 0;
    playerCard -> goldMine = 0;
    playerCard -> library = 0;
    playerCard -> statue = 0;
    playerCard -> victoryColumn = 0;
    playerCard -> hero = 0;
    playerCard -> guildHall = 0;
    playerCard -> cityHall = 0;
    playerCard -> trinmhalArch = 0;
    playerCard -> palace = 0;
}

void poker(sproduce *allProduce, scard *allCard, sproduce *playerPro, scard *playerCard){
    int32_t count = 4;
    int32_t randNum = 0;
    int32_t check = 2;
    while(count--){
        // printf("count = %d\n",count);
        check = 2;
        randNum = 0;
        while(check == 2){
            randNum = rand() % 29 + 1;
            // printf("%d\n",randNum);
            check = checkcard(randNum, allProduce, allCard);
            // printf("check = %d\n",check);
        }
        // printf("rand = %d\n",randNum);
        // printf("check = %d\n",check);
        if(randNum == 1){
            playerPro -> indigoPlant += 1;
            allProduce -> indigoPlant -= 1;
        }
        if(randNum == 2){
            playerPro -> sugarMill += 1;
            allProduce -> sugarMill -= 1;
        }
        if(randNum == 3){
            playerPro -> tobaccoStorage += 1;
            allProduce -> tobaccoStorage -= 1;
        }
        if(randNum == 4){
            playerPro -> coffeeRoaster += 1;
            allProduce -> coffeeRoaster -= 1;
        }
        if(randNum == 5){
            playerPro -> silverSmelter += 1;
            allProduce -> silverSmelter -= 1;
        }
        if(randNum == 6){
            playerCard -> tower += 1;
            allCard -> tower -= 1;
        }
        if(randNum == 7){
            playerCard -> chapel += 1;
            allCard -> chapel -= 1;
        }
        if(randNum == 8){
            playerCard -> smithy += 1;
            allCard -> smithy -= 1;
        }
        if(randNum == 9){
            playerCard -> poorHouse += 1;
            allCard -> poorHouse -= 1;
        }
        if(randNum == 10){
            playerCard -> blackMarket += 1;
            allCard -> blackMarket -= 1;
        }
        if(randNum == 11){
            playerCard -> crane += 1;
            allCard -> crane -= 1;
        }
        if(randNum == 12){
            playerCard -> carpenter += 1;
            allCard -> carpenter -= 1;
        }
        if(randNum == 13){
            playerCard -> quarry += 1;
            allCard -> quarry -= 1;
        }
        if(randNum == 14){
            playerCard -> well += 1;
            allCard -> well -= 1;
        }
        if(randNum == 15){
            playerCard -> aqueduct += 1;
            allCard -> aqueduct -= 1;
        }
        if(randNum == 16){
            playerCard -> marketStand += 1;
            allCard -> marketStand -= 1;
        }
        if(randNum == 17){
            playerCard -> marketHall += 1;
            allCard -> marketHall -= 1;
        }
        if(randNum == 18){
            playerCard -> tradingPost += 1;
            allCard -> tradingPost -= 1;
        }
        if(randNum == 19){
            playerCard -> archive += 1;
            allCard -> archive -= 1;
        }
        if(randNum == 20){
            playerCard -> prefecture += 1;
            allCard -> prefecture -= 1;
        }
        if(randNum == 21){
            playerCard -> goldMine += 1;
            allCard -> goldMine -= 1;
        }
        if(randNum == 22){
            playerCard -> library += 1;
            allCard -> library -= 1;
        }
        if(randNum == 23){
            playerCard -> statue += 1;
            allCard -> statue -= 1;
        }
        if(randNum == 24){
            playerCard -> victoryColumn += 1;
            allCard -> victoryColumn -= 1;
        }
        if(randNum == 25){
            playerCard -> hero += 1;
            allCard -> hero -= 1;
        }
        if(randNum == 26){
            playerCard -> guildHall += 1;
            allCard -> guildHall -= 1;
        }
        if(randNum == 27){
            playerCard -> cityHall += 1;
            allCard -> cityHall -= 1;
        }
        if(randNum == 28){
            playerCard -> trinmhalArch += 1;
            allCard -> trinmhalArch -= 1;
        }
        if(randNum == 29){
            playerCard -> palace += 1;
            allCard -> palace -= 1;
        }
        // printf("count = %d\n",count);
    }
}